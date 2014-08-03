/**
 * @file gameSettingValueType.h
 * @brief declare game setting value structure type.
 *
 */

#ifndef GAMESETTINGVALUETYPE_H_
#define GAMESETTINGVALUETYPE_H_

#include "../preprocessor.h"
#include "gameDefine.h"

/**
 * @brief System Setting Data Structure.
 */
typedef struct SystemSettingData{
   unsigned int  _CreditIn;/**< Credit In (上分值) */
   unsigned int  _CreditOut;/**< Credit Out (下分值) */
   unsigned int  _SingleLineMaxBet;/**< Single line maximum bet (單線最大押分) */
   unsigned int  _SingleLineMinBet;/**< Single line minimum bet (單線最小押分) */
   unsigned int  _CreditInLimit;/**< Credit in limit (系統爆機分數) */
   unsigned int  _DoubleGameCreditLimit;/**< Double game credit limit (比倍爆機分數) */
   unsigned int  _DoubleDownOnOff;/**< Double down type (比倍遊戲開關) */
   unsigned int  _DirectDoubleDown;/**< Enter to double down directly (直接比倍) */
   unsigned int  _SingleLineBetUnit;/**< Single line bet unit (單線押注進分值) */
   unsigned int  _PaySetting;/**< Pay Setting(退分設定) */
   unsigned int  _HopperSetting;/**< Hopper setting (退幣器設定) */
   unsigned int  _SoundVolume;/**< Sound Volume (音量設定) */
   unsigned int  _MaxKeyIn;/**< Max Key In (最大上分設定) */
   //Hidden
   unsigned int  _NeedReportAccount;/**< Need Report Account (是否為打碼台) */
   unsigned int  _ReportAccountDays;/**< Report Account Days (打碼間隔天數) */

   //Previous
   unsigned int  _previousCreditIn;/**< Previous Credit In (上分值) */
   unsigned int  _previousCreditOut;/**< Previous Credit Out (下分值) */
   unsigned int  _previousSingleLineMaxBet;/**< Previous Single line maximum bet (單線最大押分) */
   unsigned int  _previousSingleLineMinBet;/**< Previous Single line minimum bet (單線最小押分) */
   unsigned int  _previousSingleLineBetUnit;/**< Previous Single line bet unit (單線押注進分值) */

   //validate time
   time_t          _validate_time;/**< Validate Time */
   time_t          _validate_do_lock_time;/**< Validate Do Lock Time */
   time_t          _validate_previous_did_report_time;/**< Previous Did Report Time */

   /**
    * @brief Reset all member.
    */
   void Reset(){
	   _CreditIn                  = default_Credit_In;
	   _CreditOut                 = default_Credit_Out;
	   _SingleLineMaxBet          = default_SingleLineMaxBet;
	   _SingleLineMinBet          = default_SingleLineMinBet;
	   _CreditInLimit             = default_Credit_In_Limit;
	   _DoubleGameCreditLimit     = default_DoubleGameCreditLimit;
	   _DoubleDownOnOff           = default_DoubleGameOnOff;
	   _DirectDoubleDown          = default_Direct_DoubleGame;
	   _SingleLineBetUnit         = default_Single_line_bet_unit;
	   _HopperSetting             = default_Hopper_setting;
	   _PaySetting                = default_Pay_setting;
	   _SoundVolume               = default_Sound_Volume;
	   _MaxKeyIn                  = default_Max_Key_In;
	   //Hidden
	   _NeedReportAccount         = default_Need_Report_Account;
	   _ReportAccountDays         = default_Report_Account_Days;

	   //Previous
	   _previousCreditIn          = _CreditIn;
	   _previousCreditOut         = _CreditOut;
	   _previousSingleLineMaxBet  = _SingleLineMaxBet;
	   _previousSingleLineMinBet  = _SingleLineMinBet;
	   _previousSingleLineBetUnit = _SingleLineBetUnit;
   }

}SYSTEMSETTINGDATA;

/**
 * @brief Probability Setting Data Structure.
 */
