/**
 * @file gameDefine.h
 * @brief define game header.
 *
 */

#ifndef GAMEDEFINE_H_
#define GAMEDEFINE_H_

#include "../preprocessor.h"

#ifndef __arm__
//#define __SAVE_DATA_DIR_PATH__                  "data/"
//#define __SAVE_DATA_FILE_NAME__                 "data/save"
#define __SAVE_DATA_DIR_1_PATH__                "data1/"
#define __SAVE_DATA_DIR_2_PATH__                "data2/"
#define __SAVE_DATA_FILE_NAME__                 "save"
#else
#ifndef __fsl__
//#define __SAVE_DATA_DIR_PATH__                  "/nand2/data/"
#define __SAVE_DATA_DIR_1_PATH__                "/nand2/data1/"
#define __SAVE_DATA_DIR_2_PATH__                "/nand2/data2/"
//#define __SAVE_DATA_FILE_NAME__                 "/nand2/data/save"
#define __SAVE_DATA_FILE_NAME__                 "save"
#else
//#define __SAVE_DATA_DIR_PATH__                  "data/"
#define __SAVE_DATA_DIR_1_PATH__                "data1/"
#define __SAVE_DATA_DIR_2_PATH__                "data2/"
//#define __SAVE_DATA_FILE_NAME__                 "data/save"
#define __SAVE_DATA_FILE_NAME__                 "save"
#endif
#endif

#define GETY(Y) (Y*1.333 + 1)

/***** Setting Data Index Count *****/
#define SYSTEM_SETTING_TOTAL_INDEX_COUNT            22/**< System setting total index count */
#define PROBABILITY_SETTING_TOTAL_INDEX_COUNT        8/**< Probability setting total index count */
#define REWARDS_SETTING_TOTAL_INDEX_COUNT            6/**< Rewards setting total index count */
#define LINK_SETTING_TOTAL_INDEX_COUNT               2/**< link setting total index count */
#define TIME_SETTING_TOTAL_INDEX_COUNT               6/**< Time setting total index count */

/***** System Setting Data Default Value *****/

#define default_Credit_In                         1000/**< Default credit in */
#define default_Credit_Out                        1000/**< Default credit out */
#define default_SingleLineMaxBet                    50/**< Default single line maximum bet */
#define default_SingleLineMinBet                     1/**< Default single line minimum bet */
#define default_Single_line_bet_unit                 5/**< Default single line bet Unit */
#define default_Credit_In_Limit                 500000/**< Default credit in limit */
#define default_DoubleGameCreditLimit           100000/**< Default double down credit limit */
#define default_DoubleGameOnOff                 Enable/**< Default double down On/Off */
#define default_Direct_DoubleGame              Disable/**< Default enter to double down directly */
#define default_Pay_setting         Pay_setting_hopper/**< Default pay setting */
#define default_Hopper_setting               Hopper_NC/**< Default hopper NC/NO */
#define default_Sound_Volume                         1/**< Default Sound Volume */
#define default_Max_Key_In                       50000/**< Default Max Key In */

//Hidden
#define default_Need_Report_Account             Enable/**< Default Need Report Account */
#define default_Report_Account_Days                 14/**< Default Report Account Days */

/***** Probability Setting Data Default Value *****/

#define default_Machine_ID                           1/**< Default Machine ID */
#define default_Coin_Value                         100/**< Default coin value */
#define default_Ticket_Value                      2000/**< Default ticket value */
#define default_Pro_MainPro                       97.5/**< Default main game probability */
#define default_Pro_MainPro_Connect                 98/**< Default main game probability(link function is on) */
#define default_Pro_DoublePro                       97/**< Default double game probability */
#define default_Game_Level           Game_Level_Middle/**< Default game level */
#define default_Minus_Digit                          1/**< Default minus digit */

/*** Connect Setting Data Default Value ***/

#define default_Connect_OnOff              Connect_OFF/**< Default Connect function On/Off */
#define default_Connect_ID                           1/**< Default Connect ID */
#define default_Max_id                              10/**< Default Max link ID */

/*** Password Setting Default Value ***/
#define default_Store_Password_Digit_1       1
#define default_Store_Password_Digit_2       2
#define default_Store_Password_Digit_3       1
#define default_Store_Password_Digit_4       2

#define default_Manager_Password_Digit_1     1
#define default_Manager_Password_Digit_2     1
#define default_Manager_Password_Digit_3     1
#define default_Manager_Password_Digit_4     1

/*** width & height of each frame ***/
#define SINGLE_FRAME_WIDTH           180/**< Width of single frame */
#define SINGLE_FRAME_HEIGHT          140/**< Height of single frame */
#define DEF_OFFSET_RECT_Y             60/**< Default offset of Y axis */

