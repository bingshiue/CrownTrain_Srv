/*
 * @file tcpip_protocol_def.h
 * @brief define TCP/IP communication command
 *
 */

#ifndef PROTOCOL_DEF_H_
#define PROTOCOL_DEF_H_

/* Define Group Command ID */
#define TCP_GID_CONN                    0x01/**< Connection Command Group */
#define TCP_GID_GAMESTAT                0x02/**< Game Status Command Group */
#define TCP_GID_GAMEREC                 0x03/**< Game Record Command Group */
#define TCP_GID_SETTING                 0x04/**< Game Setting Command Group */
#define TCP_GID_PROBABILITY             0x05/**< Probability Command Group */
#define TCP_GID_CREDIT                  0x06/**< Credit Command Group */
#define TCP_GID_ERROR                   0x07/**< Error Command Group */
#define TCP_GID_SPBONUS                 0x08/**< Special Bonus Command Group */
#define TCP_GID_JACKPOT                 0x09/**< Jackpot Command Group */
/* */

/* Define Command ID */
// Group TCP_GID_CONN
#define CMDID_CONN_REQUEST_ID           0x01/**< Request Client ID */
#define CMDID_CONN_CLIENT_ALIVE         0x02/**< Check Client Alive */
#define CMDID_CONN_CHANGE_ID            0x03/**< Client Change ID */

// Group TCP_GID_STAT
#define CMDID_GAMESTAT_REQUEST          0x01/**< 主機向分機查詢分機執行狀態 */

// Group TCP_GID_GAMEREC
#define CMDID_GAMEREC_SECTIONREC        0x01/**< 主機向分機查詢大局執行資料 */
#define CMDID_GAMEREC_ALLREC            0x02/**< 主機向分機查詢ALL紀錄資料 */
#define CMDID_GAMEREC_CURRENTREC        0x03/**< 主機向分機查詢當期紀錄資料 */
#define CMDID_GAMEREC_PREVIOUSREC       0x04/**< 主機向分機查詢前期紀錄資料 */
#define CMDID_GAMEREC_SURVEY            0x05/**<  */
#define CMDID_GAMEREC_SYNC              0x06/**<  */

// Group TCP_GID_SETTING
#define CMDID_SETTING_SURVEY            0x01/**< Survey Game Setting Value */

// Group TCP_GID_PROBABILITY
#define CMDID_PROBABILITY_CTRL          0x01/**< 主機命令分機執行特定遊戲起伏及籤筒 */

// Group TCP_GID_CREDIT
#define CMDID_CREDIT_OPEN               0x01/**< 主機命令分機開指定枚數分數 */
#define CMDID_CREDIT_CLEAR              0x02/**< 主機命令分機洗分 */
#define CMDID_CREDIT_CHECK              0x03/**< 主機向分機查詢目前分機的Credit及主機命令的開洗分紀錄枚數 */

// Group TCP_GID_ERROR
#define CMDID_ERROR_ID                  0x01/**< Notify Client ID Error */
#define CMDID_ERROR_COINSET             0x02/**< Notify Client Coin Set Error */
#define CMDID_ERROR_LOCK                0x03/**< Notify Client Coin Lock Game */

// Group TCP_GID_SPBONUS
#define CMDID_SPBONUS_OPEN_KIND         0x01/**< 主機通知分機開出Special Bonus */
#define CMDID_SPBONUS_OPEN_CHECK        0x02/**< 主機向分機確認是否已開出指定的SP Bonus */
#define CMDID_SPBONUS_CANCEL            0x03/**< 主機取消開獎(Special Bonus) */

// Group TCP_GID_JACKPOT
#define CMDID_JACKPOT_STANDBY_CHECK     0x01/**< 主機命令分機進入待機模式 */
#define CMDID_JACKPOT_OPEN_KIND         0x02/**< 主機通知分機開幾號彩金 */
#define CMDID_JACKPOT_OPEN_CHECK        0x03/**< 主機向分機確認是否已開出指定的Jackpot */
#define CMDID_JACKPOT_CANCEL            0x04/**< 主機取消Jackpot開獎 */
#define CMDID_JACKPOT_RANDOM            0x05/**< 主機向分機傳送所要開出的Jackpot值 */
/* */

#endif /* PROTOCOL_DEF_H_ */
