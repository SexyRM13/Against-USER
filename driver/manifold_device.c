#include "manifold_device.h"
#include "sys.h"

// Mainfold传输过来的数据
mf_type_t mf;
// Buffer
uint8_t mf_dbus_buffer[MF_DBUS_FRAME_SIZE];

// Buffer内存布局
// [0] => yaw轴偏转角度高8位
// [1] => yaw轴偏转角度低8位
// [2] => pitch轴偏转角度高8位
// [3] => pitch轴偏转角度低8位

// 数据接收中断函数
void mf_dbus_uart_callback(void) {
    mf.vyaw = (float)((mf_dbus_buffer[0] >> 8) + mf_dbus_buffer[1]);
    mf.vpitch = (float)((mf_dbus_buffer[2] >> 8) + mf_dbus_buffer[3]);
}
