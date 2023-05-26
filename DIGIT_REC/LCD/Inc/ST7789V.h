


#ifndef __ST7789_H
#define __ST7789_H
#include "gpio.h"
#include "spi.h"
#include <string.h>



/*


B4 //0-UP-DOWN  1-DOWN-UP
B3 // 0 - RGB  1-BRG
B2 // 0 LEFT- RIGHT  1 RIGHT-LEFT
B1
B0
*/

typedef struct _ST7789V{


	GPIO_TypeDef * RST_Port;
	uint16_t		RST_Pin;
	GPIO_TypeDef * DC_Port;
	uint16_t 		DC_Pin;
	GPIO_TypeDef * CS_port;
	uint16_t 		CS_Pin;
	SPI_HandleTypeDef * pSpi;
	uint16_t LCD_Height;
	uint16_t LCD_Width;

}ST7789V;





void ST7789V_Init(ST7789V * this);
void ST7789V_Reset(ST7789V * this);
void ST7789V_WriteCommand(ST7789V * this,uint8_t cmd);
void ST7789V_WriteDataByte(ST7789V * this,uint8_t data);
void ST7789V_WriteData(ST7789V * this,uint8_t *buff,uint32_t buffSize);
void ST7789V_SetRotation(ST7789V * this);
void ST7789V_SetAdress(ST7789V* this,uint16_t X0,uint16_t Y0,uint16_t X1,uint16_t Y1);








//registers adresses

