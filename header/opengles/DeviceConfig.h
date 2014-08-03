/**
 * @file DeviceConfig.h
 * @brief OpenGLES device configure header file.
 */

#ifndef DEVICECONFIG_H
#define DEVICECONFIG_H


#include <EGL/egl.h>
#include <GLES/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../commDefine.h"

//16 bit

static EGLint const attrib_list[] = {
	EGL_RED_SIZE, 5,
	EGL_GREEN_SIZE, 6,
	EGL_BLUE_SIZE, 5,
	EGL_ALPHA_SIZE, 0,
	EGL_RENDERABLE_TYPE,
	EGL_OPENGL_ES_BIT,
	EGL_SURFACE_TYPE,
	EGL_WINDOW_BIT,
	EGL_SAMPLE_BUFFERS, GL_FALSE,
	EGL_NONE
	};

//32 bit
/*
static EGLint const attrib_list[] = {
	EGL_RED_SIZE, 8,
	EGL_GREEN_SIZE,8,
	EGL_BLUE_SIZE, 8,
	EGL_ALPHA_SIZE,8,
	EGL_RENDERABLE_TYPE,
	EGL_OPENGL_ES_BIT,
	EGL_SURFACE_TYPE,
	EGL_WINDOW_BIT,
	EGL_NONE
	};
*/

EGLConfig	m_EGLXConfig;
EGLContext	m_EGLXContext;
EGLSurface	m_EGLXSurface;
EGLDisplay	m_EGLXDisplay;
EGLint		m_EGLXNumOfConfigs;
EGLNativeWindowType  m_nativeWindow;
fbdev_window* m_EGLXwin_native;
EGLint max_num_config;

// function prototype define
bool CreateEGL(void);
void DeleteEGL(void);
void EGLFlush(void);

