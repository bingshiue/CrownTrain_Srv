/**
 * @file Task.h
 * @brief Define task system class.
 */

#ifndef TASK_H_
#define TASK_H_

#include <vector>
#include <map>
#include <string>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/rtc.h>
#include <fcntl.h>
#include <assert.h>
#ifndef __arm__
#include <GL/gl.h>
#include <GL/glu.h>
#include "../opengl/gltexture2d.h"
#else
#include <GLES/gl.h>
#include <EGL/egl.h>
#include "../opengles/gltexture2d.h"
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "../preprocessor.h"
#include "TaskSystem.h"
#include "TaskSystemEx.h"
#include "TaskPriority.h"
#include "TaskSystemUtility.h"
#include "../protocol/tcpip_protocol_def.h"
#include "../protocol/uart_protocol_def.h"
#include "../common.h"
#include "../commDefine.h"
#include "../mersenne_twister/mt_random.h"
#include "../serial/serialDataType.h"
#include "../server/mainProcess.h"
#include "../client/client_type.h"
#include "../gameEvent.h"
#include "../textures_extern.h"

/* external parameters */
extern std::map<bufferevent*,CLIENTDATA> clientMap;
extern std::vector<NETWORKEVENT> networkData;
extern MTRANDOM mtRandom;;
extern SDL_Surface *surface;

extern Mix_Music *music;
extern Mix_Chunk *scratch;
extern Mix_Chunk *high;
extern Mix_Chunk *med;
extern Mix_Chunk *low;

extern SERIALSENDDATA transData;

extern CLIENTPLAYDATA clientPlayData[20];

extern unsigned int id;

/* external functions */
#ifndef __arm__
extern char* load_png(const char* name, int* width, int* height);
extern void  create_png_texture(const char *filename,GLTEXTURE2D* gltex2d);
extern void  create_png_texture_mem(PIXELS* pixels,GLTEXTURE2D* gltex2d,unsigned int _screen_width,unsigned int _screen_height);


extern void DrawSpriteSub(GLTEXTURE2D* gltex2d,int x,int y);
extern void DrawSpriteSub(GLTEXTURE2D* gltex2d,RECTANGLE clipRect,int x,int y);
extern void DrawSpriteSub(GLTEXTURE2D* gltex2d,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,unsigned int frame,int x,int y);
extern void DrawLongSpriteSub(GLTEXTURE2D* gltex2d,int EndX, int EndY, unsigned int Value, int WH, int H);
extern void DrawFont(GLTEXTURE2D* gltex2d,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,int WH,unsigned int alignType,int StartX, int StartY,const char*fmt,...);

extern void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int x,int y);
extern void DrawSpriteSubFixScalePosition(SPRITESHEETOBJECT* spriteSheetObj,int x,int y,bool FixScalePostion);
extern void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int x,int y,unsigned int alignType);
extern void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,RECTANGLE clipRect,int x,int y);
extern void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,unsigned int frame,int x,int y);
extern void DrawLongSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int EndX, int EndY, unsigned int Value, int WH, int H);
extern void DrawLongSpriteSubMiddle(SPRITESHEETOBJECT* spriteSheetObj,int EndX, int EndY, unsigned int Value, int WH, int H);
extern void DrawFont(SPRITESHEETOBJECT* spriteSheetObj,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,int WH,unsigned int alignType,int StartX, int StartY,const char*fmt,...);
extern void DrawLine(int x1,int y1,int x2,int y2,unsigned int lineWidth,COLOR color);
#else
extern char* load_png(const char* name, int* width, int* height);
extern void  create_png_texture(const char *filename,GLTEXTURE2D* gltex2d,unsigned int _screen_width=0,unsigned int _screen_height=0);
extern void  create_compressed_texture(const char *filename,GLTEXTURE2D* gltex2d,unsigned int _screen_width,unsigned int _screen_height);
extern void  create_png_texture_mem(PIXELS* pixels,GLTEXTURE2D* gltex2d,unsigned int _screen_width,unsigned int _screen_height);


