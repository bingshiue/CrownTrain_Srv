/**
 * @file     TaskSystemEx.h
 * @brief    Game Sequence Control System.
 *
 * @author   SHIE-BINGSHIUE
 * @date     2010/08/05
 */
#ifndef _TASKSYSTEMEX_H_
#define _TASKSYSTEMEX_H_

#include <iostream>
using namespace std;
#include "TaskSystem.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <event.h>

/**
 * Type of TaskSystem initial function.
 */
typedef void (*TASKINITFUNCTION)(void);
#if 0
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

#define NETWORK_DATA_SIZE  (20*1024)//20K bytes
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
#endif
/**
 * @brief Additional Task Data.
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-08-05
 */
struct DATA
{
	int id;
	float cx,cy;
	float hit_cw,hit_ch;
	float speed;
	DWORD life,max_life;
	float rot;
	BYTE alpha;
};
/**
 * @brief TaskEx Object.
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-08-05
 */
class TaskEx : public Task
{
protected:
	int m_id;/**< ID of Task */
	float m_cx,m_cy;/**< x,y position of Task */
	float m_hit_cw,m_hit_ch;/**< hit cw,ch of Task */
	float m_speed;/**< Speed of Task */
	DWORD m_life,m_max_life;/**< Life of Task */
	float m_rot;/**< Rot of Task */
	BYTE  m_alpha;/**< Alpha Value of Task */
public:
	/**
	 * @brief Constructor.
	 *
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	TaskEx(void);
	/**
	 * @brief Initialize Task System.
	 *
	 * @taskInitFunction Function that run after TaskSystem initialization completed
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	static void InitTaskList(TASKINITFUNCTION taskInitFunction);
	/**
	 * @brief Delete Task(with specified id).
	 *
	 * @id Specified ID
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	void Delete(int id);
	/**
	 * @brief Process Key Board Event.
	 *
	 * @kevent Key Board Event
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	static void KeyEventTask(void* arg);//KEYEVENT* kevent);
	/**
	 * @brief Process Serial Port Event.
	 *
	 * @sevent Serial Port Event
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	static void SerialEventTask(void* arg);//SERIALEVENT* sevent);
	/**
	 * @brief Process Network Event.
	 *
	 * @param nevent Network Event
	 * @author SHIE-BINGSHIUE
	 * @date 2011-12-04
	 */
	static void NetWorkEventTask(void* arg);//NETWORKEVENT* nevent);
	/**
	 * @brief Draw all task in TaskSystem.
	 *
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	static void DrawTask(void);
	/**
	 * @brief Draw task(with specified id) in TaskSystem .
	 *
	 * @param id Specified ID
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	static void DrawTask(int id);
	/**
	 * @brief Get Task's(with specified id) count.
	 *
	 * @param id Specified ID
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	static DWORD GetCount(int id);
	/**
	 * @brief Get Task's(with specified id) address.
	 *
	 * @param id Specified ID
	 * @param number Number of Task
	 * @retval Task's(with specified id) address
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	static void* GetTask(int id,DWORD number);
	/**
	 * @brief Get Task's additional data.
	 *
	 * @param pData pointer of additional data
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	void GetData(DATA *pData);
	/**
	 * @brief Task's Key Board event process function.
	 *
	 * @param kevent Key Board event
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	virtual void KeyMain(void* arg);//KEYEVENT* kevent);
	/**
	 * @brief Task's Serial port event process function.
	 *
	 * @param sevent Serial port event
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	virtual void SerialMain(void* arg);//SERIALEVENT* sevent);
	/**
	 * @brief Task's Network event process function.
	 *
	 * @param nevent Network event
	 * @author SHIE-BINGSHIUE
	 * @data 2011-12-04
	 */
	virtual void NetworkMain(void* arg);//NETWORKEVENT* nevent);
	/**
	 * @brief Task's draw function.
	 *
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-05
	 */
	virtual void Draw(void)=0;
};

#endif
