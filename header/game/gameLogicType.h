/**
 * @file gameLogicType.h
 * @brief Declare game logic structure type.
 *
 */

#ifndef GAMELOGICTYPE_H_
#define GAMELOGICTYPE_H_

extern unsigned int  MaingameProM[3][15][7];
extern unsigned int  MaingameProDownM[5][7];
extern unsigned int  MaingameProUpM[5][7];
extern unsigned int  LinkMaingameProM[3][5][15];
extern unsigned int  LineBingoTypeM[9];
extern unsigned int  LineAwardTypeOddsMapping[13];
extern unsigned long FullFrameAwardTypeMapping[11][10];/**< 97 type full frame award mapping table */
extern unsigned int  SpecialGameLightAwardMultiple[9];
extern unsigned int  DoUpM[6][2];
extern unsigned int  DoDownM[6][2];

#include <map>
#include "../preprocessor.h"
#ifndef __arm__
#include "../opengl/gltexture2d.h"
#else
#include "../opengles/gltexture2d.h"
#endif
#include "../mersenne_twister/mt_random.h"
#include "../probability/probabilityDefine.h"
#include "../probability/probabilityEnum.h"
#include "../probability/probabilityType.h"
#include "gameSettingType.h"

extern SPRITESHEETOBJECT slot_move_type1;
extern SPRITESHEETOBJECT slot_move_type2;
extern SPRITESHEETOBJECT slot_move_type3;
extern SPRITESHEETOBJECT slot_move_type4;
extern SPRITESHEETOBJECT slot_move_type5;
extern SPRITESHEETOBJECT slot_item_cherry;
extern SPRITESHEETOBJECT slot_item_orange;
extern SPRITESHEETOBJECT slot_item_mango;
extern SPRITESHEETOBJECT slot_item_bell;
extern SPRITESHEETOBJECT slot_item_watermelon;
extern SPRITESHEETOBJECT slot_item_bar_yellow;
extern SPRITESHEETOBJECT slot_item_bar_red;
extern SPRITESHEETOBJECT slot_item_bar_blue;
//extern SPRITESHEETOBJECT slot_item_seven;
extern SPRITESHEETOBJECT slot_item_wild;

extern SPRITESHEETOBJECT slot_anime_item_cherry;
extern SPRITESHEETOBJECT slot_anime_item_orange;
extern SPRITESHEETOBJECT slot_anime_item_mango;
extern SPRITESHEETOBJECT slot_anime_item_bell;
extern SPRITESHEETOBJECT slot_anime_item_watermelon;
extern SPRITESHEETOBJECT slot_anime_item_bar_yellow;
extern SPRITESHEETOBJECT slot_anime_item_bar_red;
extern SPRITESHEETOBJECT slot_anime_item_bar_blue;
extern SPRITESHEETOBJECT slot_anime_item_wild;


extern SPRITESHEETOBJECT sp_slot_move_type1;
extern SPRITESHEETOBJECT sp_slot_move_type2;
extern SPRITESHEETOBJECT sp_slot_move_type3;
extern SPRITESHEETOBJECT sp_slot_move_type4;
extern SPRITESHEETOBJECT sp_slot_move_type5;
extern SPRITESHEETOBJECT sp_slot_item_cherry;
extern SPRITESHEETOBJECT sp_slot_item_orange;
extern SPRITESHEETOBJECT sp_slot_item_mango;
extern SPRITESHEETOBJECT sp_slot_item_bell;
extern SPRITESHEETOBJECT sp_slot_item_watermelon;
extern SPRITESHEETOBJECT sp_slot_item_bar_yellow;
extern SPRITESHEETOBJECT sp_slot_item_bar_red;
extern SPRITESHEETOBJECT sp_slot_item_bar_blue;
extern SPRITESHEETOBJECT sp_slot_item_seven;
extern SPRITESHEETOBJECT sp_slot_item_wild;
extern SPRITESHEETOBJECT sp_slot_anime_item_cherry;
extern SPRITESHEETOBJECT sp_slot_anime_item_orange;
extern SPRITESHEETOBJECT sp_slot_anime_item_mango;
extern SPRITESHEETOBJECT sp_slot_anime_item_bell;
extern SPRITESHEETOBJECT sp_slot_anime_item_watermelon;
extern SPRITESHEETOBJECT sp_slot_anime_item_bar_yellow;
extern SPRITESHEETOBJECT sp_slot_anime_item_bar_red;
extern SPRITESHEETOBJECT sp_slot_anime_item_bar_blue;
extern SPRITESHEETOBJECT sp_slot_anime_item_wild;


#ifdef DEBUG_OUTPUT_AWARD_DETAIL
//std::map<string,unsigned long> lineAwardRecord;
static std::map<string,unsigned long> fullAwardRecord;
#endif

/**
 * @brief Game's parameter about coins(credits,wager,win,save,paid etc...).
 */
typedef struct GameCredits{
   unsigned long credits;/**< Game credits */
   unsigned long bet;/**< Main game bet */
   unsigned long win;/**< Main game win */
   unsigned long save;/**< Double game save */
   unsigned long paid;/**< Main game paid */
   unsigned long double_win;/**< Double game win */
   unsigned long slotwin;/**< Main game slot win */
   unsigned long collectable;/**< Double game collectable */
   unsigned long trylucky;/**< Double game try lucky */
   unsigned long trylucky_times;/**< Double game's try lucky times */
   unsigned long jp1;/**< Jackpot 1 */
   unsigned long jp2;/**< Jackpot 2 */
   unsigned long jp3;/**< Jackpot 3 */
   unsigned long temp_jp1;/**< Temporary Jackpot 1 */
   unsigned long temp_jp2;/**< Temporary Jackpot 2 */
   unsigned long temp_jp3;/**< Temporary Jackpot 3 */
   unsigned long designate_jp;/**< Designated JP from master */

   unsigned long previous_credits;/**< Game previous credits */
   unsigned long previous_bet;/**< Main game previous bet */
   unsigned long previous_win;/**< Main game previous win */
   unsigned long previous_save;/**< Main game previous save */
   unsigned long previous_paid;/**< Main game previous paid */
   unsigned long previous_double_win;/**< Double game previous win */
   unsigned long previous_slotwin;/**< Double game previous slot win */
   unsigned long previous_collectable;/**< Double game previous collectable */
   unsigned long previous_trylucky;/**< Double game previous try lucky */
   unsigned long previous_trylucky_times;/**< Double game previous try lucky times */
   unsigned long previous_jp1;/**< previous Jackpot 1 */
   unsigned long previous_jp2;/**< previous Jackpot 2 */
   unsigned long previous_jp3;/**< previous Jackpot 3 */

   /**
    * @brief Constructor.
    */
   GameCredits(void){
	   this->Reset();
   }

   /**
    * @brief Reset All Member Parameters.
    */
   void Reset(){
	  this->credits = 0;
	  this->previous_credits     = this->credits;
	  this->bet   = 0;
	  this->previous_bet       = this->bet;
	  this->win     = 0;
	  this->previous_win         = this->win;
	  this->save    = 0;
	  this->previous_save        = this->save;
	  this->paid    = 0;
	  this->previous_paid        = this->paid;
	  this->double_win= 0;
	  this->previous_double_win    = this->double_win;
	  this->slotwin = 0;
	  this->previous_slotwin     = this->slotwin;
	  this->collectable = 0;
	  this->previous_collectable = this->collectable;
	  this->trylucky = 0;
	  this->previous_trylucky    = this->trylucky;
	  this->trylucky_times = 0;
	  this->previous_trylucky_times = this->trylucky_times;
	  this->jp1 = 0;
	  this->previous_jp1 = this->jp1;
	  this->jp2 = 0;
	  this->previous_jp2 = this->jp2;
	  this->jp3 = 0;
	  this->previous_jp3 = this->jp3;
	  this->designate_jp = 0;
   }
}GAMECREDITS;

typedef int (*FrameProTypeFunc)(MTRANDOM*,MAINGAMEPROBABILITYCONTROL*);/**< Type Define For Each Frame Probability Type(fixed or Mutable) */

