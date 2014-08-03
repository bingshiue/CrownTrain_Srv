/**
 * @file ServerClientIDChecker.cpp
 * @brief Server Client ID Checker.
 *
 */
#include "../../header/tasksystem/Task.h"

#define ID_CHECK_INTERVAL_TIME     5000
#define ALIVE_CHECK_INTERVAL_TIME  10000

ServerClientIDChecker::ServerClientIDChecker(void) {
	this->m_id = tid_ServerClientIDChecker;
	this->m_elapsedTimer = 0;
	this->m_idCheckerTimer = 0;
	this->m_aliveCheckTimer = 0;
}

ServerClientIDChecker::~ServerClientIDChecker(void) {

}

void ServerClientIDChecker::NetworkMain(void* arg) {

	NETWORKEVENT* nevent = (NETWORKEVENT*) arg;

	// Declare iterator of client map
	std::map<bufferevent*, CLIENTDATA>::iterator clientIterator;
	std::map<bufferevent*, CLIENTDATA>::iterator clientDuplicateIterator;
	// Find this data from which client
	clientIterator = clientMap.find(nevent->_bev);

	// Check client valid or not
	if (clientIterator == clientMap.end()) {
		printf("### No Such Client : %s,%d \n", __FILE__, __LINE__);
		return;
	}

	switch (nevent->_cmd_grp_id) {
	case TCP_GID_CONN:
		switch (nevent->_cmd_id) {
		case CMDID_CONN_REQUEST_ID:
			// Check ID, if ID duplicate return
			for (clientDuplicateIterator = clientMap.begin(); clientDuplicateIterator != clientMap.end(); clientDuplicateIterator++) {
				if (clientDuplicateIterator->second.client_id == nevent->_id) {
					//
					new(TP_ServerClientIDDuplicateNotifier) ServerClientIDDuplicateNotifier(nevent->_bev);
					//
					return;
				}
			}

			// Set up client ID
			clientIterator->second.client_id = nevent->_id;
			clientIterator->second.previousClientID = clientIterator->second.client_id;
			printf("Client ID is %d \n", clientIterator->second.client_id);

			// Set up client play data structure
			clientIterator->second.clientPlayData = &(clientPlayData[clientIterator->second.client_id - 1]);
			clientIterator->second.m_idCheckSuccess = true;

			break;
		case CMDID_CONN_CLIENT_ALIVE:
			// Print client is alive
			printf("Client ID %d is Alive \n", clientIterator->second.client_id);
			//printf("NUM is %d \n", Utility::getUnsignedIntegerFromByte(nevent->_data[0], nevent->_data[1], nevent->_data[2], nevent->_data[3]));

			// Check If Client Change ID or Not
			if(clientIterator->second.client_id != nevent->_id){
				// Reset Client Connect Flags
				clientIterator->second.ResetConnectStatusFlags();
			}

			break;

		case CMDID_CONN_CHANGE_ID:
			// Client Change ID
			// Reset Client Connect Flags
			clientIterator->second.ResetConnectStatusFlags();

			break;

		default:
			printf("### Undefined Command ID of TCP_GID_CONN ! : %s:%d \n",__FILE__,__LINE__);
			break;
		}
		break;

	default:
		break;
	}
}

void ServerClientIDChecker::Draw(void) {

}

int ServerClientIDChecker::Main(double elapsedTime) {

	std::map<bufferevent*, CLIENTDATA>::iterator clientIterator;

	//
	this->m_idCheckerTimer += elapsedTime;
	if (this->m_idCheckerTimer >= ID_CHECK_INTERVAL_TIME) {

		//
		for (clientIterator = clientMap.begin(); clientIterator != clientMap.end(); clientIterator++) {
			//
			if (clientIterator->second.m_idCheckSuccess == false) {
				//
				struct evbuffer* output = bufferevent_get_output(clientIterator->second.bev);
				NETWORKEVENT netEvent;
				memset(&netEvent, 0, sizeof(NETWORKEVENT));
				netEvent._id = 0; //server's ID is 0
				netEvent._cmd_grp_id = TCP_GID_CONN;
				netEvent._cmd_id = CMDID_CONN_REQUEST_ID;
				netEvent._data_length = 0;
				evbuffer_add(output, &netEvent, sizeof(NETWORKEVENT));
			}
		}
		//
		this->m_idCheckerTimer = 0;
	}

	//
	this->m_aliveCheckTimer += elapsedTime;
	if (this->m_aliveCheckTimer >= ALIVE_CHECK_INTERVAL_TIME) {

		//
		m_idOKClientCount = 0;
		for (clientIterator = clientMap.begin(); clientIterator != clientMap.end(); clientIterator++) {
			//
			if (clientIterator->second.PassedValidationOrNot() == true) {
				//
				struct evbuffer* output = bufferevent_get_output(clientIterator->second.bev);
				NETWORKEVENT netEvent;
				memset(&netEvent, 0, sizeof(NETWORKEVENT));
				netEvent._id = 0; //server's ID is 0
				netEvent._cmd_grp_id = TCP_GID_CONN;
				netEvent._cmd_id = CMDID_CONN_CLIENT_ALIVE;
				netEvent._data_length = 0;
				evbuffer_add(output, &netEvent, sizeof(NETWORKEVENT));
				//
				m_idOKClientCount++;
			}
		}
		//
		this->m_aliveCheckTimer = 0;
	}

	return 0;
}

int ServerClientIDChecker::GetIDOKClientCount(void){
	return this->m_idOKClientCount;
}

