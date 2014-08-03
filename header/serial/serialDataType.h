/**
 * @file serialDataType.h
 *
 */

#ifndef SERIALDATATYPE_H_
#define SERIALDATATYPE_H_

/**
 *@brief Structure of Receive Data.
 */
typedef struct SERIALRECVDATA{
	unsigned char r_buffer[256];/**< receive buffer */
	/**
	 *@brief   計算收到的CRC檢查碼是否符合
	 *@retval  0： 不符合 1 : 符合
	 */
	unsigned char isCRCOK(unsigned char* source){
		return this->CheckCRC16(source, 22);
	}
	/**
	 *@brief   檢查CRC16檢查碼是否正確
	 *
	 *@param   source  欲檢查的資料陣列
	 *@param   dataCount 傳輸位元組組數(不包含CRC16檢查碼的兩個BYTE)
	 *@return  CRC16檢查碼是否相符
	 *@retval  0： 不符合 1 : 符合
	 */
	unsigned char CheckCRC16(unsigned char* source,unsigned char dataCount){

		unsigned int xda, xdapoly;
		unsigned char i, j, xdabit;

		if (source == (void*) 0) { //Null Pointer Return 0
			return 0;
		}

		//計算CRC16檢查碼
		xda = 0xFFFF;
		xdapoly = 0xA001;
		for (i = 0; i < dataCount; i++) {
			xda ^= *(source + i);
			for (j = 0; j < 8; j++) {
				xdabit = (unsigned char) (xda & 0x01);
				xda >>= 1;
				if (xdabit)
					xda ^= xdapoly;
			}
		}
		return (*(source + dataCount) == (unsigned char) (xda & 0xFF) && *(source + dataCount + 1) == (unsigned char) (xda >> 8)) ? 1 : 0;
	}
}SERIALRECVDATA;

/**
 *@brief  structure of send data.
 */
typedef struct SERIALSENDDATA{
  unsigned char t_buffer[256];/**< transmission buffer */
	/**
	 *@brief   計算欲傳送資料的CRC16檢查碼,採用多項式(X**16 + X**15 + X**2 + 1)生成CRC16檢查碼
	 *
	 *@param   Src 資料陣列的開頭位址
	 *@param   dataCount 欲傳送的位元組組數(不包含CRC16檢查碼的兩個BYTE)
	 */
	void CRC16(unsigned char* Src, unsigned char dataCount){

		unsigned int xda, xdapoly;
		unsigned char i, j, xdabit;

		if (dataCount < 1) //預防INDEX值為0,至少要有1 BYTE的資料
			return;

		//計算CRC16檢查碼
		xda = 0xFFFF;
		xdapoly = 0xA001;
		for (i = 0; i < dataCount; i++) {
			xda ^= *(Src + i);
			for (j = 0; j < 8; j++) {
				xdabit = (unsigned char) (xda & 0x01);
				xda >>= 1;
				if (xdabit)
					xda ^= xdapoly;
			}
		}

		*(Src + dataCount) = (unsigned char) (xda & 0xFF);
		*(Src + dataCount + 1) = (unsigned char) (xda >> 8);
	}
	/**
	 *@brief   Reset Buffer Data.
	 */
	void ResetBufferData(void){
		for (unsigned int i = 0; i < sizeof(this->t_buffer) / sizeof(this->t_buffer[0]); i++) {
			this->t_buffer[i] = 0x00;
		}
	}
}SERIALSENDDATA;

#endif /* SERIALDATATYPE_H_ */
