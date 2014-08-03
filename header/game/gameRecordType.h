/**
 * @file gameRecordType.h
 * @brief Declare game record type.
 *
 */

#ifndef GAMERECORDTYPE_H_
#define GAMERECORDTYPE_H_

#include "../preprocessor.h"

/**
 * @brief RTC Time Structure.
 *
 */
typedef struct{
#if 0
	unsigned char _year;/**< Year */
	unsigned char _month;/**< Month */
	unsigned char _day;/**< Day */
	unsigned char _hour;/**< Hour */
	unsigned char _minute;/**< Minute */
	unsigned char _second;/**< Second */
#endif
	int _year;/**< Year */
	int _month;/**< Month */
	int _day;/**< Day */
	int _hour;/**< Hour */
	int _minute;/**< Minute */
	int _second;/**< Second */

	/**
	 * @brief Reset all member parameters.
	 */
	void reset(){
		this->_year    = 0;
		this->_month   = 0;
		this->_day     = 0;
		this->_hour    = 0;
		this->_minute  = 0;
	    this->_second  = 0;
	}

}RTCTIME;

/**
 * @brief Credit In/Out Record Structure.
 */
typedef struct CreditInOutRecord{
	RTCTIME _rtcTime;/**< RTC Time */
	unsigned int _score;/**< Score */

	/**
	 * @brief Reset all member parameters.
	 */
	void reset(void){
		this->_rtcTime.reset();
		this->_score = 0;
	}

}CREDITINOUTRECORD;

/**
 * @brief Award Record Structure.
 */
typedef struct AwardRecord{
	/* Main Game */
	unsigned int _lineStraightAward[8][13];/**< Line Straight Award */
	//unsigned int _fullFrameAward[11][10];/**< Full Frame Award */
	unsigned int _fullFrameAward[11];/**< Full Frame Award */
    /* Double Game */
	unsigned int _doubleGameAward[4];/**< Double Game Award */
	/* Special Game */
    unsigned int _specialGameLightAward[9];/**< Special Game Light Award */
    unsigned int _specialGameSlotAward[2];/**< Special Game Slot Award */

	/**
	 * @brief Reset all member parameters.
	 */
	void reset(void){

		for(unsigned int idx=0; idx<sizeof(this->_lineStraightAward)/sizeof(this->_lineStraightAward[0]);idx++){
			for(unsigned int idx2=0; idx2<sizeof(this->_lineStraightAward[0])/sizeof(this->_lineStraightAward[0][0]);idx2++){
				this->_lineStraightAward[idx][idx2] = 0;
			}
		}

		for(unsigned int idx=0; idx<sizeof(this->_fullFrameAward)/sizeof(this->_fullFrameAward[0]);idx++){
			this->_fullFrameAward[idx] = 0;
		}

		//for(unsigned int idx=0; idx<sizeof(this->_fullFrameAward)/sizeof(this->_fullFrameAward[0]);idx++){
			//for(unsigned int idx2=0; idx2<sizeof(this->_fullFrameAward[idx])/sizeof(this->_fullFrameAward[idx][0]);idx2++){
				//this->_fullFrameAward[idx][idx2] = 0;
			//}
		//}

		for(unsigned int idx=0; idx<sizeof(this->_doubleGameAward)/sizeof(this->_doubleGameAward[0]);idx++){
			this->_doubleGameAward[idx] = 0;
		}

		for(unsigned int idx=0; idx<sizeof(this->_specialGameLightAward)/sizeof(this->_specialGameLightAward[0]);idx++){
			this->_specialGameLightAward[idx] = 0;
		}

		for(unsigned int idx=0; idx<sizeof(this->_specialGameSlotAward)/sizeof(this->_specialGameSlotAward[0]);idx++){
			this->_specialGameSlotAward[idx] = 0;
		}
	}

}AWARDRECORD;

/**
 * @brief Great Award Type Enumeration.
 */