extern int _FrameProTypeFixed_Slot1(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_Slot2(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_Slot3(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_Slot4(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_Slot5(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_Slot6(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_Slot8(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
extern int _FrameProTypeFixed_Slot9(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
extern int _FrameProTypeMutable_Slot1(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
extern int _FrameProTypeMutable_Slot5(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
extern int _FrameProTypeMutable_Slot7(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
extern int _FrameProTypeTest(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl);
#endif

/**
 * @brief Indicate single frame.
 */
typedef struct SingleFrame{
  SpriteSheetObject* slotMoveSheetObject;/**< Slot Move Sprite Sheet Object */
  SpriteSheetObject* itemSheetObject[10];/**< Slot Item Sprite Sheet Object */
  SpriteSheetObject* itemAnimeSheetObject[10];/**< Slot Item Animation Sprite Object */

  FrameProTypeFunc frameProTypeFunc;/**< Frame's probability function */
  Rectangle     rect;/**< Clip rectangle */
  unsigned int  type;/**< Scroll type(Item older type) */
  unsigned int  pos_X;/**< X position */
  unsigned int  pos_Y;/**< Y position */
  unsigned int  stopItem;/**< Stop item */
  unsigned int  stopItemFromSerialPort;/**< Stop item via serial port */
  //unsigned int  StopLine[13];/**< Stop line           { 97,217, 329, 445, 561, 677, 793, 909, 1025, 1141, 1257, 1373, 1489 } */
  unsigned int  PreChangeLine[7];/**< Pre-Change line {     75,      155,      235,      315,        395,        475,  555 } */
  unsigned int  NextStopLine;/**< Next stop line */
  unsigned int  StopFlag;/**< Stop flag */
  unsigned int  Loop;/**< Loop times */
  unsigned int  SideBingoFlag;/**< Side bingo flag */
  unsigned int  LineBingoFlag;/**< Line bingo flag */
  unsigned int  AnimeFlag;/**< Animation Flag */
  unsigned int  AnimeIndex;/**< Animation index */
  unsigned int  AnimeLoop;/**< Animation loop times */
  unsigned int  ConvertItemToStopLine[13];/**< Convert item to stop line */
  unsigned int  award_frame_pos_X;/**< Award Frame Position X */
  unsigned int  award_frame_pos_Y;/**< Award Frame Position Y */
  //unsigned int  board_pos_X;/**< X position of board */
  //unsigned int  board_pos_Y;/**< Y position of board */
  //unsigned int  board_pic_Num;/**< Picture number of board */
  //unsigned int  board_bg_pos_X;/**< X position of board BG */
  //unsigned int  board_bg_pos_Y;/**< Y position of board BG */
  //unsigned int  board_bg_pic_Num;/**< Picture number of board BG */
  unsigned int  scrollStatus;/**< Scroll status */
            int  tempScrollValue;/**< Temporal scroll value */

  SingleFrame(void){
#if 0
	  this->itemSheetObject[ITEM_UNKNOW]     = NULL;
	  this->itemSheetObject[ITEM_CHERRY]     = &slot_item_cherry;
	  this->itemSheetObject[ITEM_ORANGE]     = &slot_item_orange;
	  this->itemSheetObject[ITEM_MANGO]      = &slot_item_mango;
	  this->itemSheetObject[ITEM_BELL]       = &slot_item_bell;
	  this->itemSheetObject[ITEM_WATERMELON] = &slot_item_watermelon;
	  this->itemSheetObject[ITEM_BAR_YELLOW] = &slot_item_bar_yellow;
	  this->itemSheetObject[ITEM_BAR_RED]    = &slot_item_bar_red;
	  this->itemSheetObject[ITEM_BAR_BLUE]   = &slot_item_bar_blue;
	  //this->itemSheetObject[ITEM_SEVEN]      = &slot_item_seven;
	  this->itemSheetObject[ITEM_WILD]       = &slot_item_wild;

	  this->itemAnimeSheetObject[ITEM_UNKNOW]     = NULL;
	  this->itemAnimeSheetObject[ITEM_CHERRY]     = &slot_anime_item_cherry;
	  this->itemAnimeSheetObject[ITEM_ORANGE]     = &slot_anime_item_orange;
	  this->itemAnimeSheetObject[ITEM_MANGO]      = &slot_anime_item_mango;
	  this->itemAnimeSheetObject[ITEM_BELL]       = &slot_anime_item_bell;
	  this->itemAnimeSheetObject[ITEM_WATERMELON] = &slot_anime_item_watermelon;
	  this->itemAnimeSheetObject[ITEM_BAR_YELLOW] = &slot_anime_item_bar_yellow;
	  this->itemAnimeSheetObject[ITEM_BAR_RED]    = &slot_anime_item_bar_red;
	  this->itemAnimeSheetObject[ITEM_BAR_BLUE]   = &slot_anime_item_bar_blue;
	  this->itemAnimeSheetObject[ITEM_WILD]       = &slot_anime_item_wild;
#endif
  }

  /**
   * @brief Set Scroll type.
   * @param type Type of scroll
   */
  void setScrollType(unsigned int type){
        this->type = type;

        switch(this->type){
        //case Type_Slot1_Fixed:
          //this->frameProTypeFunc = _FrameProTypeFixed_1;
      	    //break;

        case Type_Slot2_Fixed:
          this->frameProTypeFunc = _FrameProTypeFixed_Slot2;
      	    break;

        case Type_Slot3_Fixed:
          this->frameProTypeFunc = _FrameProTypeFixed_Slot3;
      	    break;

        case Type_Slot4_Fixed:
          this->frameProTypeFunc = _FrameProTypeFixed_Slot4;
      	    break;

        //case Type_Slot5_Fixed:
          //this->frameProTypeFunc = _FrameProTypeFixed_5;
      	    //break;

        case Type_Slot6_Fixed:
          this->frameProTypeFunc = _FrameProTypeFixed_Slot6;
      	    break;

        //case Type_Slot7_Fixed:
          //this->frameProTypeFunc = _FrameProTypeFixed_7;
      	    //break;

        case Type_Slot8_Fixed:
          this->frameProTypeFunc = _FrameProTypeFixed_Slot9;
      	    break;

        case Type_Slot9_Fixed:
          this->frameProTypeFunc = _FrameProTypeFixed_Slot9;
      	    break;

        case Type_Slot1_Mutable:
          this->frameProTypeFunc = _FrameProTypeMutable_Slot1;
            break;

        case Type_Slot5_Mutable:
          this->frameProTypeFunc = _FrameProTypeMutable_Slot5;
            break;

        case Type_Slot7_Mutable:
          this->frameProTypeFunc = _FrameProTypeMutable_Slot7;
            break;

#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
        case Type_Test:
		  this->frameProTypeFunc = _FrameProTypeTest;
        	break;
#endif

        };
  }
  /**
   * @brief Get Stop Frame.
   * @param mt Mersenne Twister Algorithm
   * @param pctrl Probability Controller
   * @retval Stop frame
   */
  int getStopFrame(MTRANDOM* mt,MAINGAMEPROBABILITYCONTROL* pctrl){

      this->stopItem = this->frameProTypeFunc(mt,pctrl);

	  //Get Stop Item From Serial Port
      //this->stopItem = this->stopItemFromSerialPort;

      return this->stopItem;
  }
  /**
   * @brief Get stop line by item.
   * @param item Stop item
   * @retval Stop line
   */
  int  getStopLineFromItem(unsigned int item){
	   this->NextStopLine = 60;
	   return 60;
  }

}SINGLEFRAME;

/**
 * @brief Indicate single line.
 */
typedef struct Line{
  unsigned char bingoFrame[3];/**< Three frames of line */
  unsigned long bet;/**< line's bet */
  unsigned long win;/**< line's win */
  bool           bingoFlag;/**< line's bingo flag */
  unsigned char bingotype;/**< line's bingo type */
  unsigned int* lineBingoTypeM;/**< Line odds mapping table */
  unsigned int  pos_X;/**< line's X position */
  unsigned int  pos_Y;/**< line's Y position */

  /**
   * @brief Reset line's parameters of rendering.
   * @param x X position
   * @param y Y position
   * @param n n Picture's number
   */
  void resetLineRenderPara(int x,int y){
	  this->pos_X = x;
	  this->pos_Y = y;
  }
  /**
   * @brief Reset all member parameters.
   */
  void reset(){
	  this->bet  =  0;
	  this->bingoFlag = false;
	  this->bingotype = LINE_AWARD_NONE;
	  this->lineBingoTypeM = LineAwardTypeOddsMapping;//LineBingoTypeM;
	  for(unsigned int i=0; i<sizeof(bingoFrame)/sizeof(bingoFrame[0]); i++){
		  this->bingoFrame[i] = 0;
	  }
  }
  /**
   * @brief Set up three frames of line.
   * @param f1 frame 1
   * @param f2 frame 2
   * @param f3 frame 3
   */
  void setBingoFrame(int f1,int f2,int f3){
	  this->bingoFrame[0] = f1;
	  this->bingoFrame[1] = f2;
	  this->bingoFrame[2] = f3;
  }

  unsigned int getWildTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_WILD){
			  times++;
		  }
	  }

	  return times;
  }
  /*
  unsigned int getSevenTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_SEVEN){
			  times++;
		  }
	  }

	  return times;
  }
  */

  unsigned int getBarBlueTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_BAR_BLUE){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getBarRedTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_BAR_RED){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getBarYellowTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_BAR_YELLOW){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getWaterMelonTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_WATERMELON){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getBellTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_BELL){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getMangoTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_MANGO){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getMixBarTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_BAR_YELLOW || sf[this->bingoFrame[i]].stopItem==ITEM_BAR_RED ||
		     sf[this->bingoFrame[i]].stopItem==ITEM_BAR_BLUE){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getOrangeTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_ORANGE){
			  times++;
		  }
	  }

	  return times;
  }

  unsigned int getCherryTimes(SingleFrame* sf){
	  unsigned int times = 0;
	  for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){
		  if(sf[this->bingoFrame[i]].stopItem==ITEM_CHERRY){
			  times++;
		  }
	  }

	  return times;
  }

  /**
   * @brief Is line bingo.
   * @param sf Single frame
   * @retval true:bingo false:none
   */
  bool isLineBingo(SingleFrame* sf){


	  bool result = false;

      if(this->getWildTimes(sf) == 3){// Seven Straight
    	  this->bingotype = LINE_AWARD_WILD;

      }//else if(this->getSevenTimes(sf) + this->getWildTimes(sf) == 3){// Seven Straight
    	  //this->bingotype = LINE_AWARD_SEVEN;

      //}
       else if(this->getBarBlueTimes(sf) + this->getWildTimes(sf) == 3){// Bar(blue) straight
    	  this->bingotype = LINE_AWARD_BAR_BLUE;

      }else if(this->getBarRedTimes(sf) + this->getWildTimes(sf) == 3){// Bar(red) straight
    	  this->bingotype = LINE_AWARD_BAR_RED;

      }else if(this->getBarYellowTimes(sf) + this->getWildTimes(sf) == 3){// Bar(yellow) straight
    	  this->bingotype = LINE_AWARD_BAR_YELLOW;

      }else if(this->getWaterMelonTimes(sf) + this->getWildTimes(sf) == 3){// Watermelon straight
    	  this->bingotype = LINE_AWARD_WATERMELON;

      }else if(this->getBellTimes(sf) + this->getWildTimes(sf) == 3){// Bell straight
    	  this->bingotype = LINE_AWARD_BELL;

      }else if(this->getMangoTimes(sf) + this->getWildTimes(sf) == 3){// Mango straight
    	  this->bingotype = LINE_AWARD_MANGO;

      }else if(this->getMixBarTimes(sf) + this->getWildTimes(sf) == 3){// Mix bar straight
    	  this->bingotype = LINE_AWARD_MIX_BAR;

      }else if(this->getOrangeTimes(sf) + this->getWildTimes(sf) == 3){// Orange straight
    	  this->bingotype = LINE_AWARD_ORANGE;

      }else if(this->getCherryTimes(sf) + this->getWildTimes(sf) == 3){// Three cherry straight
    	  this->bingotype = LINE_AWARD_THREE_CHERRY;

      }else if(this->getCherryTimes(sf) + this->getWildTimes(sf) == 2){// Two cherry straight
    	  if((sf[this->bingoFrame[0]].stopItem == ITEM_CHERRY || sf[this->bingoFrame[0]].stopItem == ITEM_WILD)
    		  && (sf[this->bingoFrame[1]].stopItem == ITEM_CHERRY || sf[this->bingoFrame[1]].stopItem == ITEM_WILD)){
    		  this->bingotype = LINE_AWARD_TWO_CHERRY;
    	  }else if((sf[this->bingoFrame[0]].stopItem == ITEM_CHERRY || sf[this->bingoFrame[0]].stopItem == ITEM_WILD)
    			   && (sf[this->bingoFrame[2]].stopItem == ITEM_CHERRY || sf[this->bingoFrame[2]].stopItem == ITEM_WILD)){
    		  this->bingotype = LINE_AWARD_ONE_CHERRY;
    	  }

      }else if(this->getCherryTimes(sf) + this->getWildTimes(sf) == 1){// One cherry straight
    	  if(sf[this->bingoFrame[0]].stopItem == ITEM_CHERRY || sf[this->bingoFrame[0]].stopItem == ITEM_WILD ){
    		  this->bingotype = LINE_AWARD_ONE_CHERRY;
    	  }
      }


      if(this->bingotype != LINE_AWARD_NONE){
    	  this->bingoFlag = true;
    	  result = true;
      }

	  return result;

  }
  /**
   * @brief Compute line's score.
   * @param sf Single frame
   * @retval Score
   */
  unsigned long computeLineScore(SingleFrame* sf){
	  unsigned long score=0;

      if(this->isLineBingo(sf)==false || this->bet==0){
    	 this->win = 0;
         return score;
      }else{//When Bingo Set LineBingoFlag True
    	 for(unsigned int i=0; i<sizeof(this->bingoFrame)/sizeof(this->bingoFrame[0]); i++){

    		 if(this->bingotype==LINE_AWARD_ONE_CHERRY){
    			 if(i==0){
					 if(sf[this->bingoFrame[i]].stopItem==ITEM_CHERRY || sf[this->bingoFrame[i]].stopItem==ITEM_WILD){
						 sf[this->bingoFrame[i]].LineBingoFlag = true;
					 }
    			 }

    		 }else if( this->bingotype==LINE_AWARD_TWO_CHERRY){
    			 if(i==0 || i==1){
					 if(sf[this->bingoFrame[i]].stopItem==ITEM_CHERRY ||  sf[this->bingoFrame[i]].stopItem==ITEM_WILD){
						 sf[this->bingoFrame[i]].LineBingoFlag = true;
					 }
    			 }

    		 }else{
    			 sf[this->bingoFrame[i]].LineBingoFlag = true;
    		 }
    	 }
      }

      this->win = this->bet * this->lineBingoTypeM[this->bingotype];
	  score = this->win;

	  return score;
  }

  unsigned int getAwardFrameCount(void){
	  unsigned int cnt =  0;

	  switch(this->bingotype){

	  case LINE_AWARD_ONE_CHERRY:
		  cnt = 1;
		  break;
	  case LINE_AWARD_TWO_CHERRY:
		  cnt = 2;
		  break;
	  case LINE_AWARD_THREE_CHERRY:
	  case LINE_AWARD_ORANGE:
	  case LINE_AWARD_MIX_BAR:
	  case LINE_AWARD_MANGO:
	  case LINE_AWARD_BELL:
	  case LINE_AWARD_WATERMELON:
	  case LINE_AWARD_BAR_YELLOW:
	  case LINE_AWARD_BAR_RED:
	  case LINE_AWARD_BAR_BLUE:
	  case LINE_AWARD_WILD:
		  cnt = 3;
		  break;

	  default:
		  break;
	  }

	  return cnt;
  }

}LINE;

/**
 * @brief Indicates single side item.
 */
typedef struct SideItem{
  unsigned long bet;/**< Side item's bet */
  unsigned char item;/**< Item kind */
  unsigned int  pos_X;/**< Side item's X position */
  unsigned int  pos_Y;/**< Side item's Y position */

  /**
   * @brief Reset side item parameters of rendering.
   * @param x Position X
   * @param y Position Y
   * @param n Picture's number
   */
  void resetSideRenderPara(int x,int y){
	 this->pos_X = x;
	 this->pos_Y = y;
  }
  /**
   * @brief Rest bet and item.
   */
  void reset(){
	  this->bet  = 0;
	  this->item = 0;
  }

}SIDEITEM;

/**
 * @brief Main game frame.
 */
typedef struct MainGameContent{

	Line line[8];/**< Line */
#if 0
	SideItem sideItem[8];/**< Side item */
#endif
	SingleFrame singleFrame[9];/**< Single frame */
    unsigned char finalStopItem[9];/**< Final stop item */
    unsigned char renderKeyOutPaid;/**< Render Key out paid */
    unsigned long temp_total_out;/**< Temporal total out */
    unsigned long bet;/**< bet */
    unsigned long m_fullAwardType;/**< Full Award Type */
    unsigned int m_step;/**< Main game step */
    unsigned int m_subStep;/**< Main game sub step */
    unsigned int m_autoRun;/**< Indicate auto play start or not */
    unsigned int m_autoRunSlotStopPattern;/**< Auto Run Slot Stop Pattern */
    unsigned int m_OpenJackpotFlag;/**< JACKPOT Open flag */
    unsigned int m_OpenJackpotKind;/**< JACKPOT kind */
    unsigned int m_GetJackpotType;/**< Get JACKPOT type */
    unsigned int _tempFrameOlder[9];/**< For random frame older */
    unsigned int m_slotAnimeSequence;/**< Slot Animation Sequence */
    unsigned int m_slotAnimePreviousSequence;/**< Slot Animation Previous Sequence */
    unsigned int m_slotAnimeSequenceLoopTimes;/**< Slot Animation Sequence Loop Times */
    bool m_keyOutFlag;/**< Key Out Flag */
    bool m_payOutFlag;/**< Pay Out Flag */
    bool m_reqPayFlag;/**< Request Pay Out Flag */
    unsigned int m_temp_key_out;/**< Temporal Key Out Value */
    unsigned int m_temp_pay_out;/**< Temporal Pay Out Value */


    /**
     * @brief Constructor.
     */
    MainGameContent(void){
    	this->Reset();
    }

    /**
     * @brief Reset all member parameters.
     */
	void Reset(){
		this->m_step = main_step_Inactive;
		this->m_subStep = main_sub_step_Inactive;
		this->m_fullAwardType = FULL_AWARD_UNKNOW;
		this->m_slotAnimeSequence = main_slot_anime_sequence_fullframe;
		this->m_slotAnimePreviousSequence = 0x99;
		this->m_slotAnimeSequenceLoopTimes = 0;
		this->m_keyOutFlag = false;
		this->m_payOutFlag = false;
		this->m_reqPayFlag = false;
		this->m_temp_key_out = 0;
		this->m_temp_pay_out = 0;
		this->m_autoRun = auto_play_stop;
		this->m_autoRunSlotStopPattern = auto_play_slot_stop_normal;

		//Line ReSet
		for(unsigned int i=0; i<sizeof(line)/sizeof(line[0]); i++){
			line[i].reset();
		}
		line[0].setBingoFrame(3,4,5);
		line[1].setBingoFrame(0,1,2);
		line[2].setBingoFrame(6,7,8);
		line[3].setBingoFrame(0,4,8);
		line[4].setBingoFrame(6,4,2);
		line[5].setBingoFrame(0,3,6);
		line[6].setBingoFrame(1,4,7);
		line[7].setBingoFrame(2,5,8);
		line[0].resetLineRenderPara(LINE_1_WAGER_INFO_X,LINE_1_WAGER_INFO_Y);
		line[1].resetLineRenderPara(LINE_2_WAGER_INFO_X,LINE_2_WAGER_INFO_Y);
		line[2].resetLineRenderPara(LINE_3_WAGER_INFO_X,LINE_3_WAGER_INFO_Y);
		line[3].resetLineRenderPara(LINE_4_WAGER_INFO_X,LINE_4_WAGER_INFO_Y);
		line[4].resetLineRenderPara(LINE_5_WAGER_INFO_X,LINE_5_WAGER_INFO_Y);
		line[5].resetLineRenderPara(LINE_6_WAGER_INFO_X,LINE_6_WAGER_INFO_Y);
		line[6].resetLineRenderPara(LINE_7_WAGER_INFO_X,LINE_7_WAGER_INFO_Y);
		line[7].resetLineRenderPara(LINE_8_WAGER_INFO_X,LINE_8_WAGER_INFO_Y);
#if 0
		//SideItem ReSet
		for(unsigned int i=0; i<sizeof(sideItem)/sizeof(sideItem[0]); i++){
			sideItem[i].reset();
		}
		sideItem[0].item = side_Blank;
		sideItem[1].item = side_Mix_Bar;
		sideItem[2].item = side_One_Bar;
		sideItem[3].item = side_Two_Bar;
		sideItem[4].item = side_Three_Bar;
		sideItem[5].item = side_Mix_7;
		sideItem[6].item = side_Red_7;
		sideItem[7].item = side_Blue_7;
		sideItem[0].resetSideRenderPara(ITEM_1_WAGER_INFO_X,ITEM_1_WAGER_INFO_Y);
		sideItem[1].resetSideRenderPara(ITEM_2_WAGER_INFO_X,ITEM_2_WAGER_INFO_Y);
		sideItem[2].resetSideRenderPara(ITEM_3_WAGER_INFO_X,ITEM_3_WAGER_INFO_Y);
		sideItem[3].resetSideRenderPara(ITEM_4_WAGER_INFO_X,ITEM_4_WAGER_INFO_Y);
		sideItem[4].resetSideRenderPara(ITEM_5_WAGER_INFO_X,ITEM_5_WAGER_INFO_Y);
		sideItem[5].resetSideRenderPara(ITEM_6_WAGER_INFO_X,ITEM_6_WAGER_INFO_Y);
		sideItem[6].resetSideRenderPara(ITEM_7_WAGER_INFO_X,ITEM_7_WAGER_INFO_Y);
		sideItem[7].resetSideRenderPara(ITEM_8_WAGER_INFO_X,ITEM_8_WAGER_INFO_Y);
#endif
        //Main Game Slot Frame Reset
		for(unsigned int idx=0; idx<sizeof(singleFrame)/sizeof(singleFrame[0]);idx++){
			this->singleFrame[idx].itemSheetObject[ITEM_UNKNOW]     = NULL;
			this->singleFrame[idx].itemSheetObject[ITEM_CHERRY]     = &slot_item_cherry;
			this->singleFrame[idx].itemSheetObject[ITEM_ORANGE]     = &slot_item_orange;
			this->singleFrame[idx].itemSheetObject[ITEM_MANGO]      = &slot_item_mango;
			this->singleFrame[idx].itemSheetObject[ITEM_BELL]       = &slot_item_bell;
			this->singleFrame[idx].itemSheetObject[ITEM_WATERMELON] = &slot_item_watermelon;
			this->singleFrame[idx].itemSheetObject[ITEM_BAR_YELLOW] = &slot_item_bar_yellow;
			this->singleFrame[idx].itemSheetObject[ITEM_BAR_RED]    = &slot_item_bar_red;
			this->singleFrame[idx].itemSheetObject[ITEM_BAR_BLUE]   = &slot_item_bar_blue;
			//this->singleFrame[idx].itemSheetObject[ITEM_SEVEN]      = &slot_item_seven;
			this->singleFrame[idx].itemSheetObject[ITEM_WILD]       = &slot_item_wild;

			this->singleFrame[idx].itemAnimeSheetObject[ITEM_UNKNOW]     = NULL;
			this->singleFrame[idx].itemAnimeSheetObject[ITEM_CHERRY]     = &slot_anime_item_cherry;
			this->singleFrame[idx].itemAnimeSheetObject[ITEM_ORANGE]     = &slot_anime_item_orange;
			this->singleFrame[idx].itemAnimeSheetObject[ITEM_MANGO]      = &slot_anime_item_mango;
			this->singleFrame[idx].itemAnimeSheetObject[ITEM_BELL]       = &slot_anime_item_bell;
			this->singleFrame[idx].itemAnimeSheetObject[ITEM_WATERMELON] = &slot_anime_item_watermelon;
			this->singleFrame[idx].itemAnimeSheetObject[ITEM_BAR_YELLOW] = &slot_anime_item_bar_yellow;
			this->singleFrame[idx].itemAnimeSheetObject[ITEM_BAR_RED]    = &slot_anime_item_bar_red;
			this->singleFrame[idx].itemAnimeSheetObject[ITEM_BAR_BLUE]   = &slot_anime_item_bar_blue;
			this->singleFrame[idx].itemAnimeSheetObject[ITEM_WILD]       = &slot_anime_item_wild;
		}
        //Frame[0]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		singleFrame[0].setScrollType(Type_Test);
#else
		singleFrame[0].setScrollType(Type_Slot1_Mutable);
#endif
		singleFrame[0].slotMoveSheetObject =  &slot_move_type1;
		singleFrame[0].pos_X        =           SLOT_1_X;
		singleFrame[0].pos_Y        =           SLOT_1_Y;
		singleFrame[0].stopItem     =        ITEM_CHERRY;
		singleFrame[0].NextStopLine =                  0;
		singleFrame[0].StopFlag     =             false;
		singleFrame[0].Loop         =                  0;
		singleFrame[0].SideBingoFlag=             false;
		singleFrame[0].LineBingoFlag=             false;
		singleFrame[0].AnimeFlag    =             false;
		singleFrame[0].rect.x = 0;
		singleFrame[0].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[0].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[0].rect.h = SINGLE_FRAME_HEIGHT;
		singleFrame[0].award_frame_pos_X = SLOT_AWARD_FRAME_1_POS_X;
		singleFrame[0].award_frame_pos_Y = SLOT_AWARD_FRAME_1_POS_Y;
		//Frame[1]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		singleFrame[1].setScrollType(Type_Test);
#else
		singleFrame[1].setScrollType(Type_Slot2_Fixed);
#endif
		singleFrame[1].slotMoveSheetObject =  &slot_move_type1;
		singleFrame[1].pos_X        =           SLOT_2_X;
		singleFrame[1].pos_Y        =   		SLOT_2_Y;
		singleFrame[1].stopItem     =        ITEM_ORANGE;
		singleFrame[1].NextStopLine =                  0;
		singleFrame[1].StopFlag     =             false;
		singleFrame[1].Loop         =                  0;
		singleFrame[1].SideBingoFlag=             false;
		singleFrame[1].LineBingoFlag=             false;
		singleFrame[1].AnimeFlag    =             false;
		singleFrame[1].rect.x = 0;
		singleFrame[1].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[1].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[1].rect.h = SINGLE_FRAME_HEIGHT;
		singleFrame[1].award_frame_pos_X = SLOT_AWARD_FRAME_2_POS_X;
		singleFrame[1].award_frame_pos_Y = SLOT_AWARD_FRAME_2_POS_Y;
		//Frame[2]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		singleFrame[2].setScrollType(Type_Test);
#else
		singleFrame[2].setScrollType(Type_Slot3_Fixed);
#endif
		singleFrame[2].slotMoveSheetObject =  &slot_move_type1;
		singleFrame[2].pos_X        =           SLOT_3_X;
		singleFrame[2].pos_Y        =           SLOT_3_Y;
		singleFrame[2].stopItem     =         ITEM_MANGO;
		singleFrame[2].NextStopLine =                  0;
		singleFrame[2].StopFlag     =             false;
		singleFrame[2].Loop         =                  0;
		singleFrame[2].SideBingoFlag=             false;
		singleFrame[2].LineBingoFlag=             false;
		singleFrame[2].AnimeFlag    =             false;
		singleFrame[2].rect.x = 0;
		singleFrame[2].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[2].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[2].rect.h = SINGLE_FRAME_HEIGHT;
		singleFrame[2].award_frame_pos_X = SLOT_AWARD_FRAME_3_POS_X;
		singleFrame[2].award_frame_pos_Y = SLOT_AWARD_FRAME_3_POS_Y;
		//Frame[3]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		singleFrame[3].setScrollType(Type_Test);
#else
		singleFrame[3].setScrollType(Type_Slot4_Fixed);
#endif
		singleFrame[3].slotMoveSheetObject =  &slot_move_type1;
		singleFrame[3].pos_X        =   		SLOT_4_X;
		singleFrame[3].pos_Y        =   		SLOT_4_Y;
		singleFrame[3].stopItem     =          ITEM_BELL;
		singleFrame[3].NextStopLine =                  0;
		singleFrame[3].StopFlag     =             false;
		singleFrame[3].Loop         =                  0;
		singleFrame[3].SideBingoFlag=             false;
		singleFrame[3].LineBingoFlag=             false;
		singleFrame[3].AnimeFlag    =             false;
		singleFrame[3].rect.x = 0;
		singleFrame[3].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[3].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[3].rect.h = SINGLE_FRAME_HEIGHT;
		singleFrame[3].award_frame_pos_X = SLOT_AWARD_FRAME_4_POS_X;
		singleFrame[3].award_frame_pos_Y = SLOT_AWARD_FRAME_4_POS_Y;
		//Frame[4]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		singleFrame[4].setScrollType(Type_Test);
#else
		singleFrame[4].setScrollType(Type_Slot5_Mutable);//Type_Mutable);
#endif
		singleFrame[4].slotMoveSheetObject =  &slot_move_type1;
		singleFrame[4].pos_X        =   		SLOT_5_X;
		singleFrame[4].pos_Y        =   		SLOT_5_Y;
		singleFrame[4].stopItem     =    ITEM_WATERMELON;
		singleFrame[4].NextStopLine =                  0;
		singleFrame[4].StopFlag     =             false;
		singleFrame[4].Loop         =                  0;
		singleFrame[4].SideBingoFlag=             false;
		singleFrame[4].LineBingoFlag=             false;
		singleFrame[4].AnimeFlag    =             false;
		singleFrame[4].rect.x = 0;
		singleFrame[4].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[4].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[4].rect.h = SINGLE_FRAME_HEIGHT;
		singleFrame[4].award_frame_pos_X = SLOT_AWARD_FRAME_5_POS_X;
		singleFrame[4].award_frame_pos_Y = SLOT_AWARD_FRAME_5_POS_Y;
		//Frame[5]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		singleFrame[5].setScrollType(Type_Test);
#else
		singleFrame[5].setScrollType(Type_Slot6_Fixed);
#endif
		singleFrame[5].slotMoveSheetObject =  &slot_move_type1;
		singleFrame[5].pos_X        =           SLOT_6_X;
		singleFrame[5].pos_Y        =           SLOT_6_Y;
		singleFrame[5].stopItem     =    ITEM_BAR_YELLOW;
		singleFrame[5].NextStopLine =                  0;
		singleFrame[5].StopFlag     =             false;
		singleFrame[5].Loop         =                  0;
		singleFrame[5].SideBingoFlag=             false;
		singleFrame[5].LineBingoFlag=             false;
		singleFrame[5].AnimeFlag    =             false;
		singleFrame[5].rect.x = 0;
		singleFrame[5].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[5].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[5].rect.h = SINGLE_FRAME_HEIGHT;
		singleFrame[5].award_frame_pos_X = SLOT_AWARD_FRAME_6_POS_X;
		singleFrame[5].award_frame_pos_Y = SLOT_AWARD_FRAME_6_POS_Y;
		//Frame[6]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		singleFrame[6].setScrollType(Type_Test);
#else
		singleFrame[6].setScrollType(Type_Slot7_Mutable);
#endif
		singleFrame[6].slotMoveSheetObject =  &slot_move_type1;
		singleFrame[6].pos_X        =           SLOT_7_X;
		singleFrame[6].pos_Y        =   		SLOT_7_Y;
		singleFrame[6].stopItem     =       ITEM_BAR_RED;
		singleFrame[6].NextStopLine =                  0;
		singleFrame[6].StopFlag     =             false;
		singleFrame[6].Loop         =                  0;
		singleFrame[6].SideBingoFlag=             false;
		singleFrame[6].LineBingoFlag=             false;
		singleFrame[6].AnimeFlag    =             false;
		singleFrame[6].rect.x = 0;
		singleFrame[6].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[6].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[6].rect.h = SINGLE_FRAME_HEIGHT;
		singleFrame[6].award_frame_pos_X = SLOT_AWARD_FRAME_7_POS_X;
		singleFrame[6].award_frame_pos_Y = SLOT_AWARD_FRAME_7_POS_Y;
		//Frame[7]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		singleFrame[7].setScrollType(Type_Test);
#else
		singleFrame[7].setScrollType(Type_Slot8_Fixed);
#endif
		singleFrame[7].slotMoveSheetObject =  &slot_move_type1;
		singleFrame[7].pos_X        =   		SLOT_8_X;
		singleFrame[7].pos_Y        =   		SLOT_8_Y;
		singleFrame[7].stopItem     =      ITEM_BAR_BLUE;
		singleFrame[7].NextStopLine =                  0;
		singleFrame[7].StopFlag     =             false;
		singleFrame[7].Loop         =                  0;
		singleFrame[7].SideBingoFlag=             false;
		singleFrame[7].LineBingoFlag=             false;
		singleFrame[7].AnimeFlag    =             false;
		singleFrame[7].rect.x = 0;
		singleFrame[7].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[7].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[7].rect.h = SINGLE_FRAME_HEIGHT;
		singleFrame[7].award_frame_pos_X = SLOT_AWARD_FRAME_8_POS_X;
		singleFrame[7].award_frame_pos_Y = SLOT_AWARD_FRAME_8_POS_Y;
		//Frame[8]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		singleFrame[8].setScrollType(Type_Test);
#else
		singleFrame[8].setScrollType(Type_Slot9_Fixed);
#endif
		singleFrame[8].slotMoveSheetObject =  &slot_move_type1;
		singleFrame[8].pos_X        =   		SLOT_9_X;
		singleFrame[8].pos_Y        =   		SLOT_9_Y;
		singleFrame[8].stopItem     =        ITEM_CHERRY;
		singleFrame[8].NextStopLine =                  0;
		singleFrame[8].StopFlag     =             false;
		singleFrame[8].Loop         =                  0;
		singleFrame[8].SideBingoFlag=             false;
		singleFrame[8].LineBingoFlag=             false;
		singleFrame[8].AnimeFlag    =             false;
		singleFrame[8].rect.x = 0;
		singleFrame[8].rect.y = DEF_OFFSET_RECT_Y;
		singleFrame[8].rect.w = SINGLE_FRAME_WIDTH;
		singleFrame[8].rect.h = SINGLE_FRAME_HEIGHT;
		singleFrame[8].award_frame_pos_X = SLOT_AWARD_FRAME_9_POS_X;
		singleFrame[8].award_frame_pos_Y = SLOT_AWARD_FRAME_9_POS_Y;
		//
		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
			this->singleFrame[i].AnimeIndex=1;
			this->singleFrame[i].AnimeLoop =0;
			this->singleFrame[i].scrollStatus = scroll_Stop;
		}

		//
		for(unsigned char i=0; i<sizeof(finalStopItem)/sizeof(finalStopItem[0]); i++){
			 finalStopItem[i] = 0;
		}
		//
		renderKeyOutPaid = false;
		temp_total_out = 0;
	}
    /**
     * @brief Compute side item's score.
     * @retval Side item's winning score
     */
	unsigned long computeSideItemScore(){
	    //unsigned char tmp_item_times[9]={0,0,0,0,0,0,0,0,0};
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
		string fullAwardName[12]= {
				"",
				"FULL_AWARD_ALL_FRUIT",
				"FULL_AWARD_ANY_BAR",
				"FULL_AWARD_ORANGE",
				"FULL_AWARD_MANGO",
				"FULL_AWARD_BELL",
			    "FULL_AWARD_WATERMELON",
			    "FULL_AWARD_CHERRY",
			    "FULL_AWARD_BAR_YELLOW",
			    "FULL_AWARD_BAR_RED",
			    "FULL_AWARD_BAR_BLUE",
			    //"FULL_AWARD_SEVEN",
			    "FULL_AWARD_WILD"
		};
#endif
		//unsigned char tmp_item_times[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
		unsigned char tmp_item_times[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	    unsigned long tmp_score=0;

	    //get all fruit times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_CHERRY || this->singleFrame[i].stopItem == ITEM_ORANGE ||
	    	   this->singleFrame[i].stopItem == ITEM_MANGO  || this->singleFrame[i].stopItem == ITEM_WATERMELON || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_ALL_FRUIT]++;
	    	}
	    }

	    //get any bar times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_BAR_YELLOW || this->singleFrame[i].stopItem == ITEM_BAR_RED ||
	    	   this->singleFrame[i].stopItem == ITEM_BAR_BLUE || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_ANY_BAR]++;
	    	}
	    }

	    //get orange times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_ORANGE || this->singleFrame[i].stopItem == ITEM_WILD ){
	    		tmp_item_times[FULL_AWARD_ORANGE]++;
	    	}
	    }

	    //get mango times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_MANGO || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_MANGO]++;
	    	}
	    }

	    //get bell times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_BELL || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_BELL]++;
	    	}
	    }

	    //get watermelon times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_WATERMELON || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_WATERMELON]++;
	    	}
	    }

	    //get bar yellow times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_BAR_YELLOW || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_BAR_YELLOW]++;
	    	}
	    }

	    //get cherry times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_CHERRY){
	    		tmp_item_times[FULL_AWARD_CHERRY]++;
	    	}
	    }

	    //get bar red times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_BAR_RED || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_BAR_RED]++;
	    	}
	    }

	    //get bar blue times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_BAR_BLUE || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_BAR_BLUE]++;
	    	}
	    }

	    /*
	    //get seven times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_SEVEN || this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_SEVEN]++;
	    	}
	    }
	    */

	    //get wild times
	    for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
	    	if(this->singleFrame[i].stopItem == ITEM_WILD){
	    		tmp_item_times[FULL_AWARD_WILD]++;
	    	}
	    }

	    //Save Final Stop Item
		for(unsigned char i=0; i<sizeof(finalStopItem)/sizeof(finalStopItem[0]); i++){
			 finalStopItem[i] = tmp_item_times[i];
		}
	    //
	    //Reset Frame's Side Bingo Flag to false
		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
			this->singleFrame[i].SideBingoFlag = false;
		}
	    //

		/*** Compute total full frame score ***/
		for(unsigned int i=sizeof(tmp_item_times)/sizeof(tmp_item_times[0])-1,exit=0; i>0 && exit==0; i--){
			switch(i){

			case FULL_AWARD_UNKNOW:
				break;
			case FULL_AWARD_ALL_FRUIT:
            	if(tmp_item_times[FULL_AWARD_ALL_FRUIT] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_ALL_FRUIT-1][tmp_item_times[FULL_AWARD_ALL_FRUIT]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_ALL_FRUIT);
                   this->m_fullAwardType = FULL_AWARD_ALL_FRUIT;
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_ALL_FRUIT],FullFrameAwardTypeMapping[FULL_AWARD_ALL_FRUIT-1][tmp_item_times[FULL_AWARD_ALL_FRUIT]] * this->bet));
#endif
            	}
				break;
			case FULL_AWARD_ANY_BAR:
            	if(tmp_item_times[FULL_AWARD_ANY_BAR] == 9 &&
            	   tmp_item_times[FULL_AWARD_BAR_YELLOW] != 9 &&
            	   tmp_item_times[FULL_AWARD_BAR_RED]    != 9 &&
            	   tmp_item_times[FULL_AWARD_BAR_BLUE]   != 9 &&
            	   this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_ANY_BAR-1][tmp_item_times[FULL_AWARD_ANY_BAR]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_ANY_BAR);
                   this->m_fullAwardType = FULL_AWARD_ANY_BAR;
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_ANY_BAR],FullFrameAwardTypeMapping[FULL_AWARD_ANY_BAR-1][tmp_item_times[FULL_AWARD_ANY_BAR]] * this->bet));
#endif
            	}
				break;
			case FULL_AWARD_ORANGE:
            	if(tmp_item_times[FULL_AWARD_ORANGE] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_ORANGE-1][tmp_item_times[FULL_AWARD_ORANGE]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_ORANGE);
                   this->m_fullAwardType = FULL_AWARD_ORANGE;
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_ORANGE],FullFrameAwardTypeMapping[FULL_AWARD_ORANGE-1][tmp_item_times[FULL_AWARD_ORANGE]] * this->bet));
#endif
            	}
				break;

			case FULL_AWARD_MANGO:
            	if(tmp_item_times[FULL_AWARD_MANGO] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_MANGO-1][tmp_item_times[FULL_AWARD_MANGO]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_MANGO);
                   this->m_fullAwardType = FULL_AWARD_MANGO;
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_MANGO],FullFrameAwardTypeMapping[FULL_AWARD_MANGO-1][tmp_item_times[FULL_AWARD_MANGO]] * this->bet));
#endif
            	}
				break;
			case FULL_AWARD_BELL:
            	if(tmp_item_times[FULL_AWARD_BELL] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_BELL-1][tmp_item_times[FULL_AWARD_BELL]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_BELL);
                   this->m_fullAwardType = FULL_AWARD_BELL;
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_BELL],FullFrameAwardTypeMapping[FULL_AWARD_BELL-1][tmp_item_times[FULL_AWARD_BELL]] * this->bet));
#endif
            	}
				break;
			case FULL_AWARD_WATERMELON:
            	if(tmp_item_times[FULL_AWARD_WATERMELON] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_WATERMELON-1][tmp_item_times[FULL_AWARD_WATERMELON]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_WATERMELON);
                   this->m_fullAwardType = FULL_AWARD_WATERMELON;
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_WATERMELON],FullFrameAwardTypeMapping[FULL_AWARD_WATERMELON-1][tmp_item_times[FULL_AWARD_WATERMELON]] * this->bet));
#endif
            	}
				break;
			case FULL_AWARD_BAR_YELLOW:
            	if(tmp_item_times[FULL_AWARD_BAR_YELLOW] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_BAR_YELLOW-1][tmp_item_times[FULL_AWARD_BAR_YELLOW]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_BAR_YELLOW);
                   this->m_fullAwardType = FULL_AWARD_BAR_YELLOW;
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_BAR_YELLOW],FullFrameAwardTypeMapping[FULL_AWARD_BAR_YELLOW-1][tmp_item_times[FULL_AWARD_BAR_YELLOW]] * this->bet));
#endif
            	}
				break;
			case FULL_AWARD_CHERRY:
            	if(tmp_item_times[FULL_AWARD_CHERRY] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_CHERRY-1][tmp_item_times[FULL_AWARD_CHERRY]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_CHERRY);
                   this->m_fullAwardType = FULL_AWARD_CHERRY;
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_CHERRY],FullFrameAwardTypeMapping[FULL_AWARD_CHERRY-1][tmp_item_times[FULL_AWARD_CHERRY]] * this->bet));
#endif
            	}
				break;
			case FULL_AWARD_BAR_RED:
            	if(tmp_item_times[FULL_AWARD_BAR_RED] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_BAR_RED-1][tmp_item_times[FULL_AWARD_BAR_RED]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_BAR_RED);
                   this->m_fullAwardType = FULL_AWARD_BAR_RED;
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_BAR_RED],FullFrameAwardTypeMapping[FULL_AWARD_BAR_RED-1][tmp_item_times[FULL_AWARD_BAR_RED]] * this->bet));
#endif
            	}
				break;
			case FULL_AWARD_BAR_BLUE:
            	if(tmp_item_times[FULL_AWARD_BAR_BLUE] == 9 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_BAR_BLUE-1][tmp_item_times[FULL_AWARD_BAR_BLUE]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_BAR_BLUE);
                   this->m_fullAwardType = FULL_AWARD_BAR_BLUE;
                   exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_BAR_BLUE],FullFrameAwardTypeMapping[FULL_AWARD_BAR_BLUE-1][tmp_item_times[FULL_AWARD_BAR_BLUE]] * this->bet));
