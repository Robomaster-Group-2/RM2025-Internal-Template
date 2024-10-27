#pragma once

#include "gpio.h"
#include "main.h"
#include "usart.h"

// #define rxBuffer_size 25
// #define txBuffer_size 25

void rxCallback(UART_HandleTypeDef *huart, uint16_t size) ;
void RC_driver_Task(void *pvPara) ;

