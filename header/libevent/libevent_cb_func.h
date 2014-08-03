/**
 * @file libevent_cb_func.h
 * @brief libevent call back function.
 *
 */

#ifndef LIBEVENT_CB_FUNC_H_
#define LIBEVENT_CB_FUNC_H_

#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <event2/listener.h>
#include <event2/event.h>
#include <event2/thread.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/util.h>
#include <sys/socket.h>
#include <errno.h>
#include <map>
#include <vector>
#include "../protocol/tcpip_protocol_def.h"
#include "../client/client_type.h"
#include "../client/client_subfunc.h"

/*--- Function Prototype ---*/
void read_cb(struct bufferevent *bev, void *ctx);
void event_cb(struct bufferevent *bev, short events, void *ctx);
void accept_conn_cb(struct evconnlistener *listener,evutil_socket_t fd, struct sockaddr *address, int socklen,void *ctx);
void accept_error_cb(struct evconnlistener *listener, void *ctx);
void* start_server_libevent_loop(void* data);
/*--------------------------*/
pthread_t pth_libevent;/**< thread ID indicator */
pthread_mutex_t libevent_mutex;/**< libevent thread mutex */

struct event_base *base;/**< event_base */
struct evconnlistener *listener;/**< evconnlistener */
struct sockaddr_in sock_in;/**< sockaddr_in */
int port;/**< listener port */
std::map<bufferevent*,CLIENTDATA> clientMap; /**< client map */
std::vector<NETWORKEVENT> networkData;/**< communication data */

/*--------------------------*/
CLIENTPLAYDATA clientPlayData[20];

/**
 * @brief TCP Mutex Lock.
 */
void TCPMutexLock(void){
	int lockResult=0;
	lockResult = pthread_mutex_lock(&libevent_mutex);

	if(lockResult != 0){
		fprintf(stdout, "Pthread Lock Failure,Error is : %d \n", lockResult);
	}
}

/**
 * @brief TCP Mutex Unlock.
 */
void TCPMutexUnlock(void){
	int unlockResult=0;
	unlockResult = pthread_mutex_unlock(&libevent_mutex);

	if(unlockResult!=0){
		fprintf(stdout, "Pthread Unlock Failure,Error is : %d \n", unlockResult);
	}
}

/**
 * @brief read call back function.
 * @param bev bufferevent
 * @param ctx input data
 */
void read_cb(struct bufferevent *bev, void *ctx){

	    //pthread_mutex_lock(&libevent_mutex);

	    int n;/**< n byte read */

	    /* This callback is invoked when there is data to read on bev. */
        struct evbuffer *input  = bufferevent_get_input(bev);

        printf("!!! evbuffer's length : %d \n",evbuffer_get_length(input));

        if(evbuffer_get_length(input) < sizeof(NETWORKEVENT) ){
        	return;
        }

        /* read data */
        NETWORKEVENT* comm;
        comm = (NETWORKEVENT*)malloc(sizeof(NETWORKEVENT));
        memset((void*)comm,0,sizeof(NETWORKEVENT));

        printf("!!! evbuffer's length : %d \n",evbuffer_get_length(input));

        TCPMutexLock();
        while( (n = evbuffer_remove(input,(void*)(comm),sizeof(NETWORKEVENT))) > 0 ){
#ifdef _DEBUG
        	printf("%d,%d,%d,%d,%d,%d,%d \n",n,comm->_id,comm->_cmd_grp_id,comm->_cmd_id,comm->_data_length,comm->_data[0],comm->_data[1]);
#endif
			comm->_bev = bev;
			networkData.push_back(*comm);

			printf("!!! after remove evbuffer's length : %d \n",evbuffer_get_length(input));
		    if(evbuffer_get_length(input) < sizeof(NETWORKEVENT) ){
		    	break;
		    }
        }
        TCPMutexUnlock();

        free(comm);
        //pthread_mutex_unlock(&libevent_mutex);
}

/**
 * @brief event call back function.
 * @param bev bufferevent
 * @param events event
 * @param ctx input data
 */
void event_cb(struct bufferevent *bev, short events, void *ctx){

	    //pthread_mutex_lock(&libevent_mutex);
		TCPMutexLock();
        if (events & BEV_EVENT_ERROR)
                perror("Error from bufferevent");
        if (events & (BEV_EVENT_EOF | BEV_EVENT_ERROR)) {
        	    remove_client_node(bev,static_cast<std::map<bufferevent*,CLIENTDATA>*>(ctx));//&clientMap);
                bufferevent_free(bev);
                bev = NULL;
        }
        TCPMutexUnlock();
        //pthread_mutex_unlock(&libevent_mutex);
}

