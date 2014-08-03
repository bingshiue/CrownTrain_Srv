/*
 * @file Utility.cpp
 * @brief some utility subfunction.
 *
 */
#include "../header/tasksystem/Task.h"
#include "../header/crc16.h"
#include "../header/security/securityFunc.h"

/**
 * @brief Unsigned integer to byte.
 *
 * @param value unsigned integer value
 * @param dest destination starting address
 */
void Utility::UnsignedIntegerToByte(unsigned int value,unsigned char *dest){
    //int offset[4] = {24,16,8,0};
	int offset[4] = {0,8,16,24};

    if(dest == NULL){
    	printf("## Address invalid ! ## \n");
    	return;
    }

	for(unsigned char i = 0; i < 4; i++){
    	 *(dest+i) = (unsigned char)(value >> offset[i]);
    }
}

/**
 * @brief Get unsigned integer from byte.
 *
 * @param b1 byte 1
 * @param b2 byte 2
 * @param b3 byte 3
 * @param b4 byte 4
 * @retval unsigned integer value
 */
unsigned int Utility::getUnsignedIntegerFromByte(unsigned char b1,unsigned char b2,unsigned char b3,unsigned char b4){
	//return (unsigned int)((b1 << 24) | (b2 << 16) | (b3 << 8) | (b4) );
	return (unsigned int)((b4 << 24) | (b3 << 16) | (b2 << 8) | (b1) );
}

/**
 * @brief Get unsigned integer from address.
 *
 * @param addr address
 * @retval unsigned integer value
 */
unsigned int Utility::getUnsignedIntegerFromAddr(unsigned char *addr){
	//return (unsigned int)((*addr << 24) | ((*(addr+1)) << 16) | ((*(addr+2)) << 8) | (*(addr+3)) );
	return (unsigned int)((*(addr+3) << 24) | ((*(addr+2)) << 16) | ((*(addr+1)) << 8) | (*(addr+0)) );
}

int Utility::getRTCTime(RTCTIME* _rtcTime){

	int rtc_fd;/**< File Descriptor of RTC device */
	int ioctl_ret;/**< ioctl() return value */
	struct rtc_time rtcTime;/**< RTC Time Structure */

	/* Open RTC Device */
	rtc_fd = open("/dev/rtc", O_RDWR);/**< Open RTC device "/dev/rtc" */
	if(rtc_fd < 0){/**< Check rtc_fd */
		printf("###ERROR:Open RTC Device Failed \n");
		close(rtc_fd);/**< Close RTC Device */
		return rtc_fd;
	}

	/* Load Time From RTC Hardware */
	ioctl_ret = ioctl(rtc_fd,RTC_RD_TIME,&rtcTime);/**< Get Time From RTC Hardware */
	if(ioctl_ret < 0){/**< Check ioctl() return value */
		printf("###ERROR:ioctl() \n");
		close(rtc_fd);/**< Close RTC Device */
		return ioctl_ret;
	}

	close(rtc_fd);/**< Close RTC Device */

	/* Save time to _rtcTime */
    _rtcTime->_year    = rtcTime.tm_year;/**< Year */
    _rtcTime->_month   = rtcTime.tm_mon; /**< Month */
    _rtcTime->_day     = rtcTime.tm_mday;/**< Day */
    _rtcTime->_hour    = rtcTime.tm_hour;/**< Hour */
    _rtcTime->_minute  = rtcTime.tm_min; /**< Minute */
    _rtcTime->_second  = rtcTime.tm_sec; /**< Second */

	return EXIT_SUCCESS;
}

bool Utility::CheckCodeCorrect(unsigned char* code,unsigned long totalIn,unsigned long totalOut,unsigned long totalPlayTimes,unsigned long randomCode,unsigned long machineID,unsigned long* settingValueArray){
	bool result = false;

	MemAllocSETInfo();

	MachDecrypt(code);
	result = CompareData(totalIn,totalOut,totalPlayTimes,randomCode,machineID);

	if(result==true){
		settingValueArray[0] = GetCVSetting();
		settingValueArray[1] = GetGPSetting();
		settingValueArray[2] = GetBPSetting();
		settingValueArray[3] = GetVariSetting();
		settingValueArray[4] = GetPresSetting();
		settingValueArray[5] = GetUBSetting();
		settingValueArray[6] = GetLBSetting();
		settingValueArray[7] = GetJPSetting();
	}

	MemFreeSETInfo();

	return result;
}

