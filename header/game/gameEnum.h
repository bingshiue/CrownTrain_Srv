/**
 * @file gameEnum.h
 * @brief define game enumeration.
 *
 */

#ifndef GAMEENUM_H_
#define GAMEENUM_H_

#include "../preprocessor.h"

/**
 * @brief Special Bonus Animation.
 */
enum SpecialAnimeType{
	Type_none   = 0,           /**< No Special Bonus Animation */
	Type_Red_7  = 1,           /**< Special Bonus Animation of Red 7 Straight */
	Type_Blue_7 = 2,           /**< Special Bonus Animation of Blue 7 Straight */
	Type_JOKER  = 3            /**< Special Bonus Animation of Joker Straight */
};

/**
 * @brief JackPot Type.
 */
enum JacPotType{
    jackpotType_None = 0,      /**< JackPot Type None */
    jackpotType_JP1  = 1,      /**< JackPot Type 1 */
    jackpotType_JP2  = 2,      /**< JackPot Type 2 */
    jackpotType_JP3  = 3       /**< JackPot Type 3 */
};

/**
 * @brief Get JacPot Scores Type.
 */
enum GetJacpotType{
	jac_AddToCredit        = 0,/**< Add JacPot Scores To Credit Directly */
	jac_PressKeyoutToClear = 1 /**< Press Key-Out Key To Clear JacPot Scores(Don't Add To Credit) */
};

/**
 * @brief Bonus Setting Type.
 */
enum BonusSettingMaster{
	DonotListenToMaster    = 0,/**< Follow Slave's  Setting Value */
	ListenToMaster         = 1 /**< Follow Master's Setting Value */
};

/**
 * @brief Special Information Render Pattern.
 */
enum SpInfoRenderPattern{
	SPPATTERN_Clr          = 0,/**< Pattern Clear */
	SPPATTERN_1            = 1,/**< Pattern 1 */
	SPPATTERN_2            = 2 /**< Pattern 2 */
};
/*
 * @brief MOTT Mode.
 */
enum MottMode{
	mott_key_in  = 0,/**< MOTT Key In */
	mott_key_out = 1,/**< MOTT Key Out */
	mott_coin_in = 2,/**< MOTT Coin In */
	mott_coin_out= 3 /**< MOTT Coin Out */
};
/*
 * @brief Scroll Status ENUM.
 */
enum ScrollStatus{
	scroll_Stop      = 0,/**< Stop      Status */
	scroll_Normal    = 1,/**< Normal    Status */
	scroll_Temp      = 2,/**< TEMP      Status */
	scroll_PreChange = 3,/**< PreChange Status */
	scroll_ToStop    = 4,/**< ToStop    Status */
	scroll_Temp2     = 5,/**< TEMP2     Status */
};

/**
 * @brief Double down return kind.
 */
enum DoubleDownKind{
     DDownKind_Standard  = 0,/**< Standard Type Manual */
     DDownKind_Auto      = 1 /**< Auto Mode */
};
/**
 * @brief Double down kind.
 */
enum DoubleDown{
	 DDown_None          = 0,/**< No double down game */
	 DDown_OneTime       = 1,/**< Can only play one turn */
	 DDown_Half          = 2,/**< Allow half style */
	 DDown_Over100000    = 3 /**< Over 100000 coins can't enter double down game */
};

/**
 * @brief quick collect.
 */
enum QuickCollect{
     QuickCollect_OFF = 0,/**< quick collect off */
     QuickCollect_ON  = 1 /**< quick collect on */
};
/**
 * @brief Reel spin speed.
 */
enum ReelSpinSpeed{
	 Reel_Spin_Speed_Slow   = 0,/**< slow */
	 Reel_Spin_Speed_Normal = 1,/**< normal */
	 Reel_Spin_Speed_Fast   = 2 /**< fast */
};
/**
 * @brief Color of Frame.
 */
enum FrameColor{
     Frame_Color_White              = 0,/**< Frame color white */
	 Frame_Color_Yellow             = 1,/**< Frame color yellow */
	 Frame_Color_Green              = 2,/**< Frame color green */
	 Frame_Color_Blue               = 3,/**< Frame color blue */
	 Frame_Color_Purple             = 4,/**< Frame color purple */
	 Frame_Color_Pink               = 5 /**< Frame color pink */
};
/**
 * @brief Color of BackGround.
 */
