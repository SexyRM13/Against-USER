#ifndef __AUTOAIM_TASK_H__
#define __AUTOAIM_TASK_H__

#include "stm32f4xx_hal.h"
#include "sys.h"

// 相对坐标偏移
typedef struct {
    float vyaw;
    float vpitch;
} offest_type_t;

#define AA_OPEN  1
#define AA_CLOSE 0

extern offest_type_t ms_offest;
extern uint8_t is_autoaim;

void autoaim_task(const void* argu);

#endif