int Utility::setRTCTime(RTCTIME* _rtcTime){

	int rtc_fd;/**< File Descriptor of RTC device */
	int ioctl_ret;/**< ioctl() return value */
	struct rtc_time rtcTime;/**< RTC Time Structure */

	/* Open RTC Device */
	rtc_fd = open("/dev/rtc", O_RDWR);/**< Open RTC device "/dev/rtc" */
	if(rtc_fd < 0){/**< Check rtc_fd */
		printf("###ERROR:Open RTC Device Failed \n");
		close(rtc_fd);/**< Close RTC Device */
		return rtc_fd;
	}

	/* Save _rtcTime to rtcTime */
	rtcTime.tm_year = _rtcTime->_year;  /**< Year */
	rtcTime.tm_mon  = _rtcTime->_month; /**< Month */
	rtcTime.tm_mday = _rtcTime->_day;   /**< Day */
	rtcTime.tm_hour = _rtcTime->_hour;  /**< Hour */
	rtcTime.tm_min  = _rtcTime->_minute;/**< Minute */
	rtcTime.tm_sec  = _rtcTime->_second;/**< Second */

	/* Set Time to RTC Hardware */
	ioctl_ret = ioctl(rtc_fd,RTC_SET_TIME,&rtcTime);/**< Set Time to RTC Hardware */
	if(ioctl_ret < 0){/**< Check ioctl() return value */
		printf("###ERROR:ioctl() \n");
		close(rtc_fd);/**< Close RTC Device */
		return ioctl_ret;
	}

	close(rtc_fd);/**< Close RTC Device */

	return EXIT_SUCCESS;
}

void Utility::getValidateRemainTime(time_t now_time,time_t validate_time,unsigned int* day,unsigned int* hour,unsigned int* minute){
	unsigned int remain_day    = 0;
	unsigned int remain_hour   = 0;
	unsigned int remain_minute = 0;

	if(now_time >= validate_time){
		*day    = remain_day;
		*hour   = remain_hour;
		*minute = remain_minute;
		return;
	}else{
		time_t delta = validate_time - now_time;

#ifdef _DEBUG
		printf("Delta is : %ld \n", delta);
#endif

		for(unsigned idx=0;;idx++){
			if(delta >= 86400){
				delta -= 86400;
				remain_day++;
			}else{
				break;
			}
		}

#ifdef _DEBUG
		printf("Delta is : %ld,Remain Day is : %d \n", delta,remain_day);
#endif

		for(unsigned idx=0;;idx++){
			if(delta >= 3600){
				delta -= 3600;
				remain_hour++;
			}else{
				break;
			}
		}

#ifdef _DEBUG
		printf("Delta is : %ld,Remain Hour is : %d \n", delta,remain_hour);
#endif

		for(unsigned idx=0;;idx++){
			if(delta >= 60){
				delta -= 60;
				remain_minute++;
			}else{
				break;
			}
		}

#ifdef _DEBUG
		printf("Delta is : %ld,Remain Minute is : %d \n", delta,remain_minute);
#endif

		*day    = remain_day;
		*hour   = remain_hour;
		*minute = remain_minute;
		return;

	}

}

int Utility::getValidateStatus(void){

#if 0
	SettingDataController* sdctrl = (SettingDataController*)TaskEx::GetTask(tid_SettingDataController,0);
	unsigned int status = validate_status_unknow;

	if(sdctrl==NULL) return -1;

	time_t now_time = time(NULL);

	//
    if(now_time < sdctrl->getGameAllSettingData()->systemSettingData._validate_previous_did_report_time ){
    	status = validate_status_now_time_less_than_previous_did;
    	return status;
    }

    //
	if(now_time <= sdctrl->getGameAllSettingData()->systemSettingData._validate_time){
		status = validate_status_in_validate_time;
	}
	else if(now_time > sdctrl->getGameAllSettingData()->systemSettingData._validate_time &&
			now_time <= sdctrl->getGameAllSettingData()->systemSettingData._validate_do_lock_time){
		status = validate_status_out_validate_time;
	}
	else if(now_time > sdctrl->getGameAllSettingData()->systemSettingData._validate_do_lock_time){
		status = validate_status_out_validate_do_lock_time;
	}

	return status;
#endif
}

int Utility::UARTSend(unsigned char group,unsigned char command,unsigned char action,unsigned char dataLength,unsigned char* data,size_t size){

    int sendbytes = 0;
	SERIALSENDDATA tmp;

	if(size > 16){
		return -1;
	}

	tmp.ResetBufferData();

	tmp.t_buffer[UART_IDX_GROUP]        = group;
	tmp.t_buffer[UART_IDX_COMMAND]      = command;
	tmp.t_buffer[UART_IDX_ACTION]       = action;
	tmp.t_buffer[UART_IDX_DATA_LENGTH]  = dataLength;
	for(unsigned int i=0; i<dataLength; i++){
		tmp.t_buffer[UART_IDX_DATA_BEGIN+i] = data[i];
	}

	sendbytes = SerialSendData(&tmp);//Send_Serial_Data(&tmp);


	return sendbytes;
}

