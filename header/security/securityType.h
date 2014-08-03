/**
 * @file securityType.h
 *
 */

#ifndef SECURITYTYPE_H_
#define SECURITYTYPE_H_

typedef struct {
	unsigned char Key[128];
	unsigned long PBox[18], SBox[4][256], DLeft, DRight;
}BFInfo;

//static BFInfo bfInfo;

typedef struct SetEDInfo{
	unsigned char Code[20];
	unsigned long CV, GP, BP, Vari, Pres, UB, LB, JP, Cmp1,Cmp2;
}SETInfo;

//static SETInfo* setInfo = NULL;

#endif /* SECURITYTYPE_H_ */
