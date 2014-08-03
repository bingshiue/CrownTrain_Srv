/*
 * @file draw_subfunc.h
 * @brief OpenGL Draw Sub Function.
 */

#ifndef DRAW_SUBFUNC_H_
#define DRAW_SUBFUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <GLES/gl.h>
#include "../commDefine.h"

/* Function Prototype */
void DrawSpriteSub(GLTEXTURE2D* gltex2d,int x,int y);
void DrawSpriteSub(GLTEXTURE2D* gltex2d,RECTANGLE clipRect,int clipScreenWidth,int clipScreenHeight,int x,int y);
void DrawSpriteSub(GLTEXTURE2D* gltex2d,int clipScreenWidth,int clipScreenHeight,unsigned,int totalFrame,unsigned int frameWidth,unsigned int frameHeight,unsigned int frame,int x,int y);
void DrawLongSpriteSub(GLTEXTURE2D* gltex2d,int clipScreenWidth,int clipScreenHeight,int EndX, int EndY, unsigned int Value, int WH, int H);
void DrawFont(GLTEXTURE2D* gltex2d,int clipScreenWidth,int clipScreenHeight,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,int WH,int StartX, int StartY,const char*fmt,...);

void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int x,int y);
void DrawSpriteSubFixScalePosition(SPRITESHEETOBJECT* spriteSheetObj,int x,int y,bool FixScalePostion);
void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int x,int y,unsigned int alignType);
void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,RECTANGLE clipRect,int x,int y);
void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,unsigned int frame,int x,int y);
void DrawLongSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int EndX, int EndY, unsigned int Value, int WH, int H);
void DrawLongSpriteSubMiddle(SPRITESHEETOBJECT* spriteSheetObj,int EndX, int EndY, unsigned int Value, int WH, int H);
void DrawFont(SPRITESHEETOBJECT* spriteSheetObj,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,int WH,int StartX, int StartY,const char*fmt,...);

void DrawLine(int x1,int y1,int x2,int y2,unsigned int lineWidth,COLOR color);

/**
 * @brief Enumeration of Split Image.
 */
enum IMAGESPLITTYPE{
	img_split_type_before_check = 0,/**< Unchecked */
	img_split_type_horizontal   = 1,/**< Image split type is horizontal */
	img_split_type_vertical     = 2,/**< Image split type is vertical */
	img_split_type_both         = 3,/**< Image split type is both horizontal and vertical */
};

/**
 * @brief Draw Sprite Sub.
 * @param gltex2d GLTEXTURE2D structure
 * @param x X position
 * @param y Y position
 */
void DrawSpriteSub(GLTEXTURE2D* gltex2d,int x,int y){
	GLfixed Plain_Vertex[8];
	GLfixed Plain_TxCoord[8];
	unsigned short Plain_Index[]={
			2,1,0,
			0,3,2
	};

	y = (SCREEN_HEIGHT) - y - gltex2d->screen_height;

	glLoadIdentity();
	glTranslatex( glF(-(HALF_SCREEN_WIDTH-(gltex2d->screen_width/2.0f)-x)*(2.0f/SCREEN_WIDTH)), glF(-(HALF_SCREEN_HEIGHT-(gltex2d->screen_height/2.0f)-y)*(2.0f/SCREEN_HEIGHT)), glF(0.0f) );
	if(gltex2d->rotate.axis & rotate_xaxis)
		glRotatef(gltex2d->rotate.x_axis_degree,1.0f,0.0f,0.0f);
	if(gltex2d->rotate.axis & rotate_yaxis)
		glRotatef(gltex2d->rotate.y_axis_degree,0.0f,1.0f,0.0f);
	if(gltex2d->rotate.axis & rotate_zaxis)
		glRotatef(gltex2d->rotate.z_axis_degree,0.0f,0.0f,1.0f);
	glScalef(gltex2d->scale.x_axis_scale,gltex2d->scale.y_axis_scale,gltex2d->scale.z_axis_scale);

	glBindTexture(GL_TEXTURE_2D, gltex2d->texnum);
	glColor4f(gltex2d->color.r, gltex2d->color.g, gltex2d->color.b, gltex2d->color.a);

	Plain_Vertex[0]=glF((gltex2d->screen_width/SCREEN_WIDTH)*-0.5f); Plain_Vertex[1]=glF((gltex2d->screen_height/SCREEN_HEIGHT)* 0.5f);//Top left
	Plain_Vertex[2]=glF((gltex2d->screen_width/SCREEN_WIDTH)* 0.5f); Plain_Vertex[3]=glF((gltex2d->screen_height/SCREEN_HEIGHT)* 0.5f);//Top right
	Plain_Vertex[4]=glF((gltex2d->screen_width/SCREEN_WIDTH)* 0.5f); Plain_Vertex[5]=glF((gltex2d->screen_height/SCREEN_HEIGHT)*-0.5f);//Bottom right
	Plain_Vertex[6]=glF((gltex2d->screen_width/SCREEN_WIDTH)*-0.5f); Plain_Vertex[7]=glF((gltex2d->screen_height/SCREEN_HEIGHT)*-0.5f);//Bottom left

	Plain_TxCoord[0]=glF(0.0f); Plain_TxCoord[1]=glF(1.0f);//Top left
	Plain_TxCoord[2]=glF(1.0f); Plain_TxCoord[3]=glF(1.0f);//Top right
	Plain_TxCoord[4]=glF(1.0f); Plain_TxCoord[5]=glF(0.0f);//Bottom right
	Plain_TxCoord[6]=glF(0.0f); Plain_TxCoord[7]=glF(0.0f);//Bottom left

	glVertexPointer(2,GL_FIXED,0, Plain_Vertex);
	glTexCoordPointer(2,GL_FIXED,0,Plain_TxCoord);

	glDrawElements(GL_TRIANGLES,2*3,GL_UNSIGNED_SHORT,Plain_Index);
}

