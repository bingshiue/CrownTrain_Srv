/*
 * @file directfb_setup.h
 * @brief directfb setup functions.
 */

#ifndef DIRECTFB_SETUP_H_
#define DIRECTFB_SETUP_H_

#include "../preprocessor.h"
#include "../commDefine.h"

#ifdef USE_DIRECTFB_INPUT_MODULE

/* function prototype */
void directfb_setup(int argc,char** argv);

/* DirectFB Instance */
IDirectFB* dfb = NULL;/**< DirectFB Interface */
IDirectFBEventBuffer* keybuffer = NULL;/**< DirectFB Event Buffer Interface */
DFBInputEvent evt;/**< DirectFB Input Event */

/**
 * @brief Setup directFB.
 */
void directfb_setup(int argc,char** argv){

	/* Initialize */
	DFBCHECK(DirectFBInit(&argc,&argv));
	DFBCHECK(DirectFBCreate(&dfb));
    /* create an input buffer for key events */
    DFBCHECK(dfb->CreateInputEventBuffer( dfb, DICAPS_KEYS, DFB_FALSE, &keybuffer ));
    DFBCHECK(dfb->SetCooperativeLevel(dfb,DFSCL_FULLSCREEN));
}

#endif

#endif /* DIRECTFB_SETUP_H_ */