enum ScreenColor{
	 Screen_Color_Black             = 0,/**< BackGround color black */
	 Screen_Color_Brown             = 1,/**< BackGround color brown */
	 Screen_Color_Green             = 2,/**< BackGround color green */
	 Screen_Color_Light_Green       = 3,/**< BackGround color light green */
	 Screen_Color_Blue              = 4,/**< BackGround color blue */
	 Screen_Color_Purple            = 5 /**< BackGround color purple */
};

/**
 * @brief Generic Enable Disable ENUM.
 */
enum GenericEnableDisable{
	 Disable = 0,/**< disable */
	 Enable  = 1,/**< enable */
};

/**
 * @brief Generic Limited Unlimited Enumeration.
 */
enum GenericLimitedUlimited{
	 Unlimited = 0,
	 Limited,
};

/**
 * @brief Pay Setting.
 */
enum PAYSETTING{
	Pay_setting_hopper = 0,/**< Pay Setting Hopper */
	Pay_setting_ticket,/**< Pay Setting Ticket */
};

/**
 * @brief hopper setting NO/NC.
 */
enum HOPPERSETTING{
	 Hopper_NO = 0,/**< NO */
	 Hopper_NC = 1,/**< NC */
};

/**
 * @brief LINK FUNCTION On/Off.
 */
enum CONNECTONOFF{
     Connect_OFF = Disable,/**< Connect off */
	 Connect_ON  = Enable  /**< Connect on  */
};

/**
 * @brief DoubleUP Key Mode.
 */
enum DOUBLEUPKEYMOD{
	Start = 0,/**< start */
	Score = 1,/**< score */
	None  = 2 /**< none */
};

/**
 * @brief Double down player select.
 */
enum DDownPlayerSelect{
	select_left   = 0,
	select_middle = 1,
	select_right  = 2,
};

/**
 * @brief Main Game Step Enumeration.
 *
 */
enum MAINGAMESTEP{
	main_step_Inactive = 0,/**< Inactive */
	main_step_SavePoint_BeforeStart,/**< Save Point Before Start */
	main_step_StandBy,/**< Standby */
	main_step_SlotStartPrepare,/**< Prepare for starting slot */
	main_step_SlotScroll,/**< Slot scroll */
    main_step_WaitNoWin,/**< Wait no win */
    main_step_WaitEnterToDoubleGameOrNot,/**< Wait enter to double game or not */
    main_step_CheckSPAnime_1,/**< Check Animation 1 */
    main_step_CheckSPAnime_2,/**< Check Animation 2 */
    main_step_CheckResult,/**< Check this turn win or not */
    main_step_SlotWinning,/**< Winning */
    main_step_AddWinningCredits,/**< Add scores */
    main_step_EnterDDownOrNot,/**< Enter Double Down or not */
    main_step_JackpotSync,/**< Get Jackpot Synchronize */
    main_step_GetJackpot,/**< Get Jackpot Action */
    main_step_JackpotEnd,/**< Get Jackpot End */
    main_step_AddWinToCreditOver,/**< Tell CGA Add Win To Credit Over */
    main_step_KeyOut,/**< Key Out */
    main_step_PayOut,/**< Pay Out */
    main_step_SavePoint_AfterPrepare,/**< Save Point After Prepare */
    main_step_SavePoint_AfterAddScore,/**< Save Point After Add Score */
    main_step_SavePoint_BeforeWaitEnterToDoubleGameOrNot,/**< Save Point Before Wait Enter To Double Game or Not */
    main_step_SavePoint_BeforeWaitNoWin,/**< Save Point Before Wait No Win */
    main_step_SavePoint_BeforeKeyOut,/**< Save Point Before KeyOut */
    main_step_SavePoint_BeforeWaitForCheckBigWin,/**< Save For Before Check Big Win */
    main_step_SavePoint_BeforeFullWeaponRandomMultiple,/**< Save Point Before Full Weapon Random Multiple */
    main_step_PrepareEnterToSpecialGame,/**< Prepare Enter To Special Game */
    main_step_EnterToSpecialGame,/**< Enter To Special Game */
    main_step_WaitForCheckBigWin,/**< Wait for check big win */
    main_step_fullweapon_random_mutiple,/**< Full weapon random multiple */
    main_step_fullweapon_decide_mutiple,/**< Full weapon decide multiple */
    main_step_fullweapon_after_decide_multiple,/**< Full weapon after decide multiple */
    main_step_fullweapon_end,/**< Full weapon end */

};

/**
 * @brief Main Game Sub Step Enumeration.
 *
 */
enum MAINGAMESUBSTEP{
	main_sub_step_Inactive = 0,/**< Inactive */
};

/**
 * @brief Double Game Step Enumeration.
 *
 */