#define ST7789V_NOP_REG 0x00 //
#define	ST7789V_SWRESET_REG 0x01 //Software Reset
#define	ST7789V_RDDID_REG 0x04 //Read Display ID
#define ST7789V_RDDST_REG 0x09 //Read Display Status
#define	ST7789V_RDDPM_REG 0x0A //Read Display powermode
#define	ST7789V_RDDMADCTL_REG 0x0B //Read Display MADCTL
#define ST7789V_RDDCOLMOD_REG 0x0C //Read Display Pixel Format
#define ST7789V_RDDIM_REG 0x0D // Read Display Image Mode
#define ST7789V_RDDSM_REG 0x0E //Read Display Signal Mode
#define ST7789V_RDDSDR_REG 0x0F //Read Display Self-Diagnostic Result
#define ST7789V_SLPIN_REG 0x10 //Sleep in
#define ST7789V_SLPOUT_REG 0x11 //Sleep Out
#define ST7789V_PTLON_REG 0x12 //Partial Display Mode On
#define ST7789V_NORON_REG 0x13 //Normal Display Mode On
#define ST7789V_INVOFF_REG 0x20 //Display Inversion Off
#define ST7789V_INVON_REG 0x21 //Display Inversion On
#define ST7789V_GAMSET_REG 0x26 //Gamma Set
#define ST7789V_DISPOFF_REG 0x28 //Display Off
#define ST7789V_DISPON_REG 0x29//Display On
#define ST7789V_CASET_REG 0x2A // Column Address Set
#define ST7789V_RASET_REG 0x2B //Row Address Set
#define ST7789V_RAMWR_REG 0x2C //Memory Write
#define ST7789V_RAMRD_REG 0x2E // Memory Read
#define ST7789V_PTLAR_REG 0x30 // Partial Area
#define ST7789V_VSCRDEF_REG 0x33 //Vertical Scrolling Definition
#define ST7789V_TEOFF_REG 0x34 // Tearing Effect Line OFF
#define ST7789V_TEON_REG 0x35 // Tearing Effect Line On
#define ST7789V_MADCTL_REG 0x36 // Memory Data Access Control
#define ST7789V_VSCSAD_REG 0x37 // Vertical Scroll Start Address of RAM
#define ST7789V_IDMOFF_REG 0x38 // Idle Mode Off
#define ST7789V_IDMON_REG 0x39 // Idle mode on
#define ST7789V_COLMOD_REG 0x3A // Interface Pixel Format
#define ST7789V_WRMEMC_REG 0x3C //  Write Memory Continue
#define ST7789V_RDMEMC_REG 0x3E //  Read Memory Continue
#define ST7789V_STE_REG 0x44 // Set Tear Scanline
#define ST7789V_GSCAN_REG 0x45 //Get Scanline
#define ST7789V_WRDISBV_REG 0x51 //Write Display Brightness
#define ST7789V_RDDISBV_REG 0x52 //Read Display Brightness Value
#define ST7789V_WRCTRLD_REG 0x53 // Write CTRL Display
#define ST7789V_RDCTRLD_REG 0x54 // Read CTRL Value Display
#define ST7789V_WRCACE_REG 0x55 // Write Content Adaptive Brightness Control and Color Enhancement
#define ST7789V_RDCABC_REG 0x56 // Read Content Adaptive Brightness Control
#define ST7789V_WRCABCMB_REG 0x5E // Write CABC Minimum Brightness
#define ST7789V_RDCABCMB_REG 0x5F //Read CABC Minimum Brightness
#define ST7789V_RDABCSDR_REG 0x68 // Read Automatic Brightness Control Self-Diagnostic Result
#define ST7789V_RDID1_REG 0xDA //Read ID1
#define ST7789V_RDID2_REG 0xDB //Read ID2
#define ST7789V_RDID3_REG 0xDC //Read ID3
#define ST7789V_RAMCTRL_REG 0xB0 //RAM Control
#define ST7789V_RGBCTRL_REG 0xB1 //RGB Interface Control
#define ST7789V_PORCTRL_REG 0xB2 //Porch Setting
#define ST7789V_FRCTRL1_REG 0xB3 // Frame Rate Control 1 (In partial mode/ idle colors)
#define ST7789V_PARCTRL_REG 0xB5 //Partial mode Control
#define ST7789V_GCTRL_REG 0xB7 //Gate Control
#define ST7789V_GTADJ_REG 0xB8 //Gate On Timing Adjustment
#define ST7789V_DGMEN_REG 0xBA //Digital Gamma Enable
#define ST7789V_VCOMS_REG 0xBB //VCOMS Setting
#define ST7789V_LCMCTRL_REG 0xC0 //LCM Control
#define ST7789V_IDSET_REG 0xC1 // ID Code Setting
#define ST7789V_VDVVRHEN_REG 0xC2 //VDV and VRH Command Enable
#define ST7789V_VRHS_REG 0xC3 // VRH Set
#define ST7789V_VDVS_REG 0xC4 //VDV Set
#define ST7789V_VCMOFSET_REG 0xC5 //VCOMS Offset Set
#define ST7789V_FRCTRL2_REG 0xC6 // Frame Rate Control in Normal Mode
#define ST7789V_CABCCTRL_REG 0xC7 //CABC Control
#define ST7789V_REGSEL1_REG 0xC8 //Register Value Selection 1
#define ST7789V_REGSEL2_REG 0xCA // Register Value Selection 2
#define ST7789V_PWMFRSEL_REG 0xCC //PWM Frequency Selection
#define ST7789V_PWCTRL1_REG 0xD0 // Power Control 1
#define ST7789V_VAPVANEN_REG 0xD2 //Enable VAP/VAN signal output
#define ST7789V_CMD2EN_REG 0xDF // Command 2 Enable
#define ST7789V_PVGAMCTRL_REG 0xE0 // Positive Voltage Gamma Control
#define ST7789V_NVGAMCTRL_REG 0xE1 //Negative Voltage Gamma Control
#define ST7789V_DGMLUTR_REG 0xE2 //Digital Gamma Look-up Table for Red
#define ST7789V_DGMLUTB_REG 0xE3 //Digital Gamma Look-up Table for Blue
#define ST7789V_GATECTRL_REG 0xE4 // Gate Control
#define ST7789V_SPI2EN_REG 0xE7 //SPI2 Enable
#define ST7789V_PWCTRL2_REG 0xE8 //Power Control 2
#define ST7789V_EQCTRL_REG 0xE9 //Equalize time control
#define ST7789V_PROMCTRL_REG 0xEC // Program Mode Control
#define ST7789V_PROMEN_REG 0xFA //Program Mode Enable
#define ST7789V_NVMSET_REG 0xFC //NVM Setting
#define ST7789V_PROMACT_REG 0xFE //Program action


#endif /* __ST7789V_H */
