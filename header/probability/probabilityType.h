/**
 * @file probabilityType.h
 * @brief Declare probability type.
 *
 */

#ifndef PROBABILITYTYPE_H_
#define PROBABILITYTYPE_H_

#include <sys/stat.h>
#include <errno.h>
#include "../preprocessor.h"
#include "../game/gameEnum.h"
#include "../game/gameRecordType.h"
//#include "../game/gameLogicType.h"
#include "probabilityEnum.h"

#ifndef __arm__
#define __PROBABILITY_CSV_FILE__          "data/probability.csv"
#define __PROBABILITY_STATUS_CSV_FILE__   "data/probabilityStatus.csv"
#else
#ifndef __fsl__
#define __PROBABILITY_CSV_FILE__          "/nand2/data/probability.csv"
#define __PROBABILITY_STATUS_CSV_FILE__   "/nand2/data/probabilityStatus.csv"
#else
#define __PROBABILITY_CSV_FILE__          "data/probability.csv"
#define __PROBABILITY_STATUS_CSV_FILE__   "data/probabilityStatus.csv"
#endif
#endif

#define SUPPLEMENTARY_AWARD_TYPE_1_MUTLIPLE  151.25f/**< supplementary section 1 multiple */
#define SUPPLEMENTARY_AWARD_TYPE_2_MUTLIPLE  1520.0f/**< supplementary section 2 multiple */

#define SUPPLEMETARY_RATE_3_PERCENTAGE    1000/**< Supplementary 3 % percentage draw count */
#define SUPPLEMETARY_RATE_4_PERCENTAGE    (SUPPLEMETARY_RATE_3_PERCENTAGE+1750)/**< Supplementary 4 % percentage draw count */
#define SUPPLEMETARY_RATE_5_PERCENTAGE    (SUPPLEMETARY_RATE_4_PERCENTAGE+2750)/**< Supplementary 5 % percentage draw count */
#define SUPPLEMETARY_RATE_6_PERCENTAGE    (SUPPLEMETARY_RATE_5_PERCENTAGE+2750)/**< Supplementary 6 % percentage draw count */
#define SUPPLEMETARY_RATE_7_PERCENTAGE    (SUPPLEMETARY_RATE_6_PERCENTAGE+1750)/**< Supplementary 7 % percentage draw count */

#define SUPPLEMETARY_TYPE_SMALL           8000
#define SUPPLEMETARY_TYPE_BIG             (SUPPLEMETARY_TYPE_SMALL+2000)

#define SUPPLEMETARY_TYPE_MULTIPLE_50     3500
#define SUPPLEMETARY_TYPE_MULTIPLE_100    (SUPPLEMETARY_TYPE_MULTIPLE_50+2000)
#define SUPPLEMETARY_TYPE_MULTIPLE_150    (SUPPLEMETARY_TYPE_MULTIPLE_100+1750)
#define SUPPLEMETARY_TYPE_MULTIPLE_250    (SUPPLEMETARY_TYPE_MULTIPLE_150+1500)
#define SUPPLEMETARY_TYPE_MULTIPLE_400    (SUPPLEMETARY_TYPE_MULTIPLE_250+1250)

#define SUPPLEMETARY_TYPE_MULTIPLE_800    4000
#define SUPPLEMETARY_TYPE_MULTIPLE_1000   (SUPPLEMETARY_TYPE_MULTIPLE_800+3000)
#define SUPPLEMETARY_TYPE_MULTIPLE_2000   (SUPPLEMETARY_TYPE_MULTIPLE_1000+2000)
#define SUPPLEMETARY_TYPE_MULTIPLE_4000   (SUPPLEMETARY_TYPE_MULTIPLE_2000+1000)

#define SUPPLEMETARY_TIMING_NORMAL_NORMAL 3334
#define SUPPLEMETARY_TIMING_NORMAL_AHEAD  (SUPPLEMETARY_TIMING_NORMAL_NORMAL+3333)
#define SUPPLEMETARY_TIMING_NORMAL_DELAY  (SUPPLEMETARY_TIMING_NORMAL_AHEAD+3333)

#define SUPPLEMETARY_TIMING_AHEAD_NORMAL  2000
#define SUPPLEMETARY_TIMING_AHEAD_AHEAD   (SUPPLEMETARY_TIMING_AHEAD_NORMAL+7000)
#define SUPPLEMETARY_TIMING_AHEAD_DELAY   (SUPPLEMETARY_TIMING_AHEAD_AHEAD+1000)

#define SUPPLEMETARY_TIMING_DELAY_NORMAL  2000
#define SUPPLEMETARY_TIMING_DELAY_AHEAD   (SUPPLEMETARY_TIMING_DELAY_NORMAL+1000)
#define SUPPLEMETARY_TIMING_DELAY_DELAY   (SUPPLEMETARY_TIMING_DELAY_AHEAD+7000)

#define SMALL_SECTION_GAME_PLAY_TIMES_1   2500
#define SMALL_SECTION_GAME_PLAY_TIMES_2   (SMALL_SECTION_GAME_PLAY_TIMES_1+5000)
#define SMALL_SECTION_GAME_PLAY_TIMES_3   (SMALL_SECTION_GAME_PLAY_TIMES_2+2000)
#define SMALL_SECTION_GAME_PLAY_TIMES_4   (SMALL_SECTION_GAME_PLAY_TIMES_3+500)

#define CHECK0_COIN_COUNT_LEVEL_1         10000
#define CHECK0_COIN_COUNT_LEVEL_2         5000
#define CHECK0_COIN_COUNT_LEVEL_3         0

#define SINGLE_LINE_BET_BASE              10
#define SMALL_SECTION_A_CHECK_SCORE       (180000)
#define SMALL_SECTION_B_CHECK_SCORE       (5000000)
#define SMALL_SECTION_C_CHECK_SCORE       (10000000)

#define SMALL_SECTION_A_START_R_VALUE     (50000)
#define SMALL_SECTION_A_START_R_ADD_STEP  (30000)

#define SMALL_SECTION_A_END_R_VALUE       (10000)
#define SMALL_SECTION_A_END_R_ADD_STEP    (8000)

#define SMALL_SECTION_B_START_R_VALUE     (150000)
#define SMALL_SECTION_B_START_R_ADD_STEP  (5000)

#define SMALL_SECTION_B_END_R_VALUE       (40000)
#define SMALL_SECTION_B_END_R_ADD_STEP    (3000)

#define SMALL_SECTION_C_START_R_VALUE     (170000)
#define SMALL_SECTION_C_START_R_ADD_STEP  (5000)

#define SMALL_SECTION_C_END_R_VALUE       (50000)
#define SMALL_SECTION_C_END_R_ADD_STEP    (2000)

#define DG_PRO_BASE  10000

#define SP_MAX_PLAY_TIMES     27
#define SP_LIGHT_AWARD_COUNT  24

#define CSV_PROBABILITY_SCORE  500000

extern MTRANDOM mtRandom;
extern MTRANDOM mtRandom_main;
extern MTRANDOM mtRandom_double;
extern MTRANDOM mtRandom_special;
extern MTRANDOM mtRandom_common;

extern unsigned long MainGameLevelMatrix[3][26][15];
extern unsigned int  MainGameSlot1ProbabilityMatrix[3][15][9];
extern unsigned int  MainGameSlot5ProbabilityMatrix[3][15][9];
extern unsigned int  MainGameSlot7ProbabilityMatrix[3][15][9];
extern unsigned int  MainGameSlot1ProbabilityDownMatrix[5][9];
extern unsigned int  MainGameSlot5ProbabilityDownMatrix[5][9];
extern unsigned int  MainGameSlot7ProbabilityDownMatrix[5][9];
extern unsigned int  MainGameSlot1ProbabilityUpMatrix[5][9];
extern unsigned int  MainGameSlot5ProbabilityUpMatrix[5][9];
extern unsigned int  MainGameSlot7ProbabilityUpMatrix[5][9];

extern unsigned int  MaingameProM[3][15][7];
extern unsigned int  MaingameProDownM[5][7];
extern unsigned int  MaingameProUpM[5][7];
extern unsigned int  LinkMaingameProM[3][5][15];
extern unsigned int  LineBingoTypeM[9];
extern unsigned long SideBingoTypeM[8][7];
extern unsigned int  DoUpM[6][2];
extern unsigned int  DoDownM[6][2];

/* Double Game Probability */
extern unsigned int dg_pro_70[4];
extern unsigned int dg_pro_80[4];
extern unsigned int dg_pro_83[4];
extern unsigned int dg_pro_86[4];
extern unsigned int dg_pro_89[4];
extern unsigned int dg_pro_92[4];
extern unsigned int dg_pro_95[4];
extern unsigned int dg_pro_98[4];
extern unsigned int dg_pro_102[4];
extern unsigned int dg_pro_105[4];
extern unsigned int dg_pro_110[4];
extern unsigned int dg_pro_115[4];

extern unsigned int* dg_pro_all[10];

extern unsigned int dg_pro_set_96[10];
extern unsigned int dg_pro_set_97[10];
extern unsigned int dg_pro_set_98[10];
extern unsigned int dg_pro_set_99[10];
extern unsigned int dg_pro_set_100[10];

extern unsigned int* dg_pro_set_all[5];

extern unsigned int  sp_award_draw_table[4][30];

static unsigned int supplementary_rate_draw_table[5] = {
		SUPPLEMETARY_RATE_3_PERCENTAGE,
		SUPPLEMETARY_RATE_4_PERCENTAGE,
		SUPPLEMETARY_RATE_5_PERCENTAGE,
		SUPPLEMETARY_RATE_6_PERCENTAGE,
		SUPPLEMETARY_RATE_7_PERCENTAGE
};

static unsigned int supplementary_type_draw_table[2] = {
		SUPPLEMETARY_TYPE_SMALL,
		SUPPLEMETARY_TYPE_BIG
};

static unsigned int supplementary_type_small_draw_table[5] = {
		SUPPLEMETARY_TYPE_MULTIPLE_50,
		SUPPLEMETARY_TYPE_MULTIPLE_100,
		SUPPLEMETARY_TYPE_MULTIPLE_150,
		SUPPLEMETARY_TYPE_MULTIPLE_250,
		SUPPLEMETARY_TYPE_MULTIPLE_400
};

static unsigned int supplementary_type_big_draw_table[4] = {
		SUPPLEMETARY_TYPE_MULTIPLE_800,
		SUPPLEMETARY_TYPE_MULTIPLE_1000,
		SUPPLEMETARY_TYPE_MULTIPLE_2000,
		SUPPLEMETARY_TYPE_MULTIPLE_4000,
};

static unsigned int supplementary_timing_normal_draw_table[3] = {
		SUPPLEMETARY_TIMING_NORMAL_NORMAL,
		SUPPLEMETARY_TIMING_NORMAL_AHEAD,
		SUPPLEMETARY_TIMING_NORMAL_DELAY
};

static unsigned int supplementary_timing_ahead_draw_table[3] = {
		SUPPLEMETARY_TIMING_AHEAD_NORMAL,
		SUPPLEMETARY_TIMING_AHEAD_AHEAD,
		SUPPLEMETARY_TIMING_AHEAD_DELAY
};

static unsigned int supplementary_timing_delay_draw_table[3] = {
		SUPPLEMETARY_TIMING_DELAY_NORMAL,
		SUPPLEMETARY_TIMING_DELAY_AHEAD,
		SUPPLEMETARY_TIMING_DELAY_DELAY
};

static unsigned int small_section_game_play_times[4] = {
		SMALL_SECTION_GAME_PLAY_TIMES_1,
		SMALL_SECTION_GAME_PLAY_TIMES_2,
		SMALL_SECTION_GAME_PLAY_TIMES_3,
		SMALL_SECTION_GAME_PLAY_TIMES_4
};

/**
 * @brief Main Game Probability Control Structure.
 */
