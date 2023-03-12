#include "ST7789V.h"
#include "ST7789V_GFX.h"

/*TODO
 *
 * Draw Line HOR
 * Draw Line VER
 * Draw Line
 * Draw Circle HOL
 * Draw Circle FIL +
 * Draw Font
 * Draw Text
 *
 *
 *
 *
*/





void Draw_Pixel(uint16_t X,uint16_t Y,uint16_t color){
	Set_Adress(X, Y, X+1, Y+1);
	uint8_t adressC[2]={color>>8,color & 0xFF};
	Write_Data(adressC,2);


}


void Draw_Rect(uint16_t X0,uint16_t Y0,uint16_t X1,uint16_t Y1,uint16_t color){
	if(X0>X1){
		uint16_t temp1=X0;
		X0=X1;
		X1=temp1;
	}

	if(Y0>Y1){
		uint16_t temp2=Y0;
		Y0=Y1;
		Y1=temp2;
	}

	Set_Adress(X0, Y0, X1, Y1);
	uint16_t X_size=X1-X0+1;
	uint16_t Y_size=Y1-Y0+1;
	uint8_t colorA=color>>8;
	uint8_t colorB=color & 0xFF;
	uint32_t dataSize=X_size*Y_size*2;
	uint32_t chunkDataSize=200*2; //even number
	uint32_t chunks=dataSize/chunkDataSize;
	uint32_t restDataSize=dataSize-chunks*chunkDataSize;

	uint8_t buff[chunkDataSize];
	uint8_t buffRest[restDataSize];
	for(uint32_t i =0;i<chunkDataSize;i+=2){
		buff[i]=colorA;
		buff[i+1]=colorB;
	}
	for(uint32_t i =0;i<restDataSize;i+=2){
		buffRest[i]=colorA;
		buffRest[i+1]=colorB;
	}
	for(uint16_t i=0;i<chunks;i++){
		Write_Data(buff, chunkDataSize);

	}
	Write_Data(buffRest, restDataSize);
}


void Draw_Circle(uint16_t X ,uint16_t Y,uint16_t radius ,uint16_t color){
	int rad = radius;
	int y = 0;
	int xChange = 1 - (radius << 1);
	int yChange = 0;
	int radiusError = 0;
	while (rad >= y)
	{
		for (int i = X - rad; i <= X + rad; i++)
		{
			Draw_Pixel(i, Y + y,color);
			Draw_Pixel(i, Y - y,color);
		}
		for (int i = X - y; i <= X + y; i++)
		{
			Draw_Pixel(i, Y + rad,color);
			Draw_Pixel(i, Y - rad,color);
		}
		y++;
		radiusError += yChange;
		yChange += 2;
		if (((radiusError << 1) + xChange) > 0)
		{
			rad--;
			radiusError += xChange;
			xChange += 2;
		}
	}
}


