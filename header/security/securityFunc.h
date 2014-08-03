/**
 * @file securityFunc.h
 *
 */

#ifndef SECURITYFUNC_H_
#define SECURITYFUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include "securityType.h"
#include "securityData.h"

#define KeyLength  16/**< 模擬置於ROM之定值 */

//Prototype Declare
void InitBFInfo(BFInfo* Tmp);
void EncryptData(BFInfo* Tmp);
void DecryptData(BFInfo* Tmp);
unsigned long FBlock(BFInfo* Tmp);
void MemAllocSETInfo(void);
void MemFreeSETInfo(void);
void DisorderData(unsigned char* Code);
void ServerEncrypt(unsigned long TotalIn, unsigned long TotalOut, unsigned long PlayTimes, unsigned long MID, unsigned long SID, unsigned long CoinValue, unsigned long GameProb, unsigned long BonusProb, unsigned long Variation, unsigned long Present, unsigned long UpperBet, unsigned long LowerBet,unsigned long JackPot);
void MachDecrypt(unsigned char* EnCode);
bool CompareData(unsigned long TotalIn, unsigned long TotalOut, unsigned long PlayTimes, unsigned long MID, unsigned long SID);
unsigned char* GetCipherCode(void);
unsigned long GetCVSetting(void);
unsigned long GetGPSetting(void);
unsigned long GetBPSetting(void);
unsigned long GetVariSetting(void);
unsigned long GetPresSetting(void);
unsigned long GetUBSetting(void);
unsigned long GetLBSetting(void);
unsigned long GetJPSetting(void);


#endif /* SECURITYFUNC_H_ */
