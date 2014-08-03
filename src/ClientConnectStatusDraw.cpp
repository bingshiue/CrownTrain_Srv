/**
 * @file ClientConnectStatusDraw.cpp
 *
 */
#include "../header/tasksystem/Task.h"

ClientConnectStatusDraw::ClientConnectStatusDraw(void){
	this->m_id = tid_ClientConnectStatusDraw;
	this->m_elapsedTimer = 0;
}

ClientConnectStatusDraw::~ClientConnectStatusDraw(void){

}

void ClientConnectStatusDraw::Draw(void){

	//Draw Line
	DrawLine(0,       0, 1023,       0, 2,COLOR(1.0f,1.0f,1.0f,1.0f));
	DrawLine(0,GETY(50), 1023, GETY(50),2,COLOR(1.0f,1.0f,1.0f,1.0f));
	DrawLine(0,GETY(526),1023,GETY(526),2,COLOR(1.0f,1.0f,1.0f,1.0f));
	DrawLine(0,GETY(574),1023,GETY(574),2,COLOR(1.0f,1.0f,1.0f,1.0f));

	DrawLine(0,       0,    0,GETY(575),2,COLOR(1.0f,1.0f,1.0f,1.0f));
	DrawLine(1023,    0, 1023,GETY(575),2,COLOR(1.0f,1.0f,1.0f,1.0f));

	for(unsigned int i=0,x=102; i<9; i++,x+=102){
		DrawLine(x,        0,x,GETY(50), 2,COLOR(1.0f,1.0f,1.0f,1.0f));
		DrawLine(x,GETY(526),x,GETY(575),2,COLOR(1.0f,1.0f,1.0f,1.0f));
	}

	//Draw Dark Number
	sheet_font.SetColor(COLOR(0.5f,0.5f,0.5f,1.0f));

	//1~10
	for(unsigned int i=1,x=(102-32)/2; i<=10; i++,x+=102){
		DrawFont(&sheet_font,256,32,32,20,font_align_none,i<10 ? x : x-8,GETY(9),  "%d",i);
	}
	//11~20
	for(unsigned int i=11,x=(102-32)/2; i<=20; i++,x+=102){
		DrawFont(&sheet_font,256,32,32,20,font_align_none,x-8,GETY(535),"%d",i);
	}

	//Draw Connecting Number
	sheet_font.SetColor(COLOR(0.0f,1.0f,0.0f,1.0f));

	//1~10
	std::map<bufferevent*,CLIENTDATA>::iterator cmit;
	for(unsigned int i=1,x=(102-32)/2; i<=10; i++,x+=102){
		for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
			if(cmit->second.client_id == i){
				DrawFont(&sheet_font,256,32,32,20,font_align_none,i<10 ? x : x-8,GETY(9),  "%d",i);
			}
		}
	}
	//11~20
	for(unsigned int i=11,x=(102-32)/2; i<=20; i++,x+=102){
		for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
			if(cmit->second.client_id == i){
				DrawFont(&sheet_font,256,32,32,20,font_align_none,x-8,GETY(535),"%d",i);
			}
		}
	}

	sheet_font.SetColor(COLOR(1.0f,1.0f,1.0f,1.0f));

	//
	ServerClientIDChecker* serverIDChecker = (ServerClientIDChecker*)this->GetTask(tid_ServerClientIDChecker,0);
	assert(serverIDChecker != NULL);
	DrawFont(&sheet_font,256,32,32,20,font_align_center,0,GETY(55),"Have %d(%d) clients",clientMap.size(),serverIDChecker->GetIDOKClientCount());


	unsigned long long totalIn = 0, sectionIn = 0;
	unsigned long long totalOut = 0, sectionOut = 0;
	unsigned long long totalMainGamePlayScores = 0, sectionMainGamePlayScores = 0;
	unsigned long long totalMainGameWinScores = 0, sectionMainGameWinScores = 0;

	std::map<bufferevent*, CLIENTDATA>::iterator clientIterator;

	for (clientIterator = clientMap.begin(); clientIterator != clientMap.end(); clientIterator++) {
		if (clientIterator->second.PassedValidationOrNot() == true) {
			totalIn += clientIterator->second.clientPlayData->m_all_time_record.m_coinIn + clientIterator->second.clientPlayData->m_all_time_record.m_keyIn;
			totalOut += clientIterator->second.clientPlayData->m_all_time_record.m_coinOut + clientIterator->second.clientPlayData->m_all_time_record.m_keyOut;
			totalMainGamePlayScores += clientIterator->second.clientPlayData->m_all_time_record.m_totalMainGamePlayScores;
			totalMainGameWinScores += clientIterator->second.clientPlayData->m_all_time_record.m_totalMainGameWinScores;

			sectionIn += clientIterator->second.clientPlayData->m_section_record.m_coinIn + clientIterator->second.clientPlayData->m_section_record.m_keyIn;
			sectionOut += clientIterator->second.clientPlayData->m_section_record.m_coinOut + clientIterator->second.clientPlayData->m_section_record.m_keyOut;
			sectionMainGamePlayScores += clientIterator->second.clientPlayData->m_section_record.m_totalMainGamePlayScores;
			sectionMainGameWinScores += clientIterator->second.clientPlayData->m_section_record.m_totalMainGameWinScores;
		}
	}

	DrawFont(&sheet_font, 256, 32, 32, 20, font_align_center, 0, GETY(87), "All Client Total In : %llu", totalIn);
	DrawFont(&sheet_font, 256, 32, 32, 20, font_align_center, 0, GETY(119), "All Client Total Out: %llu", totalOut);
	DrawFont(&sheet_font, 256, 32, 32, 20, font_align_center, 0, GETY(151), "All Client MainGamePlayScores : %llu", totalMainGamePlayScores);
	DrawFont(&sheet_font, 256, 32, 32, 20, font_align_center, 0, GETY(183), "All Client MainGameWinScores: %llu", totalMainGameWinScores);

	DrawFont(&sheet_font, 256, 32, 32, 20, font_align_center, 0, GETY(215), "Section Client Total In : %llu", sectionIn);
	DrawFont(&sheet_font, 256, 32, 32, 20, font_align_center, 0, GETY(247), "Section Client Total Out: %llu", sectionOut);
	DrawFont(&sheet_font, 256, 32, 32, 20, font_align_center, 0, GETY(279), "Section Client MainGamePlayScores : %llu", sectionMainGamePlayScores);
	DrawFont(&sheet_font, 256, 32, 32, 20, font_align_center, 0, GETY(311), "Section Client MainGameWinScores: %llu", sectionMainGameWinScores);

	//
	ServerMainProcess* mproc = (ServerMainProcess*)this->GetTask(tid_ServerMainProcess,0);

	//Draw Present JACKPOT Values
	//JACKPOT 1
	DrawFont(&sheet_font,256,32,32,20,font_align_center,0,GETY(430),"JP1: %d",mproc->getMainProcess()->m_jackpot1Value);
	//JACKPOT 2
	DrawFont(&sheet_font,256,32,32,20,font_align_center,0,GETY(462),"JP2: %d",mproc->getMainProcess()->m_jackpot2Value);
	//JACKPOT 3
	DrawFont(&sheet_font,256,32,32,20,font_align_center,0,GETY(494),"JP3: %d",mproc->getMainProcess()->m_jackpot3Value);

}

int ClientConnectStatusDraw::Main(double elapsedTime){

	return 0;
}




