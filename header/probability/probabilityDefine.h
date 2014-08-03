/*
 * @file probabilityDefine.h
 * @brief Define probability macro.
 *
 */

#ifndef PROBABILITYDEFINE_H_
#define PROBABILITYDEFINE_H_

#include "../preprocessor.h"

/*** Genuine Compute Score Style or Not ***/
#ifdef Genuine_Compute_Score
	#define HaveMixCheckBar(J,A,B,C)   (J>0)  ? true : true/**< Check have Mix BAR */

	#define HaveMixCheck7(J,A,B)       (J>0)  ? true : true/**< Check have Mix 7 */
#else
	#define HaveMixCheckBar(J,A,B,C)   (J>0)  ? true : \
									    (A==0) ? (B==0) ? false : (C==0) ? false : true  :  \
									    (B==0) ? (C==0) ? false : true : true/**< Check have Mix BAR */

	#define HaveMixCheck7(J,A,B)       (J>0)  ? true : \
									    (A&&B) ? true : false/**< Check have Mix 7 */
#endif

/**< Frame Item Define(SAIYUUKI type) */
#define ITEM_UNKNOW              0
#define ITEM_CHERRY              1
#define ITEM_ORANGE              2
#define ITEM_MANGO               3
#define ITEM_BELL                4
#define ITEM_WATERMELON          5
#define ITEM_BAR_YELLOW          6
#define ITEM_BAR_RED             7
#define ITEM_BAR_BLUE            8
#define ITEM_WILD                9/**< Wild */
//#define ITEM_SEVEN               9
//#define ITEM_WILD               10/**< Wild */

//Frame Random Define
#define ran_Item_Blank         0/**< Random indicator of Blank */
#define ran_Item_One_Bar       1/**< Random indicator of One Bar */
#define ran_Item_Two_Bar       2/**< Random indicator of Two Bar */
#define ran_Item_Three_Bar     3/**< Random indicator of Three Bar */
#define ran_Item_Red_7         4/**< Random indicator of Red 7 */
#define ran_Item_Blue_7        5/**< Random indicator of Blue 7 */
#define ran_Item_Joker         6/**< Random indicator of Joker */
//

//Line Bingo Type Define
#define lb_None                0/**< Line award type none */
#define lb_Mix_Bar_Straight    1/**< Line award type Mix Bar Straight */
#define lb_One_Bar_Straight    2/**< Line award type One Bar Straight */
#define lb_Two_Bar_Straight    3/**< Line award type Two Bar Straight */
#define lb_Three_Bar_Straight  4/**< Line award type Three Bar Straight */
#define lb_Mix_7_Straight      5/**< Line award type Mix 7 Straight */
#define lb_Red_7_Straight      6/**< Line award type Red 7 Straight */
#define lb_Blue_7_Straight     7/**< Line award type Blue 7 Straight */
#define lb_Joker_Straight      8/**< Line award type Joker 7 Straight */
//

//Line Award Type Define (97 type)
#define LINE_AWARD_NONE            0/**< Line award type none */
#define LINE_AWARD_ONE_CHERRY      1/**< Line award type one cherry straight */
#define LINE_AWARD_TWO_CHERRY      2/**< Line award type two cherry straight */
#define LINE_AWARD_THREE_CHERRY    3/**< Line award type three cherry straight */
#define LINE_AWARD_ORANGE          4/**< Line award type orange straight */
#define LINE_AWARD_MIX_BAR         5/**< Line award type mix bar */
#define LINE_AWARD_MANGO           6/**< Line award type mango straight */
#define LINE_AWARD_BELL            7/**< Line award type bell straight */
#define LINE_AWARD_WATERMELON      8/**< Line award type watermelon straight */
#define LINE_AWARD_BAR_YELLOW      9/**< Line award type bar yellow straight */
#define LINE_AWARD_BAR_RED        10/**< Line award type bar red straight */
#define LINE_AWARD_BAR_BLUE       11/**< Line award type bar blue straight */
#define LINE_AWARD_WILD           12/**< Line award type wild */
//#define LINE_AWARD_SEVEN          12/**< Line award type seven straight */
//#define LINE_AWARD_WILD           13/**< Line award type wild */

//FULL Frame Item Define(97 type for computing item count)
#define FULL_UNKNOW            0
#define FULL_CHERRY            1
#define FULL_ORANGE            2
#define FULL_MANGO             3
#define FULL_BELL              4
#define FULL_WATERMELON        5
#define FULL_BAR_YELLOW        6
#define FULL_BAR_RED           7
#define FULL_BAR_BLUE          8
#define FULL_WIND              9
//#define FULL_SEVEN             9
//#define FULL_WIND              10

//FULL Frame Award Type Define
#define FULL_AWARD_UNKNOW      0
#define FULL_AWARD_ALL_FRUIT   1
#define FULL_AWARD_ANY_BAR     2
#define FULL_AWARD_ORANGE      3
#define FULL_AWARD_MANGO       4
#define FULL_AWARD_BELL        5
#define FULL_AWARD_WATERMELON  6
//#define FULL_AWARD_BAR_YELLOW  7
//#define FULL_AWARD_CHERRY      8
#define FULL_AWARD_CHERRY      7
#define FULL_AWARD_BAR_YELLOW  8
#define FULL_AWARD_BAR_RED     9
#define FULL_AWARD_BAR_BLUE   10
#define FULL_AWARD_WILD       11
//#define FULL_AWARD_SEVEN      11
//#define FULL_AWARD_WILD       12

//Scroll Stop Item Probability(fixed)
//Scroll Stop Random Base
#define _scroll_pro_fixed_random_Base    10000/**< Random base of fixed frame */
#define _scroll_pro_Mutable_random_Base  10000/**< Random base of mutable frame */

//SCROLL 1
#define SCROLL_1_PROBABILITY_CHERRY      1000
 #define SCROLL_1_PROBABILITY_STEP_1     (SCROLL_1_PROBABILITY_CHERRY)
#define SCROLL_1_PROBABILITY_ORANGE      1500
 #define SCROLL_1_PROBABILITY_STEP_2     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE)
#define SCROLL_1_PROBABILITY_MANGO       1500
 #define SCROLL_1_PROBABILITY_STEP_3     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO)
#define SCROLL_1_PROBABILITY_BELL        1000
 #define SCROLL_1_PROBABILITY_STEP_4     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL)
#define SCROLL_1_PROBABILITY_WATERMELON  1000
 #define SCROLL_1_PROBABILITY_STEP_5     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON)
#define SCROLL_1_PROBABILITY_BAR_YELLOW  1000
 #define SCROLL_1_PROBABILITY_STEP_6     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW)
#define SCROLL_1_PROBABILITY_BAR_RED     1000
 #define SCROLL_1_PROBABILITY_STEP_7     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW+SCROLL_1_PROBABILITY_BAR_RED)
#define SCROLL_1_PROBABILITY_BAR_BLUE    1000
 #define SCROLL_1_PROBABILITY_STEP_8     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW+SCROLL_1_PROBABILITY_BAR_RED+SCROLL_1_PROBABILITY_BAR_BLUE)
#define SCROLL_1_PROBABILITY_WILD        1000
 #define SCROLL_1_PROBABILITY_STEP_9     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW+SCROLL_1_PROBABILITY_BAR_RED+SCROLL_1_PROBABILITY_BAR_BLUE+SCROLL_1_PROBABILITY_WILD)

//#define SCROLL_1_PROBABILITY_SEVEN       500
 //#define SCROLL_1_PROBABILITY_STEP_9     (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW+SCROLL_1_PROBABILITY_BAR_RED+SCROLL_1_PROBABILITY_BAR_BLUE+SCROLL_1_PROBABILITY_SEVEN)
//#define SCROLL_1_PROBABILITY_WILD        500
 //#define SCROLL_1_PROBABILITY_STEP_10    (SCROLL_1_PROBABILITY_CHERRY+SCROLL_1_PROBABILITY_ORANGE+SCROLL_1_PROBABILITY_MANGO+SCROLL_1_PROBABILITY_BELL+SCROLL_1_PROBABILITY_WATERMELON+SCROLL_1_PROBABILITY_BAR_YELLOW+SCROLL_1_PROBABILITY_BAR_RED+SCROLL_1_PROBABILITY_BAR_BLUE+SCROLL_1_PROBABILITY_SEVEN+SCROLL_1_PROBABILITY_WILD)

//SCROLL 2
#define SCROLL_2_PROBABILITY_CHERRY      100
 #define SCROLL_2_PROBABILITY_STEP_1     (SCROLL_2_PROBABILITY_CHERRY)
#define SCROLL_2_PROBABILITY_ORANGE      1500
 #define SCROLL_2_PROBABILITY_STEP_2     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE)
#define SCROLL_2_PROBABILITY_MANGO       1200
 #define SCROLL_2_PROBABILITY_STEP_3     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO)
#define SCROLL_2_PROBABILITY_BELL        2300
 #define SCROLL_2_PROBABILITY_STEP_4     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL)
#define SCROLL_2_PROBABILITY_WATERMELON  1400
 #define SCROLL_2_PROBABILITY_STEP_5     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON)
#define SCROLL_2_PROBABILITY_BAR_YELLOW  1200
 #define SCROLL_2_PROBABILITY_STEP_6     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW)
#define SCROLL_2_PROBABILITY_BAR_RED     1250
 #define SCROLL_2_PROBABILITY_STEP_7     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW+SCROLL_2_PROBABILITY_BAR_RED)
#define SCROLL_2_PROBABILITY_BAR_BLUE    850
 #define SCROLL_2_PROBABILITY_STEP_8     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW+SCROLL_2_PROBABILITY_BAR_RED+SCROLL_2_PROBABILITY_BAR_BLUE)
#define SCROLL_2_PROBABILITY_WILD        200
 #define SCROLL_2_PROBABILITY_STEP_9     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW+SCROLL_2_PROBABILITY_BAR_RED+SCROLL_2_PROBABILITY_BAR_BLUE+SCROLL_2_PROBABILITY_WILD)

//#define SCROLL_2_PROBABILITY_SEVEN       500
 //#define SCROLL_2_PROBABILITY_STEP_9     (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW+SCROLL_2_PROBABILITY_BAR_RED+SCROLL_2_PROBABILITY_BAR_BLUE+SCROLL_2_PROBABILITY_SEVEN)
//#define SCROLL_2_PROBABILITY_WILD        500
 //#define SCROLL_2_PROBABILITY_STEP_10    (SCROLL_2_PROBABILITY_CHERRY+SCROLL_2_PROBABILITY_ORANGE+SCROLL_2_PROBABILITY_MANGO+SCROLL_2_PROBABILITY_BELL+SCROLL_2_PROBABILITY_WATERMELON+SCROLL_2_PROBABILITY_BAR_YELLOW+SCROLL_2_PROBABILITY_BAR_RED+SCROLL_2_PROBABILITY_BAR_BLUE+SCROLL_2_PROBABILITY_SEVEN+SCROLL_2_PROBABILITY_WILD)

//SCROLL 3
#define SCROLL_3_PROBABILITY_CHERRY      100
 #define SCROLL_3_PROBABILITY_STEP_1     (SCROLL_3_PROBABILITY_CHERRY)
#define SCROLL_3_PROBABILITY_ORANGE      1500
 #define SCROLL_3_PROBABILITY_STEP_2     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE)
#define SCROLL_3_PROBABILITY_MANGO       1400
 #define SCROLL_3_PROBABILITY_STEP_3     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO)
#define SCROLL_3_PROBABILITY_BELL        2300
 #define SCROLL_3_PROBABILITY_STEP_4     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL)
#define SCROLL_3_PROBABILITY_WATERMELON  1400
 #define SCROLL_3_PROBABILITY_STEP_5     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON)
#define SCROLL_3_PROBABILITY_BAR_YELLOW  1200
 #define SCROLL_3_PROBABILITY_STEP_6     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW)
#define SCROLL_3_PROBABILITY_BAR_RED     1100
 #define SCROLL_3_PROBABILITY_STEP_7     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW+SCROLL_3_PROBABILITY_BAR_RED)
#define SCROLL_3_PROBABILITY_BAR_BLUE    850
 #define SCROLL_3_PROBABILITY_STEP_8     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW+SCROLL_3_PROBABILITY_BAR_RED+SCROLL_3_PROBABILITY_BAR_BLUE)
#define SCROLL_3_PROBABILITY_WILD   	  150
 #define SCROLL_3_PROBABILITY_STEP_9     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW+SCROLL_3_PROBABILITY_BAR_RED+SCROLL_3_PROBABILITY_BAR_BLUE+SCROLL_3_PROBABILITY_WILD)

//#define SCROLL_3_PROBABILITY_SEVEN   	 500
 //#define SCROLL_3_PROBABILITY_STEP_9     (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW+SCROLL_3_PROBABILITY_BAR_RED+SCROLL_3_PROBABILITY_BAR_BLUE+SCROLL_3_PROBABILITY_SEVEN)
//#define SCROLL_3_PROBABILITY_WILD        500
 //#define SCROLL_3_PROBABILITY_STEP_10    (SCROLL_3_PROBABILITY_CHERRY+SCROLL_3_PROBABILITY_ORANGE+SCROLL_3_PROBABILITY_MANGO+SCROLL_3_PROBABILITY_BELL+SCROLL_3_PROBABILITY_WATERMELON+SCROLL_3_PROBABILITY_BAR_YELLOW+SCROLL_3_PROBABILITY_BAR_RED+SCROLL_3_PROBABILITY_BAR_BLUE+SCROLL_3_PROBABILITY_SEVEN+SCROLL_3_PROBABILITY_WILD)

//SCROLL 4
#define SCROLL_4_PROBABILITY_CHERRY      200
 #define SCROLL_4_PROBABILITY_STEP_1     (SCROLL_4_PROBABILITY_CHERRY)
#define SCROLL_4_PROBABILITY_ORANGE      1500
 #define SCROLL_4_PROBABILITY_STEP_2     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE)
#define SCROLL_4_PROBABILITY_MANGO       1200
 #define SCROLL_4_PROBABILITY_STEP_3     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO)
#define SCROLL_4_PROBABILITY_BELL        2300
 #define SCROLL_4_PROBABILITY_STEP_4     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL)
#define SCROLL_4_PROBABILITY_WATERMELON  1400
 #define SCROLL_4_PROBABILITY_STEP_5     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON)
#define SCROLL_4_PROBABILITY_BAR_YELLOW  1200
 #define SCROLL_4_PROBABILITY_STEP_6     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW)
#define SCROLL_4_PROBABILITY_BAR_RED     1200
 #define SCROLL_4_PROBABILITY_STEP_7     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW+SCROLL_4_PROBABILITY_BAR_RED)
#define SCROLL_4_PROBABILITY_BAR_BLUE    850
 #define SCROLL_4_PROBABILITY_STEP_8     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW+SCROLL_4_PROBABILITY_BAR_RED+SCROLL_4_PROBABILITY_BAR_BLUE)
#define SCROLL_4_PROBABILITY_WILD        150
 #define SCROLL_4_PROBABILITY_STEP_9     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW+SCROLL_4_PROBABILITY_BAR_RED+SCROLL_4_PROBABILITY_BAR_BLUE+SCROLL_4_PROBABILITY_WILD)

//#define SCROLL_4_PROBABILITY_SEVEN       500
 //#define SCROLL_4_PROBABILITY_STEP_9     (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW+SCROLL_4_PROBABILITY_BAR_RED+SCROLL_4_PROBABILITY_BAR_BLUE+SCROLL_4_PROBABILITY_SEVEN)
//#define SCROLL_4_PROBABILITY_WILD        500
 //#define SCROLL_4_PROBABILITY_STEP_10    (SCROLL_4_PROBABILITY_CHERRY+SCROLL_4_PROBABILITY_ORANGE+SCROLL_4_PROBABILITY_MANGO+SCROLL_4_PROBABILITY_BELL+SCROLL_4_PROBABILITY_WATERMELON+SCROLL_4_PROBABILITY_BAR_YELLOW+SCROLL_4_PROBABILITY_BAR_RED+SCROLL_4_PROBABILITY_BAR_BLUE+SCROLL_4_PROBABILITY_SEVEN+SCROLL_4_PROBABILITY_WILD)

//SCROLL 5
#define SCROLL_5_PROBABILITY_CHERRY      1000
 #define SCROLL_5_PROBABILITY_STEP_1     (SCROLL_5_PROBABILITY_CHERRY)
#define SCROLL_5_PROBABILITY_ORANGE      1500
 #define SCROLL_5_PROBABILITY_STEP_2     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE)
#define SCROLL_5_PROBABILITY_MANGO       1500
 #define SCROLL_5_PROBABILITY_STEP_3     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO)
#define SCROLL_5_PROBABILITY_BELL        1000
 #define SCROLL_5_PROBABILITY_STEP_4     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL)
#define SCROLL_5_PROBABILITY_WATERMELON  1000
 #define SCROLL_5_PROBABILITY_STEP_5     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON)
#define SCROLL_5_PROBABILITY_BAR_YELLOW  1000
 #define SCROLL_5_PROBABILITY_STEP_6     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW)
#define SCROLL_5_PROBABILITY_BAR_RED     1000
 #define SCROLL_5_PROBABILITY_STEP_7     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW+SCROLL_5_PROBABILITY_BAR_RED)
#define SCROLL_5_PROBABILITY_BAR_BLUE    1000
 #define SCROLL_5_PROBABILITY_STEP_8     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW+SCROLL_5_PROBABILITY_BAR_RED+SCROLL_5_PROBABILITY_BAR_BLUE)
#define SCROLL_5_PROBABILITY_WILD        1000
 #define SCROLL_5_PROBABILITY_STEP_9     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW+SCROLL_5_PROBABILITY_BAR_RED+SCROLL_5_PROBABILITY_BAR_BLUE+SCROLL_5_PROBABILITY_WILD)

//#define SCROLL_5_PROBABILITY_SEVEN       500
 //#define SCROLL_5_PROBABILITY_STEP_9     (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW+SCROLL_5_PROBABILITY_BAR_RED+SCROLL_5_PROBABILITY_BAR_BLUE+SCROLL_5_PROBABILITY_SEVEN)
//#define SCROLL_5_PROBABILITY_WILD        500
 //#define SCROLL_5_PROBABILITY_STEP_10    (SCROLL_5_PROBABILITY_CHERRY+SCROLL_5_PROBABILITY_ORANGE+SCROLL_5_PROBABILITY_MANGO+SCROLL_5_PROBABILITY_BELL+SCROLL_5_PROBABILITY_WATERMELON+SCROLL_5_PROBABILITY_BAR_YELLOW+SCROLL_5_PROBABILITY_BAR_RED+SCROLL_5_PROBABILITY_BAR_BLUE+SCROLL_5_PROBABILITY_SEVEN+SCROLL_5_PROBABILITY_WILD)

//SCROLL 6
#define SCROLL_6_PROBABILITY_CHERRY      1000
 #define SCROLL_6_PROBABILITY_STEP_1     (SCROLL_6_PROBABILITY_CHERRY)
