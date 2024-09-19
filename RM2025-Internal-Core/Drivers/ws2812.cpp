#include "ws2812.hpp"
#include "main.h"
#include "tim.h"
#include "stdint.h"
#include <string.h>



namespace WS2812
{
#define WS2812_TIM_CLK_FREQ 84000000
#define WS2812_TIM htim1
#define WS2812_TIM_CHANNEL TIM_CHANNEL_1

uint8_t led_num = 0;
uint16_t buffer_size;
uint8_t buffer[BUFFER_SIZE];
void init(uint8_t _led_num)
{
    assert_param(led_num <= MAX_LED_NUM);

    led_num = _led_num;

    buffer_size = led_num * LED_DATA_SIZE_UNIT + RESET_PWM_SIZE;

    for(int i = 0; i < led_num * LED_DATA_SIZE_UNIT; i++)
    {
        buffer[i] = 2;
    }
    forceResetTime();

    TIM_HandleTypeDef* htim = &WS2812_TIM;

    htim->Instance->CR1 = 0; // 关闭定时器

    // 配置定时器
    htim->Instance->PSC = WS2812_TIM_CLK_FREQ / 3200000 - 1; // 设置预分频器，时钟为 84 MHz
    htim->Instance->ARR = 8 - 1; // 设置自动重载寄存器值

    // 修改计数器的值
    htim->Instance->CNT = BIT0_WIDTH; // 将计数器设置为 4

    // 更新计数器
    htim->Instance->EGR |= TIM_EGR_UG; // 触发更新事件
    

    HAL_TIM_PWM_Start_DMA(
        &WS2812_TIM, WS2812_TIM_CHANNEL, (uint32_t *)buffer, buffer_size); // Start the DMA module, in circular mode
}


void forceResetTime()
{
    // This is defined by the WS2812 protocal, need to have a "reset" period
    memset(buffer + led_num * LED_DATA_SIZE_UNIT, 0, RESET_PWM_SIZE * sizeof(buffer[0]));
}

void blink(uint16_t index, uint8_t r, uint8_t g, uint8_t b)
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
        blink(i, 0, 0, 0);
}
}