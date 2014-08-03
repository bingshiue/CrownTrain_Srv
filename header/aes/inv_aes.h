/*
 * @file inv_aes.h
 *
 */

#ifndef INV_AES_H_
#define INV_AES_H_

#define byte unsigned char

extern  byte sbox[256];
extern  byte rcon [];
extern  byte state[16];

byte* inv_aes(byte *in, byte *skey);

void inv_addRoundKey(int i);
void inv_subBytes(void);
void inv_shiftRows(void);
byte inv_xtime(byte x);
void inv_mixColumns(void);
void inv_computeKey(byte rcon, int round);

#endif /* INV_AES_H_ */