typedef struct MainGameProbabilityControl{
 /* Game Play Record */
 GAMEPLAYRECORD*  m_totalRecord;/**< Total Play Record */
 GAMEPLAYRECORD*  m_sectionRecord;/**< Section Play Record */
#ifdef EXPORT_PROBABILITY_CSV_FILE
 GAMEPLAYRECORD   m_csvRecord;/**< CSV Compare Record */
#endif
 /* MERSENNE Random */
 MTRANDOM*        m_mtRandom;/**< MT Random */
 /* Probability Control Parameters */
 unsigned int   m_probabilityControlStatus;/**< Probability Control Status */
 unsigned int   m_previousProbabilityControlStatus;/**< Previous Probability Control Status */
 unsigned long* m_sectionMGPlayScore;/**< Section Main Game Total Play Score */
 unsigned long* m_sectionMGWinScore;/**< Section Main Game Total Win Score */
 unsigned long  m_sectionClearScore;/**< Section Clear Score */
 unsigned long  m_sectionTotalClearTimes;/**< Total clear section times */
 unsigned char  m_canCheckR;/**< Can check R value */
 unsigned int   m_checkRCount;/**< Check R Value Count */
 unsigned int   m_internalGameLevel;/**< Internal GL */
 unsigned long  m_randomCheck2Rate;/**< Random check 2 random rate */
 /* Draw Control */
 unsigned int   m_indexOfRunning;/**< index of running */
 unsigned int   m_timesOfRunning;/**< Times of running */
 unsigned int   m_normalM[15];/**< Normal probability mapping */
 unsigned int   m_upM[5];/**< Up probability mapping */
 unsigned int   m_downM[5];/**< Down probability mapping */
 unsigned int   m_connectM[15];/**< Link probability mapping */
 /* Connect Control Parameters */
 unsigned int   m_receiveConnectInterruptFlag;/**< Receive Connect Command Interrupt Flag */
 unsigned char  m_nextStatusFromMaster;/**< Next status from master */
 double          m_mainGameProSettingConnectMappingArray[9];/**< Main Game Probability Connect Mapping Array */
 /* Game Setting Value */
 unsigned int*  m_connectSetting;/**< Connect Setting */
 unsigned int   m_previousConnectSetting;/**< Previous Connect Setting */
 double*         m_mainGameProSetting;/**< Main Game Probability Setting */
 double          m_previousMainGameProSetting;/**< Previous Main Game Probability Setting */
 unsigned int*  m_gameLevelSetting;/**< Game level setting */
 unsigned int   m_previousGameLevelSetting;/**< Previous game level setting */
 unsigned int*  m_coinValueSetting;/**< Coin Value Setting */
 unsigned int   m_previousCoinValueSetting;/**< Previous Coin Value Setting */
 unsigned int*  m_singleLineMaxBetSetting;/**< Single Line Max Bet Setting */
 unsigned int   m_previousSingleLineMaxBetSetting;/**< Previous Single Line Max Bet Setting */
 unsigned int*  m_GameLevelSettingConnect;/**< Game level Setting(Connect) */
 unsigned int   m_previousGameLevelSettingConnect;/**< Previous Game Level Setting(Connect) */
 double*         m_mainGameProSettingConnect;/**< Main Game Probability Setting(Connect) */
 double          m_previousMainGameProSettingConnect;/**< Previous Main Game Probability Setting(Connect) */
 /* Probability Status Record */
 unsigned int   m_totalNormalTimes;/**< Total Normal Times */
 unsigned int   m_totalCheck0DownTimes;/**< Total Check0 Down Times */
 unsigned int   m_totalCheck1DownTimes;/**< Total Check1 Down Times */
 unsigned int   m_totalCheck2DownTimes;/**< Total Check2 Down Times */
 unsigned int   m_totalCheck2UpTimes;/**< Total Check2 Up Times */
 unsigned int   m_thisTurnCheck0DownTimes;/**< This Turn Check0 Down Times */
 unsigned int   m_thisTurnCheck1DownTimes;/**< This Turn Check1 Down Times */
 unsigned int   m_thisTurnCheck2DownTimes;/**< This Turn Check2 Down Times */
 unsigned int   m_thisTurnCheck2UpTimes;/**< This Turn Check2 Up Times */
 unsigned int   m_maxCheck0DownTimes;/**< Max Check0 Down Times */
 unsigned int   m_maxCheck1DownTimes;/**< Max Check1 Down Times */
 unsigned int   m_maxCheck2DownTimes;/**< Max Check2 Down Times */
 unsigned int   m_maxCheck2UpTimes;/**< Max Check2 Up Times */
 unsigned int   m_connectRunTimes;/**< Connect Run Times */
/* Small Section Check Control */
 unsigned long  m_smallSectionCheckTimes;/**< Small Section Check Times */
 unsigned long  m_smallSectionPlayTimes;/**< Small Section Play Times */
 unsigned long  m_smallSectionRunTimes;/**< Small Section Run Times */
/* Full Frame Supplementary Control */
 unsigned char  m_supplementary_flag;/**< Supplementary Flag */
 unsigned char  m_supplementary_open_type;/**< Supplementary Open Type */
 unsigned char  m_supplementary_consecutiveness_count;/**< Supplementary Consecutiveness Count */
 unsigned char  m_supplementary_consecutiveness_award_array[8];/**< Supplementary Consecutiveness Award Array */
 unsigned char  m_supplementary_consecutiveness_award_running_index;/**< Supplementary Consecutiveness Award Running Index */
 unsigned char  m_supplementary_consecutiveness_delay_play_times;/**< Supplementary Consecutiveness Delay Play Times */
 unsigned int   m_supplementary_consecutiveness_2_times;/**< Supplementary Consecutiveness 2 Times */
 unsigned int   m_supplementary_consecutiveness_4_times;/**< Supplementary Consecutiveness 4 Times */
 unsigned int   m_supplementary_consecutiveness_8_times;/**< Supplementary Consecutiveness 8 Times */
 unsigned long  m_supplementary_rate;/**< Supplementary Rate */
 unsigned long  m_supplementary_random_rate;/**< Supplementary Random Rate */
 double          m_supplementary_target;/**< Supplementary Target */
 double          m_supplementary_save;/**< Supplementary Save */
 double          m_supplementary_max_save_minus_target;/**< Max Save Minus Target */
 unsigned long  m_supplementary_timing;/**< Supplementary Timing */
 unsigned long  m_supplementary_type;/**< Supplementary Type */
 unsigned long  m_supplementary_award_type;/**< Supplementary Award Type */
 unsigned char  m_supplementary_save_win_flag;/**< Supplementary Save Win Flag */
 unsigned long  m_supplementary_total_win;/**< Supplementary Total Win */
 /* Hot Small Section Control */
 unsigned char  m_hot_small_section_type;/**< Hot Small Section Type */
 unsigned long  m_hot_small_section_run_times;/**< Hot Small Section Run Times */
 /* Special Game Supplementary */
 unsigned int   m_sp_supplementary_target_score;/**< Special Game Supplementary Target Score */
 unsigned int   m_sp_supplementary_save_score;/**< Special Game Supplementary Save Score */
 unsigned char  m_sp_supplementary_flag;/**< Special Game Supplementary Flag */
 unsigned int   m_sp_supplementary_probability_down_open_times;/**< Special Game Supplementary Probability Down Open Times */
 /* Multiple  */
 bool m_getRandomMultipleFlag;/**< Get Random Multiple Flag */
 unsigned int m_randomMultiple;/**< Random Multiple */
 unsigned int m_randomMultiple_x1_times;/**< Random Multiple x1 times */
 unsigned int m_randomMultiple_x2_times;/**< Random Multiple x2 times */
 unsigned int m_randomMultiple_x3_times;/**< Random Multiple x3 times */
 /* Other */
 unsigned char  m_previousStopItem[9];/**< Main Game Previous Stop Item */
 unsigned long  m_statusNormalCheckRandom;/**< Status Normal Check Random */

 /**
  * @brief Constructor.
  */
 MainGameProbabilityControl(
		   GAMEPLAYRECORD* _sectionRecord,//Section Record
		   GAMEPLAYRECORD* _totalRecord,//Total Record
		   unsigned int* _connectSetting,//Connect Setting
		   unsigned int* _gameLevelConnect,//Game Level Setting (Connect)
		   double*        _mainGameProSettingConnect,//Main Game Probability Setting(Connect)
		   unsigned int* _gameLevelSetting,//Game Level Setting
		   double*        _mainGameProSetting,//Main Game Probability Setting
		   unsigned int* _coinValueSetting,//Coin Value Setting
		   unsigned int* _singleLineMaxBetSetting,//Single Line Max Bet Setting
		   MTRANDOM* _mtRandom//MT Random
           )
 {
	 this->Reset(_sectionRecord,
			      _totalRecord,
			      _connectSetting,
			      _gameLevelConnect,
			      _mainGameProSettingConnect,
			      _gameLevelSetting,
			      _mainGameProSetting,
			      _coinValueSetting,
			      _singleLineMaxBetSetting,
			      _mtRandom);
 }

 /**
  * @brief Reset.
  */
 void Reset(
	   GAMEPLAYRECORD* _sectionRecord,//Section Record
	   GAMEPLAYRECORD* _totalRecord,//Total Record
	   unsigned int* _connectSetting,//Connect Setting
	   unsigned int* _gameLevelConnect,//Game Level Setting (Connect)
	   double*        _mainGameProSettingConnect,//Main Game Probability Setting(Connect)
	   unsigned int* _gameLevelSetting,//Game Level Setting
	   double*        _mainGameProSetting,//Main Game Probability Setting
	   unsigned int* _coinValueSetting,//Coin Value Setting
	   unsigned int* _singleLineMaxBetSetting,//Single Line Max Bet Setting
	   MTRANDOM* _mtRandom//MT Random
 	   )
 {
	 //Game Record
	 m_totalRecord                       = _totalRecord;
	 m_sectionRecord                     = _sectionRecord;
	 m_sectionMGPlayScore                = (&_sectionRecord->m_totalMainGamePlayScores);
	 m_sectionMGWinScore                 = (&_sectionRecord->m_totalMainGameWinScores);
	 //連線功能設定值
	 m_connectSetting                    = _connectSetting;
	 m_previousConnectSetting            = *m_connectSetting;
	 //連線時遊戲起伏設定值
	 m_GameLevelSettingConnect           = _gameLevelConnect;
	 m_previousGameLevelSettingConnect   = *m_GameLevelSettingConnect;
	 //連線時機率設定值
	 m_mainGameProSettingConnect         = _mainGameProSettingConnect;
	 m_previousMainGameProSettingConnect = *m_mainGameProSettingConnect;
	 //單機時遊戲起伏設定值
	 m_gameLevelSetting                  = _gameLevelSetting;
	 m_previousGameLevelSetting          = *m_gameLevelSetting;
	 //單機時機率設定值
	 m_mainGameProSetting                = _mainGameProSetting;
	 m_previousMainGameProSetting        = *m_mainGameProSetting;
	 //幣值設定值
	 m_coinValueSetting                  = _coinValueSetting;
	 m_previousCoinValueSetting          = *m_coinValueSetting;
	 //單線最大押分設定值
	 m_singleLineMaxBetSetting           = _singleLineMaxBetSetting;
	 m_previousSingleLineMaxBetSetting   = *m_singleLineMaxBetSetting;
	 //MT Random
	 this->m_mtRandom                   = _mtRandom;

	 //Reset Parameters
	 this->ResetParameters();

#ifdef _DEBUG
	 this->CheckAllDrawCount();
#endif
 }

 /**
  * @brief Reset Parameters.
  */
 void ResetParameters(void){

	 DecideInternalGameLevel();
	 DecideSectionClearScore();

	 m_smallSectionRunTimes = 0;
	 m_smallSectionPlayTimes = 0;
	 DecideSmallSectionCheckPlayTimes();
	 m_supplementary_save_win_flag = false;//Supplementary Save Win Flag
	 m_supplementary_total_win = 0;//Supplementary Total Win
	 m_supplementary_consecutiveness_2_times = 0;
	 m_supplementary_consecutiveness_4_times = 0;
	 m_supplementary_consecutiveness_8_times = 0;
     this->ResetHotSmallSection();
     this->DecideHotSmallSection();
	 this->ResetSupplementary();
     this->DecideSupplementary();
     this->ResetSPSupplementary();
     this->DecideSPSupplementary();
     this->ResetRandomMutiple();

	 //When Ver.single Clear Ram Reset _status = status_normal,or _status = status_Connect
	 if(*this->m_connectSetting ==Connect_ON){
		 //設定機率控制為連線模式
		 m_probabilityControlStatus = status_connect;
		 m_previousProbabilityControlStatus = m_probabilityControlStatus;
		 //設定暫存陣列(機率抽選籤筒)
		 setDrawMatrixByProbabilityStatus();
	 }else{
		 //設定機率控制為單機模式
		 m_probabilityControlStatus = status_normal;
		 m_previousProbabilityControlStatus = m_probabilityControlStatus;
		 //設定暫存陣列(機率抽選籤筒)
		 setDrawMatrixByProbabilityStatus();
	 }
	 //
	 m_sectionTotalClearTimes = 0;
	 m_nextStatusFromMaster = 0;
	 m_canCheckR = false;
	 m_checkRCount = 0;
	 m_randomCheck2Rate = 0;
	 m_receiveConnectInterruptFlag = false;
	 m_totalNormalTimes = 0;
	 m_totalCheck0DownTimes = 0;
	 m_totalCheck1DownTimes = 0;
	 m_totalCheck2DownTimes = 0;
	 m_totalCheck2UpTimes = 0;
	 m_thisTurnCheck0DownTimes=0;
	 m_thisTurnCheck1DownTimes=0;
	 m_thisTurnCheck2DownTimes=0;
	 m_thisTurnCheck2UpTimes=0;
	 m_maxCheck0DownTimes = 0;
	 m_maxCheck1DownTimes = 0;
	 m_maxCheck2DownTimes = 0;
	 m_maxCheck2UpTimes = 0;
	 m_connectRunTimes = 0;
	 m_randomMultiple_x1_times = 0;
	 m_randomMultiple_x2_times = 0;
	 m_randomMultiple_x3_times = 0;
	 //Main Game Probability Setting(Connect) Mapping Array
	 m_mainGameProSettingConnectMappingArray[0] = 96;
	 m_mainGameProSettingConnectMappingArray[1] = 96.5;
	 m_mainGameProSettingConnectMappingArray[2] = 97;
	 m_mainGameProSettingConnectMappingArray[3] = 97.5;
	 m_mainGameProSettingConnectMappingArray[4] = 98;
	 m_mainGameProSettingConnectMappingArray[5] = 98.5;
	 m_mainGameProSettingConnectMappingArray[6] = 99;
	 m_mainGameProSettingConnectMappingArray[7] = 99.5;
	 m_mainGameProSettingConnectMappingArray[8] = 100;
 }

 /**
  * @brief Decide Section Clear Score
  */
 void DecideSectionClearScore(void){
	m_sectionClearScore = *m_singleLineMaxBetSetting * 8 * m_mtRandom->getRandomLong(300000,800000);
 }

 /**
  * @brief Decide Internal Game Level.
  */
 void DecideInternalGameLevel(void){
	unsigned int random   = m_mtRandom->getRandomLong(1000);
	unsigned int random_2 = m_mtRandom->getRandomLong(1000);

	switch(*this->m_gameLevelSetting){

	case Game_Level_Small:
		if(random < 600){
			this->m_internalGameLevel = Game_Level_Small;
		}else{
			if(random_2 < 500){
				this->m_internalGameLevel = Game_Level_Big;
			}else{
				this->m_internalGameLevel = Game_Level_Middle;
			}
		}
		break;

	case Game_Level_Middle:
		if(random < 550){
			this->m_internalGameLevel = Game_Level_Middle;
		}else{
			if(random_2 < 400){
				this->m_internalGameLevel = Game_Level_Big;
			}else{
				this->m_internalGameLevel = Game_Level_Small;
			}
		}
		break;

	case Game_Level_Big:
		if(random < 500){
			this->m_internalGameLevel = Game_Level_Big;
		}else{
			if(random_2 < 400){
				this->m_internalGameLevel = Game_Level_Middle;
			}else{
				this->m_internalGameLevel = Game_Level_Small;
			}
		}
		break;

	default:
#ifdef _DEBUG
		assert(*this->m_gameLevelSetting>=0 && *this->m_gameLevelSetting<=2);
#endif
		break;
	}

}

 /**
  * @brief Decide Small Section Check Play Times
  */
 void DecideSmallSectionCheckPlayTimes(void){
	 unsigned long random = m_mtRandom->getRandomLong(10000);

	 if(random < small_section_game_play_times[0]){
		 this->m_smallSectionCheckTimes = m_mtRandom->getRandomLong(200,300);
	 }else if(random >= small_section_game_play_times[0] && random < small_section_game_play_times[1]){
		 this->m_smallSectionCheckTimes = m_mtRandom->getRandomLong(300,600);
	 }else if(random >= small_section_game_play_times[1] && random < small_section_game_play_times[2]){
		 this->m_smallSectionCheckTimes = m_mtRandom->getRandomLong(600,800);
	 }else if(random >= small_section_game_play_times[2] && random < small_section_game_play_times[3]){
		 this->m_smallSectionCheckTimes = m_mtRandom->getRandomLong(800,1000);
	 }
 }

 /**
  * @brief Every game loop check.
  */
 void EveryLoopCheck(unsigned int bet){
	 //cout<< "###Total Out - Total In : " << (((signed)this->m_totalRecord->m_coinOut+(signed)this->m_totalRecord->m_keyOut) - ((signed)this->m_totalRecord->m_coinIn+(signed)this->m_totalRecord->m_keyIn))/(signed)(*this->m_coinValueSetting) <<endl;

	 //Check System Setting Value
	 this->CheckSettingValume();
	 //Add Small Section Play Times
	 m_smallSectionPlayTimes++;
	 if(m_smallSectionPlayTimes > m_smallSectionCheckTimes){
		 m_smallSectionPlayTimes = 0;
		 m_smallSectionRunTimes++;
		 m_canCheckR = true;
		 DecideSmallSectionCheckPlayTimes();

		 //Check Hot Small Section Run Times
		 if(this->m_smallSectionRunTimes > this->m_hot_small_section_run_times){
			 this->ResetHotSmallSection();
		 }

		 //Check Check2
		 if(m_probabilityControlStatus == status_check2_up || m_probabilityControlStatus == status_check2_down){
			 m_probabilityControlStatus = status_normal;
			 this->setDrawMatrixByProbabilityStatus();
		 }
	 }
	 //Check Probability Status
	 this->CheckStatus();
	 //Run Probability Control
	 this->RunProbabilityControl();
	 //Run Supplementary
	 this->RunSupplementaryCheck(bet);
	 //Run Special Game Supplementary
	 this->RunSPSupplementaryCheck(bet);

	 //Export Probability CSV File
#ifdef EXPORT_PROBABILITY_CSV_FILE
	 this->RunExportProbabilityStatusCSVFile();
#endif

	 //Record Probability Status Run Times
	 this->RecordProbabilityStatusRunTimes();
 }

 /**
  * @brief Run Supplementary Check
  */
 void RunSupplementaryCheck(unsigned int bet){
	 double pro      = 0;
	 double base_pro = 0;
	 double max_save_minus_target = 0;

	 if(this->m_totalRecord->m_totalMainGamePlayScores > 0){
		 pro  = (((double)this->m_totalRecord->m_totalMainGameWinScores / (double)this->m_totalRecord->m_totalMainGamePlayScores ) * 100) - (*this->m_mainGameProSetting);
	 }
	 this->m_supplementary_save += (bet * ((double)this->m_supplementary_rate/100.0));

	 if(this->m_hot_small_section_type == hot_small_section_type_none){
#ifdef TEST_SUPPLEMETARY_CONSECUTIVE
		 if(this->m_supplementary_save > this->m_supplementary_target)
#else
		 if(this->m_supplementary_save > this->m_supplementary_target)
#endif
		 {
			 this->getOpenSupplementaryProbability(&base_pro);

			 if(pro < base_pro){
				 if(this->m_supplementary_flag == supplementary_flag_not_yet){
					 this->m_supplementary_flag = supplementary_flag_open;
				 }
			 }else{
				 max_save_minus_target = (this->m_supplementary_save - this->m_supplementary_target);
				 if(max_save_minus_target > this->m_supplementary_max_save_minus_target){
					 this->m_supplementary_max_save_minus_target = max_save_minus_target;
				 }
			 }
		 }
	 }else{
		 if(this->m_supplementary_save > this->m_supplementary_target){
			 if(this->m_supplementary_flag == supplementary_flag_not_yet){
				 this->m_supplementary_flag = supplementary_flag_open;
			 }
		 }
	 }
 }

 void RunSPSupplementaryCheck(unsigned int bet){
	 unsigned long down_random = 0;
	 this->m_sp_supplementary_save_score += bet;

	 if(this->m_sp_supplementary_save_score > this->m_sp_supplementary_target_score){
		 if(this->m_probabilityControlStatus == status_normal || this->m_probabilityControlStatus == status_check2_up){
			 if(this->m_supplementary_flag != supplementary_flag_open){
				 if(this->m_sp_supplementary_flag == sp_supplementary_flag_not_yet){
					 this->m_sp_supplementary_flag = sp_supplementary_flag_open;
				 }
			 }
		 }else{
			 if(m_smallSectionPlayTimes==0){
				 if(this->m_supplementary_flag != supplementary_flag_open){
					 down_random = this->m_mtRandom->getRandomLong(1000);
					 if(down_random < 200){
						 if(this->m_sp_supplementary_flag == sp_supplementary_flag_not_yet){
							 this->m_sp_supplementary_flag = sp_supplementary_flag_open;
							 this->m_sp_supplementary_probability_down_open_times++;
						 }
					 }
				 }
			 }
		 }
	 }
 }

 /**
  * @brief Main Game Connect Level Matrix Refresh.
  */
 void mainGameConnectLevelMatrixRefresh(void){
	 float gamepro_all_tab[26] = {
	     89, 89.5, 90, 90.5, 91, 91.5, 92, 92.5, 93, 93.5,
	     94, 94.5, 95, 95.5, 96, 96.5, 97, 97.5, 98, 98.5,
	     99, 99.5,100,101,102,104
	 };
	 unsigned int tmp = 0;
	 unsigned int probabilitySetIndex = 0;
	 for(unsigned int idx=0; idx<sizeof(gamepro_all_tab)/sizeof(gamepro_all_tab[0]); idx++){
		 //if(*this->_mainProSet - (this->m_supplementary_rate) == gamepro_all_tab[idx]){
		 if(*this->m_mainGameProSetting - (this->m_supplementary_random_rate) == gamepro_all_tab[idx]){
			 probabilitySetIndex = idx;
		 }
	 }

	 for(unsigned int i=0; i<sizeof(m_connectM)/sizeof(m_connectM[0]); i++){
        tmp = m_mtRandom->getRandomLong(10000);//rand()%10000;//srandNext(0,9999);
        for(unsigned j=0; j<sizeof(MainGameLevelMatrix[0][0])/sizeof(MainGameLevelMatrix[0][0][0]); j++){
        	//if( tmp < MainGameLevelMatrix[*this->_glSetting_link][probabilitySetIndex][j] * 10 )
        	if( tmp < MainGameLevelMatrix[*this->m_GameLevelSettingConnect][probabilitySetIndex][j] * 10 )
        	{
        		m_connectM[i] = j;
        		break;
        	}
        }
	 }

	 /* Old
	 unsigned int tmp = 0;
	 unsigned int k   = getArrayIndexByMainGameProbabilityConnect(*this->m_mainGameProSettingConnect);

	 for(unsigned int i=0; i<sizeof(m_connectM)/sizeof(m_connectM[0]); i++){
        tmp = rand()%10000;//srandNext(0,9999);
        for(unsigned j=0; j<sizeof(LinkMaingameProM[0][0])/sizeof(LinkMaingameProM[0][0][0]); j++){
        	if( tmp < LinkMaingameProM[*this->m_GameLevelSettingConnect][k][j] * 10 ){
        		m_connectM[i] = j;
        		break;
        	}
        }
	 }
	 */
 }

 /**
  * @brief Main Game Stand Along Level Matrix Refresh.
  */
 void mainGameStandAlongLevelMatrixRefresh(void){
	 float gamepro_all_tab[26] = {
	     89, 89.5, 90, 90.5, 91, 91.5, 92, 92.5, 93, 93.5,
	     94, 94.5, 95, 95.5, 96, 96.5, 97, 97.5, 98, 98.5,
	     99, 99.5,100,101,102,104
	 };
	 unsigned int tmp = 0;
	 unsigned int probabilitySetIndex = 0;
	 for(unsigned int idx=0; idx<sizeof(gamepro_all_tab)/sizeof(gamepro_all_tab[0]); idx++){
		 //if(*this->_mainProSet - (this->m_supplementary_rate) == gamepro_all_tab[idx]){
		 if(*this->m_mainGameProSetting - (this->m_supplementary_random_rate) == gamepro_all_tab[idx]){
			 probabilitySetIndex = idx;
		 }
	 }

	 for(unsigned int i=0; i<sizeof(m_normalM)/sizeof(m_normalM[0]); i++){
        tmp = m_mtRandom->getRandomLong(10000);//rand()%10000;//srandNext(0,9999);
        for(unsigned j=0; j<sizeof(MainGameLevelMatrix[0][0])/sizeof(MainGameLevelMatrix[0][0][0]); j++){
        	//if( tmp < MainGameLevelMatrix[*this->_glSetting_link][probabilitySetIndex][j] * 10 )
        	if( tmp < MainGameLevelMatrix[this->m_internalGameLevel][probabilitySetIndex][j] * 10 )
        	{
        		m_normalM[i] = j;
        		break;
        	}
        }
	 }

 }

 /**
  * @brief Get Check1 Level(A,B,C).
  */
 void getCheck1Level(char* level){
	   if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_A_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))){//A Section
		   *level = 'A';
	   }

	   if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_B_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))){//B Section
		   *level = 'B';
	   }

	   if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_C_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))){//C Section
		   *level = 'C';
	   }
 }

 /**
  * @brief Get Open Supplementary Probability.
  * @param pro Probability
  */
 void getOpenSupplementaryProbability(double* pro){
	   if(*this->m_sectionMGPlayScore  <  (unsigned long)((SMALL_SECTION_B_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))){//A Section
		   *pro = 1;
	   }
	   else if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_B_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))) &&
			    *this->m_sectionMGPlayScore <  (unsigned long)((SMALL_SECTION_C_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))){//B Section
		   *pro = 2;
	   }
	   else if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_C_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))){//C Section
		   *pro = 1;
	   }
 }

 /**
  * @brief Get Check1 A Section Check Start Value.
  */
 long getCheck1ASectionCheckStartRValue(long _sectionTotalPlayScores){
	unsigned long baseValue = SMALL_SECTION_A_START_R_VALUE;
	unsigned long cnt = 0;

	if(_sectionTotalPlayScores < (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))){
		return (baseValue * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
	}else{
		for(unsigned int idx=0; ;idx++){
			if((_sectionTotalPlayScores-(1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))) - (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)) > 0){
				_sectionTotalPlayScores -= (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
				cnt++;
			}else{
				break;
			}
		}

		for(unsigned int idx=0; idx<cnt; idx++){
			baseValue += SMALL_SECTION_A_START_R_ADD_STEP;
		}

		return (baseValue * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
	}
}

 /**
  * @brief Get Check1 B Section Check Start Value.
  */
 long getCheck1BSectionCheckStartRValue(long _sectionTotalPlayScores){
	unsigned long baseValue = SMALL_SECTION_B_START_R_VALUE;
	unsigned long cnt = 0;

	for(unsigned int idx=0; ;idx++){
		if((_sectionTotalPlayScores-(5000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))) - (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)) > 0){
			_sectionTotalPlayScores -= (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
			cnt++;
		}else{
			break;
		}
	}

	for(unsigned int idx=0; idx<cnt; idx++){
		baseValue += SMALL_SECTION_B_START_R_ADD_STEP;
	}

	return (baseValue * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));

}

 /**
  * @brief Get Check1 C Section Check Start Value.
  */
 long getCheck1CSectionCheckStartRValue(long _sectionTotalPlayScores){
	unsigned long baseValue = SMALL_SECTION_C_START_R_VALUE;
	unsigned long cnt = 0;

	for(unsigned int idx=0; ;idx++){
		if((_sectionTotalPlayScores-(10000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))) - (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)) > 0){
			_sectionTotalPlayScores -= (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
			cnt++;
		}else{
			break;
		}
	}

	for(unsigned int idx=0; idx<cnt; idx++){
		baseValue += SMALL_SECTION_C_START_R_ADD_STEP;
	}

	return (baseValue * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
}

 /**
  * @brief Get Check1 A Section Check End Value.
  */
 long getCheck1ASectionCheckEndRValue(long _sectionTotalPlayScores){
	unsigned long baseValue = SMALL_SECTION_A_END_R_VALUE;
	unsigned long cnt = 0;

	if(_sectionTotalPlayScores < (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))){
		return (baseValue * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
	}else{
		for(unsigned int idx=0; ;idx++){
			if((_sectionTotalPlayScores-(1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))) - (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)) > 0){
				_sectionTotalPlayScores -= (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
				cnt++;
			}else{
				break;
			}
		}

		for(unsigned int idx=0; idx<cnt; idx++){
			baseValue += SMALL_SECTION_A_END_R_ADD_STEP;
		}

		return (baseValue * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
	}
}

 /**
  * @brief Get Check1 A Section Check End Value.
  */
 long getCheck1BSectionCheckEndRValue(long _sectionTotalPlayScores){
	unsigned long baseValue = SMALL_SECTION_B_END_R_VALUE;
	unsigned long cnt = 0;

	for(unsigned int idx=0; ;idx++){
		if((_sectionTotalPlayScores-(5000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))) - (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)) > 0){
			_sectionTotalPlayScores -= (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
			cnt++;
		}else{
			break;
		}
	}

	for(unsigned int idx=0; idx<cnt; idx++){
		baseValue += SMALL_SECTION_B_END_R_ADD_STEP;
	}

	return (baseValue * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
}

 /**
  * @brief Get Check1 A Section Check End Value.
  */
 long getCheck1CSectionCheckEndRValue(long _sectionTotalPlayScores){
	unsigned long baseValue = SMALL_SECTION_C_END_R_VALUE;
	unsigned long cnt = 0;

	for(unsigned int idx=0; ;idx++){
		if((_sectionTotalPlayScores-(10000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))) - (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)) > 0){
			_sectionTotalPlayScores -= (1000000*((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
			cnt++;
		}else{
			break;
		}
	}

	for(unsigned int idx=0; idx<cnt; idx++){
		baseValue += SMALL_SECTION_C_END_R_ADD_STEP;
	}

	return (baseValue * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE));
}

 /**
  * @brief Set Draw Matrix By Probability Status.
  */
 void setDrawMatrixByProbabilityStatus(void){
	 m_indexOfRunning = 0;//執行中籤筒索引值
	 m_timesOfRunning = 8 + rand()%15;//執行中籤筒局數 8~22

	 switch(m_probabilityControlStatus){
	 case status_normal://正常狀態
		 this->mainGameStandAlongLevelMatrixRefresh();
		 break;
	 case status_check0_down://防深下拉
	 case status_check1_down://小局下拉
	 case status_check2_down://下拉
         for(unsigned int i=0; i<sizeof(m_downM)/sizeof(m_downM[0]); i++){
        	 m_downM[i] = mtRandom.getRandomLong(5);
         }
		 break;
	 case status_check2_up://上拉
         for(unsigned int i=0; i<sizeof(m_upM)/sizeof(m_upM[0]); i++){
        	 m_upM[i] = mtRandom.getRandomLong(5);
         }
		 break;
	 case status_connect://連線狀態
         this->mainGameConnectLevelMatrixRefresh();
		 break;

	 default:
		 break;
	 }
 }

 /**
  * @brief Status Normal Check.
  */
 void statusNormalCheck(void){
   //if(_checkRCount >= 1){// 跑過一輪籤筒
	   //unsigned long random = m_mtRandom->getRandomLong(1000);
	   this->m_statusNormalCheckRandom = m_mtRandom->getRandomLong(1000);
	   m_checkRCount = 0;

	   if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_B_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))){
		   // Check 0 Check(防深檢查)
		   if(((signed)this->m_totalRecord->m_coinOut+(signed)this->m_totalRecord->m_keyOut) - ((signed)this->m_totalRecord->m_coinIn+(signed)this->m_totalRecord->m_keyIn) > (signed)(CHECK0_COIN_COUNT_LEVEL_1 * (*m_coinValueSetting))){
			   // 95 % do
			   if(this->m_statusNormalCheckRandom < 950){
				   this->m_probabilityControlStatus = status_check0_down;
				   this->setDrawMatrixByProbabilityStatus();
				   return;
			   }
		   }else if(((signed)this->m_totalRecord->m_coinOut+(signed)this->m_totalRecord->m_keyOut) - ((signed)this->m_totalRecord->m_coinIn+(signed)this->m_totalRecord->m_keyIn) > (signed)(CHECK0_COIN_COUNT_LEVEL_2 * (*m_coinValueSetting))){
			   // 50 % do
			   if(this->m_statusNormalCheckRandom < 500){
				   this->m_probabilityControlStatus = status_check0_down;
				   this->setDrawMatrixByProbabilityStatus();
				   return;
			   }
			   //return;
		   }else if(((signed)this->m_totalRecord->m_coinOut+(signed)this->m_totalRecord->m_keyOut) - ((signed)this->m_totalRecord->m_coinIn+(signed)this->m_totalRecord->m_keyIn) > (signed)(CHECK0_COIN_COUNT_LEVEL_3 * (*m_coinValueSetting))){
			   // 10 %
			   if(this->m_statusNormalCheckRandom < 100){
				   this->m_probabilityControlStatus = status_check0_down;
				   this->setDrawMatrixByProbabilityStatus();
				   return;
			   }
			   //return;
		   }
	   }

	   // Check 1 Check(小局檢查)
	   if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_A_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))
			   && *this->m_sectionMGPlayScore < (unsigned long)((SMALL_SECTION_B_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))){//A Section
		   if(this->getRValue() > getCheck1ASectionCheckStartRValue(*this->m_sectionMGPlayScore)){
			   // 64 % do
			   if(this->m_statusNormalCheckRandom < 640){
				   this->m_probabilityControlStatus = status_check1_down;
				   this->setDrawMatrixByProbabilityStatus();
				   return;
			   }
			   //return;
		   }
	   }else if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_B_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))
			   && *this->m_sectionMGPlayScore < (unsigned long)((SMALL_SECTION_C_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))){//B Section
		   if(this->getRValue() > getCheck1BSectionCheckStartRValue(*this->m_sectionMGPlayScore)){
			   // 72 % do
			   if(this->m_statusNormalCheckRandom < 720){
				   this->m_probabilityControlStatus = status_check1_down;
				   this->setDrawMatrixByProbabilityStatus();
				   return;
			   }
			   //return;
		   }
	   }else if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_C_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))){//C Section
		   if(this->getRValue() > getCheck1CSectionCheckStartRValue(*this->m_sectionMGPlayScore)){
			   // 81 % do
			   if(this->m_statusNormalCheckRandom < 810){
				   this->m_probabilityControlStatus = status_check1_down;
				   this->setDrawMatrixByProbabilityStatus();
				   return;
			   }
			   //return;
		   }
	   }
	   // Check 2 Check(上下拉檢查)
		double pro = 0;//目前大局機械機率
		if(this->m_sectionMGPlayScore > 0){
			pro  = ((((double)*this->m_sectionMGWinScore - (double)this->m_supplementary_total_win)/ (double)*this->m_sectionMGPlayScore ) * 100);
			//pro  = (((double)*this->m_sectionMGWinScore / (double)*this->m_sectionMGPlayScore ) * 100);
		}

		m_randomCheck2Rate = m_mtRandom->getRandomLong(1,5);

		if(this->m_hot_small_section_type == hot_small_section_type_R1100){

			if(pro < 100 - m_randomCheck2Rate){//this->m_supplementary_rate){//上拉
				// 70 % do
			   if(this->m_statusNormalCheckRandom < 700){
				   this->m_probabilityControlStatus = status_check2_up;
				   this->setDrawMatrixByProbabilityStatus();
				   return;
			   }
			   //return;
			}else if(pro > 100 + m_randomCheck2Rate){//this->m_supplementary_rate){//下拉
				// 70 % do
			   if(this->m_statusNormalCheckRandom < 700){
				   this->m_probabilityControlStatus = status_check2_down;
				   this->setDrawMatrixByProbabilityStatus();
				   return;
			   }
			   //return;
			}

		}else{

			if(pro < *this->m_mainGameProSetting - m_randomCheck2Rate){//this->m_supplementary_rate){//上拉
				// 70 % do
			   if(this->m_statusNormalCheckRandom < 700){
				   this->m_probabilityControlStatus = status_check2_up;
				   this->setDrawMatrixByProbabilityStatus();
				   return;
			   }
			   //return;
			}else if(pro > *this->m_mainGameProSetting + m_randomCheck2Rate){//this->m_supplementary_rate){//下拉
				// 70 % do
			   if(this->m_statusNormalCheckRandom < 700){
				   this->m_probabilityControlStatus = status_check2_down;
				   this->setDrawMatrixByProbabilityStatus();
				   return;
			   }
			   //return;
			}
		}
   //}