enum GreatAwardType{
	great_award_type_none = 0,
	great_award_type_special_game,
	great_award_type_full_frame_bar_yellow,
	great_award_type_full_frame_cherry,
	great_award_type_full_frame_bar_red,
	great_award_type_full_frame_bar_blue,
	great_award_type_full_frame_wild,
};

/**
 * @brief Great Award Record Structure.
 */
typedef struct GreatAwardRecord{
	RTCTIME _rtcTime;/**< RTC Time */
	unsigned int _awardType;/**< Award Type */
	unsigned int _score;/**< Score */

	/**
	 * @brief Reset all member parameters.
	 */
	void reset(void){
		this->_rtcTime.reset();
		this->_awardType = great_award_type_none;
		this->_score = 0;
	}

}GREATAWARDRECORD;

/**
 * @brief Game Play Record.
 */
typedef struct GamePlayRecord{
	AWARDRECORD m_awardRecord;/**< Award Record */
	RTCTIME     m_rtcTime;/**< RTC Time */
	/* In & Out */
	unsigned long m_in;/**< Total in coins */
	unsigned long m_out;/**< Total out coins */
	unsigned long m_keyIn;/**< Total key in coins */
	unsigned long m_keyOut;/**< Total key out coins */
	unsigned long m_coinIn;/**< Total coin in coins */
	unsigned long m_coinOut;/**< Total coin out coins */
    unsigned long m_masterOpen;/**< Total key in coins from master */
    unsigned long m_masterClear;/**< Total key out coins from master */
    /* Main Game */
	unsigned long m_totalMainGamePlayScores;/**< Total main game play scores */
	unsigned long m_totalMainGameWinScores;/**< Total main game win scores */
	unsigned long m_totalMainGamePlayTimes;/**< Total main game play times */
	unsigned long m_totalMainGameWinTimes;/**< Total main game win times */
	unsigned long m_totalMainGameOverTimes;/**< Total main game over max credit times */
    /* Double Game */
	unsigned long m_totalDoubleGamePlayScores;/**< Total double game play scores */
	unsigned long m_totalDoubleGameWinScores;/**< Total double game win scores */
	unsigned long m_totalDoubleGamePlayTimes;/**< Total double game play times */
	unsigned long m_totalDoubleGameWinTimes;/**< Total double game win times */
	unsigned long m_totalDoubleGameOverTimes;/**< Total double game over max credit times */
    /* Special Game */
	unsigned long m_totalSpecialGameEnterTimes;/**< Total special game enter times */
	unsigned long m_totalSpecialGamePlayScores;/**< Total special game play scores */
	unsigned long m_totalSpecialGameWinScores;/**< Total special game win scores */
	unsigned long m_totalSpecialGamePlayTimes;/**< Total special game play times */
	unsigned long m_totalSpecialGameWinTimes;/**< Total special game win times */
    /* Jackpot */
	unsigned long m_jp1Times;/**< Total JP1 times */
	unsigned long m_jp1Score;/**< Total JP1 scores */
	unsigned long m_jp2Times;/**< Total JP2 times */
	unsigned long m_jp2Score;/**< Total JP2 scores */
	unsigned long m_jp3Times;/**< Total JP3 times */
	unsigned long m_jp3Score;/**< Total JP3 scores */

	/**
	 * @brief Constructor.
	 */
	GamePlayRecord(void){
		this->Reset();
#if 0
		/* Award Record */
		m_awardRecord.Reset();
		/* RTC Time */
		m_rtcTime.Reset();
		/* In & Out */
		m_in=0;
		m_out=0;
		m_keyIn=0;
		m_keyOut=0;
		m_coinIn=0;
		m_coinOut=0;
	    m_masterOpen=0;
	    m_masterClear=0;
	    /* Main Game */
		m_totalMainGamePlayScores=0;
		m_totalMainGameWinScores=0;
		m_totalMainGamePlayTimes=0;
		m_totalMainGameWinTimes=0;
		m_totalMainGameOverTimes=0;
	    /* Double Game */
		m_totalDoubleGamePlayScores=0;
		m_totalDoubleGameWinScores=0;
		m_totalDoubleGamePlayTimes=0;
		m_totalDoubleGameWinTimes=0;
		m_totalDoubleGameOverTimes=0;
	    /* Special Game */
		m_totalSpecialGamePlayScores=0;
		m_totalSpecialGameWinScores=0;
		m_totalSpecialGamePlayTimes=0;
		m_totalSpecialGameWinTimes=0;
	    /* Jackpot */
		m_jp1Times=0;
		m_jp1Score=0;
		m_jp2Times=0;
		m_jp2Score=0;
		m_jp3Times=0;
		m_jp3Score=0;
#endif
	}
	/**
	 * @brief Reset All Member Parameters.
	 */
	void Reset(){
		/* Award Record */
		m_awardRecord.reset();
		/* RTC Time */
		m_rtcTime.reset();
		/* In & Out */
		m_in=0;
		m_out=0;
		m_keyIn=0;
		m_keyOut=0;
		m_coinIn=0;
		m_coinOut=0;
	    m_masterOpen=0;
	    m_masterClear=0;
	    /* Main Game */
		m_totalMainGamePlayScores=0;
		m_totalMainGameWinScores=0;
		m_totalMainGamePlayTimes=0;
		m_totalMainGameWinTimes=0;
		m_totalMainGameOverTimes=0;
	    /* Double Game */
		m_totalDoubleGamePlayScores=0;
		m_totalDoubleGameWinScores=0;
		m_totalDoubleGamePlayTimes=0;
		m_totalDoubleGameWinTimes=0;
		m_totalDoubleGameOverTimes=0;
	    /* Special Game */
		m_totalSpecialGameEnterTimes=0;
		m_totalSpecialGamePlayScores=0;
		m_totalSpecialGameWinScores=0;
		m_totalSpecialGamePlayTimes=0;
		m_totalSpecialGameWinTimes=0;
	    /* Jackpot */
		m_jp1Times=0;
		m_jp1Score=0;
		m_jp2Times=0;
		m_jp2Score=0;
		m_jp3Times=0;
		m_jp3Score=0;
	}


}GAMEPLAYRECORD;

