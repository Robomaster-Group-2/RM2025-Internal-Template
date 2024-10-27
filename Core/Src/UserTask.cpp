/**
 * @file UserTask.cpp
 * @author JIANG Yicheng  RM2023 (EthenJ@outlook.sg)
 * @brief Create user tasks with cpp support
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 */
#include "AppConfig.h" // Include our customized configuration
#include "FreeRTOS.h"
#include "gpio.h"
#include "main.h"
#include "task.h"


StackType_t uxMainTaskStack[configMINIMAL_STACK_SIZE];
StaticTask_t xMainTaskTCB;

#define rxBuffer_size 25
static uint8_t rxBuffer[rxBuffer_size] ;

struct DecodeData{
  uint16_t Header ;
  uint16_t Ch_1 ;
  uint16_t Ch_2 ;
  uint16_t Ch_3 ;
  uint16_t Ch_4 ;
  uint16_t Ch_5 ;
  uint16_t Ch_6 ;
  uint16_t Ch_7 ;
  uint16_t Ch_8 ;
  uint16_t Ch_9 ;
  uint16_t Ch_10 ;
  uint16_t Ch_11 ;
  uint16_t Ch_12 ;
  uint16_t Ch_13 ;
  uint16_t Ch_14 ;
  uint16_t Ch_15 ;
  uint16_t Ch_16 ;
  uint16_t Ch_17 ;
  uint16_t Ch_18 ;
  uint16_t frame_lost ;
  uint16_t failsafe_activated ;
  uint16_t Footer ;
} decodedData ;

// an example task
void mainTask(void *pvPara) {

  while (true) {


    vTaskDelay(1);
  }
}

/**
 * @brief Intialize all the drivers and add task to the scheduler
 * @todo  Add your own task in this file
 */
void startUserTasks() {
  xTaskCreateStatic(mainTask, "testTask", configMINIMAL_STACK_SIZE, NULL, 0,
                    uxMainTaskStack, &xMainTaskTCB);
  /**
   * @todo Add your own task here
   */
}
