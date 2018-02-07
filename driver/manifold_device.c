#include "manifold_device.h"
#include "sys.h"

// Mainfold传输过来的数据
mf_type_t mf;
// Buffer
uint8_t mf_dbus_buffer[MF_DBUS_FRAME_SIZE];

// Buffer内存布局
// [0] => yaw轴偏转角度高8位
// [1] => yaw轴偏转角度中上8位
// [2] => yaw轴偏转角都中下8位
// [3] => yaw轴偏转角度低8位
// [4] => pitch轴偏转角度高8位
// [5] => pitch轴偏转角度中上8位
// [6] => pitch轴偏转角都中下8位
// [7] => pitchs轴偏转角度低8位

// 数据接收中断函数
void mf_dbus_uart_callback(void) {
    // TODO: 需Debug时调整其正负
    mf.vyaw = (float)((mf_dbus_buffer[0] >> 24) + (mf_dbus_buffer[1] >> 16) + (mf_dbus_buffer[2] >> 8) + mf_dbus_buffer[3]);
    mf.vpitch = (float)((mf_dbus_buffer[4] >> 24) + (mf_dbus_buffer[5] >> 16) + (mf_dbus_buffer[6] >> 8) + mf_dbus_buffer[7]);
}
