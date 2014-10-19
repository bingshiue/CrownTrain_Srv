/*
 * @file main.cpp
 * @brief main entry point.
 */

/* Include header file */
#include "../header/main.h"

/**
 * @brief Main Entry Point.
 * @param argc count of command line parameters
 * @param argv command line parameters
 * @retval 0: Exit successfully
 */
int main( int argc, char **argv )
{
#ifndef FPS_CONTROL
	/* Elapsed Time */
	double elapsedTime;
#endif

	/* main loop variable */
    bool done = false;

    static int total_bytes  = 0;// compute how many bytes we processed
    static int offset_index = 0;// offset index
    static SERIALRECVDATA recvTemp;

	/* check argc, if != 2(must input port number), exit */
	if(argc != 2){
		/* print usage */
		//printf("Usage : %s port \n",argv[0]);
		//exit(1);
	}else{
		/* get port number */
		port = atoi(argv[1]);

		/* port number is valid or not */
		if (port<=0 || port>65535) {
			puts("Invalid port");
			exit(1);
		}
	}

#ifdef ENABLE_SYNC_SYSCLK_ONBOOT
    /* Synchronize system time with RTC */
    Sync_System_Time();
#endif


#ifndef __arm__
    // Initial SDL x OpenGL
    if( SDLInit()==false ) Quit(1);

    // Initialize SDL_Mixer
    if( SDLMixerInit()==false ) return -1;

    // Load music file
    if( load_music_file()==false ) return -1;

    /* initialize OpenGL */
    OpenGLInit();

    /* resize the initial window */
    resizeWindow( SCREEN_WIDTH, SCREEN_HEIGHT );
#else
    // OpenGLES initial
	OpenGLESInit();
	// OpenGLES get status
    OpenGLESGetStatus();

	#ifdef USE_DIRECTFB_INPUT_MODULE
    // DirectFB initial
    directfb_setup(argc,argv);
	#endif

    // initial SDL audio system
    if( SDL_Init( SDL_INIT_AUDIO) == -1 ) return -1;
    int ret = Mix_Init(MIX_INIT_OGG);
    if((ret & MIX_INIT_OGG) != MIX_INIT_OGG){
        perror("failed to initialize OGG module.");
        exit(1);
    }
    // initialize SDL_mixer
    if( Mix_OpenAudio( 11025, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        fprintf(stderr, "Mix_OpenAudio: %s\n", Mix_GetError());
    	return false;
    }
    if( load_music_file()==false ) return -1;

#endif

	// Open serial port
	//Open_Serial_Port(UART_PORT,AES_Enable,&AESKey[0][0]);//Enable AES Cipher function
    OpenSerialPort();

	/* load textures */
	Load_Texture();

	/* initial Mersenne Twister random */
	srand((unsigned)time(NULL));
	mtRandom.resetMT(rand()%10000);//19650218UL);

	/* initial Task System */
	TaskEx::InitTaskList(tasksystem_init_cb);

	/* start server libevent thread */
	pthread_mutexattr_t libeventMutexAttr;
	pthread_mutexattr_init(&libeventMutexAttr);
	pthread_mutexattr_settype(&libeventMutexAttr, PTHREAD_MUTEX_ERRORCHECK);
	int type = -1;
	pthread_mutexattr_gettype(&libeventMutexAttr, &type);
	printf("!!! MutexAttr Type is : %d \n", type);

	pthread_mutex_init(&libevent_mutex, &libeventMutexAttr);
	pthread_mutexattr_destroy(&libeventMutexAttr);
	evthread_use_pthreads();
	pthread_create(&pth_libevent,NULL,start_server_libevent_loop,NULL);

	/* initial Mersenne Twister random */
	mtRandom.resetMT(rand()%10000);//19650218UL);

	/* get now time */
	gettimeofday(&prev, NULL);
	beforeTime = getNowTime();
	previousTime = beforeTime;//0;
	//previous_progress = 0;

    /* Infinite Loop */
    while ( !done )
	{
#ifndef __arm__
    	/* handle the events in the queue */
	    while ( SDL_PollEvent( &event ) )
		{
		    switch( event.type )
			{
			case SDL_WINDOWEVENT:
			    /* handle resize event */
			    //surface = SDL_SetVideoMode( event.resize.w,event.resize.h, 32, videoFlags );
			    //if ( !surface )
				//{
				    //fprintf( stderr, "Could not get a surface after resize: %s\n", SDL_GetError( ) );
				    //Quit( 1 );
				//}
			    //resizeWindow( event.resize.w, event.resize.h );
				switch( event.window.event ){
				case SDL_WINDOWEVENT_SIZE_CHANGED:
				case SDL_WINDOWEVENT_MAXIMIZED:
					resizeWindow( event.window.data1, event.window.data2 );
					break;
				}
			    break;
			case SDL_KEYDOWN:
			    /* handle key presses */
			    handleKeyPress( &event.key.keysym );
			    break;
			case SDL_QUIT:
			    /* handle quit requests */
			    done = true;
			    break;
			default:
			    break;
			}
		}
#else
		#ifdef USE_DIRECTFB_INPUT_MODULE
	    while (keybuffer->GetEvent(keybuffer,DFB_EVENT(&evt)) == DFB_OK) {
	         if (evt.type == DIET_KEYPRESS) {
	              switch(DFB_LOWER_CASE(evt.key_symbol)) {
                  case DIKS_ESCAPE:
					   /* quit main loop */
              		   done = true;
                       break;
				  #ifdef ENABLE_KEYBOARD_INPUT
                  /* 開始鍵(全停鍵,得分鍵) */
                  case DIKS_ENTER:
                	   key_event.button = KEY_EVT_START;
                	   break;
                  /* 押注鍵(押1分) */
                  case DIKS_SMALL_C:
                	   key_event.button = KEY_EVT_BET_1;
                	   break;
                  /* 押注鍵(押8條線) */
                  case DIKS_SMALL_V:
                	   key_event.button = KEY_EVT_BET_LINE;
                	   break;
                  /* 最大押注鍵 */
                  case DIKS_SMALL_B:
                	   key_event.button = KEY_EVT_BET_MAX;
                	   break;
                  /* 自動鍵 */
                  case DIKS_SMALL_Q:
                	   key_event.button = KEY_EVT_AUTO;
                	   break;
                  /* 說明鍵 */
                  case DIKS_SMALL_H:
                	   key_event.button = KEY_EVT_HELP;
                	   break;
                  /* 停一鍵(半比倍鍵,左移鍵) */
                  case DIKS_SMALL_A:
                	   key_event.button = KEY_EVT_STOP_1;
                	   break;
                  /* 停二鍵(比倍鍵) */
                  case DIKS_SMALL_S:
                	   key_event.button = KEY_EVT_STOP_2;
                	   break;
                  /* 停三鍵(雙比倍鍵,右移鍵) */
                  case DIKS_SMALL_D:
                	   key_event.button = KEY_EVT_STOP_3;
                	   break;
                  /* 退幣鍵 */
                  case DIKS_SMALL_P:
                	   key_event.button = KEY_EVT_PAY;
                	   break;
                  /* 上分鍵 */
                  case DIKS_SMALL_I:
                	   key_event.button = KEY_EVT_OPENCREDIT;
                	   break;
                  /* 下分鍵 */
                  case DIKS_SMALL_O:
                	   key_event.button = KEY_EVT_CLEARCREDIT;
                	   break;
                  /* 測試鍵(設定鍵) */
                  case DIKS_F11:
                	   key_event.button = KEY_EVT_TEST;
                	   break;
                  /* 查帳鍵 */
                  case DIKS_F12:
                	   key_event.button = KEY_EVT_ACCOUNT;
                	   break;
				  #endif
	                  default:
	                       break;
	              }
	         }
	    }
		#endif
#endif
	    /* process serial port event */
#ifdef SERIALPORT_READ_METHOD_EPOLL
        // Receive Serial Port Data
		nfds = epoll_wait(epollfd, events, 10, 1);
		if(nfds < 0){
			perror("epoll_wait");
		}else{
			for (int n = 0; n < nfds; n++) {
				if (events[n].data.fd == fd) {
					res = read(fd, recv, sizeof(recv)/sizeof(recv[0]));
					printf("Receive %d Bytes \n",res);
				}
			}
		}
#endif

#ifdef SERIALPORT_READ_METHOD_SELECT

		memcpy(&fds,&readfds,sizeof(fd_set));
		SelectTimeOut.tv_sec  =    0;// seconds
		SelectTimeOut.tv_usec = 1000;// microseconds
		select_res = select(maxfd, &fds, NULL, NULL, &SelectTimeOut);
		if(select_res == -1){
			perror("select");
			exit(-1);
		}

		// Can read
		if(FD_ISSET(fd, &fds))
		{
			select_read_ret = read(fd,(uartRecvBuff.m_buff+uartRecvBuff.m_nextInputIndex), sizeof(uartRecvBuff.m_buff));
            // Debug
			printf("Receive %d Bytes \n",select_read_ret);
			//
			uartRecvBuff.m_totalDataBytes += select_read_ret;

			total_bytes  = 0; // compute how many bytes we processed
			offset_index = 0; // offset index
			uartRecvBuff.m_processedIndex = 0;

			while ((uartRecvBuff.m_processedIndex + 24) <= uartRecvBuff.m_totalDataBytes){

				if (recvTemp.isCRCOK(&(uartRecvBuff.m_buff[offset_index])) == true) {
#ifdef SERIALPORT_USE_AES
					// Copy 24 bytes from recvBuff to recvTemp.r_buffer
					for (int k = 0; k < 24; k++) {
						//recvTemp.r_buffer[k] = recvBuff[offset_index + k];
						recvTemp.r_buffer[k] = uartRecvBuff.m_buff[offset_index + k];
					}
					// Inverse AES
					unsigned char* plain; // plain data
					if(recvTemp.r_buffer[0]>=sizeof(AESKey)/sizeof(AESKey[0])) {recvTemp.r_buffer[0]=0;}
					plain = inv_aes(&recvTemp.r_buffer[1], AESKey[recvTemp.r_buffer[0]]);
					// Copy plain data to recvTemp.r_buffer
					for (int k = 0; k < 16; k++) {
						recvTemp.r_buffer[1 + k] = plain[k];
					}
#else
					// Copy 24 bytes from recvBuff to recvTemp.r_buffer
					for (int k = 0; k < 24; k++) {
						//recvTemp.r_buffer[k] = recvBuff[offset_index + k];
						recvTemp.r_buffer[k] = uartRecvBuff.m_buff[offset_index + k];
					}
#endif
					// Push into recvData
					recvData.push_back(recvTemp);
				} else {
#ifdef _DEBUG
					printf("UART CRC Check Failure !!! \n");
#endif
				}

				total_bytes += 24;
				offset_index += 24;
				uartRecvBuff.m_processedIndex += 24;

			};

			//Compute how many bytes remains
			uartRecvBuff.m_totalDataBytes -= uartRecvBuff.m_processedIndex;

			//Check Have Remain Data or Not
			if(uartRecvBuff.m_totalDataBytes > 0){
				//Move Remain Data To Front of Buff
				//memmove(uartRecvBuff.m_buff,&uartRecvBuff.m_buff[uartRecvBuff.m_processedIndex],uartRecvBuff.m_totalDataBytes);
				//uartRecvBuff.m_nextInputIndex = uartRecvBuff.m_totalDataBytes;
				uartRecvBuff.m_nextInputIndex = 0;
				uartRecvBuff.m_totalDataBytes = 0;
			}else{
			    uartRecvBuff.m_nextInputIndex = 0;
				uartRecvBuff.m_totalDataBytes = 0;
			}
		}

#endif

	    /* process serial port event */
		// Check how many data in recvData
		// If recvData has data
#ifdef _DEBUG
		//printf("recvData's size = %d \n",recvData.size());
#endif

		if(recvData.size() > 0){

				vector<SERIALRECVDATA>::iterator serialDataIt;

				for(serialDataIt=recvData.begin();serialDataIt!=recvData.end();serialDataIt++){
#ifdef _DEBUG
					for(int idx=0;idx<24;idx++){
						printf("recvData[%2d]=%2x \n",idx,serialDataIt->r_buffer[idx]);
					}
#endif
					//Get serial event
					getSerialEvent(serialDataIt,&serial_event);

					//Run Task
					TaskEx::SerialEventTask(&serial_event);
				}

				recvData.clear();
				serial_event._group = 0x00;
		}

	    /* process network event */
        if(networkData.size() > 0){
        	TCPMutexLock();
        	for(unsigned int i=0; i<networkData.size(); i++){
        		TaskEx::NetWorkEventTask(&networkData[i]);
        	}
        	networkData.clear();
        	TCPMutexUnlock();
        }

        /* process keyboard input event */
        TaskEx::KeyEventTask(&key_event);
        key_event._reset();

#ifdef FPS_CONTROL
        nowTime  = getNowTime();
        progress = nowTime - beforeTime;

		/* Task's Update */
#ifdef _DEBUG
        //if(previousTime >= nowTime){
        	//cout << "previousTime : " << previousTime << " " << "nowTime : " << nowTime << endl;;
        //}
#endif
        Task::RunTask(GetFrameDeltaTime(previousTime,nowTime));//progress));

        previousTime = nowTime;//progress;

        frameCount++;
        unsigned long long time = (unsigned long)(frameCount*1000000/MAX_FPS+500);

        if(progress < time){

			nowTime = getNowTime();
        	progress = nowTime - beforeTime;

        	if(progress < time){

        		drawCount++;

				/* draw the scene */
				/* Clear The Screen And The Depth Buffer */
#ifndef __arm__
				glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
#else
				glClear( GL_COLOR_BUFFER_BIT );
#endif

				/* Task's Draw*/
				TaskEx::DrawTask();

				/* Draw it to the screen */
#ifndef __arm__
				//SDL_GL_SwapBuffers( );
				/* Swap our back buffer to the front */
				SDL_GL_SwapWindow(mainwindow);
#else
				EGLFlush();
#endif

				nowTime = getNowTime();
	        	progress = nowTime - beforeTime;
#ifdef _DEBUG
	        	//cout<< "NowTime=" << nowTime << "BeforeTime=" << beforeTime << "Progress=" << progress << endl;
#endif
	        	if(progress < time){
	        		struct timespec ts;
	        		ts.tv_sec  = 0;
	        		ts.tv_nsec = (time - progress) * 1000;
	        		nanosleep(&ts,NULL);//time - progress);
#ifdef _DEBUG
	        	    //cout<< "Time=" << time << "Progress=" << progress << endl;
#endif
	        		sleepTime += time - progress;
	        		nowTime += time - progress;
	        		progress = time;
	        	}
        	}

        }

    	if(progress>=1000000)
    	{
#ifdef _DEBUG
    		//printf("FPS=%3lu DRAW=%3lu SLEEP=%3lu \n",frameCount,drawCount,sleepTime);
#endif
    		beforeTime=nowTime;
    		frameCount=0; drawCount=0; sleepTime=0;
    	}

#else
		/* Task's Update */
        elapsedTime = GetFrameDeltaTime();
        Task::RunTask(elapsedTime);

		/* draw the scene */
		/* Clear The Screen And The Depth Buffer */
#ifndef __arm__
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
#else
		glClear( GL_COLOR_BUFFER_BIT );
#endif

		/* Task's Draw*/
		TaskEx::DrawTask();

		/* Draw it to the screen */
#ifndef __arm__
		SDL_GL_SwapBuffers( );
#else
		EGLFlush();
#endif

#endif
		/* Print FPS */
		//PrintFPS();
	}

    /* clean ourselves up and exit */
    Quit( 0 );

    /* Should never get here */
    return( 0 );
}

