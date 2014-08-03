/**
 * @file etc_textures.cpp
 *
 */
/* vim: set sts=4 ts=4 noexpandtab: */
/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2009 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

#ifdef __arm__

#ifdef WIN32
#include "win32_runtime.h"
#endif /* WIN32 */

#include <GLES/gl.h>
#include <GLES/glext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "etc_textures.h"
#include "gl_runtime.h"

#ifdef DMALLOC
#include "dmalloc.h"
#endif /* DMALLOC */

/* Report which compressed texture formats are supported. */
int reportTextureFormats()
{
	int bSupportETC = 0;
	GLint *pTexFormat = NULL;
	GLint cTexFormats = 0;
	int iTexFormat = 0;

	GL_CHECK(glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS, &cTexFormats));

	pTexFormat = (GLint *)calloc(cTexFormats, sizeof(GLint));
	if(pTexFormat == NULL)
	{
		fprintf(stderr, "Error: Out of memory at %s:%i\n", __FILE__, __LINE__);
		exit(1);
	}

	GL_CHECK(glGetIntegerv(GL_COMPRESSED_TEXTURE_FORMATS, pTexFormat));
	fprintf(stdout, "Compressed texture formats supported:\n");
	for(iTexFormat = 0; iTexFormat < cTexFormats; iTexFormat ++)
	{
		fprintf(stdout, "0x%.8x\t", pTexFormat[iTexFormat]);
		switch(pTexFormat[iTexFormat])
		{
			case GL_ETC1_RGB8_OES:
				fprintf(stdout, "(%s)\n", "GL_ETC1_RGB8_OES");
				bSupportETC = 1;
				break;
			default:
				fprintf(stdout, "(%s)\n", "UNKNOWN");
				break;
		}
	}

	free(pTexFormat);
	pTexFormat = NULL;

	if(!bSupportETC)
	{
		fprintf(stderr, "Error: Texture compression format GL_ETC1_RGB8_OES not supported\n");
		exit(1);
	}

	return 0;
}



/* Create a texture from random data. */
int createTexture(unsigned char **ppTexData, int iWidth, int iHeight, int iChannel)
{
	int iTexel = 0;
	unsigned char *pTexData = (unsigned char *)calloc(iWidth * iHeight * 4, sizeof(unsigned char));

	if(pTexData == NULL)
	{
		fprintf(stderr, "Error: Out of memory at %s:%i\n", __FILE__, __LINE__);
		exit(1);
	}

	/* Initialize texture with random shades. */
	for(iTexel = 0; iTexel < iWidth * iHeight; iTexel ++)
	{
		int iRand = 0 + (int)(11.0f * (rand() / (RAND_MAX + 1.0f))); /* 0..10 */
		pTexData[iTexel * 4 + 3] = 255; /* Alpha. */
		pTexData[iTexel * 4 + iChannel] = iRand * 25;
	}

	*ppTexData = pTexData;

	return 0;
}



/* Load texture data from file into memory. */
int loadData(const char *pFilename, unsigned char **ppTexData)
{
	FILE *pFile = NULL;
	unsigned char *pTexData = NULL;
	unsigned int iLength = 0;
	size_t sRead = 0;

	pFile = fopen(pFilename, "rb");
	if(pFile == NULL)
	{
		fprintf(stderr, "Error: Failed to load '%s'\n", pFilename);
		exit(1);
	}
	fseek(pFile, 0, SEEK_END);
	iLength = ftell(pFile);
	pTexData = (unsigned char *)calloc(iLength, sizeof(unsigned char));
	if(pTexData == NULL)
	{
		fprintf(stderr, "Error: Out of memory at %s:%i\n", __FILE__, __LINE__);
		exit(1);
	}
	fseek(pFile, 0, SEEK_SET);
	sRead = fread(pTexData, sizeof(unsigned char), iLength, pFile);
	if(sRead != iLength)
	{
		fprintf(stderr, "Error: Failed to load '%s'\n", pFilename);
		exit(1);
	}
	fclose(pFile);

	*ppTexData = pTexData;

	return 0;
}



/* Load compressed Mipmaps into memory:
 * Load the base level, calculate how many Mipmap levels there are.
 * Load the PKM files into memory.
 * Load the data into the texture Mipmap levels.
 */
