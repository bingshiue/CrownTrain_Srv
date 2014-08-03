/**
 * @file gltexture2D.h
 *
 */

#ifndef GLTEXTURE2D_H_
#define GLTEXTURE2D_H_

#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>

/**
 * @brief Sprite Position Align Enumeration.
 */
enum SpriteAlign{
	sprite_align_none = 0,/**< 不對齊 */
	sprite_align_left,/**< 開頭對齊螢幕最左邊 */
	sprite_align_center,/**< 整個對齊螢幕中間 */
	sprite_align_right,/**< 尾巴對齊螢幕最右邊 */
	sprite_align_left_center,/**< 整個對齊螢幕左邊中間 */
	sprite_align_right_center,/**< 整個對齊螢幕右邊中間 */
	sprite_align_head_half_screen,/**< 開頭對齊螢幕中間 */
	sprite_align_tail_half_screen,/**< 尾巴對齊螢幕中間 */
};

/**
 * @brief Font Position Align Enumeration.
 */
enum FontAlign{
	font_align_none = 0,/**< 不對齊 */
	font_align_left,/**< 開頭對齊螢幕最左邊 */
	font_align_center,/**< 整個對齊螢幕中間 */
	font_align_right,/**< 尾巴對齊螢幕最右邊 */
	font_align_left_center,/**< 整個對齊螢幕左邊中間 */
	font_align_right_center,/**< 整個對齊螢幕右邊中間 */
	font_align_head_half_screen,/**< 開頭對齊螢幕中間 */
	font_align_tail_half_screen,/**< 尾巴對齊螢幕中間 */
};

/**
 * @brief Structure of Rectangle.
 */
typedef struct Rectangle{
	//unsigned int x;/**< X position */
	//unsigned int y;/**< Y position */
	//unsigned int w;/**< Rectangle width */
	//unsigned int h;/**< Rectangle height */

	float x;/**< X position */
	float y;/**< Y position */
	float w;/**< Rectangle width */
	float h;/**< Rectangle height */


	/**
	 * @brief Constructor.
	 */
	Rectangle(){
		this->x=0;
		this->y=0;
		this->w=0;
		this->h=0;
	}

	/**
	 * @brief Constructor.
	 * @param _x X position
	 * @param _y Y position
	 * @param _w Width
	 * @param _h Height
	 */
	Rectangle(unsigned int _x,unsigned int _y,unsigned int _w,unsigned int _h){
		this->x=_x;
		this->y=_y;
		this->w=_w;
		this->h=_h;
	}
	/**
	 * @brief Set rectangle.
	 * @param _x X position
	 * @param _y Y position
	 * @param _w Width
	 * @param _h Height
	 */
	void setRectangle(unsigned int _x,unsigned int _y,unsigned int _w,unsigned int _h){
		this->x=_x;
		this->y=_y;
		this->w=_w;
		this->h=_h;
	}

}RECTANGLE;

/**
 * @brief Structure of Color.
 */
