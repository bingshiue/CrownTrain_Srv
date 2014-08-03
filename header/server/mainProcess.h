/**
 * @file mainProcess.h
 *
 */

#ifndef MAINPROCESS_H_
#define MAINPROCESS_H_

enum MainProcessStep{
	main_process_step_StandBy = 0,
};


typedef struct MainProcessContent{
	unsigned int m_step;/**< Step */
	unsigned int m_subStep;/**< Sub Step */

	unsigned int m_jackpot1Value;/**< JACKPOT 1 Value */
	unsigned int m_jackpot2Value;/**< JACKPOT 2 Value */
	unsigned int m_jackpot3Value;/**< JACKPOT 3 Value */

    /**
     * @brief Constructor.
     */
	MainProcessContent(void){
		this->m_step    = main_process_step_StandBy;
		this->m_subStep = 0;

		this->m_jackpot1Value = 0;
		this->m_jackpot2Value = 0;
		this->m_jackpot3Value = 0;
	}

}MAINPROCESSCONTENT;


#endif /* MAINPROCESS_H_ */