#endif
            	}
				break;
			/*
			case FULL_AWARD_SEVEN:
            	if(tmp_item_times[FULL_AWARD_SEVEN] >= 2 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_SEVEN-1][tmp_item_times[FULL_AWARD_SEVEN]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_SEVEN);
                   //exit=1;
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   this->fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_SEVEN],FullFrameAwardTypeMapping[FULL_AWARD_SEVEN-1][tmp_item_times[FULL_AWARD_SEVEN]] * this->bet));
#endif
            	}
				break;
			*/
			case FULL_AWARD_WILD:
            	if(tmp_item_times[FULL_AWARD_WILD] >= 3 && this->bet > 0 ){
                   tmp_score += FullFrameAwardTypeMapping[FULL_AWARD_WILD-1][tmp_item_times[FULL_AWARD_WILD]] * this->bet;
                   this->setSideBingoFlag(FULL_AWARD_WILD);
                   if(tmp_item_times[FULL_AWARD_WILD] == 9){
                	   this->m_fullAwardType = FULL_AWARD_WILD;
                	   exit=1;
                   }
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
                   fullAwardRecord.insert(pair<string,unsigned long>(fullAwardName[FULL_AWARD_WILD],FullFrameAwardTypeMapping[FULL_AWARD_WILD-1][tmp_item_times[FULL_AWARD_WILD]] * this->bet));
#endif
            	}
				break;

			default:
				break;
			}
		}

