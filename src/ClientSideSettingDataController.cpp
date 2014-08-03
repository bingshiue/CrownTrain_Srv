/**
 * @file ClientSideSettingDataController.cpp
 * @brief Client Side Setting Data Controller.
 *
 */
#include "../header/tasksystem/Task.h"

ClientSideSettingDataController::ClientSideSettingDataController(GAMEALLSETTINGDATA* clientSideGameAllSettingData){
	this->m_id = tid_ClientSideSettingDataController;
	this->m_elapsedTimer = 0;
	this->m_clientSideGameAllSettingData = clientSideGameAllSettingData;
}

ClientSideSettingDataController::~ClientSideSettingDataController(void){

}

void ClientSideSettingDataController::Draw(void){

}

int ClientSideSettingDataController::Main(double elapsedTime){

	return 0;
}

GAMEALLSETTINGDATA* ClientSideSettingDataController::getClientSideGameAllSettingData(void){
	return this->m_clientSideGameAllSettingData;
}