bool CreateEGL()
{

	EGLConfig *configs = NULL;
	int i;

	EGLint major, minor, num_config;
	/* see egl_config.c for a list of supported configs, this looks for
	a 5650 (rgba) config, supporting OpenGL ES and windowed surfaces  */


	/* step1 - get a display */
	m_EGLXDisplay = eglGetDisplay( EGL_DEFAULT_DISPLAY );
	if ( EGL_NO_DISPLAY == m_EGLXDisplay )
	{
		printf( "eglGetDisplay() failed (error 0x%x)\n", eglGetError() );
		return 1;
	}

	if ( EGL_FALSE == eglInitialize( m_EGLXDisplay, &major, &minor ) )
	{
		printf( "eglInitialize() failed (error 0x%x)\n", eglGetError() );
		return 1;
	}
	if ( EGL_FALSE == eglGetConfigs(m_EGLXDisplay, NULL, 0, &max_num_config) )
	{
		printf( "eglGetConfigs() failed to retrive the number of configs (error 0x%x)\n", eglGetError() );
		return 1;
	}
	if(max_num_config <= 0)
	{
		printf( "No EGLconfigs found\n" );
		return 1;
	}
	configs = (EGLConfig *)malloc( sizeof( EGLConfig) * max_num_config );
	if ( NULL == configs )
	{
		printf( "Out of memory\n" );
		return 1;
	}
	/* step2 - bind to the wanted client API */
	/* eglBindAPI( EGL_OPENGL_ES_API ); */
	/* step3 - find a suitable config */
	//eglChooseConfig( dpy, attrib_list, configs, max_num_config, &num_config )
	if ( EGL_FALSE == eglChooseConfig( m_EGLXDisplay, attrib_list, configs,max_num_config, &m_EGLXNumOfConfigs ) )
	{
		printf( "eglChooseConfig() failed (error 0x%x)\n", eglGetError() );
		return 1;
	}
	if ( 0 == m_EGLXNumOfConfigs )
	{
		printf( "eglChooseConfig() was unable to find a suitable config\n" );
		return 1;
	}
	/*Use this to explicitly check that the EGL config has the expected color depths */
	//16bit

	for ( i=0; i<m_EGLXNumOfConfigs; i++ )
	{
		EGLint value;


		eglGetConfigAttrib( m_EGLXDisplay, configs[i], EGL_RED_SIZE, &value );
		if ( 5 != value ) continue;
		eglGetConfigAttrib( m_EGLXDisplay, configs[i], EGL_GREEN_SIZE, &value );
		if ( 6 != value ) continue;
		eglGetConfigAttrib( m_EGLXDisplay, configs[i], EGL_BLUE_SIZE, &value );
		if ( 5 != value ) continue;
		eglGetConfigAttrib( m_EGLXDisplay, configs[i], EGL_ALPHA_SIZE, &value );
		if ( 0 != value ) continue;
		eglGetConfigAttrib( m_EGLXDisplay, configs[i], EGL_SAMPLES, &value );
		if ( 4 != value ) continue;

		m_EGLXConfig = configs[i];
		break;
	}

	//32bit..
    /*
	for ( i=0; i<m_EGLXNumOfConfigs; i++ )
	{
		EGLint value;


		eglGetConfigAttrib( m_EGLXDisplay, configs[i], EGL_RED_SIZE, &value );
		if ( 8 != value ) continue;
		eglGetConfigAttrib( m_EGLXDisplay, configs[i], EGL_GREEN_SIZE, &value );
		if ( 8 != value ) continue;
		eglGetConfigAttrib( m_EGLXDisplay, configs[i], EGL_BLUE_SIZE, &value );
		if ( 8 != value ) continue;
		eglGetConfigAttrib( m_EGLXDisplay, configs[i], EGL_ALPHA_SIZE, &value );
		if ( 8 != value ) continue;
		eglGetConfigAttrib( m_EGLXDisplay, configs[i], EGL_SAMPLES, &value );
		if ( 4 != value ) continue;

		m_EGLXConfig = configs[i];
		break;
	}
	*/

	/* step4 - create a window surface (LCD_WIDTHxLCD_HEIGHT pixels) */
	m_EGLXwin_native = (fbdev_window *)malloc( sizeof( fbdev_window ) );
	m_EGLXwin_native->width = SCREEN_WIDTH;
	m_EGLXwin_native->height = SCREEN_HEIGHT;
	m_nativeWindow = (EGLNativeWindowType)m_EGLXwin_native;

	m_EGLXSurface = eglCreateWindowSurface( m_EGLXDisplay, m_EGLXConfig, m_nativeWindow, NULL );

	if ( EGL_NO_SURFACE == m_EGLXSurface )
	{
		printf( "eglCreateWindowSurface failed (error 0x%x\n", eglGetError() );
		return 1;
	}
	/* step5 - create a context */
	m_EGLXContext = eglCreateContext( m_EGLXDisplay, m_EGLXConfig, EGL_NO_CONTEXT, NULL );
	if ( EGL_NO_CONTEXT == m_EGLXContext )
	{
		printf( "eglCreateContext failed (error 0x%x)\n", eglGetError() );
		return 1;
	}
	/* step6 - make the context and surface current */
	if ( EGL_FALSE == eglMakeCurrent( m_EGLXDisplay, m_EGLXSurface, m_EGLXSurface, m_EGLXContext ) )
	{
		printf( "eglMakeCurrent failed (error 0x%x)\n", eglGetError() );
		return 1;
	}
	/* begin user code */
	eglSwapInterval(m_EGLXDisplay,0);

	free( configs );
	return true;
}

void DeleteEGL()
{
	eglMakeCurrent(m_EGLXDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

	eglDestroyContext(m_EGLXDisplay, m_EGLXContext);

	eglDestroySurface(m_EGLXDisplay, m_EGLXSurface);

	free(m_EGLXwin_native);

	eglTerminate(m_EGLXDisplay);
}

void EGLFlush()
{
	eglSwapBuffers(m_EGLXDisplay,m_EGLXSurface);
}

#endif
