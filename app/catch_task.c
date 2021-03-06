#include "catch_task.h"
#include "uart_device.h"
#include "cmsis_os.h"

void catch_task(const void* argu) {
    // 初始化PWM输出参数
    set_pwm_param(PWM_MOTOR_A, 1950);
    set_pwm_param(PWM_MOTOR_B, 1950);

    // 开启PWM输出
    start_pwm_output(PWM_MOTOR_A);
    start_pwm_output(PWM_MOTOR_B);

    while(1) {
        // 收回
        if(rc.sw1 == RC_DN) {
            set_pwm_param(PWM_MOTOR_A, 1980);
            set_pwm_param(PWM_MOTOR_B, 1980);

        // 伸出
        } else {
            set_pwm_param(PWM_MOTOR_A, 1730);
            set_pwm_param(PWM_MOTOR_B, 1730);
        }

        osDelay(5);
    }
}