#ifdef EXPORT_PROBABILITY_CSV_FILE_EVERY_CHECK
		this->RunExportProbabilityStatusCSVFileEveryCheck();
#endif
 }

 /**
  * @brief Status Check0 Down Check.
  */
 void statusCheck0DownCheck(void){
	 //解除條件:R值<=0 且 營業% <= 設定機械%
	 double coin_pro = ((double)this->m_totalRecord->m_coinOut+(double)this->m_totalRecord->m_keyOut)/((double)this->m_totalRecord->m_coinIn+(double)this->m_totalRecord->m_keyIn) * 100;

	 if(this->getRValue() <= 0 && coin_pro <= *this->m_mainGameProSetting){
		 //lift check0 down
		 this->m_probabilityControlStatus = status_normal;
		 this->setDrawMatrixByProbabilityStatus();
	 }
 }

 /**
  * @brief Status Check1 Down Check.
  */
 void statusCheck1DownCheck(void){
	   //lift check1 down
	   if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_A_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))
			   && *this->m_sectionMGPlayScore < (unsigned long)((SMALL_SECTION_B_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))) )
	   {//A Section
		   if(this->getRValue() < getCheck1ASectionCheckEndRValue(*this->m_sectionMGPlayScore)){
			   //lift
			   this->m_probabilityControlStatus = status_normal;
			   this->setDrawMatrixByProbabilityStatus();
			   return;
		   }
	   }else if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_B_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE)))
			   && *this->m_sectionMGPlayScore < (unsigned long)((SMALL_SECTION_C_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))) )
	   {//B Section
		   if(this->getRValue() < getCheck1BSectionCheckEndRValue(*this->m_sectionMGPlayScore)){
			   //lift
			   this->m_probabilityControlStatus = status_normal;
			   this->setDrawMatrixByProbabilityStatus();
			   return;
		   }
	   }else if(*this->m_sectionMGPlayScore >= (unsigned long)((SMALL_SECTION_C_CHECK_SCORE * ((float)*this->m_singleLineMaxBetSetting/SINGLE_LINE_BET_BASE))))
	   {//C Section
		   if(this->getRValue() < getCheck1CSectionCheckEndRValue(*this->m_sectionMGPlayScore)){
			   //lift
			   this->m_probabilityControlStatus = status_normal;
			   this->setDrawMatrixByProbabilityStatus();
			   return;
		   }
	   }
 }

 /**
  * @brief Status Check2 Down Check.
  */
 void statusCheck2DownCheck(void){
	 //do nothing
 }

 /**
  * @brief Status Check2 Up Check.
  */
 void statusCheck2UpCheck(void){
	 //do nothing
 }

 /**
  * @brief Status Connect Normal Check.
  */
 void statusConnectNormalCheck(void){
      if(m_receiveConnectInterruptFlag==true){
    	 //_CheckSettingValume();
	     ChangeConnectStatus();
    	 m_receiveConnectInterruptFlag = false;
      }
 }

 /**
  * @brief Status Connect Up Check.
  */
 void statusConnectUpCheck(){
     /*
	 if(m_receiveConnectInterruptFlag==true){
    	//_CheckSettingValume();
	    ChangeConnectStatus();
    	m_receiveConnectInterruptFlag = false;
     }else{
  	   m_allUpGTimes++;
  	   m_totalUpGameTimes++;
  	   if(m_totalUpGameTimes > m_maxUpGameTimes){
  		  m_maxUpGameTimes = m_totalUpGameTimes;
  	   }
     }
     */
 }

 /**
  * @brief Status Connect Down Check.
  */
 void statusConnectDownCheck(){
     /*
	 if(m_receiveConnectInterruptFlag==true){
    	//_CheckSettingValume();
	    ChangeConnectStatus();
      	m_receiveConnectInterruptFlag = false;
     }else{
  	   m_allDownGTimes++;
  	   m_totalDownGameTimes++;
  	   if(m_totalDownGameTimes > m_maxDownGameTimes){
  		  m_maxDownGameTimes = m_totalDownGameTimes;
  	   }
     }
     */
 }

 /**
  * @brief Check Setting Value.
  */
 void CheckSettingValume(void){

     //If Connect Setting Change
	 if(m_previousConnectSetting != *m_connectSetting){
         //判斷目前的連線設定值
		 switch(*m_connectSetting)
		 {
			 case Connect_ON:  //Connect Off -> Connect On
				 m_probabilityControlStatus = status_connect;
				 setDrawMatrixByProbabilityStatus();
				 m_sectionRecord->Reset();
				 this->ResetParameters();
				 //(*m_sectionRecord) = (*m_totalRecord);//?????
				 m_sectionRecord->m_totalMainGamePlayScores += 100000;
				 m_sectionRecord->m_totalMainGameWinScores += (unsigned long)((float)100000 * ((float)(*this->m_mainGameProSettingConnect) / (float)100));
				 m_checkRCount = 0;
				 break;

			 case Connect_OFF://Connect On -> Connect Off
				 m_probabilityControlStatus = status_normal;
				 setDrawMatrixByProbabilityStatus();
				 m_sectionRecord->Reset();
				 this->ResetParameters();
				 //(*m_sectionRecord) = (*m_totalRecord);//?????
				 m_checkRCount = 0;
				 break;

			 default:
				 break;
		 }

		m_previousConnectSetting = *m_connectSetting;
		return;
	 }

	 //If Connect Setting Don't Change
	 //Ver.Connect
	 if(getConnectSetting()==Connect_ON ){
		 //Main Probability Set Ver.link & GL Ver.link
		 if(m_previousMainGameProSettingConnect != *m_mainGameProSettingConnect || m_previousGameLevelSettingConnect != *m_GameLevelSettingConnect ){
             //Do Nothing
			 //m_probabilityControlStatus = status_connect;
             //setDrawMatrixByProbabilityStatus();

             //Save present setting value as previous
			 m_previousMainGameProSettingConnect = *m_mainGameProSettingConnect;
			 m_previousGameLevelSettingConnect   = *m_GameLevelSettingConnect;
		 }

		 //Single Line Max Bet
		 if(m_previousSingleLineMaxBetSetting != *m_singleLineMaxBetSetting){
			 m_sectionRecord->Reset();
			 this->ResetParameters();
			 m_previousSingleLineMaxBetSetting = *m_singleLineMaxBetSetting;
		 }
	 }
	 //Ver.Stand Alone
	 else{
		 //Single Line Max Bet
		 if(m_previousSingleLineMaxBetSetting != *m_singleLineMaxBetSetting){
			 m_sectionRecord->Reset();
			 this->ResetParameters();
			 m_previousSingleLineMaxBetSetting = *m_singleLineMaxBetSetting;
		 }

		 //Game Level
		 if(m_previousGameLevelSetting != *m_gameLevelSetting){
			 //Do Nothing

			 //Save present setting value to previous
			 m_previousGameLevelSetting =  *m_gameLevelSetting;
		 }

		 //Main Probability Setting & Coin Value Setting
		 if(m_previousMainGameProSetting != *m_mainGameProSetting || m_previousCoinValueSetting != *m_coinValueSetting){
             //Do Nothing
			 //m_probabilityControlStatus = status_normal;
             //setDrawMatrixByProbabilityStatus();

             ////Save present setting value to previous
			 m_previousMainGameProSetting = *m_mainGameProSetting;
			 m_previousCoinValueSetting   = *m_coinValueSetting;
		 }
	 }
 }

 /**
  * @brief Check Probability Control Status.
  */
 void CheckStatus(void){
	 //大局清帳
	 if( (*m_sectionMGPlayScore > m_sectionClearScore) && getConnectSetting()!=Connect_ON ){
		 m_probabilityControlStatus = status_normal;
		 m_sectionRecord->Reset();
		 DecideInternalGameLevel();
		 DecideSectionClearScore();
		 DecideSmallSectionCheckPlayTimes();
		 m_smallSectionRunTimes = 0;
		 m_sectionTotalClearTimes++;
		 m_canCheckR = false;
		 m_supplementary_total_win = 0;//Supplementary Total Win
		 m_supplementary_max_save_minus_target = 0;
		 // Clear & Decide Hot Small Section
		 this->ResetHotSmallSection();
		 this->DecideHotSmallSection();
		 // Clear & Decide Supplementary
		 this->ResetSupplementary();
		 this->DecideSupplementary();
		 //
		 this->setDrawMatrixByProbabilityStatus();
	 }

	 switch(this->m_probabilityControlStatus){

	 case status_normal:
         if(m_canCheckR == true){
        	 this->statusNormalCheck();
        	 m_canCheckR = false;
         }
		 break;
	 case status_check0_down://防深下拉
		 this->statusCheck0DownCheck();
		 break;
	 case status_check1_down://小局下拉
		 this->statusCheck1DownCheck();
		 break;
	 case status_check2_down://下拉
		 this->statusCheck2DownCheck();
		 break;
	 case status_check2_up://上拉
		 this->statusCheck2UpCheck();
		 break;
	 case status_connect:
		 this->statusConnectNormalCheck();

		 break;

	 default:

		 break;

	 }

	 if(getConnectSetting()==Connect_ON){
		 m_connectRunTimes++;
	 }
 }

 /**
  * @brief Run probability control.
  */
 void RunProbabilityControl(void){

	 switch(this->m_probabilityControlStatus){

	 case status_normal:
         if( m_timesOfRunning > 0 ){
        	  m_timesOfRunning--;
         }else{
        	 m_indexOfRunning++;
        	 if(m_indexOfRunning  > 14 ){
        		 m_indexOfRunning %= 15;
        		 this->setDrawMatrixByProbabilityStatus();
        		 m_checkRCount++;// 10/02/03
        		 //if(*_sectionTotalPlayScore > (unsigned long)((float)1000 * ((float)*_coinSet/(float)100) * 6 )){
        			 //_isCanCheckR = true;
        		 //}
        	 }
        	 m_timesOfRunning = 8 + (rand()%15);//8 ~ 22
         }
		 break;

	 case status_check2_up:
         if( m_timesOfRunning > 0 ){
        	  m_timesOfRunning--;
         }else{
        	 m_indexOfRunning++;
        	 if(m_indexOfRunning  > 4 ){
        		 m_indexOfRunning %= 5;
        	 }
        	 m_timesOfRunning = 8 + (rand()%15);//8 ~ 22
         }
		 break;

	 case status_check0_down:
	 case status_check1_down:
	 case status_check2_down:
         if( m_timesOfRunning > 0 ){
        	  m_timesOfRunning--;
         }else{
        	 m_indexOfRunning++;
        	 if(m_indexOfRunning  > 4 ){
        		m_indexOfRunning %= 5;
        	 }
        	 m_timesOfRunning = 8 + (rand()%15);//8 ~ 22
         }

		 break;
	 case status_connect:
         if( m_timesOfRunning > 0 ){
        	  m_timesOfRunning--;
         }else{
        	 m_indexOfRunning++;
        	 if(m_indexOfRunning  > 14 ){
        		 m_indexOfRunning %= 15;
        		 this->mainGameConnectLevelMatrixRefresh();
        	 }
        	 m_timesOfRunning = 8 + (rand()%15);//8 ~ 22
         }
		 break;

	 default:

		 break;
	 }

 }

 /**
  * @brief Change Connect Status.
  */
 void ChangeConnectStatus(void){
     m_probabilityControlStatus = (int)this->m_nextStatusFromMaster;
     setDrawMatrixByProbabilityStatus();
 }

 /**
  * @brief Reset Hot Section.
  */
 void ResetHotSmallSection(){
	 this->m_hot_small_section_type = hot_small_section_type_none;
	 this->m_hot_small_section_run_times = 0;
 }

 /**
  * @brief Decide Hot Small Section.
  */
 void DecideHotSmallSection(){
	 unsigned long random = m_mtRandom->getRandomLong(1000);

	 //Decide Have Small Section or not
	 if(random < 600){

		 random = m_mtRandom->getRandomLong(1000);
		 //Decide Hot Small Section Type
		 if(random < 500){
			 this->m_hot_small_section_type = hot_small_section_type_R1100;
			 //Decide Hot Small Section Run Times
			 this->m_hot_small_section_run_times = m_mtRandom->getRandomLong(15,50);
		 }else{
			 this->m_hot_small_section_type = hot_small_section_type_full_frame_award_ahead;
		 }

	 }else{
		 //Have No Hot Small Section
		 this->m_hot_small_section_type = hot_small_section_type_none;
		 this->m_hot_small_section_run_times = 0;
	 }

 }

 /**
  * @brief Reset Supplementary.
  */
 void ResetSupplementary(void){
 	 m_supplementary_flag = supplementary_flag_not_yet;
 	 m_supplementary_rate = 0;
 	 m_supplementary_consecutiveness_count = 0;
 	 for(unsigned int idx=0; idx<sizeof(m_supplementary_consecutiveness_award_array)/sizeof(m_supplementary_consecutiveness_award_array[0]); idx++){
 		 m_supplementary_consecutiveness_award_array[idx] = supplementary_award_type_multiple_none;
 	 }
 	 m_supplementary_consecutiveness_award_running_index = 0;
 	 m_supplementary_consecutiveness_delay_play_times = 0;
 	 m_supplementary_random_rate = 0;
     m_supplementary_target = 0;
     m_supplementary_save = 0;
     m_supplementary_timing = supplementary_timing_none;
     m_supplementary_type = supplementary_type_none;
     m_supplementary_award_type = supplementary_award_type_multiple_none;
 }

 /**
  * @brief Decide Full Frame Supplementary.
  */
 void DecideSupplementary(void){
 	/*** Decide Supplementary Rate ***/
 	unsigned int random = m_mtRandom->getRandomLong(10000);
 	if(random < supplementary_rate_draw_table[0]){
 		this->m_supplementary_rate = 3;
 		this->m_supplementary_random_rate = m_mtRandom->getRandomLong(1,this->m_supplementary_rate);
 	}else if(random >= supplementary_rate_draw_table[0] && random < supplementary_rate_draw_table[1]){
 		this->m_supplementary_rate = 4;
 		this->m_supplementary_random_rate = m_mtRandom->getRandomLong(1,this->m_supplementary_rate);
 	}else if(random >= supplementary_rate_draw_table[1] && random < supplementary_rate_draw_table[2]){
 		this->m_supplementary_rate = 5;
 		this->m_supplementary_random_rate = m_mtRandom->getRandomLong(1,this->m_supplementary_rate);
 	}else if(random >= supplementary_rate_draw_table[2] && random < supplementary_rate_draw_table[3]){
 		this->m_supplementary_rate = 6;
 		this->m_supplementary_random_rate = m_mtRandom->getRandomLong(1,this->m_supplementary_rate);
 	}else if(random >= supplementary_rate_draw_table[3] && random < supplementary_rate_draw_table[4]){
 		this->m_supplementary_rate = 7;
 		this->m_supplementary_random_rate = m_mtRandom->getRandomLong(1,this->m_supplementary_rate);
 	}

 	/*** Decide Supplementary Type ***/
 	random = m_mtRandom->getRandomLong(10000);
 	if(random < supplementary_type_draw_table[0]){
 		this->m_supplementary_type = supplementary_type_small;
 	}else if(random >= supplementary_type_draw_table[0] && random < supplementary_type_draw_table[1]){
 		this->m_supplementary_type = supplementary_type_big;
 	}

 	//If Hot Small Section is full frame award ahead, set supplementary to big
 	if(this->m_hot_small_section_type == hot_small_section_type_full_frame_award_ahead){
 		this->m_supplementary_type = supplementary_type_big;
 	}

 	unsigned int random_Consecutiveness = m_mtRandom->getRandomLong(1000);
 	unsigned int consecutiveness_array_index[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
 	unsigned int index_1=0;
 	unsigned int index_2=0;

#ifdef TEST_SUPPLEMETARY_CONSECUTIVE
 	/*** For Test Consecutive ***/
 	this->m_supplementary_type = supplementary_type_big;
#endif

 	/*** Decide Supplementary Award Type ***/
 	switch(this->m_supplementary_type){
 	case supplementary_type_small:
 			random = m_mtRandom->getRandomLong(10000);
 			if(random < supplementary_type_small_draw_table[0]){
 				this->m_supplementary_award_type = supplementary_award_type_multiple_50;
 				this->m_supplementary_open_type = supplementary_open_type_one_time;
 			}else if(random >= supplementary_type_small_draw_table[0] && random < supplementary_type_small_draw_table[1]){
 				this->m_supplementary_award_type = supplementary_award_type_multiple_100;
 				this->m_supplementary_open_type = supplementary_open_type_one_time;
 			}else if(random >= supplementary_type_small_draw_table[1] && random < supplementary_type_small_draw_table[2]){
 				this->m_supplementary_award_type = supplementary_award_type_multiple_150;
 				this->m_supplementary_open_type = supplementary_open_type_one_time;
 			}else if(random >= supplementary_type_small_draw_table[2] && random < supplementary_type_small_draw_table[3]){
 				this->m_supplementary_award_type = supplementary_award_type_multiple_250;
 				this->m_supplementary_open_type = supplementary_open_type_one_time;
 			}else if(random >= supplementary_type_small_draw_table[3] && random < supplementary_type_small_draw_table[4]){
 				this->m_supplementary_award_type = supplementary_award_type_multiple_400;
 				this->m_supplementary_open_type = supplementary_open_type_one_time;
 			}

 			break;
 	case supplementary_type_big:
				//If Hot Small Section is full frame award ahead, don't draw multiple 4000
				if(this->m_hot_small_section_type == hot_small_section_type_full_frame_award_ahead){
					random = m_mtRandom->getRandomLong(9000);
				}else{
					random = m_mtRandom->getRandomLong(10000);
				}

				if(random < supplementary_type_big_draw_table[0]){//800X
#ifdef TEST_SUPPLEMETARY_CONSECUTIVE
					if(random_Consecutiveness < 1000)
#else
					if(random_Consecutiveness < 350)
#endif
					{
						this->m_supplementary_open_type = supplementary_open_type_consecutiveness;
						this->m_supplementary_consecutiveness_count = 4;
						this->m_supplementary_consecutiveness_award_running_index = 0;
						this->m_supplementary_consecutiveness_delay_play_times = 0;
						this->m_supplementary_consecutiveness_4_times++;

						for(unsigned int idx=0,tmp=0; idx<300; idx++){
							index_1 = m_mtRandom->getRandomLong(4);
							index_2 = m_mtRandom->getRandomLong(4);

							tmp  = consecutiveness_array_index[index_1];
							consecutiveness_array_index[index_1] = consecutiveness_array_index[index_2];
							consecutiveness_array_index[index_2] = tmp;
						}
						this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[0]] = supplementary_award_type_multiple_400;
						this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[1]] = supplementary_award_type_multiple_150;
						this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[2]] = supplementary_award_type_multiple_150;
						this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[3]] = supplementary_award_type_multiple_100;

					}else{
						this->m_supplementary_award_type = supplementary_award_type_multiple_800;
						this->m_supplementary_open_type = supplementary_open_type_one_time;
					}
				}else if(random >= supplementary_type_big_draw_table[0] && random < supplementary_type_big_draw_table[1]){//1000X
#ifdef TEST_SUPPLEMETARY_CONSECUTIVE
					if(random_Consecutiveness < 1000)
#else
					if(random_Consecutiveness < 350)
#endif
					{
						if(m_mtRandom->getRandomLong(2)==0){
							this->m_supplementary_open_type = supplementary_open_type_consecutiveness;
							this->m_supplementary_consecutiveness_count = 4;
							this->m_supplementary_consecutiveness_award_running_index = 0;
							this->m_supplementary_consecutiveness_delay_play_times = 0;
							this->m_supplementary_consecutiveness_4_times++;

							for(unsigned int idx=0,tmp=0; idx<300; idx++){
								index_1 = m_mtRandom->getRandomLong(4);
								index_2 = m_mtRandom->getRandomLong(4);

								tmp  = consecutiveness_array_index[index_1];
								consecutiveness_array_index[index_1] = consecutiveness_array_index[index_2];
								consecutiveness_array_index[index_2] = tmp;
							}

							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[0]] = supplementary_award_type_multiple_400;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[1]] = supplementary_award_type_multiple_400;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[2]] = supplementary_award_type_multiple_150;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[3]] = supplementary_award_type_multiple_50;

						}else{
							this->m_supplementary_open_type = supplementary_open_type_consecutiveness;
							this->m_supplementary_consecutiveness_count = 2;
							this->m_supplementary_consecutiveness_award_running_index = 0;
							this->m_supplementary_consecutiveness_delay_play_times = 0;
							this->m_supplementary_consecutiveness_2_times++;

							for(unsigned int idx=0,tmp=0; idx<50; idx++){
								index_1 = m_mtRandom->getRandomLong(2);
								index_2 = m_mtRandom->getRandomLong(2);

								tmp  = consecutiveness_array_index[index_1];
								consecutiveness_array_index[index_1] = consecutiveness_array_index[index_2];
								consecutiveness_array_index[index_2] = tmp;
							}

							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[0]] = supplementary_award_type_multiple_800;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[1]] = supplementary_award_type_multiple_250;
						}

					}else{
						this->m_supplementary_award_type = supplementary_award_type_multiple_1000;
						this->m_supplementary_open_type = supplementary_open_type_one_time;
					}
				}else if(random >= supplementary_type_big_draw_table[1] && random < supplementary_type_big_draw_table[2]){//2500X
#ifdef TEST_SUPPLEMETARY_CONSECUTIVE
					if(random_Consecutiveness < 1000)
#else
					if(random_Consecutiveness < 350)
#endif
					{
						if(m_mtRandom->getRandomLong(2)==0){
							this->m_supplementary_open_type = supplementary_open_type_consecutiveness;
							this->m_supplementary_consecutiveness_count = 4;
							this->m_supplementary_consecutiveness_award_running_index = 0;
							this->m_supplementary_consecutiveness_delay_play_times = 0;
							this->m_supplementary_consecutiveness_4_times++;

							for(unsigned int idx=0,tmp=0; idx<300; idx++){
								index_1 = m_mtRandom->getRandomLong(4);
								index_2 = m_mtRandom->getRandomLong(4);

								tmp  = consecutiveness_array_index[index_1];
								consecutiveness_array_index[index_1] = consecutiveness_array_index[index_2];
								consecutiveness_array_index[index_2] = tmp;
							}

							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[0]] = supplementary_award_type_multiple_1000;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[1]] = supplementary_award_type_multiple_1000;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[2]] = supplementary_award_type_multiple_400;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[3]] = supplementary_award_type_multiple_100;
						}else{
							this->m_supplementary_open_type = supplementary_open_type_consecutiveness;
							this->m_supplementary_consecutiveness_count = 8;
							this->m_supplementary_consecutiveness_award_running_index = 0;
							this->m_supplementary_consecutiveness_delay_play_times = 0;
							this->m_supplementary_consecutiveness_8_times++;

							for(unsigned int idx=0,tmp=0; idx<300; idx++){
								index_1 = m_mtRandom->getRandomLong(8);
								index_2 = m_mtRandom->getRandomLong(8);

								tmp  = consecutiveness_array_index[index_1];
								consecutiveness_array_index[index_1] = consecutiveness_array_index[index_2];
								consecutiveness_array_index[index_2] = tmp;
							}

							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[0]] = supplementary_award_type_multiple_800;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[1]] = supplementary_award_type_multiple_400;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[2]] = supplementary_award_type_multiple_400;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[3]] = supplementary_award_type_multiple_400;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[4]] = supplementary_award_type_multiple_250;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[5]] = supplementary_award_type_multiple_100;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[6]] = supplementary_award_type_multiple_100;
							this->m_supplementary_consecutiveness_award_array[consecutiveness_array_index[7]] = supplementary_award_type_multiple_100;
						}
					}else{
						this->m_supplementary_award_type = supplementary_award_type_multiple_2500;
						this->m_supplementary_open_type = supplementary_open_type_one_time;
					}

				}else if(random >= supplementary_type_big_draw_table[2] && random < supplementary_type_big_draw_table[3]){//4000X
					this->m_supplementary_award_type = supplementary_award_type_multiple_4000;
					this->m_supplementary_open_type = supplementary_open_type_one_time;
				}

 			break;
 	default:
 		break;
 	}

 	/*** Decide Supplementary Timing ***/
 	random = m_mtRandom->getRandomLong(10000);
	double pro = 0;
	if(this->m_sectionMGPlayScore > 0){
	    pro  = (((double)*this->m_sectionMGWinScore / (double)*this->m_sectionMGPlayScore ) * 100) - (*this->m_mainGameProSetting);
	}

	if(this->m_hot_small_section_type == hot_small_section_type_full_frame_award_ahead){
        // 70% Supplementary Timing is Ahead
		if(random < 700){
			this->m_supplementary_timing = supplementary_timing_ahead;
		}else{
			this->m_supplementary_timing = supplementary_timing_normal;
		}

	}else{

		if(pro > 3.0){//Delay
			if(random < supplementary_timing_delay_draw_table[0]){
				this->m_supplementary_timing = supplementary_timing_normal;
			}else if(random >= supplementary_timing_delay_draw_table[0] && random <= supplementary_timing_delay_draw_table[1]){
				this->m_supplementary_timing = supplementary_timing_ahead;
			}else if(random >= supplementary_timing_delay_draw_table[1] && random <= supplementary_timing_delay_draw_table[2]){
				this->m_supplementary_timing = supplementary_timing_delay;
			}
		}else if(pro < -3.0){//Ahead
			if(random < supplementary_timing_ahead_draw_table[0]){
				this->m_supplementary_timing = supplementary_timing_normal;
			}else if(random >= supplementary_timing_ahead_draw_table[0] && random <= supplementary_timing_ahead_draw_table[1]){
				this->m_supplementary_timing = supplementary_timing_ahead;
			}else if(random >= supplementary_timing_ahead_draw_table[1] && random <= supplementary_timing_ahead_draw_table[2]){
				this->m_supplementary_timing = supplementary_timing_delay;
			}
		}else{//Normal
			if(random < supplementary_timing_normal_draw_table[0]){
				this->m_supplementary_timing = supplementary_timing_normal;
			}else if(random >= supplementary_timing_normal_draw_table[0] && random <= supplementary_timing_normal_draw_table[1]){
				this->m_supplementary_timing = supplementary_timing_ahead;
			}else if(random >= supplementary_timing_normal_draw_table[1] && random <= supplementary_timing_normal_draw_table[2]){
				this->m_supplementary_timing = supplementary_timing_delay;
			}
		}

	}

 	/*** Decide Supplementary Target Base ***/
 	switch(this->m_supplementary_type){
 	case supplementary_type_small:
#ifdef TEST_SUPPLEMETARY_CONSECUTIVE
 		this->m_supplementary_target = (SUPPLEMENTARY_AWARD_TYPE_1_MUTLIPLE * ((*this->m_singleLineMaxBetSetting)*8))/1000;
#else
 		this->m_supplementary_target = (SUPPLEMENTARY_AWARD_TYPE_1_MUTLIPLE * ((*this->m_singleLineMaxBetSetting)*8));
#endif
 		break;

 	case supplementary_type_big:
#ifdef TEST_SUPPLEMETARY_CONSECUTIVE
 		this->m_supplementary_target = (SUPPLEMENTARY_AWARD_TYPE_2_MUTLIPLE * ((*this->m_singleLineMaxBetSetting)*8))/1000;
#else
 		this->m_supplementary_target = (SUPPLEMENTARY_AWARD_TYPE_2_MUTLIPLE * ((*this->m_singleLineMaxBetSetting)*8));
#endif
 		break;

 	default:
 		break;
 	}

