/*
 * WifiConnectDataParse.c
 *
 *  Created on: 3 Eyl 2021
 *      Author: Ofis-Pc
 */
#include "WifiConnectDataParse.h"
#include "main.h"
#include "string.h"
uint8_t Case = 0;
extern UART_HandleTypeDef huart2;
char TxBuffer1[4]="AT\r\n";
char TxBuffer2[12]="AT+CWMODE?\r\n";
char TxBuffer3[13]="AT+CWMODE=1\r\n";
char TxBuffer4[10]="AT+CIFSR\r\n";
char TxBuffer5[13]="AT+CIPMUX=1\r\n";
char TxBuffer6[21]="AT+CIPSERVER=1,3333\r\n";
char TxBuffer7[39]="AT+CIPSTART=\"TCP\",\"192.168.1.72\",3333\r\n";
char TxBuffer8[14]="AT+CIPSEND=4\r\n";
char TxBuffer9[35]= "AT+CWJAP=\"Luhmann\",\"Luhmann2995@\"\r\n";

void BufferReset1()
{
	uint8_t k=0;

	for(k=0; k < 255; k++)
	{
		ESP_Gelen_Data[k] = 0;
	}
}

void DataConnectionControl()
{
	switch(Case){
	case 0:
		HAL_UART_Transmit(&huart2, (uint8_t*)TxBuffer1, 4, 500);
		Case = 1;

		//break;
	case 1:
		if(strstr(ESP_Gelen_Data,"OK"))
		{
			BufferReset1();
			Case =2;
		}
		else
		{
			Case=0;
		}
	case 2:
		HAL_UART_Transmit(&huart2, (uint8_t*)TxBuffer2,13, 1000);
		Case = 3;
	case 3:
		if(strstr(ESP_Gelen_Data,"+CWMODE:1"))
		{
			BufferReset1();
			Case= 4;
		}
		else

		{
			BufferReset1();
			HAL_UART_Transmit(&huart2, (uint8_t*)TxBuffer3,13, 100);
			Case = 3;

		}
		break;
	case 4:
		HAL_UART_Transmit(&huart2, (uint8_t*)TxBuffer9, 35, 100);
		Case = 5;
		HAL_Delay(5000);
		break;

	case 5:
		if(strstr(ESP_Gelen_Data,"OK"))
		{
			BufferReset1();
			Case = 6;
		}
		else
		{
			BufferReset1();
			Case = 6;

		}
		break;

	case 6:
		HAL_UART_Transmit(&huart2, (uint8_t*)TxBuffer4, 10, 100);
		HAL_Delay(1000);
		Case=7;
		break;
	case 7:
		if(strstr(ESP_Gelen_Data,"OK"))
		{
			BufferReset1();
			Case =8;
		}
		else
		{
			BufferReset1();
			Case=8;
		}
		break;
	case 8:
		HAL_UART_Transmit(&huart2, (uint8_t*)TxBuffer5, 13, 100);
		HAL_Delay(1000);
		Case =9;
		break;
	case 9:
		if(strstr(ESP_Gelen_Data,"OK"))
		{
			BufferReset1();
			Case =10;
		}
		else
		{
			BufferReset1();
			Case =10;
		}
		break;
	case 10:
		HAL_UART_Transmit(&huart2, (uint8_t*)TxBuffer6, 21,100);
		HAL_Delay(1000);
		HAL_Delay(1);
		Case =11;
	case 11:
		if(strstr(ESP_Gelen_Data,"OK"))
		{
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
			BufferReset1();
			Case =12;
		}
		else
		{
			BufferReset1();
			Case =12;
		}
		break;

	case 12:

		HAL_UART_Transmit(&huart2, (uint8_t*)TxBuffer7, 39,100);
		HAL_Delay(2000);
		HAL_Delay(1);
	}
}
