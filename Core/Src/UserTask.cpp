/**
 * @file UserTask.cpp
 * @author JIANG Yicheng  RM2023 (EthenJ@outlook.sg)
 * @brief Create user tasks with cpp support
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 */
#include "AppConfig.h"   // Include our customized configuration
#include "FreeRTOS.h"
#include "fdcan.h"
#include "gpio.h"
#include "main.h"
#include "task.h"
#include "tim.h"
#include "ws2812.hpp"
#include "math.h"
#include "stdint.h"

StackType_t uxTestTaskStack[configMINIMAL_STACK_SIZE];
StaticTask_t xTestTaskTCB;


void testTask(void *pvPara)
{
    HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
    WS2812::init(10);

    float r_w = 0.076f;
    float g_w = 0.134f;
    float b_w = 0.343f;
    uint8_t r = 0, g = 0, b = 0;
    
    float brightness = 20;

    float i = 0;
    while (true)
    {
        r = (uint8_t)(sin(i * r_w) * brightness + brightness);
        g = (uint8_t)(sin(i * g_w) * brightness + brightness);
        b = (uint8_t)(sin(i * b_w) * brightness + brightness);
        WS2812::setColor(0, r, g, b);
        WS2812::setColor(1, g, b, r);
        WS2812::setColor(2, b, r, g);
        WS2812::setColor(3, r, g, b);
        WS2812::setColor(4, g, b, r);
        WS2812::setColor(5, b, r, g);
        WS2812::setColor(6, r, g, b);
        WS2812::setColor(7, g, b, r);
        WS2812::setColor(8, b, r, g);
        WS2812::setColor(9, r, g, b);
        i += 0.1f;
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
        vTaskDelay(10);
    }
}

/**
 * @brief Intialize all the drivers and add task to the scheduler
 * @todo  Add your own task in this file
*/

void startUserTasks()
{
    xTaskCreateStatic(testTask, "testTask", configMINIMAL_STACK_SIZE, NULL, 0, uxTestTaskStack, &xTestTaskTCB);
    /**
     * @todo Add your own task here
     */
}