typedef struct Color{
	float r;/**< Red */
	float g;/**< Green */
	float b;/**< Blue */
	float a;/**< Alpha */

	/**
	 * @brief Constructor.
	 */
	Color(){
		this->r = 1.0f;
		this->g = 1.0f;
		this->b = 1.0f;
		this->a = 1.0f;
	}

	/**
	 * @brief Constructor.
	 * @param r Red
	 * @param g Green
	 * @param b Blue
	 * @param a Alpha
	 */
	Color(float r,float g,float b,float a){
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

}COLOR;

/**
 * @brief Enumeration of Rotate Axis.
 */
enum ROTATEAXIS{
	rotate_none  = 0x00000000,
	rotate_xaxis = 0x00000001,
	rotate_yaxis = 0x00000010,
	rotate_zaxis = 0x00000100,
};

/**
 *@brief Structure of Rotation.
 */
typedef struct Rotate{
	unsigned int axis;/**< which axis */
	float x_axis_degree;/**< x axis degree */
	float y_axis_degree;/**< y axis degree */
	float z_axis_degree;/**< z axis degree */

	/**
	 * @brief Constructor.
	 */
	Rotate(){
		this->axis          = rotate_none;
		this->x_axis_degree = 0.0f;
		this->y_axis_degree = 0.0f;
		this->z_axis_degree = 0.0f;
	}

}ROTATE;

/**
 * @brief Structure of Scale.
 */
typedef struct Scale{
	float x_axis_scale;/**< x axis scale */
	float y_axis_scale;/**< y axis scale */
	float z_axis_scale;/**< z axis scale */

	/**
	 * @brief Constructor.
	 */
	Scale(){
		this->x_axis_scale = 1.0f;
		this->y_axis_scale = 1.0f;
		this->z_axis_scale = 1.0f;
	}

}SCALE;

/**
 * @brief Structure of Pixels.
 */
typedef struct Pixels{
	GLubyte* _pixels;/**< pixels */
	unsigned int _image_width;/**< width of image */
	unsigned int _image_height;/**< height of image */

	/**
	 * @brief Constructor.
	 */
	Pixels(void){
		_pixels = NULL;
		_image_width  = 0;
		_image_height = 0;
	}

}PIXELS;

/**
 * @brief Structure of OpenGL Texture 2D.
 */
typedef struct GLTexture2D{
	GLuint texnum;/**< OpenGL texture number */
	COLOR  color;/**< Texture color */
	Rotate rotate;/**< Texture rotate */
	SCALE scale;/**< Texture scale */
	unsigned int image_width;/**< image width */
	unsigned int image_height;/**< image height */
	unsigned int screen_width;/**< screen width */
	unsigned int screen_height;/**< screen height */

	/**
	 * @brief set screen width.
	 * @param _screen_width screen width
	 */
	void setScreenWidth(unsigned int _screen_width){
		this->screen_width = _screen_width;
	}

	/**
	 * @brief set screen height.
	 * @param _screen_height screen height
	 */
	void setScreenHeight(unsigned int _screen_height){
		this->screen_height = _screen_height;
	}

	/**
	 * @brief Constructor.
	 */
	GLTexture2D(){
		this->texnum        = 0;
		this->image_width   = 0;
		this->image_height  = 0;
		this->screen_width  = 0;
		this->screen_height = 0;
	}

}GLTEXTURE2D;

/**
 * @brief Structure of Sprite Sheet Object.
 */
typedef struct SpriteSheetObject{
	GLuint texnum;/**< OpenGL texture number */
	COLOR  color;/**< Texture color */
	Rotate rotate;/**< Texture rotate */
	SCALE scale;/**< Texture scale */
	Rectangle clip_rect;/**< Clip rectangle */
	unsigned int clip_image_width;/**< clip region image width */
	unsigned int clip_image_height;/**< clip region image height */
	unsigned int sprite_sheet_image_width;/**< original sprite sheet image width */
	unsigned int sprite_sheet_image_height;/**< original sprite sheet image height */
	/**
	 * @brief Set Sprite Sheet Object Parameters.
	 * @param _ref Reference GLTexture2D object
	 * @param _clip_x_pos top left x position of clip region image
	 * @param _clip_y_pos top left y position of clip region image
	 * @param _clip_width width of clip region width
	 * @param _clip_height height of clip region height
	 */
	void SetSpriteSheetObjParas(GLTexture2D* _ref,unsigned int _clip_x_pos,unsigned int _clip_y_pos,unsigned int _clip_width,unsigned int _clip_height){
		// setup OPENGL texture number
		this->texnum = _ref->texnum;
		// setup clip rectangle
		this->clip_rect.w = _clip_width;
		this->clip_rect.h = _clip_height;
		this->clip_rect.x = _clip_x_pos;
		this->clip_rect.y = _ref->image_height - _clip_y_pos - _clip_height;
		// setup member parameter
		this->clip_image_width  = _clip_width;
		this->clip_image_height = _clip_height;
		this->sprite_sheet_image_width  = _ref->image_width;
		this->sprite_sheet_image_height = _ref->image_height;
	}

	/**
	 * @brief Set Color.
	 * @param color Color
	 */
	void SetColor(COLOR color){
		this->color.r = color.r;
		this->color.g = color.g;
		this->color.b = color.b;
		this->color.a = color.a;
	}

}SPRITESHEETOBJECT;

#endif /* GLTEXTURE2D_H_ */
