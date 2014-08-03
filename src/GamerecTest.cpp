/*
 * @fiile GamerecTest.cpp
 * @brief GamerecTest task.
 */
#include <vector>
#include <map>
#include "../header/tasksystem/Task.h"
#include "../header/protocol/tcpip_protocol_def.h"

GamerecTest::GamerecTest(void){
	this->m_id = tid_GamerecTest;
	this->m_elapsedTimer = 0.0;
}

GamerecTest::~GamerecTest(void){

}

void GamerecTest::NetworkMain(void* arg){//NETWORKEVENT* nevent){

	NETWORKEVENT* nevent = (NETWORKEVENT*)arg;

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
	case TCP_GID_GAMEREC:
		switch(nevent->_cmd_id){
		case CMDID_GAMEREC_SECTIONREC:

			/* In & Out */
			cmit->second.clientPlayData->m_section_record.m_in = Utility::getUnsignedIntegerFromAddr(&nevent->_data[0]);/**< Total in coins */
			cmit->second.clientPlayData->m_section_record.m_out = Utility::getUnsignedIntegerFromAddr(&nevent->_data[4]);/**< Total out coins */
			cmit->second.clientPlayData->m_section_record.m_keyIn = Utility::getUnsignedIntegerFromAddr(&nevent->_data[8]);/**< Total key in coins */
			cmit->second.clientPlayData->m_section_record.m_keyOut = Utility::getUnsignedIntegerFromAddr(&nevent->_data[12]);/**< Total key out coins */
			cmit->second.clientPlayData->m_section_record.m_coinIn = Utility::getUnsignedIntegerFromAddr(&nevent->_data[16]);/**< Total coin in coins */
			cmit->second.clientPlayData->m_section_record.m_coinOut = Utility::getUnsignedIntegerFromAddr(&nevent->_data[20]);/**< Total coin out coins */
			cmit->second.clientPlayData->m_section_record.m_masterOpen = Utility::getUnsignedIntegerFromAddr(&nevent->_data[24]);/**< Total key in coins from master */
			cmit->second.clientPlayData->m_section_record.m_masterClear = Utility::getUnsignedIntegerFromAddr(&nevent->_data[28]);/**< Total key out coins from master */
		    /* Main Game */
			cmit->second.clientPlayData->m_section_record.m_totalMainGamePlayScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[32]);/**< Total main game play scores */
			cmit->second.clientPlayData->m_section_record.m_totalMainGameWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[36]);/**< Total main game win scores */
			cmit->second.clientPlayData->m_section_record.m_totalMainGamePlayTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[40]);/**< Total main game play times */
			cmit->second.clientPlayData->m_section_record.m_totalMainGameWinTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[44]);/**< Total main game win times */
			cmit->second.clientPlayData->m_section_record.m_totalMainGameOverTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[48]);/**< Total main game over max credit times */
		    /* Double Game */
			cmit->second.clientPlayData->m_section_record.m_totalDoubleGamePlayScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[52]);/**< Total double game play scores */
			cmit->second.clientPlayData->m_section_record.m_totalDoubleGameWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[56]);/**< Total double game win scores */
			cmit->second.clientPlayData->m_section_record.m_totalDoubleGamePlayTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[60]);/**< Total double game play times */
			cmit->second.clientPlayData->m_section_record.m_totalDoubleGameWinTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[64]);/**< Total double game win times */
			cmit->second.clientPlayData->m_section_record.m_totalDoubleGameOverTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[68]);/**< Total double game over max credit times */
		    /* Special Game */
			cmit->second.clientPlayData->m_section_record.m_totalSpecialGameEnterTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[72]);/**< Total special game enter times */
			cmit->second.clientPlayData->m_section_record.m_totalSpecialGamePlayScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[76]);/**< Total special game play scores */
			cmit->second.clientPlayData->m_section_record.m_totalSpecialGameWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[80]);/**< Total special game win scores */
			cmit->second.clientPlayData->m_section_record.m_totalSpecialGamePlayTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[84]);/**< Total special game play times */
			cmit->second.clientPlayData->m_section_record.m_totalSpecialGameWinTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[88]);/**< Total special game win times */
		    /* Jackpot */
			cmit->second.clientPlayData->m_section_record.m_jp1Times = Utility::getUnsignedIntegerFromAddr(&nevent->_data[92]);/**< Total JP1 times */
			cmit->second.clientPlayData->m_section_record.m_jp1Score = Utility::getUnsignedIntegerFromAddr(&nevent->_data[96]);/**< Total JP1 scores */
			cmit->second.clientPlayData->m_section_record.m_jp2Times = Utility::getUnsignedIntegerFromAddr(&nevent->_data[100]);/**< Total JP2 times */
			cmit->second.clientPlayData->m_section_record.m_jp2Score = Utility::getUnsignedIntegerFromAddr(&nevent->_data[104]);/**< Total JP2 scores */
			cmit->second.clientPlayData->m_section_record.m_jp3Times = Utility::getUnsignedIntegerFromAddr(&nevent->_data[108]);/**< Total JP3 times */
			cmit->second.clientPlayData->m_section_record.m_jp3Score = Utility::getUnsignedIntegerFromAddr(&nevent->_data[112]);/**< Total JP3 scores */

			//cmit->second.clientPlayData->sectionRec._PlayScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[0]);
			//cmit->second.clientPlayData->sectionRec._WinScores  = Utility::getUnsignedIntegerFromAddr(&nevent->_data[4]);
			//cmit->second.clientPlayData->sectionRec._PlayTimes  = Utility::getUnsignedIntegerFromAddr(&nevent->_data[8]);
			//cmit->second.clientPlayData->sectionRec._WinTimes   = Utility::getUnsignedIntegerFromAddr(&nevent->_data[12]);

			//printf("ID %d => Section Play Scores : %d \n",cmit->second.client_id,cmit->second.clientPlayData->sectionRec._PlayScores);
			//printf("ID %d => Section Win  Scores : %d \n",cmit->second.client_id,cmit->second.clientPlayData->sectionRec._WinScores);
			//printf("ID %d => Section Play Times  : %d \n",cmit->second.client_id,cmit->second.clientPlayData->sectionRec._PlayTimes);
			//printf("ID %d => Section Win  Times  : %d \n",cmit->second.client_id,cmit->second.clientPlayData->sectionRec._WinTimes);

			break;
		case CMDID_GAMEREC_ALLREC:

			/* In & Out */
			cmit->second.clientPlayData->m_all_time_record.m_in = Utility::getUnsignedIntegerFromAddr(&nevent->_data[0]);/**< Total in coins */
			cmit->second.clientPlayData->m_all_time_record.m_out = Utility::getUnsignedIntegerFromAddr(&nevent->_data[4]);/**< Total out coins */
			cmit->second.clientPlayData->m_all_time_record.m_keyIn = Utility::getUnsignedIntegerFromAddr(&nevent->_data[8]);/**< Total key in coins */
			cmit->second.clientPlayData->m_all_time_record.m_keyOut = Utility::getUnsignedIntegerFromAddr(&nevent->_data[12]);/**< Total key out coins */
			cmit->second.clientPlayData->m_all_time_record.m_coinIn = Utility::getUnsignedIntegerFromAddr(&nevent->_data[16]);/**< Total coin in coins */
			cmit->second.clientPlayData->m_all_time_record.m_coinOut = Utility::getUnsignedIntegerFromAddr(&nevent->_data[20]);/**< Total coin out coins */
			cmit->second.clientPlayData->m_all_time_record.m_masterOpen = Utility::getUnsignedIntegerFromAddr(&nevent->_data[24]);/**< Total key in coins from master */
			cmit->second.clientPlayData->m_all_time_record.m_masterClear = Utility::getUnsignedIntegerFromAddr(&nevent->_data[28]);/**< Total key out coins from master */
		    /* Main Game */
			cmit->second.clientPlayData->m_all_time_record.m_totalMainGamePlayScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[32]);/**< Total main game play scores */
			cmit->second.clientPlayData->m_all_time_record.m_totalMainGameWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[36]);/**< Total main game win scores */
			cmit->second.clientPlayData->m_all_time_record.m_totalMainGamePlayTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[40]);/**< Total main game play times */
			cmit->second.clientPlayData->m_all_time_record.m_totalMainGameWinTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[44]);/**< Total main game win times */
			cmit->second.clientPlayData->m_all_time_record.m_totalMainGameOverTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[48]);/**< Total main game over max credit times */
		    /* Double Game */
			cmit->second.clientPlayData->m_all_time_record.m_totalDoubleGamePlayScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[52]);/**< Total double game play scores */
			cmit->second.clientPlayData->m_all_time_record.m_totalDoubleGameWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[56]);/**< Total double game win scores */
			cmit->second.clientPlayData->m_all_time_record.m_totalDoubleGamePlayTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[60]);/**< Total double game play times */
			cmit->second.clientPlayData->m_all_time_record.m_totalDoubleGameWinTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[64]);/**< Total double game win times */
			cmit->second.clientPlayData->m_all_time_record.m_totalDoubleGameOverTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[68]);/**< Total double game over max credit times */
		    /* Special Game */
			cmit->second.clientPlayData->m_all_time_record.m_totalSpecialGameEnterTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[72]);/**< Total special game enter times */
			cmit->second.clientPlayData->m_all_time_record.m_totalSpecialGamePlayScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[76]);/**< Total special game play scores */
			cmit->second.clientPlayData->m_all_time_record.m_totalSpecialGameWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[80]);/**< Total special game win scores */
			cmit->second.clientPlayData->m_all_time_record.m_totalSpecialGamePlayTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[84]);/**< Total special game play times */
			cmit->second.clientPlayData->m_all_time_record.m_totalSpecialGameWinTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[88]);/**< Total special game win times */
		    /* Jackpot */
			cmit->second.clientPlayData->m_all_time_record.m_jp1Times = Utility::getUnsignedIntegerFromAddr(&nevent->_data[92]);/**< Total JP1 times */
			cmit->second.clientPlayData->m_all_time_record.m_jp1Score = Utility::getUnsignedIntegerFromAddr(&nevent->_data[96]);/**< Total JP1 scores */
			cmit->second.clientPlayData->m_all_time_record.m_jp2Times = Utility::getUnsignedIntegerFromAddr(&nevent->_data[100]);/**< Total JP2 times */
			cmit->second.clientPlayData->m_all_time_record.m_jp2Score = Utility::getUnsignedIntegerFromAddr(&nevent->_data[104]);/**< Total JP2 scores */
			cmit->second.clientPlayData->m_all_time_record.m_jp3Times = Utility::getUnsignedIntegerFromAddr(&nevent->_data[108]);/**< Total JP3 times */
			cmit->second.clientPlayData->m_all_time_record.m_jp3Score = Utility::getUnsignedIntegerFromAddr(&nevent->_data[112]);/**< Total JP3 scores */

			//cmit->second.clientPlayData->totalGameRec._totalIn                    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[0]);
			//cmit->second.clientPlayData->totalGameRec._totalOut                   = Utility::getUnsignedIntegerFromAddr(&nevent->_data[4]);
			//cmit->second.clientPlayData->totalGameRec._totalKeyIn                 = Utility::getUnsignedIntegerFromAddr(&nevent->_data[8]);
			//cmit->second.clientPlayData->totalGameRec._totalKeyOut                = Utility::getUnsignedIntegerFromAddr(&nevent->_data[12]);
			//cmit->second.clientPlayData->totalGameRec._totalCoinIn                = Utility::getUnsignedIntegerFromAddr(&nevent->_data[16]);
			//cmit->second.clientPlayData->totalGameRec._totalCoinOut               = Utility::getUnsignedIntegerFromAddr(&nevent->_data[20]);
			//cmit->second.clientPlayData->totalGameRec._mainGameTotalPlayScores    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[24]);
			//cmit->second.clientPlayData->totalGameRec._mainGameTotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[28]);
			//cmit->second.clientPlayData->totalGameRec._mainGameTotalPlayTimes     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[32]);
			//cmit->second.clientPlayData->totalGameRec._mainGameTotalWinTimes      = Utility::getUnsignedIntegerFromAddr(&nevent->_data[36]);
			//cmit->second.clientPlayData->totalGameRec._ddownGameTotalPlayScores   = Utility::getUnsignedIntegerFromAddr(&nevent->_data[40]);
			//cmit->second.clientPlayData->totalGameRec._ddownGameTotalWinScores    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[44]);
			//cmit->second.clientPlayData->totalGameRec._ddownGameTotalPlayTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[48]);
			//cmit->second.clientPlayData->totalGameRec._ddownGameTotalWinTimes     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[52]);
			//cmit->second.clientPlayData->totalGameRec._ddownGameTotalChalTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[56]);
			//cmit->second.clientPlayData->totalGameRec._ddownGameTotalPassTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[60]);
			//cmit->second.clientPlayData->totalGameRec._ddownGameTotalPushTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[64]);
			//cmit->second.clientPlayData->totalGameRec._totalSystemOverTimes       = Utility::getUnsignedIntegerFromAddr(&nevent->_data[68]);
			//cmit->second.clientPlayData->totalGameRec._TotalDDownGameOverTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[72]);
			//cmit->second.clientPlayData->totalGameRec._jackpot1TotalTimes         = Utility::getUnsignedIntegerFromAddr(&nevent->_data[76]);
			//cmit->second.clientPlayData->totalGameRec._jackpot1TotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[80]);
			//cmit->second.clientPlayData->totalGameRec._jackpot2TotalTimes         = Utility::getUnsignedIntegerFromAddr(&nevent->_data[84]);
			//cmit->second.clientPlayData->totalGameRec._jackpot2TotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[88]);
			//cmit->second.clientPlayData->totalGameRec._jackpot3TotalTimes         = Utility::getUnsignedIntegerFromAddr(&nevent->_data[92]);
			//cmit->second.clientPlayData->totalGameRec._jackpot3TotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[96]);
			//cmit->second.clientPlayData->totalGameRec._jackpotTotalWinScores      = Utility::getUnsignedIntegerFromAddr(&nevent->_data[100]);
			//cmit->second.clientPlayData->totalGameRec._specialBonusTotalWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[104]);

			//printf("ID %d => Total in : %d \n"                      ,cmit->second.client_id,cmit->second.clientPlayData->totalGameRec._totalIn);
			//printf("ID %d => Main Game Total Play Scores : %d \n"   ,cmit->second.client_id,cmit->second.clientPlayData->totalGameRec._mainGameTotalPlayScores);
			//printf("ID %d => Jackpot 1 Total Times : %d \n"         ,cmit->second.client_id,cmit->second.clientPlayData->totalGameRec._jackpot1TotalTimes);
			//printf("ID %d => Special Bonus Total Win Scores : %d \n",cmit->second.client_id,cmit->second.clientPlayData->totalGameRec._specialBonusTotalWinScores);

			break;
		case CMDID_GAMEREC_CURRENTREC:

			/* In & Out */
			cmit->second.clientPlayData->m_current_term_record.m_in = Utility::getUnsignedIntegerFromAddr(&nevent->_data[0]);/**< Total in coins */
			cmit->second.clientPlayData->m_current_term_record.m_out = Utility::getUnsignedIntegerFromAddr(&nevent->_data[4]);/**< Total out coins */
			cmit->second.clientPlayData->m_current_term_record.m_keyIn = Utility::getUnsignedIntegerFromAddr(&nevent->_data[8]);/**< Total key in coins */
			cmit->second.clientPlayData->m_current_term_record.m_keyOut = Utility::getUnsignedIntegerFromAddr(&nevent->_data[12]);/**< Total key out coins */
			cmit->second.clientPlayData->m_current_term_record.m_coinIn = Utility::getUnsignedIntegerFromAddr(&nevent->_data[16]);/**< Total coin in coins */
			cmit->second.clientPlayData->m_current_term_record.m_coinOut = Utility::getUnsignedIntegerFromAddr(&nevent->_data[20]);/**< Total coin out coins */
			cmit->second.clientPlayData->m_current_term_record.m_masterOpen = Utility::getUnsignedIntegerFromAddr(&nevent->_data[24]);/**< Total key in coins from master */
			cmit->second.clientPlayData->m_current_term_record.m_masterClear = Utility::getUnsignedIntegerFromAddr(&nevent->_data[28]);/**< Total key out coins from master */
		    /* Main Game */
			cmit->second.clientPlayData->m_current_term_record.m_totalMainGamePlayScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[32]);/**< Total main game play scores */
			cmit->second.clientPlayData->m_current_term_record.m_totalMainGameWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[36]);/**< Total main game win scores */
			cmit->second.clientPlayData->m_current_term_record.m_totalMainGamePlayTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[40]);/**< Total main game play times */
			cmit->second.clientPlayData->m_current_term_record.m_totalMainGameWinTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[44]);/**< Total main game win times */
			cmit->second.clientPlayData->m_current_term_record.m_totalMainGameOverTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[48]);/**< Total main game over max credit times */
		    /* Double Game */
			cmit->second.clientPlayData->m_current_term_record.m_totalDoubleGamePlayScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[52]);/**< Total double game play scores */
			cmit->second.clientPlayData->m_current_term_record.m_totalDoubleGameWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[56]);/**< Total double game win scores */
			cmit->second.clientPlayData->m_current_term_record.m_totalDoubleGamePlayTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[60]);/**< Total double game play times */
			cmit->second.clientPlayData->m_current_term_record.m_totalDoubleGameWinTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[64]);/**< Total double game win times */
			cmit->second.clientPlayData->m_current_term_record.m_totalDoubleGameOverTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[68]);/**< Total double game over max credit times */
		    /* Special Game */
			cmit->second.clientPlayData->m_current_term_record.m_totalSpecialGameEnterTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[72]);/**< Total special game enter times */
			cmit->second.clientPlayData->m_current_term_record.m_totalSpecialGamePlayScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[76]);/**< Total special game play scores */
			cmit->second.clientPlayData->m_current_term_record.m_totalSpecialGameWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[80]);/**< Total special game win scores */
			cmit->second.clientPlayData->m_current_term_record.m_totalSpecialGamePlayTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[84]);/**< Total special game play times */
			cmit->second.clientPlayData->m_current_term_record.m_totalSpecialGameWinTimes = Utility::getUnsignedIntegerFromAddr(&nevent->_data[88]);/**< Total special game win times */
		    /* Jackpot */
			cmit->second.clientPlayData->m_current_term_record.m_jp1Times = Utility::getUnsignedIntegerFromAddr(&nevent->_data[92]);/**< Total JP1 times */
			cmit->second.clientPlayData->m_current_term_record.m_jp1Score = Utility::getUnsignedIntegerFromAddr(&nevent->_data[96]);/**< Total JP1 scores */
			cmit->second.clientPlayData->m_current_term_record.m_jp2Times = Utility::getUnsignedIntegerFromAddr(&nevent->_data[100]);/**< Total JP2 times */
			cmit->second.clientPlayData->m_current_term_record.m_jp2Score = Utility::getUnsignedIntegerFromAddr(&nevent->_data[104]);/**< Total JP2 scores */
			cmit->second.clientPlayData->m_current_term_record.m_jp3Times = Utility::getUnsignedIntegerFromAddr(&nevent->_data[108]);/**< Total JP3 times */
			cmit->second.clientPlayData->m_current_term_record.m_jp3Score = Utility::getUnsignedIntegerFromAddr(&nevent->_data[112]);/**< Total JP3 scores */

			//cmit->second.clientPlayData->currentGameRec._totalIn                    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[0]);
			//cmit->second.clientPlayData->currentGameRec._totalOut                   = Utility::getUnsignedIntegerFromAddr(&nevent->_data[4]);
			//cmit->second.clientPlayData->currentGameRec._totalKeyIn                 = Utility::getUnsignedIntegerFromAddr(&nevent->_data[8]);
			//cmit->second.clientPlayData->currentGameRec._totalKeyOut                = Utility::getUnsignedIntegerFromAddr(&nevent->_data[12]);
			//cmit->second.clientPlayData->currentGameRec._totalCoinIn                = Utility::getUnsignedIntegerFromAddr(&nevent->_data[16]);
			//cmit->second.clientPlayData->currentGameRec._totalCoinOut               = Utility::getUnsignedIntegerFromAddr(&nevent->_data[20]);
			//cmit->second.clientPlayData->currentGameRec._mainGameTotalPlayScores    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[24]);
			//cmit->second.clientPlayData->currentGameRec._mainGameTotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[28]);
			//cmit->second.clientPlayData->currentGameRec._mainGameTotalPlayTimes     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[32]);
			//cmit->second.clientPlayData->currentGameRec._mainGameTotalWinTimes      = Utility::getUnsignedIntegerFromAddr(&nevent->_data[36]);
			//cmit->second.clientPlayData->currentGameRec._ddownGameTotalPlayScores   = Utility::getUnsignedIntegerFromAddr(&nevent->_data[40]);
			//cmit->second.clientPlayData->currentGameRec._ddownGameTotalWinScores    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[44]);
			//cmit->second.clientPlayData->currentGameRec._ddownGameTotalPlayTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[48]);
			//cmit->second.clientPlayData->currentGameRec._ddownGameTotalWinTimes     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[52]);
			//cmit->second.clientPlayData->currentGameRec._ddownGameTotalChalTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[56]);
			//cmit->second.clientPlayData->currentGameRec._ddownGameTotalPassTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[60]);
			//cmit->second.clientPlayData->currentGameRec._ddownGameTotalPushTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[64]);
			//cmit->second.clientPlayData->currentGameRec._totalSystemOverTimes       = Utility::getUnsignedIntegerFromAddr(&nevent->_data[68]);
			//cmit->second.clientPlayData->currentGameRec._TotalDDownGameOverTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[72]);
			//cmit->second.clientPlayData->currentGameRec._jackpot1TotalTimes         = Utility::getUnsignedIntegerFromAddr(&nevent->_data[76]);
			//cmit->second.clientPlayData->currentGameRec._jackpot1TotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[80]);
			//cmit->second.clientPlayData->currentGameRec._jackpot2TotalTimes         = Utility::getUnsignedIntegerFromAddr(&nevent->_data[84]);
			//cmit->second.clientPlayData->currentGameRec._jackpot2TotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[88]);
			//cmit->second.clientPlayData->currentGameRec._jackpot3TotalTimes         = Utility::getUnsignedIntegerFromAddr(&nevent->_data[92]);
			//cmit->second.clientPlayData->currentGameRec._jackpot3TotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[96]);
			//cmit->second.clientPlayData->currentGameRec._jackpotTotalWinScores      = Utility::getUnsignedIntegerFromAddr(&nevent->_data[100]);
			//cmit->second.clientPlayData->currentGameRec._specialBonusTotalWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[104]);

			//printf("ID %d => Current Total in : %d \n"                      ,cmit->second.client_id,cmit->second.clientPlayData->currentGameRec._totalIn);
			//printf("ID %d => Current Main Game Total Play Scores : %d \n"   ,cmit->second.client_id,cmit->second.clientPlayData->currentGameRec._mainGameTotalPlayScores);
			//printf("ID %d => Current Jackpot 1 Total Times : %d \n"         ,cmit->second.client_id,cmit->second.clientPlayData->currentGameRec._jackpot1TotalTimes);
			//printf("ID %d => Current Special Bonus Total Win Scores : %d \n",cmit->second.client_id,cmit->second.clientPlayData->currentGameRec._specialBonusTotalWinScores);

			break;