#if 0
 	switch(this->m_supplementary_award_type){
 	case supplementary_award_type_multiple_50:
 	case supplementary_award_type_multiple_100:
 	case supplementary_award_type_multiple_150:
 	case supplementary_award_type_multiple_250:
 	case supplementary_award_type_multiple_400:
 		this->m_supplementary_target = (SUPPLEMENTARY_AWARD_TYPE_1_MUTLIPLE * ((*this->m_singleLineMaxBetSetting)*8));
 		break;
 	case supplementary_award_type_multiple_800:
 	case supplementary_award_type_multiple_1000:
 	case supplementary_award_type_multiple_2500:
 	case supplementary_award_type_multiple_4000:
 		this->m_supplementary_target = (SUPPLEMENTARY_AWARD_TYPE_2_MUTLIPLE * ((*this->m_singleLineMaxBetSetting)*8));
 		break;

 	default:
 		break;
 	}
#endif

 	/*** Decide Supplementary Target by Supplementary Timing ***/
 	switch(this->m_supplementary_timing){
 	case supplementary_timing_normal:
 		break;
 	case supplementary_timing_ahead:
 		this->m_supplementary_target -= m_mtRandom->getRandomLong(this->m_supplementary_target/2);
 		break;
 	case supplementary_timing_delay:
 		this->m_supplementary_target += m_mtRandom->getRandomLong(this->m_supplementary_target/2);
 		break;

 	default:
 		break;
 	}

 }

 void SupplementaryOpen(unsigned int* item_matrix,unsigned int size){
	 unsigned int random = m_mtRandom->getRandomLong(1000);
	 unsigned int saiyuuki_random = m_mtRandom->getRandomLong(1000);
	 unsigned int saiyuuki_index_1= 0;
	 unsigned int saiyuuki_index_2= 0;
	 unsigned int saiyuuki_index_3= 0;

	 switch(this->m_supplementary_award_type){
		case supplementary_award_type_multiple_50:

			if(random < 350){//35% Change To All Character
				for(unsigned int idx=0; idx<size; idx++){
					item_matrix[idx] = ITEM_BAR_YELLOW + m_mtRandom->getRandomLong(3);
				}
			}else{
				for(unsigned int idx=0; idx<size; idx++){
					item_matrix[idx] = ITEM_ORANGE;
				}
			}

			break;
		case supplementary_award_type_multiple_100:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_MANGO;
			}
			break;
		case supplementary_award_type_multiple_150:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_BELL;
			}
			break;
		case supplementary_award_type_multiple_250:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_WATERMELON;
			}
			break;
		case supplementary_award_type_multiple_400:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_CHERRY;//ITEM_BAR_YELLOW;
			}
			break;
		case supplementary_award_type_multiple_800:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_BAR_YELLOW;//ITEM_CHERRY;
			}
			break;
		case supplementary_award_type_multiple_1000:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_BAR_RED;
			}
			break;
		case supplementary_award_type_multiple_2500:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_BAR_BLUE;
			}
			break;
		case supplementary_award_type_multiple_4000:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_WILD;
			}
			break;

		default:
			break;
	 }

	 if(this->m_supplementary_award_type != supplementary_award_type_multiple_4000){
		 //Insert SAYUUKI
		 if(saiyuuki_random < 200){//Insert 3 SAIYUUKI
			 saiyuuki_index_1 = m_mtRandom->getRandomLong(0,8);
			 //
			 saiyuuki_index_2 = m_mtRandom->getRandomLong(0,8);
			 while(saiyuuki_index_2==saiyuuki_index_1){
				 saiyuuki_index_2 = m_mtRandom->getRandomLong(0,8);
			 }
			 //
			 saiyuuki_index_3 = m_mtRandom->getRandomLong(0,8);
			 while(saiyuuki_index_3==saiyuuki_index_2 || saiyuuki_index_3==saiyuuki_index_1){
				 saiyuuki_index_3 = m_mtRandom->getRandomLong(0,8);
			 }
			 //
			 item_matrix[saiyuuki_index_1] = ITEM_WILD;
			 item_matrix[saiyuuki_index_2] = ITEM_WILD;
			 item_matrix[saiyuuki_index_3] = ITEM_WILD;

		 }else if(saiyuuki_random >= 200 && saiyuuki_random < 400){//Insert 2 SAIYUUKI
			 saiyuuki_index_1 = m_mtRandom->getRandomLong(0,8);
			 //
			 saiyuuki_index_2 = m_mtRandom->getRandomLong(0,8);
			 while(saiyuuki_index_2==saiyuuki_index_1){
				 saiyuuki_index_2 = m_mtRandom->getRandomLong(0,8);
			 }
			 //
			 item_matrix[saiyuuki_index_1] = ITEM_WILD;
			 item_matrix[saiyuuki_index_2] = ITEM_WILD;
		 }else if(saiyuuki_random >= 400 && saiyuuki_random < 700){//Insert 1 SAIYUUKI
			 saiyuuki_index_1 = m_mtRandom->getRandomLong(0,8);
			 //
			 item_matrix[saiyuuki_index_1] = ITEM_WILD;
		 }else{//Don't Insert SAIYUUKI
		 }
	 }

 }

 void SupplementaryConsecutiveOpen(unsigned int awardType,unsigned int* item_matrix,unsigned int size){
	 unsigned int random = m_mtRandom->getRandomLong(1000);
	 unsigned int saiyuuki_random = m_mtRandom->getRandomLong(1000);
	 unsigned int saiyuuki_index_1= 0;
	 unsigned int saiyuuki_index_2= 0;
	 unsigned int saiyuuki_index_3= 0;

	 switch(awardType){
		case supplementary_award_type_multiple_50:

			if(random < 350){//35% Change To All Character
				for(unsigned int idx=0; idx<size; idx++){
					item_matrix[idx] = ITEM_BAR_YELLOW + m_mtRandom->getRandomLong(3);
				}
			}else{
				for(unsigned int idx=0; idx<size; idx++){
					item_matrix[idx] = ITEM_ORANGE;
				}
			}

			break;
		case supplementary_award_type_multiple_100:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_MANGO;
			}
			break;
		case supplementary_award_type_multiple_150:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_BELL;
			}
			break;
		case supplementary_award_type_multiple_250:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_WATERMELON;
			}
			break;
		case supplementary_award_type_multiple_400:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_CHERRY;//ITEM_BAR_YELLOW;
			}
			break;
		case supplementary_award_type_multiple_800:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_BAR_YELLOW;//ITEM_CHERRY;
			}
			break;
		case supplementary_award_type_multiple_1000:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_BAR_RED;
			}
			break;
		case supplementary_award_type_multiple_2500:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_BAR_BLUE;
			}
			break;
		case supplementary_award_type_multiple_4000:
			for(unsigned int idx=0; idx<size; idx++){
				item_matrix[idx] = ITEM_WILD;
			}
			break;

		default:
			break;
	 }

	 if(this->m_supplementary_award_type != supplementary_award_type_multiple_4000){
		 //Insert SAYUUKI
		 if(saiyuuki_random < 200){//Insert 3 SAIYUUKI
			 saiyuuki_index_1 = m_mtRandom->getRandomLong(0,8);
			 //
			 saiyuuki_index_2 = m_mtRandom->getRandomLong(0,8);
			 while(saiyuuki_index_2==saiyuuki_index_1){
				 saiyuuki_index_2 = m_mtRandom->getRandomLong(0,8);
			 }
			 //
			 saiyuuki_index_3 = m_mtRandom->getRandomLong(0,8);
			 while(saiyuuki_index_3==saiyuuki_index_2 || saiyuuki_index_3==saiyuuki_index_1){
				 saiyuuki_index_3 = m_mtRandom->getRandomLong(0,8);
			 }
			 //
			 item_matrix[saiyuuki_index_1] = ITEM_WILD;
			 item_matrix[saiyuuki_index_2] = ITEM_WILD;
			 item_matrix[saiyuuki_index_3] = ITEM_WILD;

		 }else if(saiyuuki_random >= 200 && saiyuuki_random < 400){//Insert 2 SAIYUUKI
			 saiyuuki_index_1 = m_mtRandom->getRandomLong(0,8);
			 //
			 saiyuuki_index_2 = m_mtRandom->getRandomLong(0,8);
			 while(saiyuuki_index_2==saiyuuki_index_1){
				 saiyuuki_index_2 = m_mtRandom->getRandomLong(0,8);
			 }
			 //
			 item_matrix[saiyuuki_index_1] = ITEM_WILD;
			 item_matrix[saiyuuki_index_2] = ITEM_WILD;
		 }else if(saiyuuki_random >= 400 && saiyuuki_random < 700){//Insert 1 SAIYUUKI
			 saiyuuki_index_1 = m_mtRandom->getRandomLong(0,8);
			 //
			 item_matrix[saiyuuki_index_1] = ITEM_WILD;
		 }else{//Don't Insert SAIYUUKI
		 }
	 }
 }

 void ResetSPSupplementary(void){
	 this->m_sp_supplementary_flag = sp_supplementary_flag_not_yet;
	 this->m_sp_supplementary_target_score = 0;
	 this->m_sp_supplementary_save_score = 0;
	 this->m_sp_supplementary_probability_down_open_times = 0;
 }

 void DecideSPSupplementary(void){
	 //this->m_sp_supplementary_target_score = this->m_mtRandom->getRandomLong(100000,300000);
#ifdef DEBUG_SPECIALGAME_LONGRUN_TEST
	 this->m_sp_supplementary_target_score = this->m_mtRandom->getRandomLong(125,300) * (*this->m_singleLineMaxBetSetting);
#else
	 this->m_sp_supplementary_target_score = this->m_mtRandom->getRandomLong(1250,3000) * (*this->m_singleLineMaxBetSetting) * 8;
#endif
	 this->m_sp_supplementary_save_score = 0;
 }

 void SPSupplementaryOpen(unsigned int* item_matrix,unsigned int size){
	 unsigned int saiyuuki_times = 3;
	 unsigned int tmp_slot_index[9] = {0,1,2,3,4,5,6,7,8};
	 unsigned int tmp;
	 unsigned int tmp_index_1;
	 unsigned int tmp_index_2;
	 unsigned int item_1;
	 unsigned int item_2;
	 unsigned int item_3;

	 //Random the index array
	 for(unsigned int idx=0; idx<300; idx++){
		 tmp_index_1 = m_mtRandom->getRandomLong(9);
		 tmp_index_2 = m_mtRandom->getRandomLong(9);

		 tmp                         = tmp_slot_index[tmp_index_1];
		 tmp_slot_index[tmp_index_1] = tmp_slot_index[tmp_index_2];
		 tmp_slot_index[tmp_index_2] = tmp;
	 }

	 //Decide Item 1 Item 2 Item 3
	 item_1 = this->m_mtRandom->getRandomLong(1,8);

	 item_2 = this->m_mtRandom->getRandomLong(1,8);
	 while(item_1 == item_2){
		 item_2 = this->m_mtRandom->getRandomLong(1,8);
	 }

	 item_3 = this->m_mtRandom->getRandomLong(1,8);
	 while(item_3 == item_1 || item_3 == item_2){
		 item_3 = this->m_mtRandom->getRandomLong(1,8);
	 }

	 //Write item to item_matrix
	 //SAIYUUKI
	 for(unsigned int idx=0; idx<saiyuuki_times; idx++){
		 item_matrix[tmp_slot_index[idx]] = ITEM_WILD;
	 }

	 item_matrix[tmp_slot_index[3]] = item_1;
	 item_matrix[tmp_slot_index[4]] = item_2;
	 item_matrix[tmp_slot_index[5]] = item_3;

	 for(unsigned int idx=6; idx<9; idx++){
		 item_matrix[tmp_slot_index[idx]] = this->m_mtRandom->getRandomLong(1,8);
	 }

 }

 /**
  * @brief Check All Draw Count.
  */
 void CheckAllDrawCount(void){

	 printf("### Slot 1 Draw Check ### \n");
	 //Slot 1 Draw Check
	 for(unsigned i=0; i<sizeof(MainGameSlot1ProbabilityMatrix)/sizeof(MainGameSlot1ProbabilityMatrix[0]); i++){
		 for(unsigned int j=0; j<sizeof(MainGameSlot1ProbabilityMatrix[0])/sizeof(MainGameSlot1ProbabilityMatrix[0][0]); j++){
			 for(unsigned int k=0,draw_counts=0; k<sizeof(MainGameSlot1ProbabilityMatrix[0][0])/sizeof(MainGameSlot1ProbabilityMatrix[0][0][0]); k++){
				 draw_counts += MainGameSlot1ProbabilityMatrix[i][j][k];
				 if( k== (sizeof(MainGameSlot1ProbabilityMatrix[0][0])/sizeof(MainGameSlot1ProbabilityMatrix[0][0][0]))-1){
					 if(draw_counts != 10000){
						 printf("I:%d,J:%d,Total Draw Count:%d \n",i,j,draw_counts);
					 }
				 }
			 }
		 }
	 }

	 printf("### Slot 5 Draw Check ### \n");
	 //Slot 5 Draw Check
	 for(unsigned i=0; i<sizeof(MainGameSlot5ProbabilityMatrix)/sizeof(MainGameSlot5ProbabilityMatrix[0]); i++){
		 for(unsigned int j=0; j<sizeof(MainGameSlot5ProbabilityMatrix[0])/sizeof(MainGameSlot5ProbabilityMatrix[0][0]); j++){
			 for(unsigned int k=0,draw_counts=0; k<sizeof(MainGameSlot5ProbabilityMatrix[0][0])/sizeof(MainGameSlot5ProbabilityMatrix[0][0][0]); k++){
				 draw_counts += MainGameSlot5ProbabilityMatrix[i][j][k];
				 if( k== (sizeof(MainGameSlot5ProbabilityMatrix[0][0])/sizeof(MainGameSlot5ProbabilityMatrix[0][0][0]))-1){
					 if(draw_counts != 10000){
						 printf("I:%d,J:%d,Total Draw Count:%d \n",i,j,draw_counts);
					 }
				 }
			 }
		 }
	 }

	 printf("### Slot 7 Draw Check ### \n");
	 //Slot 7 Draw Check
	 for(unsigned i=0; i<sizeof(MainGameSlot7ProbabilityMatrix)/sizeof(MainGameSlot7ProbabilityMatrix[0]); i++){
		 for(unsigned int j=0; j<sizeof(MainGameSlot7ProbabilityMatrix[0])/sizeof(MainGameSlot7ProbabilityMatrix[0][0]); j++){
			 for(unsigned int k=0,draw_counts=0; k<sizeof(MainGameSlot7ProbabilityMatrix[0][0])/sizeof(MainGameSlot7ProbabilityMatrix[0][0][0]); k++){
				 draw_counts += MainGameSlot7ProbabilityMatrix[i][j][k];
				 if( k== (sizeof(MainGameSlot7ProbabilityMatrix[0][0])/sizeof(MainGameSlot7ProbabilityMatrix[0][0][0]))-1){
					 if(draw_counts != 10000){
						 printf("I:%d,J:%d,Total Draw Count:%d \n",i,j,draw_counts);
					 }
				 }
			 }
		 }
	 }

	 //MainGameLevelMatrix[3][26][15]
	 printf("### Game Level Draw Check ### \n");
	 for(unsigned i=0; i<sizeof(MainGameLevelMatrix)/sizeof(MainGameLevelMatrix[0]); i++){
		 for(unsigned int j=0; j<sizeof(MainGameLevelMatrix[0])/sizeof(MainGameLevelMatrix[0][0]); j++){
			 for(unsigned int k=sizeof(MainGameLevelMatrix[0][0])/sizeof(MainGameLevelMatrix[0][0][0])-1; k<sizeof(MainGameLevelMatrix[0][0])/sizeof(MainGameLevelMatrix[0][0][0]); k++){
				 if( k== (sizeof(MainGameLevelMatrix[0][0])/sizeof(MainGameLevelMatrix[0][0][0]))-1){
					 if(MainGameLevelMatrix[i][j][k] != 1000){
						 printf("I:%d,J:%d,Total Draw Count:%lu \n",i,j,MainGameLevelMatrix[i][j][k]);
					 }
				 }
			 }
		 }
	 }

	 printf("### MainGameSlot1ProbabilityDownMatrix ### \n");
	 for(unsigned int i=0; i<sizeof(MainGameSlot1ProbabilityDownMatrix)/sizeof(MainGameSlot1ProbabilityDownMatrix[0]); i++){
		 for(unsigned int j=0,draw_counts=0; j<sizeof(MainGameSlot1ProbabilityDownMatrix[0])/sizeof(MainGameSlot1ProbabilityDownMatrix[0][0]); j++){
			 draw_counts += MainGameSlot1ProbabilityDownMatrix[i][j];
			 if( j == sizeof(MainGameSlot1ProbabilityDownMatrix[0])/sizeof(MainGameSlot1ProbabilityDownMatrix[0][0]) -1){
				 if(draw_counts != 10000){
					 printf("I:%d,J:%d,Total Draw Count:%d \n",i,j,draw_counts);
				 }
			 }
		 }
	 }

	 printf("### MainGameSlot5ProbabilityDownMatrix ### \n");
	 for(unsigned int i=0; i<sizeof(MainGameSlot5ProbabilityDownMatrix)/sizeof(MainGameSlot5ProbabilityDownMatrix[0]); i++){
		 for(unsigned int j=0,draw_counts=0; j<sizeof(MainGameSlot5ProbabilityDownMatrix[0])/sizeof(MainGameSlot5ProbabilityDownMatrix[0][0]); j++){
			 draw_counts += MainGameSlot5ProbabilityDownMatrix[i][j];
			 if( j == sizeof(MainGameSlot5ProbabilityDownMatrix[0])/sizeof(MainGameSlot5ProbabilityDownMatrix[0][0]) -1){
				 if(draw_counts != 10000){
					 printf("I:%d,J:%d,Total Draw Count:%d \n",i,j,draw_counts);
				 }
			 }
		 }
	 }

	 printf("### MainGameSlot7ProbabilityDownMatrix ### \n");
	 for(unsigned int i=0; i<sizeof(MainGameSlot7ProbabilityDownMatrix)/sizeof(MainGameSlot7ProbabilityDownMatrix[0]); i++){
		 for(unsigned int j=0,draw_counts=0; j<sizeof(MainGameSlot7ProbabilityDownMatrix[0])/sizeof(MainGameSlot7ProbabilityDownMatrix[0][0]); j++){
			 draw_counts += MainGameSlot7ProbabilityDownMatrix[i][j];
			 if( j == sizeof(MainGameSlot7ProbabilityDownMatrix[0])/sizeof(MainGameSlot7ProbabilityDownMatrix[0][0]) -1){
				 if(draw_counts != 10000){
					 printf("I:%d,J:%d,Total Draw Count:%d \n",i,j,draw_counts);
				 }
			 }
		 }
	 }

	 printf("### MainGameSlot1ProbabilityUpMatrix ### \n");
	 for(unsigned int i=0; i<sizeof(MainGameSlot1ProbabilityUpMatrix)/sizeof(MainGameSlot1ProbabilityUpMatrix[0]); i++){
		 for(unsigned int j=0,draw_counts=0; j<sizeof(MainGameSlot1ProbabilityUpMatrix[0])/sizeof(MainGameSlot1ProbabilityUpMatrix[0][0]); j++){
			 draw_counts += MainGameSlot1ProbabilityUpMatrix[i][j];
			 if( j == sizeof(MainGameSlot1ProbabilityUpMatrix[0])/sizeof(MainGameSlot1ProbabilityUpMatrix[0][0]) -1){
				 if(draw_counts != 10000){
					 printf("I:%d,J:%d,Total Draw Count:%d \n",i,j,draw_counts);
				 }
			 }
		 }
	 }

	 printf("### MainGameSlot5ProbabilityUpMatrix ### \n");
	 for(unsigned int i=0; i<sizeof(MainGameSlot5ProbabilityUpMatrix)/sizeof(MainGameSlot5ProbabilityUpMatrix[0]); i++){
		 for(unsigned int j=0,draw_counts=0; j<sizeof(MainGameSlot5ProbabilityUpMatrix[0])/sizeof(MainGameSlot5ProbabilityUpMatrix[0][0]); j++){
			 draw_counts += MainGameSlot5ProbabilityUpMatrix[i][j];
			 if( j == sizeof(MainGameSlot5ProbabilityUpMatrix[0])/sizeof(MainGameSlot5ProbabilityUpMatrix[0][0]) -1){
				 if(draw_counts != 10000){
					 printf("I:%d,J:%d,Total Draw Count:%d \n",i,j,draw_counts);
				 }
			 }
		 }
	 }

	 printf("### MainGameSlot7ProbabilityUpMatrix ### \n");
	 for(unsigned int i=0; i<sizeof(MainGameSlot7ProbabilityUpMatrix)/sizeof(MainGameSlot7ProbabilityUpMatrix[0]); i++){
		 for(unsigned int j=0,draw_counts=0; j<sizeof(MainGameSlot7ProbabilityUpMatrix[0])/sizeof(MainGameSlot7ProbabilityUpMatrix[0][0]); j++){
			 draw_counts += MainGameSlot7ProbabilityUpMatrix[i][j];
			 if( j == sizeof(MainGameSlot7ProbabilityUpMatrix[0])/sizeof(MainGameSlot7ProbabilityUpMatrix[0][0]) -1){
				 if(draw_counts != 10000){
					 printf("I:%d,J:%d,Total Draw Count:%d \n",i,j,draw_counts);
				 }
			 }
		 }
	 }

	 printf("### SpecialGameAwardDrawTable ### \n");
	 for(unsigned int i=0; i<sizeof(sp_award_draw_table)/sizeof(sp_award_draw_table[0]); i++){
		 for(unsigned int j=0; j<sizeof(sp_award_draw_table[0])/sizeof(sp_award_draw_table[0][0]); j++){
			 if( j == sizeof(sp_award_draw_table[0])/sizeof(sp_award_draw_table[0][0]) -1){
				 if(sp_award_draw_table[i][j] != 10000){
					 printf("I:%d,J:%d,Total Draw Count:%d \n",i,j,sp_award_draw_table[i][j]);
				 }
			 }
		 }
	 }
 }

 /**
  * @brief Called By Connect Interrupt Function.
  * @param nextStatusFromMaster Next status from master
  */
 void ConnectInterrupt(unsigned int nextStatusFromMaster){
	   m_nextStatusFromMaster = nextStatusFromMaster;
	   m_receiveConnectInterruptFlag = true;
	   /*
	   //For Record Up&Down Times
	   if(m_nextStatusFromMaster == status_up){
		   m_totalUpTimes++;
		   m_totalUpGameTimes = 0;
	   }else if(m_nextStatusFromMaster == status_down){
		   m_totalDownTimes++;
		   m_totalDownGameTimes = 0;
	   }
	   */
 }

 /**
  * @brief Called By Connect Interrupt Function.
  * @param nextStatusFromMaster Next status from master
  * @param _mainProSetFromMaster Next main game probability setting from master
  * @param _glFromMaster Next game level from master
  */
 void ConnectInterrupt(unsigned int nextStatusFromMaster,unsigned char _mainProSetFromMaster,unsigned char _glFromMaster){
	   m_nextStatusFromMaster   = nextStatusFromMaster;
	   *this->m_mainGameProSettingConnect = m_mainGameProSettingConnectMappingArray[_mainProSetFromMaster];
       *this->m_GameLevelSettingConnect  = _glFromMaster;
	   m_receiveConnectInterruptFlag = true;

	   /*
	   //For Record Up&Down Times
	   if(m_nextStatusFromMaster == status_up){
		   m_totalUpTimes++;
		   m_totalUpGameTimes = 0;
	   }else if(m_nextStatusFromMaster == status_down){
		   m_totalDownTimes++;
		   m_totalDownGameTimes = 0;
	   }
	   */
 }

 /**
  * @brief Get Index By Main Game Probability(Connect).
  * @param mainpro Main Game Probability(Connect)
  */
 unsigned int getArrayIndexByMainGameProbabilityConnect(unsigned int mainpro){
	 unsigned int ret=0;

	 for(unsigned int i=0; i<sizeof(m_mainGameProSettingConnectMappingArray)/sizeof(m_mainGameProSettingConnectMappingArray[0]); i++){
         if(mainpro == m_mainGameProSettingConnectMappingArray[i]){
        	ret = i;
        	break;
         }
     }

	 return ret;
 }

 /**
  * @brief Get R Value.
  * @retval R value
  */
 long getRValue(){
	 return (  *m_sectionMGWinScore - (unsigned long)((float)*m_sectionMGPlayScore * ((float)*m_mainGameProSetting /(float)100))  );
 }

 /**
  * @brief Get Connect Setting.
  * @retval Connect Setting
  */
 unsigned int getConnectSetting(){
     return (*this->m_connectSetting);
 }

 /**
  * @brief Record Probability Status Run Times.
  */
 void RecordProbabilityStatusRunTimes(void){
	 switch(this->m_probabilityControlStatus){

	 case status_normal:
		 this->m_totalNormalTimes++;
		 break;
	 case status_connect:

		 break;
	 case status_check0_down:
		 //Total
		 this->m_totalCheck0DownTimes++;
		 //This Turn Run Times
		 this->m_thisTurnCheck0DownTimes++;
		 if(this->m_thisTurnCheck0DownTimes > this->m_maxCheck0DownTimes){
			 this->m_maxCheck0DownTimes = this->m_thisTurnCheck0DownTimes;
		 }
		 break;
	 case status_check1_down:
		 //Total
		 this->m_totalCheck1DownTimes++;
		 //This Turn Run Times
		 this->m_thisTurnCheck1DownTimes++;
		 if(this->m_thisTurnCheck1DownTimes > this->m_maxCheck1DownTimes){
			 this->m_maxCheck1DownTimes = this->m_thisTurnCheck1DownTimes;
		 }
		 break;
	 case status_check2_up:
		 //Total
		 this->m_totalCheck2UpTimes++;
		 //This Turn Run Times
		 this->m_thisTurnCheck2UpTimes++;
		 if(this->m_thisTurnCheck2UpTimes > this->m_maxCheck2UpTimes){
			 this->m_maxCheck2UpTimes = this->m_thisTurnCheck2UpTimes;
		 }
		 break;
	 case status_check2_down:
		 //Total
		 this->m_totalCheck2DownTimes++;
		 //This Turn Run Times
		 this->m_thisTurnCheck2DownTimes++;
		 if(this->m_thisTurnCheck2DownTimes > this->m_maxCheck2DownTimes){
			 this->m_maxCheck2DownTimes = this->m_thisTurnCheck2DownTimes;
		 }
		 break;

	 default:
		 break;
	 }
 }

 /**
  * @brief Reset Random Multiple.
  */
 void ResetRandomMutiple(void){
	this->m_getRandomMultipleFlag = false;
	this->m_randomMultiple = random_multiple_none;
 }

 /**
  * @brief Get Random Multiple.
  */
 void GetRandomMultiple(void){
	 unsigned long random = m_mtRandom->getRandomLong(1000);

	 if(random < 540){//x1
		 this->m_randomMultiple = random_multiple_x1;
		 m_randomMultiple_x1_times++;
	 }else if(random >= 540 && random < 960){//x2
		 this->m_randomMultiple = random_multiple_x2;
		 m_randomMultiple_x2_times++;
	 }else{//x3
		 this->m_randomMultiple = random_multiple_x3;
		 m_randomMultiple_x3_times++;
	 }

	 this->m_getRandomMultipleFlag = true;
 }

