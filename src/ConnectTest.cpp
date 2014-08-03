/*
 * @fiile ConnectTest.cpp
 * @brief ConnectTest task.
 */
#include <vector>
#include <map>
#include "../header/tasksystem/Task.h"
#include "../header/protocol/tcpip_protocol_def.h"

ConnectTest::ConnectTest(void){
	this->m_id = tid_ConnectTest;
	this->m_elapsedTimer = 0.0;
}

ConnectTest::~ConnectTest(void){
	// Release textures
	//glDeleteTextures(1,&fixed_font.texnum);
}

void ConnectTest::NetworkMain(void* arg){//NETWORKEVENT* nevent){

	NETWORKEVENT* nevent = (NETWORKEVENT*)arg;

	// Declare iterator of client map
	std::map<bufferevent*,CLIENTDATA>::iterator cmit;
	// Find this data from which client
	cmit = clientMap.find(nevent->_bev);

	// Check client valid or not
	if(cmit == clientMap.end()){
		printf("No such client ConnectTest ! \n");
		return;
	}

	// For Check Client's ID
	std::map<bufferevent*,CLIENTDATA>::iterator cmit_tmp;

	switch(nevent->_cmd_grp_id){
	case TCP_GID_CONN:
		switch(nevent->_cmd_id){
		case  CMDID_CONN_REQUEST_ID:
			// Check ID, if ID duplicate return
			for(cmit_tmp=clientMap.begin();cmit_tmp!=clientMap.end();cmit_tmp++){
				if(cmit_tmp->second.client_id == nevent->_id){
					return;
				}
			}

			// Set up client ID
			cmit->second.client_id = nevent->_id;
			printf("Get client ID is %d \n",cmit->second.client_id);

			// Set up client play data structure
			cmit->second.clientPlayData = &(clientPlayData[cmit->second.client_id-1]);
			cmit->second.m_idCheckSuccess = true;

			break;
		case  CMDID_CONN_CLIENT_ALIVE:
			// Print client is alive
			printf("Client ID %d is alive \n",cmit->second.client_id);
			printf("NUM is %d \n",Utility::getUnsignedIntegerFromByte(nevent->_data[0],nevent->_data[1],nevent->_data[2],nevent->_data[3]));
			break;

		default:
			printf("Undefined Command ID of TCP_GID_CONN \n");
			break;
		}
		break;
	case TCP_GID_GAMESTAT:
		switch(nevent->_cmd_id){
		case CMDID_GAMESTAT_REQUEST:

			break;

		default:
			printf("Undefined Command ID of TCP_GID_GAMESTAT \n");
			break;
		}
		break;
	case TCP_GID_GAMEREC:
		switch(nevent->_cmd_id){
		case CMDID_GAMEREC_SECTIONREC:

			break;
		case CMDID_GAMEREC_ALLREC:

			break;
		case CMDID_GAMEREC_CURRENTREC:

			break;
		case CMDID_GAMEREC_PREVIOUSREC:

			break;

		default:
			printf("Undefined Command ID of TCP_GID_GAMEREC \n");
			break;
		}
		break;
	case TCP_GID_SETTING:
		switch(nevent->_cmd_id){
		case CMDID_SETTING_SURVEY:

			break;

		default:
			printf("Undefined Command ID of TCP_GID_SETTING \n");
			break;
		}
		break;
	case TCP_GID_PROBABILITY:
		switch(nevent->_cmd_id){
		case CMDID_PROBABILITY_CTRL:

			break;

		default:
			printf("Undefined Command ID of TCP_GID_PROBABILITY \n");
			break;
		}
		break;
	case TCP_GID_CREDIT:
		switch(nevent->_cmd_id){
		case CMDID_CREDIT_OPEN:

			break;
		case CMDID_CREDIT_CLEAR:

			break;
		case CMDID_CREDIT_CHECK:

			break;

		default:
			printf("Undefined Command ID of TCP_GID_CREDIT \n");
			break;
		}
		break;
	case TCP_GID_ERROR:
		switch(nevent->_cmd_id){
		case CMDID_ERROR_ID:

			break;
        case CMDID_ERROR_COINSET:

        	break;
        case CMDID_ERROR_LOCK:

        	break;

		default:
			printf("Undefined Command ID of TCP_GID_ERROR \n");
			break;
		}
		break;
	case TCP_GID_SPBONUS:
		switch(nevent->_cmd_id){
		case CMDID_SPBONUS_OPEN_KIND:

			break;
		case CMDID_SPBONUS_OPEN_CHECK:

			break;
		case CMDID_SPBONUS_CANCEL:

			break;

		default:
			printf("Undefined Command ID of TCP_GID_SPBONUS \n");
			break;
		}
		break;
	case TCP_GID_JACKPOT:
		switch(nevent->_cmd_id){
		case CMDID_JACKPOT_STANDBY_CHECK:

			break;
		case CMDID_JACKPOT_OPEN_KIND:

			break;
		case CMDID_JACKPOT_OPEN_CHECK:

			break;
		case CMDID_JACKPOT_CANCEL:

			break;
		case CMDID_JACKPOT_RANDOM:

			break;

		default:
			printf("Undefined Command ID of TCP_GID_JACKPOT \n");
			break;
		}
		break;

	default:
		printf("Undefined Group Command ID ! \n");
		break;
	}
}

void ConnectTest::Draw(void){
	DrawFont(&sheet_font,256,32,32,20,font_align_center,0,GETY(55),"Total %d(%d) clients",clientMap.size(),idCheckOKClientCount);
}

int ConnectTest::Main(double elapsedTime){

	std::map<bufferevent*,CLIENTDATA>::iterator cmit;

    //Print how many client have
	this->m_elapsedTimer += elapsedTime;
	if(this->m_elapsedTimer > 2000.0){
		idCheckOKClientCount = 0;
		for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
			if(cmit->second.m_idCheckSuccess==true){
				idCheckOKClientCount++;
			}
		}
		printf("client's count is %d(%d) \n",clientMap.size(),idCheckOKClientCount);
		this->m_elapsedTimer = 0;
	}

	//Check client alive or not every 1 second
    this->m_aliveTimer += elapsedTime;
    if(this->m_aliveTimer > 1000.0){
    	for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
    		if(cmit->second.m_idCheckSuccess == true){
				struct evbuffer *output = bufferevent_get_output(cmit->second.bev);
				NETWORKEVENT tran;
				tran._id          = 0;//server's ID is 0
				tran._cmd_grp_id  = TCP_GID_CONN;
				tran._cmd_id      = CMDID_CONN_CLIENT_ALIVE;
				tran._data_length = 0;
				evbuffer_add(output,&tran,sizeof(NETWORKEVENT));
    		}
    	}
    	this->m_aliveTimer = 0.0;
    }

	return 0;
}