#define SCROLL_6_PROBABILITY_ORANGE      1800
 #define SCROLL_6_PROBABILITY_STEP_2     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE)
#define SCROLL_6_PROBABILITY_MANGO       1600
 #define SCROLL_6_PROBABILITY_STEP_3     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO)
#define SCROLL_6_PROBABILITY_BELL        1400
 #define SCROLL_6_PROBABILITY_STEP_4     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL)
#define SCROLL_6_PROBABILITY_WATERMELON  1200
 #define SCROLL_6_PROBABILITY_STEP_5     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON)
#define SCROLL_6_PROBABILITY_BAR_YELLOW  1000
 #define SCROLL_6_PROBABILITY_STEP_6     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW)
#define SCROLL_6_PROBABILITY_BAR_RED     1000
 #define SCROLL_6_PROBABILITY_STEP_7     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW+SCROLL_6_PROBABILITY_BAR_RED)
#define SCROLL_6_PROBABILITY_BAR_BLUE    850
 #define SCROLL_6_PROBABILITY_STEP_8     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW+SCROLL_6_PROBABILITY_BAR_RED+SCROLL_6_PROBABILITY_BAR_BLUE)
#define SCROLL_6_PROBABILITY_WILD        150
 #define SCROLL_6_PROBABILITY_STEP_9     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW+SCROLL_6_PROBABILITY_BAR_RED+SCROLL_6_PROBABILITY_BAR_BLUE+SCROLL_6_PROBABILITY_WILD)

//#define SCROLL_6_PROBABILITY_SEVEN       500
 //#define SCROLL_6_PROBABILITY_STEP_9     (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW+SCROLL_6_PROBABILITY_BAR_RED+SCROLL_6_PROBABILITY_BAR_BLUE+SCROLL_6_PROBABILITY_SEVEN)
//#define SCROLL_6_PROBABILITY_WILD        500
 //#define SCROLL_6_PROBABILITY_STEP_10    (SCROLL_6_PROBABILITY_CHERRY+SCROLL_6_PROBABILITY_ORANGE+SCROLL_6_PROBABILITY_MANGO+SCROLL_6_PROBABILITY_BELL+SCROLL_6_PROBABILITY_WATERMELON+SCROLL_6_PROBABILITY_BAR_YELLOW+SCROLL_6_PROBABILITY_BAR_RED+SCROLL_6_PROBABILITY_BAR_BLUE+SCROLL_6_PROBABILITY_SEVEN+SCROLL_6_PROBABILITY_WILD)

//SCROLL 7
#define SCROLL_8_PROBABILITY_CHERRY      1000
 #define SCROLL_8_PROBABILITY_STEP_1     (SCROLL_8_PROBABILITY_CHERRY)
#define SCROLL_8_PROBABILITY_ORANGE      1800
 #define SCROLL_8_PROBABILITY_STEP_2     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE)
#define SCROLL_8_PROBABILITY_MANGO       1600
 #define SCROLL_8_PROBABILITY_STEP_3     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO)
#define SCROLL_8_PROBABILITY_BELL        1400
 #define SCROLL_8_PROBABILITY_STEP_4     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL)
#define SCROLL_8_PROBABILITY_WATERMELON  1200
 #define SCROLL_8_PROBABILITY_STEP_5     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON)
#define SCROLL_8_PROBABILITY_BAR_YELLOW  1000
 #define SCROLL_8_PROBABILITY_STEP_6     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW)
#define SCROLL_8_PROBABILITY_BAR_RED     1000
 #define SCROLL_8_PROBABILITY_STEP_7     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED)
#define SCROLL_8_PROBABILITY_BAR_BLUE    850
 #define SCROLL_8_PROBABILITY_STEP_8     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED+SCROLL_8_PROBABILITY_BAR_BLUE)
#define SCROLL_8_PROBABILITY_WILD        150
 #define SCROLL_8_PROBABILITY_STEP_9     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED+SCROLL_8_PROBABILITY_BAR_BLUE+SCROLL_8_PROBABILITY_WILD)

//#define SCROLL_7_PROBABILITY_SEVEN       500
 //#define SCROLL_7_PROBABILITY_STEP_9     (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE+SCROLL_7_PROBABILITY_MANGO+SCROLL_7_PROBABILITY_BELL+SCROLL_7_PROBABILITY_WATERMELON+SCROLL_7_PROBABILITY_BAR_YELLOW+SCROLL_7_PROBABILITY_BAR_RED+SCROLL_7_PROBABILITY_BAR_BLUE+SCROLL_7_PROBABILITY_SEVEN)
//#define SCROLL_7_PROBABILITY_WILD        500
 //#define SCROLL_7_PROBABILITY_STEP_10    (SCROLL_7_PROBABILITY_CHERRY+SCROLL_7_PROBABILITY_ORANGE+SCROLL_7_PROBABILITY_MANGO+SCROLL_7_PROBABILITY_BELL+SCROLL_7_PROBABILITY_WATERMELON+SCROLL_7_PROBABILITY_BAR_YELLOW+SCROLL_7_PROBABILITY_BAR_RED+SCROLL_7_PROBABILITY_BAR_BLUE+SCROLL_7_PROBABILITY_SEVEN+SCROLL_7_PROBABILITY_WILD)

//SCROLL 9
#define SCROLL_9_PROBABILITY_CHERRY      1000
 #define SCROLL_9_PROBABILITY_STEP_1     (SCROLL_9_PROBABILITY_CHERRY)
#define SCROLL_9_PROBABILITY_ORANGE      1800
 #define SCROLL_9_PROBABILITY_STEP_2     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE)
#define SCROLL_9_PROBABILITY_MANGO       1600
 #define SCROLL_9_PROBABILITY_STEP_3     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO)
#define SCROLL_9_PROBABILITY_BELL        1400
 #define SCROLL_9_PROBABILITY_STEP_4     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL)
#define SCROLL_9_PROBABILITY_WATERMELON  1200
 #define SCROLL_9_PROBABILITY_STEP_5     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL+SCROLL_9_PROBABILITY_WATERMELON)
#define SCROLL_9_PROBABILITY_BAR_YELLOW  1000
 #define SCROLL_9_PROBABILITY_STEP_6     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL+SCROLL_9_PROBABILITY_WATERMELON+SCROLL_9_PROBABILITY_BAR_YELLOW)
#define SCROLL_9_PROBABILITY_BAR_RED     1000
 #define SCROLL_9_PROBABILITY_STEP_7     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL+SCROLL_9_PROBABILITY_WATERMELON+SCROLL_9_PROBABILITY_BAR_YELLOW+SCROLL_9_PROBABILITY_BAR_RED)
#define SCROLL_9_PROBABILITY_BAR_BLUE    850
 #define SCROLL_9_PROBABILITY_STEP_8     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL+SCROLL_9_PROBABILITY_WATERMELON+SCROLL_9_PROBABILITY_BAR_YELLOW+SCROLL_9_PROBABILITY_BAR_RED+SCROLL_9_PROBABILITY_BAR_BLUE)
#define SCROLL_9_PROBABILITY_WILD        150
 #define SCROLL_9_PROBABILITY_STEP_9     (SCROLL_9_PROBABILITY_CHERRY+SCROLL_9_PROBABILITY_ORANGE+SCROLL_9_PROBABILITY_MANGO+SCROLL_9_PROBABILITY_BELL+SCROLL_9_PROBABILITY_WATERMELON+SCROLL_9_PROBABILITY_BAR_YELLOW+SCROLL_9_PROBABILITY_BAR_RED+SCROLL_9_PROBABILITY_BAR_BLUE+SCROLL_9_PROBABILITY_WILD)

//#define SCROLL_8_PROBABILITY_SEVEN       500
 //#define SCROLL_8_PROBABILITY_STEP_9     (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED+SCROLL_8_PROBABILITY_BAR_BLUE+SCROLL_8_PROBABILITY_SEVEN)
//#define SCROLL_8_PROBABILITY_WILD        500
 //#define SCROLL_8_PROBABILITY_STEP_10    (SCROLL_8_PROBABILITY_CHERRY+SCROLL_8_PROBABILITY_ORANGE+SCROLL_8_PROBABILITY_MANGO+SCROLL_8_PROBABILITY_BELL+SCROLL_8_PROBABILITY_WATERMELON+SCROLL_8_PROBABILITY_BAR_YELLOW+SCROLL_8_PROBABILITY_BAR_RED+SCROLL_8_PROBABILITY_BAR_BLUE+SCROLL_8_PROBABILITY_SEVEN+SCROLL_8_PROBABILITY_WILD)

//fixed Scroll 1
#define _scroll_1_pro_fixed_Blank      6000
  #define _scoroll_1_pro_fixed_step1    (_scroll_1_pro_fixed_Blank)
#define _scroll_1_pro_fixed_1Bar       800
  #define _scoroll_1_pro_fixed_step2    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar)
#define _scroll_1_pro_fixed_2Bar       800
  #define _scoroll_1_pro_fixed_step3    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar)
#define _scroll_1_pro_fixed_3Bar       800
  #define _scoroll_1_pro_fixed_step4    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar)
#define _scroll_1_pro_fixed_Red7       600
  #define _scoroll_1_pro_fixed_step5    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar + _scroll_1_pro_fixed_Red7)
#define _scroll_1_pro_fixed_Blue7      700
  #define _scoroll_1_pro_fixed_step6    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar + _scroll_1_pro_fixed_Red7 + _scroll_1_pro_fixed_Blue7)
#define _scroll_1_pro_fixed_Joker      300
  #define _scoroll_1_pro_fixed_step7    (_scroll_1_pro_fixed_Blank + _scroll_1_pro_fixed_1Bar + _scroll_1_pro_fixed_2Bar + _scroll_1_pro_fixed_3Bar + _scroll_1_pro_fixed_Red7 + _scroll_1_pro_fixed_Blue7 + _scroll_1_pro_fixed_Joker)

//fixed Scroll 2
#define _scroll_2_pro_fixed_Blank      4800
  #define _scoroll_2_pro_fixed_step1    (_scroll_2_pro_fixed_Blank)
#define _scroll_2_pro_fixed_1Bar       1500
  #define _scoroll_2_pro_fixed_step2    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar)
#define _scroll_2_pro_fixed_2Bar       1000
  #define _scoroll_2_pro_fixed_step3    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar)
#define _scroll_2_pro_fixed_3Bar       1500
  #define _scoroll_2_pro_fixed_step4    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar)
#define _scroll_2_pro_fixed_Red7        600
  #define _scoroll_2_pro_fixed_step5    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar + _scroll_2_pro_fixed_Red7)
#define _scroll_2_pro_fixed_Blue7       500
  #define _scoroll_2_pro_fixed_step6    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar + _scroll_2_pro_fixed_Red7 + _scroll_2_pro_fixed_Blue7)
#define _scroll_2_pro_fixed_Joker       100
  #define _scoroll_2_pro_fixed_step7    (_scroll_2_pro_fixed_Blank + _scroll_2_pro_fixed_1Bar + _scroll_2_pro_fixed_2Bar + _scroll_2_pro_fixed_3Bar + _scroll_2_pro_fixed_Red7 + _scroll_2_pro_fixed_Blue7 + _scroll_2_pro_fixed_Joker)

//fixed Scroll 3
#define _scroll_3_pro_fixed_Blank      5600
  #define _scoroll_3_pro_fixed_step1    (_scroll_3_pro_fixed_Blank)
#define _scroll_3_pro_fixed_1Bar       1200
  #define _scoroll_3_pro_fixed_step2    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar)
#define _scroll_3_pro_fixed_2Bar       1200
  #define _scoroll_3_pro_fixed_step3    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar)
#define _scroll_3_pro_fixed_3Bar       800
  #define _scoroll_3_pro_fixed_step4    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar)
#define _scroll_3_pro_fixed_Red7       500
  #define _scoroll_3_pro_fixed_step5    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar + _scroll_3_pro_fixed_Red7)
#define _scroll_3_pro_fixed_Blue7      500
  #define _scoroll_3_pro_fixed_step6    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar + _scroll_3_pro_fixed_Red7 + _scroll_3_pro_fixed_Blue7)
#define _scroll_3_pro_fixed_Joker      200
  #define _scoroll_3_pro_fixed_step7    (_scroll_3_pro_fixed_Blank + _scroll_3_pro_fixed_1Bar + _scroll_3_pro_fixed_2Bar + _scroll_3_pro_fixed_3Bar + _scroll_3_pro_fixed_Red7 + _scroll_3_pro_fixed_Blue7 + _scroll_3_pro_fixed_Joker)

//fixed Scroll 4
#define _scroll_4_pro_fixed_Blank      5800
  #define _scoroll_4_pro_fixed_step1    (_scroll_4_pro_fixed_Blank)
#define _scroll_4_pro_fixed_1Bar        900
  #define _scoroll_4_pro_fixed_step2    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar)
#define _scroll_4_pro_fixed_2Bar       1100
  #define _scoroll_4_pro_fixed_step3    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar)
#define _scroll_4_pro_fixed_3Bar       1000
  #define _scoroll_4_pro_fixed_step4    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar)
#define _scroll_4_pro_fixed_Red7        600
  #define _scoroll_4_pro_fixed_step5    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar + _scroll_4_pro_fixed_Red7)
#define _scroll_4_pro_fixed_Blue7       500
  #define _scoroll_4_pro_fixed_step6    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar + _scroll_4_pro_fixed_Red7 + _scroll_4_pro_fixed_Blue7)
#define _scroll_4_pro_fixed_Joker       100
  #define _scoroll_4_pro_fixed_step7    (_scroll_4_pro_fixed_Blank + _scroll_4_pro_fixed_1Bar + _scroll_4_pro_fixed_2Bar + _scroll_4_pro_fixed_3Bar + _scroll_4_pro_fixed_Red7 + _scroll_4_pro_fixed_Blue7 + _scroll_4_pro_fixed_Joker)

//fixed Scroll 5
#define _scroll_5_pro_fixed_Blank      6000
  #define _scoroll_5_pro_fixed_step1    (_scroll_5_pro_fixed_Blank)
#define _scroll_5_pro_fixed_1Bar        900
  #define _scoroll_5_pro_fixed_step2    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar)
#define _scroll_5_pro_fixed_2Bar       1000
  #define _scoroll_5_pro_fixed_step3    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar)
#define _scroll_5_pro_fixed_3Bar       1000
  #define _scoroll_5_pro_fixed_step4    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar)
#define _scroll_5_pro_fixed_Red7        600
  #define _scoroll_5_pro_fixed_step5    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar + _scroll_5_pro_fixed_Red7)
#define _scroll_5_pro_fixed_Blue7       400
  #define _scoroll_5_pro_fixed_step6    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar + _scroll_5_pro_fixed_Red7 + _scroll_5_pro_fixed_Blue7)
#define _scroll_5_pro_fixed_Joker       100
  #define _scoroll_5_pro_fixed_step7    (_scroll_5_pro_fixed_Blank + _scroll_5_pro_fixed_1Bar + _scroll_5_pro_fixed_2Bar + _scroll_5_pro_fixed_3Bar + _scroll_5_pro_fixed_Red7 + _scroll_5_pro_fixed_Blue7 + _scroll_5_pro_fixed_Joker)

//fixed Scroll 6
#define _scroll_6_pro_fixed_Blank      4600
  #define _scoroll_6_pro_fixed_step1    (_scroll_6_pro_fixed_Blank)
#define _scroll_6_pro_fixed_1Bar       1600
  #define _scoroll_6_pro_fixed_step2    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar)
#define _scroll_6_pro_fixed_2Bar       1400
  #define _scoroll_6_pro_fixed_step3    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar)
#define _scroll_6_pro_fixed_3Bar       1100
  #define _scoroll_6_pro_fixed_step4    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar)
#define _scroll_6_pro_fixed_Red7        700
  #define _scoroll_6_pro_fixed_step5    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar + _scroll_6_pro_fixed_Red7)
#define _scroll_6_pro_fixed_Blue7       400
  #define _scoroll_6_pro_fixed_step6    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar + _scroll_6_pro_fixed_Red7 + _scroll_6_pro_fixed_Blue7)
#define _scroll_6_pro_fixed_Joker       200
  #define _scoroll_6_pro_fixed_step7    (_scroll_6_pro_fixed_Blank + _scroll_6_pro_fixed_1Bar + _scroll_6_pro_fixed_2Bar + _scroll_6_pro_fixed_3Bar + _scroll_6_pro_fixed_Red7 + _scroll_6_pro_fixed_Blue7 + _scroll_6_pro_fixed_Joker)

//fixed Scroll 7
#define _scroll_7_pro_fixed_Blank      5700
  #define _scoroll_7_pro_fixed_step1    (_scroll_7_pro_fixed_Blank)
#define _scroll_7_pro_fixed_1Bar       1100
  #define _scoroll_7_pro_fixed_step2    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar)
#define _scroll_7_pro_fixed_2Bar       1000
  #define _scoroll_7_pro_fixed_step3    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar)
#define _scroll_7_pro_fixed_3Bar       1100
  #define _scoroll_7_pro_fixed_step4    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar)
#define _scroll_7_pro_fixed_Red7        500
  #define _scoroll_7_pro_fixed_step5    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar + _scroll_7_pro_fixed_Red7)
#define _scroll_7_pro_fixed_Blue7       500
  #define _scoroll_7_pro_fixed_step6    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar + _scroll_7_pro_fixed_Red7 + _scroll_7_pro_fixed_Blue7)
#define _scroll_7_pro_fixed_Joker       100
  #define _scoroll_7_pro_fixed_step7    (_scroll_7_pro_fixed_Blank + _scroll_7_pro_fixed_1Bar + _scroll_7_pro_fixed_2Bar + _scroll_7_pro_fixed_3Bar + _scroll_7_pro_fixed_Red7 + _scroll_7_pro_fixed_Blue7 + _scroll_7_pro_fixed_Joker)

//fixed Scroll 8
#define _scroll_8_pro_fixed_Blank      5400
  #define _scoroll_8_pro_fixed_step1    (_scroll_8_pro_fixed_Blank)
#define _scroll_8_pro_fixed_1Bar       1000
  #define _scoroll_8_pro_fixed_step2    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar)
#define _scroll_8_pro_fixed_2Bar       1000
  #define _scoroll_8_pro_fixed_step3    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar)
#define _scroll_8_pro_fixed_3Bar       1000
  #define _scoroll_8_pro_fixed_step4    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar)
#define _scroll_8_pro_fixed_Red7       600
  #define _scoroll_8_pro_fixed_step5    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar + _scroll_8_pro_fixed_Red7)
#define _scroll_8_pro_fixed_Blue7      800
  #define _scoroll_8_pro_fixed_step6    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar + _scroll_8_pro_fixed_Red7 + _scroll_8_pro_fixed_Blue7)