void DrawSpriteSub(GLTEXTURE2D* gltex2d,RECTANGLE clipRect,int clipScreenWidth,int clipScreenHeight,int x,int y){
	GLfixed Plain_Vertex[8];
	GLfixed Plain_TxCoord[8];
	unsigned short Plain_Index[]={
			2,1,0,
			0,3,2
	};

	y = (SCREEN_HEIGHT) - y - clipScreenHeight;
	clipRect.y = clipScreenHeight - clipRect.y - clipRect.h;

	glLoadIdentity();
	glTranslatex( glF(-(HALF_SCREEN_WIDTH-(clipScreenWidth/2.0f)-x)*(2.0f/SCREEN_WIDTH)), glF(-(HALF_SCREEN_HEIGHT-(clipScreenHeight/2.0f)-y)*(2.0f/SCREEN_HEIGHT)), glF(0.0f) );
	if(gltex2d->rotate.axis & rotate_xaxis)
		glRotatef(gltex2d->rotate.x_axis_degree,1.0f,0.0f,0.0f);
	if(gltex2d->rotate.axis & rotate_yaxis)
		glRotatef(gltex2d->rotate.y_axis_degree,0.0f,1.0f,0.0f);
	if(gltex2d->rotate.axis & rotate_zaxis)
		glRotatef(gltex2d->rotate.z_axis_degree,0.0f,0.0f,1.0f);
	glScalef(gltex2d->scale.x_axis_scale,gltex2d->scale.y_axis_scale,gltex2d->scale.z_axis_scale);

	glBindTexture(GL_TEXTURE_2D, gltex2d->texnum);
	glColor4f(gltex2d->color.r, gltex2d->color.g, gltex2d->color.b, gltex2d->color.a);

	Plain_Vertex[0]=glF((clipScreenWidth/SCREEN_WIDTH)*-0.5f); Plain_Vertex[1]=glF((clipScreenHeight/SCREEN_HEIGHT)* 0.5f);//Top left
	Plain_Vertex[2]=glF((clipScreenWidth/SCREEN_WIDTH)* 0.5f); Plain_Vertex[3]=glF((clipScreenHeight/SCREEN_HEIGHT)* 0.5f);//Top right
	Plain_Vertex[4]=glF((clipScreenWidth/SCREEN_WIDTH)* 0.5f); Plain_Vertex[5]=glF((clipScreenHeight/SCREEN_HEIGHT)*-0.5f);//Bottom right
	Plain_Vertex[6]=glF((clipScreenWidth/SCREEN_WIDTH)*-0.5f); Plain_Vertex[7]=glF((clipScreenHeight/SCREEN_HEIGHT)*-0.5f);//Bottom left

	Plain_TxCoord[0]=glF(clipRect.x/(float)gltex2d->image_width);              Plain_TxCoord[1]=glF((clipRect.y+clipRect.h)/(float)gltex2d->image_height);//Top left
	Plain_TxCoord[2]=glF((clipRect.x+clipRect.w)/(float)gltex2d->image_width); Plain_TxCoord[3]=glF((clipRect.y+clipRect.h)/(float)gltex2d->image_height);//Top right
	Plain_TxCoord[4]=glF((clipRect.x+clipRect.w)/(float)gltex2d->image_width); Plain_TxCoord[5]=glF(clipRect.y/(float)gltex2d->image_height);//Bottom right
	Plain_TxCoord[6]=glF(clipRect.x/(float)gltex2d->image_width);              Plain_TxCoord[7]=glF(clipRect.y/(float)gltex2d->image_height);//Bottom left

	glVertexPointer(2,GL_FIXED,0, Plain_Vertex);
	glTexCoordPointer(2,GL_FIXED,0,Plain_TxCoord);

	glDrawElements(GL_TRIANGLES,2*3,GL_UNSIGNED_SHORT,Plain_Index);
}

