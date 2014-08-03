/*
 * @file load_png.h
 *
 */

#ifndef LOAD_PNG_H_
#define LOAD_PNG_H_

#include <stdlib.h>
#include <assert.h>

#include <stdint.h>
#include <sys/types.h>
#include <png.h>
#include "gltexture2d.h"

#define PNG_SIG_BYTES 8

/* Function Prototype */
char* load_png(const char* name, int* width, int* height);
void  create_png_texture(const char *filename,GLTEXTURE2D* gltex2d);

void  create_png_texture_mem(PIXELS* pixels,GLTEXTURE2D* gltex2d,unsigned int _screen_width,unsigned int _screen_height);

/**
 * @brief load PNG image file.
 * @name PNG file name
 * @width Width
 * @height Height
 * @retval Pixels array pointer
 */
char* load_png(const char* name, int* width, int* height)
{
	FILE *png_file = fopen(name, "rb");
	assert(png_file);

	uint8_t header[PNG_SIG_BYTES];

	unsigned int bytes_loaded = fread(header, 1, PNG_SIG_BYTES, png_file);
	if(bytes_loaded <= 0){
		assert(!png_sig_cmp(header, 0, PNG_SIG_BYTES));
	}

	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	assert(png_ptr);

	png_infop info_ptr = png_create_info_struct(png_ptr);
	assert(info_ptr);

	png_infop end_info = png_create_info_struct(png_ptr);
	assert(end_info);

	assert(!setjmp(png_jmpbuf(png_ptr)));
	png_init_io(png_ptr, png_file);
	png_set_sig_bytes(png_ptr, PNG_SIG_BYTES);
	png_read_info(png_ptr, info_ptr);

	*width = png_get_image_width(png_ptr, info_ptr);
	*height = png_get_image_height(png_ptr, info_ptr);

#ifdef _DEBUG
	printf("Image file:%s,Width=%d,Height=%d \n",name,*width,*height);
#endif

	png_uint_32 bit_depth, color_type;
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);
	color_type = png_get_color_type(png_ptr, info_ptr);

	if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
		png_set_gray_1_2_4_to_8(png_ptr);

	if (bit_depth == 16)
			png_set_strip_16(png_ptr);

	if(color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png_ptr);
	else if(color_type == PNG_COLOR_TYPE_GRAY ||
			color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
		{
			png_set_gray_to_rgb(png_ptr);
		}

	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha(png_ptr);
	else
		png_set_filler(png_ptr, 0xff, PNG_FILLER_AFTER);

	png_read_update_info(png_ptr, info_ptr);

	png_uint_32 rowbytes = png_get_rowbytes(png_ptr, info_ptr);
	png_uint_32 numbytes = rowbytes*(*height);
	png_byte* pixels = (png_byte*)malloc(numbytes);
	png_byte** row_ptrs = (png_byte**)malloc((*height) * sizeof(png_byte*));

	int i;
	for (i=0; i<(*height); i++)
	  row_ptrs[i] = pixels + ((*height) - 1 - i)*rowbytes;

	png_read_image(png_ptr, row_ptrs);

	free(row_ptrs);
	png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
	fclose(png_file);

	return (char *)pixels;
}

/**
 * @brief Create texture from PNG file.
 * @param filename PNG file name
 * @param gltex2d GLTEXTURE2D structure
 */
void create_png_texture(const char *filename,GLTEXTURE2D* gltex2d){

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &gltex2d->texnum);
	glBindTexture(GL_TEXTURE_2D, gltex2d->texnum);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	GLubyte *pixels = (GLubyte *)load_png(filename, (signed*)&gltex2d->image_width, (signed*)&gltex2d->image_height);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, gltex2d->image_width, gltex2d->image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	free(pixels);
}

void  create_png_texture_mem(PIXELS* pixels,GLTEXTURE2D* gltex2d,unsigned int _screen_width,unsigned int _screen_height){

	glGenTextures(1, &gltex2d->texnum);
	glBindTexture(GL_TEXTURE_2D, gltex2d->texnum);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);//GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//GLubyte *pixels = (GLubyte *)load_png(filename, (signed*)&gltex2d->image_width, (signed*)&gltex2d->image_height);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pixels->_image_width, pixels->_image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels->_pixels);
	//free(pixels);

	gltex2d->image_width  = pixels->_image_width;
	gltex2d->image_height = pixels->_image_height;

	gltex2d->screen_width  = _screen_width;
	gltex2d->screen_height = _screen_height;
}

#endif /* LOAD_PNG_H_ */
