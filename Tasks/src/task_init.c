/*
 * @Author: dan_n 2560651727@qq.com
 * @Date: 2026-10-05 21:02:34
 * @LastEditors: dan_n 2560651727@qq.com
 * @LastEditTime: 2026-10-06 14:49:48
 * @FilePath: \222\Tasks\src\task_init.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "task_init.h"
extern IWDG_HandleTypeDef hiwdg;
extern TIM_HandleTypeDef htim2;

// 第2题：全局变量 tick，Ozone 里要能看到
volatile uint32_t tick = 0;

// 第1题：GPIO 初始化（PC13 低电平点亮）
void Task_GPIO_Init(void) {
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
}

// 第2题：定时器回调（全工程只写这一份！）
// 注意：如果用 C++ 写，函数前面要加 extern "C"
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM2) {
        tick++;
        //HAL_IWDG_Refresh(&hiwdg); // 第2题：喂狗。第3题要求删掉这一行
    }
}

// 统一初始化入口
void Task_Init(void) {
    Task_GPIO_Init();
    HAL_TIM_Base_Start_IT(&htim2); // 启动定时器中断
}
