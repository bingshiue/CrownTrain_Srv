/**
 * @file main.h
 * @brief main header file.
 *
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <linux/rtc.h>
#include <fcntl.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "game/gameRecordType.h"
#include "game/gameEnum.h"
#include "probability/probabilityEnum.h"
#include "game/gameDefine.h"
#include "game/gameSettingType.h"
#include "preprocessor.h"
#include "commDefine.h"
#include "keyboard/keyevent_def.h"
#include "mersenne_twister/mt_random.h"
#include "tasksystem/TaskSystemEx.h"
#include "tasksystem/Task.h"
#include "textures.h"
#include "serial/serialDataType.h"
#include "serial/serialComm.h"
#include "serial/aes_keys.h"
#include "serial/serialDevice.h"
#include "serial/serial_subfunc.h"
#include "libevent/libevent_cb_func.h"
#include "server/mainProcess.h"
#ifndef __arm__
#include <GL/gl.h>
#include <GL/glu.h>
#include "opengl/load_png.h"
#include "opengl/gltexture2d.h"
#include "opengl/draw_subfunc.h"
#else
#include <GLES/gl.h>
#include <EGL/egl.h>
#include "opengles/opengles_setup.h"
#include "opengles/load_png.h"
#include "opengles/gltexture2d.h"
#include "opengles/draw_subfunc.h"
#include "directfb/directfb_setup.h"
#endif

/*--- Function Prototype ---*/
#ifndef __arm__
bool SDLInit(void);
int  OpenGLInit(void);
void OpenGLGetStatus(void);
int  resizeWindow(int width, int height);
void handleKeyPress(SDL_Keysym *keysym);
#endif
bool SDLMixerInit(void);
int  Load_Texture(void);
bool load_music_file(void);
void tasksystem_init_cb(void);
double GetFrameDeltaTime(void);
double GetFrameDeltaTime(unsigned long long _previous,unsigned long long _now);
unsigned long long getNowTime(void);
void PrintFPS(void);
void Quit(int returnCode);
int Sync_System_Time(void);
/*--------------------------*/

/*--- Global Parameters ---*/
SDL_Window *mainwindow; /* Our window handle */
SDL_GLContext maincontext; /* Our opengl context handle */
SDL_Surface *surface;/**< This is our SDL surface */
int videoFlags;/**< Flags to pass to SDL_SetVideoMode */
SDL_Event event;/**< used to collect events */
//const SDL_VideoInfo *videoInfo;/**< this holds some info about our display */
KEYEVENT key_event;/**< Key board input event */
SERIALEVENT serial_event;/**< Serial port input event */
MTRANDOM mtRandom;/**< Mersenne Twister Random */
struct timeval current, prev;/**< current and previous time */
double t0, t1;/**< For computing frame delta time */

struct timeval fps_current, fps_prev;
unsigned long long fps_t0;
unsigned long long beforeTime;
unsigned long frameCount=0;
unsigned long drawCount=0;
unsigned long sleepTime=0;
unsigned long long nowTime;
unsigned long long progress;
unsigned long long previousTime;
//unsigned int id=5;/**< id */

GAMEALLSETTINGDATA ClientSideAllSettingData;/**< Client Side Game All Setting Data */

MAINPROCESSCONTENT mainProcessContent;/**< Main Process Content */

Mix_Music *music   = NULL;/**< The music that will be played */
Mix_Chunk *scratch = NULL;/**< The sound effects */
Mix_Chunk *high    = NULL;/**< The sound effects */
Mix_Chunk *med     = NULL;/**< The sound effects */
Mix_Chunk *low     = NULL;/**< The sound effects */
/*-------------------------*/

#ifndef __arm__
/**
 * @brief SDL x OpenGL Initialize.
 */