/**
 * @brief Assistant Record Structure.
 */
typedef struct AssistantRecord{
	RTCTIME _rtcTime;/**< RTC Time */
	unsigned long _keyIn;/**< Key In */
	unsigned long _keyOut;/**< Key Out */
	unsigned long _coinIn;/**< Coin In */
	unsigned long _coinOut;/**< Coin Out */
    unsigned long _mainGamePlayTimes;/**< Main Game Play Times */
    unsigned long _mainGameWinTimes;/**< Main Game Win Times */
    unsigned long _mainGamePlayScores;/**< Main Game Play Scores */
    unsigned long _mainGameWinScores;/**< Main Game Win Scores */
    unsigned long _mainGameOverTimes;/**< Main Game Over Max Win Times */
    unsigned long _doubleGamePlayTimes;/**< Double Down Game Play Times */
    unsigned long _doubleGameWinTimes;/**< Double Down Game Win Times */
    unsigned long _doubleGamePlayScores;/**< Double Down Game Play Scores */
    unsigned long _doubleGameWinScores;/**< Double Down Game Win Scores */
    unsigned long _specialGameEnterTimes;/**< Special Game Enter Times */
    unsigned long _specialGamePlayTimes;/**< Special Game Play Times */
    unsigned long _specialGameWinTimes;/**< Special Game Win Times */
    unsigned long _specialGamePlayScores;/**< Special Game Play Scores */
    unsigned long _specialGameWinScores;/**< Special Game Win Scores */

    AWARDRECORD _awardRecord;/**< Award Record */

    //CREDITINOUTRECORD _keyInRecord[ASSISTANT_RECORD_SIZE];/**< Key In Record */
    //CREDITINOUTRECORD _keyOutRecord[ASSISTANT_RECORD_SIZE];/**< Key Out Record */
    //CREDITINOUTRECORD _coinInRecord[ASSISTANT_RECORD_SIZE];/**< Coin In Record */
    //CREDITINOUTRECORD _coinOutRecord[ASSISTANT_RECORD_SIZE];/**< Coin Out Record */

    /**
     * @brief Reset all member parameters.
     */
    void Reset(void){
    	this->_rtcTime.reset();

    	this->_keyIn=0;
    	this->_keyOut=0;
    	this->_coinIn=0;
    	this->_coinOut=0;
    	this->_mainGamePlayTimes=0;
    	this->_mainGameWinTimes=0;
    	this->_mainGamePlayScores=0;
    	this->_mainGameWinScores=0;
    	this->_mainGameOverTimes=0;
    	this->_doubleGamePlayTimes=0;
    	this->_doubleGameWinTimes=0;
    	this->_doubleGamePlayScores=0;
    	this->_doubleGameWinScores=0;
    	this->_specialGameEnterTimes=0;
    	this->_specialGamePlayTimes=0;
    	this->_specialGameWinTimes=0;
    	this->_specialGamePlayScores=0;
    	this->_specialGameWinScores=0;

    	this->_awardRecord.reset();

    	/*
    	for(unsigned int idx=0; idx<ASSISTANT_RECORD_SIZE; idx++){
    		this->_keyInRecord[idx].reset();
    		this->_keyOutRecord[idx].reset();
    		this->_coinInRecord[idx].reset();
    		this->_coinOutRecord[idx].reset();
    	}
    	*/

    }

}ASSISTANTRECORD;

