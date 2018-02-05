#include "catch_task.h"
#include "uart_device.h"

void catch_task(const void* argu) {
    // 初始化PWM输出参数
    set_pwm_param(PWM_MOTOR_A, 1700);
    set_pwm_param(PWM_MOTOR_B, 1700);

    // 开启PWM输出
    start_pwm_output(PWM_MOTOR_A);
    start_pwm_output(PWM_MOTOR_B);

    while(1) {
        // 收回
        if(rc.sw1 == RC_DN) {
            set_pwm_param(PWM_MOTOR_A, 2000);
            set_pwm_param(PWM_MOTOR_B, 2000);

        // 伸出
        } else {
            set_pwm_param(PWM_MOTOR_A, 1700);
            set_pwm_param(PWM_MOTOR_B, 1700);
            
        }
    }
}
