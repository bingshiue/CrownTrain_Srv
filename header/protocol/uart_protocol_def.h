/*
 * @file uart_protocol_def.h
 * @brief define UART communication command.
 *
 */
#ifndef UART_PROTOCOL_DEF_H_
#define UART_PROTOCOL_DEF_H_

#define UART_DATA_LENGTH  16/**< UART Data Length */

/*---------- UART PROTOCOL DEFINE ----------*/
/*----- UART GROUP SEQUENCE -----*/
#define UG_SEQUENCE    0x01/**< Group SEQUENCE () */
    /*--- ACION DEFINE ---*/
    #define UA_SEQUENCE_REQUEST       0x01
    #define UA_SEQUENCE_REPLY         0x02
        /*- COMMAND DEFINE -*/
        #define UC_SEQUENCE_INIT_COMPLETE          0x01/**< Initial Completely */
        #define UC_SEQUENCE_LOCK_GAME              0x02/**< Lock Game */

/*----- UART GROUP VALIDATE -----*/
#define UG_VALIDATE    0x02/**< Group VALIDATE () */
    /*--- ACION DEFINE ---*/
    #define UA_VALIDATE_REQUEST       0x01
    #define UA_VALIDATE_REPLY         0x02
        /*- COMMAND DEFINE -*/
        #define UC_VALIDATE_READ                   0x01
        #define UC_VALIDATE_WRITE                  0x02

/*----- UART GROUP COIN -----*/
#define UG_COIN        0x03/**< Group COIN () */
    /*--- ACION DEFINE ---*/
    #define UA_COIN_REQUEST           0x01
    #define UA_COIN_REPLY             0x02
        /*- COMMAND DEFINE -*/
        #define UC_COIN_COININ                     0x01
        #define UC_COIN_COINOUT                    0x02
        #define UC_COINOUT_OVER                    0x03
        #define UC_COINOUT_OVER_REPLY              0x04

/*----- UART GROUP KEY -----*/
#define UG_KEY         0x04/**< Group KEY () */
    /*--- ACION DEFINE ---*/
    #define UA_KEY_SHORT_PRESS        0x01
    #define UA_KEY_LONG_PRESS         0x02
    #define UA_KEY_REGISTER_STATUS    0x03
        /*- COMMAND DEFINE -*/
		#define UC_KEY_NONE                        0x00/**< None */
		#define UC_KEY_START                       0x60/**< 開始鍵(全停鍵,得分鍵) */
		#define UC_KEY_STOP_1                      0x61/**< 停一鍵(半比倍鍵,左移鍵) */
		#define UC_KEY_STOP_2                      0x62/**< 停二鍵(比倍鍵) */
		#define UC_KEY_STOP_3                      0x63/**< 停三鍵(雙比倍鍵,右移鍵) */
		#define UC_KEY_BET_1                       0x64/**< 押注鍵(押1分) */
		#define UC_KEY_BET_LINE                    0x65/**< 押注鍵(押8條線) */
		#define UC_KEY_BET_MAX                     0x66/**< 最大押注鍵 */
		#define UC_KEY_PAY                         0x67/**< 退幣鍵 */
		#define UC_KEY_HELP                        0x68/**< 說明鍵 */
		#define UC_KEY_AUTO                        0x69/**< 自動鍵 */
		#define UC_KEY_OPENCREDIT                  0x6a/**< 上分鍵 */
		#define UC_KEY_CLEARCREDIT                 0x6b/**< 下分鍵 */
		#define UC_KEY_ACCOUNT                     0x6c/**< 查帳鍵 */
		#define UC_KEY_TEST                        0x6d/**< 測試鍵(設定鍵) */
		#define UC_KEY_START_MAXBET                0x99/**< 開始鍵+最大押注鍵 */
        #define UC_KEY_REGISTER_STATE              0x6e/**< 暫存器狀態 */


/*----- UART GROUP LAMP -----*/
#define UG_LAMP        0x05/**< Group LAMP () */
    /*--- ACION DEFINE ---*/
    #define UA_LAMP_REQUEST           0x01
    #define UA_LAMP_REPLY             0x02
        /*- COMMAND DEFINE -*/
        #define UC_LAMP_SETUP                      0x01/**<  */

