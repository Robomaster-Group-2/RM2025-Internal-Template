#include "gpio.h"
#include "main.h"
#include "usart.h"
#include "RC_driver.hpp"

#define rxBuffer_size 25
#define txBuffer_size 25

static uint8_t rxBuffer[rxBuffer_size] ;
static uint16_t txBuffer[txBuffer_size] ;

struct DecodedData{
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


void rxCallback(UART_HandleTypeDef *huart, uint16_t size){
  decodedData.Header = rxBuffer[0] ;
  decodedData.Ch_1 = ((rxBuffer[2] & 0b111) << 8) | (rxBuffer[1]) ;
  decodedData.Ch_2 = ((rxBuffer[3] & 0b111111) << 5) | ((rxBuffer[2] & 0b11111) >> 3) ;
  decodedData.Ch_3 = ((rxBuffer[5] & 0b1) << 10) | (rxBuffer[4] << 2) | ((rxBuffer[3] & 0b11) >> 6)  ;
  decodedData.Ch_4 = ((rxBuffer[6] & 0b1111) << 7) | ((rxBuffer[5] & 0b1111111) >> 1) ;
  decodedData.Ch_5 = ((rxBuffer[7] & 0b1111111) << 4) | ((rxBuffer[6] & 0b1111) >> 4) ;
  decodedData.Ch_6 = ((rxBuffer[9] & 0b11) << 9) | (rxBuffer[8] << 1) | ((rxBuffer[7] & 0b1) >> 7) ;
  decodedData.Ch_7 = ((rxBuffer[10] & 0b11111) << 6) | ((rxBuffer[9] & 0b111111) >> 2) ; 
  decodedData.Ch_8 = (rxBuffer[11] << 3) | ((rxBuffer[10] & 0b111) >> 5) ; 
  decodedData.Ch_9 = ((rxBuffer[13] & 0b111) << 8) | (rxBuffer[12]) ;
  decodedData.Ch_10 = ((rxBuffer[14] & 0b111111) << 5) | ((rxBuffer[13] & 0b11111) >> 3) ; 
  decodedData.Ch_11 = ((rxBuffer[16] & 0b1) << 10) | (rxBuffer[15] << 2) | ((rxBuffer[14] & 0b11) >> 6) ;
  decodedData.Ch_12 = ((rxBuffer[17] & 0b1111) << 7) | ((rxBuffer[16] & 0b1111111) >> 1) ;
  decodedData.Ch_13 = ((rxBuffer[18] &0b1111111) << 4) | ((rxBuffer[17] & 0b1111) >> 4) ;
  decodedData.Ch_14 = ((rxBuffer[20] &0b11) << 9) | (rxBuffer[19] << 1) | ((rxBuffer[18] &0b1) >> 7) ;
  decodedData.Ch_15 = ((rxBuffer[21] &0b11111) << 6) | ((rxBuffer[20] &0b111111) >> 2) ;
  decodedData.Ch_16 = (rxBuffer[22] << 3) | ((rxBuffer[21] &0b111) >> 5) ;
  decodedData.Ch_17 = (rxBuffer[23] &0b1) ;
  decodedData.Ch_18 = (rxBuffer[23] &0b1) ;
  decodedData.frame_lost = (rxBuffer[23] &0b1) ;
  decodedData.failsafe_activated = (rxBuffer[23] &0b1) ;
  decodedData.Footer = rxBuffer[24] ;
  HAL_UARTEx_ReceiveToIdle_IT(&huart3, rxBuffer, sizeof(rxBuffer)) ;
}


void RC_driver_Task(void *pvPara){
    HAL_UART_RegisterRxEventCallback(&huart3, rxCallback) ;
    HAL_UARTEx_ReceiveToIdle_IT(&huart3, rxBuffer, sizeof(rxBuffer)) ;
    
    while (1) {
        HAL_Delay(1);
    }
}