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


StackType_t uxTestTaskStack[configMINIMAL_STACK_SIZE];
StaticTask_t xTestTaskTCB;

void testTask(void *pvPara)
{
    HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);

    while (true)
    {
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
        // HAL_GPIO_TogglePin(LASER_GPIO_Port, LASER_Pin);
        vTaskDelay(200);
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