extern void DrawSpriteSub(GLTEXTURE2D* gltex2d,int x,int y);
extern void DrawSpriteSub(GLTEXTURE2D* gltex2d,RECTANGLE clipRect,int clipScreenWidth,int clipScreenHeight,int x,int y);
extern void DrawSpriteSub(GLTEXTURE2D* gltex2d,int clipScreenWidth,int clipScreenHeight,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,unsigned int frame,int x,int y);
extern void DrawLongSpriteSub(GLTEXTURE2D* gltex2d,int clipScreenWidth,int clipScreenHeight,int EndX, int EndY, unsigned int Value, int WH, int H);
extern void DrawFont(GLTEXTURE2D* gltex2d,int clipScreenWidth,int clipScreenHeight,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,int WH,unsigned int alignType,int StartX, int StartY,const char*fmt,...);

extern void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int x,int y);
extern void DrawSpriteSubFixScalePosition(SPRITESHEETOBJECT* spriteSheetObj,int x,int y,bool FixScalePostion);
extern void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int x,int y,unsigned int alignType);
extern void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,RECTANGLE clipRect,int x,int y);
extern void DrawSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,unsigned int frame,int x,int y);
extern void DrawLongSpriteSub(SPRITESHEETOBJECT* spriteSheetObj,int EndX, int EndY, unsigned int Value, int WH, int H);
extern void DrawLongSpriteSubMiddle(SPRITESHEETOBJECT* spriteSheetObj,int EndX, int EndY, unsigned int Value, int WH, int H);
extern void DrawFont(SPRITESHEETOBJECT* spriteSheetObj,unsigned int totalFrame,unsigned int frameWidth,unsigned int frameHeight,int WH,unsigned int alignType,int StartX, int StartY,const char*fmt,...);
extern void DrawLine(int x1,int y1,int x2,int y2,unsigned int lineWidth,COLOR color);
#endif

//extern int  Send_Serial_Data(SERIALSENDDATA* _serialSendData);
extern int  SerialSendData(SERIALSENDDATA* _serialSendData);

/**
 * @brief ID of tasks
 */
enum TASKID{
	tid_ClientSideSettingDataController = 0,
	tid_ServerClientIDChecker,
	tid_ServerClientIDDuplicateNotifier,
	tid_ServerClientSettingValueChecker,
	tid_ServerClientPlayDataPreChecker,
	tid_ServerClientPlayDataChecker,
	tid_ServerClientPlayDataSync,
	tid_ServerClientGameStatusChecker,
	tid_ServerJackpotValueSender,
	tid_ServerMainProcess,
	tid_ConnectTest,
	tid_GamerecTest,
	tid_ProbabilityControlTest,
	tid_ClientConnectStatusDraw,
};

/**
 * @brief Client Side Setting Data Controller.
 */