int loadCompressedMipmaps(const char *pFilenameBase, const char *pFilenameSuffix, GLuint *pTexName)
{
	char *pFilename = NULL;
	unsigned char *pData = NULL;
	ETCHeader *pETCHeader = NULL;
	int iWidth = 0;
	int iHeight = 0;
	int cMipmaps = 0;
	int iMipmap = 0;

	/* Allocate texture name. */
	GL_CHECK(glGenTextures(1, pTexName));
	GL_CHECK(glBindTexture(GL_TEXTURE_2D, *pTexName));

	/* Load base level Mipmap. */
	/* Construct filename, load and tidy up. */
	pFilename = (char *)calloc(strlen(pFilenameBase) + strlen("0") + strlen(pFilenameSuffix) + 1, sizeof(char));
	if(pFilename == NULL)
	{
		fprintf(stderr, "Error: Out of memory at %s:%i\n", __FILE__, __LINE__);
		exit(1);
	}
	strcat(pFilename, pFilenameBase);
	strcat(pFilename, "0");
	strcat(pFilename, pFilenameSuffix);
	loadData(pFilename, &pData);
	free(pFilename);
	pFilename = NULL;
	pETCHeader = (ETCHeader *)pData;

	/* Calculate number of Mipmap levels. */
	fprintf(stdout, "Base level Mipmap loaded: (%i, %i) padded to 4x4 blocks, (%i, %i) actual\n", getPaddedWidth(pETCHeader), getPaddedHeight(pETCHeader), getWidth(pETCHeader), getHeight(pETCHeader));
	iWidth = getWidth(pETCHeader);
	iHeight = getHeight(pETCHeader);
	cMipmaps = 1;
	while((iWidth > 1) || (iHeight > 1))
	{
		cMipmaps ++;
		if(iWidth > 1) iWidth >>= 1;
		if(iHeight > 1) iHeight >>= 1;
	}

	fprintf(stdout, "Requires %i Mipmap levels in total\n", cMipmaps);

	/* Load base Mipmap level into level 0 of texture. */
	/* Skip the 16 byte header of the PKM file before passing the data to OpenGL-ES. */
	glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_ETC1_RGB8_OES, getWidth(pETCHeader), getHeight(pETCHeader), 0, (getPaddedWidth(pETCHeader) * getPaddedHeight(pETCHeader)) >> 1, pData + 16);
	free(pData);
	pData = NULL;

	/* Load other levels. */
	for(iMipmap = 1; iMipmap < cMipmaps; iMipmap++)
	{
		/* Construct filename, load and tidy up. */
		char *pLevel = NULL;
		int iInput = iMipmap;
		int iInputLen = 0;

		/* Calculate the string length of the Mipmap level number (no snprintf in ANSI C). */
		do
		{
			iInput /= 10;
			iInputLen ++;
		}
		while(iInput != 0);

		pLevel = (char *)calloc(iInputLen + 1, sizeof(char));
		if(pLevel == NULL)
		{
			fprintf(stderr, "Error: Out of memory at %s:%i\n", __FILE__, __LINE__);
			exit(1);
		}
		sprintf(pLevel, "%i", iMipmap);

		pFilename = (char *)calloc(strlen(pFilenameBase) + strlen(pLevel) + strlen(pFilenameSuffix) + 1, sizeof(char));
		if(pFilename == NULL)
		{
			fprintf(stderr, "Error: Out of memory at %s:%i\n", __FILE__, __LINE__);
			exit(1);
		}
		strcat(pFilename, pFilenameBase);
		strcat(pFilename, pLevel);
		strcat(pFilename, pFilenameSuffix);
		loadData(pFilename, &pData);
		free(pFilename);
		pFilename = NULL;
		free(pLevel);
		pLevel = NULL;
		pETCHeader = (ETCHeader *)pData;

		/* Load Mipmap level into texture. */
		/* Skip the 16 byte header of the PKM file before passing the data to OpenGL-ES. */
		glCompressedTexImage2D(GL_TEXTURE_2D, iMipmap, GL_ETC1_RGB8_OES, getWidth(pETCHeader), getHeight(pETCHeader), 0, (getPaddedWidth(pETCHeader) * getPaddedHeight(pETCHeader)) >> 1, pData + 16);

		free(pData);
		pData = NULL;
	}

	return 0;
}

unsigned short getWidth(ETCHeader *pHeader)
{
	return (pHeader->iWidthMSB << 8) | pHeader->iWidthLSB;
}

unsigned short getHeight(ETCHeader *pHeader)
{
	return (pHeader->iHeightMSB << 8) | pHeader->iHeightLSB;
}

unsigned short getPaddedWidth(ETCHeader *pHeader)
{
	return (pHeader->iPaddedWidthMSB << 8) | pHeader->iPaddedWidthLSB;
}

unsigned short getPaddedHeight(ETCHeader *pHeader)
{
	return (pHeader->iPaddedHeightMSB << 8) | pHeader->iPaddedHeightLSB;
}

#endif