#define ASSISTANT_RECORD_SIZE    10
#define GREAT_AWARD_RECORD_SIZE  10

/**
 * @brief Game All Play Record.
 */
typedef struct GameAllPlayRecord{
	/* Manager Page */
	GAMEPLAYRECORD m_all_time_record;/**< All Time Record */
	GAMEPLAYRECORD m_current_term_record;/**< Current Term Record */

	GAMEPLAYRECORD m_section_record;/**< Section Record */

	/* Assistant Page */
	AssistantRecord m_assistantRecord[2];/**< Assistant Record (當班&前班) */
	// Great Award Record
	GreatAwardRecord m_specialGameGARecord[GREAT_AWARD_RECORD_SIZE];/**< Special Game Great Award Record */
	GreatAwardRecord m_fullFrameCherryGARecord[GREAT_AWARD_RECORD_SIZE];/**< Full frame Cheery Great Award Record */
	GreatAwardRecord m_fullFrameBarYellowGARecord[GREAT_AWARD_RECORD_SIZE];/**< Full frame Bar Yellow Great Award Record */
	GreatAwardRecord m_fullFrameBarRedGARecord[GREAT_AWARD_RECORD_SIZE];/**< Full frame Bar Red Great Award Record */
	GreatAwardRecord m_fullFrameBarBlueGARecord[GREAT_AWARD_RECORD_SIZE];/**< Full frame Bar Blue Great Award Record */
	GreatAwardRecord m_fullFrameWildGARecord[GREAT_AWARD_RECORD_SIZE];/**< Full frame Wild Great Award Record */

	/* Credit In & Out Record */
    CREDITINOUTRECORD _keyInRecord[ASSISTANT_RECORD_SIZE];/**< Key In Record */
    CREDITINOUTRECORD _keyOutRecord[ASSISTANT_RECORD_SIZE];/**< Key Out Record */
    CREDITINOUTRECORD _coinInRecord[ASSISTANT_RECORD_SIZE];/**< Coin In Record */
    CREDITINOUTRECORD _coinOutRecord[ASSISTANT_RECORD_SIZE];/**< Coin Out Record */

	/**
	 * @brief Constructor.
	 */
	GameAllPlayRecord(void){
		this->Reset();
	}

	/**
	 * @brief Reset all record.
	 */
	void Reset(void){

		m_all_time_record.Reset();
		m_current_term_record.Reset();
		m_section_record.Reset();

		for(unsigned int idx=0; idx<sizeof(m_assistantRecord)/sizeof(m_assistantRecord[0]); idx++){
			m_assistantRecord[idx].Reset();
		}

		for(unsigned int idx=0; idx<GREAT_AWARD_RECORD_SIZE; idx++){
			m_specialGameGARecord[idx].reset();
			m_fullFrameBarYellowGARecord[idx].reset();
			m_fullFrameCherryGARecord[idx].reset();
			m_fullFrameBarRedGARecord[idx].reset();
			m_fullFrameBarBlueGARecord[idx].reset();
			m_fullFrameWildGARecord[idx].reset();
		}

    	for(unsigned int idx=0; idx<ASSISTANT_RECORD_SIZE; idx++){
    		_keyInRecord[idx].reset();
    		_keyOutRecord[idx].reset();
    		_coinInRecord[idx].reset();
    		_coinOutRecord[idx].reset();
    	}
	}


}GAMEALLPLAYRECORD;


