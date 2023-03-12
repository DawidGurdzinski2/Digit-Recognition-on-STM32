
#define USE_DMA
#include "ST7789V.h"
#include <string.h>
#include "ST7789V_GFX.h"

volatile uint16_t LCD_HEIGHT = 320;
volatile uint16_t LCD_WIDTH	=240;


void Init(){


	HAL_GPIO_WritePin(RST_PORT, RST_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);
	HAL_Delay(30);
	HAL_GPIO_WritePin(RST_PORT, RST_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);
	HAL_Delay(30);
	//////////////////////////////////
	Write_Command(COLMOD_REG);
	Write_Data_byte(0x55); //16 bit mode

	Write_Command(INVON_REG);
	Write_Command(SLPOUT_REG);
	Write_Command(NORON_REG);
	Write_Command(DISPON_REG);
	Write_Command(0x01);
	HAL_Delay(10);
	Write_Command(0x11);
	HAL_Delay(100);
	Write_Command(0x29);

	Set_Rotation();
	Set_Adress(0, 0, 240, 320);
	Draw_Rect(0, 0, 240, 320, 0x0000);

}




void Write_Command(uint8_t cmd){
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DC_PORT, DC_PIN, GPIO_PIN_RESET);
	while(!__HAL_SPI_GET_FLAG(&SPI_PORT, SPI_FLAG_TXE));
	HAL_SPI_Transmit(&SPI_PORT, &cmd, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);

}

void Write_Data_byte(uint8_t data){
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DC_PORT, DC_PIN, GPIO_PIN_SET);
	while(!__HAL_SPI_GET_FLAG(&SPI_PORT, SPI_FLAG_TXE));
	HAL_SPI_Transmit(&SPI_PORT, &data, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);

}


void Write_Data(uint8_t *buff,uint32_t buffSize){
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DC_PORT, DC_PIN, GPIO_PIN_SET);
	uint16_t DataSize;
	uint32_t buffsize=buffSize;
	while(buffsize>0){
		if (buffsize>65535)
			DataSize=65535;
		else
			DataSize=buffsize;
		HAL_SPI_Transmit_DMA(&SPI_PORT, buff,DataSize);
		while (SPI_PORT.hdmatx->State != HAL_DMA_STATE_READY)
		{}
		buff+=DataSize;
		buffsize-=DataSize;

	}
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);
}


void Set_Rotation(void){
	Write_Command(MADCTL_REG);
	HAL_Delay(1);
	Write_Data_byte(0x00|0x00);
	LCD_HEIGHT=320;
	LCD_WIDTH=240;
}


void Set_Adress(uint16_t X0,uint16_t Y0,uint16_t X1,uint16_t Y1){
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
	Write_Command(CASET_REG);
	uint8_t adressX[4]={X0>>8,X0 & 0xFF,X1>>8,X1 & 0xFF};
	Write_Data(adressX,4);
	Write_Command(RASET_REG);
	uint8_t adressY[4]={Y0>>8,Y0 & 0xFF,Y1>>8,Y1 & 0xFF};
	Write_Data(adressY,4);
	Write_Command(RAMWR_REG);

}







