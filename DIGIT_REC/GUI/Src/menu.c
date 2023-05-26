#include "menu.h"



void RefreshMenu(ST7789V *this,ChunkMatrix * cmtx){

	ST7789V_DrawRect(this, 0, 0, this->LCD_Width, this->LCD_Height, BACKGROUNDCOL);
	ST7789V_DrawRect(this,8, 88, this->LCD_Width-cmtx->ChunkSize, this->LCD_Height-cmtx->ChunkSize, MATRIXCOL);
	ST7789V_DrawRect(this,8, cmtx->ChunkSize, this->LCD_Width-cmtx->ChunkSize, 55,BUTTONCOL);
	memset(cmtx->Chunks,0,cmtx->ChunkNum);
}

void LoopScreen(ST7789V *this,ChunkMatrix * cmtx,uint16_t X ,uint16_t Y){
	static uint32_t time1=0;// 1=100us
	static uint8_t menuState=1;

	if(Y>=88 &&menuState==1){
		CalcChunk(this,cmtx,X, Y);


	}
	else if(Y<=20 && menuState==1&& (TIM2->CNT- time1)>10000){
		time1=TIM2->CNT;
		menuState=0;
		//uint8_t  prediction = predict(void)
		//uint8_t  predictionProb = getProb(void)
		ST7789V_DrawRect(this,0, 0,this->LCD_Width,this->LCD_Height , RELOADCOL);
		//DrawText(" ")

	}
	else if(TIM2->CNT-time1>10000){
		RefreshMenu(this,cmtx);
		time1=TIM2->CNT;

		menuState=1;
	}
	if(TIM2->CNT<time1)
		time1=0;


}