typedef struct ProbabilitySettingData{
  unsigned int    _MachineID;/**< Machine ID (機台代碼) */
  unsigned int    _CoinValue;/**< Coin value (投退幣幣值) */
  unsigned int    _TicketValue;/**< Ticket value (彩票票值) */
  double           _MainProSetting;/**< Main game probability setting */
  double           _MainProSetting_Link;/**< Main game probability setting(Linking) */
  double           _DoubleProSetting;/**< Double down game probability setting */
  unsigned int    _GameLevel;/**< Game level (遊戲起伏) */
  unsigned int    _GameLevel_Link;/**< Game level(linking) (遊戲起伏) */
  unsigned int    _MinusDigit;/**< Minus Digit (縮位) */

  unsigned char   _GetJackpotType;/**< Type of getting JACKPOT(Auto/Manual) */

  unsigned int     D_ProSetting_Value;/**< Fixed probability value of double down game */
  double*           D_ProSetting;/**< Fixed probability pointer of double down game */

  //Previous
  double           _previousMainProSetting;/**< Previous Main game probability setting */
  double           _previousDoubleProSetting;/**< Previous Double down game probability setting */
  unsigned int    _previousCoinValue;/**< Previous Coin value (投退幣幣值) */

 /**
  * @brief Reset All Member Parameters.
  */
 void Reset(){
	 _MachineID                =  default_Machine_ID;
	 _CoinValue                =  default_Coin_Value;
	 _TicketValue              =  default_Ticket_Value;
	 _MainProSetting           =  default_Pro_MainPro;
	 _MainProSetting_Link      =  default_Pro_MainPro_Connect;
	 _DoubleProSetting         =  default_Pro_DoublePro;
	 _GameLevel                =  default_Game_Level;
	 _MinusDigit               =  default_Minus_Digit;
	 _GameLevel_Link           =  default_Game_Level;
	 _GetJackpotType           =  jac_AddToCredit;

	  D_ProSetting_Value=101;
	  D_ProSetting=&_DoubleProSetting;

	 //Previous
	  _previousMainProSetting = _MainProSetting;
	  _previousDoubleProSetting = _DoubleProSetting;
	  _previousCoinValue = _CoinValue;

 }
}PROBABILITYSETTINGDATA;

/**
 * @brief Connect Setting.
 */
typedef struct ConnectSetting{
	unsigned int  _ConnectOnOff;/**< Connect ON/OFF (連線功能) */
	unsigned char _ConnectID;/**< Connect ID (連線ID) */
	unsigned char _MaxConnectMount;/**< Max connect count (最大連線台數) */

	/**
	 * @brief Reset All Member Parameters.
	 */
	void Reset(){
		_ConnectOnOff     = default_Connect_OnOff;
		_ConnectID        = default_Connect_ID;
		_MaxConnectMount  = default_Max_id;
	}

}CONNECTSETTING;
/**
 * @brief Time Setting.
 */
typedef struct TimeSetting{
    unsigned int _year;
    unsigned int _month;
    unsigned int _date;
    unsigned int _week;
    unsigned int _hour;
    unsigned int _minute;

	/**
	 * @brief Reset All Member Parameters.
	 */
    void Reset(){
    	this->_year  = 0;
    	this->_month = 0;
    	this->_date  = 0;
    	this->_week  = 0;
    	this->_hour  = 0;
    	this->_minute= 0;
    }

}TIMESETTING;

/**
 * @brief Password Setting.
 */
typedef struct PasswordSetting{
	unsigned char m_StorePassword[4];/**< Store Password */
	unsigned char m_ManagerPassword[4];/**< Manager Password */

	/**
	 * @brief Constructor.
	 */
	PasswordSetting(void){
		this->Reset();
	}

	/**
	 * @brief Reset.
	 */
	void Reset(void){
		this->m_StorePassword[0]   = default_Store_Password_Digit_1;
		this->m_StorePassword[1]   = default_Store_Password_Digit_2;
		this->m_StorePassword[2]   = default_Store_Password_Digit_3;
		this->m_StorePassword[3]   = default_Store_Password_Digit_4;

		this->m_ManagerPassword[0] = default_Manager_Password_Digit_1;
		this->m_ManagerPassword[1] = default_Manager_Password_Digit_2;
		this->m_ManagerPassword[2] = default_Manager_Password_Digit_3;
		this->m_ManagerPassword[3] = default_Manager_Password_Digit_4;
	}

}PASSWORDSETTING;

/**
 * @brief Account Manager Menu Lock.
 */
typedef struct AccountManagerMenuLock{
	unsigned int m_locktime;/**< Lock Time (Minutes) */
	unsigned char m_lockFlag;/**< Lock Flag */

	/**
	 * @brief Reset.
	 */
	void Reset(void){
		this->m_locktime = 0;
		this->m_lockFlag = false;
	}

}ACCOUNTMANAGERMENULOCK;

/**
 * @brief Game All Setting Data.
 */
typedef struct GameAllSettingData{
	SYSTEMSETTINGDATA       systemSettingData;/**< System Setting Data */
	PROBABILITYSETTINGDATA  probabilitySettingData;/**< Probability Setting Data */
	CONNECTSETTING          connectSettingData;/**< Connect Setting Data */
	TIMESETTING             timeSettingData;/**< Time Setting Data */
	PASSWORDSETTING         passwordSetting;/**< Password Setting */
	ACCOUNTMANAGERMENULOCK  accountManagerMenuLock;/**< Account Manager Menu Menu Lock */

	/**
	 * @brief Constructor.
	 */
	GameAllSettingData(void){
		this->Reset();
	}

	/**
	 * @brief Reset.
	 */
	void Reset(void){
		this->systemSettingData.Reset();
		this->probabilitySettingData.Reset();
		this->connectSettingData.Reset();
		this->timeSettingData.Reset();
		this->passwordSetting.Reset();
		this->accountManagerMenuLock.Reset();
	}

}GAMEALLSETTINGDATA;

#endif /* GAMETYPE_H_ */
