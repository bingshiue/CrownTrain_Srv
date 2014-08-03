/**
 * @file ServerClientPlayDataPreChecker.cpp
 * @brief Server Client Play Data Pre Checker.
 *
 */
#include "../../header/tasksystem/Task.h"

#define PLAY_DATA_CHECK_INTERVAL_TIME   1000

ServerClientPlayDataPreChecker::ServerClientPlayDataPreChecker(void) {
	this->m_id = tid_ServerClientPlayDataPreChecker;
	this->m_elapsedTimer = 0;
	this->m_playDataCheckTimer = 0;
}

ServerClientPlayDataPreChecker::~ServerClientPlayDataPreChecker(void) {

}

void ServerClientPlayDataPreChecker::NetworkMain(void* arg) {

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

	unsigned int idx = 0;
	switch (nevent->_cmd_grp_id) {

	case TCP_GID_GAMEREC:
		switch (nevent->_cmd_id) {

		case CMDID_GAMEREC_SURVEY:

			printf("CMDID_GAMEREC_SURVEY : %d \n", nevent->_data_length);

			// Check client data correct or not
			//if(...){
				//new(TP_ServerClientPlayDataSync) ServerClientPlayDataSync();
				//return;
			//}
			//

			for (; idx < sizeof(GAMEPLAYRECORD); idx++) {
				*((unsigned char*) &clientIterator->second.clientPlayData->m_all_time_record + idx) = *(nevent->_data + idx);
			}

			for (; idx < sizeof(GAMEPLAYRECORD) * 2; idx++) {
				*((unsigned char*) &clientIterator->second.clientPlayData->m_current_term_record + idx) = *(nevent->_data + (idx - sizeof(GAMEPLAYRECORD)));
			}

			for (; idx < sizeof(GAMEPLAYRECORD) * 3; idx++) {
				*((unsigned char*) &clientIterator->second.clientPlayData->m_section_record + idx) = *(nevent->_data + (idx - sizeof(GAMEPLAYRECORD) * 2));
			}

			clientIterator->second.m_playDataCheckSuccess = true;

			break;

		default:
			break;
		}
		break;

	default:
		break;
	}

}

void ServerClientPlayDataPreChecker::Draw(void) {

}

int ServerClientPlayDataPreChecker::Main(double elapsedTime) {

	std::map<bufferevent*, CLIENTDATA>::iterator clientIterator;

	//
	this->m_playDataCheckTimer += elapsedTime;
	if (this->m_playDataCheckTimer >= PLAY_DATA_CHECK_INTERVAL_TIME) {

		//
		for (clientIterator = clientMap.begin(); clientIterator != clientMap.end(); clientIterator++) {
			//
			if (clientIterator->second.m_idCheckSuccess == true) {
				//
				if (clientIterator->second.m_settingValueCheckSuccess == true) {
					//
					if(clientIterator->second.m_playDataCheckSuccess == false){
						//
						struct evbuffer* output = bufferevent_get_output(clientIterator->second.bev);
						NETWORKEVENT netEvent;
						memset(&netEvent, 0, sizeof(NETWORKEVENT));
						netEvent._id = 0; //server's ID is 0
						netEvent._cmd_grp_id = TCP_GID_GAMEREC;
						netEvent._cmd_id = CMDID_GAMEREC_SURVEY;
						netEvent._data_length = 0;
						evbuffer_add(output, &netEvent, sizeof(NETWORKEVENT));
					}

				}

			}

		}

		//
		this->m_playDataCheckTimer = 0;
	}

	return 0;
}

