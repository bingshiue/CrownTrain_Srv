/**
 * @file ServerClientPlayDataSync.cpp
 * @brief Server Client Play Data Sync.
 *
 */
#include "../../header/tasksystem/Task.h"

ServerClientPlayDataSync::ServerClientPlayDataSync(bufferevent* bev){
	this->m_id = tid_ServerClientPlayDataSync;
	this->m_playDataSyncTimer = 0;
	this->m_bufferevent = bev;
}

ServerClientPlayDataSync::~ServerClientPlayDataSync(void){

}

void ServerClientPlayDataSync::NetworkMain(void* arg){

	//NETWORKEVENT* nevent = (NETWORKEVENT*) arg;

}

void ServerClientPlayDataSync::Draw(void){

}

int ServerClientPlayDataSync::Main(double elapsedTime){

	//
	if(this->m_bufferevent == NULL){
		delete this;
	}

	//
	this->m_playDataSyncTimer += elapsedTime;
	if(this->m_playDataSyncTimer > 0){
		//
		struct evbuffer* output = bufferevent_get_output(this->m_bufferevent);
		NETWORKEVENT netEvent;
		memset(&netEvent, 0, sizeof(NETWORKEVENT));
		netEvent._id = 0; //server's ID is 0
		netEvent._cmd_grp_id = TCP_GID_GAMEREC;
		netEvent._cmd_id = CMDID_GAMEREC_SYNC;
		netEvent._data_length = 0;
		evbuffer_add(output, &netEvent, sizeof(NETWORKEVENT));

		//
		this->m_playDataSyncTimer = 0;
		// Delete this
		delete this;
	}

	return 0;
}