#define _scroll_8_pro_fixed_Joker      200
  #define _scoroll_8_pro_fixed_step7    (_scroll_8_pro_fixed_Blank + _scroll_8_pro_fixed_1Bar + _scroll_8_pro_fixed_2Bar + _scroll_8_pro_fixed_3Bar + _scroll_8_pro_fixed_Red7 + _scroll_8_pro_fixed_Blue7 + _scroll_8_pro_fixed_Joker)

/*** ***/

/***Link Probability ***/
//*SAMLL*/
//GL small Probability 90
#define gl_s_pro_90_82  190
#define gl_s_pro_90_84  (gl_s_pro_90_82 +200)
#define gl_s_pro_90_86  (gl_s_pro_90_84 +150)
#define gl_s_pro_90_88  (gl_s_pro_90_86 +125)
#define gl_s_pro_90_90  (gl_s_pro_90_88 +110)
#define gl_s_pro_90_92  (gl_s_pro_90_90 +75)
#define gl_s_pro_90_94  (gl_s_pro_90_92 +45)
#define gl_s_pro_90_96  (gl_s_pro_90_94 +10)
#define gl_s_pro_90_98  (gl_s_pro_90_96 +30)
#define gl_s_pro_90_100 (gl_s_pro_90_98 +5)
#define gl_s_pro_90_102 (gl_s_pro_90_100+20)
#define gl_s_pro_90_104 (gl_s_pro_90_102+15)
#define gl_s_pro_90_106 (gl_s_pro_90_104+10)
#define gl_s_pro_90_108 (gl_s_pro_90_106+10)
#define gl_s_pro_90_110 (gl_s_pro_90_108+5)
//GL small Probability 91
#define gl_s_pro_91_82  165
#define gl_s_pro_91_84  (gl_s_pro_91_82 +175)
#define gl_s_pro_91_86  (gl_s_pro_91_84 +180)
#define gl_s_pro_91_88  (gl_s_pro_91_86 +105)
#define gl_s_pro_91_90  (gl_s_pro_91_88 +80)
#define gl_s_pro_91_92  (gl_s_pro_91_90 +70)
#define gl_s_pro_91_94  (gl_s_pro_91_92 +60)
#define gl_s_pro_91_96  (gl_s_pro_91_94 +10)
#define gl_s_pro_91_98  (gl_s_pro_91_96 +50)
#define gl_s_pro_91_100 (gl_s_pro_91_98 +35)
#define gl_s_pro_91_102 (gl_s_pro_91_100+25)
#define gl_s_pro_91_104 (gl_s_pro_91_102+5)
#define gl_s_pro_91_106 (gl_s_pro_91_104+10)
#define gl_s_pro_91_108 (gl_s_pro_91_106+10)
#define gl_s_pro_91_110 (gl_s_pro_91_108+20)
//GL small Probability 92
#define gl_s_pro_92_82  175
#define gl_s_pro_92_84  (gl_s_pro_92_82 +130)
#define gl_s_pro_92_86  (gl_s_pro_92_84 +145)
#define gl_s_pro_92_88  (gl_s_pro_92_86 +125)
#define gl_s_pro_92_90  (gl_s_pro_92_88 +50)
#define gl_s_pro_92_92  (gl_s_pro_92_90 +65)
#define gl_s_pro_92_94  (gl_s_pro_92_92 +100)
#define gl_s_pro_92_96  (gl_s_pro_92_94 +50)
#define gl_s_pro_92_98  (gl_s_pro_92_96 +50)
#define gl_s_pro_92_100 (gl_s_pro_92_98 +10)
#define gl_s_pro_92_102 (gl_s_pro_92_100+10)
#define gl_s_pro_92_104 (gl_s_pro_92_102+15)
#define gl_s_pro_92_106 (gl_s_pro_92_104+25)
#define gl_s_pro_92_108 (gl_s_pro_92_106+25)
#define gl_s_pro_92_110 (gl_s_pro_92_108+25)
//GL small Probability 93
#define gl_s_pro_93_82  145
#define gl_s_pro_93_84  (gl_s_pro_93_82 +150)
#define gl_s_pro_93_86  (gl_s_pro_93_84 +60)
#define gl_s_pro_93_88  (gl_s_pro_93_86 +135)
#define gl_s_pro_93_90  (gl_s_pro_93_88 +125)
#define gl_s_pro_93_92  (gl_s_pro_93_90 +20)
#define gl_s_pro_93_94  (gl_s_pro_93_92 +50)
#define gl_s_pro_93_96  (gl_s_pro_93_94 +70)
#define gl_s_pro_93_98  (gl_s_pro_93_96 +80)
#define gl_s_pro_93_100 (gl_s_pro_93_98 +40)
#define gl_s_pro_93_102 (gl_s_pro_93_100+35)
#define gl_s_pro_93_104 (gl_s_pro_93_102+40)
#define gl_s_pro_93_106 (gl_s_pro_93_104+20)
#define gl_s_pro_93_108 (gl_s_pro_93_106+15)
#define gl_s_pro_93_110 (gl_s_pro_93_108+15)
//GL small Probability 94
#define gl_s_pro_94_82  110
#define gl_s_pro_94_84  (gl_s_pro_94_82 +120)
#define gl_s_pro_94_86  (gl_s_pro_94_84 +100)
#define gl_s_pro_94_88  (gl_s_pro_94_86 +60)
#define gl_s_pro_94_90  (gl_s_pro_94_88 +100)
#define gl_s_pro_94_92  (gl_s_pro_94_90 +60)
#define gl_s_pro_94_94  (gl_s_pro_94_92 +100)
#define gl_s_pro_94_96  (gl_s_pro_94_94 +60)
#define gl_s_pro_94_98  (gl_s_pro_94_96 +135)
#define gl_s_pro_94_100 (gl_s_pro_94_98 +25)
#define gl_s_pro_94_102 (gl_s_pro_94_100+45)
#define gl_s_pro_94_104 (gl_s_pro_94_102+35)
#define gl_s_pro_94_106 (gl_s_pro_94_104+25)
#define gl_s_pro_94_108 (gl_s_pro_94_106+10)
#define gl_s_pro_94_110 (gl_s_pro_94_108+15)

//*MID*/
//GL mid Probability 90
#define gl_m_pro_90_70  130
#define gl_m_pro_90_75  (gl_m_pro_90_70 +120)
#define gl_m_pro_90_80  (gl_m_pro_90_75 +135)
#define gl_m_pro_90_85  (gl_m_pro_90_80 +50)
#define gl_m_pro_90_90  (gl_m_pro_90_85 +75)
#define gl_m_pro_90_92  (gl_m_pro_90_90 +145)
#define gl_m_pro_90_94  (gl_m_pro_90_92 +20)
#define gl_m_pro_90_96  (gl_m_pro_90_94 +90)
#define gl_m_pro_90_98  (gl_m_pro_90_96 +100)
#define gl_m_pro_90_100 (gl_m_pro_90_98 +35)
#define gl_m_pro_90_103 (gl_m_pro_90_100+35)
#define gl_m_pro_90_107 (gl_m_pro_90_103+15)
#define gl_m_pro_90_110 (gl_m_pro_90_107+25)
#define gl_m_pro_90_115 (gl_m_pro_90_110+15)
#define gl_m_pro_90_125 (gl_m_pro_90_115+10)
//GL mid Probability 91
#define gl_m_pro_91_70  155
#define gl_m_pro_91_75  (gl_m_pro_91_70 +120)
#define gl_m_pro_91_80  (gl_m_pro_91_75 +55)
#define gl_m_pro_91_85  (gl_m_pro_91_80 +120)
#define gl_m_pro_91_90  (gl_m_pro_91_85 +50)
#define gl_m_pro_91_92  (gl_m_pro_91_90 +45)
#define gl_m_pro_91_94  (gl_m_pro_91_92 +85)
#define gl_m_pro_91_96  (gl_m_pro_91_94 +105)
#define gl_m_pro_91_98  (gl_m_pro_91_96 +115)
#define gl_m_pro_91_100 (gl_m_pro_91_98 +5)
#define gl_m_pro_91_103 (gl_m_pro_91_100+40)
#define gl_m_pro_91_107 (gl_m_pro_91_103+25)
#define gl_m_pro_91_110 (gl_m_pro_91_107+25)
#define gl_m_pro_91_115 (gl_m_pro_91_110+35)
#define gl_m_pro_91_125 (gl_m_pro_91_115+20)
//GL mid Probability 92
#define gl_m_pro_92_70  140
#define gl_m_pro_92_75  (gl_m_pro_92_70 +125)
#define gl_m_pro_92_80  (gl_m_pro_92_75 +105)
#define gl_m_pro_92_85  (gl_m_pro_92_80 +80)
#define gl_m_pro_92_90  (gl_m_pro_92_85 +40)
#define gl_m_pro_92_92  (gl_m_pro_92_90 +85)
#define gl_m_pro_92_94  (gl_m_pro_92_92 +45)
#define gl_m_pro_92_96  (gl_m_pro_92_94 +55)
#define gl_m_pro_92_98  (gl_m_pro_92_96 +65)
#define gl_m_pro_92_100 (gl_m_pro_92_98 +50)
#define gl_m_pro_92_103 (gl_m_pro_92_100+60)
#define gl_m_pro_92_107 (gl_m_pro_92_103+45)
#define gl_m_pro_92_110 (gl_m_pro_92_107+30)
#define gl_m_pro_92_115 (gl_m_pro_92_110+35)
#define gl_m_pro_92_125 (gl_m_pro_92_115+40)
//GL mid Probability 93
#define gl_m_pro_93_70  100
#define gl_m_pro_93_75  (gl_m_pro_93_70 +115)
#define gl_m_pro_93_80  (gl_m_pro_93_75 +60)
#define gl_m_pro_93_85  (gl_m_pro_93_80 +75)
#define gl_m_pro_93_90  (gl_m_pro_93_85 +115)
#define gl_m_pro_93_92  (gl_m_pro_93_90 +50)
#define gl_m_pro_93_94  (gl_m_pro_93_92 +75)
#define gl_m_pro_93_96  (gl_m_pro_93_94 +70)
#define gl_m_pro_93_98  (gl_m_pro_93_96 +105)
#define gl_m_pro_93_100 (gl_m_pro_93_98 +50)
#define gl_m_pro_93_103 (gl_m_pro_93_100+70)
#define gl_m_pro_93_107 (gl_m_pro_93_103+50)
#define gl_m_pro_93_110 (gl_m_pro_93_107+20)
#define gl_m_pro_93_115 (gl_m_pro_93_110+20)
#define gl_m_pro_93_125 (gl_m_pro_93_115+25)
//GL mid Probability 94
#define gl_m_pro_94_70  75
#define gl_m_pro_94_75  (gl_m_pro_94_70 +115)
#define gl_m_pro_94_80  (gl_m_pro_94_75 +70)
#define gl_m_pro_94_85  (gl_m_pro_94_80 +85)
#define gl_m_pro_94_90  (gl_m_pro_94_85 +110)
#define gl_m_pro_94_92  (gl_m_pro_94_90 +55)
#define gl_m_pro_94_94  (gl_m_pro_94_92 +80)
#define gl_m_pro_94_96  (gl_m_pro_94_94 +90)
#define gl_m_pro_94_98  (gl_m_pro_94_96 +70)
#define gl_m_pro_94_100 (gl_m_pro_94_98 +45)
#define gl_m_pro_94_103 (gl_m_pro_94_100+65)
#define gl_m_pro_94_107 (gl_m_pro_94_103+35)
#define gl_m_pro_94_110 (gl_m_pro_94_107+30)
#define gl_m_pro_94_115 (gl_m_pro_94_110+30)
#define gl_m_pro_94_125 (gl_m_pro_94_115+45)

//*BIG*/
//GL big Probability 90
#define gl_b_pro_90_70  155
#define gl_b_pro_90_72  (gl_b_pro_90_70 +100)
#define gl_b_pro_90_74  (gl_b_pro_90_72 +115)
#define gl_b_pro_90_76  (gl_b_pro_90_74 +50)
#define gl_b_pro_90_78  (gl_b_pro_90_76 +105)
#define gl_b_pro_90_80  (gl_b_pro_90_78 +60)
#define gl_b_pro_90_85  (gl_b_pro_90_80 +110)
#define gl_b_pro_90_90  (gl_b_pro_90_85 +55)
#define gl_b_pro_90_95  (gl_b_pro_90_90 +45)
#define gl_b_pro_90_100 (gl_b_pro_90_95 +50)
#define gl_b_pro_90_106 (gl_b_pro_90_100+40)
#define gl_b_pro_90_114 (gl_b_pro_90_106+15)
#define gl_b_pro_90_123 (gl_b_pro_90_114+50)
#define gl_b_pro_90_133 (gl_b_pro_90_123+25)
#define gl_b_pro_90_144 (gl_b_pro_90_133+25)
//GL big Probability 91
#define gl_b_pro_91_70  115
#define gl_b_pro_91_72  (gl_b_pro_91_70 +120)
#define gl_b_pro_91_74  (gl_b_pro_91_72 +105)
#define gl_b_pro_91_76  (gl_b_pro_91_74 +80)
#define gl_b_pro_91_78  (gl_b_pro_91_76 +60)
#define gl_b_pro_91_80  (gl_b_pro_91_78 +45)
#define gl_b_pro_91_85  (gl_b_pro_91_80 +80)
#define gl_b_pro_91_90  (gl_b_pro_91_85 +110)
#define gl_b_pro_91_95  (gl_b_pro_91_90 +90)
#define gl_b_pro_91_100 (gl_b_pro_91_95 +50)
#define gl_b_pro_91_106 (gl_b_pro_91_100+25)
#define gl_b_pro_91_114 (gl_b_pro_91_106+40)
#define gl_b_pro_91_123 (gl_b_pro_91_114+15)
#define gl_b_pro_91_133 (gl_b_pro_91_123+30)
#define gl_b_pro_91_144 (gl_b_pro_91_133+35)
//GL big Probability 92
#define gl_b_pro_92_70  130
#define gl_b_pro_92_72  (gl_b_pro_92_70 +75)
#define gl_b_pro_92_74  (gl_b_pro_92_72 +65)
#define gl_b_pro_92_76  (gl_b_pro_92_74 +60)
#define gl_b_pro_92_78  (gl_b_pro_92_76 +105)
#define gl_b_pro_92_80  (gl_b_pro_92_78 +80)
#define gl_b_pro_92_85  (gl_b_pro_92_80 +105)
#define gl_b_pro_92_90  (gl_b_pro_92_85 +90)
#define gl_b_pro_92_95  (gl_b_pro_92_90 +35)
#define gl_b_pro_92_100 (gl_b_pro_92_95 +70)
#define gl_b_pro_92_106 (gl_b_pro_92_100+60)
#define gl_b_pro_92_114 (gl_b_pro_92_106+45)
#define gl_b_pro_92_123 (gl_b_pro_92_114+20)
#define gl_b_pro_92_133 (gl_b_pro_92_123+35)
#define gl_b_pro_92_144 (gl_b_pro_92_133+25)
//GL big Probability 93
#define gl_b_pro_93_70  130
#define gl_b_pro_93_72  (gl_b_pro_93_70 +65)
#define gl_b_pro_93_74  (gl_b_pro_93_72 +80)
#define gl_b_pro_93_76  (gl_b_pro_93_74 +100)
#define gl_b_pro_93_78  (gl_b_pro_93_76 +80)
#define gl_b_pro_93_80  (gl_b_pro_93_78 +100)
#define gl_b_pro_93_85  (gl_b_pro_93_80 +45)
#define gl_b_pro_93_90  (gl_b_pro_93_85 +30)
#define gl_b_pro_93_95  (gl_b_pro_93_90 +100)
#define gl_b_pro_93_100 (gl_b_pro_93_95 +50)
#define gl_b_pro_93_106 (gl_b_pro_93_100+40)
#define gl_b_pro_93_114 (gl_b_pro_93_106+60)
#define gl_b_pro_93_123 (gl_b_pro_93_114+40)
#define gl_b_pro_93_133 (gl_b_pro_93_123+40)
#define gl_b_pro_93_144 (gl_b_pro_93_133+40)
//GL big Probability 94
#define gl_b_pro_94_70  100
#define gl_b_pro_94_72  (gl_b_pro_94_70 +65)
#define gl_b_pro_94_74  (gl_b_pro_94_72 +60)
#define gl_b_pro_94_76  (gl_b_pro_94_74 +60)
#define gl_b_pro_94_78  (gl_b_pro_94_76 +55)
#define gl_b_pro_94_80  (gl_b_pro_94_78 +85)
#define gl_b_pro_94_85  (gl_b_pro_94_80 +100)
#define gl_b_pro_94_90  (gl_b_pro_94_85 +95)
#define gl_b_pro_94_95  (gl_b_pro_94_90 +95)
#define gl_b_pro_94_100 (gl_b_pro_94_95 +95)
#define gl_b_pro_94_106 (gl_b_pro_94_100+55)
#define gl_b_pro_94_114 (gl_b_pro_94_106+35)
#define gl_b_pro_94_123 (gl_b_pro_94_114+30)
#define gl_b_pro_94_133 (gl_b_pro_94_123+40)
#define gl_b_pro_94_144 (gl_b_pro_94_133+30)

/* Game Level Draw Table */
// SMALL 89 %
#define GL_SMALL_89__82   175
#define GL_SMALL_89__84   (GL_SMALL_89__82  +  85)
#define GL_SMALL_89__86   (GL_SMALL_89__84  + 125)
#define GL_SMALL_89__88   (GL_SMALL_89__86  + 125)
#define GL_SMALL_89__90   (GL_SMALL_89__88  + 175)
#define GL_SMALL_89__92   (GL_SMALL_89__90  + 110)
#define GL_SMALL_89__94   (GL_SMALL_89__92  +  75)
#define GL_SMALL_89__96   (GL_SMALL_89__94  +  75)
#define GL_SMALL_89__98   (GL_SMALL_89__96  +   5)
#define GL_SMALL_89__100  (GL_SMALL_89__98  +  25)
#define GL_SMALL_89__102  (GL_SMALL_89__100 +   5)
#define GL_SMALL_89__104  (GL_SMALL_89__102 +   5)
#define GL_SMALL_89__106  (GL_SMALL_89__104 +   5)
#define GL_SMALL_89__108  (GL_SMALL_89__106 +   5)
#define GL_SMALL_89__110  (GL_SMALL_89__108 +   5)

// SMALL 89.5 %
#define GL_SMALL_89_5__82   115
#define GL_SMALL_89_5__84   (GL_SMALL_89_5__82  + 120)
#define GL_SMALL_89_5__86   (GL_SMALL_89_5__84  + 125)
#define GL_SMALL_89_5__88   (GL_SMALL_89_5__86  + 125)
#define GL_SMALL_89_5__90   (GL_SMALL_89_5__88  + 175)
#define GL_SMALL_89_5__92   (GL_SMALL_89_5__90  + 110)
#define GL_SMALL_89_5__94   (GL_SMALL_89_5__92  +  75)
#define GL_SMALL_89_5__96   (GL_SMALL_89_5__94  +  60)
#define GL_SMALL_89_5__98   (GL_SMALL_89_5__96  +  45)
#define GL_SMALL_89_5__100  (GL_SMALL_89_5__98  +  25)
#define GL_SMALL_89_5__102  (GL_SMALL_89_5__100 +   5)
#define GL_SMALL_89_5__104  (GL_SMALL_89_5__102 +   5)
#define GL_SMALL_89_5__106  (GL_SMALL_89_5__104 +   5)
#define GL_SMALL_89_5__108  (GL_SMALL_89_5__106 +   5)
#define GL_SMALL_89_5__110  (GL_SMALL_89_5__108 +   5)