/*----- UART GROUP MOTT -----*/
#define UG_MOTT        0x06/**< Group MOTT () */
    /*--- ACION DEFINE ---*/
    #define UA_MOTT_REQUEST           0x01
    #define UA_MOTT_REPLY             0x02
        /*- COMMAND DEFINE -*/
        #define UC_MOTT_SETUP                      0x01/**<  */

/*----- UART GROUP ERROR -----*/
#define UG_ERROR       0x07/**< Group ERROR () */
    /*--- ACION DEFINE ---*/
    #define UA_ERROR_OCCUR            0x01
    #define UA_ERROR_REPLY            0x02
        /*- COMMAND DEFINE -*/
		#define UC_ERROR_COIN_IN                   0x01/**< 投幣器錯誤 */
		#define UC_ERROR_COIN_OUT                  0x02/**< 卡幣 */
		#define UC_ERROR_NO_COIN                   0x03/**< 無幣 */
		#define UC_ERROR_CANCEL                    0x04/**< Error Cancel */

/*----- UART GROUP RESUME -----*/
#define UG_RESUME      0x08/**< Group RESUME () */
    /*--- ACION DEFINE ---*/
    #define UA_RESUM_REQUEST          0x01
    #define UA_RESUM_REPLY            0x02
        /*- COMMAND DEFINE -*/
/*----- UART GROUP HOPPER SETUP -----*/
#define UG_SETUP_HOPPER 0x09/**< Group SETUP HOPPER () */
    /*--- ACION DEFINE ---*/
    #define UA_SETUP_HOPPER_REQUEST   0x01
    #define UA_SETUP_HOPPER_REPLY     0x02
        /*- COMMAND DEFINE -*/
        #define UC_SETUP_HOPPER_NC                 0x01/**<  */
		#define UC_SETUP_HOPPER_NO                 0x02/**<  */

/*** UART DATA PACKET INDEX DEFINE ***/
#define UART_IDX_AES_KEY                        0/**< AES key */
#define UART_IDX_DATA_BEGIN                     1/**< Data begin */
#define UART_IDX_DATA_END                      16/**< Data end */
#define UART_IDX_DATA_LENGTH                   17/**< Data Length */
#define UART_IDX_GROUP                         18/**< Group */
#define UART_IDX_COMMAND                       19/**< Command */
#define UART_IDX_ACTION                        20/**< Action */
#define UART_IDX_RESERVE                       21/**< Reserve */
#define UART_IDX_CRC_HIGH_BYTE                 22/**< CRC high byte */
#define UART_IDX_CRC_LOW_BYTE                  23/**< CRC low byte */

/*** LAMP DEFINE ***/
//LAMP
#define UART_LAMP_START	((unsigned int)0x00000001)
#define UART_LAMP_PAY	    ((unsigned int)0x00000020)
#define UART_LAMP_HELP	    ((unsigned int)0x00000040)
#define UART_LAMP_BET1	    ((unsigned int)0x00000080)
#define UART_LAMP_MAXBET	((unsigned int)0x00000100)
#define UART_LAMP_STOP3	((unsigned int)0x00000200)
#define UART_LAMP_AUTO	    ((unsigned int)0x00001000)
#define UART_LAMP_STOP2	((unsigned int)0x00002000)
#define UART_LAMP_BET8	    ((unsigned int)0x00004000)
#define UART_LAMP_STOP1	((unsigned int)0x00008000)
#define UART_LAMP_ALL	    ((unsigned int)0x0000F3E1)

//LAMP MODE
#define UART_LAMPMODE_C     0x01/**< Light mode CANCEL */
#define UART_LAMPMODE_L     0x02/**< Light mode LIGHT  */
#define UART_LAMPMODE_B     0x04/**< Light mode BLINK  */

#endif /* UART_PROTOCOL_DEF_H_ */

#if 0
#ifndef UART_PROTOCOL_DEF_H_
#define UART_PROTOCOL_DEF_H_

/*** Transmission index define ***/
#define idx_data_begin                          1/**< data begin */
#define idx_data_end                           16/**< date end */
#define idx_length                             17/**< length */
#define idx_group                              18/**< group */
#define idx_command                            19/**< command */
#define idx_action                             20/**< action */
#define idx_crc_high_byte                      22/**< CRC high byte */
#define idx_crc_low_byte                       23/**< CRC low byte */