#if 0
		case CMDID_GAMEREC_PREVIOUSREC:
			cmit->second.clientPlayData->previousGameRec._totalIn                    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[0]);
			cmit->second.clientPlayData->previousGameRec._totalOut                   = Utility::getUnsignedIntegerFromAddr(&nevent->_data[4]);
			cmit->second.clientPlayData->previousGameRec._totalKeyIn                 = Utility::getUnsignedIntegerFromAddr(&nevent->_data[8]);
			cmit->second.clientPlayData->previousGameRec._totalKeyOut                = Utility::getUnsignedIntegerFromAddr(&nevent->_data[12]);
			cmit->second.clientPlayData->previousGameRec._totalCoinIn                = Utility::getUnsignedIntegerFromAddr(&nevent->_data[16]);
			cmit->second.clientPlayData->previousGameRec._totalCoinOut               = Utility::getUnsignedIntegerFromAddr(&nevent->_data[20]);
			cmit->second.clientPlayData->previousGameRec._mainGameTotalPlayScores    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[24]);
			cmit->second.clientPlayData->previousGameRec._mainGameTotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[28]);
			cmit->second.clientPlayData->previousGameRec._mainGameTotalPlayTimes     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[32]);
			cmit->second.clientPlayData->previousGameRec._mainGameTotalWinTimes      = Utility::getUnsignedIntegerFromAddr(&nevent->_data[36]);
			cmit->second.clientPlayData->previousGameRec._ddownGameTotalPlayScores   = Utility::getUnsignedIntegerFromAddr(&nevent->_data[40]);
			cmit->second.clientPlayData->previousGameRec._ddownGameTotalWinScores    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[44]);
			cmit->second.clientPlayData->previousGameRec._ddownGameTotalPlayTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[48]);
			cmit->second.clientPlayData->previousGameRec._ddownGameTotalWinTimes     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[52]);
			cmit->second.clientPlayData->previousGameRec._ddownGameTotalChalTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[56]);
			cmit->second.clientPlayData->previousGameRec._ddownGameTotalPassTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[60]);
			cmit->second.clientPlayData->previousGameRec._ddownGameTotalPushTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[64]);
			cmit->second.clientPlayData->previousGameRec._totalSystemOverTimes       = Utility::getUnsignedIntegerFromAddr(&nevent->_data[68]);
			cmit->second.clientPlayData->previousGameRec._TotalDDownGameOverTimes    = Utility::getUnsignedIntegerFromAddr(&nevent->_data[72]);
			cmit->second.clientPlayData->previousGameRec._jackpot1TotalTimes         = Utility::getUnsignedIntegerFromAddr(&nevent->_data[76]);
			cmit->second.clientPlayData->previousGameRec._jackpot1TotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[80]);
			cmit->second.clientPlayData->previousGameRec._jackpot2TotalTimes         = Utility::getUnsignedIntegerFromAddr(&nevent->_data[84]);
			cmit->second.clientPlayData->previousGameRec._jackpot2TotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[88]);
			cmit->second.clientPlayData->previousGameRec._jackpot3TotalTimes         = Utility::getUnsignedIntegerFromAddr(&nevent->_data[92]);
			cmit->second.clientPlayData->previousGameRec._jackpot3TotalWinScores     = Utility::getUnsignedIntegerFromAddr(&nevent->_data[96]);
			cmit->second.clientPlayData->previousGameRec._jackpotTotalWinScores      = Utility::getUnsignedIntegerFromAddr(&nevent->_data[100]);
			cmit->second.clientPlayData->previousGameRec._specialBonusTotalWinScores = Utility::getUnsignedIntegerFromAddr(&nevent->_data[104]);

			printf("ID %d => Previous Total in : %d \n"                      ,cmit->second.client_id,cmit->second.clientPlayData->previousGameRec._totalIn);
			printf("ID %d => Previous Main Game Total Play Scores : %d \n"   ,cmit->second.client_id,cmit->second.clientPlayData->previousGameRec._mainGameTotalPlayScores);
			printf("ID %d => Previous Jackpot 1 Total Times : %d \n"         ,cmit->second.client_id,cmit->second.clientPlayData->previousGameRec._jackpot1TotalTimes);
			printf("ID %d => Previous Special Bonus Total Win Scores : %d \n",cmit->second.client_id,cmit->second.clientPlayData->previousGameRec._specialBonusTotalWinScores);

			break;