// SMALL 90 %
#define GL_SMALL_90__82   105
#define GL_SMALL_90__84   (GL_SMALL_90__82  + 105)
#define GL_SMALL_90__86   (GL_SMALL_90__84  + 125)
#define GL_SMALL_90__88   (GL_SMALL_90__86  + 125)
#define GL_SMALL_90__90   (GL_SMALL_90__88  + 175)
#define GL_SMALL_90__92   (GL_SMALL_90__90  + 110)
#define GL_SMALL_90__94   (GL_SMALL_90__92  +  75)
#define GL_SMALL_90__96   (GL_SMALL_90__94  +  60)
#define GL_SMALL_90__98   (GL_SMALL_90__96  +  45)
#define GL_SMALL_90__100  (GL_SMALL_90__98  +  25)
#define GL_SMALL_90__102  (GL_SMALL_90__100 +  20)
#define GL_SMALL_90__104  (GL_SMALL_90__102 +  10)
#define GL_SMALL_90__106  (GL_SMALL_90__104 +  10)
#define GL_SMALL_90__108  (GL_SMALL_90__106 +   5)
#define GL_SMALL_90__110  (GL_SMALL_90__108 +   5)

// SMALL 90.5 %
#define GL_SMALL_90_5__82   65
#define GL_SMALL_90_5__84   (GL_SMALL_90_5__82  + 120)
#define GL_SMALL_90_5__86   (GL_SMALL_90_5__84  + 125)
#define GL_SMALL_90_5__88   (GL_SMALL_90_5__86  + 125)
#define GL_SMALL_90_5__90   (GL_SMALL_90_5__88  + 175)
#define GL_SMALL_90_5__92   (GL_SMALL_90_5__90  + 110)
#define GL_SMALL_90_5__94   (GL_SMALL_90_5__92  +  75)
#define GL_SMALL_90_5__96   (GL_SMALL_90_5__94  +  60)
#define GL_SMALL_90_5__98   (GL_SMALL_90_5__96  +  50)
#define GL_SMALL_90_5__100  (GL_SMALL_90_5__98  +  40)
#define GL_SMALL_90_5__102  (GL_SMALL_90_5__100 +  20)
#define GL_SMALL_90_5__104  (GL_SMALL_90_5__102 +  10)
#define GL_SMALL_90_5__106  (GL_SMALL_90_5__104 +  15)
#define GL_SMALL_90_5__108  (GL_SMALL_90_5__106 +   5)
#define GL_SMALL_90_5__110  (GL_SMALL_90_5__108 +   5)

// SMALL 91 %
#define GL_SMALL_91__82   15
#define GL_SMALL_91__84   (GL_SMALL_91__82  + 100)
#define GL_SMALL_91__86   (GL_SMALL_91__84  + 125)
#define GL_SMALL_91__88   (GL_SMALL_91__86  + 130)
#define GL_SMALL_91__90   (GL_SMALL_91__88  + 175)
#define GL_SMALL_91__92   (GL_SMALL_91__90  + 150)
#define GL_SMALL_91__94   (GL_SMALL_91__92  + 125)
#define GL_SMALL_91__96   (GL_SMALL_91__94  +  60)
#define GL_SMALL_91__98   (GL_SMALL_91__96  +  45)
#define GL_SMALL_91__100  (GL_SMALL_91__98  +  35)
#define GL_SMALL_91__102  (GL_SMALL_91__100 +  10)
#define GL_SMALL_91__104  (GL_SMALL_91__102 +  10)
#define GL_SMALL_91__106  (GL_SMALL_91__104 +  10)
#define GL_SMALL_91__108  (GL_SMALL_91__106 +   5)
#define GL_SMALL_91__110  (GL_SMALL_91__108 +   5)

// SMALL 91.5 %
#define GL_SMALL_91_5__82   40
#define GL_SMALL_91_5__84   (GL_SMALL_91_5__82  + 135)
#define GL_SMALL_91_5__86   (GL_SMALL_91_5__84  + 125)
#define GL_SMALL_91_5__88   (GL_SMALL_91_5__86  + 100)
#define GL_SMALL_91_5__90   (GL_SMALL_91_5__88  + 105)
#define GL_SMALL_91_5__92   (GL_SMALL_91_5__90  + 125)
#define GL_SMALL_91_5__94   (GL_SMALL_91_5__92  +  75)
#define GL_SMALL_91_5__96   (GL_SMALL_91_5__94  +  75)
#define GL_SMALL_91_5__98   (GL_SMALL_91_5__96  +  95)
#define GL_SMALL_91_5__100  (GL_SMALL_91_5__98  +  50)
#define GL_SMALL_91_5__102  (GL_SMALL_91_5__100 +  25)
#define GL_SMALL_91_5__104  (GL_SMALL_91_5__102 +  30)
#define GL_SMALL_91_5__106  (GL_SMALL_91_5__104 +  10)
#define GL_SMALL_91_5__108  (GL_SMALL_91_5__106 +   5)
#define GL_SMALL_91_5__110  (GL_SMALL_91_5__108 +   5)

// SMALL 92 %
#define GL_SMALL_92__82   50
#define GL_SMALL_92__84   (GL_SMALL_92__82  +  80)
#define GL_SMALL_92__86   (GL_SMALL_92__84  +  80)
#define GL_SMALL_92__88   (GL_SMALL_92__86  + 140)
#define GL_SMALL_92__90   (GL_SMALL_92__88  + 125)
#define GL_SMALL_92__92   (GL_SMALL_92__90  + 150)
#define GL_SMALL_92__94   (GL_SMALL_92__92  + 100)
#define GL_SMALL_92__96   (GL_SMALL_92__94  +  70)
#define GL_SMALL_92__98   (GL_SMALL_92__96  +  70)
#define GL_SMALL_92__100  (GL_SMALL_92__98  +  45)
#define GL_SMALL_92__102  (GL_SMALL_92__100 +  25)
#define GL_SMALL_92__104  (GL_SMALL_92__102 +  25)
#define GL_SMALL_92__106  (GL_SMALL_92__104 +  20)
#define GL_SMALL_92__108  (GL_SMALL_92__106 +  10)
#define GL_SMALL_92__110  (GL_SMALL_92__108 +  10)

// SMALL 92.5 %
#define GL_SMALL_92_5__82   25
#define GL_SMALL_92_5__84   (GL_SMALL_92_5__82  + 145)
#define GL_SMALL_92_5__86   (GL_SMALL_92_5__84  +  50)
#define GL_SMALL_92_5__88   (GL_SMALL_92_5__86  +  90)
#define GL_SMALL_92_5__90   (GL_SMALL_92_5__88  + 125)
#define GL_SMALL_92_5__92   (GL_SMALL_92_5__90  + 140)
#define GL_SMALL_92_5__94   (GL_SMALL_92_5__92  + 110)
#define GL_SMALL_92_5__96   (GL_SMALL_92_5__94  +  80)
#define GL_SMALL_92_5__98   (GL_SMALL_92_5__96  +  70)
#define GL_SMALL_92_5__100  (GL_SMALL_92_5__98  +  55)
#define GL_SMALL_92_5__102  (GL_SMALL_92_5__100 +  40)
#define GL_SMALL_92_5__104  (GL_SMALL_92_5__102 +  25)
#define GL_SMALL_92_5__106  (GL_SMALL_92_5__104 +  15)
#define GL_SMALL_92_5__108  (GL_SMALL_92_5__106 +  15)
#define GL_SMALL_92_5__110  (GL_SMALL_92_5__108 +  15)

// SMALL 93 %
#define GL_SMALL_93__82   10
#define GL_SMALL_93__84   (GL_SMALL_93__82  +  60)
#define GL_SMALL_93__86   (GL_SMALL_93__84  +  80)
#define GL_SMALL_93__88   (GL_SMALL_93__86  + 140)
#define GL_SMALL_93__90   (GL_SMALL_93__88  + 100)
#define GL_SMALL_93__92   (GL_SMALL_93__90  + 150)
#define GL_SMALL_93__94   (GL_SMALL_93__92  + 125)
#define GL_SMALL_93__96   (GL_SMALL_93__94  + 100)
#define GL_SMALL_93__98   (GL_SMALL_93__96  + 100)
#define GL_SMALL_93__100  (GL_SMALL_93__98  +  30)
#define GL_SMALL_93__102  (GL_SMALL_93__100 +  30)
#define GL_SMALL_93__104  (GL_SMALL_93__102 +  30)
#define GL_SMALL_93__106  (GL_SMALL_93__104 +  30)
#define GL_SMALL_93__108  (GL_SMALL_93__106 +  10)
#define GL_SMALL_93__110  (GL_SMALL_93__108 +   5)

// SMALL 93.5 %
#define GL_SMALL_93_5__82   85
#define GL_SMALL_93_5__84   (GL_SMALL_93_5__82  +  20)
#define GL_SMALL_93_5__86   (GL_SMALL_93_5__84  +  10)
#define GL_SMALL_93_5__88   (GL_SMALL_93_5__86  + 140)
#define GL_SMALL_93_5__90   (GL_SMALL_93_5__88  + 125)
#define GL_SMALL_93_5__92   (GL_SMALL_93_5__90  + 150)
#define GL_SMALL_93_5__94   (GL_SMALL_93_5__92  + 100)
#define GL_SMALL_93_5__96   (GL_SMALL_93_5__94  +  70)
#define GL_SMALL_93_5__98   (GL_SMALL_93_5__96  +  70)
#define GL_SMALL_93_5__100  (GL_SMALL_93_5__98  +  70)
#define GL_SMALL_93_5__102  (GL_SMALL_93_5__100 +  70)
#define GL_SMALL_93_5__104  (GL_SMALL_93_5__102 +  50)
#define GL_SMALL_93_5__106  (GL_SMALL_93_5__104 +  20)
#define GL_SMALL_93_5__108  (GL_SMALL_93_5__106 +  10)
#define GL_SMALL_93_5__110  (GL_SMALL_93_5__108 +  10)

// SMALL 94 %
#define GL_SMALL_94__82   40
#define GL_SMALL_94__84   (GL_SMALL_94__82  +  40)
#define GL_SMALL_94__86   (GL_SMALL_94__84  +  60)
#define GL_SMALL_94__88   (GL_SMALL_94__86  +  75)
#define GL_SMALL_94__90   (GL_SMALL_94__88  + 125)
#define GL_SMALL_94__92   (GL_SMALL_94__90  + 145)
#define GL_SMALL_94__94   (GL_SMALL_94__92  + 115)
#define GL_SMALL_94__96   (GL_SMALL_94__94  + 100)
#define GL_SMALL_94__98   (GL_SMALL_94__96  +  80)
#define GL_SMALL_94__100  (GL_SMALL_94__98  +  65)
#define GL_SMALL_94__102  (GL_SMALL_94__100 +  50)
#define GL_SMALL_94__104  (GL_SMALL_94__102 +  40)
#define GL_SMALL_94__106  (GL_SMALL_94__104 +  25)
#define GL_SMALL_94__108  (GL_SMALL_94__106 +  25)
#define GL_SMALL_94__110  (GL_SMALL_94__108 +  15)

// SMALL 94.5 %
#define GL_SMALL_94_5__82   60
#define GL_SMALL_94_5__84   (GL_SMALL_94_5__82  +  40)
#define GL_SMALL_94_5__86   (GL_SMALL_94_5__84  +  10)
#define GL_SMALL_94_5__88   (GL_SMALL_94_5__86  +  75)
#define GL_SMALL_94_5__90   (GL_SMALL_94_5__88  + 125)
#define GL_SMALL_94_5__92   (GL_SMALL_94_5__90  + 145)
#define GL_SMALL_94_5__94   (GL_SMALL_94_5__92  + 115)
#define GL_SMALL_94_5__96   (GL_SMALL_94_5__94  + 100)
#define GL_SMALL_94_5__98   (GL_SMALL_94_5__96  +  80)
#define GL_SMALL_94_5__100  (GL_SMALL_94_5__98  +  65)
#define GL_SMALL_94_5__102  (GL_SMALL_94_5__100 +  50)
#define GL_SMALL_94_5__104  (GL_SMALL_94_5__102 +  50)
#define GL_SMALL_94_5__106  (GL_SMALL_94_5__104 +  45)
#define GL_SMALL_94_5__108  (GL_SMALL_94_5__106 +  25)
#define GL_SMALL_94_5__110  (GL_SMALL_94_5__108 +  15)

// SMALL 95 %
#define GL_SMALL_95__82   15
#define GL_SMALL_95__84   (GL_SMALL_95__82  +  50)
#define GL_SMALL_95__86   (GL_SMALL_95__84  +  20)
#define GL_SMALL_95__88   (GL_SMALL_95__86  +  80)
#define GL_SMALL_95__90   (GL_SMALL_95__88  + 100)
#define GL_SMALL_95__92   (GL_SMALL_95__90  + 145)
#define GL_SMALL_95__94   (GL_SMALL_95__92  + 115)
#define GL_SMALL_95__96   (GL_SMALL_95__94  +  90)
#define GL_SMALL_95__98   (GL_SMALL_95__96  + 100)
#define GL_SMALL_95__100  (GL_SMALL_95__98  +  90)
#define GL_SMALL_95__102  (GL_SMALL_95__100 +  90)
#define GL_SMALL_95__104  (GL_SMALL_95__102 +  75)
#define GL_SMALL_95__106  (GL_SMALL_95__104 +  10)
#define GL_SMALL_95__108  (GL_SMALL_95__106 +  10)
#define GL_SMALL_95__110  (GL_SMALL_95__108 +  10)

// SMALL 95.5 %
#define GL_SMALL_95_5__82   30
#define GL_SMALL_95_5__84   (GL_SMALL_95_5__82  +  10)
#define GL_SMALL_95_5__86   (GL_SMALL_95_5__84  +  25)
#define GL_SMALL_95_5__88   (GL_SMALL_95_5__86  +  75)
#define GL_SMALL_95_5__90   (GL_SMALL_95_5__88  +  50)
#define GL_SMALL_95_5__92   (GL_SMALL_95_5__90  + 145)
#define GL_SMALL_95_5__94   (GL_SMALL_95_5__92  + 115)
#define GL_SMALL_95_5__96   (GL_SMALL_95_5__94  + 100)
#define GL_SMALL_95_5__98   (GL_SMALL_95_5__96  + 150)
#define GL_SMALL_95_5__100  (GL_SMALL_95_5__98  + 150)
#define GL_SMALL_95_5__102  (GL_SMALL_95_5__100 + 110)
#define GL_SMALL_95_5__104  (GL_SMALL_95_5__102 +  10)
#define GL_SMALL_95_5__106  (GL_SMALL_95_5__104 +  10)
#define GL_SMALL_95_5__108  (GL_SMALL_95_5__106 +  10)
#define GL_SMALL_95_5__110  (GL_SMALL_95_5__108 +  10)

// SMALL 96 %
#define GL_SMALL_96__82   5
#define GL_SMALL_96__84   (GL_SMALL_96__82  +  25)
#define GL_SMALL_96__86   (GL_SMALL_96__84  +  40)
#define GL_SMALL_96__88   (GL_SMALL_96__86  +  45)
#define GL_SMALL_96__90   (GL_SMALL_96__88  +  60)
#define GL_SMALL_96__92   (GL_SMALL_96__90  + 125)
#define GL_SMALL_96__94   (GL_SMALL_96__92  + 150)
#define GL_SMALL_96__96   (GL_SMALL_96__94  + 145)
#define GL_SMALL_96__98   (GL_SMALL_96__96  + 100)
#define GL_SMALL_96__100  (GL_SMALL_96__98  +  95)
#define GL_SMALL_96__102  (GL_SMALL_96__100 +  75)
#define GL_SMALL_96__104  (GL_SMALL_96__102 +  75)
#define GL_SMALL_96__106  (GL_SMALL_96__104 +  40)
#define GL_SMALL_96__108  (GL_SMALL_96__106 +  10)
#define GL_SMALL_96__110  (GL_SMALL_96__108 +  10)

// SMALL 96.5 %
#define GL_SMALL_96_5__82   10
#define GL_SMALL_96_5__84   (GL_SMALL_96_5__82  +  30)
#define GL_SMALL_96_5__86   (GL_SMALL_96_5__84  +  20)
#define GL_SMALL_96_5__88   (GL_SMALL_96_5__86  +  25)
#define GL_SMALL_96_5__90   (GL_SMALL_96_5__88  +  60)
#define GL_SMALL_96_5__92   (GL_SMALL_96_5__90  + 115)
#define GL_SMALL_96_5__94   (GL_SMALL_96_5__92  + 145)
#define GL_SMALL_96_5__96   (GL_SMALL_96_5__94  + 150)
#define GL_SMALL_96_5__98   (GL_SMALL_96_5__96  + 100)
#define GL_SMALL_96_5__100  (GL_SMALL_96_5__98  + 100)
#define GL_SMALL_96_5__102  (GL_SMALL_96_5__100 + 115)
#define GL_SMALL_96_5__104  (GL_SMALL_96_5__102 +  70)
#define GL_SMALL_96_5__106  (GL_SMALL_96_5__104 +  40)
#define GL_SMALL_96_5__108  (GL_SMALL_96_5__106 +  10)
#define GL_SMALL_96_5__110  (GL_SMALL_96_5__108 +  10)

// SMALL 97 %
#define GL_SMALL_97__82   45
#define GL_SMALL_97__84   (GL_SMALL_97__82  +  10)
#define GL_SMALL_97__86   (GL_SMALL_97__84  +   5)
#define GL_SMALL_97__88   (GL_SMALL_97__86  +  25)
#define GL_SMALL_97__90   (GL_SMALL_97__88  +  50)
#define GL_SMALL_97__92   (GL_SMALL_97__90  +  75)
#define GL_SMALL_97__94   (GL_SMALL_97__92  + 150)
#define GL_SMALL_97__96   (GL_SMALL_97__94  + 145)
#define GL_SMALL_97__98   (GL_SMALL_97__96  + 100)
#define GL_SMALL_97__100  (GL_SMALL_97__98  + 110)
#define GL_SMALL_97__102  (GL_SMALL_97__100 + 110)
#define GL_SMALL_97__104  (GL_SMALL_97__102 + 120)
#define GL_SMALL_97__106  (GL_SMALL_97__104 +  25)
#define GL_SMALL_97__108  (GL_SMALL_97__106 +  15)
#define GL_SMALL_97__110  (GL_SMALL_97__108 +  15)

