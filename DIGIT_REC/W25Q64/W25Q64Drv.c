#include "W25Q64Drv.h"



HAL_StatusTypeDef W25Q64_SPI_Transmit_Data(MEMORY * this,uint8_t *data, uint16_t size){
	HAL_StatusTypeDef status;

	status = HAL_SPI_Transmit(this->pSpi, data, size, 1000);

	return status;
}

HAL_StatusTypeDef W25Q64_SPI_Receive_Data(MEMORY * this,uint8_t *data, uint16_t size){
	HAL_StatusTypeDef status;

	status = HAL_SPI_Receive(this->pSpi, data, size, 1000);

	return status;
}

void W25Q64_Set_ChipSelect_Low(MEMORY * this){
	HAL_GPIO_WritePin(this->CS_port, this->CS_Pin, GPIO_PIN_RESET);
}

void W25Q64_Set_ChipSelect_High(MEMORY * this){
	HAL_GPIO_WritePin(this->CS_port, this->CS_Pin, GPIO_PIN_SET);
}

uint8_t W25Q64_Init(MEMORY * this){
	this->CS_port=W25Q64_CS_GPIO_Port;
	this->CS_Pin=W25Q64_CS_Pin;
	this->pSpi=&hspi3;


	W25Q64_ResetFlash(this);
	W25Q64_get_JEDEC_ID(this);

	if(W25Q64_WIBOND_ID	 == this->manufacturer_ID && W25Q64_SPI_DEVICE_ID == this->memory_type && W25Q64_CAPACITY_64_MBIT	 == this->capacity)
		return HAL_OK;
	else
		return HAL_ERROR;
}


void W25Q64_ResetFlash(MEMORY * this){
	uint8_t data_to_send[] = { W25Q64_ENABLE_RESET	, W25Q64_RESET };

	W25Q64_Set_ChipSelect_Low(this);
	W25Q64_SPI_Transmit_Data(this,data_to_send, 1);
	W25Q64_Set_ChipSelect_High(this);

    W25Q64_Set_ChipSelect_Low(this);
	W25Q64_SPI_Transmit_Data(this,&data_to_send[1], 1);
	W25Q64_Set_ChipSelect_High(this);
}

void W25Q64_get_JEDEC_ID(MEMORY * this){
	uint8_t data_to_send = 0x9F;
	uint8_t receive_data[3] = { 0, 0, 0 };

	W25Q64_Set_ChipSelect_Low(this);

	W25Q64_SPI_Transmit_Data(this,&data_to_send, 1);
	W25Q64_SPI_Receive_Data(this,receive_data, 3);

	W25Q64_Set_ChipSelect_High(this);

	this->manufacturer_ID = receive_data[0];
	this->memory_type = receive_data[1];
	this->capacity = receive_data[2];
}



void W25Q64_WriteEnable(MEMORY * this){
	uint8_t data_to_send =  W25Q64_WRITE_ENABLE;

	W25Q64_Set_ChipSelect_Low(this);
	W25Q64_SPI_Transmit_Data(this,&data_to_send, 1);
	W25Q64_Set_ChipSelect_High(this);
}

void W25Q64_WriteEnable_and_WaitForWriteEnableLatch(MEMORY * this){
	while(!(W25Q64_ReadStatusRegister1(this) & W25Q64_WRITE_ENABLE_LATCH))
	{
		W25Q64_WriteEnable(this);
	}
}

void W25Q64_WaitForWriteEnableLatch(MEMORY * this){
	while(!(W25Q64_ReadStatusRegister1(this) & W25Q64_WRITE_ENABLE_LATCH)){};
}

void W25Q64_WaitForWriteInProgressClear(MEMORY * this){
	while((W25Q64_ReadStatusRegister1(this) & W25Q64_WRITE_IN_PROGRESS)){};
}


HAL_StatusTypeDef W25Q64_SectorErase(MEMORY * this,uint16_t sector_number){
	uint32_t adress;
	adress = sector_number * SECTOR_SIZE;
	uint8_t data_to_send[] = { 0, 0, 0, 0 };
	HAL_StatusTypeDef status;

	W25Q64_WaitForWriteInProgressClear(this);
	W25Q64_WriteEnable_and_WaitForWriteEnableLatch(this);

	data_to_send[0] = W25Q64_SECTOR_ERASE;
	data_to_send[1] = (adress >> 16) & 0xff;
	data_to_send[2] = (adress >> 8) & 0xff;
	data_to_send[3] = adress & 0xff;

	W25Q64_Set_ChipSelect_Low(this);
	status = W25Q64_SPI_Transmit_Data(this,data_to_send, 4);
	W25Q64_Set_ChipSelect_High(this);

	W25Q64_WaitForWriteInProgressClear(this);

	return status;
}

