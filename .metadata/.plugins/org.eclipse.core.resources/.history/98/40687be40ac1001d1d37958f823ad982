#include <stdio.h>
#include <string.h>
#include "common.h"
#include "menu_GUI.h"
#include "gpio.h"

extern void (*key_tap_func)(void);

extern uint8_t ACV;
extern volatile uint8_t RSTinfo;

 void ACVISITION_ON(void){
	 ACV=1;
	 HAL_GPIO_WritePin(ACV_GPIO_Port, ACV_Pin, GPIO_PIN_SET);
 }
void ACVISITION_OFF(void){
	ACV=0;
	HAL_GPIO_WritePin(ACV_GPIO_Port, ACV_Pin, GPIO_PIN_RESET);
}
 void RSTACV(void){
	 HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_RESET);
	 RSTinfo=0;
	 ACV=0;
	 HAL_Delay(1);
	 HAL_GPIO_WritePin(ACV_GPIO_Port, ACV_Pin, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(RST_GPIO_Port,RST_Pin, GPIO_PIN_SET);
	 refresh_taskbar();
 }
void PRINT(void){

}