enum DOUBLEGAMESTEP{
	dg_step_Inactive = 0,/**< Inactive */
	dg_step_SavePoint_BeforeStart,/**< Save Point Before Start */
    dg_step_StandBy,/**< Standby */
    dg_step_StartPrepare,/**< Prepare for starting slot */
    dg_step_GetAwardType,/**< Get award type */
    dg_step_SavePoint_BeforeCheckResult,/**< Save Point Before Check Result */
    dg_step_CheckResult,/**< Check result */
    dg_step_Winning,/**< Winning */
    dg_step_Losing,/**< Losing */
    dg_step_AddWinningScoreToCredits,/**< Add winning scores to credits */
    dg_step_WinningWaitPlayer,/**< Win game, wait for player's decision */
    dg_step_LosingWaitToEnd,/**< Lose game, wait for returning main game */
    dg_step_ReturnToMainGame,/**< Return to Main Game */

};

/**
 * @brief Double Game Sub Step Enumeration.
 *
 */
enum DOUBLEGAMESUBSTEP{
	dg_sub_step_Inactive = 0,/**< Inactive */
};

/**
 * @brief Special Game Step Enumeration.
 */
enum SPECIALGAMESTEP{
	sp_step_Inactive = 0,
	sp_step_SavePoint_BeforeStart,/**< Save Point Before Start */
	sp_step_StandBy,
	sp_step_Prepare,
	sp_step_moving_start,
	sp_step_moving_stop_slot,
	sp_step_moving_find_prepare_stop,
	sp_step_moving_find_next,
	sp_step_SavePoint_BeforeCheckResult,
	sp_step_check_result,
	sp_step_winning_anime,
	sp_step_wait_player_input,
	sp_step_after_player_input,
	sp_step_add_win_to_credit,
	sp_step_Return_to_standBy,
	sp_step_Return_to_mainGame,
};

/**
 * @brief Special Game Sub Step Enumeration.
 */
enum SPECIALGAMESUBSTEP{
	sp_sub_step_Inactive = 0,
};

/**
 * @brief Demo Step Enumeration.
 */
enum DEMOSTEP{
	demo_step_drawbg = 0,/**< step draw background */
	demo_step_nemo   = 1,/**< step draw nemo */
	demo_step_dora   = 2,/**< step draw dora */
	demo_step_logo   = 3,/**< step draw logo */
	demo_step_odds   = 4,/**< step draw odds */
	demo_step_del    = 5,/**< step delete */
};

/**
 * @brief Main Game Slot Draw Mode.
 */
enum MAINSLOTDRAWMODE{
	main_SlotDraw_Mode_Normal = 0,/**< Draw mode normal */
	main_SlotDraw_Mode_BingoAnime,/**< Draw mode animation */
	main_SlotDraw_Mode_AutoDelete,/**< Draw mode delete automatically */
};

/**
 * @brief Main Game Slot Animation Sequence.
 */
enum MAINGAMESLOTANIMATIONSEQUENCE{
	main_slot_anime_sequence_fullframe = 0,
	main_slot_anime_sequence_line_1,
	main_slot_anime_sequence_line_2,
	main_slot_anime_sequence_line_3,
	main_slot_anime_sequence_line_4,
	main_slot_anime_sequence_line_5,
	main_slot_anime_sequence_line_6,
	main_slot_anime_sequence_line_7,
	main_slot_anime_sequence_line_8,
	main_slot_anime_sequence_end,
	main_slot_anime_sequence_all_end,
};

/**
 * @brief Special Game Slot Draw Mode.
 */
enum SPECIALGAMESLOTDRAWMODE{
	sp_SlotDraw_Mode_Normal = 0,/**< Draw mode normal */
	sp_SlotDraw_Mode_BingoAnime,/**< Draw mode animation */
};

/**
 * @brief Double Game Slot Draw Mode.
 */
enum DOUBLESLOTDRAWMODE{
	dg_SlotDraw_Mode_Normal = 0,/**< Draw mode normal */
	dg_SlotDraw_Mode_BingoAnime,/**< Draw mode animation */
	dg_SlotDraw_Mode_AutoDelete,/**< Draw mode delete automatically */
};

/**
 * @brief Double Game Player Select Status Enumeration.
 */
enum DOUBLEGAMEPLAYERSELECT{
    dgame_player_not_selected      = 0,/**< not selected */
	dgame_player_selected_ushimaou = 1,/**< selected Ushimaou */
	//dgame_player_selected_sanzou   = 2,/**< selected Sanzon */
	dgame_player_selected_gokuu    = 2,/**< selected Goguu */
};