bool SDLInit(void){

	/* initialize SDL */
    if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ){
	    fprintf( stderr, "Video initialization failed: %s\n",SDL_GetError() );
	    return false;
	}

    /* Fetch the video info */
    //videoInfo = SDL_GetVideoInfo();

    //if ( !videoInfo ){
	    //fprintf( stderr, "Video query failed: %s\n",SDL_GetError() );
	    //return false;
	//}

	//Use OpenGL 2.1
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

    /* Create our window centered at 512x512 resolution */
    mainwindow = SDL_CreateWindow("CrownTrain_Srv", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
           1024, 768, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!mainwindow) /* Die if creation failed */{
        printf("Unable to create window");
        return false;
    }



    /* the flags to pass to SDL_SetVideoMode */
    //videoFlags  = SDL_OPENGL;          /* Enable OpenGL in SDL */
    //videoFlags |= SDL_GL_DOUBLEBUFFER; /* Enable double buffering */
    //videoFlags |= SDL_HWPALETTE;       /* Store the palette in hardware */
    //videoFlags |= SDL_RESIZABLE;       /* Enable window resizing */

    /* This checks to see if surfaces can be stored in memory */
    //if ( videoInfo->hw_available )
	//videoFlags |= SDL_HWSURFACE;
    //else
	//videoFlags |= SDL_SWSURFACE;

    /* This checks if hardware blits can be done */
    //if ( videoInfo->blit_hw )
    	//videoFlags |= SDL_HWACCEL;

    //checkSDLError(__LINE__);

    /* Create our opengl context and attach it to our window */
    maincontext = SDL_GL_CreateContext(mainwindow);
	if( maincontext == NULL )
	{
		printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
    //checkSDLError(__LINE__);

    /* This makes our buffer swap syncronized with the monitor's vertical refresh */
    SDL_GL_SetSwapInterval(1);

    /* Sets up OpenGL double buffering */
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    /* get a SDL surface */
    //surface = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,videoFlags );

    /* Verify there is a surface */
    //if ( !surface ){
	    //fprintf( stderr,  "Video mode set failed: %s\n", SDL_GetError() );
	    //return false;
	//}

    //Set the window caption
    //SDL_WM_SetCaption( "CrownTrain_Srv", NULL );
    SDL_SetWindowTitle( mainwindow,"CrownTrain_Srv");

    //Set the cursor display disable
    SDL_ShowCursor(SDL_DISABLE);

    return true;
}

/**
 * @brief general OpenGL initialization function.
 * @retval Success or Failure
 */
int OpenGLInit(void){

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /* Enable smooth shading */
    glShadeModel( GL_SMOOTH );

    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 1.0f, 0.0f );

    /* Depth buffer setup */
    //glClearDepth( 1.0f );

    /* Enables Depth Testing */
    //glEnable( GL_DEPTH_TEST );

    /* The Type Of Depth Test To Do */
    //glDepthFunc( GL_LEQUAL );

    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );

    return( true );
}

/**
 * @brief Get OpenGL Status.
 */
void OpenGLGetStatus(void){

	GLint texture_max_size;
    GLint texture_max_units;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE,&texture_max_size);
    printf( "==GL_MAX_TEXTURE_SIZE=%d= \n",texture_max_size);
    glGetIntegerv(GL_MAX_TEXTURE_UNITS,&texture_max_units);
    printf( "==GL_MAX_TEXTURE_UNITS=%d=\n",texture_max_units);
}

/**
 * @brief function to reset our viewport after a window resize.
 * @retval Success or Failure
 */
int resizeWindow(int width, int height){
    /* Height / width ration */
#ifdef USE_3D_PERSPECTIVE
	GLfloat ratio;
#endif

    /* Protect against a divide by zero */
    if ( height == 0 )
	height = 1;

#ifdef USE_3D_PERSPECTIVE
    ratio = ( GLfloat )width / ( GLfloat )height;
#endif

    /* Setup our viewport. */
    glViewport( 0, 0, ( GLsizei )width, ( GLsizei )height );

    /* change to the projection matrix and set our viewing volume. */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    /* Set our perspective */
#ifdef USE_3D_PERSPECTIVE
    gluPerspective( 45.0f, ratio, 0.1f, 100.0f );
	gluLookAt(0,0,3, 0,0,-5, 0,1,0);
#else
    gluOrtho2D(-0.999f, 0.999f, -0.999f, 0.999f);
    //gluOrtho2D(-1.1, 1.1, -1.1, 1.1);
#endif

    /* Make sure we're chaning the model view and not the projection */
    glMatrixMode( GL_MODELVIEW );

    /* Reset The View */
    glLoadIdentity( );

    return( true );
}

/**
 * @brief function to handle key press events.
 * @param SDL Key Symbol
 */
