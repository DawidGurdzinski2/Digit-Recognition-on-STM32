#include "menu.h"
#include "ST7789V_GFX.h"
#include "matrix.h"
#include <string.h>
#include "tim.h"
extern struct matrix Screen;

void refreshMenu(void){
	Draw_Rect(0, 0, LCD_WIDTH, LCD_HEIGHT, BACKGROUNDCOL);
	Draw_Rect(8, 88, LCD_WIDTH-PIXEL_SIZE, LCD_HEIGHT-PIXEL_SIZE, MATRIXCOL);
	Draw_Rect(8, PIXEL_SIZE, LCD_WIDTH-PIXEL_SIZE, 55,BUTTONCOL);
	memset(Screen.Atributs,0,NUM_PIXELS);




}

void updateScreen(uint16_t X ,uint16_t Y){
	static uint32_t time1=0;// 1=100us
	static uint8_t menuState=1;

	if(Y>=88 &&menuState==1){
		calcChunk(X, Y);


	}
	else if(Y<=20 && menuState==1&& (TIM2->CNT- time1)>10000){
		time1=TIM2->CNT;
		menuState=0;
		//uint8_t  prediction = predict(void)
		//uint8_t  predictionProb = getProb(void)
		Draw_Rect(0, 0, LCD_WIDTH, LCD_HEIGHT, RELOADCOL);
		//DrawText(" ")

	}
	else if(TIM2->CNT-time1>10000){
		refreshMenu();
		time1=TIM2->CNT;

		menuState=1;
	}
	if(TIM2->CNT<time1)
		time1=0;


}
