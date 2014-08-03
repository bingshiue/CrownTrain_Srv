/**
 * @file gameSettingValue.h
 * @brief Declare game setting value table.
 *
 */

#ifndef GAMESETTINGVALUE_H_
#define GAMESETTINGVALUE_H_

#include "../preprocessor.h"
#include "gameEnum.h"

#define word unsigned int/**< define word as unsigned int */
#define byte unsigned char/**< define byte as unsigned char */

/************************ System Setting ***************************/
/**
 * Key In.(上分值)
 */
const word creditin_tab[10] = { Disable, 100, 200, 500, 1000, 2000, 5000, 10000, 50000, 100000 };
/**
 * Key Out.(下分值)
 */
const word creditout_tab[7] = { 1, 10, 100, 200, 500, 1000, 2000 };
/**
 * Single line maximum bet.(單線最大押分)
 */
const word single_line_maxbet_tab[6] = { 5, 10, 20, 30, 40, 50 };
/**
 * Single line minimum bet.(單線最小押分)
 */
const word single_line_minbet_tab[5] = { 1, 2, 5, 10, 20 };
/**
 * Credit In Limit.(系統爆機分數)
 */
const word creditinlimit_tab[13] = { 50000, 100000, 200000, 300000, 400000, 500000,
600000, 800000, 1000000, 1200000, 1600000, 2000000, 0 };
/**
 * Enter to double down directly.(直接比倍)
 */
const word directdd_tab[2] = { Disable, Enable };
/**
 * Double up game credit limit.(比倍爆機分數)
 */
const word ddcreditlimit_tab[6] = { 50000, 100000, 150000, 200000, 250000, 500000 };
/**
 * Double up game on/off (比倍遊戲開關).
 */
const byte ddonoff_tab[2] = { Disable, Enable };
/*
 * Single Line Bet Unit.(單線押注進分值)
 */
const word single_line_bet_unit_tab[5] = { 1, 2, 3, 5, 10 };
/*
 * Pay Setting.(退分設定)
 */
const byte pay_setting_tab[2] ={ Pay_setting_hopper, Pay_setting_ticket };
/**
 * Hopper Setting.(退幣器設定)
 */
const byte hopper_setting_tab[2]= { Hopper_NO,Hopper_NC };
/**
 * Sound Volume.(音量設定)
 */
const byte sound_volume_tab[11]         = { 0, 1,  2,  3,  4,  5,  6,  7,  8,   9,  10 };
const byte sound_volume_mapping_tab[11] = { 0, 8, 16, 32, 40, 64, 72, 80, 96, 112, 128 };
/**
 * Max Key In.(最大上分設定)
 */
const word max_keyin_tab[11] = { 10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,Unlimited};

/*******************************************************************/
const word creditinlimit_single_line_max_bet_05_tab[4] = {  0,  1,  2,  12 };
const word creditinlimit_single_line_max_bet_10_tab[4] = {  1,  2,  4,  12 };
const word creditinlimit_single_line_max_bet_20_tab[4] = {  2,  4,  7,  12 };
const word creditinlimit_single_line_max_bet_30_tab[4] = {  3,  6,  9,  12 };
const word creditinlimit_single_line_max_bet_40_tab[4] = {  4,  7, 10,  12 };
const word creditinlimit_single_line_max_bet_50_tab[4] = {  5,  8, 11,  12 };

const word single_line_minbet_single_line_max_bet_05_tab[3] = {  0, 1, 2 };
const word single_line_minbet_single_line_max_bet_10_tab[4] = {  0, 1, 2, 3 };
const word single_line_minbet_single_line_max_bet_20_tab[5] = {  0, 1, 2, 3, 4 };
const word single_line_minbet_single_line_max_bet_30_tab[5] = {  0, 1, 2, 3, 4 };
const word single_line_minbet_single_line_max_bet_40_tab[5] = {  0, 1, 2, 3, 4 };
const word single_line_minbet_single_line_max_bet_50_tab[5] = {  0, 1, 2, 3, 4 };