/*** GROUP DEFINE ***/
#define G_KEY_DEF          0x01/**< Group KEY */
#define G_DRAW_DEF         0x02/**< Group DRAW */
#define G_CONTROLLER_DEF   0x03/**< Group CONTROLLER */
#define G_SEQUENCE_DEF     0x04/**< Group SEQUENCE */
#define G_CREDIT_DEF       0x05/**< Group CREDIT */
#define G_PROBABILITY_DEF  0x06/**< Group PROBABILITY */
#define G_SETTING_DEF      0x07/**< Group SETTING */
#define G_SOUND_DEF        0x08/**< Group SOUND */
#define G_ERROR_DEF        0x09/**< Group ERROR */
#define G_ACC_DEF          0x0a/**< Group ACCOUNTING */
#define G_LIGHT_DEF        0x0b/**< Group LIGHT */
#define G_RESUME_DEF       0x0c/**< Group RESUME */
/********************/

/*** KEY ACTION KIND DEFINE ***/
#define A_PRESS_S_DEF        0x01/**< Action press key shortly */
#define A_PRESS_L_DEF        0x02/**< Action press key longly */
#define A_REGISTER_STATE     0x03/**< Action CGA key register state */
/******************************/

/*** DRAW ACTION KIND DEFINE ***/
#define A_DRAW_CREATE        0x01/**< Action create draw task */
#define A_DRAW_DELETE        0x02/**< Action delete draw task */
/*******************************/

/*** CONTROLLER ACTION KIND DEFINE ***/
#define A_CONTROLLER_CREATE  0x01/**< Action create controller task */
#define A_CONTROLLER_DELETE  0x02/**< Action delete controller task */
/*************************************/

/*** SEQUENCE ACTION KIND DEFINE ***/
#define A_SEQUENCE_REQUEST   0x01/**< Action request sequence */
#define A_SEQUENCE_REPLY     0x02/**< Action reply sequence */
/***********************************/

/*** CREDIT ACTION KIND DEFINE ***/
#define A_CREDIT_TRAN        0x01/**< Action transmit credit status */
#define A_CREDIT_REQ         0x02/**< Action request credit status */
#define A_CREDIT_REPLY       0x03/**< Action reply credit status */
/*********************************/

/*** PROBABILITY ACTION KIND DEFINE ***/
#define A_PROBABILITY_TRAN   0x01/**< Action transmit probability data */
#define A_PROBABILITY_REPLY  0x02/**< Action reply probability data */
/**************************************/

/*** SETTING ACTION KIND DEFINE ***/
#define A_SETTING_TRAN       0x01/**< Action transmit setting value */
#define A_SETTING_REQ        0x02/**< Action request setting value */
#define A_SETTING_SET        0x03/**< Action set setting value */
#define A_SETTING_REPLY      0x04/**< Action reply setting value */
/**********************************/

/*** SOUND ACTION DEFINE ***/
#define A_SOUND_TRAN         0x01/**< Action transmit sound track */

/*** ERROR ACTION DEFINE ***/
#define A_ERROR_TRAN         0x01/**< Action transmit error occur */
#define A_ERROR_REPLY        0x02/**< Action reply error occur */

/*** Accounting ACTION DEFINE ***/
#define A_ACC_TRAN           0x01/**< Action transmit accounting status */
#define A_ACC_REPLY          0x02/**< Action reply accounting status */

/*** LIGHT ACTION KIND DEFINE ***/
#define A_LIGHT_TRAN         0x01/**< Action transmit light status */
#define A_LIGHT_REPLY        0x02/**< Action reply light status */

/*** Resume ACTION KIND DEFINE ***/
#define A_RESUME_TRAN        0x01/**< Action transmit resume command */
#define A_RESUME_REPLY       0x02/**< Action reply resume command */

/*** KEY COMMAND DEFINE ***/
#define C_KEY_REGISTER_STATE 0x64/**< Action CGA key register status */

