/*
 * @file crc16.h
 */

#ifndef CRC16_H_
#define CRC16_H_

// Declare function prototype
void CRC16(unsigned char* Src, unsigned int dataCount, unsigned char* lowbyte, unsigned char* highbyte);
bool CheckCRC16(unsigned char* source, unsigned int dataCount, unsigned char* lowbyte, unsigned char* highbyte);

/**
 * @brief Do CRC16 compute.
 * @param Src Source address
 * @param dataCount byte count of data
 * @param lowbyte Output CRC16 low byte
 * @param highbyte Output CRC16 high byte
 */
void CRC16(unsigned char* Src, unsigned int dataCount, unsigned char* lowbyte, unsigned char* highbyte) {

	unsigned int  xda, xdapoly;
	//unsigned char i, j, xdabit;
	unsigned int i,j;
	unsigned char xdabit;

	if (dataCount < 1)//預防INDEX值為0,至少要有1 BYTE的資料
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

	*lowbyte  = (unsigned char) (xda & 0xFF);/* CRC16 Low  byte */
	*highbyte = (unsigned char) (xda >> 8);  /* CRC16 High byte*/
}

/**
 * @brief Check CRC16 code.
 * @param source Source address
 * @param dataCount byte count of data
 * @param lowbyte CRC16 low byte
 * @param highbyte CRC16 high byte
 */
bool CheckCRC16(unsigned char* source, unsigned int dataCount, unsigned char* lowbyte, unsigned char* highbyte){

	unsigned int  xda, xdapoly;
	//unsigned char i, j, xdabit;
	unsigned int i,j;
	unsigned char xdabit;

	if(source==(void*)0){//Null Pointer Return 0
		return false;
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

#ifdef _DEBUG
	printf("##CRC16 Compute : Low byte : %d, High byte : %d \n",(unsigned char) (xda & 0xFF),(unsigned char) (xda >> 8));
#endif

    return ( (*lowbyte) == (unsigned char) (xda & 0xFF)  &&  (*highbyte) == (unsigned char) (xda >> 8) ) ? \
    		true : false;
}


#endif /* CRC16_H_ */
