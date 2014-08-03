/**
 * @file ServerClientIDDuplicateNotifier.cpp
 * @brief Server Client ID Duplicate Notifier.
 *
 */
#include "../../header/tasksystem/Task.h"

#define NOTIFY_INTERVAL_TIME  500

ServerClientIDDuplicateNotifier::ServerClientIDDuplicateNotifier(bufferevent* bev){
	this->m_id = tid_ServerClientIDDuplicateNotifier;
	this->m_notifyTimer = 0;
	this->m_bufferevent = bev;
}

ServerClientIDDuplicateNotifier::~ServerClientIDDuplicateNotifier(void){

}

void ServerClientIDDuplicateNotifier::Draw(void){

}

int ServerClientIDDuplicateNotifier::Main(double elapsedTime){

	//
	this->m_notifyTimer += elapsedTime;
	if(this->m_notifyTimer >= NOTIFY_INTERVAL_TIME){

		//
		struct evbuffer* output = bufferevent_get_output(this->m_bufferevent);
		NETWORKEVENT netEvent;
		memset(&netEvent, 0, sizeof(NETWORKEVENT));
		netEvent._id = 0; //server's ID is 0
		netEvent._cmd_grp_id = TCP_GID_ERROR;
		netEvent._cmd_id = CMDID_ERROR_ID;
		netEvent._data_length = 0;
		evbuffer_add(output, &netEvent, sizeof(NETWORKEVENT));

		//
		this->m_notifyTimer = 0;
		delete this;
	}

	return 0;
}