HAL_StatusTypeDef W25Q64_ChipErase(MEMORY * this){
	uint8_t data_to_send =  W25Q64_SECTOR_ERASE	;
	HAL_StatusTypeDef status;

	W25Q64_WaitForWriteInProgressClear(this);
	W25Q64_WriteEnable_and_WaitForWriteEnableLatch(this);

	W25Q64_Set_ChipSelect_Low(this);
	status = W25Q64_SPI_Transmit_Data(this,&data_to_send, 1);
	W25Q64_Set_ChipSelect_High(this);

	W25Q64_WaitForWriteInProgressClear(this);

	return status;
}


HAL_StatusTypeDef W25Q64_PageProgram(MEMORY * this,uint32_t page_adress, uint8_t *data, uint16_t size){
	uint8_t data_to_send[] = { 0, 0, 0, 0 };
	HAL_StatusTypeDef status;

	W25Q64_WaitForWriteInProgressClear(this);
	W25Q64_WriteEnable_and_WaitForWriteEnableLatch(this);
	data_to_send[0] = W25Q64_PAGE_PROGRAM;
	data_to_send[1] = (page_adress >> 16) & 0xff;
	data_to_send[2] = (page_adress >> 8) & 0xff;
	data_to_send[3] = page_adress & 0xff;

	W25Q64_Set_ChipSelect_Low(this);
	W25Q64_SPI_Transmit_Data(this,data_to_send, 4);
	status = W25Q64_SPI_Transmit_Data(this,data, size);
	W25Q64_Set_ChipSelect_High(this);
	return status;
}






HAL_StatusTypeDef W25Q64_ReadDataBytes(MEMORY * this,uint32_t adress, uint8_t *data, uint16_t size){
	uint8_t data_to_send[] = { 0, 0, 0, 0 };
	HAL_StatusTypeDef status;

	W25Q64_WaitForWriteInProgressClear(this);

	data_to_send[0] = W25Q64_READ_DATA;
	data_to_send[1] = (adress >> 16) & 0xff;
	data_to_send[2] = (adress >> 8) & 0xff;
	data_to_send[3] = adress & 0xff;

	W25Q64_Set_ChipSelect_Low(this);
	W25Q64_SPI_Transmit_Data(this,data_to_send, 4);
	status = W25Q64_SPI_Receive_Data(this,data, size);
	W25Q64_Set_ChipSelect_High(this);

	return status;
}






uint8_t W25Q64_ReadStatusRegister1(MEMORY * this){
	uint8_t data_to_send = W25Q64_READ_STATUS_REG1;
	uint8_t receive_data = 0;

	W25Q64_Set_ChipSelect_Low(this);
	W25Q64_SPI_Transmit_Data(this,&data_to_send, 1);
	W25Q64_SPI_Receive_Data(this,&receive_data, 1);
	W25Q64_Set_ChipSelect_High(this);

	return receive_data;
}

uint8_t W25Q64_ReadStatusRegister2(MEMORY * this){
	uint8_t data_to_send = W25Q64_READ_STATUS_REG2;
	uint8_t receive_data = 0;

	W25Q64_Set_ChipSelect_Low(this);
	W25Q64_SPI_Transmit_Data(this,&data_to_send, 1);
	W25Q64_SPI_Receive_Data(this,&receive_data, 1);
	W25Q64_Set_ChipSelect_High(this);

	return receive_data;
}

void W25Q64_WriteStatusRegister(MEMORY * this,uint8_t reg1, uint8_t reg2){
	uint8_t data_to_send[] = { 0, 0, 0 };

	W25Q64_WriteEnable_and_WaitForWriteEnableLatch(this);

	data_to_send[0] = W25Q64_WRITE_STATUS_REG;
	data_to_send[1] = reg1;
	data_to_send[2] = reg2;

	W25Q64_Set_ChipSelect_Low(this);
	W25Q64_SPI_Transmit_Data(this,data_to_send, 2);
	W25Q64_Set_ChipSelect_High(this);
}











