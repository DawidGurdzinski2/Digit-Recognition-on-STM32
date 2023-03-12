#include "menu_GUI.h"
#include "ILI9341_GFX.h"
#include "ILI9341_STM32_Driver.h"


extern uint8_t ACV;
 void print_S1(uint16_t X0, uint16_t X1, uint16_t Y0,uint16_t Y1){

	 ILI9341_DrawFilledRectangleCoord(X0, Y0, X1, Y1, RED);


 }
 void print_S2(uint16_t X0, uint16_t X1, uint16_t Y0,uint16_t Y1){

	 ILI9341_DrawFilledRectangleCoord(X0, Y0, X1, Y1, GREEN);

 }
 void print_S3(uint16_t X0, uint16_t X1, uint16_t Y0,uint16_t Y1){

	 ILI9341_DrawFilledRectangleCoord(X0, Y0, X1, Y1, BLUE);

 }
 void print_S4(uint16_t X0, uint16_t X1, uint16_t Y0,uint16_t Y1){

	 ILI9341_DrawFilledRectangleCoord(X0, Y0, X1, Y1, YELLOW);

 }

 void refresh_taskbar(void){
	 ILI9341_DrawFilledRectangleCoord(0, 0, 240, 39, BLACK);
	 ILI9341_DrawText("ACQUISITION:",FONT4, 10, 10, WHITE, BLACK);
	if(ACV){
		ILI9341_DrawText("ON",FONT4, 130, 10, GREEN, BLACK);
	}
 	else{
 		ILI9341_DrawText("OFF",FONT4, 130, 10, RED, BLACK);
	 	}

	//	ILI9341_DrawText(str, font, X, Y, color, bgcolor);



 }
