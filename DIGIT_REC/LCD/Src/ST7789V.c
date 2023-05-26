

#include "ST7789V.h"
#include "ST7789V_GFX.h"





void ST7789V_Init(ST7789V * this){

	this->CS_port=LCD_CS_GPIO_Port;
	this->CS_Pin=LCD_CS_Pin;
	this->RST_Port=LCD_RST_GPIO_Port;
	this->RST_Pin=LCD_RST_Pin;
	this->DC_Port=LCD_DC_GPIO_Port;
	this->DC_Pin=LCD_DC_Pin;
	this->pSpi=&hspi1;
	this->LCD_Height=320;
	this->LCD_Width=240;

	ST7789V_Reset(this);


	//////////////////////////////////
	ST7789V_WriteCommand(this, ST7789V_COLMOD_REG);
	ST7789V_WriteDataByte(this, 0X55);//16 bit mode

	ST7789V_WriteCommand(this, ST7789V_INVON_REG);
	ST7789V_WriteCommand(this, ST7789V_SLPOUT_REG);
	ST7789V_WriteCommand(this, ST7789V_NORON_REG);
	ST7789V_WriteCommand(this, ST7789V_DISPON_REG);
	ST7789V_WriteCommand(this, 0x01);
	HAL_Delay(10);
	ST7789V_WriteCommand(this, 0x11);
	HAL_Delay(100);
	ST7789V_WriteCommand(this, 0x29);

	ST7789V_SetRotation(this);

	ST7789V_SetAdress(this,0, 0, 240, 320);
	ST7789V_DrawRect(this,0, 0, 240, 320, 0x0000);

}


void ST7789V_Reset(ST7789V * this){


	HAL_GPIO_WritePin(this->RST_Port, this->RST_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(this->CS_port,this->CS_Pin, GPIO_PIN_RESET);
	HAL_Delay(30);
	HAL_GPIO_WritePin(this->RST_Port, this->RST_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(this->CS_port,this->CS_Pin, GPIO_PIN_SET);

	HAL_Delay(30);


}


void ST7789V_WriteCommand(ST7789V * this,uint8_t cmd){
	HAL_GPIO_WritePin(this->CS_port,this->CS_Pin , GPIO_PIN_RESET);
	HAL_GPIO_WritePin(this->DC_Port,this->DC_Pin, GPIO_PIN_RESET);
	while(!__HAL_SPI_GET_FLAG(this->pSpi, SPI_FLAG_TXE));
	HAL_SPI_Transmit(this->pSpi, &cmd, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(this->CS_port,this->CS_Pin , GPIO_PIN_SET);

}

void ST7789V_WriteDataByte(ST7789V * this,uint8_t data){

	HAL_GPIO_WritePin(this->CS_port,this->CS_Pin , GPIO_PIN_RESET);
	HAL_GPIO_WritePin(this->DC_Port,this->DC_Pin, GPIO_PIN_SET);
	while(!__HAL_SPI_GET_FLAG(this->pSpi, SPI_FLAG_TXE));
	HAL_SPI_Transmit(this->pSpi, &data, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(this->CS_port,this->CS_Pin , GPIO_PIN_SET);


}


void ST7789V_WriteData(ST7789V * this,uint8_t *buff,uint32_t buffSize){

	HAL_GPIO_WritePin(this->CS_port,this->CS_Pin , GPIO_PIN_RESET);
	HAL_GPIO_WritePin(this->DC_Port,this->DC_Pin, GPIO_PIN_SET);

	uint16_t DataSize;
	uint32_t buffsize=buffSize;
	while(buffsize>0){
		if (buffsize>65535)
			DataSize=65535;
		else
			DataSize=buffsize;
		HAL_SPI_Transmit_DMA(this->pSpi, buff,DataSize);
		while (this->pSpi->hdmatx->State != HAL_DMA_STATE_READY);
		buff+=DataSize;
		buffsize-=DataSize;

	}
	HAL_GPIO_WritePin(this->CS_port,this->CS_Pin , GPIO_PIN_SET);
}


void ST7789V_SetRotation(ST7789V * this){
	ST7789V_WriteCommand(this,ST7789V_MADCTL_REG);
	HAL_Delay(1);
	ST7789V_WriteDataByte(this, 0x00|0x00);
	this->LCD_Height=320;
	this->LCD_Width=240;

}


void ST7789V_SetAdress(ST7789V* this,uint16_t X0,uint16_t Y0,uint16_t X1,uint16_t Y1){
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
	ST7789V_WriteCommand(this, ST7789V_CASET_REG);
	uint8_t adressX[4]={X0>>8,X0 & 0xFF,X1>>8,X1 & 0xFF};
	ST7789V_WriteData(this, adressX, 4);
	ST7789V_WriteCommand(this, ST7789V_RASET_REG);
	uint8_t adressY[4]={Y0>>8,Y0 & 0xFF,Y1>>8,Y1 & 0xFF};
	ST7789V_WriteData(this, adressY, 4);
	ST7789V_WriteCommand(this, ST7789V_RAMWR_REG);


}





