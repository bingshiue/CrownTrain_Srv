/*
 * @file serial_subfunc.h
 * @brief Define sub functions using by UART communication.
 *
 */

#ifndef SERIAL_SUBFUNC_H_
#define SERIAL_SUBFUNC_H_

#include <stdio.h>
#include <vector>
#include "serialDataType.h"
#include "../protocol/uart_protocol_def.h"


/*** Function ProtoType ***/
int getSerialEvent(SERIALRECVDATA* _recvData,SERIALEVENT* _serial_event);

/**
 * @brief Get Serial Port Event.
 * @param _recvData Command data
 * @param _serial_event Serial port event
 * @retval 0 : successfully -1 : failure
 */
int getSerialEvent(SERIALRECVDATA* _recvData,SERIALEVENT* _serial_event){

	//Check Pointer is NULL or not
	if(_recvData==NULL || _serial_event==NULL){
		perror("get serial event failure");
		return -1;
	}

	//Get data 16 bytes
	for(unsigned int idx=UART_IDX_DATA_BEGIN; idx<=UART_IDX_DATA_END; idx++){
		_serial_event->_data[idx-UART_IDX_DATA_BEGIN] = _recvData->r_buffer[idx];
	}

	//Get data length
	_serial_event->_length = _recvData->r_buffer[UART_IDX_DATA_LENGTH];
	//Get group
	_serial_event->_group  = _recvData->r_buffer[UART_IDX_GROUP];
	//Get command
	_serial_event->_command= _recvData->r_buffer[UART_IDX_COMMAND];
	//Get action
	_serial_event->_action = _recvData->r_buffer[UART_IDX_ACTION];

	return 0;
}

/**
 * @brief Get Serial Port Event.
 * @param _recvData Command data
 * @param _serial_event Serial port event
 * @retval 0 : successfully -1 : failure
 */
int getSerialEvent(std::vector<SERIALRECVDATA>::iterator _recvData,SERIALEVENT* _serial_event){

	//Check Pointer is NULL or not
	if(/* _recvData==NULL || */ _serial_event==NULL){
		perror("get serial event failure");
		return -1;
	}

	//Get data 16 bytes
	for(unsigned int idx=UART_IDX_DATA_BEGIN; idx<=UART_IDX_DATA_END; idx++){
		_serial_event->_data[idx-UART_IDX_DATA_BEGIN] = _recvData->r_buffer[idx];
	}

	//Get data length
	_serial_event->_length = _recvData->r_buffer[UART_IDX_DATA_LENGTH];
	//Get group
	_serial_event->_group  = _recvData->r_buffer[UART_IDX_GROUP];
	//Get command
	_serial_event->_command= _recvData->r_buffer[UART_IDX_COMMAND];
	//Get action
	_serial_event->_action = _recvData->r_buffer[UART_IDX_ACTION];

	return 0;
}

#endif /* SERIAL_SUBFUNC_H_ */