// SMALL 97.5 %
#define GL_SMALL_97_5__82   15
#define GL_SMALL_97_5__84   (GL_SMALL_97_5__82  +  15)
#define GL_SMALL_97_5__86   (GL_SMALL_97_5__84  +  15)
#define GL_SMALL_97_5__88   (GL_SMALL_97_5__86  +  25)
#define GL_SMALL_97_5__90   (GL_SMALL_97_5__88  +  50)
#define GL_SMALL_97_5__92   (GL_SMALL_97_5__90  +  75)
#define GL_SMALL_97_5__94   (GL_SMALL_97_5__92  + 150)
#define GL_SMALL_97_5__96   (GL_SMALL_97_5__94  + 145)
#define GL_SMALL_97_5__98   (GL_SMALL_97_5__96  + 100)
#define GL_SMALL_97_5__100  (GL_SMALL_97_5__98  +  95)
#define GL_SMALL_97_5__102  (GL_SMALL_97_5__100 + 110)
#define GL_SMALL_97_5__104  (GL_SMALL_97_5__102 + 120)
#define GL_SMALL_97_5__106  (GL_SMALL_97_5__104 +  55)
#define GL_SMALL_97_5__108  (GL_SMALL_97_5__106 +  15)
#define GL_SMALL_97_5__110  (GL_SMALL_97_5__108 +  15)

// SMALL 98 %
#define GL_SMALL_98__82   25
#define GL_SMALL_98__84   (GL_SMALL_98__82  +  10)
#define GL_SMALL_98__86   (GL_SMALL_98__84  +  15)
#define GL_SMALL_98__88   (GL_SMALL_98__86  +  15)
#define GL_SMALL_98__90   (GL_SMALL_98__88  +  50)
#define GL_SMALL_98__92   (GL_SMALL_98__90  +  75)
#define GL_SMALL_98__94   (GL_SMALL_98__92  + 100)
#define GL_SMALL_98__96   (GL_SMALL_98__94  + 125)
#define GL_SMALL_98__98   (GL_SMALL_98__96  + 150)
#define GL_SMALL_98__100  (GL_SMALL_98__98  + 130)
#define GL_SMALL_98__102  (GL_SMALL_98__100 + 100)
#define GL_SMALL_98__104  (GL_SMALL_98__102 +  75)
#define GL_SMALL_98__106  (GL_SMALL_98__104 +  50)
#define GL_SMALL_98__108  (GL_SMALL_98__106 +  50)
#define GL_SMALL_98__110  (GL_SMALL_98__108 +  30)

// SMALL 98.5 %
#define GL_SMALL_98_5__82   25
#define GL_SMALL_98_5__84   (GL_SMALL_98_5__82  +  10)
#define GL_SMALL_98_5__86   (GL_SMALL_98_5__84  +  10)
#define GL_SMALL_98_5__88   (GL_SMALL_98_5__86  +  15)
#define GL_SMALL_98_5__90   (GL_SMALL_98_5__88  +  25)
#define GL_SMALL_98_5__92   (GL_SMALL_98_5__90  +  75)
#define GL_SMALL_98_5__94   (GL_SMALL_98_5__92  + 100)
#define GL_SMALL_98_5__96   (GL_SMALL_98_5__94  + 125)
#define GL_SMALL_98_5__98   (GL_SMALL_98_5__96  + 150)
#define GL_SMALL_98_5__100  (GL_SMALL_98_5__98  + 130)
#define GL_SMALL_98_5__102  (GL_SMALL_98_5__100 + 100)
#define GL_SMALL_98_5__104  (GL_SMALL_98_5__102 +  85)
#define GL_SMALL_98_5__106  (GL_SMALL_98_5__104 +  60)
#define GL_SMALL_98_5__108  (GL_SMALL_98_5__106 +  60)
#define GL_SMALL_98_5__110  (GL_SMALL_98_5__108 +  30)

// SMALL 99 %
#define GL_SMALL_99__82   10
#define GL_SMALL_99__84   (GL_SMALL_99__82  +  10)
#define GL_SMALL_99__86   (GL_SMALL_99__84  +   5)
#define GL_SMALL_99__88   (GL_SMALL_99__86  +  10)
#define GL_SMALL_99__90   (GL_SMALL_99__88  +  50)
#define GL_SMALL_99__92   (GL_SMALL_99__90  +  60)
#define GL_SMALL_99__94   (GL_SMALL_99__92  +  90)
#define GL_SMALL_99__96   (GL_SMALL_99__94  + 125)
#define GL_SMALL_99__98   (GL_SMALL_99__96  + 150)
#define GL_SMALL_99__100  (GL_SMALL_99__98  + 145)
#define GL_SMALL_99__102  (GL_SMALL_99__100 + 100)
#define GL_SMALL_99__104  (GL_SMALL_99__102 +  75)
#define GL_SMALL_99__106  (GL_SMALL_99__104 +  55)
#define GL_SMALL_99__108  (GL_SMALL_99__106 +  65)
#define GL_SMALL_99__110  (GL_SMALL_99__108 +  50)

// SMALL 99.5 %
#define GL_SMALL_99_5__82   20
#define GL_SMALL_99_5__84   (GL_SMALL_99_5__82  +  10)
#define GL_SMALL_99_5__86   (GL_SMALL_99_5__84  +   5)
#define GL_SMALL_99_5__88   (GL_SMALL_99_5__86  +  10)
#define GL_SMALL_99_5__90   (GL_SMALL_99_5__88  +  10)
#define GL_SMALL_99_5__92   (GL_SMALL_99_5__90  +  50)
#define GL_SMALL_99_5__94   (GL_SMALL_99_5__92  +  85)
#define GL_SMALL_99_5__96   (GL_SMALL_99_5__94  + 125)
#define GL_SMALL_99_5__98   (GL_SMALL_99_5__96  + 150)
#define GL_SMALL_99_5__100  (GL_SMALL_99_5__98  + 145)
#define GL_SMALL_99_5__102  (GL_SMALL_99_5__100 + 125)
#define GL_SMALL_99_5__104  (GL_SMALL_99_5__102 +  75)
#define GL_SMALL_99_5__106  (GL_SMALL_99_5__104 +  75)
#define GL_SMALL_99_5__108  (GL_SMALL_99_5__106 +  65)
#define GL_SMALL_99_5__110  (GL_SMALL_99_5__108 +  50)

// SMALL 100 %
#define GL_SMALL_100__82   35
#define GL_SMALL_100__84   (GL_SMALL_100__82  +  15)
#define GL_SMALL_100__86   (GL_SMALL_100__84  +  15)
#define GL_SMALL_100__88   (GL_SMALL_100__86  +  20)
#define GL_SMALL_100__90   (GL_SMALL_100__88  +  25)
#define GL_SMALL_100__92   (GL_SMALL_100__90  +  75)
#define GL_SMALL_100__94   (GL_SMALL_100__92  +  75)
#define GL_SMALL_100__96   (GL_SMALL_100__94  +  75)
#define GL_SMALL_100__98   (GL_SMALL_100__96  + 100)
#define GL_SMALL_100__100  (GL_SMALL_100__98  +  90)
#define GL_SMALL_100__102  (GL_SMALL_100__100 +  90)
#define GL_SMALL_100__104  (GL_SMALL_100__102 +  60)
#define GL_SMALL_100__106  (GL_SMALL_100__104 +  75)
#define GL_SMALL_100__108  (GL_SMALL_100__106 + 125)
#define GL_SMALL_100__110  (GL_SMALL_100__108 + 125)

// SMALL 101 %
#define GL_SMALL_101__82   5
#define GL_SMALL_101__84   (GL_SMALL_101__82  +  10)
#define GL_SMALL_101__86   (GL_SMALL_101__84  +  25)
#define GL_SMALL_101__88   (GL_SMALL_101__86  +   5)
#define GL_SMALL_101__90   (GL_SMALL_101__88  +   5)
#define GL_SMALL_101__92   (GL_SMALL_101__90  +  40)
#define GL_SMALL_101__94   (GL_SMALL_101__92  +  80)
#define GL_SMALL_101__96   (GL_SMALL_101__94  +  80)
#define GL_SMALL_101__98   (GL_SMALL_101__96  + 125)
#define GL_SMALL_101__100  (GL_SMALL_101__98  + 125)
#define GL_SMALL_101__102  (GL_SMALL_101__100 + 125)
#define GL_SMALL_101__104  (GL_SMALL_101__102 +  60)
#define GL_SMALL_101__106  (GL_SMALL_101__104 +  75)
#define GL_SMALL_101__108  (GL_SMALL_101__106 + 130)
#define GL_SMALL_101__110  (GL_SMALL_101__108 + 110)

// SMALL 102 %
#define GL_SMALL_102__82   20
#define GL_SMALL_102__84   (GL_SMALL_102__82  +  10)
#define GL_SMALL_102__86   (GL_SMALL_102__84  +  25)
#define GL_SMALL_102__88   (GL_SMALL_102__86  +  25)
#define GL_SMALL_102__90   (GL_SMALL_102__88  +  25)
#define GL_SMALL_102__92   (GL_SMALL_102__90  +  25)
#define GL_SMALL_102__94   (GL_SMALL_102__92  +  50)
#define GL_SMALL_102__96   (GL_SMALL_102__94  +  50)
#define GL_SMALL_102__98   (GL_SMALL_102__96  +  75)
#define GL_SMALL_102__100  (GL_SMALL_102__98  +  75)
#define GL_SMALL_102__102  (GL_SMALL_102__100 +  75)
#define GL_SMALL_102__104  (GL_SMALL_102__102 +  75)
#define GL_SMALL_102__106  (GL_SMALL_102__104 + 120)
#define GL_SMALL_102__108  (GL_SMALL_102__106 + 200)
#define GL_SMALL_102__110  (GL_SMALL_102__108 + 150)

// SMALL 104 %
#define GL_SMALL_104__82   20
#define GL_SMALL_104__84   (GL_SMALL_104__82  +   5)
#define GL_SMALL_104__86   (GL_SMALL_104__84  +   5)
#define GL_SMALL_104__88   (GL_SMALL_104__86  +   5)
#define GL_SMALL_104__90   (GL_SMALL_104__88  +  10)
#define GL_SMALL_104__92   (GL_SMALL_104__90  +  10)
#define GL_SMALL_104__94   (GL_SMALL_104__92  +  10)
#define GL_SMALL_104__96   (GL_SMALL_104__94  +  50)
#define GL_SMALL_104__98   (GL_SMALL_104__96  +  75)
#define GL_SMALL_104__100  (GL_SMALL_104__98  +  75)
#define GL_SMALL_104__102  (GL_SMALL_104__100 +  75)
#define GL_SMALL_104__104  (GL_SMALL_104__102 +  75)
#define GL_SMALL_104__106  (GL_SMALL_104__104 + 185)
#define GL_SMALL_104__108  (GL_SMALL_104__106 + 200)
#define GL_SMALL_104__110  (GL_SMALL_104__108 + 200)


// MIDDLE 89 %
#define GL_MIDDLE_89__75   85
#define GL_MIDDLE_89__78   (GL_MIDDLE_89__75  +  55)
#define GL_MIDDLE_89__81   (GL_MIDDLE_89__78  +  90)
#define GL_MIDDLE_89__84   (GL_MIDDLE_89__81  + 150)
#define GL_MIDDLE_89__87   (GL_MIDDLE_89__84  + 140)
#define GL_MIDDLE_89__90   (GL_MIDDLE_89__87  + 125)
#define GL_MIDDLE_89__93   (GL_MIDDLE_89__90  + 125)
#define GL_MIDDLE_89__96   (GL_MIDDLE_89__93  +  75)
#define GL_MIDDLE_89__99   (GL_MIDDLE_89__96  +  75)
#define GL_MIDDLE_89__102  (GL_MIDDLE_89__99  +  20)
#define GL_MIDDLE_89__105  (GL_MIDDLE_89__102 +   5)
#define GL_MIDDLE_89__108  (GL_MIDDLE_89__105 +  10)
#define GL_MIDDLE_89__111  (GL_MIDDLE_89__108 +  20)
#define GL_MIDDLE_89__114  (GL_MIDDLE_89__111 +  10)
#define GL_MIDDLE_89__117  (GL_MIDDLE_89__114 +  15)

// MIDDLE 89 %
#define GL_MIDDLE_89_5__75   50
#define GL_MIDDLE_89_5__78   (GL_MIDDLE_89_5__75  +  80)
#define GL_MIDDLE_89_5__81   (GL_MIDDLE_89_5__78  +  90)
#define GL_MIDDLE_89_5__84   (GL_MIDDLE_89_5__81  + 150)
#define GL_MIDDLE_89_5__87   (GL_MIDDLE_89_5__84  + 140)
#define GL_MIDDLE_89_5__90   (GL_MIDDLE_89_5__87  + 125)
#define GL_MIDDLE_89_5__93   (GL_MIDDLE_89_5__90  + 125)
#define GL_MIDDLE_89_5__96   (GL_MIDDLE_89_5__93  +  70)
#define GL_MIDDLE_89_5__99   (GL_MIDDLE_89_5__96  +  65)
#define GL_MIDDLE_89_5__102  (GL_MIDDLE_89_5__99  +  20)
#define GL_MIDDLE_89_5__105  (GL_MIDDLE_89_5__102 +  20)
#define GL_MIDDLE_89_5__108  (GL_MIDDLE_89_5__105 +  20)
#define GL_MIDDLE_89_5__111  (GL_MIDDLE_89_5__108 +  20)
#define GL_MIDDLE_89_5__114  (GL_MIDDLE_89_5__111 +  10)
#define GL_MIDDLE_89_5__117  (GL_MIDDLE_89_5__114 +  15)

// MIDDLE 90 %
#define GL_MIDDLE_90__75   65
#define GL_MIDDLE_90__78   (GL_MIDDLE_90__75  +  60)
#define GL_MIDDLE_90__81   (GL_MIDDLE_90__78  +  85)
#define GL_MIDDLE_90__84   (GL_MIDDLE_90__81  + 135)
#define GL_MIDDLE_90__87   (GL_MIDDLE_90__84  + 140)
#define GL_MIDDLE_90__90   (GL_MIDDLE_90__87  + 125)
#define GL_MIDDLE_90__93   (GL_MIDDLE_90__90  + 125)
#define GL_MIDDLE_90__96   (GL_MIDDLE_90__93  +  75)
#define GL_MIDDLE_90__99   (GL_MIDDLE_90__96  +  65)
#define GL_MIDDLE_90__102  (GL_MIDDLE_90__99  +  25)
#define GL_MIDDLE_90__105  (GL_MIDDLE_90__102 +  25)
#define GL_MIDDLE_90__108  (GL_MIDDLE_90__105 +  25)
#define GL_MIDDLE_90__111  (GL_MIDDLE_90__108 +  25)
#define GL_MIDDLE_90__114  (GL_MIDDLE_90__111 +  15)
#define GL_MIDDLE_90__117  (GL_MIDDLE_90__114 +  10)

// MIDDLE 90.5 %
#define GL_MIDDLE_90_5__75   40
#define GL_MIDDLE_90_5__78   (GL_MIDDLE_90_5__75  +  55)
#define GL_MIDDLE_90_5__81   (GL_MIDDLE_90_5__78  +  90)
#define GL_MIDDLE_90_5__84   (GL_MIDDLE_90_5__81  + 140)
#define GL_MIDDLE_90_5__87   (GL_MIDDLE_90_5__84  + 140)
#define GL_MIDDLE_90_5__90   (GL_MIDDLE_90_5__87  + 125)
#define GL_MIDDLE_90_5__93   (GL_MIDDLE_90_5__90  + 125)
#define GL_MIDDLE_90_5__96   (GL_MIDDLE_90_5__93  +  90)
#define GL_MIDDLE_90_5__99   (GL_MIDDLE_90_5__96  +  70)
#define GL_MIDDLE_90_5__102  (GL_MIDDLE_90_5__99  +  25)
#define GL_MIDDLE_90_5__105  (GL_MIDDLE_90_5__102 +  25)
#define GL_MIDDLE_90_5__108  (GL_MIDDLE_90_5__105 +  25)
#define GL_MIDDLE_90_5__111  (GL_MIDDLE_90_5__108 +  25)
#define GL_MIDDLE_90_5__114  (GL_MIDDLE_90_5__111 +  15)
#define GL_MIDDLE_90_5__117  (GL_MIDDLE_90_5__114 +  10)

// MIDDLE 91 %
#define GL_MIDDLE_91__75   10
#define GL_MIDDLE_91__78   (GL_MIDDLE_91__75  + 105)
#define GL_MIDDLE_91__81   (GL_MIDDLE_91__78  + 105)
#define GL_MIDDLE_91__84   (GL_MIDDLE_91__81  + 110)
#define GL_MIDDLE_91__87   (GL_MIDDLE_91__84  + 110)
#define GL_MIDDLE_91__90   (GL_MIDDLE_91__87  + 125)
#define GL_MIDDLE_91__93   (GL_MIDDLE_91__90  + 125)
#define GL_MIDDLE_91__96   (GL_MIDDLE_91__93  +  90)
#define GL_MIDDLE_91__99   (GL_MIDDLE_91__96  +  70)
#define GL_MIDDLE_91__102  (GL_MIDDLE_91__99  +  25)
#define GL_MIDDLE_91__105  (GL_MIDDLE_91__102 +  30)
#define GL_MIDDLE_91__108  (GL_MIDDLE_91__105 +  30)
#define GL_MIDDLE_91__111  (GL_MIDDLE_91__108 +  30)
#define GL_MIDDLE_91__114  (GL_MIDDLE_91__111 +  20)
#define GL_MIDDLE_91__117  (GL_MIDDLE_91__114 +  15)

// MIDDLE 91.5 %
#define GL_MIDDLE_91_5__75   25
#define GL_MIDDLE_91_5__78   (GL_MIDDLE_91_5__75  +  90)
#define GL_MIDDLE_91_5__81   (GL_MIDDLE_91_5__78  +  50)
#define GL_MIDDLE_91_5__84   (GL_MIDDLE_91_5__81  + 130)
#define GL_MIDDLE_91_5__87   (GL_MIDDLE_91_5__84  + 140)
#define GL_MIDDLE_91_5__90   (GL_MIDDLE_91_5__87  + 125)
#define GL_MIDDLE_91_5__93   (GL_MIDDLE_91_5__90  + 125)
#define GL_MIDDLE_91_5__96   (GL_MIDDLE_91_5__93  +  80)
#define GL_MIDDLE_91_5__99   (GL_MIDDLE_91_5__96  +  70)
#define GL_MIDDLE_91_5__102  (GL_MIDDLE_91_5__99  +  30)
#define GL_MIDDLE_91_5__105  (GL_MIDDLE_91_5__102 +  30)
#define GL_MIDDLE_91_5__108  (GL_MIDDLE_91_5__105 +  30)
#define GL_MIDDLE_91_5__111  (GL_MIDDLE_91_5__108 +  30)
#define GL_MIDDLE_91_5__114  (GL_MIDDLE_91_5__111 +  25)
#define GL_MIDDLE_91_5__117  (GL_MIDDLE_91_5__114 +  20)

