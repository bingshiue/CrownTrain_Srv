/**
 * @file etc_textures.h
 *
 */

#ifndef ETC_TEXTURES_H_
#define ETC_TEXTURES_H_

#include <GLES/gl.h>

typedef struct {
	char	aName[6];
	unsigned short iBlank;
	/* NB: Beware endianess issues here. */
	unsigned char iPaddedWidthMSB;
	unsigned char iPaddedWidthLSB;
	unsigned char iPaddedHeightMSB;
	unsigned char iPaddedHeightLSB;
	unsigned char iWidthMSB;
	unsigned char iWidthLSB;
	unsigned char iHeightMSB;
	unsigned char iHeightLSB;
} ETCHeader;

unsigned short getWidth(ETCHeader *pHeader);
unsigned short getHeight(ETCHeader *pHeader);
unsigned short getPaddedWidth(ETCHeader *pHeader);
unsigned short getPaddedHeight(ETCHeader *pHeader);

int reportTextureFormats(void);
int createTexture(unsigned char **ppTexData, int iWidth, int iHeight, int iChannel);
int loadData(const char *pFilename, unsigned char **ppTexData);
int loadCompressedMipmaps(const char *pFilenameBase, const char *pFilenameSuffix, GLuint *pTexName);

#endif /* ETC_TEXTURES_H_ */
