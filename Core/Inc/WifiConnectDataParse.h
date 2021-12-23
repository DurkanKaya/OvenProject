/*
 * WifiConnectDataParse.h
 *
 *  Created on: 3 Eyl 2021
 *      Author: Ofis-Pc
 */

#ifndef INC_WIFICONNECTDATAPARSE_H_
#define INC_WIFICONNECTDATAPARSE_H_
#include "stm32f4xx_hal.h"

/*typedef struct
{
	UART_HandleTypeDef* uart2;
}uart;*/


#define ESP_Buffer_Boyutu 5000
char ESP_Gelen_Data[ESP_Buffer_Boyutu];

void BufferReset1();
void DataConnectionControl();



#endif /* INC_WIFICONNECTDATAPARSE_H_ */