class ClientSideSettingDataController : public TaskEx {
	double m_elapsedTimer;/**< for compute elapsed time */
	GAMEALLSETTINGDATA* m_clientSideGameAllSettingData;/**< Client Side Game All Setting Data */
public:
    /**
     * @brief Constructor.
     * @param clientSideGameAllSettingData Client Side Game All Setting Data
     */
	ClientSideSettingDataController(GAMEALLSETTINGDATA* clientSideGameAllSettingData);
	/**
	 * @brief Deconstructor.
	 */
    ~ClientSideSettingDataController(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
    /**
     * @brief Get Client Side Game All Setting Data.
     * @retval  Client Side Game All Setting Data
     */
    GAMEALLSETTINGDATA* getClientSideGameAllSettingData(void);
};

/**
 * @brief Server Client ID Checker.
 */
class ServerClientIDChecker : public TaskEx {
	double m_elapsedTimer;/**< for compute elapsed time */
	double m_idCheckerTimer;/**< for check ID */
	double m_aliveCheckTimer;/**< for check alive */
	int m_idOKClientCount;/**< ID OK Client Count */
public:
    /**
     * @brief Constructor.
     */
	ServerClientIDChecker(void);
	/**
	 * @brief Deconstructor.
	 */
    ~ServerClientIDChecker(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
    /**
     * @brief Network event process function.
     * @param nevent Network event
     */
    void NetworkMain(void* arg);
    /**
     * @brief Get ID OK Client Count.
     * @retval ID OK Client Count
     */
    int GetIDOKClientCount(void);
};

/**
 * @brief Server Client ID Duplicate Notifier.
 */
class ServerClientIDDuplicateNotifier : public TaskEx{
	double m_notifyTimer;/**< Notify Timer */
	bufferevent* m_bufferevent;/**< bufferevent */
public:
    /**
     * @brief Constructor.
     * @param bev bufferevent
     */
	ServerClientIDDuplicateNotifier(bufferevent* bev);
	/**
	 * @brief Deconstructor.
	 */
    ~ServerClientIDDuplicateNotifier(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
};

/**
 * @brief Server Client Setting Value Checker
 */
class ServerClientSettingValueChecker : public TaskEx {
	double m_elapsedTimer;/**< for compute elapsed time */
	double m_settingValueCheckTimer;/**< for check setting value */
public:
    /**
     * @brief Constructor.
     */
	ServerClientSettingValueChecker(void);
	/**
	 * @brief Deconstructor.
	 */
    ~ServerClientSettingValueChecker(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
    /**
     * @brief Network event process function.
     * @param nevent Network event
     */
    void NetworkMain(void* arg);
};

/**
 * @brief Server Client Play Data Pre Checker.
 */
class ServerClientPlayDataPreChecker : public TaskEx {
	double m_elapsedTimer;/**< for compute elapsed time */
	double m_playDataCheckTimer;/**< for check play data */
public:
    /**
     * @brief Constructor.
     */
	ServerClientPlayDataPreChecker(void);
	/**
	 * @brief Deconstructor.
	 */
    ~ServerClientPlayDataPreChecker(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
    /**
     * @brief Network event process function.
     * @param nevent Network event
     */
    void NetworkMain(void* arg);
};

/**
 * @brief Server Client Play Data Checker.
 */
class ServerClientPlayDataChecker : public TaskEx {
	double m_playDataCheckTimer;/**< for check play data */
public:
    /**
     * @brief Constructor.
     */
	ServerClientPlayDataChecker(void);
	/**
	 * @brief Deconstructor.
	 */
    ~ServerClientPlayDataChecker(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
    /**
     * @brief Network event process function.
     * @param nevent Network event
     */
    void NetworkMain(void* arg);
};

/**
 * @brief Server Client Play Data Sync.
 */
class ServerClientPlayDataSync : public TaskEx {
	double m_playDataSyncTimer;/**< Play Data Sync Timer */
	bufferevent* m_bufferevent;/**< bufferevent */
public:
    /**
     * @brief Constructor.
     * @param bev bufferevent
     */
	ServerClientPlayDataSync(bufferevent* bev);
	/**
	 * @brief Deconstructor.
	 */
    ~ServerClientPlayDataSync(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
    /**
     * @brief Network event process function.
     * @param nevent Network event
     */
    void NetworkMain(void* arg);
};

/**
 * @brief Server ClientGame Status Checker.
 */
class ServerClientGameStatusChecker : public TaskEx {
	double m_gameStatusCheckTimer;/**< Game Status Check Timer */
public:
    /**
     * @brief Constructor.
     */
	ServerClientGameStatusChecker(void);
	/**
	 * @brief Deconstructor.
	 */
    ~ServerClientGameStatusChecker(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
    /**
     * @brief Network event process function.
     * @param nevent Network event
     */
    void NetworkMain(void* arg);
};

/**
 * @brief for test connection only.
 */
class ConnectTest : public TaskEx {
	//GLTEXTURE2D bg;/**< Background */
	//GLTEXTURE2D fixed_font;/**< font */
	//GLTEXTURE2D fixed_font_2;/**< font 2 */
	//SPRITESHEETOBJECT sheet_font;/**< Sprite sheet font */
    double m_elapsedTimer;/**< for compute elapsed time */
    double m_aliveTimer;/**< for check client is alive */
    unsigned int idCheckOKClientCount;/**< ID Check OK Client Count */
public:
    /**
     * @brief Constructor.
     */
	ConnectTest(void);
	/**
	 * @brief Deconstructor.
	 */
    ~ConnectTest(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
    /**
     * @brief Network event process function.
     *
     * @param nevent Network event
     */
    void NetworkMain(void* arg);//NETWORKEVENT* nevent);
};

/**
 * @brief Game Record Control.
 */
class GamerecTest : public TaskEx{
	double m_elapsedTimer; /**< for compute elapsed time */
	double m_elapsedTimer2;/**< for compute elapsed time 2 */
	double m_elapsedTimer3;/**< for compute elapsed time 3 */
	double m_elapsedTimer4;/**< for compute elapsed time 4 */
public:
    /**
     * @brief Constructor.
     */
	GamerecTest(void);
	/**
	 * @brief Deconstructor.
	 */
    ~GamerecTest(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
    /**
     * @brief Network event process function.
     *
     * @param nevent Network event
     */
    void NetworkMain(void* arg);//NETWORKEVENT* nevent);
};

/**
 * @brief Probability Control
 */
class ProbabilityControlTest : public TaskEx {
	double m_elapsedTimer; /**< for compute elapsed time */
public:
    /**
     * @brief Constructor.
     */
	ProbabilityControlTest(void);
	/**
	 * @brief Deconstructor.
	 */
    ~ProbabilityControlTest(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
    /**
     * @brief Network event process function.
     *
     * @param nevent Network event
     */
    void NetworkMain(void* arg);//NETWORKEVENT* nevent);
};

/**
 * @brief Client Connect Status Draw.
 */
class ClientConnectStatusDraw : public TaskEx {
	double m_elapsedTimer;/**< for compute elapsed time */
public:
    /**
     * @brief Constructor.
     */
	ClientConnectStatusDraw(void);
	/**
	 * @brief Deconstructor.
	 */
    ~ClientConnectStatusDraw(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
};

/**
 * @brief Server Main Process.
 */
class ServerMainProcess : public TaskEx {
	double m_elapsedTimer;/**< for compute elapsed time */
	MAINPROCESSCONTENT* m_mainProcessContent;/**< Main Process */
public:
    /**
     * @brief Constructor.
     */
	ServerMainProcess(MAINPROCESSCONTENT* mainProcessContent);
	/**
	 * @brief Deconstructor.
	 */
    ~ServerMainProcess(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
    /**
     * @brief Get Main Process.
     * @retval Main Process
     */
    MAINPROCESSCONTENT* getMainProcess(void);
    /**
     * @brief Get Main Process Step.
     * @retval Main Process Step
     */
    unsigned int& getMainProcessStep(void);
    /**
     * @brief Get Main Process Sub Step.
     * @retval Main Process Sub Step
     */
    unsigned int& getMainProcessSubStep(void);
};

/**
 * @brief Server Jackpot Value Sender
 */
class ServerJackpotValueSender : public TaskEx {
	double m_sendTimer;/**< Send Timer */
public:
    /**
     * @brief Constructor.
     */
	ServerJackpotValueSender(void);
	/**
	 * @brief Deconstructor.
	 */
    ~ServerJackpotValueSender(void);
    /**
     * @brief Draw function.
     */
    void Draw(void);
    /**
     * @brief Main update function.
     *
     * @param elapsedTime elapsed time
     * @retval success or failure
     */
    int Main(double elapsedTime);
};

/**
 * @brief Utility class
 */
class Utility : public TaskEx {
public:
	static void UnsignedIntegerToByte(unsigned int value,unsigned char *dest);
	static unsigned int getUnsignedIntegerFromByte(unsigned char b1,unsigned char b2,unsigned char b3,unsigned char b4);
	static unsigned int getUnsignedIntegerFromAddr(unsigned char *addr);
	static bool CheckCodeCorrect(unsigned char* code,unsigned long totalIn,unsigned long totalOut,unsigned long totalPlayTimes,unsigned long randomCode,unsigned long machineID,unsigned long* settingValueArray);
	static int getRTCTime(RTCTIME* _rtcTime);// get RTC time
	static int setRTCTime(RTCTIME* _rtcTime);// set RTC time
	static void getValidateRemainTime(time_t now_time,time_t validate_time,unsigned int* day,unsigned int* hour,unsigned int* minute);
	static int getValidateStatus(void);
	int UARTSend(unsigned char group,unsigned char command,unsigned char action,unsigned char dataLength,unsigned char* data,size_t size);
};

#endif /* TASK_H_ */
