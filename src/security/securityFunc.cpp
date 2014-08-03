/**
 * @file securityFunc.cpp
 *
 */
#include "../../header/security/securityFunc.h"

static BFInfo bfInfo;
static SETInfo* setInfo = NULL;

//----------------加解密演算法函式----------------//
// 初始BFInfo內容
void InitBFInfo(BFInfo* Tmp){

	unsigned int i, j, idx = 0;

	for(i=0;i<KeyLength;i++){ Tmp->Key[i] = EnKey[i]; }
	for(i=0;i<18;i++){ Tmp->PBox[i] = pbox[i]; }
	for(i=0;i<4;i++){ for(j=0;j<256;j++){ Tmp->SBox[i][j] = sbox[i][j]; } }

	for(i=0;i<18;i++){
		Tmp->DLeft = 0x00000000;
		for(j=0;j<4;j++){
			Tmp->DLeft = ((Tmp->DLeft)<<8)|(Tmp->Key[idx]);
			idx++;
			if (idx>=KeyLength){ idx = 0; }
		}
		Tmp->PBox[i] ^= Tmp->DLeft;
	}
	Tmp->DLeft = 0x00; Tmp->DRight = 0x00;
	// 變換P-Box值(以DLeft，DRight為0x00值變換)
	for(i=0;i<(18/2);i++){
		EncryptData(Tmp);
		Tmp->PBox[i*2] = Tmp->DLeft;
		Tmp->PBox[(i*2)+1] = Tmp->DRight;
	}
	// 變換S-Box值(以P-Box末值變換)
	for(i=0;i<4;i++){
		for(j=0;j<(256/2);j++){
			EncryptData(Tmp);
			Tmp->SBox[i][j*2] = Tmp->DLeft;
			Tmp->SBox[i][(j*2)+1] = Tmp->DRight;
		}
	}
	Tmp->DLeft = 0x00; Tmp->DRight = 0x00;
}
//
// 加密
void EncryptData(BFInfo* Tmp){

	int i;
	unsigned long temp;
	for(i=0;i<16;i++){
		Tmp->DLeft ^= Tmp->PBox[i];
		Tmp->DRight ^= FBlock(Tmp);
		temp = Tmp->DLeft;
		Tmp->DLeft = Tmp->DRight;
		Tmp->DRight = temp;
	}
	// 交換並異或最後一組PBox值
	temp = Tmp->DLeft;
	Tmp->DLeft = (Tmp->DRight)^(Tmp->PBox[17]);
	Tmp->DRight = temp^(Tmp->PBox[16]);
}
//
// 解密
void DecryptData(BFInfo* Tmp){

	int i;
	unsigned long temp;
	for(i=17;i>1;i--){
		Tmp->DLeft ^= Tmp->PBox[i];
		Tmp->DRight ^= FBlock(Tmp);
		temp = Tmp->DLeft;
		Tmp->DLeft = Tmp->DRight;
		Tmp->DRight = temp;
	}
	// 交換並異或最後一組PBox值
	temp = Tmp->DLeft;
	Tmp->DLeft = (Tmp->DRight)^Tmp->PBox[0];
	Tmp->DRight = temp^(Tmp->PBox[1]);
}
//
// 資料轉換(相與和異或)
unsigned long FBlock(BFInfo* Tmp){

	int i;
	unsigned long bits[4];
	for(i=0;i<4;i++){ bits[i] = (((Tmp->DLeft)>>((3-i)*8))&0xff); }
	return ((Tmp->SBox[0][bits[0]]+Tmp->SBox[1][bits[1]])^Tmp->SBox[2][bits[2]])+Tmp->SBox[3][bits[3]];
}
//--------------------介面函式--------------------//
// 申請資源(SettingInfo)
void MemAllocSETInfo(void){ setInfo = (SETInfo*) malloc(sizeof(SETInfo)); }
//
// 釋放資源(SettingInfo)
void MemFreeSETInfo(void){ free(setInfo); setInfo = NULL; }
//
// 位移
void DisorderData(unsigned char* Code){
	unsigned char tmp;
	tmp = Code[0]; Code[0] = Code[9]; Code[9] = tmp;
	tmp = Code[2]; Code[2] = Code[7]; Code[7] = tmp;
	tmp = Code[4]; Code[4] = Code[5]; Code[5] = tmp;
	tmp = Code[10]; Code[10] = Code[19]; Code[19] = tmp;
	tmp = Code[12]; Code[12] = Code[17]; Code[17] = tmp;
	tmp = Code[14]; Code[14] = Code[15]; Code[15] = tmp;
}
//
// 伺服端加密
// 讀入資料：總入、總出、遊戲次數、板號、編號資料、投幣值、主機率、比倍機率、遊戲起伏、外贈、最大押分、最小押分、彩金累積率
// 傳回代碼：控制碼、比對碼
void ServerEncrypt(unsigned long TotalIn, unsigned long TotalOut, unsigned long PlayTimes, unsigned long MID, unsigned long SID,
				   unsigned long CoinValue, unsigned long GameProb, unsigned long BonusProb, unsigned long Variation,
				   unsigned long Present, unsigned long UpperBet, unsigned long LowerBet,unsigned long JackPot			){

	int i=0;
	InitBFInfo(&bfInfo);
	// 組合20位資料
	bfInfo.DLeft = ((((((CoinValue*10+Variation)*10+GameProb)*10+BonusProb)*10+Present)*10+UpperBet)*10+LowerBet)*10+JackPot;
	bfInfo.DRight = sbox[TotalIn%4][TotalIn%251]^sbox[TotalOut%4][TotalOut%252]^sbox[PlayTimes%4][PlayTimes%253]^sbox[MID%4][MID%254]^sbox[SID%4][SID%255];
	EncryptData(&bfInfo);

	// 轉ASCII碼
	for(i=9;i>=0;i--){
		setInfo->Code[i] = bfInfo.DLeft%10+48;		bfInfo.DLeft = (bfInfo.DLeft-(bfInfo.DLeft%10))/10;
		setInfo->Code[i+10] = bfInfo.DRight%10+48;	bfInfo.DRight = (bfInfo.DRight-(bfInfo.DRight%10))/10;
	}
	DisorderData(setInfo->Code);
}
//
// 客戶端解密
// 讀入代碼：控制碼、比對碼
// 傳回資料：(總入、總出、遊戲次數、板號、編號資料)、)投幣值、主機率、比倍機率、遊戲起伏、外贈、最大押分、最小押分、彩金累積率_
void MachDecrypt(unsigned char* EnCode){

	int i=0;

	InitBFInfo(&bfInfo);

	/**/
	DisorderData(EnCode);

	// 轉數字
	bfInfo.DLeft = 0; bfInfo.DRight = 0;
	for(i=0;i<10;i++){
		bfInfo.DLeft	*= 10;
		bfInfo.DRight	*= 10;
		bfInfo.DLeft	+= (EnCode[i]-48);
		bfInfo.DRight	+= (EnCode[i+10]-48);
	}

	DecryptData(&bfInfo);

	//setInfo->Cmp1	= bfInfo.DLeft%10;		bfInfo.DLeft	= ((bfInfo.DLeft-(bfInfo.DLeft%10))/10);
	setInfo->JP		= bfInfo.DLeft%10;		bfInfo.DLeft	= ((bfInfo.DLeft-(bfInfo.DLeft%10))/10);
	setInfo->LB		= bfInfo.DLeft%10;		bfInfo.DLeft	= ((bfInfo.DLeft-(bfInfo.DLeft%10))/10);
	setInfo->UB		= bfInfo.DLeft%10;		bfInfo.DLeft	= ((bfInfo.DLeft-(bfInfo.DLeft%10))/10);
	setInfo->Pres	= bfInfo.DLeft%10;		bfInfo.DLeft	= ((bfInfo.DLeft-(bfInfo.DLeft%10))/10);
	setInfo->BP		= bfInfo.DLeft%10;		bfInfo.DLeft	= ((bfInfo.DLeft-(bfInfo.DLeft%10))/10);
	setInfo->GP		= bfInfo.DLeft%10;		bfInfo.DLeft	= ((bfInfo.DLeft-(bfInfo.DLeft%10))/10);
	setInfo->Vari	= bfInfo.DLeft%10;		bfInfo.DLeft	= ((bfInfo.DLeft-(bfInfo.DLeft%10))/10);
	setInfo->CV		= bfInfo.DLeft%10;		bfInfo.DLeft	= ((bfInfo.DLeft-(bfInfo.DLeft%10))/10);
	setInfo->Cmp2	= bfInfo.DRight;

}
//
// 比對資料
bool CompareData(unsigned long TotalIn, unsigned long TotalOut, unsigned long PlayTimes, unsigned long MID, unsigned long SID){

	unsigned long tmp = sbox[TotalIn%4][TotalIn%251]^sbox[TotalOut%4][TotalOut%252]^sbox[PlayTimes%4][PlayTimes%253]^sbox[MID%4][MID%254]^sbox[SID%4][SID%255];

	printf("Cmp2=%lu \n",setInfo->Cmp2);

	return (setInfo->Cmp2==tmp);
}
//
// 取得密文
unsigned char* GetCipherCode(void){ return setInfo->Code; }
//
// 取得幣值設定碼
unsigned long GetCVSetting(void){ return setInfo->CV; }
//
// 取得主遊戲機率碼
unsigned long GetGPSetting(void){ return setInfo->GP; }
//
// 取得比倍遊戲機率碼
unsigned long GetBPSetting(void){ return setInfo->BP; }
//
// 取得遊戲起伏設定碼
unsigned long GetVariSetting(void){ return setInfo->Vari; }
//
// 取得外贈設定碼
unsigned long GetPresSetting(void){ return setInfo->Pres; }
//
// 取得最大壓分設定碼
unsigned long GetUBSetting(void){ return setInfo->UB; }
//
// 取得最小壓分設定碼
unsigned long GetLBSetting(void){ return setInfo->LB; }
//
// 取得彩金累積率設定碼
unsigned long GetJPSetting(void){ return setInfo->JP; }




