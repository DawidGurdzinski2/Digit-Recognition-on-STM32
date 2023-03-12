#include "menu.h"
#include "ST7789V_GFX.h"
#include "matrix.h"
#include <string.h>

extern struct matrix Screen;

void refreshMenu(void){
	Draw_Rect(0, 0, LCD_WIDTH, LCD_HEIGHT, GREEN);
	Draw_Rect(8, 88, LCD_WIDTH-PIXEL_SIZE, LCD_HEIGHT-PIXEL_SIZE, WHITE);
	memset(Screen.Atributs,0,NUM_PIXELS);




}

void updateScreen(uint16_t X ,uint16_t Y){
	static uint8_t menuState=1;
	if(Y>=88 &&menuState==1){
		calcChunk(X, Y);


	}
	else if(Y<=60 && menuState==1){
		menuState=0;
		//uint8_t  prediction = predict(void)
		//uint8_t  predictionProb = getProb(void)
		Draw_Rect(0, 0, LCD_WIDTH, LCD_HEIGHT, BLUE);
		//DrawText(" ")
	}else{
		refreshMenu();
		menuState=1;
	}


}
