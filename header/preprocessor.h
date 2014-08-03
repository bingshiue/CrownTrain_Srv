/*
 * @file preprocessor.h
 *
 */

#ifndef PREPROCESSOR_H_
#define PREPROCESSOR_H_

//#ifndef __arm__
#define FPS_CONTROL/**< FPS Control */
//#endif

#define USE_3D_PERSPECTIVE/**< Use 3D Perspective */

#define ENABLE_DRAW_12_H/**< Enable draw 1.2 height */

#define ENABLE_KEYBOARD_INPUT/**< Enable keyboard input */

#ifdef __arm__
#define USE_DIRECTFB_INPUT_MODULE/**< Use directFB input module */
#define ENABLE_SYNC_SYSCLK_ONBOOT/**< Enable synchronize system time with RTC time on boot */
#endif

#define USE_OPENGL/**< Use OpenGL */

//#define SERIALPORT_READ_METHOD_EPOLL
#define SERIALPORT_READ_METHOD_SELECT
#define SERIALPORT_USE_AES

#endif /* PREPROCESSOR_H_ */
