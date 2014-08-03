/**
 * @file serialComm.h
 *
 */

#ifndef SERIALCOMM_H_
#define SERIALCOMM_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <limits.h>
#include <poll.h>
#include "../preprocessor.h"
#include "serialDevice.h"
#include "serialDataType.h"
#include "aes_keys.h"
#include "../aes/aes.h"
#include "../aes/inv_aes.h"

#define RECV_BUFF_SIZE  1024
/**
 * @brief UART Receive Buffer.
 */
typedef struct UartRecvBuff {
	unsigned char m_buff[RECV_BUFF_SIZE];/**< Data Buffer */
	int m_processedIndex;/**< Processed Index */
	int m_nextInputIndex;/**< Next Input Index */
	int m_totalDataBytes;/**< Total Data Bytes */

	/**
	 * @brief Constructor.
	 */
	UartRecvBuff(void) {
		memset(this->m_buff, 0, (sizeof(this->m_buff) / sizeof(this->m_buff[0])));
		this->m_processedIndex = 0;
		this->m_nextInputIndex = 0;
		this->m_totalDataBytes = 0;
	}

} UARTRECVBUFF;

UARTRECVBUFF uartRecvBuff;

#define BAUDRATE  B115200/**< BAUD RATE  */

int fd;/**< serial port fd */
struct termios oldtio;/**< old port setting */
struct termios newtio;/**< new port setting */

#ifdef SERIALPORT_READ_METHOD_EPOLL
int epollfd;/**< epoll fd */
struct epoll_event ev, events[10];/**< epoll parameters */
#endif

#ifdef SERIALPORT_READ_METHOD_SELECT
int maxfd;/**< max fd */
int select_res;/**< select result */
int select_read_ret;/**< read result */
fd_set fds;/**< Temporal fds */
fd_set readfds;/**< file descriptor set (Read) */
struct timeval SelectTimeOut;/**< select time out */
#endif

/**
 * @brief Receive Data.
 */
vector<SERIALRECVDATA> recvData;
/**
 * @brief Transmission Data.
 */
SERIALSENDDATA         transData;


int OpenSerialPort(void){

	char uartPort[256];
	char *pUart=NULL;

	if ((pUart = getenv("UARTPORT")) != NULL) {
		strncpy(uartPort, pUart, (256 - 1));
		// open device
		fd = open(uartPort, O_RDWR | O_NOCTTY /*| O_NDELAY*/ /* | O_NONBLOCK */);
		if (fd < 0) {
			perror(uartPort);
			return -1;
		}
	} else {
		// open device
		fd = open(UART_PORT, O_RDWR | O_NOCTTY /*| O_NDELAY*/ /* | O_NONBLOCK */);
		if (fd < 0) {
			perror(UART_PORT);
			return -1;
		}
	}

	// save current port settings
	tcgetattr(fd, &(oldtio));
	bzero(&newtio,sizeof(newtio));//fixed

	// set options
	newtio.c_cflag = BAUDRATE | /* CRTSCTS |*/ CS8 | CLOCAL | CREAD;
	newtio.c_iflag = IGNPAR;
	newtio.c_oflag = 0;
	newtio.c_lflag = 0;
	newtio.c_cc[VMIN] = 24;
	newtio.c_cc[VTIME] = 0;

	// flush
	tcflush(fd, TCIFLUSH);

	// set
	tcsetattr(fd, TCSANOW, &(newtio));

	// Print Information
	printf("Open Serial Port %s Success ! \n",pUart==NULL ? UART_PORT : pUart);

#ifdef SERIALPORT_READ_METHOD_EPOLL
	// create epoll instance
	epollfd = epoll_create(10);
	if (epollfd == -1) {
		perror("epoll_create");
		exit(EXIT_FAILURE);
	}

	// set EPOLL
	memset(&ev,0,sizeof(ev));
	ev.events = EPOLLIN;
	ev.data.fd = fd;

	if (epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &(ev)) == -1) {
		perror("epoll_ctl");
		exit(EXIT_FAILURE);
	}
#endif

#ifdef SERIALPORT_READ_METHOD_SELECT
	maxfd = fd + 1;

	FD_ZERO(&readfds);
	FD_SET(fd,&readfds);
#endif

	return 0;
}

int CloseSerialPort(void){

#ifdef SERIALPORT_READ_METHOD_EPOLL
	close(epollfd);
#endif
	close(fd);
	// Restore previous port setting
	tcsetattr(fd, TCSANOW, &(oldtio));

	return 0;
}

int SerialSendData(SERIALSENDDATA* _serialSendData){
	int write_bytes = 0;

#ifdef SERIALPORT_USE_AES
	// Decide which AES Key will be used
	unsigned char *Cipher;
	int ran_key = rand() % 5;
	// Set AES Key byte
	(*_serialSendData).t_buffer[0] = ran_key;
	// Start AES cipher
	Cipher = aes(&((*_serialSendData).t_buffer[1]),AESKey[ran_key]);
	for (int k = 0; k < 16; k++) {
		(*_serialSendData).t_buffer[1 + k] = Cipher[k];
	}
#endif

	// Start generate CRC16 check code
	(*_serialSendData).CRC16((*_serialSendData).t_buffer, 22);

	write(fd, (*_serialSendData).t_buffer, 24);
	if(write_bytes < 0){
		perror("SerialSendData :");
	}

	return write_bytes;
}


#endif /* SERIALCOMM_H_ */