#endif

		default:
			printf("Undefined Command ID of TCP_GID_GAMEREC \n");
			break;
		}
		break;

	default:
		break;
	}

}

void GamerecTest::Draw(void){

	unsigned long long totalIn=0;
	unsigned long long totalOut=0;
	unsigned long long totalMainGamePlayScores=0;
	unsigned long long totalMainGameWinScores=0;

	std::map<bufferevent*,CLIENTDATA>::iterator cmit;

	for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
		if(cmit->second.m_idCheckSuccess==true){
			totalIn  += cmit->second.clientPlayData->m_all_time_record.m_in;
			totalOut += cmit->second.clientPlayData->m_all_time_record.m_out;
		}
	}

	for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
		if(cmit->second.m_idCheckSuccess==true){
			totalMainGamePlayScores  += cmit->second.clientPlayData->m_all_time_record.m_totalMainGamePlayScores;
			totalMainGameWinScores   += cmit->second.clientPlayData->m_all_time_record.m_totalMainGameWinScores;
		}
	}

	DrawFont(&sheet_font,256,32,32,20,font_align_center,0,GETY(87), "All Client Total In : %llu",totalIn);
	DrawFont(&sheet_font,256,32,32,20,font_align_center,0,GETY(119),"All Client Total Out: %llu",totalOut);
	DrawFont(&sheet_font,256,32,32,20,font_align_center,0,GETY(151),"All Client MainGamePlayScores : %llu",totalMainGamePlayScores);
	DrawFont(&sheet_font,256,32,32,20,font_align_center,0,GETY(183),"All Client MainGameWinScores: %llu",totalMainGameWinScores);
}

