/**
 * @file gameEvent.h
 *
 */

#ifndef GAMEEVENT_H_
#define GAMEEVENT_H_

#include <event.h>

/**
 * @brief Key Board Event.
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-08-05
 */
typedef struct KeyEvent{
    unsigned int eventKind;
	unsigned int button;

	void _reset(){
		this->eventKind = 0x00;
        this->button = 0x00;
	}
}KEYEVENT;
/**
 * @brief Serial Port Event.
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-08-05
 */
typedef struct SerialEvent{
    unsigned char _group;
    unsigned char _action;
    unsigned char _length;
    unsigned char _data[16];
    unsigned char _command;
}SERIALEVENT;

#define NETWORK_DATA_SIZE  (8*1024)//8K bytes
/**
 * @brief Network Event.
 */
typedef struct NetworkEvent{
	unsigned int  _id;/**< data's id */
    unsigned char _cmd_grp_id;/**< data's command group ID */
	unsigned char _cmd_id;/**< data's command ID */
	unsigned int  _data_length;/**< data's length */
	unsigned char _data[NETWORK_DATA_SIZE];/**< data */
    bufferevent*  _bev;
}NETWORKEVENT;


#endif /* GAMEEVENT_H_ */
