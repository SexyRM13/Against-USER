#include "autoaim_task.h"
#include "cmsis_os.h"
#include "uart_device.h"
#include "keyboard.h"

offest_type_t ms_offest;
uint8_t is_autoaim;

void autoaim_task(const void* argu) {
    is_autoaim = AA_CLOSE;
    ms_offest.vyaw = 0.0f;
    ms_offest.vpitch = 0.0f;

    while(1) {
        // 开关自瞄模式
        if(rc.kb.bit.V) {
            is_autoaim = AA_OPEN;
        } else {
            is_autoaim = AA_CLOSE;
        }

        // 处理鼠标累计数据
        if(is_autoaim == 1) {
            ms_offest.vyaw -= rc.mouse.x * KB_RATIO * GIMBAL_PC_MOVE_RATIO_YAW;
            ms_offest.vpitch -= rc.mouse.y * KB_RATIO * GIMBAL_PC_MOVE_RATIO_PIT;
        } else {
            ms_offest.vyaw = 0.0f;
            ms_offest.vpitch = 0.0f;
        }

        osDelay(5);
    }
}