void DrawSpriteSub(GLTEXTURE2D* gltex2d,int clipScreenWidth,int clipScreenHeight,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,unsigned int frame,int x,int y){
	GLfixed Plain_Vertex[8];
	GLfixed Plain_TxCoord[8];
	unsigned short Plain_Index[]={
			2,1,0,
			0,3,2
	};

	int split_type = img_split_type_before_check;
	// Check image split type
	if(gltex2d->image_height == frameHeight){
		split_type = img_split_type_horizontal;
	}else if(gltex2d->image_width == frameWidth){
		split_type = img_split_type_vertical;
	}else if(gltex2d->image_height%frameHeight==0 && gltex2d->image_width%frameWidth==0){
		split_type = img_split_type_both;
	}else{
		printf("Image size error or Input width/height error ! \n");
		return;
	}

	RECTANGLE clipRect;
	y = (SCREEN_HEIGHT) - y - clipScreenHeight;
	glLoadIdentity();
	glTranslatef( -(HALF_SCREEN_WIDTH-(clipScreenWidth/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(clipScreenHeight/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );
	if(gltex2d->rotate.axis & rotate_xaxis)
		glRotatef(gltex2d->rotate.x_axis_degree,1.0f,0.0f,0.0f);
	if(gltex2d->rotate.axis & rotate_yaxis)
		glRotatef(gltex2d->rotate.y_axis_degree,0.0f,1.0f,0.0f);
	if(gltex2d->rotate.axis & rotate_zaxis)
		glRotatef(gltex2d->rotate.z_axis_degree,0.0f,0.0f,1.0f);
	glScalef(gltex2d->scale.x_axis_scale,gltex2d->scale.y_axis_scale,gltex2d->scale.z_axis_scale);

	glBindTexture(GL_TEXTURE_2D, gltex2d->texnum);
	glColor4f(gltex2d->color.r, gltex2d->color.g, gltex2d->color.b, gltex2d->color.a);

	switch(split_type){

	case img_split_type_horizontal:
		clipRect.w = frameWidth;
		clipRect.h = frameHeight;
		clipRect.x = frame * frameWidth;
		clipRect.y = 0;
		break;

	case img_split_type_vertical:
		clipRect.w = frameWidth;
		clipRect.h = frameHeight;
		clipRect.x = 0;
		clipRect.y = (totalFrame - 1 - frame) * frameHeight;
		break;

	case img_split_type_both:
		clipRect.w = frameWidth;
		clipRect.h = frameHeight;
		clipRect.x = (frame % (gltex2d->image_width/frameWidth)) * (frameWidth);
		clipRect.y = (gltex2d->image_height-frameHeight) - ((frame/(gltex2d->image_width/frameWidth)) * frameHeight);
		break;

	default:
		printf("Unknown error ! \n");
		break;
	}

	Plain_Vertex[0]=glF((clipScreenWidth/SCREEN_WIDTH)*-0.5f); Plain_Vertex[1]=glF((clipScreenHeight/SCREEN_HEIGHT)* 0.5f);//Top left
	Plain_Vertex[2]=glF((clipScreenWidth/SCREEN_WIDTH)* 0.5f); Plain_Vertex[3]=glF((clipScreenHeight/SCREEN_HEIGHT)* 0.5f);//Top right
	Plain_Vertex[4]=glF((clipScreenWidth/SCREEN_WIDTH)* 0.5f); Plain_Vertex[5]=glF((clipScreenHeight/SCREEN_HEIGHT)*-0.5f);//Bottom right
	Plain_Vertex[6]=glF((clipScreenWidth/SCREEN_WIDTH)*-0.5f); Plain_Vertex[7]=glF((clipScreenHeight/SCREEN_HEIGHT)*-0.5f);//Bottom left

	Plain_TxCoord[0]=glF(clipRect.x/(float)gltex2d->image_width);              Plain_TxCoord[1]=glF((clipRect.y+clipRect.h)/(float)gltex2d->image_height);//Top left
	Plain_TxCoord[2]=glF((clipRect.x+clipRect.w)/(float)gltex2d->image_width); Plain_TxCoord[3]=glF((clipRect.y+clipRect.h)/(float)gltex2d->image_height);//Top right
	Plain_TxCoord[4]=glF((clipRect.x+clipRect.w)/(float)gltex2d->image_width); Plain_TxCoord[5]=glF(clipRect.y/(float)gltex2d->image_height);//Bottom right
	Plain_TxCoord[6]=glF(clipRect.x/(float)gltex2d->image_width);              Plain_TxCoord[7]=glF(clipRect.y/(float)gltex2d->image_height);//Bottom left

	glVertexPointer(2,GL_FIXED,0, Plain_Vertex);
	glTexCoordPointer(2,GL_FIXED,0,Plain_TxCoord);

	glDrawElements(GL_TRIANGLES,2*3,GL_UNSIGNED_SHORT,Plain_Index);
}

void DrawLongSpriteSub(GLTEXTURE2D* gltex2d,int clipScreenWidth,int clipScreenHeight,int EndX, int EndY, unsigned int Value, int WH, int H){
	RECTANGLE clipRect;
	int index;
	unsigned int frame_width;
	unsigned int frame_height;

	frame_width  = gltex2d->image_width/10;
	frame_height = gltex2d->image_height;

    for (index = 0; index < H; index++)
    {
        if (Value > 0 || index == 0)
        {
        	clipRect.x = (Value%10)*frame_width;
        	clipRect.y = 0;
        	clipRect.w = frame_width;
        	clipRect.h = frame_height;
        	DrawSpriteSub(gltex2d,clipRect,clipScreenWidth,clipScreenHeight,EndX,EndY);
        }
        Value /= 10;
        if (EndX >= WH) EndX -= WH;
    }
}

void DrawFont(GLTEXTURE2D* gltex2d,int clipScreenWidth,int clipScreenHeight,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,int WH,unsigned int alignType,int StartX, int StartY,const char*fmt,...){
	char text[256]; /* Holds our string */
	va_list ap;     /* Pointer to our list of elements */

	/* If there's no text, do nothing */
	if( fmt == NULL )
		return;

	/* Parses The String For Variables */
	va_start( ap, fmt );
	/* Converts Symbols To Actual Numbers */
	vsprintf( text, fmt, ap );
	va_end( ap );

#ifdef _DEBUG
	/*
	printf("%s,%d \n",text,strlen(text));


	for(unsigned int i=0; i<strlen(text); i++){
		printf("%c \t",*(text + i));
	}
	printf("\n");
	*/
#endif

	unsigned int intervals_cnt = strlen(text) - 1;

	switch(alignType){

	case font_align_none:
		// do nothing
		break;

	case font_align_left:
        StartX = 0;
		break;

	case font_align_center:
        StartX = (1024 - (frameWidth+(WH*intervals_cnt))) / 2;
		break;

	case font_align_right:
        StartX = (1024 - (frameWidth+(WH*intervals_cnt)));
		break;

	case font_align_left_center:
		StartX = ((1024 - (frameWidth+(WH*intervals_cnt))) / 2) - 1024/4;
		break;

	case font_align_right_center:
		StartX = ((1024 - (frameWidth+(WH*intervals_cnt))) / 2) + 1024/4;
		break;

	case font_align_head_half_screen:
		StartX = 512;
		break;

	case font_align_tail_half_screen:
		 StartX = (512 - (frameWidth+(WH*intervals_cnt)));
		break;

	default:
		break;
	}

	for(unsigned int i=0; i<strlen(text); i++){
		int current = *(text + i);
		//current -= 0x20;
		if(current >=0 && current < 256){
			DrawSpriteSub(gltex2d,clipScreenWidth,clipScreenHeight,totalFrame,frameWidth,frameHeight,current,StartX,StartY);
			//StartX += frameWidth;
			StartX += WH;
		}
	}
}


void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int x,int y){
	GLfixed Plain_Vertex[8];
	GLfixed Plain_TxCoord[8];
	unsigned short Plain_Index[]={
			2,1,0,
			0,3,2
	};

#ifdef ENABLE_DRAW_12_H
	RECTANGLE targetRect(x,y,spriteSheetObj->clip_image_width,spriteSheetObj->clip_image_height * 1.333 + 1);
	y = (SCREEN_HEIGHT) - y - targetRect.h;
#else
	y = (SCREEN_HEIGHT) - y - spriteSheetObj->clip_image_height;
#endif

	glLoadIdentity();
#ifdef ENABLE_DRAW_12_H
	glTranslatef( -(HALF_SCREEN_WIDTH-(targetRect.w/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(targetRect.h/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );
#else
	glTranslatef( -(HALF_SCREEN_WIDTH-(spriteSheetObj->clip_image_width/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(spriteSheetObj->clip_image_height/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );
#endif

	if(spriteSheetObj->rotate.axis & rotate_xaxis)
		glRotatef(spriteSheetObj->rotate.x_axis_degree,1.0f,0.0f,0.0f);
	if(spriteSheetObj->rotate.axis & rotate_yaxis)
		glRotatef(spriteSheetObj->rotate.y_axis_degree,0.0f,1.0f,0.0f);
	if(spriteSheetObj->rotate.axis & rotate_zaxis)
		glRotatef(spriteSheetObj->rotate.z_axis_degree,0.0f,0.0f,1.0f);
	glScalef(spriteSheetObj->scale.x_axis_scale,spriteSheetObj->scale.y_axis_scale,spriteSheetObj->scale.z_axis_scale);

	glBindTexture(GL_TEXTURE_2D, spriteSheetObj->texnum);
	glColor4f(spriteSheetObj->color.r, spriteSheetObj->color.g, spriteSheetObj->color.b, spriteSheetObj->color.a);

#ifdef ENABLE_DRAW_12_H
	Plain_Vertex[0]=glF((targetRect.w/SCREEN_WIDTH)*-1.0f); Plain_Vertex[1]=glF((targetRect.h/SCREEN_HEIGHT)* 1.0f);//Top left
	Plain_Vertex[2]=glF((targetRect.w/SCREEN_WIDTH)* 1.0f); Plain_Vertex[3]=glF((targetRect.h/SCREEN_HEIGHT)* 1.0f);//Top right
	Plain_Vertex[4]=glF((targetRect.w/SCREEN_WIDTH)* 1.0f); Plain_Vertex[5]=glF((targetRect.h/SCREEN_HEIGHT)*-1.0f);//Bottom right
	Plain_Vertex[6]=glF((targetRect.w/SCREEN_WIDTH)*-1.0f); Plain_Vertex[7]=glF((targetRect.h/SCREEN_HEIGHT)*-1.0f);//Bottom left
#else
	Plain_Vertex[0]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)*-0.5f); Plain_Vertex[1]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)* 0.5f);//Top left
	Plain_Vertex[2]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)* 0.5f); Plain_Vertex[3]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)* 0.5f);//Top right
	Plain_Vertex[4]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)* 0.5f); Plain_Vertex[5]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)*-0.5f);//Bottom right
	Plain_Vertex[6]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)*-0.5f); Plain_Vertex[7]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)*-0.5f);//Bottom left