/*** SEQUENCE COMMAND DEFINE ***/
#define C_SEQUENCE_INIT_COMPLETE       0x01/**< Initial completely */
#define C_SEQUENCE_SOFTRESET           0x02/**< Software reset */
#define C_SEQUENCE_MAIN_SLOT_STOP      0x03/**< Main game slot stop */
#define C_SEQUENCE_MAIN_ONE_TURN_END   0x04/**< Main game one turn end */
#define C_SEQUENCE_DDOWN_ONE_TURN_SYNC 0x05/**< Double down one turn synchronize */
#define C_SEQUENCE_DDOWN_TO_MAIN_GAME  0x06/**< Double down to main game */
#define C_SEQUENCE_READY_GET_JACKPOT   0x07/**< Ready to get JACKPOT */
#define C_SEQUENCE_GET_JACKPOT_END     0x08/**< Get JACKPOT end */
#define C_SEQUENCE_CALL_ATTENDANCE     0x09/**< Call attendance */
#define C_SEQUENCE_CANCEL_ATTENDANCE   0x0a/**< Cancel attendance */
#define C_SEQUENCE_DDOWN_COMPUTE_SCORE 0x0b/**< Double down compute score then wait to exit */
#define C_SEQUENCE_JACKPOT_CLEAR_SCORE 0x0c/**< Clear(KeyOut) JACKPOT score if 'get JACKPOT' is setting to 'jac_PressKeyoutToClear' */
#define C_SEQUENCE_SHOW_ODDS           0x0d/**< Show odds */
#define C_SEQUENCE_ODDS_TO_MAINGAME    0x0e/**< Odds to main game */
#define C_SEQUENCE_ENTER_TO_ACC        0x0f/**< Main game to accounting */
#define C_SEQUENCE_END_ACC             0x10/**< End accounting then return to main game */
#define C_SEQUENCE_MAIN_GAME_ADD_OVER  0x11/**< Main Game add win to credit over */
#define C_SEQUENCE_DDOWN_GAME_ADD_OVER 0x12/**< Double down add win to credit over */
#define C_SEQUENCE_FAKE_HOMEPAGE       0x13/**< Display fake home page */
#define C_SEQUENCE_CANCEL_ENTER_DDOWN  0x14/**< Cancel enter to double down game */

#define C_SEQUENCE_ENTER_SET_TIME_MODE 0xa0/**< Enter Time Setting(First Boot or Ram error) */
#define C_SEQUENCE_SET_TIME_DONE       0xa1/**< Set Time Done(First Boot or Ram error) */
/*******************************/

/*** DRAW COMMAND DEFINE ***/
#define C_DRAW_CREATE_BATCH       0x02/**< Command batch creating draw task */
#define C_DRAW_DELETE_BATCH       0x03/**< Command batch deleting draw task */

/*** CONTROLLER COMMAND DEFINE ***/
#define C_CONTROLLER_CREATE_BATCH 0x01/**< Command batch creating controller task */
#define C_CONTROLLER_DELETE_BATCH 0x02/**< Command batch deleting controller task */

/*** CREDIT COMMAND DEFINE ***/
#define C_CREDIT_INIT                   0x01/**< Command initial credits */
#define C_CREDIT_KEYIN                  0x02/**< Command key-in */
#define C_CREDIT_BET                    0x03/**< Command bet */
#define C_CREDIT_ALL                    0x04/**< Command all information */
#define C_CREDIT_DDOWN_PLAY             0x05/**< Command double down play */
#define C_CREDIT_DDOWN_REQUEST_RESULT   0x06/**< Command double down request result */
#define C_CREDIT_DDOWN_REPLY_RESULT     0x07/**< Command double down reply result */
#define C_CREDIT_KEYOUT_SYNC            0x08/**< Command key-out synchronize */
#define C_CREDIT_SYNC                   0x09/**< Command credit synchronize */
#define C_CREDIT_JP_SYNC                0x0a/**< Command JOCKPOT synchronize */
#define C_CREDIT_COIN_IN                0x0b/**< Command coin-in */
#define C_CREDIT_EXIT_ACC_SYNC          0x0c/**< Command exit accounting mode synchronize */
#define C_CREDIT_JP_DATA                0x0d/**< Command synchronize JOCKPOT data */
/*****************************/

/*** PROBABILITY COMMAND DEFINE ***/
#define C_PROBABILITY_9ITEM        0x01/**< Command probability 9 item */
#define C_PROBABILITY_DDOWN_DEALER 0x02/**< Command double down dealer */
#define C_PROBABILITY_DDOWN_3ITEM  0x03/**< Command double down 3 item */

