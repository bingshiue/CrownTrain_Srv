/**
 * @file opengles_setup.h
 * @brief OpenGLES setup functions.
 */

#ifndef OPENGLES_SETUP_H_
#define OPENGLES_SETUP_H_

#include <GLES/gl.h>
#include <EGL/egl.h>
#include "DeviceConfig.h"

/*--- function prototype define ---*/
bool OpenGLESInit(void);
void InitGLES(void);
void OpenGLESGetStatus(void);
void OpenGLESEnd(void);
void glPerspectivef(GLfloat fov, GLfloat aspect, GLfloat near_val, GLfloat far_val);
void OrthoBegin(void);
void OrthoEnd(void);
float framerate(int Poly);
double GetTime(void);

bool OpenGLESInit(){

	if(!CreateEGL())
       return false;

	InitGLES();
	//InitTexture();

	return true;
}

void InitGLES(){

	glClearColorx(glF(0.0f), glF(0.0f), glF(1.0f), glF(1.0f));

    //glShadeModel(GL_SMOOTH);                  // 20120914
	//glEnable(GL_DEPTH_TEST);					// hidden surface removal 20120914
	//glEnable(GL_CULL_FACE);				    // do not calculate inside of poly's 20120914
    glEnable(GL_TEXTURE_2D);                   // Enable Smooth Shading
    glFrontFace(GL_CCW);						// counter clock-wise polygons are out 20120914
	//glCullFace(GL_BACK);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	//glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do 20120914
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glClearDepthx(glF(1.0f));

    glDisableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    // Set Projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrthox(glF(0.0f),glF(LCD_WIDTH),0,glF(LCD_HEIGHT),glF(-1.0f),glF(1.0f));
	glOrthox(glF(-0.999f),glF(0.999f),glF(-0.999f),glF(0.999f),glF(-1.0f),glF(1.0f));
	// setting perspective correction
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	//glPerspectivef( 3.141592654f/4.0f, 1.33f, 0.01f, 1000.0f );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void OpenGLESGetStatus(void){

	int status =0;

    glGetIntegerv(GL_MAX_TEXTURE_SIZE,&status);
    printf( "==GL_MAX_TEXTURE_SIZE=%d=\n",status);

    glGetIntegerv(GL_MAX_TEXTURE_UNITS,&status);
    printf( "==GL_MAX_TEXTURE_UNITS=%d=\n",status);
}

void glPerspectivef(GLfloat fov, GLfloat aspect, GLfloat near_val, GLfloat far_val){

	GLfloat top = (GLfloat)(tan(fov*0.5) * near_val);
	GLfloat bottom = -top;
	GLfloat left = aspect * bottom;
	GLfloat right = aspect * top;

    glFrustumx(glF(left), glF(right), glF(bottom), glF(top), glF(near_val),glF(far_val));
}


void OrthoBegin(void){

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);


	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrthox(0,SCREEN_WIDTH*65536,0,SCREEN_HEIGHT*65536,-1.0*65536,1.0*65536);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}

void OrthoEnd(void){

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}


void OpenGLESEnd(){

    DeleteEGL();
    //Free the sound effects
    //Mix_FreeChunk( scratch );
    //Mix_FreeChunk( high );
    //Mix_FreeChunk( med );
    //Mix_FreeChunk( low );

    //Free the music
    //Mix_FreeMusic( music );

    //Quit SDL_mixer
    Mix_CloseAudio();

    //Quit SDL
    SDL_Quit();
}

/**
 * @brief Calculate frame rate.
 * @param Poly ???
 * @retval frame rate
 *
 */
float framerate(int Poly){

    static float previous   = 0;
    static int   framecount = 0;
	static float finalfps   = 0;
    framecount++;

    if( framecount == 10 ){
        float time = (float)GetTime();
        float seconds = time - previous;
        float fps = framecount / seconds;
        previous = time;
		finalfps = fps;
        framecount = 0;
    }

	return finalfps;
}

double GetTime(){
    //clock_t sTime;
	double dSec=0;
	/*
	dSec=((double)clock()/CLOCKS_PER_SEC);
    printf("%f : %d \n",dSec,CLOCKS_PER_SEC);
    */
	return dSec;
}



#endif /* OPENGLES_SETUP_H_ */
