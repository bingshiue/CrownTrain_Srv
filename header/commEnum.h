/*
 * @file commEnum.h
 * @brief Common Enumeration Define
 */

#ifndef COMMENUM_H_
#define COMMENUM_H_

/**
 * @brief Game Level Enumeration.
 */
enum GAME_LEVEL{
	game_level_big = 0,/**< Big */
	game_level_middle,/**< Middle */
	game_level_small,/**< Small */
};

/**
 * @brief Game lot Status Enumeration.
 */
enum GAME_LOTSTAT{
	game_lot_normal = 0,/**< normal */
	game_lot_pull_down,/**< pull down */
	game_lot_pull_up,/**< pull up */
};

#endif /* COMMENUM_H_ */