/**
 * @brief Double Game Award Type.
 */
enum DOUBLEGAMEAWARDTYPE{
	dgame_award_type_lose = 0,
	dgame_award_type_X2,
	dgame_award_type_X4,
	dgame_award_type_X6,
#if 0
	dgame_award_type_lose = 0,
	dgame_award_type_gokuu_x2,
	dgame_award_type_ushimaou_x2,
	dgame_award_type_sanzou_x6,
	dgame_award_type_gokuu_x4,
	dgame_award_type_ushimaou_x4,
#endif
};

/**
 * @brief Double Game Award History Type.
 */
enum DOUBLEGAMEAWARDHISTORYTYPE{
	dgame_award_history_type_lose = 0,
	dgame_award_history_type_gokuu_x2,
	dgame_award_history_type_ushimaou_x2,
	dgame_award_history_type_sanzou_x6,
	dgame_award_history_type_gokuu_x4,
	dgame_award_history_type_ushimaou_x4,

};

/**
 * @brief Double Game Open Type.
 */
enum DOUBLEGAMEOPENTYPE{
	dgame_open_type_unknow = 0,
	dgame_open_type_gokuu,
	dgame_open_type_ushimaou,
	dgame_open_type_sanzou,
	dgame_open_type_gokuu_x4,
	dgame_open_type_ushimaou_x4,
};

/**
 * @brief Double Game Result Type.
 */
enum DOUBLEGAMERESULTTYPE{
	dgame_result_type_unknow = 0,
	dgame_result_type_lose,
	dgame_result_type_win,
};

/**
 * @brief Idol Information Kind Enumeration.
 */
enum IDOLINFOKIND{
	idol_info_draw_kind_1 = 0,/**< draw kind 1 */
	idol_info_draw_kind_2,    /**< draw kind 2 */
};

/**
 * @brief Main Game Auto Play MODE Enumeration.
 */
enum AUTOPLAYMODE{
	auto_play_stop = 0,/**< Auto play stop */
	auto_play_start,   /**< Auto play start */
};

/**
 * @brief Auto Play Slot Stop Pattern.
 */
enum AUTOPLAYSLOTSTOPPATTERN{
	auto_play_slot_stop_normal = 0,
	auto_play_slot_stop_pattern_1,
	auto_play_slot_stop_pattern_2,
};

/**
 * @brief Double Game Result.
 */
enum DOUBLEGAMERESULT{
    dgame_result_not_play = 0,/**< Not Play yet */
	dgame_result_win,/**< Win */
    dgame_result_lose,/**< Lose */
};

/**
 * @brief Error Type.
 */
enum ERRORTYPE{
	err_type_system_over = 0,/**< System Over Max Win */
	err_type_ddown_over,/**< Double-Up Over Max Win */
	err_type_memory,/**< Memory Error */
	err_type_coin_in,/**< Coin-In Error */
	err_type_coin_out,/**< Coin-Out Error */
	err_type_coin_value,/**< Coin Value Error */
	err_type_id,/**< ID Error */
	err_type_network,/**< Network Disconnect */
};

/**
 * @brief Jackpot Bonus Draw Type.
 */
enum JACKPOTBONUSDRAWTYPE{
	jackpot_bonus_draw_type_normal = 0,/**< Draw all bonus */
    jackpot_bonus_draw_type_blink  = 1,/**< Only Draw bingo bonus blink */
};

/**
 * @brief Odds Running Status.
 */
enum ODDSRUNNINGSTATUS{
	odds_status_maingame_to_odds = 0,/**< maingame to odds */
	odds_status_odds_to_maingame,/**< odds to maingame */
};

/**
 * @brief JACKPOT Display Mode.
 */
enum JACKPOTDISPLAYMODE{
	jackpot_display_mode_random    = 0,/**< type random */
	jackpot_display_mode_designate = 1,/**< type designate by master */
};

/**
 * @brief Validate Status.
 */
enum VALIDATESTATUS{
	validate_status_unknow = 0,/**< Unknow */
	validate_status_in_validate_time,/**< In validate time */
	validate_status_out_validate_time,/**< Out validate time */
	validate_status_out_validate_do_lock_time,/**< Out validate do lock time */
	validate_status_now_time_less_than_previous_did/**< Now time less then previous did time */
};

/**
 * @brief MainGameRandomMultiple.
 */
enum MainGameRandomMultiple{
	random_multiple_none = 0,
	random_multiple_x1   = 1,
	random_multiple_x2   = 2,
	random_multiple_x3   = 3,
};
#endif /* GAMEENUM_H_ */