/*** SETTING COMMAND DEFINE ***/
#define C_SETTING_SYSTEM          0x01/**< Command system setting */
#define C_SETTING_PROBABILITY     0x02/**< Command probability setting */
#define C_SETTING_BONUS           0x03/**< Command bonus setting */
#define C_SETTING_LINK            0x04/**< Command link setting */
#define C_SETTING_TIME            0x05/**< Command time setting */
#define C_SETTING_SYSTEM_2        0x10/**< Command system setting 2 */

#define C_SETTING_SYSTEM_LAST        0x06/**< Command last system setting */
#define C_SETTING_PROBABILITY_LAST   0x07/**< Command last probability setting */
#define C_SETTING_BONUS_LAST         0x08/**< Command last bonus setting */
#define C_SETTING_LINK_LAST          0x09/**< Command last link setting */
#define C_SETTING_SYSTEM_LAST_2      0x11/**< Command last system setting 2 */

#define C_SETTING_SYSTEM_DEFAULT        0x0a/**< Command default system setting */
#define C_SETTING_PROBABILITY_DEFAULT   0x0b/**< Command default probability setting */
#define C_SETTING_BONUS_DEFAULT         0x0c/**< Command default bonus setting */
#define C_SETTING_LINK_DEFAULT          0x0d/**< Command default link setting */
#define C_SETTING_PASSWORD              0x0e/**< Command default password */
#define C_SETTING_CLEAR_CURRENT_OPER    0x0f/**< Command default clear current operation record */
#define C_SETTING_SYSTEM_DEFAULT_2      0x12/**< Command default system setting 2 */

/*** SOUND COMMAND DEFINE ***/
#define C_SOUND_PLAY              0x01/**< Command play sound */
#define C_SOUND_STOP              0x02/**< Command stop sound */

/*** ERROR COMMAND DEFINE ***/
#define C_ERROR_HAPPEN            0x01/**< Command error happen */
#define C_ERROR_CANCEL            0x02/**< Command cancel error */

/*** Accounting COMMAND DEFINE ***/
#define C_ACC_OPER_CURRENT_SLOT           0x01/**< Command current slot record */
#define C_ACC_OPER_PREVIOUS_SLOT          0x02/**< Command previous slot record */
#define C_ACC_OPER_CURRENT_DDOWN_1        0x03/**< Command current double down record */
#define C_ACC_OPER_CURRENT_DDOWN_2        0x04/**< Command current double down record 2 */
#define C_ACC_OPER_PREVIOUS_DDOWN_1       0x05/**< Command previous double down record */
#define C_ACC_OPER_PREVIOUS_DDOWN_2       0x06/**< Command previous double down record 2 */
#define C_ACC_OPER_CURRENT_TOTAL_INOUT    0x07/**< Command current total in/out */
#define C_ACC_OPER_PREVIOUS_TOTAL_INOUT   0x08/**< Command previous total in/out */

#define C_ACC_SLOT_RECORD_1               0x09/**< Command slot record 1 */
#define C_ACC_SLOT_RECORD_2               0x0a/**< Command slot record 2 */

#define C_ACC_DDOWN_RECORD_1              0x0b/**< Command double down game record 1 */
#define C_ACC_DDOWN_RECORD_2              0x0c/**< Command double down game record 2 */

#define C_ACC_JACKPOT_RECORD_1            0x0d/**< Command JOCKPOT record 1 */
#define C_ACC_JACKPOT_RECORD_2            0x0e/**< Command JOCKPOT record 2 */

#define C_ACC_LAST_RECORD_1               0x0f/**< Command last game record 1 */
#define C_ACC_LAST_RECORD_2               0x10/**< Command last game record 2 */
#define C_ACC_LAST_RECORD_3               0x11/**< Command last game record 3 */
#define C_ACC_LAST_RECORD_4               0x12/**< Command last game record 4 */
#define C_ACC_LAST_RECORD_5               0x13/**< Command last game record 5 */
#define C_ACC_LAST_RECORD_6               0x14/**< Command last game record 6 */
#define C_ACC_LAST_RECORD_7               0x15/**< Command last game record 7 */

