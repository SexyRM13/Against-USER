#include "catch_task.h"
#include "uart_device.h"
#include "cmsis_os.h"

void catch_task(const void* argu) {
    // 初始化PWM输出参数
    set_pwm_param(PWM_MOTOR_A, 1700);
    set_pwm_param(PWM_MOTOR_B, 1700);

    // 开启PWM输出
    start_pwm_output(PWM_MOTOR_A);
    start_pwm_output(PWM_MOTOR_B);

    // 夹持任务
    uint32_t catch_wake_time = osKernelSysTick();
    while(1) {
        // 收回
        if(rc.sw1 == RC_DN) {
            set_pwm_param(PWM_MOTOR_A, 1950);
            set_pwm_param(PWM_MOTOR_B, 1950);

        // 伸出
        } else {
            set_pwm_param(PWM_MOTOR_A, 1760);
            set_pwm_param(PWM_MOTOR_B, 1760);
        }

        osDelayUntil(&catch_wake_time, CATCH_PERIOD);
    }
}
