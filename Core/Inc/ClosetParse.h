/*
 * ClosetParse.h
 *
 *  Created on: Sep 2, 2021
 *      Author: Ofis-Pc
 */

#ifndef INC_CLOSETPARSE_H_
#define INC_CLOSETPARSE_H_

#define ESP_Buffer_Boyutu1 5000
char ESP_Gelen_Data1[ESP_Buffer_Boyutu1];
static int RxBufferCnt1=0;

void PcDolapAcKapat();
void BufferReset();

#endif /* INC_CLOSETPARSE_H_ */

