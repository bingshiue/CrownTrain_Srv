/*
 * @file TaskSystemUtility.h
 * @brief TaskSystem Utility Macro.
 *
 */

#ifndef TASKSYSTEMUTILITY_H_
#define TASKSYSTEMUTILITY_H_


#define TaskDuplicateCheck(sourceTask,taskName,taskID,taskPriority,constructorParameters...)      \
{                                                                                                 \
    if(sourceTask->GetTask(taskID,0)==NULL)                                                       \
    {                                                                                             \
       new(taskPriority) taskName(constructorParameters);	                                      \
    }                                                                                             \
    else                                                                                          \
    {                                                                                             \
       fprintf(stderr,"##Create Duplicate Task => File : %s, Line : %d \n",__FILE__,__LINE__);    \
    }                                                                                             \
}/**< Task Duplicate Check */


#define TaskExistCheck(destination,sourceTask,taskName,taskID)                                    \
{                                                                                                 \
	void* addr=sourceTask->GetTask(taskID,0);                                                     \
    if(addr==NULL)                                                                                \
    {                                                                                             \
    	fprintf(stderr,"##Task Not Exist => File : %s, Line : %d \n",__FILE__,__LINE__);          \
    }                                                                                             \
    else                                                                                          \
    {                                                                                             \
        destination = (taskName*)addr;                                                            \
    }                                                                                             \
}/**< Task Exist Check */

#endif /* TASKSYSTEMUTILITY_H_ */