#ifdef DEBUG_OUTPUT_AWARD_DETAIL
		std::map<string,unsigned long>::iterator fullAwardNameIterator;
		fullAwardNameIterator = fullAwardRecord.begin();
		for(;fullAwardNameIterator!=fullAwardRecord.end();fullAwardNameIterator++){
			printf("FULL Frame Award Type is : %s, Win is %ld \n",fullAwardNameIterator->first.c_str(),fullAwardNameIterator->second);
		}
		fullAwardRecord.clear();
#endif
	    return tmp_score;

	}
    /**
     * @brief Get total win.
     * @retval Total win
     */
	unsigned long getTotalWin(SYSTEMSETTINGDATA* _systemSettingData){
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
	    string lineAwardName[13] = {
			"LINE_AWARD_NONE",
			"LINE_AWARD_ONE_CHERRY",
			"LINE_AWARD_TWO_CHERRY",
			"LINE_AWARD_THREE_CHERRY",
			"LINE_AWARD_ORANGE",
			"LINE_AWARD_MIX_BAR",
			"LINE_AWARD_MANGO",
			"LINE_AWARD_BELL",
			"LINE_AWARD_WATERMELON",
			"LINE_AWARD_BAR_YELLOW",
			"LINE_AWARD_BAR_RED",
			"LINE_AWARD_BAR_BLUE",
			//"LINE_AWARD_SEVEN",
			"LINE_AWARD_WILD",
	    };
#endif

#ifdef Max_Win_Limit

#ifdef DEBUG_OUTPUT_AWARD_DETAIL
	    printf("---------------------- AWARD DETAIL OUTPUT ----------------------\n");
#endif
	    unsigned long totalwin = 0;
		for(unsigned int i=0; i<sizeof(this->line)/sizeof(this->line[0]); i++){
		    totalwin += this->line[i].computeLineScore(this->singleFrame);
#ifdef DEBUG_OUTPUT_AWARD_DETAIL
		    if(this->line[i].bingotype != LINE_AWARD_NONE){
		    	printf("Line %d award type is : %s, Win is %ld \n",i+1,lineAwardName[this->line[i].bingotype].c_str(),this->line[i].win);
		    }
#endif

		}

		// Total win can't over ( single_line_maxbet * 8 * 100000 ).
		totalwin += this->computeSideItemScore();
		if(totalwin > (((unsigned long)_systemSettingData->_SingleLineMaxBet*8/8) * (100000)) ){
			totalwin = (((unsigned long)_systemSettingData->_SingleLineMaxBet*8/8) * (100000));
		}

#ifdef DEBUG_OUTPUT_AWARD_DETAIL
		printf("Total win is : %ld \n",totalwin);
		printf("-----------------------------------------------------------------\n");
#endif

		return totalwin;

#else
		unsigned long tmp = 0;
		for(unsigned int i=0; i<sizeof(this->line)/sizeof(this->line[0]); i++){
		    tmp += this->line[i].computeLineScore(this->singleFrame);
		}
		return this->computeSideItemScore() + tmp;
#endif
	}
    /**
     * @brief Reset scroll parameters for re-starting.
     * @retval 0:success others:failure
     */
	unsigned int ResetScrollParameters(){

		this->m_fullAwardType = FULL_AWARD_UNKNOW;

		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
			this->singleFrame[i].Loop = 0;
			this->singleFrame[i].StopFlag = false;
			this->singleFrame[i].LineBingoFlag = false;
			this->singleFrame[i].SideBingoFlag = false;
			this->singleFrame[i].AnimeIndex= 1;
			this->singleFrame[i].AnimeLoop = 0;
			this->singleFrame[i].AnimeFlag = false;
			this->singleFrame[i].scrollStatus = scroll_Stop;//scroll_Normal;
		}

		for(unsigned int i=0; i<sizeof(this->line)/sizeof(this->line[0]); i++){
			this->line[i].bingoFlag = false;
			this->line[i].bingotype = LINE_AWARD_NONE;
		}

		this->m_slotAnimeSequence = main_slot_anime_sequence_fullframe;
		this->m_slotAnimeSequenceLoopTimes = 0;

		return 0;
	}
	/**
	 * @brief Reset Slot Y Axis Position Before Rolling.
	 */
	void ResetRollingYAxisPotion(void){
		this->singleFrame[0].rect.y = 980;
		this->singleFrame[1].rect.y = 1120;
		this->singleFrame[2].rect.y = 1260;
		this->singleFrame[3].rect.y = 560;
		this->singleFrame[4].rect.y = 700;
		this->singleFrame[5].rect.y = 840;
		this->singleFrame[6].rect.y = 140;
		this->singleFrame[7].rect.y = 280;
		this->singleFrame[8].rect.y = 420;
	}
    /**
     * @brief Get total link or side item bingo frames .
     * @retval Count
     */
	unsigned int getTotalLinkOrSideBingoFrame(){
		unsigned int result=0;
		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
			if(this->singleFrame[i].SideBingoFlag==true || this->singleFrame[i].LineBingoFlag==true){
			   result++;
			}
		}

		return result;
	}
    /**
     * @brief Set side bingo flag.
     * @param sideBingoType Side item bingo type
     * @retval 0:success others:failure
     */
	unsigned int setSideBingoFlag(unsigned int sideBingoType){

		switch(sideBingoType){

		case FULL_AWARD_UNKNOW:
			break;
		case FULL_AWARD_ALL_FRUIT:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_CHERRY || this->singleFrame[i].stopItem == ITEM_ORANGE ||
    			   this->singleFrame[i].stopItem == ITEM_MANGO  || this->singleFrame[i].stopItem == ITEM_WATERMELON || this->singleFrame[i].stopItem == ITEM_WILD ){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_ORANGE:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_ORANGE || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_ANY_BAR:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_BAR_YELLOW || this->singleFrame[i].stopItem == ITEM_BAR_RED ||
    			   this->singleFrame[i].stopItem == ITEM_BAR_BLUE || this->singleFrame[i].stopItem == ITEM_WILD ){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_MANGO:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_MANGO || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_BELL:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_BELL || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_WATERMELON:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_WATERMELON || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_CHERRY:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_CHERRY || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_BAR_YELLOW:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_BAR_YELLOW || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_BAR_RED:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_BAR_RED || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		case FULL_AWARD_BAR_BLUE:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_BAR_BLUE || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		/*
		case FULL_AWARD_SEVEN:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_SEVEN || this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;
		*/
		case FULL_AWARD_WILD:
    		for(unsigned int i=0; i<sizeof(this->singleFrame)/sizeof(this->singleFrame[0]); i++){
    			if(this->singleFrame[i].stopItem == ITEM_WILD){
    			   this->singleFrame[i].SideBingoFlag = true;
    			}
    		}
			break;

		default:
			break;
		}

		return 0;
	}

	/**
	 * @brief Get JACKPOT TYPE.
	 * @retval JACKPOT Type
	 */
	unsigned int GetJackpotType(void){
		unsigned int jackpotType = jackpotType_None;
        unsigned int jackpotMappingArray[5]={1,3,4,5,7};

        //JP 1 Check
        for(unsigned int idx=0,cnt=0; idx<sizeof(jackpotMappingArray)/sizeof(jackpotMappingArray[0]); idx++){
        	if(this->singleFrame[jackpotMappingArray[idx]].stopItem == ITEM_BAR_BLUE){
        		cnt++;
        		if(cnt == 5){
        			jackpotType = jackpotType_JP1;
        			return jackpotType;
        		}
        	}
        }

        //JP 2 Check
        for(unsigned int idx=0,cnt=0; idx<sizeof(jackpotMappingArray)/sizeof(jackpotMappingArray[0]); idx++){
        	if(this->singleFrame[jackpotMappingArray[idx]].stopItem == ITEM_BAR_RED){
        		cnt++;
        		if(cnt == 5){
        			jackpotType = jackpotType_JP2;
        			return jackpotType;
        		}
        	}
        }

        //JP 3 Check
        for(unsigned int idx=0,cnt=0; idx<sizeof(jackpotMappingArray)/sizeof(jackpotMappingArray[0]); idx++){
        	if(this->singleFrame[jackpotMappingArray[idx]].stopItem == ITEM_BAR_YELLOW){
        		cnt++;
        		if(cnt == 5){
        			jackpotType = jackpotType_JP3;
        			return jackpotType;
        		}
        	}
        }

		return jackpotType;
	}

	  unsigned int getSingleLineAwardFrameCount(unsigned int line){
		  unsigned int cnt = 0;
		  for(unsigned int idx=0; idx<sizeof(this->line[line].bingoFrame)/sizeof(this->line[line].bingoFrame[0]); idx++){
			  if(this->singleFrame[this->line[line].bingoFrame[idx]].LineBingoFlag == true){
				  cnt++;
			  }
		  }

		  return cnt;
	  }


}MAINGAMECONTENT;

