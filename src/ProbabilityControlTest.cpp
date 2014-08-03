/*
 * @file ProbabilityControlTest.cpp
 * @brief ProbabilityControlTest Task
 */
#include <vector>
#include <map>
#include "../header/tasksystem/Task.h"
#include "../header/protocol/tcpip_protocol_def.h"

ProbabilityControlTest::ProbabilityControlTest(void){
	this->m_elapsedTimer = 0.0f;
	this->m_id = tid_ProbabilityControlTest;
}

ProbabilityControlTest::~ProbabilityControlTest(void){

}

void ProbabilityControlTest::NetworkMain(void* arg){//NETWORKEVENT* nevent){

	NETWORKEVENT* nevent = (NETWORKEVENT*)arg;

	const char* game_level_str[3]    = { "game_level_big","game_level_middle","game_level_small"};
	const char* game_lot_stat_str[3] = { "game_lot_normal","game_lot_pull_down","game_lot_pull_up"};

	// Declare iterator of client map
	std::map<bufferevent*,CLIENTDATA>::iterator cmit;
	// Find this data from which client
	cmit = clientMap.find(nevent->_bev);

	// Check client valid or not
	if(cmit == clientMap.end()){
		printf("No such client ! \n");
		return;
	}

	switch(nevent->_cmd_grp_id){
	case TCP_GID_PROBABILITY:
		switch(nevent->_cmd_id){
		case CMDID_PROBABILITY_CTRL:

			printf("ID %d => Set Probability to : %d \n",cmit->second.client_id,nevent->_data[0]);
			printf("ID %d => Set Game level to  : %s \n",cmit->second.client_id,game_level_str[nevent->_data[1]]);
			printf("ID %d => Set Game lot to    : %s \n",cmit->second.client_id,game_lot_stat_str[nevent->_data[2]]);

			break;

		default:
			printf("Undefined Command ID of TCP_GID_GAMEREC \n");
			break;
		}
		break;

	default:
		break;
	}


}

void ProbabilityControlTest::Draw(void){

}

int ProbabilityControlTest::Main(double elapsedTime){

	std::map<bufferevent*,CLIENTDATA>::iterator cmit;

	// Request Section play data
	this->m_elapsedTimer += elapsedTime;
	if(this->m_elapsedTimer >= 1000.0){
    	for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
    		if(cmit->second.m_idCheckSuccess == true){
				struct evbuffer *output = bufferevent_get_output(cmit->second.bev);
				NETWORKEVENT tran;
				tran._id          = 0;//server's ID is 0
				tran._cmd_grp_id  = TCP_GID_PROBABILITY;
				tran._cmd_id      = CMDID_PROBABILITY_CTRL;
				tran._data_length = 3;
				tran._data[0] = 98;
				tran._data[1] = game_level_big;
				tran._data[2] = game_lot_pull_down;
				evbuffer_add(output,&tran,sizeof(NETWORKEVENT));
    		}
    	}
		this->m_elapsedTimer=0;
	}

	return 0;
}