#define C_ACC_PREVIOUS_RECORD_1           0x16/**< Command previous game record 1 */
#define C_ACC_PREVIOUS_RECORD_2           0x17/**< Command previous game record 2 */
#define C_ACC_PREVIOUS_RECORD_3           0x18/**< Command previous game record 3 */
#define C_ACC_PREVIOUS_RECORD_4           0x19/**< Command previous game record 4 */
#define C_ACC_PREVIOUS_RECORD_5           0x1a/**< Command previous game record 5 */
#define C_ACC_PREVIOUS_RECORD_6           0x1b/**< Command previous game record 6 */
#define C_ACC_PREVIOUS_RECORD_7           0x1c/**< Command previous game record 7 */

#define C_ACC_LINE_RECORD_1               0x1d/**< Command line record 1 */
#define C_ACC_LINE_RECORD_2               0x1e/**< Command line record 2 */
#define C_ACC_LINE_RECORD_3               0x1f/**< Command line record 3 */

#define C_ACC_SETTING_RECORD_1            0x20/**< Command setting record 1 */
#define C_ACC_SETTING_RECORD_2            0x21/**< Command setting record 2 */
#define C_ACC_SETTING_RECORD_3            0x22/**< Command setting record 3 */
#define C_ACC_SETTING_RECORD_4            0x23/**< Command setting record 4 */
#define C_ACC_SETTING_RECORD_5            0x24/**< Command setting record 5 */

#define C_ACC_SETTING_RECORD_CLAER        0x25/**< Command clear setting record */

#define C_ACC_SETTING_SAVE                0x26/**< Command save */
#define C_ACC_SETTING_DEFAULT_SETTING     0x27/**< Command restore default setting value */
#define C_ACC_SETTING_SAVE_NEW_PASSWORD   0x28/**< Command save new password */

#define C_ACC_ERROR_RECORD_1              0x29/**< Command error record 1 */
#define C_ACC_ERROR_RECORD_2              0x2a/**< Command error record 2 */
#define C_ACC_ERROR_RECORD_3              0x2b/**< Command error record 3 */
#define C_ACC_ERROR_RECORD_4              0x2c/**< Command error record 4 */

#define C_ACC_DEBUG_SECTION_REC_1         0x2d/**< Command debug section record 1 */
#define C_ACC_DEBUG_SECTION_REC_2         0x2e/**< Command debug section record 2 */
#define C_ACC_DEBUG_CGA_PRIVATE_DATA      0x2f/**< Command get CGA's private data */

/*** Light COMMAND DEFINE ***/
#define C_LIGHT_SET_STATUS                0x01/**< Command set light status */

/*** Resume COMMAND DEFINE ***/
#define C_RESUME_MG_CREDITS_STATUS        0x01/**< Command main game resume credits status */
#define C_RESUME_MG_STOP_ITEM             0x02/**< Command main game resume stop item */
#define C_RESUME_MG_JP_DATA               0x03/**< Command main game resume JOCKPOT data */
#define C_RESUME_MG_JP_VALUE              0x04/**< Command main game resume JOCKPOT value */
#define C_RESUME_MG_STEP                  0x05/**< Command main game resume last step */
#define C_RESUME_MG_DONE                  0x06/**< Command main game resume done */

#define C_RESUME_DG_CREDITS_STATUS        0x07/**< Command double down game resume credits status */
#define C_RESUME_DG_STOP_ITEM             0x08/**< Command double down game resume stop item */
#define C_RESUME_DG_PARAMETER             0x09/**< Command double down game resume parameters */
#define C_RESUME_DG_PARAMETER_2           0x0a/**< Command double down game resume parameters 2 */
#define C_RESUME_DG_PARAMETER_3           0x0b/**< Command double down game resume parameters 3 */
#define C_RESUME_DG_STEP                  0x0c/**< Command double down game resume step */
#define C_RESUME_DG_DONE                  0x0d/**< Command double down game resume done */

