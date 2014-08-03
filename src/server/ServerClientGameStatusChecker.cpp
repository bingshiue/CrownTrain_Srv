/**
 * @file ServerClientGameStatusChecker.cpp
 * @brief Server Client Game Status Checker.
 *
 */
#include "../../header/tasksystem/Task.h"

#define GAME_STATUS_CHECK_INTERVAL_TIME   10000

ServerClientGameStatusChecker::ServerClientGameStatusChecker(void){
	this->m_id = tid_ServerClientGameStatusChecker;
	this->m_gameStatusCheckTimer = 0;
}

ServerClientGameStatusChecker::~ServerClientGameStatusChecker(void){

}

void ServerClientGameStatusChecker::NetworkMain(void* arg){

	NETWORKEVENT* nevent = (NETWORKEVENT*) arg;

	// Declare iterator of client map
	std::map<bufferevent*, CLIENTDATA>::iterator clientIterator;
	// Find this data from which client
	clientIterator = clientMap.find(nevent->_bev);

	// Check client valid or not
	if (clientIterator == clientMap.end()) {
		printf("### No Such Client : %s,%d \n", __FILE__, __LINE__);
		return;
	}

	switch (nevent->_cmd_grp_id) {

	case TCP_GID_GAMESTAT:
		switch (nevent->_cmd_id) {

		case CMDID_GAMESTAT_REQUEST:
			//

			break;

		default:
			printf("### Undefined Command ID of TCP_GID_GAMESTAT ! : %s:%d \n",__FILE__,__LINE__);
			break;
		}

		break;

	default:
		break;
	}

}

void ServerClientGameStatusChecker::Draw(void){

}

int ServerClientGameStatusChecker::Main(double elapsedTime){

	std::map<bufferevent*, CLIENTDATA>::iterator clientIterator;

	//
	this->m_gameStatusCheckTimer += elapsedTime;
	if(this->m_gameStatusCheckTimer >= GAME_STATUS_CHECK_INTERVAL_TIME){
		//
		for (clientIterator = clientMap.begin(); clientIterator != clientMap.end(); clientIterator++) {
			//
			if(clientIterator->second.PassedValidationOrNot()==true){
				//
				struct evbuffer* output = bufferevent_get_output(clientIterator->second.bev);
				NETWORKEVENT netEvent;
				memset(&netEvent, 0, sizeof(NETWORKEVENT));
				netEvent._id = 0; //server's ID is 0
				netEvent._cmd_grp_id = TCP_GID_GAMESTAT;
				netEvent._cmd_id = CMDID_GAMESTAT_REQUEST;
				netEvent._data_length = 0;
				evbuffer_add(output, &netEvent, sizeof(NETWORKEVENT));
			}
		}

		//
		this->m_gameStatusCheckTimer = 0;
	}

	return 0;
}





