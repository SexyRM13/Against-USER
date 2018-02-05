#ifndef __CATCH_TASK_H__
#define __CATCH_TASK_H__

#include "stm32f4xx_hal.h"
#include "rm_hal_lib.h"

#define PWM_MOTOR_A PWM_IO7
#define PWM_MOTOR_B PWM_IO8

void catch_task(const void* argu);

#endif