#ifdef EXPORT_PROBABILITY_CSV_FILE
 /**
  * @brief Create probability CSV file.
  */
 void CreateProbabilityCSVFile(void){

     struct stat stat_buf;
     if(stat(__PROBABILITY_CSV_FILE__,&stat_buf)==-1 && errno == ENOENT){//File don't exist
    	 FILE* csv = fopen(__PROBABILITY_CSV_FILE__,"wb");

    	 if(csv == NULL){
    		 printf("!!! Create Probability CSV File Failure !!! \n");
    		 return;
    	 }

    	 fprintf(csv,"MainGameTotalPlayScore,MainGameTotalWinScore,MainGameMach%%,MainGameTotalPlayTimes,MainGameTotalWinTimes,WinRate%% \n");

    	 fclose(csv);
     }
 }

 /**
  * @brief Update probability CSV file.
  */
 void UpdateProbabilityCSVFile(void){
	 FILE* csv = fopen(__PROBABILITY_CSV_FILE__,"a+");

	 if(csv == NULL){
		 printf("!!! Open Probability CSV File Failure !!! \n");
		 return;
	 }

	 fprintf(csv,"%ld,%ld,%.2f%%,%ld,%ld,%.2f%% \n",
			 this->m_totalRecord->m_totalMainGamePlayScores-this->m_csvRecord.m_totalMainGamePlayScores,
			 this->m_totalRecord->m_totalMainGameWinScores-this->m_csvRecord.m_totalMainGameWinScores,
			 (double)(this->m_totalRecord->m_totalMainGameWinScores-this->m_csvRecord.m_totalMainGameWinScores)/(this->m_totalRecord->m_totalMainGamePlayScores-this->m_csvRecord.m_totalMainGamePlayScores)*100,
			 this->m_totalRecord->m_totalMainGamePlayTimes-this->m_csvRecord.m_totalMainGamePlayTimes,
			 this->m_totalRecord->m_totalMainGameWinTimes-this->m_csvRecord.m_totalMainGameWinTimes,
			 (double)(this->m_totalRecord->m_totalMainGameWinTimes-this->m_csvRecord.m_totalMainGameWinTimes)/(this->m_totalRecord->m_totalMainGamePlayTimes-this->m_csvRecord.m_totalMainGamePlayTimes)*100
	 );


	 fclose(csv);
 }

 /**
  * @brief Run Export Probability CSV File.
  */
 void RunExportProbabilityCSVFile(void){
     if(this->m_totalRecord->m_totalMainGamePlayScores - this->m_csvRecord.m_totalMainGamePlayScores >=  CSV_PROBABILITY_SCORE){
    	 this->UpdateProbabilityCSVFile();
    	 this->m_csvRecord = *this->m_totalRecord;
     }
 }

 /**
  * @brief Create Probability Status CSV file.
  */
 void CreateProbabilityStatusCSVFile(void){

     struct stat stat_buf;
     if(stat(__PROBABILITY_STATUS_CSV_FILE__,&stat_buf)==-1 && errno == ENOENT){//File don't exist
    	 FILE* csv = fopen(__PROBABILITY_STATUS_CSV_FILE__,"wb");

    	 if(csv == NULL){
    		 printf("!!! Create Probability Status CSV File Failure !!! \n");
    		 return;
    	 }

    	 fprintf(csv,"StatusChanged,PresentStatus,PreviousStatus,TotalIn,TotalOut,+/-(Coin),MainGameSectionPlayScores,MainGameSectionWinScores,SectionMach%%,R-Value,Check1Level,Level1StartRValue,Level1EndRValue,StatusCheckRandom,SupplementaryTotalWin,SectionMach(-S)%%,SupplementaryOpenBasePro,MaxSaveMinusTarget,"
    			 "Check2RandomRate,Check0DownRunTimes,Check1DownRunTimes,Check2DownRunTimes,Check2UpRunTimes,Check0DownMaxTimes,Check1DownMaxTimes,Check2DownMaxTimes,Check2UpMaxTimes,C2Times,C4Times,C8Times \n");

    	 fclose(csv);
     }
 }

 /**
  * @brief Update Probability Status CSV File.
  */
 void UpdateProbabilityStatusCSVFile(void){

	 const char statusChanged = '*';
	 const char* pro_str[5] = {
		"normal",
		"check0_down",
		"check1_down",
		"check2_down",
		"check2_up"
	 };
	 char check1_level = 0x00;
	 long check1_level_start_R_value = 0;
	 long check1_level_end_R_value = 0;
	 this->getCheck1Level(&check1_level);

	 switch(check1_level){

	 case 'A':
		 check1_level_start_R_value = this->getCheck1ASectionCheckStartRValue(*this->m_sectionMGPlayScore);
		 check1_level_end_R_value = this->getCheck1ASectionCheckEndRValue(*this->m_sectionMGPlayScore);
		 break;

	 case 'B':
		 check1_level_start_R_value = this->getCheck1BSectionCheckStartRValue(*this->m_sectionMGPlayScore);
		 check1_level_end_R_value = this->getCheck1BSectionCheckEndRValue(*this->m_sectionMGPlayScore);
		 break;

	 case 'C':
		 check1_level_start_R_value = this->getCheck1CSectionCheckStartRValue(*this->m_sectionMGPlayScore);
		 check1_level_end_R_value = this->getCheck1CSectionCheckEndRValue(*this->m_sectionMGPlayScore);
		 break;
	 default:
		 break;
	 }

	 double base_pro=0;
	 this->getOpenSupplementaryProbability(&base_pro);

	 FILE* csv = fopen(__PROBABILITY_STATUS_CSV_FILE__,"a+");

	 if(csv == NULL){
		 printf("!!! Open Probability CSV File Failure !!! \n");
		 return;
	 }

	 fprintf(csv,"%c,%s,%s,%ld,%ld,%d,%ld,%ld,%.2f%%,%ld,%c,%ld,%ld,%ld,%ld,%.2f%%,%.2f,%.2f,%ld,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d \n",
			 statusChanged,
			 pro_str[this->m_probabilityControlStatus],
			 pro_str[this->m_previousProbabilityControlStatus],
			 this->m_totalRecord->m_keyIn+this->m_totalRecord->m_coinIn,
			 this->m_totalRecord->m_keyOut+this->m_totalRecord->m_coinOut,
			 //((this->m_totalRecord->m_keyIn+this->m_totalRecord->m_coinIn)-(this->m_totalRecord->m_keyOut+this->m_totalRecord->m_coinOut))/(*this->m_coinValueSetting),
			 (((signed)this->m_totalRecord->m_coinOut+(signed)this->m_totalRecord->m_keyOut) - ((signed)this->m_totalRecord->m_coinIn+(signed)this->m_totalRecord->m_keyIn))/(signed)(*this->m_coinValueSetting),
			 this->m_sectionRecord->m_totalMainGamePlayScores,
			 this->m_sectionRecord->m_totalMainGameWinScores,
			 (double)this->m_sectionRecord->m_totalMainGameWinScores/m_sectionRecord->m_totalMainGamePlayScores * 100,
			 this->getRValue(),
			 check1_level,
			 check1_level_start_R_value,
			 check1_level_end_R_value,
			 this->m_statusNormalCheckRandom,
			 this->m_supplementary_total_win,
			 ((double)this->m_sectionRecord->m_totalMainGameWinScores-(double)this->m_supplementary_total_win)/m_sectionRecord->m_totalMainGamePlayScores * 100,
			 base_pro,
			 this->m_supplementary_max_save_minus_target,
			 this->m_randomCheck2Rate,
			 this->m_thisTurnCheck0DownTimes,
			 this->m_thisTurnCheck1DownTimes,
			 this->m_thisTurnCheck2DownTimes,
			 this->m_thisTurnCheck2UpTimes,
			 this->m_maxCheck0DownTimes,
			 this->m_maxCheck1DownTimes,
			 this->m_maxCheck2DownTimes,
			 this->m_maxCheck2UpTimes,
			 this->m_supplementary_consecutiveness_2_times,
			 this->m_supplementary_consecutiveness_4_times,
			 this->m_supplementary_consecutiveness_8_times
	 );

	 fclose(csv);
 }

 /**
  * @brief Run Export Probability Status CSV File.
  */
 void RunExportProbabilityStatusCSVFile(void){
	 if(m_previousProbabilityControlStatus != m_probabilityControlStatus)
	 {
		 this->UpdateProbabilityStatusCSVFile();
		 this->m_thisTurnCheck0DownTimes=0;
		 this->m_thisTurnCheck1DownTimes=0;
		 this->m_thisTurnCheck2DownTimes=0;
		 this->m_thisTurnCheck2UpTimes=0;
		 m_previousProbabilityControlStatus = m_probabilityControlStatus;
	 }
 }

 /**
  * @brief Update Probability Status CSV File Every Check.
  */
 void UpdateProbabilityStatusCSVFileEveryCheck(void){

	 const char statusChanged = '#';
	 const char* pro_str[5] = {
		"normal",
		"check0_down",
		"check1_down",
		"check2_down",
		"check2_up"
	 };
	 char check1_level = 0x00;
	 long check1_level_start_R_value = 0;
	 long check1_level_end_R_value = 0;
	 this->getCheck1Level(&check1_level);

	 switch(check1_level){

	 case 'A':
		 check1_level_start_R_value = this->getCheck1ASectionCheckStartRValue(*this->m_sectionMGPlayScore);
		 check1_level_end_R_value = this->getCheck1ASectionCheckEndRValue(*this->m_sectionMGPlayScore);
		 break;

	 case 'B':
		 check1_level_start_R_value = this->getCheck1BSectionCheckStartRValue(*this->m_sectionMGPlayScore);
		 check1_level_end_R_value = this->getCheck1BSectionCheckEndRValue(*this->m_sectionMGPlayScore);
		 break;

	 case 'C':
		 check1_level_start_R_value = this->getCheck1CSectionCheckStartRValue(*this->m_sectionMGPlayScore);
		 check1_level_end_R_value = this->getCheck1CSectionCheckEndRValue(*this->m_sectionMGPlayScore);
		 break;
	 default:
		 break;
	 }

	 double base_pro=0;
	 this->getOpenSupplementaryProbability(&base_pro);

	 FILE* csv = fopen(__PROBABILITY_STATUS_CSV_FILE__,"a+");

	 if(csv == NULL){
		 printf("!!! Open Probability CSV File Failure !!! \n");
		 return;
	 }

	 fprintf(csv,"%c,%s,%s,%ld,%ld,%d,%ld,%ld,%.2f%%,%ld,%c,%ld,%ld,%ld,%ld,%.2f%%,%.2f,%.2f,%ld,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d \n",
			 statusChanged,
			 pro_str[this->m_probabilityControlStatus],
			 pro_str[this->m_previousProbabilityControlStatus],
			 this->m_totalRecord->m_keyIn+this->m_totalRecord->m_coinIn,
			 this->m_totalRecord->m_keyOut+this->m_totalRecord->m_coinOut,
			 //((this->m_totalRecord->m_keyIn+this->m_totalRecord->m_coinIn)-(this->m_totalRecord->m_keyOut+this->m_totalRecord->m_coinOut))/(*this->m_coinValueSetting),
			 (((signed)this->m_totalRecord->m_coinOut+(signed)this->m_totalRecord->m_keyOut) - ((signed)this->m_totalRecord->m_coinIn+(signed)this->m_totalRecord->m_keyIn))/(signed)(*this->m_coinValueSetting),
			 this->m_sectionRecord->m_totalMainGamePlayScores,
			 this->m_sectionRecord->m_totalMainGameWinScores,
			 (double)this->m_sectionRecord->m_totalMainGameWinScores/m_sectionRecord->m_totalMainGamePlayScores * 100,
			 this->getRValue(),
			 check1_level,
			 check1_level_start_R_value,
			 check1_level_end_R_value,
			 this->m_statusNormalCheckRandom,
			 this->m_supplementary_total_win,
			 ((double)this->m_sectionRecord->m_totalMainGameWinScores-(double)this->m_supplementary_total_win)/m_sectionRecord->m_totalMainGamePlayScores * 100,
			 base_pro,
			 this->m_supplementary_max_save_minus_target,
			 this->m_randomCheck2Rate,
			 this->m_thisTurnCheck0DownTimes,
			 this->m_thisTurnCheck1DownTimes,
			 this->m_thisTurnCheck2DownTimes,
			 this->m_thisTurnCheck2UpTimes,
			 this->m_maxCheck0DownTimes,
			 this->m_maxCheck1DownTimes,
			 this->m_maxCheck2DownTimes,
			 this->m_maxCheck2UpTimes,
			 this->m_supplementary_consecutiveness_2_times,
			 this->m_supplementary_consecutiveness_4_times,
			 this->m_supplementary_consecutiveness_8_times
	 );

	 fclose(csv);
 }

 /**
  * @brief Run Export Probability Status CSV File Every Check.
  */
 void RunExportProbabilityStatusCSVFileEveryCheck(void){
	 if(m_previousProbabilityControlStatus == m_probabilityControlStatus)
	 {
		 this->UpdateProbabilityStatusCSVFileEveryCheck();
	 }
 }