#endif

	Plain_TxCoord[0]=glF(spriteSheetObj->clip_rect.x/(float)spriteSheetObj->sprite_sheet_image_width);                               Plain_TxCoord[1]=glF((spriteSheetObj->clip_rect.y+spriteSheetObj->clip_rect.h)/(float)spriteSheetObj->sprite_sheet_image_height);//Top left
	Plain_TxCoord[2]=glF((spriteSheetObj->clip_rect.x+spriteSheetObj->clip_rect.w)/(float)spriteSheetObj->sprite_sheet_image_width); Plain_TxCoord[3]=glF((spriteSheetObj->clip_rect.y+spriteSheetObj->clip_rect.h)/(float)spriteSheetObj->sprite_sheet_image_height);//Top right
	Plain_TxCoord[4]=glF((spriteSheetObj->clip_rect.x+spriteSheetObj->clip_rect.w)/(float)spriteSheetObj->sprite_sheet_image_width); Plain_TxCoord[5]=glF(spriteSheetObj->clip_rect.y/(float)spriteSheetObj->sprite_sheet_image_height);//Bottom right
	Plain_TxCoord[6]=glF(spriteSheetObj->clip_rect.x/(float)spriteSheetObj->sprite_sheet_image_width);                               Plain_TxCoord[7]=glF(spriteSheetObj->clip_rect.y/(float)spriteSheetObj->sprite_sheet_image_height);//Bottom left

	glVertexPointer(2,GL_FIXED,0, Plain_Vertex);
	glTexCoordPointer(2,GL_FIXED,0,Plain_TxCoord);

	glDrawElements(GL_TRIANGLES,2*3,GL_UNSIGNED_SHORT,Plain_Index);

	//glBegin(GL_QUADS);
	//glTexCoord2f(spriteSheetObj->clip_rect.x/(float)spriteSheetObj->sprite_sheet_image_width, spriteSheetObj->clip_rect.y/(float)spriteSheetObj->sprite_sheet_image_height);                                                             glVertex2f((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)*-0.5f, (spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)*-0.5f);
	//glTexCoord2f((spriteSheetObj->clip_rect.x+spriteSheetObj->clip_rect.w)/(float)spriteSheetObj->sprite_sheet_image_width, spriteSheetObj->clip_rect.y/(float)spriteSheetObj->sprite_sheet_image_height);                               glVertex2f((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)* 0.5f, (spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)*-0.5f);
	//glTexCoord2f((spriteSheetObj->clip_rect.x+spriteSheetObj->clip_rect.w)/(float)spriteSheetObj->sprite_sheet_image_width, (spriteSheetObj->clip_rect.y+spriteSheetObj->clip_rect.h)/(float)spriteSheetObj->sprite_sheet_image_height); glVertex2f((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)* 0.5f, (spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)* 0.5f);
	//glTexCoord2f(spriteSheetObj->clip_rect.x/(float)spriteSheetObj->sprite_sheet_image_width, (spriteSheetObj->clip_rect.y+spriteSheetObj->clip_rect.h)/(float)spriteSheetObj->sprite_sheet_image_height);                               glVertex2f((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)*-0.5f, (spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)* 0.5f);
    //glEnd();
}

void DrawSpriteSubFixScalePosition(SPRITESHEETOBJECT* spriteSheetObj,int x,int y,bool FixScalePostion){
	GLfixed Plain_Vertex[8];
	GLfixed Plain_TxCoord[8];
	unsigned short Plain_Index[]={
			2,1,0,
			0,3,2
	};

#ifdef ENABLE_DRAW_12_H
	unsigned int scale_width=0,scale_height=0;//fixed
	if(FixScalePostion==true){
		scale_width  = spriteSheetObj->clip_image_width * spriteSheetObj->scale.x_axis_scale/1.0f;//fixed
		scale_height = spriteSheetObj->clip_image_height * spriteSheetObj->scale.y_axis_scale/1.0f * 1.333;//fixed
	}
	RECTANGLE targetRect(x,y,spriteSheetObj->clip_image_width,spriteSheetObj->clip_image_height * 1.333 + 1);
	if(FixScalePostion==true){
		y = (SCREEN_HEIGHT) - y - scale_height;//fixed
	}else{
		y = (SCREEN_HEIGHT) - y - targetRect.h;
	}
#else
	y = (SCREEN_HEIGHT) - y - spriteSheetObj->clip_image_height;
#endif

	glLoadIdentity();
#ifdef ENABLE_DRAW_12_H
	if(FixScalePostion==true){
		glTranslatef( -(HALF_SCREEN_WIDTH-(scale_width/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(scale_height/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );//fixed
	}else{
		glTranslatef( -(HALF_SCREEN_WIDTH-(targetRect.w/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(targetRect.h/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );
	}
#else
	glTranslatef( -(HALF_SCREEN_WIDTH-(spriteSheetObj->clip_image_width/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(spriteSheetObj->clip_image_height/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );
#endif

	if(spriteSheetObj->rotate.axis & rotate_xaxis)
		glRotatef(spriteSheetObj->rotate.x_axis_degree,1.0f,0.0f,0.0f);
	if(spriteSheetObj->rotate.axis & rotate_yaxis)
		glRotatef(spriteSheetObj->rotate.y_axis_degree,0.0f,1.0f,0.0f);
	if(spriteSheetObj->rotate.axis & rotate_zaxis)
		glRotatef(spriteSheetObj->rotate.z_axis_degree,0.0f,0.0f,1.0f);
	glScalef(spriteSheetObj->scale.x_axis_scale,spriteSheetObj->scale.y_axis_scale,spriteSheetObj->scale.z_axis_scale);

	glBindTexture(GL_TEXTURE_2D, spriteSheetObj->texnum);
	glColor4f(spriteSheetObj->color.r, spriteSheetObj->color.g, spriteSheetObj->color.b, spriteSheetObj->color.a);

#ifdef ENABLE_DRAW_12_H
	Plain_Vertex[0]=glF((targetRect.w/SCREEN_WIDTH)*-1.0f); Plain_Vertex[1]=glF((targetRect.h/SCREEN_HEIGHT)* 1.0f);//Top left
	Plain_Vertex[2]=glF((targetRect.w/SCREEN_WIDTH)* 1.0f); Plain_Vertex[3]=glF((targetRect.h/SCREEN_HEIGHT)* 1.0f);//Top right
	Plain_Vertex[4]=glF((targetRect.w/SCREEN_WIDTH)* 1.0f); Plain_Vertex[5]=glF((targetRect.h/SCREEN_HEIGHT)*-1.0f);//Bottom right
	Plain_Vertex[6]=glF((targetRect.w/SCREEN_WIDTH)*-1.0f); Plain_Vertex[7]=glF((targetRect.h/SCREEN_HEIGHT)*-1.0f);//Bottom left
#else
	Plain_Vertex[0]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)*-0.5f); Plain_Vertex[1]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)* 0.5f);//Top left
	Plain_Vertex[2]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)* 0.5f); Plain_Vertex[3]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)* 0.5f);//Top right
	Plain_Vertex[4]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)* 0.5f); Plain_Vertex[5]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)*-0.5f);//Bottom right
	Plain_Vertex[6]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)*-0.5f); Plain_Vertex[7]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)*-0.5f);//Bottom left
#endif

	Plain_TxCoord[0]=glF(spriteSheetObj->clip_rect.x/(float)spriteSheetObj->sprite_sheet_image_width);                               Plain_TxCoord[1]=glF((spriteSheetObj->clip_rect.y+spriteSheetObj->clip_rect.h)/(float)spriteSheetObj->sprite_sheet_image_height);//Top left
	Plain_TxCoord[2]=glF((spriteSheetObj->clip_rect.x+spriteSheetObj->clip_rect.w)/(float)spriteSheetObj->sprite_sheet_image_width); Plain_TxCoord[3]=glF((spriteSheetObj->clip_rect.y+spriteSheetObj->clip_rect.h)/(float)spriteSheetObj->sprite_sheet_image_height);//Top right
	Plain_TxCoord[4]=glF((spriteSheetObj->clip_rect.x+spriteSheetObj->clip_rect.w)/(float)spriteSheetObj->sprite_sheet_image_width); Plain_TxCoord[5]=glF(spriteSheetObj->clip_rect.y/(float)spriteSheetObj->sprite_sheet_image_height);//Bottom right
	Plain_TxCoord[6]=glF(spriteSheetObj->clip_rect.x/(float)spriteSheetObj->sprite_sheet_image_width);                               Plain_TxCoord[7]=glF(spriteSheetObj->clip_rect.y/(float)spriteSheetObj->sprite_sheet_image_height);//Bottom left

	glVertexPointer(2,GL_FIXED,0, Plain_Vertex);
	glTexCoordPointer(2,GL_FIXED,0,Plain_TxCoord);

	glDrawElements(GL_TRIANGLES,2*3,GL_UNSIGNED_SHORT,Plain_Index);
}