// MIDDLE 92 %
#define GL_MIDDLE_92__75   50
#define GL_MIDDLE_92__78   (GL_MIDDLE_92__75  +  35)
#define GL_MIDDLE_92__81   (GL_MIDDLE_92__78  +  40)
#define GL_MIDDLE_92__84   (GL_MIDDLE_92__81  +  75)
#define GL_MIDDLE_92__87   (GL_MIDDLE_92__84  + 125)
#define GL_MIDDLE_92__90   (GL_MIDDLE_92__87  + 160)
#define GL_MIDDLE_92__93   (GL_MIDDLE_92__90  + 175)
#define GL_MIDDLE_92__96   (GL_MIDDLE_92__93  + 125)
#define GL_MIDDLE_92__99   (GL_MIDDLE_92__96  +  55)
#define GL_MIDDLE_92__102  (GL_MIDDLE_92__99  +  55)
#define GL_MIDDLE_92__105  (GL_MIDDLE_92__102 +  55)
#define GL_MIDDLE_92__108  (GL_MIDDLE_92__105 +  15)
#define GL_MIDDLE_92__111  (GL_MIDDLE_92__108 +  15)
#define GL_MIDDLE_92__114  (GL_MIDDLE_92__111 +  10)
#define GL_MIDDLE_92__117  (GL_MIDDLE_92__114 +  10)

// MIDDLE 92.5 %
#define GL_MIDDLE_92_5__75   10
#define GL_MIDDLE_92_5__78   (GL_MIDDLE_92_5__75  +  60)
#define GL_MIDDLE_92_5__81   (GL_MIDDLE_92_5__78  +  50)
#define GL_MIDDLE_92_5__84   (GL_MIDDLE_92_5__81  +  85)
#define GL_MIDDLE_92_5__87   (GL_MIDDLE_92_5__84  + 100)
#define GL_MIDDLE_92_5__90   (GL_MIDDLE_92_5__87  + 160)
#define GL_MIDDLE_92_5__93   (GL_MIDDLE_92_5__90  + 175)
#define GL_MIDDLE_92_5__96   (GL_MIDDLE_92_5__93  + 150)
#define GL_MIDDLE_92_5__99   (GL_MIDDLE_92_5__96  +  50)
#define GL_MIDDLE_92_5__102  (GL_MIDDLE_92_5__99  +  40)
#define GL_MIDDLE_92_5__105  (GL_MIDDLE_92_5__102 +  40)
#define GL_MIDDLE_92_5__108  (GL_MIDDLE_92_5__105 +  30)
#define GL_MIDDLE_92_5__111  (GL_MIDDLE_92_5__108 +  30)
#define GL_MIDDLE_92_5__114  (GL_MIDDLE_92_5__111 +  10)
#define GL_MIDDLE_92_5__117  (GL_MIDDLE_92_5__114 +  10)

// MIDDLE 93 %
#define GL_MIDDLE_93__75   15
#define GL_MIDDLE_93__78   (GL_MIDDLE_93__75  +  40)
#define GL_MIDDLE_93__81   (GL_MIDDLE_93__78  +  40)
#define GL_MIDDLE_93__84   (GL_MIDDLE_93__81  +  75)
#define GL_MIDDLE_93__87   (GL_MIDDLE_93__84  + 125)
#define GL_MIDDLE_93__90   (GL_MIDDLE_93__87  + 160)
#define GL_MIDDLE_93__93   (GL_MIDDLE_93__90  + 175)
#define GL_MIDDLE_93__96   (GL_MIDDLE_93__93  + 125)
#define GL_MIDDLE_93__99   (GL_MIDDLE_93__96  +  55)
#define GL_MIDDLE_93__102  (GL_MIDDLE_93__99  +  55)
#define GL_MIDDLE_93__105  (GL_MIDDLE_93__102 +  55)
#define GL_MIDDLE_93__108  (GL_MIDDLE_93__105 +  40)
#define GL_MIDDLE_93__111  (GL_MIDDLE_93__108 +  20)
#define GL_MIDDLE_93__114  (GL_MIDDLE_93__111 +  15)
#define GL_MIDDLE_93__117  (GL_MIDDLE_93__114 +   5)

// MIDDLE 93.5 %
#define GL_MIDDLE_93_5__75   35
#define GL_MIDDLE_93_5__78   (GL_MIDDLE_93_5__75  +  50)
#define GL_MIDDLE_93_5__81   (GL_MIDDLE_93_5__78  +  40)
#define GL_MIDDLE_93_5__84   (GL_MIDDLE_93_5__81  +   5)
#define GL_MIDDLE_93_5__87   (GL_MIDDLE_93_5__84  + 125)
#define GL_MIDDLE_93_5__90   (GL_MIDDLE_93_5__87  + 160)
#define GL_MIDDLE_93_5__93   (GL_MIDDLE_93_5__90  + 175)
#define GL_MIDDLE_93_5__96   (GL_MIDDLE_93_5__93  + 125)
#define GL_MIDDLE_93_5__99   (GL_MIDDLE_93_5__96  +  55)
#define GL_MIDDLE_93_5__102  (GL_MIDDLE_93_5__99  +  65)
#define GL_MIDDLE_93_5__105  (GL_MIDDLE_93_5__102 +  75)
#define GL_MIDDLE_93_5__108  (GL_MIDDLE_93_5__105 +  75)
#define GL_MIDDLE_93_5__111  (GL_MIDDLE_93_5__108 +   5)
#define GL_MIDDLE_93_5__114  (GL_MIDDLE_93_5__111 +   5)
#define GL_MIDDLE_93_5__117  (GL_MIDDLE_93_5__114 +   5)


// MIDDLE 94 %
#define GL_MIDDLE_94__75   10
#define GL_MIDDLE_94__78   (GL_MIDDLE_94__75  +  85)
#define GL_MIDDLE_94__81   (GL_MIDDLE_94__78  +  65)
#define GL_MIDDLE_94__84   (GL_MIDDLE_94__81  +  10)
#define GL_MIDDLE_94__87   (GL_MIDDLE_94__84  +  10)
#define GL_MIDDLE_94__90   (GL_MIDDLE_94__87  + 125)
#define GL_MIDDLE_94__93   (GL_MIDDLE_94__90  + 160)
#define GL_MIDDLE_94__96   (GL_MIDDLE_94__93  + 165)
#define GL_MIDDLE_94__99   (GL_MIDDLE_94__96  + 200)
#define GL_MIDDLE_94__102  (GL_MIDDLE_94__99  + 100)
#define GL_MIDDLE_94__105  (GL_MIDDLE_94__102 +  30)
#define GL_MIDDLE_94__108  (GL_MIDDLE_94__105 +  10)
#define GL_MIDDLE_94__111  (GL_MIDDLE_94__108 +   5)
#define GL_MIDDLE_94__114  (GL_MIDDLE_94__111 +  10)
#define GL_MIDDLE_94__117  (GL_MIDDLE_94__114 +  15)

// MIDDLE 94.5 %
#define GL_MIDDLE_94_5__75   15
#define GL_MIDDLE_94_5__78   (GL_MIDDLE_94_5__75  +  25)
#define GL_MIDDLE_94_5__81   (GL_MIDDLE_94_5__78  +  75)
#define GL_MIDDLE_94_5__84   (GL_MIDDLE_94_5__81  +  20)
#define GL_MIDDLE_94_5__87   (GL_MIDDLE_94_5__84  +  20)
#define GL_MIDDLE_94_5__90   (GL_MIDDLE_94_5__87  + 125)
#define GL_MIDDLE_94_5__93   (GL_MIDDLE_94_5__90  + 160)
#define GL_MIDDLE_94_5__96   (GL_MIDDLE_94_5__93  + 225)
#define GL_MIDDLE_94_5__99   (GL_MIDDLE_94_5__96  + 150)
#define GL_MIDDLE_94_5__102  (GL_MIDDLE_94_5__99  + 100)
#define GL_MIDDLE_94_5__105  (GL_MIDDLE_94_5__102 +  50)
#define GL_MIDDLE_94_5__108  (GL_MIDDLE_94_5__105 +  15)
#define GL_MIDDLE_94_5__111  (GL_MIDDLE_94_5__108 +   5)
#define GL_MIDDLE_94_5__114  (GL_MIDDLE_94_5__111 +  10)
#define GL_MIDDLE_94_5__117  (GL_MIDDLE_94_5__114 +   5)

// MIDDLE 95 %
#define GL_MIDDLE_95__75   20
#define GL_MIDDLE_95__78   (GL_MIDDLE_95__75  +  50)
#define GL_MIDDLE_95__81   (GL_MIDDLE_95__78  +  50)
#define GL_MIDDLE_95__84   (GL_MIDDLE_95__81  +  50)
#define GL_MIDDLE_95__87   (GL_MIDDLE_95__84  +  60)
#define GL_MIDDLE_95__90   (GL_MIDDLE_95__87  +  60)
#define GL_MIDDLE_95__93   (GL_MIDDLE_95__90  + 160)
#define GL_MIDDLE_95__96   (GL_MIDDLE_95__93  + 165)
#define GL_MIDDLE_95__99   (GL_MIDDLE_95__96  + 100)
#define GL_MIDDLE_95__102  (GL_MIDDLE_95__99  + 100)
#define GL_MIDDLE_95__105  (GL_MIDDLE_95__102 + 100)
#define GL_MIDDLE_95__108  (GL_MIDDLE_95__105 +  50)
#define GL_MIDDLE_95__111  (GL_MIDDLE_95__108 +  10)
#define GL_MIDDLE_95__114  (GL_MIDDLE_95__111 +  10)
#define GL_MIDDLE_95__117  (GL_MIDDLE_95__114 +  15)

// MIDDLE 95.5 %
#define GL_MIDDLE_95_5__75   10
#define GL_MIDDLE_95_5__78   (GL_MIDDLE_95_5__75  +  50)
#define GL_MIDDLE_95_5__81   (GL_MIDDLE_95_5__78  +  15)
#define GL_MIDDLE_95_5__84   (GL_MIDDLE_95_5__81  +  15)
#define GL_MIDDLE_95_5__87   (GL_MIDDLE_95_5__84  +  15)
#define GL_MIDDLE_95_5__90   (GL_MIDDLE_95_5__87  + 125)
#define GL_MIDDLE_95_5__93   (GL_MIDDLE_95_5__90  + 160)
#define GL_MIDDLE_95_5__96   (GL_MIDDLE_95_5__93  + 165)
#define GL_MIDDLE_95_5__99   (GL_MIDDLE_95_5__96  + 275)
#define GL_MIDDLE_95_5__102  (GL_MIDDLE_95_5__99  + 100)
#define GL_MIDDLE_95_5__105  (GL_MIDDLE_95_5__102 +  30)
#define GL_MIDDLE_95_5__108  (GL_MIDDLE_95_5__105 +  10)
#define GL_MIDDLE_95_5__111  (GL_MIDDLE_95_5__108 +   5)
#define GL_MIDDLE_95_5__114  (GL_MIDDLE_95_5__111 +  10)
#define GL_MIDDLE_95_5__117  (GL_MIDDLE_95_5__114 +  15)

// MIDDLE 96 %
#define GL_MIDDLE_96__75   30
#define GL_MIDDLE_96__78   (GL_MIDDLE_96__75  +  45)
#define GL_MIDDLE_96__81   (GL_MIDDLE_96__78  +  45)
#define GL_MIDDLE_96__84   (GL_MIDDLE_96__81  +  50)
#define GL_MIDDLE_96__87   (GL_MIDDLE_96__84  +  80)
#define GL_MIDDLE_96__90   (GL_MIDDLE_96__87  +  90)
#define GL_MIDDLE_96__93   (GL_MIDDLE_96__90  + 100)
#define GL_MIDDLE_96__96   (GL_MIDDLE_96__93  + 100)
#define GL_MIDDLE_96__99   (GL_MIDDLE_96__96  + 100)
#define GL_MIDDLE_96__102  (GL_MIDDLE_96__99  + 100)
#define GL_MIDDLE_96__105  (GL_MIDDLE_96__102 + 100)
#define GL_MIDDLE_96__108  (GL_MIDDLE_96__105 +  60)
#define GL_MIDDLE_96__111  (GL_MIDDLE_96__108 +  45)
#define GL_MIDDLE_96__114  (GL_MIDDLE_96__111 +  25)
#define GL_MIDDLE_96__117  (GL_MIDDLE_96__114 +  30)

// MIDDLE 96.5 %
#define GL_MIDDLE_96_5__75   20
#define GL_MIDDLE_96_5__78   (GL_MIDDLE_96_5__75  +  35)
#define GL_MIDDLE_96_5__81   (GL_MIDDLE_96_5__78  +  25)
#define GL_MIDDLE_96_5__84   (GL_MIDDLE_96_5__81  +  25)
#define GL_MIDDLE_96_5__87   (GL_MIDDLE_96_5__84  +  40)
#define GL_MIDDLE_96_5__90   (GL_MIDDLE_96_5__87  +  50)
#define GL_MIDDLE_96_5__93   (GL_MIDDLE_96_5__90  + 175)
#define GL_MIDDLE_96_5__96   (GL_MIDDLE_96_5__93  + 200)
#define GL_MIDDLE_96_5__99   (GL_MIDDLE_96_5__96  + 150)
#define GL_MIDDLE_96_5__102  (GL_MIDDLE_96_5__99  + 100)
#define GL_MIDDLE_96_5__105  (GL_MIDDLE_96_5__102 +  60)
#define GL_MIDDLE_96_5__108  (GL_MIDDLE_96_5__105 +  40)
#define GL_MIDDLE_96_5__111  (GL_MIDDLE_96_5__108 +  50)
#define GL_MIDDLE_96_5__114  (GL_MIDDLE_96_5__111 +  15)
#define GL_MIDDLE_96_5__117  (GL_MIDDLE_96_5__114 +  15)

// MIDDLE 97 %
#define GL_MIDDLE_97__75   65
#define GL_MIDDLE_97__78   (GL_MIDDLE_97__75  +  10)
#define GL_MIDDLE_97__81   (GL_MIDDLE_97__78  +  45)
#define GL_MIDDLE_97__84   (GL_MIDDLE_97__81  +  45)
#define GL_MIDDLE_97__87   (GL_MIDDLE_97__84  +  40)
#define GL_MIDDLE_97__90   (GL_MIDDLE_97__87  +  55)
#define GL_MIDDLE_97__93   (GL_MIDDLE_97__90  +  55)
#define GL_MIDDLE_97__96   (GL_MIDDLE_97__93  + 100)
#define GL_MIDDLE_97__99   (GL_MIDDLE_97__96  + 150)
#define GL_MIDDLE_97__102  (GL_MIDDLE_97__99  + 150)
#define GL_MIDDLE_97__105  (GL_MIDDLE_97__102 + 150)
#define GL_MIDDLE_97__108  (GL_MIDDLE_97__105 +  65)
#define GL_MIDDLE_97__111  (GL_MIDDLE_97__108 +  50)
#define GL_MIDDLE_97__114  (GL_MIDDLE_97__111 +  10)
#define GL_MIDDLE_97__117  (GL_MIDDLE_97__114 +  10)

// MIDDLE 97.5 %
#define GL_MIDDLE_97_5__75   60
#define GL_MIDDLE_97_5__78   (GL_MIDDLE_97_5__75  +  20)
#define GL_MIDDLE_97_5__81   (GL_MIDDLE_97_5__78  +  20)
#define GL_MIDDLE_97_5__84   (GL_MIDDLE_97_5__81  +  25)
#define GL_MIDDLE_97_5__87   (GL_MIDDLE_97_5__84  +  50)
#define GL_MIDDLE_97_5__90   (GL_MIDDLE_97_5__87  +  50)
#define GL_MIDDLE_97_5__93   (GL_MIDDLE_97_5__90  +  75)
#define GL_MIDDLE_97_5__96   (GL_MIDDLE_97_5__93  +  75)
#define GL_MIDDLE_97_5__99   (GL_MIDDLE_97_5__96  + 150)
#define GL_MIDDLE_97_5__102  (GL_MIDDLE_97_5__99  + 210)
#define GL_MIDDLE_97_5__105  (GL_MIDDLE_97_5__102 + 150)
#define GL_MIDDLE_97_5__108  (GL_MIDDLE_97_5__105 +  75)
#define GL_MIDDLE_97_5__111  (GL_MIDDLE_97_5__108 +  10)
#define GL_MIDDLE_97_5__114  (GL_MIDDLE_97_5__111 +  15)
#define GL_MIDDLE_97_5__117  (GL_MIDDLE_97_5__114 +  15)

// MIDDLE 98 %
#define GL_MIDDLE_98__75   40
#define GL_MIDDLE_98__78   (GL_MIDDLE_98__75  +  25)
#define GL_MIDDLE_98__81   (GL_MIDDLE_98__78  +  40)
#define GL_MIDDLE_98__84   (GL_MIDDLE_98__81  +  40)
#define GL_MIDDLE_98__87   (GL_MIDDLE_98__84  +  40)
#define GL_MIDDLE_98__90   (GL_MIDDLE_98__87  +  40)
#define GL_MIDDLE_98__93   (GL_MIDDLE_98__90  +  75)
#define GL_MIDDLE_98__96   (GL_MIDDLE_98__93  + 110)
#define GL_MIDDLE_98__99   (GL_MIDDLE_98__96  + 125)
#define GL_MIDDLE_98__102  (GL_MIDDLE_98__99  + 125)
#define GL_MIDDLE_98__105  (GL_MIDDLE_98__102 + 125)
#define GL_MIDDLE_98__108  (GL_MIDDLE_98__105 + 150)
#define GL_MIDDLE_98__111  (GL_MIDDLE_98__108 +  25)
#define GL_MIDDLE_98__114  (GL_MIDDLE_98__111 +  25)
#define GL_MIDDLE_98__117  (GL_MIDDLE_98__114 +  15)

// MIDDLE 98.5 %
#define GL_MIDDLE_98_5__75   45
#define GL_MIDDLE_98_5__78   (GL_MIDDLE_98_5__75  +  20)
#define GL_MIDDLE_98_5__81   (GL_MIDDLE_98_5__78  +  25)
#define GL_MIDDLE_98_5__84   (GL_MIDDLE_98_5__81  +  25)
#define GL_MIDDLE_98_5__87   (GL_MIDDLE_98_5__84  +  25)
#define GL_MIDDLE_98_5__90   (GL_MIDDLE_98_5__87  +  15)
#define GL_MIDDLE_98_5__93   (GL_MIDDLE_98_5__90  +  50)
#define GL_MIDDLE_98_5__96   (GL_MIDDLE_98_5__93  + 200)
#define GL_MIDDLE_98_5__99   (GL_MIDDLE_98_5__96  + 150)
#define GL_MIDDLE_98_5__102  (GL_MIDDLE_98_5__99  + 125)
#define GL_MIDDLE_98_5__105  (GL_MIDDLE_98_5__102 + 190)
#define GL_MIDDLE_98_5__108  (GL_MIDDLE_98_5__105 +  50)
#define GL_MIDDLE_98_5__111  (GL_MIDDLE_98_5__108 +  25)
#define GL_MIDDLE_98_5__114  (GL_MIDDLE_98_5__111 +  30)
#define GL_MIDDLE_98_5__117  (GL_MIDDLE_98_5__114 +  25)

