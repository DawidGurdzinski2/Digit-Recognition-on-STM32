#include "matrix.h"
#include "ST7789V_GFX.h"



struct matrix Screen;





//column 0-27  row 0-27
void calcChunk(uint16_t X ,uint16_t Y){

	uint8_t column =30-(X-X%PIXEL_SIZE)/PIXEL_SIZE;
	uint8_t row=40-(Y-Y%PIXEL_SIZE)/PIXEL_SIZE;
	static uint8_t prevRow=0,prevCol=0;
	if(column==0) column=1;
	if(column>=29) column=MATRIX_RESOLUTION;
	column--;
	if(row==0) row=1;
	if(row>=29) row=MATRIX_RESOLUTION;
	row--;
	if(prevRow!=row || prevCol!=column){
		boundaryConditions(row, column);
		prevRow=row;
		prevCol=column;
	}
}



/*0-ALL
 * 1 - U D R RU RD
 * 2 - U D L LU LD
 * 4 - L LD D RD R
 * 5 - D RD R
 * 6 - L LD D
 * 7 - L LU U RU R
 * 8 - U RU R
 * 9 - L LU U
 */

void boundaryConditions(uint8_t row , uint8_t column){
	uint8_t bound1=0,bound2=0;
	if(row==0)
		bound1=4;
	else if(row==27)
		bound1=7;
	if(column==0)
		bound2=1;
	else if(column==27)
		bound2=2;
	switch(bound1+bound2){
		case 0:{
			putDataToArray(row, column-1, 64); //L
			putDataToArray(row-1, column-1, 64); //LU
			putDataToArray(row-1, column, 64);//U
			putDataToArray(row, column, 255);
			putDataToArray(row-1, column+1,64);//RU
			putDataToArray(row, column+1, 64);//R
			putDataToArray(row+1, column+1, 64);//RD
			putDataToArray(row+1, column, 64);//D
			putDataToArray(row+1, column-1, 64);//LD

			break;
		}
		case 1:{// 1 - U D R RU RD
			putDataToArray(row+1, column, 64); //D
			putDataToArray(row+1, column+1, 64); //RD
			putDataToArray(row, column, 255);
			putDataToArray(row-1, column+1, 64);//RU
			putDataToArray(row-1, column, 64);//U
			putDataToArray(row, column+1, 64);//R
			break;
		}
		case 2:{//2 - U D L LU LD
			putDataToArray(row+1, column, 64);//D
			putDataToArray(row+1, column-1, 64);//LD
			putDataToArray(row, column, 255);
			putDataToArray(row-1, column-1, 64);//LU
			putDataToArray(row-1, column, 64);//U
			putDataToArray(row, column-1, 64);//L
			break;
		}
		case 4:{// 4 - L LD D RD R
			putDataToArray(row, column-1, 64);//L
			putDataToArray(row+1, column-1, 64);//LD
			putDataToArray(row, column, 255);
			putDataToArray(row+1, column+1, 64);//RD
			putDataToArray(row+1, column, 64);//D
			putDataToArray(row, column+1, 64);//R

			break;
		}
		case 5:{//5 - D RD R
			putDataToArray(row, column+1, 64);//R
			putDataToArray(row+1, column+1, 64);//RD
			putDataToArray(row, column, 255);
			putDataToArray(row+1, column, 64);//D
			break;
		}
		case 6:{// 6 - L LD D
			putDataToArray(row, column-1, 64);//L
			putDataToArray(row, column, 255);
			putDataToArray(row+1, column-1, 64);//LD
			putDataToArray(row+1, column, 64);//D
			break;
		}
		case 7:{//7 - L LU U RU R
			putDataToArray(row, column-1, 64);//L
			putDataToArray(row-1, column-1, 64);//LU
			putDataToArray(row, column, 255);
			putDataToArray(row-1, column+1, 64);//RU
			putDataToArray(row, column+1, 64);//R
			putDataToArray(row-1, column, 64);//U
			break;
		}
		case 8:{//8 - U RU R
			putDataToArray(row-1, column, 64);//U
			putDataToArray(row-1, column+1, 64);//RU
			putDataToArray(row, column, 255);
			putDataToArray(row, column+1, 64);//R
			break;
		}
		case 9:{//9 - L LU U
			putDataToArray(row-1, column, 64);//U
			putDataToArray(row-1, column-1, 64);//LU
			putDataToArray(row, column, 255);
			putDataToArray(row, column-1, 64);//L
			break;
		}
		default:{
			putDataToArray(row, column, 255);
			break;
		}


	}





}

void putDataToArray(uint8_t row , uint8_t column,uint16_t value){
	if(Screen.Atributs[MATRIX_RESOLUTION*row+column]<=128 &&value!=255){
		Screen.Atributs[MATRIX_RESOLUTION*row+column]+=value;
	}
	else if(Screen.Atributs[MATRIX_RESOLUTION*row+column]<=192 && value!=255){
		Screen.Atributs[MATRIX_RESOLUTION*row+column]+=value-1;
	}
	else{
		Screen.Atributs[MATRIX_RESOLUTION*row+column]=255;
	}
	ColorPixel(row, column);
}

void ColorPixel(uint16_t row , uint16_t column){
	uint16_t X0=LCD_WIDTH-2*PIXEL_SIZE-PIXEL_SIZE*column;
	uint16_t X1=LCD_WIDTH-PIXEL_SIZE-PIXEL_SIZE*column;
	uint16_t Y0=LCD_HEIGHT-PIXEL_SIZE-PIXEL_SIZE*row;
	uint16_t Y1=LCD_HEIGHT-2*PIXEL_SIZE-PIXEL_SIZE*row;
	if(Screen.Atributs[MATRIX_RESOLUTION*row+column]==64){
		Draw_Rect(X0, Y0, X1, Y1, SHAD4);
	}
	else if(Screen.Atributs[MATRIX_RESOLUTION*row+column]==128){
		Draw_Rect(X0, Y0, X1, Y1,SHAD3);
	}
	else if(Screen.Atributs[MATRIX_RESOLUTION*row+column]==192){
		Draw_Rect(X0, Y0, X1, Y1, SHAD2);
	}
	else if(Screen.Atributs[MATRIX_RESOLUTION*row+column]==255){
		Draw_Rect(X0, Y0, X1, Y1, SHAD1);
	}
	else{

		Draw_Rect(X0, Y0, X1, Y1, YELLOW);
	}



}