void handleKeyPress(SDL_Keysym *keysym){

	switch ( keysym->sym )
	{
	case SDLK_ESCAPE:
	    /* ESC key was pressed */
	    Quit( 0 );
	    break;
	case SDLK_F1:
	    /* F1 key was pressed
	     * this toggles fullscreen mode
	     */
	    //SDL_WM_ToggleFullScreen( surface );
	    break;
#ifdef ENABLE_KEYBOARD_INPUT
	/* 開始鍵(全停鍵,得分鍵) */
	case SDLK_RETURN:
		   key_event.button = KEY_EVT_START;
		   break;
	/* 押注鍵(押1分) */
	case SDLK_c:
		   key_event.button = KEY_EVT_BET_1;
		   break;
	/* 押注鍵(押8條線) */
	case SDLK_v:
		   key_event.button = KEY_EVT_BET_LINE;
		   break;
	/* 最大押注鍵 */
	case SDLK_b:
		   key_event.button = KEY_EVT_BET_MAX;
		   break;
    /* 自動鍵 */
	case SDLK_q:
		   key_event.button = KEY_EVT_AUTO;
		   break;
    /* 說明鍵 */
	case SDLK_h:
		   key_event.button = KEY_EVT_HELP;
		   break;
    /* 停一鍵(半比倍鍵,左移鍵) */
	case SDLK_a:
		   key_event.button = KEY_EVT_STOP_1;
		   break;
    /* 停二鍵(比倍鍵) */
	case SDLK_s:
		   key_event.button = KEY_EVT_STOP_2;
		   break;
    /* 停三鍵(雙比倍鍵,右移鍵) */
	case SDLK_d:
		   key_event.button = KEY_EVT_STOP_3;
		   break;
	/* 上分鍵 */
	case SDLK_i:
		   key_event.button = KEY_EVT_OPENCREDIT;
		   break;
	/* 下分鍵 */
	case SDLK_o:
		   key_event.button = KEY_EVT_CLEARCREDIT;
		   break;
	/* 退幣鍵 */
	case SDLK_p:
		   key_event.button = KEY_EVT_PAY;
		   break;
    /* 測試鍵(設定鍵) */
	case SDLK_F11:
		   key_event.button = KEY_EVT_TEST;
		   break;
	/* 查帳鍵 */
	case SDLK_F12:
		   key_event.button = KEY_EVT_ACCOUNT;
		   break;
#endif
	default:
	    break;
	}

    return;
}
#endif

/**
 * @brief SDL_Mixer Initialize.
 * @retval Success or Failure
 *
 */
