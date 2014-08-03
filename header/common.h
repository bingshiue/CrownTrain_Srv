/**
 * @file common.h
 *
 */

#ifndef COMMON_H_
#define COMMON_H_

#if 0
/**
 * @brief RTC Time Structure.
 *
 */
typedef struct{
	unsigned char _year;/**< Year */
	unsigned char _month;/**< Month */
	unsigned char _day;/**< Day */
	unsigned char _hour;/**< Hour */
	unsigned char _minute;/**< Minute */
	unsigned char _second;/**< Second */

	/**
	 * @brief Reset all member parameters.
	 */
	void reset(){
		this->_year    = 0;
		this->_month   = 0;
		this->_day     = 0;
		this->_hour    = 0;
		this->_minute  = 0;
	    this->_second  = 0;
	}

}RTCTIME;
#endif


#endif /* COMMON_H_ */
