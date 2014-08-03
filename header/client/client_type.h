/**
 * @file client_type.h
 * @brief define client's information data structure
 */
#ifndef CLIENT_DATA_H_
#define CLIENT_DATA_H_

#include <list>
#include <netdb.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include "../probability/probabilityEnum.h"
#include "../game/gameRecordType.h"
#include "../game/gameEnum.h"
#include "../game/gameDefine.h"
#include "../game/gameSettingType.h"
#include "../commEnum.h"

/**
 * @brief Client Probability Status.
 */
typedef struct ClientProbabilityStatus {

	unsigned char _clientProbabilitySet;/**< client probability set value */
	unsigned char _clientGameLevel;/**< client game level */
	unsigned char _clientLotStatus;/**< client lot status */
	/**
	 * @brief constructor.
	 */
	ClientProbabilityStatus() {
		_clientProbabilitySet = 90;
		_clientGameLevel = game_level_middle;
		_clientLotStatus = game_lot_normal;
	}
} CLIENTPROBABILITYSTATUS;

/**
 * @brief Client Game Run Status.
 */
typedef struct ClientGameRunStatus {

	unsigned char m_isIdleFlag;/**< Is Idle Flag */
	unsigned char m_runningMode;/**< Running Mode */
	CLIENTPROBABILITYSTATUS m_clientProbabilityStatus;/**< Client Probability Status */

	/**
	 * @brief Constructor.
	 */
	ClientGameRunStatus(void){
		this->m_isIdleFlag = false;
		this->m_runningMode = 0;
	}

} CLIENTGAMERUNSTATUS;


typedef struct ClientPlayData {
	GAMEPLAYRECORD m_all_time_record;/**< All Time Record */
	GAMEPLAYRECORD m_current_term_record;/**< Current Term Record */
	GAMEPLAYRECORD m_section_record;/**< Section Record */

	GAMEALLSETTINGDATA m_gameAllSettingData;/**< Game All Setting Data */

	CLIENTGAMERUNSTATUS m_clientGameRunStatus;/**< Client Game Run Status */

	ClientPlayData(void) {
		//printf("Sizeof GAMEPLAYRECORD is : %d \n", sizeof(GAMEPLAYRECORD)); //660
		//printf("Sizeof GAMEALLSETTINGDATA is : %d \n", sizeof(GAMEALLSETTINGDATA)); //220
	}

} CLIENTPLAYDATA;

/**
 * @brief information of each client connection.
 */
typedef struct ClientData {
	bool m_idCheckSuccess;/**< ID check success */
	bool m_settingValueCheckSuccess;/**< Setting Value check success */
	bool m_playDataCheckSuccess;/**< Play Data check success */
	unsigned int client_id;/**< client's ID */
	unsigned int previousClientID;/**< Previous Client ID */

	evutil_socket_t client_fd;/**< client's file descriptor */
	bufferevent *bev;/**< client's bufferevent */
	struct sockaddr* clientSockaddr;/**< client's sockaddr */
	char hbuf[NI_MAXHOST]; /**< client's IP */
	char sbuf[NI_MAXSERV]; /**< client's PORT */
	/**
	 * @brief write data into hbuf.
	 * @param data source data
	 * @param size source data's size
	 */
	void setHbuf(char* data, size_t size) {
		for (size_t i = 0; i < size; i++) {
			this->hbuf[i] = data[i];
		}
	}
	/**
	 * @brief write data into sbuf.
	 * @param data source data
	 * @param size source data's size
	 */
	void setSbuf(char* data, size_t size) {
		for (size_t i = 0; i < size; i++) {
			this->sbuf[i] = data[i];
		}
	}

	/**
	 * @brief Client Play Data.
	 */
	CLIENTPLAYDATA* clientPlayData;

	/**
	 * @brief Constructor.
	 */
	ClientData(void) {
		client_id = 0;
		m_idCheckSuccess = false;
		m_settingValueCheckSuccess = false;
		m_playDataCheckSuccess = false;
		clientPlayData = NULL;
	}

	/**
	 * @brief Reset Connect Status Flags.
	 */
	void ResetConnectStatusFlags(void){
		this->m_idCheckSuccess = false;
		this->m_settingValueCheckSuccess = false;
		this->m_playDataCheckSuccess = false;
	}

	/**
	 * @brief Passed Validation or Not
	 * @retval true : passed false : not passed
	 */
	bool PassedValidationOrNot(void){
		return (this->m_idCheckSuccess && this->m_settingValueCheckSuccess && this->m_playDataCheckSuccess);
	}

} CLIENTDATA;

#endif /* CLIENT_DATA_H_ */
