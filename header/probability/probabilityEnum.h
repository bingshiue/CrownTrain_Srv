/**
 * @file probabilityEnum.h
 * @brief Define probability Enumeration.
 *
 */

#ifndef PROBABILITYENUM_H_
#define PROBABILITYENUM_H_

#include "../preprocessor.h"

/**
 * @brief Probability Control Type of each Frame.
 */
enum ScrollProbability{
    Type_Slot1_Fixed    = 0,        /**< Slot 1 Fix Type */
    Type_Slot2_Fixed    = 1,        /**< Slot 2 Fix Type */
	Type_Slot3_Fixed    = 2,        /**< Slot 3 Fix Type */
	Type_Slot4_Fixed    = 3,        /**< Slot 4 Fix Type */
	Type_Slot5_Fixed    = 4,        /**< Slot 5 Fix Type */
	Type_Slot6_Fixed    = 5,        /**< Slot 6 Fix Type */
	Type_Slot7_Fixed    = 6,        /**< Slot 7 Fix Type */
	Type_Slot8_Fixed    = 7,        /**< Slot 8 Fix Type */
	Type_Slot9_Fixed    = 8,        /**< Slot 9 Fix Type */
	Type_Slot1_Mutable  = 9,        /**< Slot1 Mutable Type */
	Type_Slot5_Mutable  =10,        /**< Slot5 Mutable Type */
	Type_Slot7_Mutable  =11,        /**< Slot7 Mutable Type */
#ifdef TEST_MAIN_GAME_COMPUTE_SCORE
    Type_Test           =12         /**< For Test Main Game Compute Score */
#endif
};

/**
 * @brief Probability Control Status.
 */
enum ProbabilityControlStatus
{
	status_normal      = 0,    /**< Probability Control Status : Normal */
	status_check0_down,        /**< Probability Control Status : Check0 Down */
	status_check1_down,        /**< Probability Control Status : Check1 Down */
	status_check2_down,        /**< Probability Control Status : Check2 Down */
	status_check2_up,          /**< Probability Control Status : Check2 Up */
	status_connect,            /**< Probability Control Status : Connect Mode */
};


/**
 * @brief Speical Game Type.
 */
enum SpecialGameType{
	sp_type_normal_draw = 0,
	sp_type_supplementary,
};

/**
 * @brief Special Game Supplementary Open Flag.
 */
enum SpecialGameSupplementaryOpenFlag{
	sp_supplementary_flag_not_yet = 0,
	sp_supplementary_flag_open,
};

/**
 * @brief Full Frame Supplementary Open Flag.
 */
enum FullFrameSupplementaryOpenFlag
{
	supplementary_flag_not_yet = 0,
	supplementary_flag_open
};

/**
 * @brief Full Frame Supplementary Type.
 */
enum FullFrameSupplementaryType
{
	supplementary_type_none = 0,
	supplementary_type_small,/**< Supplementary Type Small */
	supplementary_type_big,/**< Supplementary Type Big */
};

/**
 * @brief Supplementary Open Type.
 */
enum FullFrameSupplementaryOpenType
{
	supplementary_open_type_none = 0,
	supplementary_open_type_one_time,/**< One Time */
	supplementary_open_type_consecutiveness,/**<  Consecutiveness */
};

/**
 * @brief Full Frame Supplementary Award Type.
 */
enum FullFrameSupplementaryAwardType
{
	supplementary_award_type_multiple_none = 0,
	supplementary_award_type_multiple_50,
	supplementary_award_type_multiple_100,
	supplementary_award_type_multiple_150,
	supplementary_award_type_multiple_250,
	supplementary_award_type_multiple_400,
	supplementary_award_type_multiple_800,
	supplementary_award_type_multiple_1000,
	supplementary_award_type_multiple_2500,
	supplementary_award_type_multiple_4000
};

/**
 * @brief Full Frame Supplementary Timing.
 */
enum FullFrameSupplementaryTiming
{
	supplementary_timing_none = 0,
	supplementary_timing_normal,
	supplementary_timing_ahead,
	supplementary_timing_delay
};

/**
 * @brief Hot Small Section.
 */
enum HotSmallSectionType{
	hot_small_section_type_none,
	hot_small_section_type_R1100,
	hot_small_section_type_full_frame_award_ahead,
};

/**
 * @brief game level.
 */
enum GameLevel{
	 Game_Level_Small    = 0,/**< game level small */
	 Game_Level_Middle   = 1,/**< game level middle */
	 Game_Level_Big      = 2 /**< game level big */
};

/**
 * @brief Double Game Probability Status.
 */
enum DoubleGameProbabilityStatus{
	DoubleGameProbabilityStatus_Down_level3 = 0,
	DoubleGameProbabilityStatus_Down_level2,
    DoubleGameProbabilityStatus_Down_level1,
    DoubleGameProbabilityStatus_Normal,
    DoubleGameProbabilityStatus_Up_level1,
    DoubleGameProbabilityStatus_Up_level2,
    DoubleGameProbabilityStatus_Up_level3
};


/**
 * @brief Special Game Draw Type Enumeration.
 */
enum SpecialGameDrawType{
	sp_draw_type_none = 0,
	sp_draw_type_draw,
	sp_draw_type_no_win,
	sp_draw_type_exit,
};

/**
 * @brief Special Game Light Award Type Enumeration.
 */
enum SpecialGameLightAwardType{
	sp_light_award_type_exit = 0,
	sp_light_award_type_none,
	sp_light_award_type_weapon_3,
	sp_light_award_type_weapon_2,
	sp_light_award_type_book,
	sp_light_award_type_weapon_4,
	sp_light_award_type_weapon_1,
	sp_light_award_type_character_3,
	sp_light_award_type_character_2,
	sp_light_award_type_character_1,
	sp_light_award_type_saiyuuki,
};

/**
 * @brief Special Game Slot Award Type Enumeration.
 */
enum SpecialGameSlotAwardType{
	sp_slot_award_type_none = 0,
	sp_slot_award_type_x20,
	sp_slot_award_type_x500,
};

/**
 * @brief Special Game Light Award Result Enumeration.
 */
enum SpecialGameLightAwardResult{
	sp_light_award_result_exit = 0,
	sp_light_award_result_none,
	sp_light_award_result_weapon_3,
	sp_light_award_result_weapon_2,
	sp_light_award_result_book,
	sp_light_award_result_weapon_4,
	sp_light_award_result_weapon_1,
	sp_light_award_result_character_3,
	sp_light_award_result_character_2,
	sp_light_award_result_character_1,
	sp_light_award_result_saiyuuki,
};

/**
 * @brief Special Game Slot Award Result Enumeration.
 */
enum SpecialGameSlotAwardResult{
	sp_slot_award_result_none = 0,
	sp_slot_award_result_x20,
	sp_slot_award_result_x500,
};


#endif /* PROBABILITYENUM_H_ */