/**
 * @brief accept connection call back function.
 * @param listener evconnlistener
 * @param fd evutil_socket_t
 * @param address sockaddr
 * @param socklen length of sockaddr
 * @param ctx input data
 */
void accept_conn_cb(struct evconnlistener *listener,evutil_socket_t fd, struct sockaddr *address, int socklen,void *ctx){

	    //pthread_mutex_lock(&libevent_mutex);
		TCPMutexLock();
        /* We got a new connection! Set up a bufferevent for it. */
        struct event_base *base = evconnlistener_get_base(listener);
        struct bufferevent *bev = bufferevent_socket_new(
                base, fd, BEV_OPT_CLOSE_ON_FREE|BEV_OPT_THREADSAFE);

        bufferevent_setcb(bev, read_cb, NULL, event_cb, static_cast<void*>(&clientMap));

        bufferevent_enable(bev, EV_READ|EV_WRITE);

        /* We want to save client as list node */
        CLIENTDATA clientData;
        clientData.client_fd = fd;
        clientData.bev = bev;
        clientData.clientSockaddr = address;
        getnameinfo(address,socklen,clientData.hbuf,sizeof(clientData.hbuf),clientData.sbuf,sizeof(clientData.sbuf),NI_NUMERICHOST | NI_NUMERICSERV);
        //clientList.push_back(clientData);
        clientMap.insert(std::pair<bufferevent*,CLIENTDATA>(bev,clientData));
#ifdef _DEBUG
        printf("Client's IP:PORT => %s:%s \n",clientData.hbuf,clientData.sbuf);
#endif

#if 0
        /* after connection established, request client's ID */
        struct evbuffer* output = bufferevent_get_output(clientData.bev);
        NETWORKEVENT* tranData;
        tranData = (NETWORKEVENT*)malloc(sizeof(NETWORKEVENT));
        memset((void*)tranData,0,sizeof(NETWORKEVENT));
        tranData->_id          = 0;
        tranData->_cmd_grp_id  = TCP_GID_CONN;
        tranData->_cmd_id      = CMDID_CONN_REQUEST_ID;//PROTO_REQUEST_ID;
        tranData->_data_length = 0;
        evbuffer_add(output,(void*)tranData,sizeof(NETWORKEVENT));
        /* free it space */
        free(tranData);
#endif
        //pthread_mutex_unlock(&libevent_mutex);
        TCPMutexUnlock();
}

/**
 * @brief accept error call back function.
 * @param listener evconnlistener
 * @param ctx input data
 */
void accept_error_cb(struct evconnlistener *listener, void *ctx){

        struct event_base *base = evconnlistener_get_base(listener);
        int err = EVUTIL_SOCKET_ERROR();
        fprintf(stderr, "Got an error %d (%s) on the listener. "
                "Shutting down.\n", err, evutil_socket_error_to_string(err));

        event_base_loopexit(base, NULL);
}

/**
 * @brief server thread run function.
 * @param data input data
 * @retval return data
 */
void* start_server_libevent_loop(void* data){

    base = event_base_new();
    if (!base) {
            puts("Couldn't open event base");
            //return 1;
            pthread_exit(NULL);
    }

    /* Clear the sockaddr before using it, in case there are extra
     * platform-specific fields that can mess us up. */
    memset(&sock_in, 0, sizeof(sock_in));
    /* This is an INET address */
    sock_in.sin_family = AF_INET;
    /* Listen on 0.0.0.0 */
    sock_in.sin_addr.s_addr = htonl(0);
    /* Listen on the given port. */
    sock_in.sin_port = htons(port);

    listener = evconnlistener_new_bind(base, accept_conn_cb, NULL,
        LEV_OPT_CLOSE_ON_FREE|LEV_OPT_REUSEABLE, -1,
        (struct sockaddr*)&sock_in, sizeof(sock_in));
    if (!listener) {
            perror("Couldn't create listener");
            //return 1;
            pthread_exit(NULL);
    }

    evconnlistener_set_error_cb(listener, accept_error_cb);

    event_base_dispatch(base);

    // Thread Exit
    pthread_exit(NULL);
}

#endif /* LIBEVENT_CB_FUNC_H_ */
