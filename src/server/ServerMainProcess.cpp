/**
 * @file MainProcess.cpp
 *
 */
#include "../../header/tasksystem/Task.h"

ServerMainProcess::ServerMainProcess(MAINPROCESSCONTENT* mainProcessContent){
	this->m_id = tid_ServerMainProcess;
	this->m_elapsedTimer = 0;
	this->m_mainProcessContent = mainProcessContent;
}

ServerMainProcess::~ServerMainProcess(void){

}

void ServerMainProcess::Draw(void){
	DrawFont(&sheet_font,256,32,32,20,font_align_none,0,GETY(-32),"Step: %d,SubStep: %d",this->getMainProcessStep(),this->getMainProcessSubStep());
}

int ServerMainProcess::Main(double elapsedTime){

	return 0;
}

MAINPROCESSCONTENT* ServerMainProcess::getMainProcess(void){
	return this->m_mainProcessContent;
}

unsigned int& ServerMainProcess::getMainProcessStep(void){
	return this->m_mainProcessContent->m_step;
}

unsigned int& ServerMainProcess::getMainProcessSubStep(void){
	return this->m_mainProcessContent->m_subStep;
}