/*** ERROR TYPE DEFINE ***/
#define ERR_NONE	             0/**< None error */
#define ERR_COIN_IN	         1/**< Coin-in error */
#define ERR_COIN_OUT	         2/**< Coin-out error */
#define ERR_NO_COIN   	         3/**< No coin in coin-in */
#define ERR_SYS_OVER	         4/**< System Over */
#define ERR_DOUBLE_OVER	     5/**< Double Down Over */
#define ERR_MEMORY	             6/**< Memory error */
#define ERR_LINK_ID             7/**< Link id error */
#define ERR_LINK_COINVALUE      8/**< Link coin value error */
#define ERR_NO_LINK             9/**< Link break */
#define ERR_COIN_IN_LIMIT      10/**< Coin in limit error */
#define ERR_KEY_IN_LIMIT       11/**< Key in limit error */
#define ERR_HOPPER_MAX_PAY     12/**< Hopper max pay error */

/*** Password key input mapping define ***/
#define PWD_STOP1               1/**< Password of stop 1 key */
#define PWD_STOP2               2/**< Password of stop 2 key */
#define PWD_STOP3               3/**< Password of stop 3 key */
#define PWD_STOP4               4/**< Password of stop 4 key */
#define PWD_STOP5               5/**< Password of stop 5 key */
#define PWD_BIG                 6/**< Password of big key */
#define PWD_BEBA                7/**< Password of double up key */
#define PWD_SMALL               8/**< Password of small key */
#define PWD_START               9/**< Password of start key */
#define PWD_BET                 0/**< Password of bet key */

/***** Idol Information Appear Time *****/
#define IDLEINFO_APPEAR_TIME     90000/**< Time of idle appear */

/***** Main Game Slot frame position *****/
#define SLOT_1_X   242/**< main game's slot 1 x position */
#define SLOT_1_Y   GETY(67)/**< main game's slot 1 y position */

#define SLOT_2_X   432/**< main game's slot 2 x position */
#define SLOT_2_Y   GETY(67)/**< main game's slot 2 y position */

#define SLOT_3_X   622/**< main game's slot 3 x position */
#define SLOT_3_Y   GETY(67)/**< main game's slot 3 y position */

#define SLOT_4_X   242/**< main game's slot 4 x position */
#define SLOT_4_Y   GETY(217)/**< main game's slot 4 y position */

#define SLOT_5_X   432/**< main game's slot 5 x position */
#define SLOT_5_Y   GETY(217)/**< main game's slot 5 y position */

#define SLOT_6_X   622/**< main game's slot 6 x position */
#define SLOT_6_Y   GETY(217)/**< main game's slot 6 y position */

#define SLOT_7_X   242/**< main game's slot 7 x position */
#define SLOT_7_Y   GETY(367)/**< main game's slot 7 y position */

#define SLOT_8_X   432/**< main game's slot 8 x position */
#define SLOT_8_Y   GETY(367)/**< main game's slot 8 y position */

#define SLOT_9_X   622/**< main game's slot 9 x position */
#define SLOT_9_Y   GETY(367)/**< main game's slot 9 y position */

#define SLOT_AWARD_FRAME_1_POS_X 234
#define SLOT_AWARD_FRAME_1_POS_Y GETY(59)

#define SLOT_AWARD_FRAME_2_POS_X 424
#define SLOT_AWARD_FRAME_2_POS_Y GETY(59)

#define SLOT_AWARD_FRAME_3_POS_X 614
#define SLOT_AWARD_FRAME_3_POS_Y GETY(59)

#define SLOT_AWARD_FRAME_4_POS_X 234
#define SLOT_AWARD_FRAME_4_POS_Y GETY(209)

#define SLOT_AWARD_FRAME_5_POS_X 424
#define SLOT_AWARD_FRAME_5_POS_Y GETY(209)

#define SLOT_AWARD_FRAME_6_POS_X 614
#define SLOT_AWARD_FRAME_6_POS_Y GETY(209)

#define SLOT_AWARD_FRAME_7_POS_X 234
#define SLOT_AWARD_FRAME_7_POS_Y GETY(359)

#define SLOT_AWARD_FRAME_8_POS_X 424
#define SLOT_AWARD_FRAME_8_POS_Y GETY(359)

#define SLOT_AWARD_FRAME_9_POS_X 614
#define SLOT_AWARD_FRAME_9_POS_Y GETY(359)

//Main Game Each Line & Each Item Wager Information
#define LINE_1_WAGER_INFO_X    207/**< main game's line 1 wager x position  */
#define LINE_1_WAGER_INFO_Y    291/**< main game's line 1 wager y position */

#define LINE_2_WAGER_INFO_X    207/**< main game's line 3 wager x position */
#define LINE_2_WAGER_INFO_Y    142/**< main game's line 3 wager y position */

#define LINE_3_WAGER_INFO_X    207/**< main game's line 2 wager x position */
#define LINE_3_WAGER_INFO_Y    417/**< main game's line 2 wager y position */

