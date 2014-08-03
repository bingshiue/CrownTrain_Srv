/**
 * @file commDefine.h
 * @brief common define header file.
 *
 */

#ifndef COMMDEFINE_H_
#define COMMDEFINE_H_

#ifdef __arm__
#include <directfb.h>
#endif

#define SECOND 1000000.0/**< One second (Micro Second) */

#define SCREEN_WIDTH  1024.0f/**< Screen Width */
#define SCREEN_HEIGHT  768.0f/**< Screen Height */
#define SCREEN_BPP      32/**< Screen BPP */

#define HALF_SCREEN_WIDTH   SCREEN_WIDTH/2.0f/**< Half Screen Width */
#define HALF_SCREEN_HEIGHT  SCREEN_HEIGHT/2.0f/**< Half Screen Height */

#ifdef __arm__
#define MAX_FPS 30.0f
#else
#define MAX_FPS 60.0f
#endif

#ifdef __arm__

// for GLfixed type
#define glF(x)  ((GLfixed)((x)*(1<<16)))
#define RGB16(red, green, blue) ( ((red >> 3) << 11) | ((green >> 2) << 5) | (blue >> 3) )
#define PI 3.1415926535897932f

#define DFBCHECK(x...)                                         \
{                                                               \
    DFBResult err = x;                                          \
                                                                \
    if (err != DFB_OK)                                          \
    {                                                           \
        fprintf( stderr, "%s <%d>:\n\t", __FILE__, __LINE__ );  \
        DirectFBErrorFatal( #x, err );                          \
    }                                                           \
}/**< DirectFB Error Check */

#endif

#define GETY(Y) (Y*1.333 + 1)

#endif /* COMMDEFINE_H_ */