bool SDLMixerInit(void){

#if 0
    int ret = Mix_Init(MIX_INIT_OGG);
    if((ret & MIX_INIT_OGG) != MIX_INIT_OGG){
        perror("failed to initialize OGG module.");
        return false;
    }
#endif

    // initialize SDL_mixer
#ifndef __arm__
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
#else
    if( Mix_OpenAudio( 11025, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
#endif
    {
        fprintf(stderr, "Mix_OpenAudio: %s\n", Mix_GetError());
    	return false;
    }

	return true;
}

/**
 * @brief Load OpenGL Texture.
 * @retval Success or Failure
 */
int Load_Texture(void){

    //Load Textures
	create_png_texture("./res/font.png", &fixed_font);
	//Set up sprite sheet parameters
	sheet_font.SetSpriteSheetObjParas(&fixed_font,0,0,512,512);

	return 0;
}

/**
 * @brief Load the music files.
 * @retval true : success false : failure
 */
bool load_music_file(void){

	//Load the music
    music = Mix_LoadMUS( "effect/reel_spin.wav" );

    //If there was a problem loading the music
    if( music == NULL )
    {
        return false;
    }

    //Load the sound effects
    scratch = Mix_LoadWAV( "effect/scratch.wav" );
    high = Mix_LoadWAV( "effect/high.wav" );
    med = Mix_LoadWAV( "effect/medium.wav" );
    low = Mix_LoadWAV( "effect/low.wav" );

    //If there was a problem loading the sound effects
    if( ( scratch == NULL ) || ( high == NULL ) || ( med == NULL ) || ( low == NULL ) )
    {
        return false;
    }

    return true;
}

/**
 * @brief TaskSystem startup call back function.
 */
void tasksystem_init_cb(void){

	new(TP_ClientSideSettingDataController) ClientSideSettingDataController(&ClientSideAllSettingData);
	new(TP_ServerMainProcess)               ServerMainProcess(&mainProcessContent);
	new(TP_ServerClientIDChecker)           ServerClientIDChecker();
	new(TP_ServerClientSettingValueChecker) ServerClientSettingValueChecker();
	new(TP_ServerClientPlayDataPreChecker)  ServerClientPlayDataPreChecker();
	new(TP_ServerClientPlayDataChecker)     ServerClientPlayDataChecker();
	new(TP_ServerClientGameStatusChecker)   ServerClientGameStatusChecker();

    new(TP_ServerJackpotValueSender)        ServerJackpotValueSender();
	new(TP_ClientConnectStatusDraw)         ClientConnectStatusDraw();

	//new(TP_ConnectTest)                 ConnectTest();
	//new(TP_GamerecTest)                 GamerecTest();
	//new(TP_ProbabilityControlTest)      ProbabilityControlTest();
}

/**
 * @brief Get frame delta time.
 * @retval frame delta time
 *
 */
double GetFrameDeltaTime(void){

	double ElapsedTime;

	/* Compute Frame Time */
    gettimeofday(&current, NULL);
    t0 = current.tv_sec * SECOND + current.tv_usec;
    t1 = prev.tv_sec * SECOND + prev.tv_usec;
    prev.tv_sec = current.tv_sec;
    prev.tv_usec = current.tv_usec;
    ElapsedTime = (double)((t0-t1)/1000.0);
#ifdef _DEBUG
	//printf("ElapsedTime: %f \n",ElapsedTime);
#endif
    return (ElapsedTime > 0 ) ? ElapsedTime : 0;
}

/**
 * @brief Get Frame Delta Time.
 * @param _previous previous time
 * @param _now now time
 * @retval frame delta time
 */
double GetFrameDeltaTime(unsigned long long _previous,unsigned long long _now){

#ifdef _DEBUG
    if(_previous >= _now){
    	cout << "_previous : " << _previous << " " << "_now : " << _now << endl;
    }
#endif

#if 0
	return (_now > _previous ? ((double)_now-(double)_previous) / (double)1000 :
		   ((double)1000000 - (double)_previous + (double)_now + 500)/(double)1000);
#endif
	return ((double)_now-(double)_previous) / (double)1000;
}

/**
 * @brief Get Now Time.
 * @retval Now Time
 */
unsigned long long getNowTime(void){

	/* Compute Frame Time */
    gettimeofday(&fps_current, NULL);
    fps_t0 = (unsigned long long)fps_current.tv_sec * SECOND + fps_current.tv_usec;

#ifdef _DEBUG
	//printf("Now Time: %lu \n",fps_t0);
#endif
    return fps_t0;
}

/**
 * @brief Print FPS.
 */
void PrintFPS(void){
	/* These are to calculate our fps */
	static GLint T0     = 0;
	static GLint Frames = 0;

	/* Gather our frames per second */
    Frames++;
	GLint t = SDL_GetTicks();
	if (t - T0 >= 5000) {
	    GLfloat seconds = (t - T0) / 1000.0;
	    GLfloat fps = Frames / seconds;
	    printf("%d frames in %g seconds = %g FPS\n", Frames, seconds, fps);
	    T0 = t;
	    Frames = 0;
	}
}

/**
 * @brief function to release/destroy our resources and restoring the old desktop.
 *
 */
void Quit(int returnCode){

#ifdef __arm__
	DeleteEGL();
	#ifdef USE_DIRECTFB_INPUT_MODULE
	keybuffer->Release(keybuffer);
	dfb->Release(dfb);
	#endif
#endif

    //Free the sound effects
    Mix_FreeChunk( scratch );
    Mix_FreeChunk( high );
    Mix_FreeChunk( med );
    Mix_FreeChunk( low );

    //Free the music
    Mix_FreeMusic( music );

    //Quit SDL_mixer
    Mix_CloseAudio();

	/* clean up the window */
    SDL_Quit();

    /* and exit appropriately */
    exit( returnCode );
}

/**
 * @brief Synchronize System Time With RTC.
 * @retval 0:Success else:Failure
 */
int Sync_System_Time(void){

	int rtc_fd;/**< File Descriptor of RTC device */
	int ioctl_ret;/**< ioctl() return value */
	time_t t;/**< time_t */
	struct rtc_time rtcTime;/**< RTC Time Structure */
	struct tm tm;/**< Time Structure */

	/* Open RTC Device */
	rtc_fd = open("/dev/rtc", O_RDWR);/**< Open RTC device "/dev/rtc" */
	if(rtc_fd < 0){/**< Check rtc_fd */
		printf("###ERROR:Open RTC Device Failed \n");
		close(rtc_fd);/**< Close RTC Device */
		return rtc_fd;
	}

	/* Load Time From RTC Hardware */
	ioctl_ret = ioctl(rtc_fd,RTC_RD_TIME,&rtcTime);/**< Get Time From RTC Hardware */
	if(ioctl_ret < 0){/**< Check ioctl() return value */
		printf("###ERROR:ioctl() \n");
		close(rtc_fd);/**< Close RTC Device */
		return ioctl_ret;
	}

	close(rtc_fd);/**< Close RTC Device */

	/* Save time to tm */
    tm.tm_year = rtcTime.tm_year;/**< Year */
    tm.tm_mon  = rtcTime.tm_mon; /**< Month */
    tm.tm_mday = rtcTime.tm_mday;/**< Day */
    tm.tm_hour = rtcTime.tm_hour;/**< Hour */
    tm.tm_min  = rtcTime.tm_min; /**< Minute */
    tm.tm_sec  = rtcTime.tm_sec; /**< Second */

    /* Write RTC time to system time */
    t = mktime(&tm);/**< change tm to time_t */
    stime(&t);

	return EXIT_SUCCESS;
}

#endif /* MAIN_H_ */
