/*
 * @file client_sub.h
 * @brief sub-function of operating client.
 */

#ifndef CLIENT_SUB_H_
#define CLIENT_SUB_H_

#include <list>
#include <netdb.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>

#include "client_type.h"

/**
 * @brief Get client's IP from client map.
 * @param bev bufferevent
 * @param clientMap client map
 */
char* get_client_ip_from_list(bufferevent* bev,std::map<bufferevent*,CLIENTDATA>* clientMap){

	std::map<bufferevent*,CLIENTDATA>::iterator cmit = clientMap->begin();
	while(cmit != clientMap->end()){
		if(cmit->second.bev == bev){
			return cmit->second.hbuf;
		}else{
			cmit++;
		}
	}

	return NULL;
}

/**
 * @brief Get client's PORT from client map.
 * @param bev bufferevent
 * @param clientMap client map
 */
char* get_client_port_from_list(bufferevent* bev,std::map<bufferevent*,CLIENTDATA>* clientMap){

	std::map<bufferevent*,CLIENTDATA>::iterator cmit = clientMap->begin();
	while(cmit != clientMap->end()){
		if(cmit->second.bev == bev){
			return cmit->second.sbuf;
		}else{
			cmit++;
		}
	}

	return NULL;
}

/**
 * @brief Remove client node.
 * @param bev bufferevent
 * @param clientMap client map
 */
int remove_client_node(bufferevent* bev,std::map<bufferevent*,CLIENTDATA>* clientMap){

	std::map<bufferevent*,CLIENTDATA>::iterator cmit = clientMap->begin();
    while(cmit != clientMap->end()){
    	if(cmit->second.bev == bev){
#ifdef _Debug
    		printf("Client disconnect IP:PORT => %s,%s \n",get_client_ip_from_list(bev,clientMap),get_client_port_from_list(bev,clientMap));
#endif
    		clientMap->erase(cmit);
    		break;
    	}else{
    		cmit++;
    	}
    };

	return EXIT_SUCCESS;
}

#endif /* CLIENT_SUB_H_ */