/**
 * @brief Double Game Content.
 */
typedef struct DoubleGameContent {
	unsigned int m_step;/**< Step */
	unsigned int m_subStep;/**< Sub step */
	int m_playerSelect;/**< Player selected or not */
	unsigned char m_gameResult;/**< One turn result */
	unsigned int m_history[5];/**< history */
	unsigned int m_this_turn_award_type;/**< this turn award type */
	unsigned int m_this_turn_open_type;/**< this turn open type */
	unsigned int m_this_turn_result_type;/**< this turn result type */
	unsigned int m_max_pass_times;/**< Max pass times */

	/**
	 * @brief Constructor.
	 */
	DoubleGameContent(void){
		this->Reset();
	}

	/**
	 * @brief Reset all member parameters.
	 */
	void Reset(){
		this->m_step = dg_step_Inactive;
		this->m_subStep = dg_sub_step_Inactive;
		this->m_playerSelect = dgame_player_selected_ushimaou;
		this->m_gameResult = dgame_result_not_play;
		this->m_this_turn_award_type = dgame_award_type_lose;
		this->m_this_turn_open_type = dgame_open_type_gokuu;
		this->m_max_pass_times = 0;

		for(unsigned int idx=0; idx<sizeof(this->m_history)/sizeof(this->m_history[0]); idx++){
			this->m_history[idx] = dgame_award_history_type_gokuu_x2 - 1;
		}
	}

	/*
	 * @brief Reset player's selection.
	 */
	void ResetPlayerSelect(){

	}

	/**
	 * @brief Add history record.
	 */
	void AddHistoryRecord(unsigned int thisTurnRecord){
		for(unsigned int idx=0; idx<sizeof(this->m_history)/sizeof(this->m_history[0])-1; idx++){
			this->m_history[idx] = this->m_history[idx+1];
		}

		this->m_history[sizeof(this->m_history)/sizeof(this->m_history[0])-1] = thisTurnRecord;

	}

}DOUBLEGAMECONTENT;