void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int x,int y,unsigned int alignType){
	GLfixed Plain_Vertex[8];
	GLfixed Plain_TxCoord[8];
	unsigned short Plain_Index[]={
			2,1,0,
			0,3,2
	};

#ifdef ENABLE_DRAW_12_H
	RECTANGLE targetRect(x,y,spriteSheetObj->clip_image_width,spriteSheetObj->clip_image_height * 1.333 + 1);
	y = (SCREEN_HEIGHT) - y - targetRect.h;
#else
	y = (SCREEN_HEIGHT) - y - spriteSheetObj->clip_image_height;
#endif

	switch(alignType){

	case sprite_align_none:/**< 不對齊 */
		// do nothing
		break;

	case sprite_align_left:/**< 開頭對齊螢幕最左邊 */
        x = 0;
		break;

	case sprite_align_center:/**< 整個對齊螢幕中間 */
        x = (1024 - (spriteSheetObj->clip_image_width))/ 2;
		break;

	case sprite_align_right:/**< 尾巴對齊螢幕最右邊 */
        x = (1024 - (spriteSheetObj->clip_image_width));
		break;

	case sprite_align_left_center:/**< 整個對齊螢幕左邊中間 */
		x = ((1024 - (spriteSheetObj->clip_image_width)) / 2) - 1024/4;
		break;

	case sprite_align_right_center:/**< 整個對齊螢幕右邊中間 */
		x = ((1024 - (spriteSheetObj->clip_image_width)) / 2) + 1024/4;
		break;

	case sprite_align_head_half_screen:/**< 開頭對齊螢幕中間 */
		x = 512;
		break;

	case sprite_align_tail_half_screen:/**< 尾巴對齊螢幕中間 */
		x = (512 - (spriteSheetObj->clip_image_width));
		break;

	default:
		break;
	}

	glLoadIdentity();
#ifdef ENABLE_DRAW_12_H
	glTranslatef( -(HALF_SCREEN_WIDTH-(targetRect.w/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(targetRect.h/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );
#else
	glTranslatef( -(HALF_SCREEN_WIDTH-(spriteSheetObj->clip_image_width/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(spriteSheetObj->clip_image_height/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );
#endif

	if(spriteSheetObj->rotate.axis & rotate_xaxis)
		glRotatef(spriteSheetObj->rotate.x_axis_degree,1.0f,0.0f,0.0f);
	if(spriteSheetObj->rotate.axis & rotate_yaxis)
		glRotatef(spriteSheetObj->rotate.y_axis_degree,0.0f,1.0f,0.0f);
	if(spriteSheetObj->rotate.axis & rotate_zaxis)
		glRotatef(spriteSheetObj->rotate.z_axis_degree,0.0f,0.0f,1.0f);
	glScalef(spriteSheetObj->scale.x_axis_scale,spriteSheetObj->scale.y_axis_scale,spriteSheetObj->scale.z_axis_scale);

	glBindTexture(GL_TEXTURE_2D, spriteSheetObj->texnum);
	glColor4f(spriteSheetObj->color.r, spriteSheetObj->color.g, spriteSheetObj->color.b, spriteSheetObj->color.a);

#ifdef ENABLE_DRAW_12_H
	Plain_Vertex[0]=glF((targetRect.w/SCREEN_WIDTH)*-1.0f); Plain_Vertex[1]=glF((targetRect.h/SCREEN_HEIGHT)* 1.0f);//Top left
	Plain_Vertex[2]=glF((targetRect.w/SCREEN_WIDTH)* 1.0f); Plain_Vertex[3]=glF((targetRect.h/SCREEN_HEIGHT)* 1.0f);//Top right
	Plain_Vertex[4]=glF((targetRect.w/SCREEN_WIDTH)* 1.0f); Plain_Vertex[5]=glF((targetRect.h/SCREEN_HEIGHT)*-1.0f);//Bottom right
	Plain_Vertex[6]=glF((targetRect.w/SCREEN_WIDTH)*-1.0f); Plain_Vertex[7]=glF((targetRect.h/SCREEN_HEIGHT)*-1.0f);//Bottom left
#else
	Plain_Vertex[0]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)*-0.5f); Plain_Vertex[1]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)* 0.5f);//Top left
	Plain_Vertex[2]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)* 0.5f); Plain_Vertex[3]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)* 0.5f);//Top right
	Plain_Vertex[4]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)* 0.5f); Plain_Vertex[5]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)*-0.5f);//Bottom right
	Plain_Vertex[6]=glF((spriteSheetObj->clip_rect.w/SCREEN_WIDTH)*-0.5f); Plain_Vertex[7]=glF((spriteSheetObj->clip_rect.h/SCREEN_HEIGHT)*-0.5f);//Bottom left
#endif

	Plain_TxCoord[0]=glF(spriteSheetObj->clip_rect.x/(float)spriteSheetObj->sprite_sheet_image_width);                               Plain_TxCoord[1]=glF((spriteSheetObj->clip_rect.y+spriteSheetObj->clip_rect.h)/(float)spriteSheetObj->sprite_sheet_image_height);//Top left
	Plain_TxCoord[2]=glF((spriteSheetObj->clip_rect.x+spriteSheetObj->clip_rect.w)/(float)spriteSheetObj->sprite_sheet_image_width); Plain_TxCoord[3]=glF((spriteSheetObj->clip_rect.y+spriteSheetObj->clip_rect.h)/(float)spriteSheetObj->sprite_sheet_image_height);//Top right
	Plain_TxCoord[4]=glF((spriteSheetObj->clip_rect.x+spriteSheetObj->clip_rect.w)/(float)spriteSheetObj->sprite_sheet_image_width); Plain_TxCoord[5]=glF(spriteSheetObj->clip_rect.y/(float)spriteSheetObj->sprite_sheet_image_height);//Bottom right
	Plain_TxCoord[6]=glF(spriteSheetObj->clip_rect.x/(float)spriteSheetObj->sprite_sheet_image_width);                               Plain_TxCoord[7]=glF(spriteSheetObj->clip_rect.y/(float)spriteSheetObj->sprite_sheet_image_height);//Bottom left

	glVertexPointer(2,GL_FIXED,0, Plain_Vertex);
	glTexCoordPointer(2,GL_FIXED,0,Plain_TxCoord);

	glDrawElements(GL_TRIANGLES,2*3,GL_UNSIGNED_SHORT,Plain_Index);
}

