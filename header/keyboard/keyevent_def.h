/**
 * @file keyevent_def.h
 * @brief Define key board event.
 *
 */

#ifndef KEYEVENT_DEF_H_
#define KEYEVENT_DEF_H_

#define KEY_EVT_NONE         0x00/**< None */
#define KEY_EVT_START        0x60/**< 開始鍵(全停鍵,得分鍵) */
#define KEY_EVT_STOP_1       0x61/**< 停一鍵(半比倍鍵,左移鍵) */
#define KEY_EVT_STOP_2       0x62/**< 停二鍵(比倍鍵) */
#define KEY_EVT_STOP_3       0x63/**< 停三鍵(雙比倍鍵,右移鍵) */
#define KEY_EVT_BET_1        0x64/**< 押注鍵(押1分) */
#define KEY_EVT_BET_LINE     0x65/**< 押注鍵(押8條線) */
#define KEY_EVT_BET_MAX      0x66/**< 最大押注鍵 */
#define KEY_EVT_PAY          0x67/**< 退幣鍵 */
#define KEY_EVT_HELP         0x68/**< 說明鍵 */
#define KEY_EVT_AUTO         0x69/**< 自動鍵 */
#define KEY_EVT_OPENCREDIT   0x6a/**< 上分鍵 */
#define KEY_EVT_CLEARCREDIT  0x6b/**< 下分鍵 */
#define KEY_EVT_ACCOUNT      0x6c/**< 查帳鍵 */
#define KEY_EVT_TEST         0x6d/**< 測試鍵(設定鍵) */


#endif /* KEYEVENT_DEF_H_ */
