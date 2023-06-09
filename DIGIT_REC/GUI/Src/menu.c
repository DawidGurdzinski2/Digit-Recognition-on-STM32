#include "menu.h"



/*
  * @brief 	Wypisuje text na przycisku w menu "SPRAWDZ WYNIK"
  * @param  this - wskaznik na strukture ST7789V
  * @retval None
*/
static void Write_button_text(ST7789V *this){

	uint16_t X0=15;
	uint16_t Y0=20;

	char text[]="SPRAWDZ WYNIK";
	for(uint8_t i=0;i<13;i++){
		ST7789V_WriteChar(this, X0+i*16, Y0,text[i], Font_16x26, MATRIXCOL, BUTTONCOL);
	}


}




/*
  * @brief  Odświeza ekran rysujac spowrotem Menu
  * @param  this - wskaznik na strukture ST7789V
  * @param 	cmtx - wskaznik na strukture Chunkmatrix
  * @retval None
*/
void RefreshMenu(ST7789V *this,ChunkMatrix * cmtx){

	ST7789V_DrawRect(this, 0, 0, this->LCD_Width, this->LCD_Height, BACKGROUNDCOL);
	ST7789V_DrawRect(this,8, 88, this->LCD_Width-cmtx->ChunkSize, this->LCD_Height-cmtx->ChunkSize, MATRIXCOL);
	ST7789V_DrawRect(this,8, cmtx->ChunkSize, this->LCD_Width-cmtx->ChunkSize, 55,BUTTONCOL);
	memset(cmtx->Chunks,0,cmtx->ChunkNum);
	Write_button_text(this);
}
/*
  * @brief  Główna pętla , decyduje ona jaka operacja wykona się kiedy klikniemy odpowiednia czaesc ekranu
  * 		dla ekranu o pozycji wiekszej niz Y=88 kalkulowany jest który sektor został wcisniety. Dane sa
  * 		zapisywane do struktury CHunkMatrix
  * @param  this - wskaznik na strukture ST7789V
  * @param 	cmtx - wskaznik na strukture Chunkmatrix
  * @param  X - poziomy kordynat na ekranie
  * @param  Y - pionowy kordynat na ekranie
  * @retval zwraca czy rozpoczac obliczenia jaka liczba zotałą wpisana do ekranu 1 rozpoczyna 0 nie.
*/
uint8_t LoopScreen(ST7789V *this,ChunkMatrix * cmtx,uint16_t X ,uint16_t Y){
	static uint32_t time1=0;// 1=100us
	static uint8_t menuState=1;

	if(Y>=88 &&menuState==1){
		CalcChunk(this,cmtx,X, Y);


	}
	else if(Y<=20 && menuState==1&& (TIM2->CNT- time1)>10000){
		time1=TIM2->CNT;
		menuState=0;
		ST7789V_DrawRect(this,0, 0,this->LCD_Width,this->LCD_Height , RELOADCOL);
		return 1;

	}
	else if(TIM2->CNT-time1>10000){
		RefreshMenu(this,cmtx);
		time1=TIM2->CNT;

		menuState=1;
	}
	if(TIM2->CNT<time1)
		time1=0;

	return 0;
}
/*
  * @brief 	Wypisuje nam na ekranie wynik wykalkulowany przez siec neuronowa
  * @param  this - wskaznik na strukture ST7789V
  * @param  result - wynik jaki zworciła siec
  * @retval None
*/

void Print_Result(ST7789V *this,uint8_t result){
	ST7789V_DrawRect(this, 0, 0, this->LCD_Width, this->LCD_Height, BLACK);
	uint16_t X0=10;
	uint16_t Y0=147;
	char text[]="TWOJ WYNIK TO:";
	for(uint8_t i=0;i<sizeof(text)-1;i++){
		ST7789V_WriteChar(this, X0+i*16, Y0,text[i], Font_16x26, RED, BLACK);
	}
	ST7789V_WriteChar(this, 112, 176,(char)(48+result), Font_16x26,RED, BLACK);


}

/*
  * @brief 	Wyswietla informacje o ty ze aktualnie sa prowadzone obliczenia
  * @param  this - wskaznik na strukture ST7789V
  * @retval None
*/

void Print_Info_Calc(ST7789V *this){
	ST7789V_DrawRect(this, 0, 0, this->LCD_Width, this->LCD_Height, BLACK);
	uint16_t X0=60;
	uint16_t Y0=147;
	char text[]="TRWAJA:";
	for(uint8_t i=0;i<sizeof(text)-1;i++){
		ST7789V_WriteChar(this, X0+i*16, Y0,text[i], Font_16x26, RED, BLACK);
	}
	X0=30;
	Y0=173;
	char text1[]="OBLICZENIA:";
	for(uint8_t i=0;i<sizeof(text1)-1;i++){
		ST7789V_WriteChar(this, X0+i*16, Y0,text1[i], Font_16x26, RED, BLACK);
	}


}
/*
  * @brief 	Wyswietla informacje o ty ze aktualnie sa czysczane sa sektory  w pamieci
  * @param  this - wskaznik na strukture ST7789V
  * @retval None
*/

void Print_Info_MEM_CL(ST7789V *this){
	ST7789V_DrawRect(this, 0, 0, this->LCD_Width, this->LCD_Height, BLACK);
	uint16_t X0=30;
	uint16_t Y0=147;
	char text[]="Czyszczenie";
	for(uint8_t i=0;i<sizeof(text)-1;i++){
		ST7789V_WriteChar(this, X0+i*16, Y0,text[i], Font_16x26, RED, BLACK);
	}
	X0=60;
	Y0=173;
	char text1[]="Pamieci";
	for(uint8_t i=0;i<sizeof(text1)-1;i++){
		ST7789V_WriteChar(this, X0+i*16, Y0,text1[i], Font_16x26, RED, BLACK);
	}


}


/*
  * @brief 	Wyswietla informacje o ty ze aktualnie sa wczytywane dane do pamieci
  * @param  this - wskaznik na strukture ST7789V
  * @retval None
*/

void Print_Info_MEM_WR(ST7789V *this){
	ST7789V_DrawRect(this, 0, 0, this->LCD_Width, this->LCD_Height, BLACK);
	uint16_t X0=30;
	uint16_t Y0=147;
	char text[]="Wczytywanie";
	for(uint8_t i=0;i<sizeof(text)-1;i++){
		ST7789V_WriteChar(this, X0+i*16, Y0,text[i], Font_16x26, RED, BLACK);
	}
	X0=70;
	Y0=173;
	char text1[]="Danych";
	for(uint8_t i=0;i<sizeof(text1)-1;i++){
		ST7789V_WriteChar(this, X0+i*16, Y0,text1[i], Font_16x26, RED, BLACK);
	}
}





/*
  * @brief 	Wypisuje nam na ekranie procent łądowania
  * @param  this - wskaznik na strukture ST7789V
  * @param  result - postep w kratkach (ile ma ich wyswietlic)
  * @retval None
*/

void Print_Proc_10(ST7789V *this,uint8_t number){
	if(number>13){
		number=13;
	}
	uint16_t start=8;
	uint16_t gap=8;
	uint16_t Y0=220;
	uint16_t size=10;
	for(uint8_t i=0;i<number;i++){
		 ST7789V_DrawRect(this, start+(i*(size+gap)), Y0, start+size+i*(size+gap) ,Y0+10, RED);
	}


}

