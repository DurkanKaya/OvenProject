/*
 * ClosetParse.c
 *
 *  Created on: Sep 2, 2021
 *      Author: Ofis-Pc
 */
#include "ClosetParse.h"
#include "main.h"

int BCC =0;

void BufferReset()
{
	uint8_t x=0;

	for(x=0; x < 255; x++)
	{
		ESP_Gelen_Data1[x] = 0;
	}
}
void PcDolapAcKapat()
{
	BCC = 0;
	for (int i = 0; i < 4; ++i) {

		BCC ^= ESP_Gelen_Data1[i];
	}
	if(ESP_Gelen_Data1[0] == 2 && ESP_Gelen_Data1[3] == 3)
	{
		if(ESP_Gelen_Data1[4] == BCC)
		{
			if(ESP_Gelen_Data1[1] == 5)
			{
				if(ESP_Gelen_Data1[2] == 10)
				{
					HAL_GPIO_WritePin(OpenCloseRole_GPIO_Port,OpenCloseRole_Pin,GPIO_PIN_SET);
					RxBufferCnt1 =0;
					BufferReset();
				}
				if(ESP_Gelen_Data1[2] == 11)
				{
					HAL_GPIO_WritePin(OpenCloseRole_GPIO_Port,OpenCloseRole_Pin,GPIO_PIN_RESET);
				}
			}
			if(ESP_Gelen_Data1[1] == 6)
			{
				if(ESP_Gelen_Data1[2] == 10)
				{
					HAL_GPIO_WritePin(OnOffLedRole_GPIO_Port,OnOffLedRole_Pin,GPIO_PIN_SET);
				}
				if(ESP_Gelen_Data1[2] == 11)
				{
					HAL_GPIO_WritePin(OnOffLedRole_GPIO_Port,OnOffLedRole_Pin,GPIO_PIN_RESET);
				}
			}

		}

	}
}