int GamerecTest::Main(double elapsedTime){

	std::map<bufferevent*,CLIENTDATA>::iterator cmit;

	// Request Section play data
	this->m_elapsedTimer += elapsedTime;
	if(this->m_elapsedTimer >= 100.0){
    	for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
    		if(cmit->second.m_idCheckSuccess == true){
				struct evbuffer *output = bufferevent_get_output(cmit->second.bev);
				NETWORKEVENT tran;
				tran._id          = 0;//server's ID is 0
				tran._cmd_grp_id  = TCP_GID_GAMEREC;
				tran._cmd_id      = CMDID_GAMEREC_SECTIONREC;
				tran._data_length = 0;
				evbuffer_add(output,&tran,sizeof(NETWORKEVENT));
    		}
    	}
		this->m_elapsedTimer=0;
	}

	// Request Total Game Record
	this->m_elapsedTimer2 += elapsedTime;
	if(this->m_elapsedTimer2 >= 100.0){
    	for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
    		if(cmit->second.m_idCheckSuccess == true){
				struct evbuffer *output = bufferevent_get_output(cmit->second.bev);
				NETWORKEVENT tran;
				tran._id          = 0;//server's ID is 0
				tran._cmd_grp_id  = TCP_GID_GAMEREC;
				tran._cmd_id      = CMDID_GAMEREC_ALLREC;
				tran._data_length = 0;
				evbuffer_add(output,&tran,sizeof(NETWORKEVENT));
    		}
    	}
		this->m_elapsedTimer2=0;
	}

	// Request Current Game Record
	this->m_elapsedTimer3 += elapsedTime;
	if(this->m_elapsedTimer3 >= 100.0){
    	for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
    		if(cmit->second.m_idCheckSuccess == true){
				struct evbuffer *output = bufferevent_get_output(cmit->second.bev);
				NETWORKEVENT tran;
				tran._id          = 0;//server's ID is 0
				tran._cmd_grp_id  = TCP_GID_GAMEREC;
				tran._cmd_id      = CMDID_GAMEREC_CURRENTREC;
				tran._data_length = 0;
				evbuffer_add(output,&tran,sizeof(NETWORKEVENT));
    		}
    	}
		this->m_elapsedTimer3=0;
	}

#if 0
	// Request Previous Game Record
	this->m_elapsedTimer4 += elapsedTime;
	if(this->m_elapsedTimer4 >= 100.0){
    	for(cmit=clientMap.begin();cmit!=clientMap.end();cmit++){
    		if(cmit->second.m_idCheckSuccess == true){
				struct evbuffer *output = bufferevent_get_output(cmit->second.bev);
				NETWORKEVENT tran;
				tran._id          = 0;//server's ID is 0
				tran._cmd_grp_id  = TCP_GID_GAMEREC;
				tran._cmd_id      = CMDID_GAMEREC_PREVIOUSREC;
				tran._data_length = 0;
				evbuffer_add(output,&tran,sizeof(NETWORKEVENT));
    		}
    	}
		this->m_elapsedTimer4=0;
	}
#endif

	return 0;
}


