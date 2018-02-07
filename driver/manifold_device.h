#ifndef __MANIFOLD_DEVICE_H__
#define __MANIFOLD_DEVICE_H__

#include "rm_hal_lib.h"

/**
  * @brief     解析后的云台偏转角度
  */
typedef struct {
    float vyaw;             // Yaw轴偏转角度
    float vpitch;           // Pitch轴偏转角度
} mf_type_t;

// 数据接收中断函数
void mf_dbus_uart_callback(void);

extern mf_type_t mf;
extern uint8_t mf_dbus_buffer[];

#endif
