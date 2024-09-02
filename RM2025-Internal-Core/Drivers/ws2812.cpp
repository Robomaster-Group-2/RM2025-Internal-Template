#include "ws2812.hpp"
#include "main.h"
#include "tim.h"
#include "stdint.h"
#include <string.h>

namespace WS2812
{
uint8_t led_num = 0;
uint16_t buffer_size;
uint32_t buffer[BUFFER_SIZE];
void init(TIM_HandleTypeDef* htim, uint32_t channel, uint8_t _led_num)
{
    assert_param(led_num <= MAX_LED_NUM);

    led_num = _led_num;

    buffer_size = led_num * LED_DATA_SIZE_UNIT + RESET_PWM_SIZE;

    for(int i = 0; i < led_num * LED_DATA_SIZE_UNIT; i++)
    {
        buffer[i] = 2;
    }

    HAL_TIM_PWM_Start_DMA(
        htim, channel, buffer, buffer_size); // Start the DMA module, in circular mode
}


void forceResetTime()
{
    // This is defined by the WS2812 protocal, need to have a "reset" period
    memset(buffer + led_num * LED_DATA_SIZE_UNIT, 0, RESET_PWM_SIZE * sizeof(buffer[0]));
}

void setColor(uint16_t index, uint8_t r, uint8_t g, uint8_t b)
{
    if (index >= led_num)
        return;
    uint32_t data = r << 16 | g << 8 | b;
    for (uint32_t j = 0; j < LED_DATA_SIZE_UNIT; j++)
        buffer[index * LED_DATA_SIZE_UNIT + j] =  (data & 0x800000) ? BIT1_WIDTH : BIT0_WIDTH, data <<= 1;
}

void blankAll()
{
    for (int i = 0; i < led_num; i++)
        setColor(i, 0, 0, 0);
}
}