#define LINE_4_WAGER_INFO_X    207/**< main game's line 5 wager x position */
#define LINE_4_WAGER_INFO_Y     59/**< main game's line 5 wager y position */

#define LINE_5_WAGER_INFO_X    207/**< main game's line 4 wager x position */
#define LINE_5_WAGER_INFO_Y    503/**< main game's line 4 wager y position */

#define LINE_6_WAGER_INFO_X    366/**< main game's line 6 wager x position */
#define LINE_6_WAGER_INFO_Y     23/**< main game's line 6 wager y position */

#define LINE_7_WAGER_INFO_X    555/**< main game's line 7 wager x position */
#define LINE_7_WAGER_INFO_Y     23/**< main game's line 7 wager y position */

#define LINE_8_WAGER_INFO_X    745/**< main game's line 8 wager x position */
#define LINE_8_WAGER_INFO_Y     23/**< main game's line 8 wager y position */

#define ITEM_1_WAGER_INFO_X     994/**< main game's item 1 wager x position */
#define ITEM_1_WAGER_INFO_Y     681/**< main game's item 1 wager y position */

#define ITEM_2_WAGER_INFO_X     994/**< main game's item 2 wager x position */
#define ITEM_2_WAGER_INFO_Y     604/**< main game's item 2 wager y position */

#define ITEM_3_WAGER_INFO_X     994/**< main game's item 3 wager x position */
#define ITEM_3_WAGER_INFO_Y     527/**< main game's item 3 wager y position */

#define ITEM_4_WAGER_INFO_X     994/**< main game's item 4 wager x position */
#define ITEM_4_WAGER_INFO_Y     451/**< main game's item 4 wager y position */

#define ITEM_5_WAGER_INFO_X     994/**< main game's item 5 wager x position */
#define ITEM_5_WAGER_INFO_Y     374/**< main game's item 5 wager y position */

#define ITEM_6_WAGER_INFO_X     994/**< main game's item 6 wager x position */
#define ITEM_6_WAGER_INFO_Y     297/**< main game's item 6 wager y position */

#define ITEM_7_WAGER_INFO_X     994/**< main game's item 7 wager x position */
#define ITEM_7_WAGER_INFO_Y     220/**< main game's item 7 wager y position */

#define ITEM_8_WAGER_INFO_X     994/**< main game's item 8 wager x position */
#define ITEM_8_WAGER_INFO_Y     143/**< main game's item 8 wager y position */

/***** Special Game Slot frame position *****/
#define SP_SLOT_1_X   253/**< special game's slot 1 x position */
#define SP_SLOT_1_Y   GETY(257)/**< special game's slot 1 y position */

#define SP_SLOT_2_X   383/**< special game's slot 2 x position */
#define SP_SLOT_2_Y   GETY(257)/**< special game's slot 2 y position */

#define SP_SLOT_3_X   514/**< special game's slot 3 x position */
#define SP_SLOT_3_Y   GETY(257)/**< special game's slot 3 y position */

#define SP_SLOT_4_X   644/**< special game's slot 4 x position */
#define SP_SLOT_4_Y   GETY(257)/**< special game's slot 4 y position */

#define SP_SLOT_AWARD_FRAME_1_POS_X 247
#define SP_SLOT_AWARD_FRAME_1_POS_Y GETY(252)

#define SP_SLOT_AWARD_FRAME_2_POS_X 377
#define SP_SLOT_AWARD_FRAME_2_POS_Y GETY(252)

#define SP_SLOT_AWARD_FRAME_3_POS_X 508
#define SP_SLOT_AWARD_FRAME_3_POS_Y GETY(252)

#define SP_SLOT_AWARD_FRAME_4_POS_X 638
#define SP_SLOT_AWARD_FRAME_4_POS_Y GETY(252)

/* Account Mode Key Number define */
#define ACC_KEY_NUM_START        0/**< 開始鍵(全停鍵,得分鍵) */
#define ACC_KEY_NUM_STOP_1       1/**< 停一鍵(半比倍鍵,左移鍵) */
#define ACC_KEY_NUM_STOP_2       2/**< 停二鍵(比倍鍵) */
#define ACC_KEY_NUM_STOP_3       3/**< 停三鍵(雙比倍鍵,右移鍵) */
#define ACC_KEY_NUM_BET_1        4/**< 押注鍵(押1分) */
#define ACC_KEY_NUM_BET_LINE     5/**< 押注鍵(押8條線) */
#define ACC_KEY_NUM_BET_MAX      6/**< 最大押注鍵 */
#define ACC_KEY_NUM_PAY          7/**< 退幣鍵 */
#define ACC_KEY_NUM_HELP         8/**< 說明鍵 */
#define ACC_KEY_NUM_AUTO         9/**< 自動鍵 */

#endif /* GAMEDEFINE_H_ */
