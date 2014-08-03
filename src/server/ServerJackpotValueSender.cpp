/**
 * @file ServerJackpotValueSender.cpp
 * @brief Server Jackpot Value Sender.
 *
 */
#include "../../header/tasksystem/Task.h"

#define INTERVAL_SEND_TIME  3000/**< Interval Send Time */

ServerJackpotValueSender::ServerJackpotValueSender(void){
	this->m_id = tid_ServerJackpotValueSender;
	this->m_sendTimer = INTERVAL_SEND_TIME;
}

ServerJackpotValueSender::~ServerJackpotValueSender(void){

}

void ServerJackpotValueSender::Draw(void){

}

int ServerJackpotValueSender::Main(double elapsedTime){

	ServerMainProcess* mproc = (ServerMainProcess*)this->GetTask(tid_ServerMainProcess,0);

	if(mproc==NULL) return -1;

	this->m_sendTimer -= elapsedTime;
	if(this->m_sendTimer <= 0){

		mproc->getMainProcess()->m_jackpot1Value = mtRandom.getRandomLong(20000,30000);
		mproc->getMainProcess()->m_jackpot2Value = mtRandom.getRandomLong(10000,20000);
		mproc->getMainProcess()->m_jackpot3Value = mtRandom.getRandomLong( 1000,10000);

		//Send Jackpot Value to Client
        std::map<bufferevent*,CLIENTDATA>::iterator cmit;
        struct evbuffer *output;
        for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
        	output = bufferevent_get_output(cmit->second.bev);
        	NETWORKEVENT data;
			data._id          = 0;//server's ID is 0
			data._cmd_grp_id  = TCP_GID_JACKPOT;
			data._cmd_id      = CMDID_JACKPOT_RANDOM;
			data._data_length = 12;

			Utility::UnsignedIntegerToByte(mproc->getMainProcess()->m_jackpot1Value,&data._data[0]);
			Utility::UnsignedIntegerToByte(mproc->getMainProcess()->m_jackpot2Value,&data._data[4]);
			Utility::UnsignedIntegerToByte(mproc->getMainProcess()->m_jackpot3Value,&data._data[8]);

			evbuffer_add(output,&data,sizeof(NETWORKEVENT));

        }

		this->m_sendTimer = INTERVAL_SEND_TIME;
	}

	return 0;
}




