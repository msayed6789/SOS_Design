
#include"sos.h"

Task_t SystemTasks[TASK_NUM]={
	/*Task#1*/
	{
		.periodicity=300,
		.TaskFunc=Func1,
		.Copy_u8Priority=0;
	},
	/*Task#2*/
	{
		.periodicity=500,
		.TaskFunc=Func2,
		.Copy_u8Priority=1;
	},
	/*Task#3*/
	{
		.periodicity=INVALID_TASK,
		.TaskFunc=INVALID_TASK,
		.Copy_u8Priority=INVALID_TASK;
	},
	/*Idle task*/
	{
		.periodicity=50,
		.TaskFunc=Idle_Func,
		.Copy_u8Priority=TASK_NUM-1;
	}
};