#endif

}MAINGAMEPROBABILITYCONTROL;

/**
 * @brief Double Game Probability Control.
 */
typedef struct DoubleGameProbabilityControl{
	unsigned long* m_double_game_total_play_scores;/**< Double game total play */
	unsigned long* m_double_game_total_win_scores;/**< Double game total win */
	unsigned long* m_double_game_section_play_scores;/**< Double game section play */
	unsigned long* m_double_game_section_win_scores;/**< Double game section win */
	unsigned long* m_double_game_section_play_times;/**< Double game section play times */
	unsigned long* m_double_game_section_win_times;/**< Double game section win times */
	double* m_double_game_probability_setting;/**< Double game probability setting */
	unsigned long m_doubleGameAwardType;/**< Double game award type */
	unsigned long m_doubleGameOpenType;/**< Double game open type */
	unsigned long m_doubleGameResultType;/**< Double game result type */
	unsigned long m_totalDrawNormalTimes;/**< Total Draw Normal Times */
	unsigned long m_totalDrawDownLevel1Times;/**< Total Draw Down Level 1 Times */
	unsigned long m_totalDrawDownLevel2Times;/**< Total Draw Down Level 2 Times */
	unsigned long m_totalDrawDownLevel3Times;/**< Total Draw Down Level 3 Times */
	unsigned long m_totalDrawUpLevel1Times;/**< Total Draw Up Level 1 Times */
	unsigned long m_totalDrawUpLevel2Times;/**< Total Draw Up Level 2 Times */
	unsigned long m_totalDrawUpLevel3Times;/**< Total Draw Up Level 3 Times */
	unsigned long m_total70PercentageDownTimes;/**< Total 70% Percentage Down Times */

	/**
	 * @brief Constructor.
	 */
	DoubleGameProbabilityControl(
			unsigned long* _double_game_total_play_scores,
			unsigned long* _double_game_total_win_scores,
			unsigned long* _double_game_section_play_scores,
			unsigned long* _double_game_section_win_scores,
			unsigned long* _double_game_section_play_times,
			unsigned long* _double_game_section_win_times,
			double* _double_game_probability_setting)
	{
		m_double_game_total_play_scores   = _double_game_total_play_scores;
		m_double_game_total_win_scores    = _double_game_total_win_scores;
		m_double_game_section_play_scores = _double_game_section_play_scores;
		m_double_game_section_win_scores  = _double_game_section_win_scores;
		m_double_game_section_play_times  = _double_game_section_play_times;
		m_double_game_section_win_times   = _double_game_section_win_times;
		m_double_game_probability_setting = _double_game_probability_setting;

		m_totalDrawNormalTimes       = 0;
		m_totalDrawDownLevel1Times   = 0;
		m_totalDrawDownLevel2Times   = 0;
		m_totalDrawDownLevel3Times   = 0;
		m_totalDrawUpLevel1Times     = 0;
		m_totalDrawUpLevel2Times     = 0;
		m_totalDrawUpLevel3Times     = 0;
		m_total70PercentageDownTimes = 0;
	}

	/**
	 * @brief Get Award Type.
	 */
	unsigned int getAwardType(unsigned long thisTurnDoubleBet){

		// Compute now double game probability
		double nowPro = (double)(*m_double_game_section_win_scores)/(*m_double_game_section_play_scores) * 100;
		unsigned int thisTurnStatus = DoubleGameProbabilityStatus_Normal;
		// Decide this turn double game probability status
		if(*this->m_double_game_section_play_times > 500){
			if(nowPro >= *m_double_game_probability_setting){
				if((nowPro - *m_double_game_probability_setting) > 7.0){
					thisTurnStatus = DoubleGameProbabilityStatus_Down_level3;
				}else if((nowPro - *m_double_game_probability_setting) > 5.0){
					thisTurnStatus = DoubleGameProbabilityStatus_Down_level2;
				}else if((nowPro - *m_double_game_probability_setting) > 1.0){
					thisTurnStatus = DoubleGameProbabilityStatus_Down_level1;
				}else{
					thisTurnStatus = DoubleGameProbabilityStatus_Normal;
				}
			}else{
				if(*m_double_game_probability_setting - nowPro > 7.0){
					thisTurnStatus = DoubleGameProbabilityStatus_Up_level3;
				}else if(*m_double_game_probability_setting - nowPro > 5.0){
					thisTurnStatus = DoubleGameProbabilityStatus_Up_level2;
				}else if(*m_double_game_probability_setting - nowPro > 1.0){
					thisTurnStatus = DoubleGameProbabilityStatus_Up_level1;
				}else{
					thisTurnStatus = DoubleGameProbabilityStatus_Normal;
				}
			}
		}

#ifdef DEBUG_DOUBLE_GAME_PROBABILITY
		printf("thisTurnStatus : %d \n",thisTurnStatus);
#endif

		// Get this turn award type
		unsigned int random_1 = mtRandom_double.getRandomLong(DG_PRO_BASE);
		unsigned int random_2 = mtRandom_double.getRandomLong(DG_PRO_BASE);
		unsigned int stepValue_1=0;
		unsigned int stepValue_2=0;
		unsigned int* matrix = NULL;
		unsigned int* matrix2 = NULL;
		switch(thisTurnStatus){

		case DoubleGameProbabilityStatus_Down_level3:
			for(unsigned int idx=0; idx< 4; idx++){
				stepValue_1 = 0;
				stepValue_2 = 0;
            	for(unsigned idx2=0; idx2< idx; idx2++){
            		stepValue_1 += dg_pro_70[idx2];
            	}
            	for(unsigned idx2=0; idx2<= idx; idx2++){
            		stepValue_2 += dg_pro_70[idx2];
            	}
            	if(random_2 >= stepValue_1 && random_2 < stepValue_2){
            		this->m_doubleGameAwardType = convertIndexToAwardType(idx);
            		//return this->m_doubleGameAwardType;
            	}
            }

			m_totalDrawDownLevel3Times++;
			break;

		case DoubleGameProbabilityStatus_Down_level2:
			for(unsigned int idx=0; idx< 4; idx++){
				stepValue_1 = 0;
				stepValue_2 = 0;
            	for(unsigned idx2=0; idx2< idx; idx2++){
            		stepValue_1 += dg_pro_80[idx2];
            	}
            	for(unsigned idx2=0; idx2<= idx; idx2++){
            		stepValue_2 += dg_pro_80[idx2];
            	}
            	if(random_2 >= stepValue_1 && random_2 < stepValue_2){
            		this->m_doubleGameAwardType = convertIndexToAwardType(idx);
            		//return this->m_doubleGameAwardType;
            	}
            }

			m_totalDrawDownLevel2Times++;
			break;
		case DoubleGameProbabilityStatus_Down_level1:
			stepValue_1 = 0;
			stepValue_2 = 0;
            for(unsigned int idx=0; idx< 4; idx++){
    			stepValue_1 = 0;
    			stepValue_2 = 0;
            	for(unsigned idx2=0; idx2< idx; idx2++){
            		stepValue_1 += dg_pro_83[idx2];
            	}
            	for(unsigned idx2=0; idx2<= idx; idx2++){
            		stepValue_2 += dg_pro_83[idx2];
            	}
            	if(random_2 >= stepValue_1 && random_2 < stepValue_2){
            		this->m_doubleGameAwardType = convertIndexToAwardType(idx);
            		//return this->m_doubleGameAwardType;
            	}
            }

            m_totalDrawDownLevel1Times++;
			break;

		case DoubleGameProbabilityStatus_Normal:
			switch((unsigned int)*m_double_game_probability_setting){
			case 96:
				matrix = dg_pro_set_all[0];
				break;
			case 97:
				matrix = dg_pro_set_all[1];
				break;
			case 98:
				matrix = dg_pro_set_all[2];
				break;
			case 99:
				matrix = dg_pro_set_all[3];
				break;
			case 100:
				matrix = dg_pro_set_all[4];
				break;
			default:
				break;
			}
#ifdef _DEBUG
			assert(matrix);
#endif
            for(unsigned int idx=0; idx<10; idx++){
    			stepValue_1 = 0;
    			stepValue_2 = 0;
            	for(unsigned idx2=0; idx2< idx; idx2++){
            		stepValue_1 += matrix[idx2];
            	}
            	for(unsigned idx2=0; idx2<= idx; idx2++){
            		stepValue_2 += matrix[idx2];
            	}
            	if(random_1 >= stepValue_1 && random_1 < stepValue_2){
            		matrix2 = dg_pro_all[idx];
            		break;
            	}
            }

#ifdef _DEBUG
			assert(matrix2);
#endif
            for(unsigned idx=0; idx<4; idx++){
    			stepValue_1 = 0;
    			stepValue_2 = 0;
            	for(unsigned idx2=0; idx2< idx; idx2++){
            		stepValue_1 += matrix2[idx2];
            	}
            	for(unsigned idx2=0; idx2<= idx; idx2++){
            		stepValue_2 += matrix2[idx2];
            	}
            	if(random_2 >= stepValue_1 && random_2 < stepValue_2){
            		this->m_doubleGameAwardType = convertIndexToAwardType(idx);
            		//return this->m_doubleGameAwardType;
            	}
            }

            m_totalDrawNormalTimes++;

			break;
		case DoubleGameProbabilityStatus_Up_level1:
            for(unsigned int idx=0; idx< 4; idx++){
    			stepValue_1 = 0;
    			stepValue_2 = 0;
            	for(unsigned idx2=0; idx2< idx; idx2++){
            		stepValue_1 += dg_pro_105[idx2];
            	}
            	for(unsigned idx2=0; idx2<= idx; idx2++){
            		stepValue_2 += dg_pro_105[idx2];
            	}
            	if(random_2 >= stepValue_1 && random_2 < stepValue_2){
            		this->m_doubleGameAwardType = convertIndexToAwardType(idx);
            		//return this->m_doubleGameAwardType;
            	}
            }

            m_totalDrawUpLevel1Times++;
			break;
		case DoubleGameProbabilityStatus_Up_level2:
            for(unsigned int idx=0; idx< 4; idx++){
    			stepValue_1 = 0;
    			stepValue_2 = 0;
            	for(unsigned idx2=0; idx2< idx; idx2++){
            		stepValue_1 += dg_pro_110[idx2];
            	}
            	for(unsigned idx2=0; idx2<= idx; idx2++){
            		stepValue_2 += dg_pro_110[idx2];
            	}
            	if(random_2 >= stepValue_1 && random_2 < stepValue_2){
            		this->m_doubleGameAwardType = convertIndexToAwardType(idx);
            		//return this->m_doubleGameAwardType;
            	}
            }

            m_totalDrawUpLevel2Times++;
			break;
		case DoubleGameProbabilityStatus_Up_level3:
            for(unsigned int idx=0; idx< 4; idx++){
    			stepValue_1 = 0;
    			stepValue_2 = 0;
            	for(unsigned idx2=0; idx2< idx; idx2++){
            		stepValue_1 += dg_pro_115[idx2];
            	}
            	for(unsigned idx2=0; idx2<= idx; idx2++){
            		stepValue_2 += dg_pro_115[idx2];
            	}
            	if(random_2 >= stepValue_1 && random_2 < stepValue_2){
            		this->m_doubleGameAwardType = convertIndexToAwardType(idx);
            		//return this->m_doubleGameAwardType;
            	}
            }

            m_totalDrawUpLevel3Times++;
			break;

		default:
#ifdef _DEBUG
			printf("!!!Double game get award type error ! \n");
#endif
			break;
		}

		/* 防深下拉  */
		unsigned long tmp_win = thisTurnDoubleBet;

		if(*this->m_double_game_section_play_times > 500){
			switch(this->m_doubleGameAwardType){

			case dgame_award_type_lose:
				break;

			case dgame_award_type_X2:
				tmp_win *= 2;
				break;
			case dgame_award_type_X4:
				tmp_win *= 4;
				break;
			case dgame_award_type_X6:
				tmp_win *= 6;
				break;

			default:
				break;
			}

			double pro = ((double)(tmp_win + *this->m_double_game_section_win_scores) / ((double)*this->m_double_game_section_play_scores + (double)(thisTurnDoubleBet)) ) * 100;
			unsigned int random_70Down = mtRandom_double.getRandomLong(1000);

			if(pro > (*this->m_double_game_probability_setting + 2.0f)){
				if(random_70Down < 700){
					this->m_doubleGameAwardType = dgame_award_type_lose;
					this->m_total70PercentageDownTimes++;
				}
			}
		}


#ifdef DEBUG_DOUBLE_GAME_PROBABILITY
		printf("m_doubleGameAwardType : %ld \n",this->m_doubleGameAwardType);
#endif

		//this->m_doubleGameAwardType = dgame_award_type_lose;

		return this->m_doubleGameAwardType;
	}

	/**
	 * @brief Get Open Type.
	 */
    unsigned int getOpenType(int _playerSelect){

    	switch(this->m_doubleGameAwardType){

    	case dgame_award_type_lose:
            switch(_playerSelect){

            case dgame_player_selected_ushimaou:
            	this->m_doubleGameOpenType = dgame_open_type_gokuu;

            	break;
#if 0
            case dgame_player_selected_sanzou:

            	break;
#endif

            case dgame_player_selected_gokuu:
            	this->m_doubleGameOpenType = dgame_open_type_ushimaou;

            	break;

            default:
            	break;
            }
    		break;

    	case dgame_award_type_X2:

            switch(_playerSelect){

            case dgame_player_selected_ushimaou:
            	this->m_doubleGameOpenType = dgame_open_type_ushimaou;
            	break;
#if 0
            case dgame_player_selected_sanzou:

            	break;
#endif
            case dgame_player_selected_gokuu:
            	this->m_doubleGameOpenType = dgame_open_type_gokuu;
            	break;

            default:
            	break;
            }
    		break;

    	case dgame_award_type_X4:
            switch(_playerSelect){

            case dgame_player_selected_ushimaou:
            	this->m_doubleGameOpenType = dgame_open_type_ushimaou_x4;
            	break;
#if 0
            case dgame_player_selected_sanzou:

            	break;
#endif
            case dgame_player_selected_gokuu:
            	this->m_doubleGameOpenType = dgame_open_type_gokuu_x4;
            	break;

            default:
            	break;
            }
    		break;

    	case dgame_award_type_X6:
            switch(_playerSelect){

            case dgame_player_selected_ushimaou:
            	this->m_doubleGameOpenType = dgame_open_type_sanzou;
            	break;
#if 0
            case dgame_player_selected_sanzou:

            	break;
#endif
            case dgame_player_selected_gokuu:
            	this->m_doubleGameOpenType = dgame_open_type_sanzou;
            	break;

            default:
            	break;
            }
    		break;

    	default:
#ifdef _DEBUG
    		printf("!!!Get Open Type Error! \n");
#endif
    		break;
    	}

    	return this->m_doubleGameOpenType;
    }

    /**
     * @brief Convert Index to Award Type.
     */
    unsigned int convertIndexToAwardType(unsigned int _index){
    	switch(_index){

    	case 0:
    		return dgame_award_type_lose;
    		break;
    	case 1:
    		return dgame_award_type_X2;
    		break;
    	case 2:
    		return dgame_award_type_X4;
    		break;
    	case 3:
    		return dgame_award_type_X6;
    		break;

    	default:
#ifdef _DEBUG
    	    printf("!!!Convert Index To Award Type Error! \n");
#endif
    		break;
    	}

    	return dgame_award_type_lose;
    }

    /**
     * @brief Get Result Type.
     */
    unsigned int getResultType(void){

    	switch(this->m_doubleGameAwardType){

    	case dgame_award_type_lose:
    		this->m_doubleGameResultType = dgame_result_type_lose;
    		break;
    	case dgame_award_type_X2:
    	case dgame_award_type_X4:
    	case dgame_award_type_X6:
    		this->m_doubleGameResultType = dgame_result_type_win;
    		break;

    	default:
    		break;
    	}

    	return this->m_doubleGameResultType;
    }


}DOUBLEGAMEPROBABILITYCONTROL;

