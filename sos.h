#ifndef SOS_H_
#define SOS_H_
#include "../../utilises/timers/timers_services.h"

typedef enum
{
	SOS_STATUS_SUCCESS,
	SOS_STATUS_INVALID_STATE
}enu_system_status_t;


typedef enum
{
	CREATE_TASK_SUCCESS,
	CHANGE_PRIORITY
}enu_creat_task_status_t;

typedef enum
{
	DELETE_TASK_SUCCESS,
	DELETE_TASK_UNSUCCESS
}enu_delete_task_status_t;

typedef enum
{
	MODIFY_TASK_SUCCESS,
	MODIFY_TASK_UNSUCCESS
}enu_modify_task_status_t;

typedef enum
{
	SOS_RUN,
	SOS_STOP
}enu_sos_operation_status_t;


typedef struct
{
	u8 Copy_u8periodicity;
	void(*TaskFunc)(void);
	u8 Copy_u8Priority;
}Task_t;

/******************************************************SOS_Functions**************************************************************************************************************************************/


enu_system_status_t sos_init (void);
/*
  Function Type                           Synchronous
  Function Type                           Non_Reentrant
  Parameters(in)                               None
  Return                                  SOS_STATUS_SUCCESS in case of successful operation
                                          SOS_STATUS_INVALID_STATE in case that the SOS is already initialized

*/
enu_system_status_t sos_deinit (void);
/*
  Function Type                           Synchronous
  Function Type                           Non_Reentrant
  Parameters(in)                               None
  Return                                  SOS_STATUS_SUCCESS in case of successful operation
                                          SOS_STATUS_INVALID_STATE in case that the SOS is already De-initialized or was not initialized previously
*/

enu_creat_task_status_t sos_create_task (u8 Copy_u8Priority , void(*fptr)(void) , u16 Copy_u16Periodicity);
/*
  Function Type                           Synchronous
  Function Type                           Reentrant
  Parameters(in)                          Task priority,Task Function,Task periodicity
  Return                                  CREATE_TASK_SUCCESS in case of successful operation
                                          CHANGE_PRIORITY in case that we have task at same priority 
*/
enu_delete_task_status_t sos_delete_task (u8 Copy_u8Priority);
/*
  Function Type                           Synchronous
  Function Type                           Non_Reentrant
  Parameters(in)                          Task priority
  Return                                  DELETE_TASK_SUCCESS in case of successful operation
                                          DELETE_TASK_UNSUCCESS in case that task is running 
*/

enu_modify_task_status_t sos_modify_task ( void(*fptr)(void) , u16 Copy_u16Periodicity);
/*
  Function Type                           Synchronous
  Function Type                           Reentrant
  Parameters(in)                          Task Function,Task periodicity
  Return                                  MODIFY_TASK_SUCCESS in case of successful operation
                                          MODIFY_TASK_UNSUCCESS in case that the pointer to function is null 
*/
enu_sos_operation_status_t sos_run (void);
/*
  Function Type                           Synchronous
  Function Type                           Non_Reentrant
  Parameters(in)                          None
  Return                                  SOS_RUN in case of successful operation
                                          SOS_STOP in case that the timer can't be initialized 
*/
enu_sos_operation_status_t sos_disable (void);
/*
  Function Type                           Synchronous
  Function Type                           Non_Reentrant
  Parameters(in)                          None
  Return                                  SOS_STOP in case of successful operation
*/


#endif /* SOS_H_ */