#define SP_SLOT_3_STRAIGHT_MULTIPLE   20
#define SP_SLOT_4_STRAIGHT_MULTIPLE  500

/**
 * @brief Special Game Content.
 */
typedef struct SpecialGameContent{
	SINGLEFRAME m_sp_frame[4];/**< SP Slot Frame */
	unsigned int m_step;/**< Step */
	unsigned int m_subStep;/**< Sub step */
	unsigned int m_sp_win;/**< Special Game One Turn Win */
	unsigned int m_sp_this_time_total_win;/**< Special Game This Time Total Win */
	unsigned int m_saiyuuki_times;/**< SAIYUUKI Times */
	unsigned int m_draw_table_index;/**< Index of draw table */
	unsigned int m_draw_run_index;/**< Draw run index */
	unsigned int m_light_award_table[SP_LIGHT_AWARD_COUNT];/**< Light Award Table */
	unsigned int m_draw_type_array[SP_MAX_PLAY_TIMES];/**< This turn draw type array */
	unsigned int m_this_turn_draw_type;/**< This turn draw type */
	unsigned int m_total_play_times;/**< Total play times */
	unsigned int m_player_play_times;/**< Player play times */
	unsigned int m_this_turn_light_award;/**< This turn light award */
	unsigned int m_this_turn_slot_award;/**< This turn slot award */
	unsigned int m_this_turn_light_result;/**< This turn light result */
	unsigned int m_this_turn_slot_result;/**< This turn slot result */
	unsigned int m_cloud_index;/**< Cloud Index */
	unsigned int m_light_loop_times;/**< Light Loop Times */
	          int m_next_light_index;/**< Next light index */
	          int m_prepare_stop_index;/**< Prepare Stop Index */

    /**
     * @brief Constructor.
     */
	SpecialGameContent(void){
    	this->Reset();
    }

	/**
	 * @brief Reset.
	 */
	void Reset(void){

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

        this->ResetDrawTypeArray();

        this->m_draw_table_index       = 0;
        this->m_draw_run_index         = 0;
        this->m_this_turn_draw_type    = sp_draw_type_none;
		this->m_this_turn_light_award  = sp_light_award_type_none;
		this->m_this_turn_slot_award   = sp_slot_award_type_none;
		this->m_this_turn_light_result = sp_light_award_result_none;
		this->m_this_turn_slot_result  = sp_slot_award_result_none;
		this->m_sp_this_time_total_win = 0;

		for(unsigned int idx=0; idx<sizeof(m_sp_frame)/sizeof(m_sp_frame[0]);idx++){
			this->m_sp_frame[idx].itemSheetObject[ITEM_UNKNOW]     = NULL;
			this->m_sp_frame[idx].itemSheetObject[ITEM_CHERRY]     = &sp_slot_item_cherry;
			this->m_sp_frame[idx].itemSheetObject[ITEM_ORANGE]     = &sp_slot_item_orange;
			this->m_sp_frame[idx].itemSheetObject[ITEM_MANGO]      = &sp_slot_item_mango;
			this->m_sp_frame[idx].itemSheetObject[ITEM_BELL]       = &sp_slot_item_bell;
			this->m_sp_frame[idx].itemSheetObject[ITEM_WATERMELON] = &sp_slot_item_watermelon;
			this->m_sp_frame[idx].itemSheetObject[ITEM_BAR_YELLOW] = &sp_slot_item_bar_yellow;
			this->m_sp_frame[idx].itemSheetObject[ITEM_BAR_RED]    = &sp_slot_item_bar_red;
			this->m_sp_frame[idx].itemSheetObject[ITEM_BAR_BLUE]   = &sp_slot_item_bar_blue;
			//this->m_sp_frame[idx].itemSheetObject[ITEM_SEVEN]      = &slot_item_seven;
			this->m_sp_frame[idx].itemSheetObject[ITEM_WILD]       = &sp_slot_item_wild;

			this->m_sp_frame[idx].itemAnimeSheetObject[ITEM_UNKNOW]     = NULL;
			this->m_sp_frame[idx].itemAnimeSheetObject[ITEM_CHERRY]     = &sp_slot_anime_item_cherry;
			this->m_sp_frame[idx].itemAnimeSheetObject[ITEM_ORANGE]     = &sp_slot_anime_item_orange;
			this->m_sp_frame[idx].itemAnimeSheetObject[ITEM_MANGO]      = &sp_slot_anime_item_mango;
			this->m_sp_frame[idx].itemAnimeSheetObject[ITEM_BELL]       = &sp_slot_anime_item_bell;
			this->m_sp_frame[idx].itemAnimeSheetObject[ITEM_WATERMELON] = &sp_slot_anime_item_watermelon;
			this->m_sp_frame[idx].itemAnimeSheetObject[ITEM_BAR_YELLOW] = &sp_slot_anime_item_bar_yellow;
			this->m_sp_frame[idx].itemAnimeSheetObject[ITEM_BAR_RED]    = &sp_slot_anime_item_bar_red;
			this->m_sp_frame[idx].itemAnimeSheetObject[ITEM_BAR_BLUE]   = &sp_slot_anime_item_bar_blue;
			this->m_sp_frame[idx].itemAnimeSheetObject[ITEM_WILD]       = &sp_slot_anime_item_wild;
		}

        //Frame[0]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		m_sp_frame[0].setScrollType(Type_Test);
#else
		m_sp_frame[0].setScrollType(Type_Slot1_Mutable);
#endif
		m_sp_frame[0].slotMoveSheetObject =  &sp_slot_move_type1;
		m_sp_frame[0].pos_X        =           SP_SLOT_1_X;
		m_sp_frame[0].pos_Y        =           SP_SLOT_1_Y;
		m_sp_frame[0].stopItem     =        ITEM_CHERRY;
		m_sp_frame[0].NextStopLine =                  0;
		m_sp_frame[0].StopFlag     =             false;
		m_sp_frame[0].Loop         =                  0;
		m_sp_frame[0].SideBingoFlag=             false;
		m_sp_frame[0].LineBingoFlag=             false;
		m_sp_frame[0].rect.x = 0;
		m_sp_frame[0].rect.y = DEF_OFFSET_RECT_Y;
		m_sp_frame[0].rect.w = SINGLE_FRAME_WIDTH;
		m_sp_frame[0].rect.h = SINGLE_FRAME_HEIGHT;
		m_sp_frame[0].award_frame_pos_X = SP_SLOT_AWARD_FRAME_1_POS_X;
		m_sp_frame[0].award_frame_pos_Y = SP_SLOT_AWARD_FRAME_1_POS_Y;
		//Frame[1]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		m_sp_frame[1].setScrollType(Type_Test);
#else
		m_sp_frame[1].setScrollType(Type_Slot2_Fixed);
#endif
		m_sp_frame[1].slotMoveSheetObject =  &sp_slot_move_type1;
		m_sp_frame[1].pos_X        =           SP_SLOT_2_X;
		m_sp_frame[1].pos_Y        =   		SP_SLOT_2_Y;
		m_sp_frame[1].stopItem     =        ITEM_ORANGE;
		m_sp_frame[1].NextStopLine =                  0;
		m_sp_frame[1].StopFlag     =             false;
		m_sp_frame[1].Loop         =                  0;
		m_sp_frame[1].SideBingoFlag=             false;
		m_sp_frame[1].LineBingoFlag=             false;
		m_sp_frame[1].rect.x = 0;
		m_sp_frame[1].rect.y = DEF_OFFSET_RECT_Y;
		m_sp_frame[1].rect.w = SINGLE_FRAME_WIDTH;
		m_sp_frame[1].rect.h = SINGLE_FRAME_HEIGHT;
		m_sp_frame[1].award_frame_pos_X = SP_SLOT_AWARD_FRAME_2_POS_X;
		m_sp_frame[1].award_frame_pos_Y = SP_SLOT_AWARD_FRAME_2_POS_Y;
		//Frame[2]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		m_sp_frame[2].setScrollType(Type_Test);
#else
		m_sp_frame[2].setScrollType(Type_Slot3_Fixed);
#endif
		m_sp_frame[2].slotMoveSheetObject =  &sp_slot_move_type1;
		m_sp_frame[2].pos_X        =           SP_SLOT_3_X;
		m_sp_frame[2].pos_Y        =           SP_SLOT_3_Y;
		m_sp_frame[2].stopItem     =         ITEM_MANGO;
		m_sp_frame[2].NextStopLine =                  0;
		m_sp_frame[2].StopFlag     =             false;
		m_sp_frame[2].Loop         =                  0;
		m_sp_frame[2].SideBingoFlag=             false;
		m_sp_frame[2].LineBingoFlag=             false;
		m_sp_frame[2].rect.x = 0;
		m_sp_frame[2].rect.y = DEF_OFFSET_RECT_Y;
		m_sp_frame[2].rect.w = SINGLE_FRAME_WIDTH;
		m_sp_frame[2].rect.h = SINGLE_FRAME_HEIGHT;
		m_sp_frame[2].award_frame_pos_X = SP_SLOT_AWARD_FRAME_3_POS_X;
		m_sp_frame[2].award_frame_pos_Y = SP_SLOT_AWARD_FRAME_3_POS_Y;
		//Frame[3]
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
		m_sp_frame[3].setScrollType(Type_Test);
#else
		m_sp_frame[3].setScrollType(Type_Slot4_Fixed);
#endif
		m_sp_frame[3].slotMoveSheetObject =  &sp_slot_move_type1;
		m_sp_frame[3].pos_X        =   		SP_SLOT_4_X;
		m_sp_frame[3].pos_Y        =   		SP_SLOT_4_Y;
		m_sp_frame[3].stopItem     =          ITEM_BELL;
		m_sp_frame[3].NextStopLine =                  0;
		m_sp_frame[3].StopFlag     =             false;
		m_sp_frame[3].Loop         =                  0;
		m_sp_frame[3].SideBingoFlag=             false;
		m_sp_frame[3].LineBingoFlag=             false;
		m_sp_frame[3].rect.x = 0;
		m_sp_frame[3].rect.y = DEF_OFFSET_RECT_Y;
		m_sp_frame[3].rect.w = SINGLE_FRAME_WIDTH;
		m_sp_frame[3].rect.h = SINGLE_FRAME_HEIGHT;
		m_sp_frame[3].award_frame_pos_X = SP_SLOT_AWARD_FRAME_4_POS_X;
		m_sp_frame[3].award_frame_pos_Y = SP_SLOT_AWARD_FRAME_4_POS_Y;

		for(unsigned int i=0; i<sizeof(this->m_sp_frame)/sizeof(this->m_sp_frame[0]); i++){
			this->m_sp_frame[i].AnimeIndex=1;
			this->m_sp_frame[i].AnimeLoop =0;
			this->m_sp_frame[i].scrollStatus = scroll_Stop;
		}
	}

	/**
	 * @brief Reset This Turn Draw Array.
	 */
	void ResetDrawTypeArray(void){
		for(unsigned int idx=0; idx<sizeof(m_draw_type_array)/sizeof(m_draw_type_array[0]); idx++){
			this->m_draw_type_array[idx] = sp_draw_type_none;
		}

	}

    /**
     * @brief Reset slot parameters for re-starting.
     * @retval 0:success others:failure
     */
	unsigned int ReSetSlotParameters(){

		for(unsigned int i=0; i<sizeof(this->m_sp_frame)/sizeof(this->m_sp_frame[0]); i++){
			this->m_sp_frame[i].Loop = 0;
			this->m_sp_frame[i].StopFlag = false;
			this->m_sp_frame[i].LineBingoFlag = false;
			this->m_sp_frame[i].SideBingoFlag = false;
			this->m_sp_frame[i].AnimeIndex= 1;
			this->m_sp_frame[i].AnimeLoop = 0;
			this->m_sp_frame[i].scrollStatus = scroll_Stop;//scroll_Normal;
		}

		return 0;
	}
	/**
	 * @brief Reset Slot Y Axis Position Before Rolling.
	 */
	void ResetRollingYAxisPotion(void){
		this->m_sp_frame[0].rect.y = 140;
		this->m_sp_frame[1].rect.y = 420;
		this->m_sp_frame[2].rect.y = 700;
		this->m_sp_frame[3].rect.y = 980;
	}
    /**
     * @brief Change Light Type To Slot Type.
     */
    unsigned int ChangeLightTypeToSlotType(unsigned int lightType){
    	unsigned int slotType = ITEM_UNKNOW;
    	unsigned int translate[9] ={ 2, 3, 4, 5, 1, 6, 7, 8, 9 };

    	if(lightType < 2){
    		return 0;
    	}

    	slotType = translate[lightType-2];
    	return slotType;

    }

	/**
	 * @brief Compute Light Award Win Score.
	 */
    unsigned int ComputeLightAwardWinScore(unsigned int bet){
    	unsigned int light_win = 0;
    	bool result = false;

    	for(unsigned int idx=0; idx<sizeof(this->m_sp_frame)/sizeof(this->m_sp_frame[0]); idx++){
    		if(ChangeLightTypeToSlotType(this->m_light_award_table[this->m_cloud_index])==this->m_sp_frame[idx].stopItem){
    			result = true;
    			this->m_sp_frame[idx].LineBingoFlag = true;
    		}
    	}

    	if(result == true){
			light_win = bet * SpecialGameLightAwardMultiple[this->m_light_award_table[this->m_cloud_index]-2];

			switch(this->m_light_award_table[this->m_cloud_index]){

			case sp_light_award_type_weapon_3:
				this->m_this_turn_light_result = sp_light_award_result_weapon_3;
				break;
			case sp_light_award_type_weapon_2:
				this->m_this_turn_light_result = sp_light_award_result_weapon_2;
				break;
			case sp_light_award_type_book:
				this->m_this_turn_light_result = sp_light_award_result_book;
				break;
			case sp_light_award_type_weapon_4:
				this->m_this_turn_light_result = sp_light_award_result_weapon_4;
				break;
			case sp_light_award_type_weapon_1:
				this->m_this_turn_light_result = sp_light_award_result_weapon_1;
				break;
			case sp_light_award_type_character_3:
				this->m_this_turn_light_result = sp_light_award_result_character_3;
				break;
			case sp_light_award_type_character_2:
				this->m_this_turn_light_result = sp_light_award_result_character_2;
				break;
			case sp_light_award_type_character_1:
				this->m_this_turn_light_result = sp_light_award_result_character_1;
				break;
			case sp_light_award_type_saiyuuki:
				this->m_this_turn_light_result = sp_light_award_result_saiyuuki;
				break;

			default:
				break;
			}

    	}else{
    		if(this->m_light_award_table[this->m_cloud_index]==sp_light_award_type_exit){
    			this->m_this_turn_light_result = sp_light_award_result_exit;
    		}else{
    			this->m_this_turn_light_result = sp_light_award_result_none;
    		}
    	}
#ifdef _DEBUG
    	assert(this->m_this_turn_light_award == this->m_this_turn_light_result);
#endif
    	return light_win;
    }

	/**
	 * @brief Compute Slot Award Win Score.
	 */
	unsigned int ComputeSlotAwardWinScore(unsigned long bet){
		unsigned int slot_win_x20_array_1[3] = {0,1,2};
		unsigned int slot_win_x20_array_2[3] = {1,2,3};
		unsigned int slot_win_x500_array[4]  = {0,1,2,3};

		this->m_this_turn_slot_result = sp_slot_award_type_none;

		if(this->m_this_turn_slot_award != sp_slot_award_type_none){
			//Compute Slot Award
			//x500
			if((this->m_sp_frame[slot_win_x500_array[0]].stopItem == this->m_sp_frame[slot_win_x500_array[1]].stopItem) &&
				(this->m_sp_frame[slot_win_x500_array[1]].stopItem == this->m_sp_frame[slot_win_x500_array[2]].stopItem) &&
				(this->m_sp_frame[slot_win_x500_array[2]].stopItem == this->m_sp_frame[slot_win_x500_array[3]].stopItem)){
				this->m_this_turn_slot_result = sp_slot_award_result_x500;
				//Set Line Bingo Flag
				for(unsigned int idx=0; idx<sizeof(slot_win_x500_array)/sizeof(slot_win_x500_array[0]); idx++){
					this->m_sp_frame[slot_win_x500_array[idx]].LineBingoFlag = true;
				}

	#ifdef _DEBUG
				assert(this->m_this_turn_slot_award == this->m_this_turn_slot_result);
	#endif
				return bet *  SP_SLOT_4_STRAIGHT_MULTIPLE;
			}
			//x20
			//Type 0 1 2
			if((this->m_sp_frame[slot_win_x20_array_1[0]].stopItem == this->m_sp_frame[slot_win_x20_array_1[1]].stopItem) &&
				(this->m_sp_frame[slot_win_x20_array_1[1]].stopItem == this->m_sp_frame[slot_win_x20_array_1[2]].stopItem)){
				this->m_this_turn_slot_result = sp_slot_award_result_x20;
				//Set Line Bingo Flag
				for(unsigned int idx=0; idx<sizeof(slot_win_x20_array_1)/sizeof(slot_win_x20_array_1[0]); idx++){
					this->m_sp_frame[slot_win_x20_array_1[idx]].LineBingoFlag = true;
				}
	#ifdef _DEBUG
				assert(this->m_this_turn_slot_award == this->m_this_turn_slot_result);
	#endif
				return bet *  SP_SLOT_3_STRAIGHT_MULTIPLE;
			}
			//Type 1 2 3
			if((this->m_sp_frame[slot_win_x20_array_2[0]].stopItem == this->m_sp_frame[slot_win_x20_array_2[1]].stopItem) &&
				 (this->m_sp_frame[slot_win_x20_array_2[1]].stopItem == this->m_sp_frame[slot_win_x20_array_2[2]].stopItem)){
				this->m_this_turn_slot_result = sp_slot_award_result_x20;
				//Set Line Bingo Flag
				for(unsigned int idx=0; idx<sizeof(slot_win_x20_array_2)/sizeof(slot_win_x20_array_2[0]); idx++){
					this->m_sp_frame[slot_win_x20_array_2[idx]].LineBingoFlag = true;
				}
	#ifdef _DEBUG
				assert(this->m_this_turn_slot_award == this->m_this_turn_slot_result);
	#endif
				return bet *  SP_SLOT_3_STRAIGHT_MULTIPLE;
			}

		}

		return 0;
	}

	/**
	 * @brief Get Total Line Bingo Frame.
	 */
	unsigned int getTotalLineBingoFrame(void){
		unsigned count = 0;
		for(unsigned int idx=0; idx<sizeof(this->m_sp_frame)/sizeof(this->m_sp_frame[0]); idx++){
			if(this->m_sp_frame[idx].LineBingoFlag == true){
				count++;
			}
		}

		return count;
	}

}SPECIALGAMECONTENT;

#endif /* GAMELOGICTYPE_H_ */