/**
 * @brief Special Game Probability Control.
 */
typedef struct SpecialGameProbabilityControl{
	unsigned int m_light_award_table[SP_LIGHT_AWARD_COUNT];/**< Light Award Table */
	unsigned int m_no_win_stop_light_stop_award;/**< No win stop light stop award */
	bool m_fake_saiyuuki_flag;/**< Fake SAIYUUKI Light flag  */
	/*
	 * @brief Constructor.
	 */
	SpecialGameProbabilityControl(void){
		this->Reset();
	}

	/*
	 * @brief Reset.
	 */
	void Reset(void){
		m_no_win_stop_light_stop_award = sp_light_award_type_none;
		m_fake_saiyuuki_flag = false;

		this->m_light_award_table[0]  = sp_light_award_type_saiyuuki;
		this->m_light_award_table[1]  = sp_light_award_type_weapon_3;
		this->m_light_award_table[2]  = sp_light_award_type_book;
        this->m_light_award_table[3]  = sp_light_award_type_exit;
		this->m_light_award_table[4]  = sp_light_award_type_weapon_1;
		this->m_light_award_table[5]  = sp_light_award_type_character_1;
		this->m_light_award_table[6]  = sp_light_award_type_weapon_2;
		this->m_light_award_table[7]  = sp_light_award_type_weapon_3;
		this->m_light_award_table[8]  = sp_light_award_type_character_2;
		this->m_light_award_table[9]  = sp_light_award_type_exit;
		this->m_light_award_table[10] = sp_light_award_type_character_3;
		this->m_light_award_table[11] = sp_light_award_type_book;
		this->m_light_award_table[12] = sp_light_award_type_character_1;
		this->m_light_award_table[13] = sp_light_award_type_weapon_4;
		this->m_light_award_table[14] = sp_light_award_type_weapon_1;
		this->m_light_award_table[15] = sp_light_award_type_exit;
		this->m_light_award_table[16] = sp_light_award_type_character_3;
		this->m_light_award_table[17] = sp_light_award_type_weapon_2;
		this->m_light_award_table[18] = sp_light_award_type_weapon_3;
		this->m_light_award_table[19] = sp_light_award_type_book;
		this->m_light_award_table[20] = sp_light_award_type_character_2;
		this->m_light_award_table[21] = sp_light_award_type_exit;
		this->m_light_award_table[22] = sp_light_award_type_weapon_4;
		this->m_light_award_table[23] = sp_light_award_type_weapon_2;
	}

	/**
	 * @brief Decide Draw which table
	 */
	unsigned int DecideDrawWhichTable(unsigned int specialGameType){
		unsigned int table_index = 0;
		unsigned int random = mtRandom_special.getRandomLong(1000);

		if(specialGameType == sp_type_supplementary){
			table_index = 3;
		}else{
			if(random < 333){
				table_index = 0;
			}else if(random >= 333 && random < 666){
				table_index = 1;
			}else{
				table_index = 2;
			}
		}

		return table_index;
	}

	/**
	 * @brief Get Total Special Game Times.
	 * @param saiyuuki_times Saiyuuki Times
	 * @retval Total Turn Special Game Times
	 */
	unsigned int getTotalSpecialGameTimes(unsigned int saiyuuki_times){
		unsigned int times = 0;

		times = saiyuuki_times + saiyuuki_times + mtRandom_special.getRandomLong(0,saiyuuki_times);

		return times;
	}

	/**
	 * @brief Arrange Draw Array.
	 * @param saiyuuki_times Saiyuuki Times
	 * @param totalPlayTimes Total Play Times
	 */
	void arrangeDrawArray(unsigned int* drawTypeArray,unsigned int saiyuuki_times,unsigned int totalPlayTimes){
		unsigned char* index_array;
		unsigned int index_1 = 0;
		unsigned int index_2 = 0;
		unsigned int tmp=0;

#ifdef _DEBUG
		bool assert_result = true;
		unsigned int assert_type_draw_times = 0;
		unsigned int assert_type_exit_times = 0;
#endif

		index_array = (unsigned char*)malloc(totalPlayTimes-1);
		for(unsigned int idx=0; idx<totalPlayTimes-1; idx++){
			index_array[idx] = idx;
		}

		//Random content of index_array
		for(unsigned int idx=0; idx<500; idx++){
			index_1 = mtRandom_special.getRandomLong(0,totalPlayTimes-2);
			index_2 = mtRandom_special.getRandomLong(0,totalPlayTimes-2);

			tmp = index_array[index_1];
			index_array[index_1] = index_array[index_2];
			index_array[index_2] = tmp;
		}

		//Set final index to exit
		drawTypeArray[totalPlayTimes-1] = sp_draw_type_exit;
		//Set draw index
		for(unsigned int idx=0; idx<saiyuuki_times; idx++){
			drawTypeArray[index_array[idx]] = sp_draw_type_draw;
		}
		//Set remain exit index
		for(unsigned int idx=saiyuuki_times; idx<(saiyuuki_times+saiyuuki_times-1); idx++){
			drawTypeArray[index_array[idx]] = sp_draw_type_exit;
		}
		//Set no win index
		for(unsigned int idx=(saiyuuki_times+saiyuuki_times-1); idx<totalPlayTimes-1; idx++){
			drawTypeArray[index_array[idx]] = sp_draw_type_no_win;
		}

#ifdef _DEBUG
		for(unsigned int idx=0; idx<totalPlayTimes; idx++){
			if(drawTypeArray[idx] == sp_draw_type_none){
				assert_result = false;
				break;
			}
		}

		assert_type_draw_times=0;
		for(unsigned int idx=0; idx<totalPlayTimes; idx++){
			if(drawTypeArray[idx] == sp_draw_type_draw){
				assert_type_draw_times++;
			}
		}
		if(assert_type_draw_times != saiyuuki_times) assert_result = false;

		assert_type_exit_times=0;
		for(unsigned int idx=0; idx<totalPlayTimes; idx++){
			if(drawTypeArray[idx] == sp_draw_type_exit){
				assert_type_exit_times++;
			}
		}
		if(assert_type_exit_times != saiyuuki_times) assert_result = false;

		assert(assert_result);
#endif

		free(index_array);
	}

	/**
	 * @brief Convert Index To Award Type.
	 * @param index Index
	 * @param lightAwardType Light award type
	 * @param slotAwardType Slot award type
	 *
	 */
	void ConvertIndexToAwardType(unsigned int index,unsigned int* lightAwardType,unsigned int* slotAwardType){
		//Convert
		switch(index){

		case  0:
    		*lightAwardType = sp_light_award_type_none;
    		*slotAwardType  = sp_slot_award_type_none;
			break;
		case  1:
    		*lightAwardType = sp_light_award_type_weapon_3;
    		*slotAwardType  = sp_slot_award_type_none;
			break;
		case  2:
    		*lightAwardType = sp_light_award_type_weapon_2;
    		*slotAwardType  = sp_slot_award_type_none;
			break;
		case  3:
    		*lightAwardType = sp_light_award_type_book;
    		*slotAwardType  = sp_slot_award_type_none;
			break;
		case  4:
    		*lightAwardType = sp_light_award_type_weapon_4;
    		*slotAwardType  = sp_slot_award_type_none;
			break;
		case  5:
    		*lightAwardType = sp_light_award_type_weapon_1;
    		*slotAwardType  = sp_slot_award_type_none;
			break;
		case  6:
    		*lightAwardType = sp_light_award_type_character_3;
    		*slotAwardType  = sp_slot_award_type_none;
			break;
		case  7:
    		*lightAwardType = sp_light_award_type_character_2;
    		*slotAwardType  = sp_slot_award_type_none;
			break;
		case  8:
    		*lightAwardType = sp_light_award_type_character_1;
    		*slotAwardType  = sp_slot_award_type_none;
			break;
		case  9:
    		*lightAwardType = sp_light_award_type_saiyuuki;
    		*slotAwardType  = sp_slot_award_type_none;
			break;
		case 10:
    		*lightAwardType = sp_light_award_type_none;
    		*slotAwardType  = sp_slot_award_type_x20;
			break;
		case 11:
    		*lightAwardType = sp_light_award_type_weapon_3;
    		*slotAwardType  = sp_slot_award_type_x20;
			break;
		case 12:
    		*lightAwardType = sp_light_award_type_weapon_2;
    		*slotAwardType  = sp_slot_award_type_x20;
			break;
		case 13:
    		*lightAwardType = sp_light_award_type_book;
    		*slotAwardType  = sp_slot_award_type_x20;
			break;
		case 14:
    		*lightAwardType = sp_light_award_type_weapon_4;
    		*slotAwardType  = sp_slot_award_type_x20;
			break;
		case 15:
    		*lightAwardType = sp_light_award_type_weapon_1;
    		*slotAwardType  = sp_slot_award_type_x20;
			break;
		case 16:
    		*lightAwardType = sp_light_award_type_character_3;
    		*slotAwardType  = sp_slot_award_type_x20;
			break;
		case 17:
    		*lightAwardType = sp_light_award_type_character_2;
    		*slotAwardType  = sp_slot_award_type_x20;
			break;
		case 18:
    		*lightAwardType = sp_light_award_type_character_1;
    		*slotAwardType  = sp_slot_award_type_x20;
			break;
		case 19:
    		*lightAwardType = sp_light_award_type_saiyuuki;
    		*slotAwardType  = sp_slot_award_type_x20;
			break;
		case 20:
    		*lightAwardType = sp_light_award_type_none;
    		*slotAwardType  = sp_slot_award_type_x500;
			break;
		case 21:
    		*lightAwardType = sp_light_award_type_weapon_3;
    		*slotAwardType  = sp_slot_award_type_x500;
			break;
		case 22:
    		*lightAwardType = sp_light_award_type_weapon_2;
    		*slotAwardType  = sp_slot_award_type_x500;
			break;
		case 23:
    		*lightAwardType = sp_light_award_type_book;
    		*slotAwardType  = sp_slot_award_type_x500;
			break;
		case 24:
    		*lightAwardType = sp_light_award_type_weapon_4;
    		*slotAwardType  = sp_slot_award_type_x500;
			break;
		case 25:
    		*lightAwardType = sp_light_award_type_weapon_1;
    		*slotAwardType  = sp_slot_award_type_x500;
			break;
		case 26:
    		*lightAwardType = sp_light_award_type_character_3;
    		*slotAwardType  = sp_slot_award_type_x500;
			break;
		case 27:
    		*lightAwardType = sp_light_award_type_character_2;
    		*slotAwardType  = sp_slot_award_type_x500;
			break;
		case 28:
    		*lightAwardType = sp_light_award_type_character_1;
    		*slotAwardType  = sp_slot_award_type_x500;
			break;
		case 29:
    		*lightAwardType = sp_light_award_type_saiyuuki;
    		*slotAwardType  = sp_slot_award_type_x500;
			break;

		default:
			break;
		}
	}

	/**
	 * @brief Get This Turn Award Type.
	 * @param thisTurnDrawType This turn draw type
	 * @param drawTableIndex Draw Table Index
	 * @param lightAwardType Light award type
	 * @param slotAwardType Slot award type
	 */
    void getThisTurnAwardType(unsigned int thisTurnDrawType,unsigned int drawTableIndex,unsigned int* lightAwardType,unsigned int* slotAwardType){
    	unsigned int random = mtRandom_special.getRandomLong(10000);

    	// By This Turn Draw Type
    	switch(thisTurnDrawType){

    	case sp_draw_type_draw:

    		for(unsigned int idx=0; idx<sizeof(sp_award_draw_table[0])/sizeof(sp_award_draw_table[0][0]); idx++){
    			if(idx==0){
    				if(random < sp_award_draw_table[drawTableIndex][idx]){
    					this->ConvertIndexToAwardType(idx,lightAwardType,slotAwardType);
    					break;
    				}
    			}else{
					if(random >= sp_award_draw_table[drawTableIndex][idx-1] && random < sp_award_draw_table[drawTableIndex][idx]){
						this->ConvertIndexToAwardType(idx,lightAwardType,slotAwardType);
						break;
					}
				}
    		}

    		break;

    	case sp_draw_type_no_win:

    		if(random < 5000){
        		*lightAwardType = sp_light_award_type_none;
        		*slotAwardType  = sp_slot_award_type_none;
    		}else if(random >= 5000 && random < 8000){
        		*lightAwardType = sp_light_award_type_weapon_3;
        		*slotAwardType  = sp_slot_award_type_none;
    		}else{
        		*lightAwardType = sp_light_award_type_weapon_2;
        		*slotAwardType  = sp_slot_award_type_none;
    		}

    		break;

    	case sp_draw_type_exit:
    		*lightAwardType = sp_light_award_type_exit;
    		*slotAwardType  = sp_slot_award_type_none;
    		break;

    	default:
    		break;
    	}

#ifdef DEBUG_SPECIALGAME_SPECIFIED_ITEM
		*lightAwardType = sp_light_award_type_saiyuuki;
		*slotAwardType  = sp_slot_award_type_x500;
#endif

	}

    /**
     * @brief Decide Light and Slot Item.
     */
    void DecideLightAndSlotItem(unsigned int* thisTurnLightAward,unsigned int* thisTurnSlotAward,int* nextLightIndex,
    		                        unsigned int* stopItem1,unsigned int* stopItem2,unsigned int* stopItem3,unsigned int* stopItem4){

    	unsigned int* sp_stop_item[4]   = {stopItem1,stopItem2,stopItem3,stopItem4};
    	unsigned int  tmp_array[4] = { 0 };
    	unsigned int  x20_straight_index_1[3]  ={0,1,2};
    	unsigned int  x20_straight_index_2[3]  ={1,2,3};
    	unsigned int  x500_straight_index[4]   ={1,2,3,4};
    	unsigned long x20_straight_random      = 0;
    	unsigned int  win_light_award_index_array[4] = {0,1,2,3};
    	unsigned int  win_light_award_item_count = 0;
    	unsigned int  tmp_slot_style=0;
    	unsigned int  tmp_slot_item_1;
    	unsigned int  tmp_slot_item_2;
    	unsigned int  tmp_slot_item_3;
    	unsigned int  tmp_slot_item_4;
    	unsigned int  x20_no_straight_index_1[3] = {0,1,3};
    	unsigned int  x20_no_straight_index_2[3] = {0,2,3};
    	unsigned int  tmp = 0;
    	unsigned int  index_1 = 0;
    	unsigned int  index_2 = 0;


    	//Decide Light Index
    	switch(*thisTurnLightAward){

    	case sp_light_award_type_exit:
    	case sp_light_award_type_none:
    	case sp_light_award_type_weapon_3:
    	case sp_light_award_type_weapon_2:
    	case sp_light_award_type_book:
    	case sp_light_award_type_weapon_4:
    	case sp_light_award_type_weapon_1:
    	case sp_light_award_type_character_3:
    	case sp_light_award_type_character_2:
    	case sp_light_award_type_character_1:
    	case sp_light_award_type_saiyuuki:
    		*nextLightIndex = getLightIndexByLightAward(thisTurnLightAward);
    		break;

    	default:
    		break;
    	}

    	//Decide Slot Item
    	switch(*thisTurnSlotAward){

    	case sp_slot_award_type_none:

    		switch(*thisTurnLightAward){

    		case sp_light_award_type_exit:
    		case sp_light_award_type_none://不中燈號時的滾輪隨機抽選(不能生成3連線或4連線)

    			if(m_fake_saiyuuki_flag==false){
    				tmp_slot_style = mtRandom_common.getRandomLong(3);

    				if(tmp_slot_style == 2){//配三個相同的物件,但不能連線
    					tmp_slot_item_1 = mtRandom_common.getRandomLong(2,10);//決定三個相同的物件是那一個
    					while(tmp_slot_item_1 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_1 = mtRandom_common.getRandomLong(2,10);
    					}
    					tmp_slot_item_2 = mtRandom_common.getRandomLong(2,10);//決定剩下的那一個物件
    					while(tmp_slot_item_2 == tmp_slot_item_1 || tmp_slot_item_2 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_2 = mtRandom_common.getRandomLong(2,10);
    					}

    					if(mtRandom_common.getRandomLong(2)==0){//決定滾輪物件的排列出現方式
    						for(unsigned int idx=0; idx<sizeof(x20_no_straight_index_1)/sizeof(x20_no_straight_index_1[0]); idx++){
    							tmp_array[x20_no_straight_index_1[idx]] = tmp_slot_item_1;
    						}
    						tmp_array[2] = tmp_slot_item_2;

    					}else{//決定滾輪物件的排列出現方式
    						for(unsigned int idx=0; idx<sizeof(x20_no_straight_index_2)/sizeof(x20_no_straight_index_2[0]); idx++){
    							tmp_array[x20_no_straight_index_2[idx]] = tmp_slot_item_1;
    						}
    						tmp_array[1] = tmp_slot_item_2;
    					}
    				}else if(tmp_slot_style == 1){//配兩個相同的物件
    					for(unsigned int idx=0; idx<300; idx++){//Random the array index
    	    				index_1 = mtRandom_special.getRandomLong(0,3);
    	    				index_2 = mtRandom_special.getRandomLong(0,3);

    	    				tmp = win_light_award_index_array[index_1];
    	    				win_light_award_index_array[index_1] = win_light_award_index_array[index_2];
    	    				win_light_award_index_array[index_2] = tmp;
    	    			}

    					tmp_slot_item_1 = mtRandom_common.getRandomLong(2,10);//決定兩個相同的物件是那一個
    					while(tmp_slot_item_1 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_1 = mtRandom_common.getRandomLong(2,10);
    					}
    					tmp_slot_item_2 = mtRandom_common.getRandomLong(2,10);//決定另一個物件
    					while(tmp_slot_item_2 == tmp_slot_item_1 || tmp_slot_item_2 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_2 = mtRandom_common.getRandomLong(2,10);
    					}
    					tmp_slot_item_3 = mtRandom_common.getRandomLong(2,10);//決定最後一個物件
    					while(tmp_slot_item_3 == tmp_slot_item_1 || tmp_slot_item_3 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_3 = mtRandom_common.getRandomLong(2,10);
    					}

    					for(unsigned int idx=0; idx<2; idx++){
    						tmp_array[idx] = tmp_slot_item_1;
    					}
    					tmp_array[2] = tmp_slot_item_2;
    					tmp_array[3] = tmp_slot_item_3;

    				}else if(tmp_slot_style == 0){//四個都不相同
    					tmp_slot_item_1 = mtRandom_common.getRandomLong(2,10);//決定第一個物件
    					while(tmp_slot_item_1 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_1 = mtRandom_common.getRandomLong(2,10);
    					}
    					tmp_slot_item_2 = mtRandom_common.getRandomLong(2,10);//決定第二個物件
    					while(tmp_slot_item_2 == tmp_slot_item_1 || tmp_slot_item_2 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_2 = mtRandom_common.getRandomLong(2,10);
    					}
    					tmp_slot_item_3 = mtRandom_common.getRandomLong(2,10);//決定第三個物件
    					while(tmp_slot_item_3 == tmp_slot_item_1 || tmp_slot_item_3 == tmp_slot_item_2 || tmp_slot_item_3 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_3 = mtRandom_common.getRandomLong(2,10);
    					}

    					tmp_slot_item_4 = mtRandom_common.getRandomLong(2,10);//決定第四個物件
    					while(tmp_slot_item_4 == tmp_slot_item_1 || tmp_slot_item_4 == tmp_slot_item_2 || tmp_slot_item_4 == tmp_slot_item_3 || tmp_slot_item_4 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_4 = mtRandom_common.getRandomLong(2,10);
    					}

    					tmp_array[0] = tmp_slot_item_1;
    					tmp_array[1] = tmp_slot_item_2;
    					tmp_array[2] = tmp_slot_item_3;
    					tmp_array[3] = tmp_slot_item_4;
    				}
#if 0
					tmp_type =  mtRandom_special.getRandomLong(2,10);
					while(tmp_type == this->m_no_win_stop_light_stop_award){
						tmp_type = mtRandom_special.getRandomLong(2,10);
					}
					tmp_array[idx] = tmp_type;
#endif
    			}else{
    				tmp_slot_style = mtRandom_common.getRandomLong(3);

    				if(tmp_slot_style == 2){//配三個相同的物件,但不能連線
    					tmp_slot_item_1 = mtRandom_common.getRandomLong(2,9);//決定三個相同的物件是那一個
    					while(tmp_slot_item_1 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_1 = mtRandom_common.getRandomLong(2,9);
    					}
    					tmp_slot_item_2 = mtRandom_common.getRandomLong(2,9);//決定剩下的那一個物件
    					while(tmp_slot_item_2 == tmp_slot_item_1 || tmp_slot_item_2 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_2 = mtRandom_common.getRandomLong(2,9);
    					}

    					if(mtRandom_common.getRandomLong(2)==0){//決定滾輪物件的排列出現方式
    						for(unsigned int idx=0; idx<sizeof(x20_no_straight_index_1)/sizeof(x20_no_straight_index_1[0]); idx++){
    							tmp_array[x20_no_straight_index_1[idx]] = tmp_slot_item_1;
    						}
    						tmp_array[2] = tmp_slot_item_2;

    					}else{//決定滾輪物件的排列出現方式
    						for(unsigned int idx=0; idx<sizeof(x20_no_straight_index_2)/sizeof(x20_no_straight_index_2[0]); idx++){
    							tmp_array[x20_no_straight_index_2[idx]] = tmp_slot_item_1;
    						}
    						tmp_array[1] = tmp_slot_item_2;
    					}
    				}else if(tmp_slot_style == 1){//配兩個相同的物件
    					for(unsigned int idx=0; idx<300; idx++){//Random the array index
    	    				index_1 = mtRandom_common.getRandomLong(0,3);
    	    				index_2 = mtRandom_common.getRandomLong(0,3);

    	    				tmp = win_light_award_index_array[index_1];
    	    				win_light_award_index_array[index_1] = win_light_award_index_array[index_2];
    	    				win_light_award_index_array[index_2] = tmp;
    	    			}

    					tmp_slot_item_1 = mtRandom_common.getRandomLong(2,9);//決定兩個相同的物件是那一個
    					while(tmp_slot_item_1 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_1 = mtRandom_common.getRandomLong(2,9);
    					}
    					tmp_slot_item_2 = mtRandom_common.getRandomLong(2,9);//決定另一個物件
    					while(tmp_slot_item_2 == tmp_slot_item_1 || tmp_slot_item_2 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_2 = mtRandom_common.getRandomLong(2,9);
    					}
    					tmp_slot_item_3 = mtRandom_common.getRandomLong(2,9);//決定最後一個物件
    					while(tmp_slot_item_3 == tmp_slot_item_1 || tmp_slot_item_3 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_3 = mtRandom_common.getRandomLong(2,9);
    					}

    					for(unsigned int idx=0; idx<2; idx++){
    						tmp_array[idx] = tmp_slot_item_1;
    					}
    					tmp_array[2] = tmp_slot_item_2;
    					tmp_array[3] = tmp_slot_item_3;

    				}else if(tmp_slot_style == 0){//四個都不相同
    					tmp_slot_item_1 = mtRandom_common.getRandomLong(2,9);//決定第一個物件
    					while(tmp_slot_item_1 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_1 = mtRandom_common.getRandomLong(2,9);
    					}
    					tmp_slot_item_2 = mtRandom_common.getRandomLong(2,10);//決定第二個物件
    					while(tmp_slot_item_2 == tmp_slot_item_1 || tmp_slot_item_2 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_2 = mtRandom_common.getRandomLong(2,9);
    					}
    					tmp_slot_item_3 = mtRandom_common.getRandomLong(2,10);//決定第三個物件
    					while(tmp_slot_item_3 == tmp_slot_item_1 || tmp_slot_item_3 == tmp_slot_item_2 || tmp_slot_item_3 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_3 = mtRandom_common.getRandomLong(2,9);
    					}

    					tmp_slot_item_4 = mtRandom_common.getRandomLong(2,10);//決定第四個物件
    					while(tmp_slot_item_4 == tmp_slot_item_1 || tmp_slot_item_4 == tmp_slot_item_2 || tmp_slot_item_4 == tmp_slot_item_3 || tmp_slot_item_4 == this->m_no_win_stop_light_stop_award){
    						tmp_slot_item_4 = mtRandom_common.getRandomLong(2,9);
    					}

    					tmp_array[0] = tmp_slot_item_1;
    					tmp_array[1] = tmp_slot_item_2;
    					tmp_array[2] = tmp_slot_item_3;
    					tmp_array[3] = tmp_slot_item_4;
    				}
#if 0
    				tmp_type =  mtRandom_special.getRandomLong(2,9);
					while(tmp_type == this->m_no_win_stop_light_stop_award){
						tmp_type = mtRandom_special.getRandomLong(2,9);
					}
					tmp_array[idx] = tmp_type;
#endif
    			}

    			//for(unsigned int idx=0,tmp_type=0; idx<4; idx++){

        		//}

        		//轉換 light 燈號物件為 Slot 停止物件
        		for(unsigned int idx=0; idx<4; idx++){
        			*sp_stop_item[win_light_award_index_array[idx]] = ChangeLightTypeToSlotType(tmp_array[idx]);
        		}
    			break;

    		case sp_light_award_type_weapon_3:
    		case sp_light_award_type_weapon_2:
    		case sp_light_award_type_book:
    		case sp_light_award_type_weapon_4:
    		case sp_light_award_type_weapon_1:
    		case sp_light_award_type_character_3:
    		case sp_light_award_type_character_2:
    		case sp_light_award_type_character_1:
    		case sp_light_award_type_saiyuuki:
    	    	//unsigned int  win_light_award_index_array[4] = {0,1,2,3};
    	    	//unsigned int  win_light_award_item_count = 0;
    	    	//unsigned int index_1 = 0;
    	    	//unsigned int index_2 = 0;
    			for(unsigned int idx=0; idx<300; idx++){
    				index_1 = mtRandom_special.getRandomLong(0,3);
    				index_2 = mtRandom_special.getRandomLong(0,3);

    				tmp = win_light_award_index_array[index_1];
    				win_light_award_index_array[index_1] = win_light_award_index_array[index_2];
    				win_light_award_index_array[index_2] = tmp;
    			}

    			win_light_award_item_count = mtRandom_special.getRandomLong(1,2);//Max 2 the same winning item

    			for(unsigned int idx=0; idx<win_light_award_item_count; idx++){
    				tmp_array[idx] = *thisTurnLightAward;
    			}

    			for(unsigned int idx=win_light_award_item_count,tmp_type=0; idx<4; idx++){
        			tmp_type =  mtRandom_special.getRandomLong(2,10);
        			while(tmp_type ==  *thisTurnLightAward){
        				tmp_type = mtRandom_special.getRandomLong(2,10);
        			}
        			tmp_array[idx] = tmp_type;
    			}

    			for(unsigned int idx=0; idx<4; idx++){
    				*sp_stop_item[win_light_award_index_array[idx]] = ChangeLightTypeToSlotType(tmp_array[idx]);
    			}

    			break;

    		default:
    			break;
    		}


    		break;

    	case sp_slot_award_type_x20:

    		switch(*thisTurnLightAward){

    		case sp_light_award_type_none:
    			x20_straight_random =  mtRandom_special.getRandomLong(1000);
    			tmp_slot_item_1 = mtRandom_special.getRandomLong(2,10);
    			while(tmp_slot_item_1 == this->m_no_win_stop_light_stop_award){
    				tmp_slot_item_1 = mtRandom_special.getRandomLong(2,10);
    			}

        		if(x20_straight_random < 500){
        			for(unsigned int idx=0; idx<sizeof(x20_straight_index_1)/sizeof(x20_straight_index_1[0]); idx++){
        				*sp_stop_item[x20_straight_index_1[idx]] = ChangeLightTypeToSlotType(tmp_slot_item_1);
        			}

        			unsigned int tmp_type =  mtRandom_special.getRandomLong(2,10);
        			while(tmp_type ==  tmp_slot_item_1 || tmp_type == this->m_no_win_stop_light_stop_award){
        				tmp_type = mtRandom_special.getRandomLong(2,10);
        			}

        			*sp_stop_item[3] = ChangeLightTypeToSlotType(tmp_type);

        		}else{
        			for(unsigned int idx=0; idx<sizeof(x20_straight_index_2)/sizeof(x20_straight_index_2[0]); idx++){
        				*sp_stop_item[x20_straight_index_2[idx]] = ChangeLightTypeToSlotType(tmp_slot_item_1);
        			}

        			unsigned int tmp_type =  mtRandom_special.getRandomLong(2,10);
        			while(tmp_type == tmp_slot_item_1 || tmp_type == this->m_no_win_stop_light_stop_award){
        				tmp_type = mtRandom_special.getRandomLong(2,10);
        			}

        			*sp_stop_item[0] = ChangeLightTypeToSlotType(tmp_type);
        		}
    			break;

    		case sp_light_award_type_weapon_3:
    		case sp_light_award_type_weapon_2:
    		case sp_light_award_type_book:
    		case sp_light_award_type_weapon_4:
    		case sp_light_award_type_weapon_1:
    		case sp_light_award_type_character_3:
    		case sp_light_award_type_character_2:
    		case sp_light_award_type_character_1:
    		case sp_light_award_type_saiyuuki:
        		x20_straight_random =  mtRandom_special.getRandomLong(1000);
        		if(x20_straight_random < 500){
        			for(unsigned int idx=0; idx<sizeof(x20_straight_index_1)/sizeof(x20_straight_index_1[0]); idx++){
        				*sp_stop_item[x20_straight_index_1[idx]] = ChangeLightTypeToSlotType(*thisTurnLightAward);
        			}

        			unsigned int tmp_type =  mtRandom_special.getRandomLong(2,10);
        			while(tmp_type ==  *thisTurnLightAward){
        				tmp_type = mtRandom_special.getRandomLong(2,10);
        			}

        			*sp_stop_item[3] = ChangeLightTypeToSlotType(tmp_type);

        		}else{
        			for(unsigned int idx=0; idx<sizeof(x20_straight_index_2)/sizeof(x20_straight_index_2[0]); idx++){
        				*sp_stop_item[x20_straight_index_2[idx]] = ChangeLightTypeToSlotType(*thisTurnLightAward);
        			}

        			unsigned int tmp_type =  mtRandom_special.getRandomLong(2,10);
        			while(tmp_type ==  *thisTurnLightAward){
        				tmp_type = mtRandom_special.getRandomLong(2,10);
        			}

        			*sp_stop_item[0] = ChangeLightTypeToSlotType(tmp_type);
        		}
    			break;

    		default:
    			break;
    		}

    		break;

    	case sp_slot_award_type_x500:

    		switch(*thisTurnLightAward){

    		case sp_light_award_type_none:
    			tmp_slot_item_1 = mtRandom_special.getRandomLong(2,10);
    			while(tmp_slot_item_1 == this->m_no_win_stop_light_stop_award){
    				tmp_slot_item_1 = mtRandom_special.getRandomLong(2,10);
    			}

        		for(unsigned int idx=0; idx<sizeof(x500_straight_index)/sizeof(x500_straight_index[0]); idx++){
        			*sp_stop_item[idx] = ChangeLightTypeToSlotType(tmp_slot_item_1);
        		}
    			break;

    		case sp_light_award_type_weapon_3:
    		case sp_light_award_type_weapon_2:
    		case sp_light_award_type_book:
    		case sp_light_award_type_weapon_4:
    		case sp_light_award_type_weapon_1:
    		case sp_light_award_type_character_3:
    		case sp_light_award_type_character_2:
    		case sp_light_award_type_character_1:
    		case sp_light_award_type_saiyuuki:
        		for(unsigned int idx=0; idx<sizeof(x500_straight_index)/sizeof(x500_straight_index[0]); idx++){
        			*sp_stop_item[idx] = ChangeLightTypeToSlotType(*thisTurnLightAward);
        		}
    			break;

    		default:
    			break;
    		}



    		break;

    	default:
    		break;
    	}

    }

    /**
     * @brief Get Light Index by Light Award.
     */
    unsigned int getLightIndexByLightAward(unsigned int* thisTurnLighrAward){
    	unsigned int  index = 1;
    	unsigned long random = mtRandom_special.getRandomLong(1000);

    	unsigned int _exitIndex[4]       = { 3, 9, 15, 21 };
    	unsigned int _weapon3Index[3]    = { 1, 7, 18 };
    	unsigned int _weapon2Index[3]    = { 6,17, 23 };
    	unsigned int _bookIndex[3]       = { 2,11, 19 };
    	unsigned int _weapon4Index[2]    = {13,22 };
    	unsigned int _weapon1Index[2]    = { 4,14 };
    	unsigned int _character3Index[2] = {10,16 };
    	unsigned int _character2Index[2] = { 8,20 };
    	unsigned int _character1Index[2] = { 5,12};
    	unsigned int _saiyuukiIndex[1]   = { 0 };

    	switch(*thisTurnLighrAward){

    	case sp_light_award_type_exit:
    		index = _exitIndex[mtRandom_special.getRandomLong(sizeof(_exitIndex)/sizeof(_exitIndex[0]))];
    		break;

    	case sp_light_award_type_none:

    		if(random < 10){
    			index = _saiyuukiIndex[0];
    			m_fake_saiyuuki_flag = true;
    			this->m_no_win_stop_light_stop_award = sp_light_award_type_saiyuuki;
    		}else{
    			m_fake_saiyuuki_flag = false;
    			this->m_no_win_stop_light_stop_award = mtRandom_special.getRandomLong(2,9);
    			switch(this->m_no_win_stop_light_stop_award){

    			case sp_light_award_type_weapon_3:
    				index = _weapon3Index[mtRandom_special.getRandomLong(sizeof(_weapon3Index)/sizeof(_weapon3Index[0]))];
    				break;
    			case sp_light_award_type_weapon_2:
    				index = _weapon2Index[mtRandom_special.getRandomLong(sizeof(_weapon2Index)/sizeof(_weapon2Index[0]))];
    				break;
    			case sp_light_award_type_book:
    				index = _bookIndex[mtRandom_special.getRandomLong(sizeof(_bookIndex)/sizeof(_bookIndex[0]))];
    				break;
    			case sp_light_award_type_weapon_4:
    				index = _weapon4Index[mtRandom_special.getRandomLong(sizeof(_weapon4Index)/sizeof(_weapon4Index[0]))];
    				break;
    			case sp_light_award_type_weapon_1:
    				index = _weapon1Index[mtRandom_special.getRandomLong(sizeof(_weapon1Index)/sizeof(_weapon1Index[0]))];
    				break;
    			case sp_light_award_type_character_3:
    				index = _character3Index[mtRandom_special.getRandomLong(sizeof(_character3Index)/sizeof(_character3Index[0]))];
    				break;
    			case sp_light_award_type_character_2:
    				index = _character2Index[mtRandom_special.getRandomLong(sizeof(_character2Index)/sizeof(_character2Index[0]))];
    				break;
    			case sp_light_award_type_character_1:
    				index = _character1Index[mtRandom_special.getRandomLong(sizeof(_character1Index)/sizeof(_character1Index[0]))];
    				break;

    			default:
    				break;
    			}
    		}

    		break;

    	case sp_light_award_type_weapon_3:
    		index = _weapon3Index[mtRandom_special.getRandomLong(sizeof(_weapon3Index)/sizeof(_weapon3Index[0]))];
    		break;

    	case sp_light_award_type_weapon_2:
    		index = _weapon2Index[mtRandom_special.getRandomLong(sizeof(_weapon2Index)/sizeof(_weapon2Index[0]))];
    		break;

    	case sp_light_award_type_book:
    		index = _bookIndex[mtRandom_special.getRandomLong(sizeof(_bookIndex)/sizeof(_bookIndex[0]))];
    		break;

    	case sp_light_award_type_weapon_4:
    		index = _weapon4Index[mtRandom_special.getRandomLong(sizeof(_weapon4Index)/sizeof(_weapon4Index[0]))];
    		break;

    	case sp_light_award_type_weapon_1:
    		index = _weapon1Index[mtRandom_special.getRandomLong(sizeof(_weapon1Index)/sizeof(_weapon1Index[0]))];
    		break;

    	case sp_light_award_type_character_3:
    		index = _character3Index[mtRandom_special.getRandomLong(sizeof(_character3Index)/sizeof(_character3Index[0]))];
    		break;

    	case sp_light_award_type_character_2:
    		index = _character2Index[mtRandom_special.getRandomLong(sizeof(_character2Index)/sizeof(_character2Index[0]))];
    		break;

    	case sp_light_award_type_character_1:
    		index = _character1Index[mtRandom_special.getRandomLong(sizeof(_character1Index)/sizeof(_character1Index[0]))];
    		break;

    	case sp_light_award_type_saiyuuki:
    		index = _saiyuukiIndex[0];
    		break;

    	default:
    		break;
    	}

    	return index;
    }

    /**
     * @brief Change Light Type To Slot Type.
     */
    unsigned int ChangeLightTypeToSlotType(unsigned int lightType){
    	unsigned int slotType = ITEM_UNKNOW;
    	unsigned int translate[9] ={ 2, 3, 4, 5, 1, 6, 7, 8, 9 };


    	slotType = translate[lightType-2];
    	return slotType;

    }

	/**
	 * @brief Get Prepare Stop Index.
	 */
	void getPrepareStopIndex(int* nextStopIndex,int* prepareStopIndex){
		unsigned int random = 5;//mtRandom_special.getRandomLong(4,5);
		*prepareStopIndex = *nextStopIndex - random;
		if(*prepareStopIndex < 0){
			*prepareStopIndex = *prepareStopIndex + 24 + 1;
			if(*prepareStopIndex >= 24){
				*prepareStopIndex %= 24;
			}
		}
	}


}SPECIALGAMEPROBABILITYCONTROL;

#endif /* PROBABILITYTYPE_H_ */
