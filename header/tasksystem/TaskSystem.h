/**
 * @file     TaskSystem.h
 * @brief    Manage Memory System.
 *
 * @author   SHIE-BINGSHIUE
 * @date     2010/08/03
 */
#ifndef _TASKSYSTEM_H_
#define _TASKSYSTEM_H_

#include<stdio.h>
#include<malloc.h>		        // for malloc, free
#include<string.h>		        // for memset, memmove

typedef unsigned char BYTE;
typedef unsigned long DWORD;

#define TRUE  1
#define FALSE 0
/**
 * @brief Base Task Object.
 *
 * @author SHIE-BINGSHIUE
 * @date 2010-08-03
 */
class Task
{
	BYTE m_use;/**< TRUE using / FALSE not use */
	DWORD m_size;/**< count of byte */
	float m_priority;/**< priority */
	/**
	 * @brief Defrag TaskSystem's memory.
	 *
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	static void Defrag(void);
protected:
	static BYTE* m_active;/**< Pointer to first task in TaskSystem */
	static BYTE* m_free;/**< Pointer to begin address of free memory */
	Task* m_pre;/**< Pointer to previous task */
	Task* m_next;/**< Pointer to next task */
public:
	/**
	 * @brief virtual deconstructor.
	 *
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	virtual ~Task(void){}
	/**
	 * @brief Initial TaskSystem's task list.
	 *
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	static void InitTaskList(void);
	/**
	 * @brief Release TaskSystem's task list.
	 *
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	static void ReleaseTaskList(void);
	/**
	 * @brief Delete all other task in task list.
	 *
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	void Delete(void);
	/**
	 * @brief Run TaskSystem.
	 *
	 * @param elapsedTime Elapsed Time of each frame
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	static void RunTask(double elapsedTime);
	/**
	 * @brief Overload 'new' operator.
	 *
	 * @param priority Default Priority
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	void* operator new(size_t size,float priority=0.5f);
	/**
	 * @brief Overload 'delete' operator.
	 *
	 * @param pTask Task's address
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	void operator delete(void *pTask);
	/**
	 * @brief Set Task's Priority.
	 *
	 * @param priority New Priority
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	void SetPriority(float priority);
	/**
	 * @brief Get TaskSystem's size.
	 *
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	static DWORD GetSize(void);
	/**
	 * @brief Get count of tasks in TaskSystem.
	 *
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	static DWORD GetCount(void);
	/**
	 * @brief Dump TaskSystem's content.
	 *
	 * @filename File Name
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	static void Dump(const char *filename);
	/**
	 * @brief Main Process Function.
	 *
	 * @elapsedTime Elapsed Time of each frame
	 * @author SHIE-BINGSHIUE
	 * @date 2010-08-03
	 */
	virtual int Main(double elapsedTime)=0;
};


#endif
