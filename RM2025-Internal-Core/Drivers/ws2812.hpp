#pragma once

#include "main.h"
#include "stdint.h"

#define BIT1_WIDTH 4
#define BIT0_WIDTH 2

#define MAX_LED_NUM 15

#define LED_DATA_SIZE_UNIT 24
#define RESET_PWM_SIZE 290

#define BUFFER_SIZE (MAX_LED_NUM * LED_DATA_SIZE_UNIT + RESET_PWM_SIZE)

namespace WS2812
{
void init(uint8_t _led_num);
void blink(uint16_t index, uint8_t r, uint8_t g, uint8_t b);
void blankAll();
void forceResetTime();
}
