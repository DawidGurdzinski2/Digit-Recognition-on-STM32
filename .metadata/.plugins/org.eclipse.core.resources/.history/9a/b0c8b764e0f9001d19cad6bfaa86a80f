#ifndef _W25Q64_H_
#define _W25Q64_H_


#include "gpio.h"
#include "spi.h"

#define PAGE_SIZE				256
#define SECTOR_SIZE				4096

typedef struct _MEMORY
{
	uint8_t manufacturer_ID;
	uint8_t memory_type;
	uint8_t capacity;

	uint16_t 		DC_Pin;
	GPIO_TypeDef * CS_port;
	uint16_t 		CS_Pin;
	SPI_HandleTypeDef * pSpi;


}MEMORY;



HAL_StatusTypeDef W25Q64_SPI_Transmit_Data(MEMORY * this,uint8_t *data, uint16_t size);
HAL_StatusTypeDef W25Q64_SPI_Receive_Data(MEMORY * this,uint8_t *data, uint16_t size);
void W25Q64_Set_ChipSelect_Low(MEMORY * this);
void W25Q64_Set_ChipSelect_High(MEMORY * this);
uint8_t W25Q64_Init(MEMORY * this);
void W25Q64_ResetFlash(MEMORY * this);
void W25Q64_get_JEDEC_ID(MEMORY * this);
void W25Q64_WriteEnable(MEMORY * this);
void W25Q64_WriteEnable_and_WaitForWriteEnableLatch(MEMORY * this);
void W25Q64_WaitForWriteEnableLatch(MEMORY * this);
void W25Q64_WaitForWriteInProgressClear(MEMORY * this);
HAL_StatusTypeDef W25Q64_SectorErase(MEMORY * this,uint16_t sector_number);
HAL_StatusTypeDef W25Q64_ChipErase(MEMORY * this);
HAL_StatusTypeDef W25Q64_PageProgram(MEMORY * this,uint32_t page_adress, uint8_t *data, uint16_t size);
HAL_StatusTypeDef W25Q64_ReadDataBytes(MEMORY * this,uint32_t adress, uint8_t *data, uint16_t size);
uint8_t W25Q64_ReadStatusRegister1(MEMORY * this);
uint8_t W25Q64_ReadStatusRegister2(MEMORY * this);
void W25Q64_WriteStatusRegister(MEMORY * this,uint8_t reg1, uint8_t reg2);





#define W25Q64_WRITE_IN_PROGRESS  	    0x01
#define W25Q64_WRITE_ENABLE_LATCH 	    0x02
#define W25Q64_WRITE_ENABLE				0x06
#define W25Q64_WRITE_DISABLE			0x04
#define W25Q64_READ_STATUS_REG1			0x05
#define W25Q64_READ_STATUS_REG2			0x35
#define W25Q64_WRITE_STATUS_REG			0x01
#define W25Q64_READ_DATA				0x03
#define W25Q64_PAGE_PROGRAM				0x02
#define W25Q64_SECTOR_ERASE				0x20
#define W25Q64_CHIP_ERASE				0xC7
#define W25Q64_ENABLE_RESET				0x66
#define W25Q64_RESET					0x99
#define	W25Q64_WIBOND_ID				0xEF
#define W25Q64_SPI_DEVICE_ID			0x40
#define W25Q64_CAPACITY_64_MBIT			0x17


#endif