// MIDDLE 99 %
#define GL_MIDDLE_99__75   25
#define GL_MIDDLE_99__78   (GL_MIDDLE_99__75  +  20)
#define GL_MIDDLE_99__81   (GL_MIDDLE_99__78  +  15)
#define GL_MIDDLE_99__84   (GL_MIDDLE_99__81  +  40)
#define GL_MIDDLE_99__87   (GL_MIDDLE_99__84  +  40)
#define GL_MIDDLE_99__90   (GL_MIDDLE_99__87  +  25)
#define GL_MIDDLE_99__93   (GL_MIDDLE_99__90  +  80)
#define GL_MIDDLE_99__96   (GL_MIDDLE_99__93  + 140)
#define GL_MIDDLE_99__99   (GL_MIDDLE_99__96  + 125)
#define GL_MIDDLE_99__102  (GL_MIDDLE_99__99  + 140)
#define GL_MIDDLE_99__105  (GL_MIDDLE_99__102 + 175)
#define GL_MIDDLE_99__108  (GL_MIDDLE_99__105 + 100)
#define GL_MIDDLE_99__111  (GL_MIDDLE_99__108 +  25)
#define GL_MIDDLE_99__114  (GL_MIDDLE_99__111 +  25)
#define GL_MIDDLE_99__117  (GL_MIDDLE_99__114 +  25)

// MIDDLE 99.5 %
#define GL_MIDDLE_99_5__75   15
#define GL_MIDDLE_99_5__78   (GL_MIDDLE_99_5__75  +  15)
#define GL_MIDDLE_99_5__81   (GL_MIDDLE_99_5__78  +  30)
#define GL_MIDDLE_99_5__84   (GL_MIDDLE_99_5__81  +  30)
#define GL_MIDDLE_99_5__87   (GL_MIDDLE_99_5__84  +  30)
#define GL_MIDDLE_99_5__90   (GL_MIDDLE_99_5__87  +  25)
#define GL_MIDDLE_99_5__93   (GL_MIDDLE_99_5__90  +  80)
#define GL_MIDDLE_99_5__96   (GL_MIDDLE_99_5__93  + 150)
#define GL_MIDDLE_99_5__99   (GL_MIDDLE_99_5__96  + 125)
#define GL_MIDDLE_99_5__102  (GL_MIDDLE_99_5__99  + 150)
#define GL_MIDDLE_99_5__105  (GL_MIDDLE_99_5__102 + 175)
#define GL_MIDDLE_99_5__108  (GL_MIDDLE_99_5__105 +  50)
#define GL_MIDDLE_99_5__111  (GL_MIDDLE_99_5__108 +  75)
#define GL_MIDDLE_99_5__114  (GL_MIDDLE_99_5__111 +  25)
#define GL_MIDDLE_99_5__117  (GL_MIDDLE_99_5__114 +  25)

// MIDDLE 100 %
#define GL_MIDDLE_100__75   40
#define GL_MIDDLE_100__78   (GL_MIDDLE_100__75  +  20)
#define GL_MIDDLE_100__81   (GL_MIDDLE_100__78  +  35)
#define GL_MIDDLE_100__84   (GL_MIDDLE_100__81  +  35)
#define GL_MIDDLE_100__87   (GL_MIDDLE_100__84  +  35)
#define GL_MIDDLE_100__90   (GL_MIDDLE_100__87  +  45)
#define GL_MIDDLE_100__93   (GL_MIDDLE_100__90  +  50)
#define GL_MIDDLE_100__96   (GL_MIDDLE_100__93  +  80)
#define GL_MIDDLE_100__99   (GL_MIDDLE_100__96  + 125)
#define GL_MIDDLE_100__102  (GL_MIDDLE_100__99  + 125)
#define GL_MIDDLE_100__105  (GL_MIDDLE_100__102 + 125)
#define GL_MIDDLE_100__108  (GL_MIDDLE_100__105 +  75)
#define GL_MIDDLE_100__111  (GL_MIDDLE_100__108 +  75)
#define GL_MIDDLE_100__114  (GL_MIDDLE_100__111 +  75)
#define GL_MIDDLE_100__117  (GL_MIDDLE_100__114 +  60)

// MIDDLE 101 %
#define GL_MIDDLE_101__75   10
#define GL_MIDDLE_101__78   (GL_MIDDLE_101__75  +  40)
#define GL_MIDDLE_101__81   (GL_MIDDLE_101__78  +  30)
#define GL_MIDDLE_101__84   (GL_MIDDLE_101__81  +  30)
#define GL_MIDDLE_101__87   (GL_MIDDLE_101__84  +  35)
#define GL_MIDDLE_101__90   (GL_MIDDLE_101__87  +  45)
#define GL_MIDDLE_101__93   (GL_MIDDLE_101__90  +  50)
#define GL_MIDDLE_101__96   (GL_MIDDLE_101__93  +  80)
#define GL_MIDDLE_101__99   (GL_MIDDLE_101__96  +  50)
#define GL_MIDDLE_101__102  (GL_MIDDLE_101__99  + 200)
#define GL_MIDDLE_101__105  (GL_MIDDLE_101__102 + 130)
#define GL_MIDDLE_101__108  (GL_MIDDLE_101__105 +  75)
#define GL_MIDDLE_101__111  (GL_MIDDLE_101__108 +  75)
#define GL_MIDDLE_101__114  (GL_MIDDLE_101__111 +  75)
#define GL_MIDDLE_101__117  (GL_MIDDLE_101__114 +  75)

// MIDDLE 102 %
#define GL_MIDDLE_102__75   25
#define GL_MIDDLE_102__78   (GL_MIDDLE_102__75  +  30)
#define GL_MIDDLE_102__81   (GL_MIDDLE_102__78  +  30)
#define GL_MIDDLE_102__84   (GL_MIDDLE_102__81  +  25)
#define GL_MIDDLE_102__87   (GL_MIDDLE_102__84  +  25)
#define GL_MIDDLE_102__90   (GL_MIDDLE_102__87  +  35)
#define GL_MIDDLE_102__93   (GL_MIDDLE_102__90  +  50)
#define GL_MIDDLE_102__96   (GL_MIDDLE_102__93  +  50)
#define GL_MIDDLE_102__99   (GL_MIDDLE_102__96  + 100)
#define GL_MIDDLE_102__102  (GL_MIDDLE_102__99  + 125)
#define GL_MIDDLE_102__105  (GL_MIDDLE_102__102 + 140)
#define GL_MIDDLE_102__108  (GL_MIDDLE_102__105 + 100)
#define GL_MIDDLE_102__111  (GL_MIDDLE_102__108 +  75)
#define GL_MIDDLE_102__114  (GL_MIDDLE_102__111 +  75)
#define GL_MIDDLE_102__117  (GL_MIDDLE_102__114 + 115)

// MIDDLE 104 %
#define GL_MIDDLE_104__75   10
#define GL_MIDDLE_104__78   (GL_MIDDLE_104__75  +  25)
#define GL_MIDDLE_104__81   (GL_MIDDLE_104__78  +  10)
#define GL_MIDDLE_104__84   (GL_MIDDLE_104__81  +  10)
#define GL_MIDDLE_104__87   (GL_MIDDLE_104__84  +  25)
#define GL_MIDDLE_104__90   (GL_MIDDLE_104__87  +  25)
#define GL_MIDDLE_104__93   (GL_MIDDLE_104__90  +  25)
#define GL_MIDDLE_104__96   (GL_MIDDLE_104__93  +  25)
#define GL_MIDDLE_104__99   (GL_MIDDLE_104__96  +  90)
#define GL_MIDDLE_104__102  (GL_MIDDLE_104__99  +  75)
#define GL_MIDDLE_104__105  (GL_MIDDLE_104__102 + 150)
#define GL_MIDDLE_104__108  (GL_MIDDLE_104__105 + 325)
#define GL_MIDDLE_104__111  (GL_MIDDLE_104__108 + 125)
#define GL_MIDDLE_104__114  (GL_MIDDLE_104__111 +  50)
#define GL_MIDDLE_104__117  (GL_MIDDLE_104__114 +  30)


// BIG 89 %
#define GL_BIG_89__72   105
#define GL_BIG_89__75   (GL_BIG_89__72  + 195)
#define GL_BIG_89__80   (GL_BIG_89__75  + 140)
#define GL_BIG_89__84   (GL_BIG_89__80  +  90)
#define GL_BIG_89__88   (GL_BIG_89__84  + 100)
#define GL_BIG_89__92   (GL_BIG_89__88  +  65)
#define GL_BIG_89__96   (GL_BIG_89__92  +  60)
#define GL_BIG_89__100  (GL_BIG_89__96  +  70)
#define GL_BIG_89__104  (GL_BIG_89__100 +  10)
#define GL_BIG_89__108  (GL_BIG_89__104 +  10)
#define GL_BIG_89__112  (GL_BIG_89__108 +  20)
#define GL_BIG_89__117  (GL_BIG_89__112 + 100)
#define GL_BIG_89__123  (GL_BIG_89__117 +  10)
#define GL_BIG_89__128  (GL_BIG_89__123 +  20)
#define GL_BIG_89__133  (GL_BIG_89__128 +   5)

// BIG 89.5 %
#define GL_BIG_89_5__72   75
#define GL_BIG_89_5__75   (GL_BIG_89_5__72  + 230)
#define GL_BIG_89_5__80   (GL_BIG_89_5__75  + 140)
#define GL_BIG_89_5__84   (GL_BIG_89_5__80  +  90)
#define GL_BIG_89_5__88   (GL_BIG_89_5__84  +  95)
#define GL_BIG_89_5__92   (GL_BIG_89_5__88  +  60)
#define GL_BIG_89_5__96   (GL_BIG_89_5__92  +  50)
#define GL_BIG_89_5__100  (GL_BIG_89_5__96  +  70)
#define GL_BIG_89_5__104  (GL_BIG_89_5__100 +  10)
#define GL_BIG_89_5__108  (GL_BIG_89_5__104 +  10)
#define GL_BIG_89_5__112  (GL_BIG_89_5__108 +  20)
#define GL_BIG_89_5__117  (GL_BIG_89_5__112 + 100)
#define GL_BIG_89_5__123  (GL_BIG_89_5__117 +  20)
#define GL_BIG_89_5__128  (GL_BIG_89_5__123 +  20)
#define GL_BIG_89_5__133  (GL_BIG_89_5__128 +  10)

// BIG 90 %
#define GL_BIG_90__72   120
#define GL_BIG_90__75   (GL_BIG_90__72  + 165)
#define GL_BIG_90__80   (GL_BIG_90__75  + 140)
#define GL_BIG_90__84   (GL_BIG_90__80  +  90)
#define GL_BIG_90__88   (GL_BIG_90__84  + 100)
#define GL_BIG_90__92   (GL_BIG_90__88  +  60)
#define GL_BIG_90__96   (GL_BIG_90__92  +  50)
#define GL_BIG_90__100  (GL_BIG_90__96  +  75)
#define GL_BIG_90__104  (GL_BIG_90__100 +  10)
#define GL_BIG_90__108  (GL_BIG_90__104 +   5)
#define GL_BIG_90__112  (GL_BIG_90__108 +  30)
#define GL_BIG_90__117  (GL_BIG_90__112 + 100)
#define GL_BIG_90__123  (GL_BIG_90__117 +  25)
#define GL_BIG_90__128  (GL_BIG_90__123 +  20)
#define GL_BIG_90__133  (GL_BIG_90__128 +  10)

// BIG 90.5 %
#define GL_BIG_90_5__72   90
#define GL_BIG_90_5__75   (GL_BIG_90_5__72  + 185)
#define GL_BIG_90_5__80   (GL_BIG_90_5__75  + 135)
#define GL_BIG_90_5__84   (GL_BIG_90_5__80  +  90)
#define GL_BIG_90_5__88   (GL_BIG_90_5__84  + 100)
#define GL_BIG_90_5__92   (GL_BIG_90_5__88  +  60)
#define GL_BIG_90_5__96   (GL_BIG_90_5__92  +  50)
#define GL_BIG_90_5__100  (GL_BIG_90_5__96  +  75)
#define GL_BIG_90_5__104  (GL_BIG_90_5__100 +  10)
#define GL_BIG_90_5__108  (GL_BIG_90_5__104 +   5)
#define GL_BIG_90_5__112  (GL_BIG_90_5__108 +  70)
#define GL_BIG_90_5__117  (GL_BIG_90_5__112 +  75)
#define GL_BIG_90_5__123  (GL_BIG_90_5__117 +  25)
#define GL_BIG_90_5__128  (GL_BIG_90_5__123 +  20)
#define GL_BIG_90_5__133  (GL_BIG_90_5__128 +  10)

// BIG 91 %
#define GL_BIG_91__72   85
#define GL_BIG_91__75   (GL_BIG_91__72  + 155)
#define GL_BIG_91__80   (GL_BIG_91__75  + 135)
#define GL_BIG_91__84   (GL_BIG_91__80  + 100)
#define GL_BIG_91__88   (GL_BIG_91__84  + 100)
#define GL_BIG_91__92   (GL_BIG_91__88  +  75)
#define GL_BIG_91__96   (GL_BIG_91__92  +  75)
#define GL_BIG_91__100  (GL_BIG_91__96  +  75)
#define GL_BIG_91__104  (GL_BIG_91__100 +   5)
#define GL_BIG_91__108  (GL_BIG_91__104 +   5)
#define GL_BIG_91__112  (GL_BIG_91__108 +  30)
#define GL_BIG_91__117  (GL_BIG_91__112 + 100)
#define GL_BIG_91__123  (GL_BIG_91__117 +  40)
#define GL_BIG_91__128  (GL_BIG_91__123 +  10)
#define GL_BIG_91__133  (GL_BIG_91__128 +  10)

// BIG 91.5 %
#define GL_BIG_91_5__72   50
#define GL_BIG_91_5__75   (GL_BIG_91_5__72  + 185)
#define GL_BIG_91_5__80   (GL_BIG_91_5__75  + 140)
#define GL_BIG_91_5__84   (GL_BIG_91_5__80  + 100)
#define GL_BIG_91_5__88   (GL_BIG_91_5__84  + 100)
#define GL_BIG_91_5__92   (GL_BIG_91_5__88  +  65)
#define GL_BIG_91_5__96   (GL_BIG_91_5__92  +  50)
#define GL_BIG_91_5__100  (GL_BIG_91_5__96  +  75)
#define GL_BIG_91_5__104  (GL_BIG_91_5__100 +  10)
#define GL_BIG_91_5__108  (GL_BIG_91_5__104 +  20)
#define GL_BIG_91_5__112  (GL_BIG_91_5__108 +  75)
#define GL_BIG_91_5__117  (GL_BIG_91_5__112 +  75)
#define GL_BIG_91_5__123  (GL_BIG_91_5__117 +  25)
#define GL_BIG_91_5__128  (GL_BIG_91_5__123 +  20)
#define GL_BIG_91_5__133  (GL_BIG_91_5__128 +  10)

// BIG 92 %
#define GL_BIG_92__72   105
#define GL_BIG_92__75   (GL_BIG_92__72  + 120)
#define GL_BIG_92__80   (GL_BIG_92__75  + 150)
#define GL_BIG_92__84   (GL_BIG_92__80  + 100)
#define GL_BIG_92__88   (GL_BIG_92__84  +  75)
#define GL_BIG_92__92   (GL_BIG_92__88  +  50)
#define GL_BIG_92__96   (GL_BIG_92__92  +  50)
#define GL_BIG_92__100  (GL_BIG_92__96  +  75)
#define GL_BIG_92__104  (GL_BIG_92__100 +  75)
#define GL_BIG_92__108  (GL_BIG_92__104 +   5)
#define GL_BIG_92__112  (GL_BIG_92__108 +  30)
#define GL_BIG_92__117  (GL_BIG_92__112 + 110)
#define GL_BIG_92__123  (GL_BIG_92__117 +  25)
#define GL_BIG_92__128  (GL_BIG_92__123 +  20)
#define GL_BIG_92__133  (GL_BIG_92__128 +  10)

// BIG 92.5 %
#define GL_BIG_92_5__72   55
#define GL_BIG_92_5__75   (GL_BIG_92_5__72  + 155)
#define GL_BIG_92_5__80   (GL_BIG_92_5__75  + 150)
#define GL_BIG_92_5__84   (GL_BIG_92_5__80  + 100)
#define GL_BIG_92_5__88   (GL_BIG_92_5__84  +  75)
#define GL_BIG_92_5__92   (GL_BIG_92_5__88  +  50)
#define GL_BIG_92_5__96   (GL_BIG_92_5__92  +  50)
#define GL_BIG_92_5__100  (GL_BIG_92_5__96  +  75)
#define GL_BIG_92_5__104  (GL_BIG_92_5__100 +  75)
#define GL_BIG_92_5__108  (GL_BIG_92_5__104 +  35)
#define GL_BIG_92_5__112  (GL_BIG_92_5__108 +  30)
#define GL_BIG_92_5__117  (GL_BIG_92_5__112 + 100)
#define GL_BIG_92_5__123  (GL_BIG_92_5__117 +  20)
#define GL_BIG_92_5__128  (GL_BIG_92_5__123 +  15)
#define GL_BIG_92_5__133  (GL_BIG_92_5__128 +  15)

// BIG 93 %
#define GL_BIG_93__72   50
#define GL_BIG_93__75   (GL_BIG_93__72  + 170)
#define GL_BIG_93__80   (GL_BIG_93__75  + 150)
#define GL_BIG_93__84   (GL_BIG_93__80  + 100)
#define GL_BIG_93__88   (GL_BIG_93__84  +  75)
#define GL_BIG_93__92   (GL_BIG_93__88  +  50)
#define GL_BIG_93__96   (GL_BIG_93__92  +  50)
#define GL_BIG_93__100  (GL_BIG_93__96  +  75)
#define GL_BIG_93__104  (GL_BIG_93__100 +  75)
#define GL_BIG_93__108  (GL_BIG_93__104 +   5)
#define GL_BIG_93__112  (GL_BIG_93__108 +  20)
#define GL_BIG_93__117  (GL_BIG_93__112 +  75)
#define GL_BIG_93__123  (GL_BIG_93__117 +  20)
#define GL_BIG_93__128  (GL_BIG_93__123 +  75)
#define GL_BIG_93__133  (GL_BIG_93__128 +  10)