//const word single_line_bet_unit_single_line_max_bet_05_tab[2] = {  0, 1 };
const word single_line_bet_unit_single_line_max_bet_05_tab[1] = {  0 };
const word single_line_bet_unit_single_line_max_bet_10_tab[3] = {  0, 1, 3 };
const word single_line_bet_unit_single_line_max_bet_20_tab[3] = {  1, 3, 4 };
const word single_line_bet_unit_single_line_max_bet_30_tab[3] = {  2, 3, 4 };
const word single_line_bet_unit_single_line_max_bet_40_tab[2] = {  3, 4 };
const word single_line_bet_unit_single_line_max_bet_50_tab[2] = {  3, 4 };

/********************** Probability Setting ************************/
/**
 * Coin value.(投退幣幣值)
 */
const word coin_value_tab[12] = { 0, 1, 2, 5, 10, 20, 25, 50, 100, 200, 500, 1000 };
/**
 * Ticket value.(彩票票值)
 */
const word ticket_value_tab[15] = {0, 1, 2, 5, 10, 20, 25, 50, 100, 200, 500, 1000, 2000, 5000, 100000};
/**
 * Main game probability (主遊戲機率設定值).
 */
const float gamepro_tab[9] = { 96, 96.5, 97, 97.5, 98, 98.5, 99, 99.5, 100 };
/**
 * Double game probability (比倍遊戲機率設定值).
 */
const float ddpro_tab[5] = { 96, 97, 98, 99, 100 };
/**
 * Game level.(遊戲起伏)
 */
const byte gamelevel_tab[3] = { Game_Level_Small, Game_Level_Middle, Game_Level_Big };
/**
 * Minus Digit.(縮位)
 */
const byte minus_digit_tab[3] = { 1, 10, 100 };
/**
 * Lock Time Adjust Table(鎖機時間)
 */
const word lock_time_tab[5] = { 7, 14, 21, 28, 35 };


/************************ Connect Setting **************************/
/**
 * Connect on/off (連線設定).
 */
const byte connect_onoff_tab[2] = { Connect_OFF, Connect_ON };
/**
 * Connect ID (連線ID).
 */
const byte connect_id_tab[20] = {  1, 2, 3, 4, 5, 6, 7, 8, 9,10,
                                   11,12,13,14,15,16,17,18,19,20 };
/**
 * Max link count (最大連線台數).
 */
const byte max_id_tab[1] = { 10 };

/************************** Time Setting ***************************/
/**
 * hour (時).
 */
const byte hour_tab[24] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
		15, 16, 17, 18, 19, 20, 21, 22, 23 };
/**
 * minute (分).
 */
const byte minutes_tab[60] = {  0,  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
		14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
		32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
		50, 51, 52, 53, 54, 55, 56, 57, 58, 59 };
/**
 * week (星期).
 */
const byte week_tab[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
/**
 * date (日).
 */
const byte date_tab[31] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
		15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };
/**
 * month (月).
 */
const byte month_tab[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
/**
 * year (年).
 */
const word year_tab[90] = {
		2010,2011,2012,2013,2014,2015,2016,2017,2018,2019,
		2020,2021,2022,2023,2024,2025,2026,2027,2028,2029,
		2030,2031,2032,2033,2034,2035,2036,2037,2038,2039,
		2040,2041,2042,2043,2044,2045,2046,2047,2048,2049,
		2050,2051,2052,2053,2054,2055,2056,2057,2058,2059,
		2060,2061,2062,2063,2064,2065,2066,2067,2068,2069,
		2070,2071,2072,2073,2074,2075,2076,2077,2078,2079,
		2080,2081,2082,2083,2084,2085,2086,2087,2088,2089,
		2090,2091,2092,2093,2094,2095,2096,2097,2098,2099
};

#endif /* GAMESETTINGVALUE_H_ */
