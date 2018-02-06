#ifndef __CATCH_TASK_H__
#define __CATCH_TASK_H__

#include "stm32f4xx_hal.h"
#include "rm_hal_lib.h"

// 夹持电机PWM IO口设置
#define PWM_MOTOR_A PWM_IO9
#define PWM_MOTOR_B PWM_IO10

void catch_task(const void* argu);

#endif