// BIG 93.5 %
#define GL_BIG_93_5__72   80
#define GL_BIG_93_5__75   (GL_BIG_93_5__72  + 125)
#define GL_BIG_93_5__80   (GL_BIG_93_5__75  + 150)
#define GL_BIG_93_5__84   (GL_BIG_93_5__80  + 100)
#define GL_BIG_93_5__88   (GL_BIG_93_5__84  +  75)
#define GL_BIG_93_5__92   (GL_BIG_93_5__88  +  50)
#define GL_BIG_93_5__96   (GL_BIG_93_5__92  +  50)
#define GL_BIG_93_5__100  (GL_BIG_93_5__96  +  75)
#define GL_BIG_93_5__104  (GL_BIG_93_5__100 +  80)
#define GL_BIG_93_5__108  (GL_BIG_93_5__104 +   5)
#define GL_BIG_93_5__112  (GL_BIG_93_5__108 +  30)
#define GL_BIG_93_5__117  (GL_BIG_93_5__112 +  50)
#define GL_BIG_93_5__123  (GL_BIG_93_5__117 +  60)
#define GL_BIG_93_5__128  (GL_BIG_93_5__123 +  60)
#define GL_BIG_93_5__133  (GL_BIG_93_5__128 +  10)

// BIG 94 %
#define GL_BIG_94__72   45
#define GL_BIG_94__75   (GL_BIG_94__72  + 120)
#define GL_BIG_94__80   (GL_BIG_94__75  + 150)
#define GL_BIG_94__84   (GL_BIG_94__80  + 140)
#define GL_BIG_94__88   (GL_BIG_94__84  +  75)
#define GL_BIG_94__92   (GL_BIG_94__88  +  45)
#define GL_BIG_94__96   (GL_BIG_94__92  +  50)
#define GL_BIG_94__100  (GL_BIG_94__96  +  75)
#define GL_BIG_94__104  (GL_BIG_94__100 +  60)
#define GL_BIG_94__108  (GL_BIG_94__104 +  25)
#define GL_BIG_94__112  (GL_BIG_94__108 +  25)
#define GL_BIG_94__117  (GL_BIG_94__112 + 100)
#define GL_BIG_94__123  (GL_BIG_94__117 +  30)
#define GL_BIG_94__128  (GL_BIG_94__123 +  30)
#define GL_BIG_94__133  (GL_BIG_94__128 +  30)

// BIG 94.5 %
#define GL_BIG_94_5__72   95
#define GL_BIG_94_5__75   (GL_BIG_94_5__72  +  80)
#define GL_BIG_94_5__80   (GL_BIG_94_5__75  + 150)
#define GL_BIG_94_5__84   (GL_BIG_94_5__80  + 100)
#define GL_BIG_94_5__88   (GL_BIG_94_5__84  +  75)
#define GL_BIG_94_5__92   (GL_BIG_94_5__88  +  45)
#define GL_BIG_94_5__96   (GL_BIG_94_5__92  +  50)
#define GL_BIG_94_5__100  (GL_BIG_94_5__96  +  75)
#define GL_BIG_94_5__104  (GL_BIG_94_5__100 +  60)
#define GL_BIG_94_5__108  (GL_BIG_94_5__104 +  50)
#define GL_BIG_94_5__112  (GL_BIG_94_5__108 +  30)
#define GL_BIG_94_5__117  (GL_BIG_94_5__112 + 100)
#define GL_BIG_94_5__123  (GL_BIG_94_5__117 +  30)
#define GL_BIG_94_5__128  (GL_BIG_94_5__123 +  30)
#define GL_BIG_94_5__133  (GL_BIG_94_5__128 +  30)

// BIG 95 %
#define GL_BIG_95__72   120
#define GL_BIG_95__75   (GL_BIG_95__72  +  30)
#define GL_BIG_95__80   (GL_BIG_95__75  + 150)
#define GL_BIG_95__84   (GL_BIG_95__80  + 140)
#define GL_BIG_95__88   (GL_BIG_95__84  +  75)
#define GL_BIG_95__92   (GL_BIG_95__88  +  45)
#define GL_BIG_95__96   (GL_BIG_95__92  +  50)
#define GL_BIG_95__100  (GL_BIG_95__96  +  75)
#define GL_BIG_95__104  (GL_BIG_95__100 +  65)
#define GL_BIG_95__108  (GL_BIG_95__104 +  25)
#define GL_BIG_95__112  (GL_BIG_95__108 +  25)
#define GL_BIG_95__117  (GL_BIG_95__112 +  50)
#define GL_BIG_95__123  (GL_BIG_95__117 +  50)
#define GL_BIG_95__128  (GL_BIG_95__123 +  50)
#define GL_BIG_95__133  (GL_BIG_95__128 +  50)

// BIG 95.5 %
#define GL_BIG_95_5__72   45
#define GL_BIG_95_5__75   (GL_BIG_95_5__72  + 180)
#define GL_BIG_95_5__80   (GL_BIG_95_5__75  + 100)
#define GL_BIG_95_5__84   (GL_BIG_95_5__80  +  75)
#define GL_BIG_95_5__88   (GL_BIG_95_5__84  +  75)
#define GL_BIG_95_5__92   (GL_BIG_95_5__88  +  50)
#define GL_BIG_95_5__96   (GL_BIG_95_5__92  +  50)
#define GL_BIG_95_5__100  (GL_BIG_95_5__96  +  75)
#define GL_BIG_95_5__104  (GL_BIG_95_5__100 +  60)
#define GL_BIG_95_5__108  (GL_BIG_95_5__104 +  20)
#define GL_BIG_95_5__112  (GL_BIG_95_5__108 +  50)
#define GL_BIG_95_5__117  (GL_BIG_95_5__112 + 100)
#define GL_BIG_95_5__123  (GL_BIG_95_5__117 +  50)
#define GL_BIG_95_5__128  (GL_BIG_95_5__123 +  40)
#define GL_BIG_95_5__133  (GL_BIG_95_5__128 +  30)

// BIG 96 %
#define GL_BIG_96__72   25
#define GL_BIG_96__75   (GL_BIG_96__72  +  90)
#define GL_BIG_96__80   (GL_BIG_96__75  + 150)
#define GL_BIG_96__84   (GL_BIG_96__80  + 140)
#define GL_BIG_96__88   (GL_BIG_96__84  +  75)
#define GL_BIG_96__92   (GL_BIG_96__88  +  45)
#define GL_BIG_96__96   (GL_BIG_96__92  +  50)
#define GL_BIG_96__100  (GL_BIG_96__96  +  75)
#define GL_BIG_96__104  (GL_BIG_96__100 +  60)
#define GL_BIG_96__108  (GL_BIG_96__104 +  75)
#define GL_BIG_96__112  (GL_BIG_96__108 +  50)
#define GL_BIG_96__117  (GL_BIG_96__112 +  40)
#define GL_BIG_96__123  (GL_BIG_96__117 +  40)
#define GL_BIG_96__128  (GL_BIG_96__123 +  40)
#define GL_BIG_96__133  (GL_BIG_96__128 +  45)

// BIG 96.5 %
#define GL_BIG_96_5__72   130
#define GL_BIG_96_5__75   (GL_BIG_96_5__72  +  30)
#define GL_BIG_96_5__80   (GL_BIG_96_5__75  + 100)
#define GL_BIG_96_5__84   (GL_BIG_96_5__80  + 110)
#define GL_BIG_96_5__88   (GL_BIG_96_5__84  +  80)
#define GL_BIG_96_5__92   (GL_BIG_96_5__88  +  45)
#define GL_BIG_96_5__96   (GL_BIG_96_5__92  +  60)
#define GL_BIG_96_5__100  (GL_BIG_96_5__96  +  75)
#define GL_BIG_96_5__104  (GL_BIG_96_5__100 +  60)
#define GL_BIG_96_5__108  (GL_BIG_96_5__104 +  75)
#define GL_BIG_96_5__112  (GL_BIG_96_5__108 +  50)
#define GL_BIG_96_5__117  (GL_BIG_96_5__112 +  40)
#define GL_BIG_96_5__123  (GL_BIG_96_5__117 +  40)
#define GL_BIG_96_5__128  (GL_BIG_96_5__123 +  60)
#define GL_BIG_96_5__133  (GL_BIG_96_5__128 +  45)

// BIG 97 %
#define GL_BIG_97__72   75
#define GL_BIG_97__75   (GL_BIG_97__72  +  60)
#define GL_BIG_97__80   (GL_BIG_97__75  + 100)
#define GL_BIG_97__84   (GL_BIG_97__80  + 125)
#define GL_BIG_97__88   (GL_BIG_97__84  +  90)
#define GL_BIG_97__92   (GL_BIG_97__88  +  45)
#define GL_BIG_97__96   (GL_BIG_97__92  +  50)
#define GL_BIG_97__100  (GL_BIG_97__96  +  75)
#define GL_BIG_97__104  (GL_BIG_97__100 +  60)
#define GL_BIG_97__108  (GL_BIG_97__104 +  75)
#define GL_BIG_97__112  (GL_BIG_97__108 +  95)
#define GL_BIG_97__117  (GL_BIG_97__112 +  15)
#define GL_BIG_97__123  (GL_BIG_97__117 +  15)
#define GL_BIG_97__128  (GL_BIG_97__123 +  60)
#define GL_BIG_97__133  (GL_BIG_97__128 +  60)

// BIG 97.5 %
#define GL_BIG_97_5__72   75
#define GL_BIG_97_5__75   (GL_BIG_97_5__72  +  35)
#define GL_BIG_97_5__80   (GL_BIG_97_5__75  + 100)
#define GL_BIG_97_5__84   (GL_BIG_97_5__80  + 110)
#define GL_BIG_97_5__88   (GL_BIG_97_5__84  + 150)
#define GL_BIG_97_5__92   (GL_BIG_97_5__88  +  40)
#define GL_BIG_97_5__96   (GL_BIG_97_5__92  +  40)
#define GL_BIG_97_5__100  (GL_BIG_97_5__96  +  40)
#define GL_BIG_97_5__104  (GL_BIG_97_5__100 +  75)
#define GL_BIG_97_5__108  (GL_BIG_97_5__104 +  75)
#define GL_BIG_97_5__112  (GL_BIG_97_5__108 +  75)
#define GL_BIG_97_5__117  (GL_BIG_97_5__112 +  15)
#define GL_BIG_97_5__123  (GL_BIG_97_5__117 +  75)
#define GL_BIG_97_5__128  (GL_BIG_97_5__123 +  80)
#define GL_BIG_97_5__133  (GL_BIG_97_5__128 +  15)

// BIG 98 %
#define GL_BIG_98__72   55
#define GL_BIG_98__75   (GL_BIG_98__72  +  85)
#define GL_BIG_98__80   (GL_BIG_98__75  + 100)
#define GL_BIG_98__84   (GL_BIG_98__80  + 100)
#define GL_BIG_98__88   (GL_BIG_98__84  +  90)
#define GL_BIG_98__92   (GL_BIG_98__88  +  40)
#define GL_BIG_98__96   (GL_BIG_98__92  +  75)
#define GL_BIG_98__100  (GL_BIG_98__96  +  75)
#define GL_BIG_98__104  (GL_BIG_98__100 + 100)
#define GL_BIG_98__108  (GL_BIG_98__104 +  10)
#define GL_BIG_98__112  (GL_BIG_98__108 +  10)
#define GL_BIG_98__117  (GL_BIG_98__112 + 120)
#define GL_BIG_98__123  (GL_BIG_98__117 +  20)
#define GL_BIG_98__128  (GL_BIG_98__123 +  20)
#define GL_BIG_98__133  (GL_BIG_98__128 + 100)

// BIG 98.5 %
#define GL_BIG_98_5__72   125
#define GL_BIG_98_5__75   (GL_BIG_98_5__72  +  40)
#define GL_BIG_98_5__80   (GL_BIG_98_5__75  +  75)
#define GL_BIG_98_5__84   (GL_BIG_98_5__80  +  50)
#define GL_BIG_98_5__88   (GL_BIG_98_5__84  + 125)
#define GL_BIG_98_5__92   (GL_BIG_98_5__88  +  50)
#define GL_BIG_98_5__96   (GL_BIG_98_5__92  +  40)
#define GL_BIG_98_5__100  (GL_BIG_98_5__96  +  40)
#define GL_BIG_98_5__104  (GL_BIG_98_5__100 +  85)
#define GL_BIG_98_5__108  (GL_BIG_98_5__104 +  75)
#define GL_BIG_98_5__112  (GL_BIG_98_5__108 +  75)
#define GL_BIG_98_5__117  (GL_BIG_98_5__112 +  90)
#define GL_BIG_98_5__123  (GL_BIG_98_5__117 +  20)
#define GL_BIG_98_5__128  (GL_BIG_98_5__123 +  20)
#define GL_BIG_98_5__133  (GL_BIG_98_5__128 +  90)

// BIG 99 %
#define GL_BIG_99__72   45
#define GL_BIG_99__75   (GL_BIG_99__72  +  90)
#define GL_BIG_99__80   (GL_BIG_99__75  +  75)
#define GL_BIG_99__84   (GL_BIG_99__80  +  80)
#define GL_BIG_99__88   (GL_BIG_99__84  +  90)
#define GL_BIG_99__92   (GL_BIG_99__88  +  50)
#define GL_BIG_99__96   (GL_BIG_99__92  +  75)
#define GL_BIG_99__100  (GL_BIG_99__96  +  50)
#define GL_BIG_99__104  (GL_BIG_99__100 + 100)
#define GL_BIG_99__108  (GL_BIG_99__104 +  25)
#define GL_BIG_99__112  (GL_BIG_99__108 +  20)
#define GL_BIG_99__117  (GL_BIG_99__112 + 150)
#define GL_BIG_99__123  (GL_BIG_99__117 + 125)
#define GL_BIG_99__128  (GL_BIG_99__123 +   5)
#define GL_BIG_99__133  (GL_BIG_99__128 +  20)

// BIG 99.5 %
#define GL_BIG_99_5__72   75
#define GL_BIG_99_5__75   (GL_BIG_99_5__72  +  90)
#define GL_BIG_99_5__80   (GL_BIG_99_5__75  +  80)
#define GL_BIG_99_5__84   (GL_BIG_99_5__80  +  50)
#define GL_BIG_99_5__88   (GL_BIG_99_5__84  + 100)
#define GL_BIG_99_5__92   (GL_BIG_99_5__88  +  50)
#define GL_BIG_99_5__96   (GL_BIG_99_5__92  +  40)
#define GL_BIG_99_5__100  (GL_BIG_99_5__96  +  40)
#define GL_BIG_99_5__104  (GL_BIG_99_5__100 +  85)
#define GL_BIG_99_5__108  (GL_BIG_99_5__104 +  75)
#define GL_BIG_99_5__112  (GL_BIG_99_5__108 + 125)
#define GL_BIG_99_5__117  (GL_BIG_99_5__112 +  25)
#define GL_BIG_99_5__123  (GL_BIG_99_5__117 +  20)
#define GL_BIG_99_5__128  (GL_BIG_99_5__123 +  20)
#define GL_BIG_99_5__133  (GL_BIG_99_5__128 + 125)

// BIG 100 %
#define GL_BIG_100__72   105
#define GL_BIG_100__75   (GL_BIG_100__72  +  95)
#define GL_BIG_100__80   (GL_BIG_100__75  +  20)
#define GL_BIG_100__84   (GL_BIG_100__80  +  20)
#define GL_BIG_100__88   (GL_BIG_100__84  +  90)
#define GL_BIG_100__92   (GL_BIG_100__88  +  50)
#define GL_BIG_100__96   (GL_BIG_100__92  +  75)
#define GL_BIG_100__100  (GL_BIG_100__96  +  50)
#define GL_BIG_100__104  (GL_BIG_100__100 + 100)
#define GL_BIG_100__108  (GL_BIG_100__104 +  15)
#define GL_BIG_100__112  (GL_BIG_100__108 +  75)
#define GL_BIG_100__117  (GL_BIG_100__112 + 150)
#define GL_BIG_100__123  (GL_BIG_100__117 + 125)
#define GL_BIG_100__128  (GL_BIG_100__123 +   5)
#define GL_BIG_100__133  (GL_BIG_100__128 +  25)

// BIG 101 %
#define GL_BIG_101__72   65
#define GL_BIG_101__75   (GL_BIG_101__72  +  90)
#define GL_BIG_101__80   (GL_BIG_101__75  +  50)
#define GL_BIG_101__84   (GL_BIG_101__80  + 100)
#define GL_BIG_101__88   (GL_BIG_101__84  +  25)
#define GL_BIG_101__92   (GL_BIG_101__88  +  25)
#define GL_BIG_101__96   (GL_BIG_101__92  +  75)
#define GL_BIG_101__100  (GL_BIG_101__96  +  30)
#define GL_BIG_101__104  (GL_BIG_101__100 + 100)
#define GL_BIG_101__108  (GL_BIG_101__104 +  20)
#define GL_BIG_101__112  (GL_BIG_101__108 + 125)
#define GL_BIG_101__117  (GL_BIG_101__112 + 125)
#define GL_BIG_101__123  (GL_BIG_101__117 + 125)
#define GL_BIG_101__128  (GL_BIG_101__123 +  15)
#define GL_BIG_101__133  (GL_BIG_101__128 +  30)

// BIG 102 %
#define GL_BIG_102__72   40
#define GL_BIG_102__75   (GL_BIG_102__72  + 120)
#define GL_BIG_102__80   (GL_BIG_102__75  +  70)
#define GL_BIG_102__84   (GL_BIG_102__80  +  65)
#define GL_BIG_102__88   (GL_BIG_102__84  +  50)
#define GL_BIG_102__92   (GL_BIG_102__88  +  50)
#define GL_BIG_102__96   (GL_BIG_102__92  +  50)
#define GL_BIG_102__100  (GL_BIG_102__96  +  25)
#define GL_BIG_102__104  (GL_BIG_102__100 +  75)
#define GL_BIG_102__108  (GL_BIG_102__104 +  35)
#define GL_BIG_102__112  (GL_BIG_102__108 +  50)
#define GL_BIG_102__117  (GL_BIG_102__112 + 110)
#define GL_BIG_102__123  (GL_BIG_102__117 + 125)
#define GL_BIG_102__128  (GL_BIG_102__123 + 125)
#define GL_BIG_102__133  (GL_BIG_102__128 +  10)

// BIG 104 %
#define GL_BIG_104__72   55
#define GL_BIG_104__75   (GL_BIG_104__72  +  65)
#define GL_BIG_104__80   (GL_BIG_104__75  +  25)
#define GL_BIG_104__84   (GL_BIG_104__80  +  90)
#define GL_BIG_104__88   (GL_BIG_104__84  +  40)
#define GL_BIG_104__92   (GL_BIG_104__88  +  40)
#define GL_BIG_104__96   (GL_BIG_104__92  +  40)
#define GL_BIG_104__100  (GL_BIG_104__96  +  40)
#define GL_BIG_104__104  (GL_BIG_104__100 +  60)
#define GL_BIG_104__108  (GL_BIG_104__104 + 125)
#define GL_BIG_104__112  (GL_BIG_104__108 + 110)
#define GL_BIG_104__117  (GL_BIG_104__112 + 100)
#define GL_BIG_104__123  (GL_BIG_104__117 +  75)
#define GL_BIG_104__128  (GL_BIG_104__123 +  75)
#define GL_BIG_104__133  (GL_BIG_104__128 +  60)


#endif /* PROBABILITYDEFINE_H_ */
