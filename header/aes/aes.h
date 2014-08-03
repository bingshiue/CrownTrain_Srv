/*
 * @file aes.h
 *
 */

#ifndef AES_H_
#define AES_H_

#define byte unsigned char

byte* aes(byte *in, byte *skey);

void addRoundKey(void);
void subBytes(void);
void shiftRows(void);
byte xtime(byte x);
void mixColumns(void);
void computeKey(byte rcon);

#endif /* AES_H_ */