/**
 * @brief Setting Record.
 */
typedef struct SettingRecord{
	RTCTIME m_rtcTime;/**< RTC Time */
	double m_previous_setting_value;/**< Previous Setting Value */
	double m_present_setting_value;/**< Present Setting Value */

	/**
	 * @brief Reset.
	 */
	void Reset(void){
		this->m_rtcTime.reset();
		this->m_previous_setting_value = 0;
		this->m_present_setting_value  = 0;
	}

}SETTINGRECORD;

#define SETTING_RECORD_SIZE  10

/**
 * @brief Game All Setting Record.
 */
typedef struct GameAllSettingRecord{
	SETTINGRECORD m_mainGameProbability[SETTING_RECORD_SIZE];/**< Main Game Probability  */
	SETTINGRECORD m_doubleGameProbability[SETTING_RECORD_SIZE];/**< Double Game Probability */
	SETTINGRECORD m_coinValue[SETTING_RECORD_SIZE];/**< Coin Value */
	SETTINGRECORD m_keyInValue[SETTING_RECORD_SIZE];/**< Key In Value */
	SETTINGRECORD m_keyOutValue[SETTING_RECORD_SIZE];/**< Key Out Value */
	SETTINGRECORD m_singleLineMaxBet[SETTING_RECORD_SIZE];/**< Single Line Maximum Bet */
	SETTINGRECORD m_singleLineMinBet[SETTING_RECORD_SIZE];/**< Single Line Minimum Bet */
	SETTINGRECORD m_singleLineBetUnit[SETTING_RECORD_SIZE];/**< Single Line Bet Unit */

	SETTINGRECORD m_assistantChange[SETTING_RECORD_SIZE];/**< Assistant Change */
	SETTINGRECORD m_clearCurrentTerm[SETTING_RECORD_SIZE];/**< Clear Current Term */
	SETTINGRECORD m_changeStorePassword[SETTING_RECORD_SIZE];/**< Change Store Password */
	SETTINGRECORD m_changeManagerPassword[SETTING_RECORD_SIZE];/**< Change Manager Password */
	SETTINGRECORD m_enterManagerMenu[SETTING_RECORD_SIZE];/**< Enter Manager Menu */
	SETTINGRECORD m_restoreFactorySetting[SETTING_RECORD_SIZE];/**< Restore Factory Setting */

	/**
	 * @brief Reset.
	 */
	void Reset(void){

		for(unsigned int idx=0; idx<SETTING_RECORD_SIZE; idx++){
			this->m_mainGameProbability[idx].Reset();
			this->m_doubleGameProbability[idx].Reset();
			this->m_coinValue[idx].Reset();
			this->m_keyInValue[idx].Reset();
			this->m_keyOutValue[idx].Reset();
			this->m_singleLineMaxBet[idx].Reset();
			this->m_singleLineMinBet[idx].Reset();
			this->m_singleLineBetUnit[idx].Reset();

			this->m_assistantChange[idx].Reset();
			this->m_clearCurrentTerm[idx].Reset();
			this->m_changeStorePassword[idx].Reset();
			this->m_changeManagerPassword[idx].Reset();
			this->m_enterManagerMenu[idx].Reset();
			this->m_restoreFactorySetting[idx].Reset();
		}
	}

}GAMEALLSETTINGRECORD;

#endif /* GAMERECORDTYPE_H_ */
