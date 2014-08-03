/**
 * @file ServerClientSettingValueChecker.cpp
 * @brief Server Client Setting Value Checker.
 *
 */
#include "../../header/tasksystem/Task.h"

#define SETTING_VALUE_CHECK_INTERVAL_TIME   5000

ServerClientSettingValueChecker::ServerClientSettingValueChecker(void){
	this->m_id = tid_ServerClientSettingValueChecker;
	this->m_elapsedTimer = 0;
	this->m_settingValueCheckTimer = 0;
}

ServerClientSettingValueChecker::~ServerClientSettingValueChecker(void){

}

void ServerClientSettingValueChecker::NetworkMain(void* arg){

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

	case TCP_GID_SETTING:
		switch (nevent->_cmd_id) {

		case CMDID_SETTING_SURVEY:
			printf("Get Game All Setting Data, Size is %d \n",nevent->_data_length);

			for(unsigned int idx=0; idx<nevent->_data_length; idx++){
				*((unsigned char*)&(clientIterator->second.clientPlayData->m_gameAllSettingData)+idx) = *(nevent->_data+idx);
			}

			clientIterator->second.m_settingValueCheckSuccess = true;

			printf("%4.2f \n",clientIterator->second.clientPlayData->m_gameAllSettingData.probabilitySettingData._MainProSetting);

		    break;

		default:
			break;
		}
		break;

	default:
		break;
	}

}

void ServerClientSettingValueChecker::Draw(void){

}

int ServerClientSettingValueChecker::Main(double elapsedTime){

	std::map<bufferevent*, CLIENTDATA>::iterator clientIterator;

	//
	this->m_settingValueCheckTimer += elapsedTime;
	if(this->m_settingValueCheckTimer >= SETTING_VALUE_CHECK_INTERVAL_TIME){

		//
		for (clientIterator = clientMap.begin(); clientIterator != clientMap.end(); clientIterator++) {

			//
			if(clientIterator->second.m_idCheckSuccess == true){
				//
				if(clientIterator->second.m_settingValueCheckSuccess == false){
					//
					struct evbuffer* output = bufferevent_get_output(clientIterator->second.bev);
					NETWORKEVENT netEvent;
					memset(&netEvent, 0, sizeof(NETWORKEVENT));
					netEvent._id = 0; //server's ID is 0
					netEvent._cmd_grp_id = TCP_GID_SETTING;
					netEvent._cmd_id = CMDID_SETTING_SURVEY;
					netEvent._data_length = 0;
					evbuffer_add(output, &netEvent, sizeof(NETWORKEVENT));
				}
			}
		}

		//
		this->m_settingValueCheckTimer = 0;
	}

	return 0;
}