/*** KEY DEFINE ***/
#define event_key_bet                        0x00/**< Event bet key pressed */
#define event_key_max_bet                    0x01/**< Event max bet key pressed */
#define event_key_stop4                      0x02/**< Event stop 4 key pressed */
#define event_key_stop5                      0x03/**< Event stop 5 key pressed */
#define event_key_stop1                      0x04/**< Event stop 1 key pressed */
#define event_key_stop2                      0x05/**< Event stop 2 key pressed */
#define event_key_stop3                      0x06/**< Event stop 3 key pressed */
#define event_key_start                      0x07/**< Event start key pressed */
#define event_key_score                      0x08/**< Event score key pressed */
#define event_key_keyout                     0x09/**< Event key-out key pressed */
#define event_key_keyin                      0x0a/**< Event key-in key pressed */
#define event_key_acc                        0x0b/**< Event accounting key pressed */
#define event_key_set                        0x0c/**< Event set key pressed */
#define event_key_pay                        0x0d/**< Event pay key pressed */
#define event_mul_key_stop1_stop2_stop3      0x0e/**< Event stop 1 + stop 2 + stop 3 key pressed together */
#define event_key_call_attendance            0x0f/**< Event call attendance key pressed */
#define event_key_homepage                   0x10/**< Event home-page key pressed(F12) */
#define event_key_null                       0x63/**< Event NULL */

/*** Music Track Define ***/
#define Mus_coin		      0/**< Track coin */
#define Mus_maxcoin		  1/**< Track max coin */
#define Mus_bet			  2/**< Track bet */
#define Mus_activegame	      3/**< Track active game*/
#define Mus_push		      4/**< Track push */
#define Mus_winno1		      5/**< Track winning effect 1 */
#define Mus_holdbotton	      6/**< Track holdbotton */
#define Mus_gamebotton	      7/**< Track gamebotton */
#define Mus_bigwin		      8/**< Track big win */
#define Mus_indouble	      9/**< Track into double down */
#define Mus_winhand		 10/**< Track win hand */
#define Mus_error		     11/**< Track error */
#define Mus_open		     12/**< Track open */
#define Mus_attendant	     13/**< Track call attendance */
#define Mus_d_reel_spin     14/**< Track double down slot reel effect */
#define Mus_testect		 15/**< Track testect */
#define Mus_demo		     16/**< Track DEMO */
#define Mus_goldfish	     17/**< Track gold fish */
#define Mus_joker_nouse     18/**< Track joker no using */
#define Mus_slot_claasic    19/**< Track slot reel effect classic */
#define Mus_onuse		     20/**< Track no using */
#define Mus_slot		     21/**< Track slot reel */
#define Mus_slotstop	     22/**< Track slot stop */
#define Mus_winno3		     23/**< Track winning effect 3 */
#define Mus_winno2		     24/**< Track winning effect 2 */
#define Mus_winno4		     25/**< Track winning effect 4 */
#define Mus_winno5		     26/**< Track winning effect 5 */
#define Mus_clear		     27/**< Track clear */
#define Mus_red7		     28/**< Track red 7 effect */
#define Mus_red7_fw1	     29/**< Track red 7 fire effect 1 */
#define Mus_red7_fw2	     30/**< Track red 7 fire effect 2 */
#define Mus_red7_fw3	     31/**< Track red 7 fire effect 3 */
#define Mus_blue7		     32/**< Track blue 7 effect */
#define Mus_joker		     33/**< Track joker */
#define Mus_jackpot         34/**< Track JOCKPOT */
#define Mus_score		     35/**< Track score */
#define Mus_pay_out_over_49 36/**< Track pay out over 49 */
#define Mus_card_open       37/**< Track card open */
#define Mus_home            38/**< Track home-page */

/*** Light Key & Mode Define ***/
#define L_START    ((unsigned long)0x0001)/**< start key light */
#define L_STOP1	((unsigned long)0x0002)/**< stop 1 key light */
#define L_STOP5	((unsigned long)0x0004)/**< stop 5 key light */
#define L_STOP2	((unsigned long)0x0008)/**< stop 2 key light */
#define L_BET		((unsigned long)0x0010)/**< bet key light */
#define L_STOP3	((unsigned long)0x0020)/**< stop 3 key light */
#define L_MAXBET	((unsigned long)0x0040)/**< max bet key light */
#define L_STOP4	((unsigned long)0x0080)/**< stop 4 key light */
#define L_HELP		((unsigned long)0x0100)/**< help key light */
#define L_PAY      ((unsigned long)0x0200)/**< pay key light */
#define L_ALL		((unsigned long)0x03FF)/**< all */

