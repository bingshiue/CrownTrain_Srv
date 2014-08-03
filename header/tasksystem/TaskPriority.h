/**
 * @file TaskPriority.h
 * @brief Define Task's Priority.
 *
 */

#ifndef TASKPRIORITY_H_
#define TASKPRIORITY_H_

#define TP_ClientSideSettingDataController      (0.01f)
#define TP_ServerClientIDChecker                (0.01f)
#define TP_ServerClientIDDuplicateNotifier      (0.02f)
#define TP_ServerClientSettingValueChecker      (0.02f)
#define TP_ServerClientPlayDataPreChecker       (0.02f)
#define TP_ServerClientPlayDataChecker          (0.02f)
#define TP_ServerClientPlayDataSync             (0.02f)
#define TP_ServerClientGameStatusChecker        (0.02f)
#define TP_ServerJackpotValueSender             (0.02f)
#define TP_ServerMainProcess                    (0.02f)
#define TP_ConnectTest                          (0.01f)
#define TP_GamerecTest                          (0.01f)
#define TP_ProbabilityControlTest               (0.01f)
#define TP_UARTSendTest                         (0.01f)
#define TP_ClientConnectStatusDraw              (0.5f)

#endif /* TASKPRIORITY_H_ */