void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,RECTANGLE clipRect,int x,int y){
	GLfixed Plain_Vertex[8];
	GLfixed Plain_TxCoord[8];
	unsigned short Plain_Index[]={
			2,1,0,
			0,3,2
	};

#ifdef ENABLE_DRAW_12_H
	unsigned int scale_width,scale_height;//fixed
	scale_width  = clipRect.w * spriteSheetObj->scale.x_axis_scale/1.0f;//fixed
	scale_height = clipRect.h * spriteSheetObj->scale.y_axis_scale/1.0f * 1.333;//fixed
	RECTANGLE targetRect(x,y,clipRect.w,clipRect.h * 1.333 + 1);
	y = (SCREEN_HEIGHT) - y - scale_height;//fixed
	//y = (SCREEN_HEIGHT) - y - targetRect.h;
	clipRect.y = spriteSheetObj->clip_image_height - clipRect.y - clipRect.h;
#else
	y = (SCREEN_HEIGHT) - y - clipRect.h;
	clipRect.y = spriteSheetObj->clip_image_height - clipRect.y - clipRect.h;
#endif

	glLoadIdentity();
#ifdef ENABLE_DRAW_12_H
	glTranslatef( -(HALF_SCREEN_WIDTH-(scale_width/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(scale_height/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );//fixed
	//glTranslatef( -(HALF_SCREEN_WIDTH-(targetRect.w/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(targetRect.h/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );
#else
	glTranslatef( -(HALF_SCREEN_WIDTH-(clipRect.w/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(clipRect.h/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );
#endif

	if(spriteSheetObj->rotate.axis & rotate_xaxis)
		glRotatef(spriteSheetObj->rotate.x_axis_degree,1.0f,0.0f,0.0f);
	if(spriteSheetObj->rotate.axis & rotate_yaxis)
		glRotatef(spriteSheetObj->rotate.y_axis_degree,0.0f,1.0f,0.0f);
	if(spriteSheetObj->rotate.axis & rotate_zaxis)
		glRotatef(spriteSheetObj->rotate.z_axis_degree,0.0f,0.0f,1.0f);
	glScalef(spriteSheetObj->scale.x_axis_scale,spriteSheetObj->scale.y_axis_scale,spriteSheetObj->scale.z_axis_scale);

	glBindTexture(GL_TEXTURE_2D, spriteSheetObj->texnum);
	glColor4f(spriteSheetObj->color.r, spriteSheetObj->color.g, spriteSheetObj->color.b, spriteSheetObj->color.a);

#ifdef ENABLE_DRAW_12_H
	Plain_Vertex[0]=glF((targetRect.w/SCREEN_WIDTH)*-1.0f); Plain_Vertex[1]=glF((targetRect.h/SCREEN_HEIGHT)* 1.0f);//Top left
	Plain_Vertex[2]=glF((targetRect.w/SCREEN_WIDTH)* 1.0f); Plain_Vertex[3]=glF((targetRect.h/SCREEN_HEIGHT)* 1.0f);//Top right
	Plain_Vertex[4]=glF((targetRect.w/SCREEN_WIDTH)* 1.0f); Plain_Vertex[5]=glF((targetRect.h/SCREEN_HEIGHT)*-1.0f);//Bottom right
	Plain_Vertex[6]=glF((targetRect.w/SCREEN_WIDTH)*-1.0f); Plain_Vertex[7]=glF((targetRect.h/SCREEN_HEIGHT)*-1.0f);//Bottom left
#else
	Plain_Vertex[0]=glF((clipRect.w/SCREEN_WIDTH)*-0.5f); Plain_Vertex[1]=glF((clipRect.h/SCREEN_HEIGHT)* 0.5f);//Top left
	Plain_Vertex[2]=glF((clipRect.w/SCREEN_WIDTH)* 0.5f); Plain_Vertex[3]=glF((clipRect.h/SCREEN_HEIGHT)* 0.5f);//Top right
	Plain_Vertex[4]=glF((clipRect.w/SCREEN_WIDTH)* 0.5f); Plain_Vertex[5]=glF((clipRect.h/SCREEN_HEIGHT)*-0.5f);//Bottom right
	Plain_Vertex[6]=glF((clipRect.w/SCREEN_WIDTH)*-0.5f); Plain_Vertex[7]=glF((clipRect.h/SCREEN_HEIGHT)*-0.5f);//Bottom left
#endif

	Plain_TxCoord[0]=glF((spriteSheetObj->clip_rect.x+clipRect.x)/(float)spriteSheetObj->sprite_sheet_image_width);              Plain_TxCoord[1]=glF((spriteSheetObj->clip_rect.y+clipRect.y+clipRect.h)/(float)spriteSheetObj->sprite_sheet_image_height);//Top left
	Plain_TxCoord[2]=glF((spriteSheetObj->clip_rect.x+clipRect.x+clipRect.w)/(float)spriteSheetObj->sprite_sheet_image_width);   Plain_TxCoord[3]=glF((spriteSheetObj->clip_rect.y+clipRect.y+clipRect.h)/(float)spriteSheetObj->sprite_sheet_image_height);//Top right
	Plain_TxCoord[4]=glF((spriteSheetObj->clip_rect.x+clipRect.x+clipRect.w)/(float)spriteSheetObj->sprite_sheet_image_width);   Plain_TxCoord[5]=glF((spriteSheetObj->clip_rect.y+clipRect.y)/(float)spriteSheetObj->sprite_sheet_image_height);//Bottom right
	Plain_TxCoord[6]=glF((spriteSheetObj->clip_rect.x+clipRect.x)/(float)spriteSheetObj->sprite_sheet_image_width);              Plain_TxCoord[7]=glF((spriteSheetObj->clip_rect.y+clipRect.y)/(float)spriteSheetObj->sprite_sheet_image_height);//Bottom left

	glVertexPointer(2,GL_FIXED,0, Plain_Vertex);
	glTexCoordPointer(2,GL_FIXED,0,Plain_TxCoord);

	glDrawElements(GL_TRIANGLES,2*3,GL_UNSIGNED_SHORT,Plain_Index);
	//glBegin(GL_QUADS);
		//glTexCoord2f((spriteSheetObj->clip_rect.x+clipRect.x)/(float)spriteSheetObj->sprite_sheet_image_width, (spriteSheetObj->clip_rect.y+clipRect.y)/(float)spriteSheetObj->sprite_sheet_image_height);
		//glVertex2f((clipRect.w/SCREEN_WIDTH)*-0.5f, (clipRect.h/SCREEN_HEIGHT)*-0.5f);

		//glTexCoord2f((spriteSheetObj->clip_rect.x+clipRect.x+clipRect.w)/(float)spriteSheetObj->sprite_sheet_image_width, (spriteSheetObj->clip_rect.y+clipRect.y)/(float)spriteSheetObj->sprite_sheet_image_height);
		//glVertex2f((clipRect.w/SCREEN_WIDTH)* 0.5f, (clipRect.h/SCREEN_HEIGHT)*-0.5f);

		//glTexCoord2f((spriteSheetObj->clip_rect.x+clipRect.x+clipRect.w)/(float)spriteSheetObj->sprite_sheet_image_width, (spriteSheetObj->clip_rect.y+clipRect.y+clipRect.h)/(float)spriteSheetObj->sprite_sheet_image_height);
		//glVertex2f((clipRect.w/SCREEN_WIDTH)* 0.5f, (clipRect.h/SCREEN_HEIGHT)* 0.5f);

		//glTexCoord2f((spriteSheetObj->clip_rect.x+clipRect.x)/(float)spriteSheetObj->sprite_sheet_image_width, (spriteSheetObj->clip_rect.y+clipRect.y+clipRect.h)/(float)spriteSheetObj->sprite_sheet_image_height);
		//glVertex2f((clipRect.w/SCREEN_WIDTH)*-0.5f, (clipRect.h/SCREEN_HEIGHT)* 0.5f);
    //glEnd();
}

void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,unsigned int frame,int x,int y){
	GLfixed Plain_Vertex[8];
	GLfixed Plain_TxCoord[8];
	unsigned short Plain_Index[]={
			2,1,0,
			0,3,2
	};

	int split_type = img_split_type_before_check;
	// Check image split type
	if(spriteSheetObj->clip_image_height == frameHeight){
		split_type = img_split_type_horizontal;
	}else if(spriteSheetObj->clip_image_width == frameWidth){
		split_type = img_split_type_vertical;
	}else if(spriteSheetObj->clip_image_height%frameHeight==0 && spriteSheetObj->clip_image_width%frameWidth==0){
		split_type = img_split_type_both;
	}else{
		printf("Image size error or Input width/height error ! \n");
		return;
	}

	RECTANGLE clipRect;
#ifdef ENABLE_DRAW_12_H
	unsigned int scale_width,scale_height;//fixed
	scale_width  = frameWidth  * spriteSheetObj->scale.x_axis_scale/1.0f;//fixed
	scale_height = frameHeight * spriteSheetObj->scale.y_axis_scale/1.0f * 1.333;//fixed
	RECTANGLE targetRect(x,y,frameWidth,frameHeight * 1.333 + 1);
	y = (SCREEN_HEIGHT) - y - scale_height;
	//y = (SCREEN_HEIGHT) - y - targetRect.h;
#else
	y = (SCREEN_HEIGHT) - y - frameHeight;
#endif

	glLoadIdentity();
#ifdef ENABLE_DRAW_12_H
	glTranslatef( -(HALF_SCREEN_WIDTH-(scale_width/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(scale_height/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );//fixed
	//glTranslatef( -(HALF_SCREEN_WIDTH-(targetRect.w/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(targetRect.h/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );
#else
	glTranslatef( -(HALF_SCREEN_WIDTH-(frameWidth/2.0f)-x)*(2.0f/SCREEN_WIDTH), -(HALF_SCREEN_HEIGHT-(frameHeight/2.0f)-y)*(2.0f/SCREEN_HEIGHT), 0.0f );
#endif

	if(spriteSheetObj->rotate.axis & rotate_xaxis)
		glRotatef(spriteSheetObj->rotate.x_axis_degree,1.0f,0.0f,0.0f);
	if(spriteSheetObj->rotate.axis & rotate_yaxis)
		glRotatef(spriteSheetObj->rotate.y_axis_degree,0.0f,1.0f,0.0f);
	if(spriteSheetObj->rotate.axis & rotate_zaxis)
		glRotatef(spriteSheetObj->rotate.z_axis_degree,0.0f,0.0f,1.0f);
	glScalef(spriteSheetObj->scale.x_axis_scale,spriteSheetObj->scale.y_axis_scale,spriteSheetObj->scale.z_axis_scale);

	glBindTexture(GL_TEXTURE_2D, spriteSheetObj->texnum);
	glColor4f(spriteSheetObj->color.r, spriteSheetObj->color.g, spriteSheetObj->color.b, spriteSheetObj->color.a);

	switch(split_type){

	case img_split_type_horizontal:
		clipRect.w = frameWidth;
		clipRect.h = frameHeight;
		clipRect.x = frame * frameWidth;
		clipRect.y = 0;
		break;

	case img_split_type_vertical:
		clipRect.w = frameWidth;
		clipRect.h = frameHeight;
		clipRect.x = 0;
		clipRect.y = (totalFrame - 1 - frame) * frameHeight;
		break;

	case img_split_type_both:
		clipRect.w = frameWidth;
		clipRect.h = frameHeight;
		clipRect.x = (frame % (spriteSheetObj->clip_image_width/frameWidth)) * (frameWidth);
		clipRect.y = (spriteSheetObj->clip_image_height-frameHeight) - ((frame/(spriteSheetObj->clip_image_width/frameWidth)) * frameHeight);
		break;

	default:
		printf("Unknown error ! \n");
		break;
	}

#ifdef ENABLE_DRAW_12_H
	Plain_Vertex[0]=glF((targetRect.w/SCREEN_WIDTH)*-1.0f); Plain_Vertex[1]=glF((targetRect.h/SCREEN_HEIGHT)* 1.0f);//Top left
	Plain_Vertex[2]=glF((targetRect.w/SCREEN_WIDTH)* 1.0f); Plain_Vertex[3]=glF((targetRect.h/SCREEN_HEIGHT)* 1.0f);//Top right
	Plain_Vertex[4]=glF((targetRect.w/SCREEN_WIDTH)* 1.0f); Plain_Vertex[5]=glF((targetRect.h/SCREEN_HEIGHT)*-1.0f);//Bottom right
	Plain_Vertex[6]=glF((targetRect.w/SCREEN_WIDTH)*-1.0f); Plain_Vertex[7]=glF((targetRect.h/SCREEN_HEIGHT)*-1.0f);//Bottom left
#else
	Plain_Vertex[0]=glF((clipRect.w/SCREEN_WIDTH)*-0.5f); Plain_Vertex[1]=glF((clipRect.h/SCREEN_HEIGHT)* 0.5f);//Top left
	Plain_Vertex[2]=glF((clipRect.w/SCREEN_WIDTH)* 0.5f); Plain_Vertex[3]=glF((clipRect.h/SCREEN_HEIGHT)* 0.5f);//Top right
	Plain_Vertex[4]=glF((clipRect.w/SCREEN_WIDTH)* 0.5f); Plain_Vertex[5]=glF((clipRect.h/SCREEN_HEIGHT)*-0.5f);//Bottom right
	Plain_Vertex[6]=glF((clipRect.w/SCREEN_WIDTH)*-0.5f); Plain_Vertex[7]=glF((clipRect.h/SCREEN_HEIGHT)*-0.5f);//Bottom left
#endif

	clipRect.x+=0.5f;
	clipRect.y-=0.13f;
	clipRect.w-=1.0f;
	clipRect.h-=0.26f;

	Plain_TxCoord[0]=glF((spriteSheetObj->clip_rect.x+clipRect.x)/(float)spriteSheetObj->sprite_sheet_image_width);                 Plain_TxCoord[1]=glF((spriteSheetObj->clip_rect.y+clipRect.y+clipRect.h)/(float)spriteSheetObj->sprite_sheet_image_height);//Top left
	Plain_TxCoord[2]=glF((spriteSheetObj->clip_rect.x+clipRect.x+clipRect.w)/(float)spriteSheetObj->sprite_sheet_image_width);      Plain_TxCoord[3]=glF((spriteSheetObj->clip_rect.y+clipRect.y+clipRect.h)/(float)spriteSheetObj->sprite_sheet_image_height);//Top right
	Plain_TxCoord[4]=glF((spriteSheetObj->clip_rect.x+clipRect.x+clipRect.w)/(float)spriteSheetObj->sprite_sheet_image_width);      Plain_TxCoord[5]=glF((spriteSheetObj->clip_rect.y+clipRect.y)/(float)spriteSheetObj->sprite_sheet_image_height);//Bottom right
	Plain_TxCoord[6]=glF((spriteSheetObj->clip_rect.x+clipRect.x)/(float)spriteSheetObj->sprite_sheet_image_width);                 Plain_TxCoord[7]=glF((spriteSheetObj->clip_rect.y+clipRect.y)/(float)spriteSheetObj->sprite_sheet_image_height);//Bottom left

	/*
	Plain_TxCoord[0]=glF((spriteSheetObj->clip_rect.x+clipRect.x)/(float)spriteSheetObj->sprite_sheet_image_width*1.001f);                 Plain_TxCoord[1]=glF((spriteSheetObj->clip_rect.y+clipRect.y+clipRect.h)/(float)spriteSheetObj->sprite_sheet_image_height*0.999f);//Top left
	Plain_TxCoord[2]=glF((spriteSheetObj->clip_rect.x+clipRect.x+clipRect.w)/(float)spriteSheetObj->sprite_sheet_image_width*0.999f);      Plain_TxCoord[3]=glF((spriteSheetObj->clip_rect.y+clipRect.y+clipRect.h)/(float)spriteSheetObj->sprite_sheet_image_height*0.999f);//Top right
	Plain_TxCoord[4]=glF((spriteSheetObj->clip_rect.x+clipRect.x+clipRect.w)/(float)spriteSheetObj->sprite_sheet_image_width*0.999f);      Plain_TxCoord[5]=glF((spriteSheetObj->clip_rect.y+clipRect.y)/(float)spriteSheetObj->sprite_sheet_image_height*1.001f);//Bottom right
	Plain_TxCoord[6]=glF((spriteSheetObj->clip_rect.x+clipRect.x)/(float)spriteSheetObj->sprite_sheet_image_width*1.001f);                 Plain_TxCoord[7]=glF((spriteSheetObj->clip_rect.y+clipRect.y)/(float)spriteSheetObj->sprite_sheet_image_height*1.001f);//Bottom left
    */

	glVertexPointer(2,GL_FIXED,0, Plain_Vertex);
	glTexCoordPointer(2,GL_FIXED,0,Plain_TxCoord);

	glDrawElements(GL_TRIANGLES,2*3,GL_UNSIGNED_SHORT,Plain_Index);
}

void DrawLongSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int EndX, int EndY, unsigned int Value, int WH, int H){
	RECTANGLE clipRect;
	int index;
	unsigned int frame_width;
	unsigned int frame_height;

	frame_width  = spriteSheetObj->clip_image_width/10;//gltex2d->image_width/10;
	frame_height = spriteSheetObj->clip_image_height;//gltex2d->image_height;

    for (index = 0; index < H; index++)
    {
        if (Value > 0 || index == 0)
        {
        	clipRect.x = (Value%10)*frame_width;
        	clipRect.y = 0;
        	clipRect.w = frame_width;
        	clipRect.h = frame_height;
        	DrawSpriteSub(spriteSheetObj,clipRect,EndX,EndY);
        }
        Value /= 10;
        if (EndX >= WH) EndX -= WH;
    }
}

void DrawLongSpriteSubMiddle(SPRITESHEETOBJECT* spriteSheetObj,int EndX, int EndY, unsigned int Value, int WH, int H){
	RECTANGLE clipRect;
	int index;
	unsigned int frame_width;
	unsigned int frame_height;
	int digits = 0;

	//
	for(unsigned int step=1; step<=Value; step*=10){
		digits++;
	}

	if(digits==0) digits=1;
	digits -= 1;
	if(digits < 0) { digits = 0; }

	if(WH%2==1){ EndX = EndX + ((WH-1)/2) * digits; }
	else { EndX = EndX + ((WH)/2) * digits;}
	//

	frame_width  = spriteSheetObj->clip_image_width/10;//gltex2d->image_width/10;
	frame_height = spriteSheetObj->clip_image_height;//gltex2d->image_height;

    for (index = 0; index < H; index++)
    {
        if (Value > 0 || index == 0)
        {
        	clipRect.x = (Value%10)*frame_width;
        	clipRect.y = 0;
        	clipRect.w = frame_width;
        	clipRect.h = frame_height;
        	DrawSpriteSub(spriteSheetObj,clipRect,EndX,EndY);
        }
        Value /= 10;
        if (EndX >= WH) EndX -= WH;
    }
}


void DrawFont(SPRITESHEETOBJECT* spriteSheetObj,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,int WH,unsigned int alignType,int StartX, int StartY,const char*fmt,...){
	char text[256]; /* Holds our string */
	va_list ap;     /* Pointer to our list of elements */

	/* If there's no text, do nothing */
	if( fmt == NULL )
		return;

	/* Parses The String For Variables */
	va_start( ap, fmt );
	/* Converts Symbols To Actual Numbers */
	vsprintf( text, fmt, ap );
	va_end( ap );

#ifdef _DEBUG
	/*
	printf("%s,%d \n",text,strlen(text));


	for(unsigned int i=0; i<strlen(text); i++){
		printf("%c \t",*(text + i));
	}
	printf("\n");
	*/
#endif

	unsigned int intervals_cnt = strlen(text) - 1;

	switch(alignType){

	case font_align_none:
		// do nothing
		break;

	case font_align_left:
        StartX = 0;
		break;

	case font_align_center:
        StartX = (1024 - (frameWidth+(WH*intervals_cnt))) / 2;
		break;

	case font_align_right:
        StartX = (1024 - (frameWidth+(WH*intervals_cnt)));
		break;

	case font_align_left_center:
		StartX = ((1024 - (frameWidth+(WH*intervals_cnt))) / 2) - 1024/4;
		break;

	case font_align_right_center:
		StartX = ((1024 - (frameWidth+(WH*intervals_cnt))) / 2) + 1024/4;
		break;

	case font_align_head_half_screen:
		StartX = 512;
		break;

	case font_align_tail_half_screen:
		 StartX = (512 - (frameWidth+(WH*intervals_cnt)));
		break;

	default:
		break;
	}

	for(unsigned int i=0; i<strlen(text); i++){
		int current = *(text + i);
		//current -= 0x20;
		if(current >=0 && current < 256){
			DrawSpriteSub(spriteSheetObj,totalFrame,frameWidth,frameHeight,current,StartX,StartY);
			//StartX += frameWidth;
			StartX += WH;
		}
	}
}

void DrawLine(int x1,int y1,int x2,int y2,unsigned int lineWidth,COLOR color){
	GLfixed Line_Vertex[4];
	unsigned short Line_Index[]={
			0,1
	};

	Line_Vertex[0] = glF(-1.0f+((float)x1/512));
	Line_Vertex[1] = glF(-1.0f+(768-(float)y1)/384);
	Line_Vertex[2] = glF(-1.0f+((float)x2/512));
	Line_Vertex[3] = glF(-1.0f+(768-(float)y2)/384);

	glDisable(GL_TEXTURE_2D);
	glColor4f(color.r,color.g,color.b,color.a);
	glLineWidth((float)lineWidth);
	glLoadIdentity();
	glVertexPointer(2,GL_FIXED,0, Line_Vertex);
	glDrawElements(GL_LINES,4/2,GL_UNSIGNED_SHORT,Line_Index);
	//glBegin(GL_LINES);
	//glVertex2f(-1.0f+((float)x1/512),-1.0f+(768-(float)y1)/384);
	//glVertex2f(-1.0f+((float)x2/512),-1.0f+(768-(float)y2)/384);
	//glEnd();
	glEnable(GL_TEXTURE_2D);


}

#endif /* DRAW_SUBFUNC_H_ */