#define LAMPMODE_N             0/**< light mode N */
#define LAMPMODE_C             1/**< light mode C */
#define LAMPMODE_L             2/**< light mode L */
#define LAMPMODE_B             4/**< light mode B */
#define LAMPMODE_X             8/**< light mode X */
#define LAMPMODE_CT           16/**< light mode CT */
#define LAMPMODE_LT           32/**< light mode LT */
#define LAMPMODE_BT           64/**< light mode BT */
#define LAMPMODE_XT          128/**< light mode XT */

/*** CGA's Main Game Step ***/
#define state_MainGame_Standby                  0xff/**< Main Game Standby Step. */
#define state_MainGame_ReStart                  0xfe/**< Back to main game from double down game. */
#define state_MainGame_ReStart_After_Add_Credit 0xfd/**< After add win this step will redirect running step to main_step_StandBy. */
#define state_MainGame_Init                     0xfc/**< Initialize with RISC. */
#define state_MainGame_Probability              0x60/**< Control probability. */
#define state_MainGame_PreScrollStart           0x70/**< Prepare for slot starting */
#define state_MainGame_ScrollStart              0x61/**< Scroll start */
#define state_MainGame_ScrollStop               0x62/**< Scroll stop */
#define state_MainGame_ComputeScroll            0x63/**< Compute scroll */
#define state_MainGame_WaitNoWin                0x64/**< No win wait for input. */
#define state_MainGame_ScrollAnime              0x65/**< Scroll animation */
#define state_MainGame_WaitIfWin                0x66/**< Win check double game style. */
#define state_MainGame_Add_Win_To_Credit        0x67/**< Add win to credits. */
#define state_MainGame_Wait_Add_Win_Over        0x85/**< Wait add win action over */
#define state_MainGame_GetJackpot               0x68/**< Get JACKPOT. */
#define state_MainGame_CallAttend               0x69/**< Call Attend. */
#define state_MainGame_WaitScrollStop           0x80/**< Wait RISC scroll stop. */
#define state_MainGame_WaitOneTurnEnd           0x81/**< Wait RISC one turn end. */
#define state_MainGame_WaitJackpot              0x82/**< Wait for RISC enter get JACKPOT mode. */
#define state_MainGame_WaitJackpotEnd           0x83/**< Wait RISC GET JACKPOT End */
#define state_MainGame_ShowOdds                 0x84/**< Show Odds */

/*** CGA's Double Game Step ***/
#define D_CASE_WAIT_PLAY		        2/**< Wait play double up */
#define D_CASE_WAIT_REPLY_PLAY        17/**< Wait reply of play command */
#define D_CASE_START			        3/**< Slot start */
#define D_CASE_SLOTGO			        4/**< Slot go */
#define D_CASE_WAIT_REPLY_DEALER      18/**< Wait reply of C_PROBABILITY_DDOWN_DEALER */
#define D_CASE_DEALSTOP			    5/**< Dealer stop */
#define D_SELECT0	                    6/**< Select 0 */
#define D_CASE_WAIT_REPLY_3ITEM       19/**< Wait reply of C_PROBABILITY_DDOWN_3ITEM */
#define D_SELECT1	                    7/**< Select 1 */
#define D_SELECT2	                    8/**< Select 2 */
#define D_CASE_COUNTWIN			    9/**< Count win */
#define D_CASE_WAIT_REQUEST_RESULT    20/**< Wait for request one turn result */
#define D_ANIME		               10/**< Animation */
#define D_CHMOD		               11/**< Change mode */
#define D_CASE_END_NORMAL		       13/**< end normally */
#define D_CASE_OVER_COLLECT		   14/**< over max win collection */
#define D_CASE_SCORE_F			       15/**< Score F(Final ?) */
#define D_CASE_SCORE_B			       16/**< Score B(?) */
#define D_CASE_MOVEWIN0			   60/**< Get win 0 */
#define D_CASE_MOVEWIN1			   61/**< Get win 1 */
#define D_CASE_DELAY_WAITEND	       62/**< Delay */
#define D_CASE_WAIT_END			   63/**< Wait RISC end */
#define D_CASE_WAIT_ADD_WIN_OVER      64/**< Wait RISC add winning score end */
#define D_CASE_EXIT				   99/**< Exit */

#endif /* UART_PROTOCOL_DEF_H_ */
#endif
