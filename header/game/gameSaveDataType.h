/**
 * @file gameSaveDataType.h
 *
 */

#ifndef GAMESAVEDATATYPE_H_
#define GAMESAVEDATATYPE_H_

#include "gameLogicType.h"
#include "gameRecordType.h"
#include "gameSettingType.h"
#include "../probability/probabilityType.h"

typedef struct GameSaveData{

	/* Setting Data */
	GAMEALLSETTINGDATA* m_gameAllSettingData;/**< Game All Setting Data */
	/* Record Data */
	GAMEALLPLAYRECORD* m_gameAllPlayRecord;/**< Game All Play Record */
	GAMEALLSETTINGRECORD* m_gameAllSettingRecord;/**< Game All Setting Record */
	/* Probability Data */
	MAINGAMEPROBABILITYCONTROL*  m_mainGameProbabilityControl;
	DOUBLEGAMEPROBABILITYCONTROL* m_doubleGameProbabilityControl;
	SPECIALGAMEPROBABILITYCONTROL* m_specialGameProbabilityControl;
	/* Game Content Data */
	MAINGAMECONTENT*    m_mainGameContent;/**< Main Game Content */
	DOUBLEGAMECONTENT*  m_doubleGameContent;/**< Double Game Content */
	SPECIALGAMECONTENT* m_specialGameContent;/**< Special Game Content */
	/* Game Credits Data */
	GAMECREDITS* m_gameCredits;/**< game credit */

	/**
	 * @brief Constructor.
	 */
	GameSaveData(
			GAMEALLSETTINGDATA*            gameAllSettingData,
			GAMEALLPLAYRECORD*             gameAllPlayRecord,
			GAMEALLSETTINGRECORD*          gameAllSettingRecord,
			MAINGAMEPROBABILITYCONTROL*    mainGameProbabilityControl,
			DOUBLEGAMEPROBABILITYCONTROL*  doubleGameProbabilityControl,
			SPECIALGAMEPROBABILITYCONTROL* specialGameProbabilityControl,
			MAINGAMECONTENT*               mainGameContent,
			DOUBLEGAMECONTENT*             doubleGameContent,
			SPECIALGAMECONTENT*            specialGameContent,
			GAMECREDITS*                   gameCredits
	){
		this->m_gameAllSettingData            = gameAllSettingData;
		this->m_gameAllPlayRecord             = gameAllPlayRecord;
		this->m_gameAllSettingRecord          = gameAllSettingRecord;
		this->m_mainGameProbabilityControl    = mainGameProbabilityControl;
		this->m_doubleGameProbabilityControl  = doubleGameProbabilityControl;
		this->m_specialGameProbabilityControl = specialGameProbabilityControl;
		this->m_mainGameContent               = mainGameContent;
		this->m_doubleGameContent             = doubleGameContent;
		this->m_specialGameContent            = specialGameContent;
		this->m_gameCredits                   = gameCredits;
	}


}GAMESAVEDATA;


#endif /* GAMESAVEDATATYPE_H_ */
