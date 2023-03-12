


#ifndef __ST7789_H
#define __ST7789_H
#include "gpio.h"
#include "spi.h"

#define SPI_PORT hspi1
extern SPI_HandleTypeDef SPI_PORT;

/*


B4 //0-UP-DOWN  1-DOWN-UP
B3 // 0 - RGB  1-BRG
B2 // 0 LEFT- RIGHT  1 RIGHT-LEFT
B1
B0
*/



#define RST_PORT LCD_RST_GPIO_Port
#define RST_PIN  LCD_RST_Pin
#define DC_PORT  LCD_DC_GPIO_Port
#define DC_PIN   LCD_DC_Pin
#define CS_PORT  LCD_CS_GPIO_Port
#define CS_PIN   LCD_CS_Pin


void Init(void);
void Write_Command(uint8_t);
void Write_Data_byte(uint8_t);
void Write_Data(uint8_t *,uint32_t);
void Set_Rotation(void);
void Set_Adress(uint16_t,uint16_t,uint16_t,uint16_t);





//registers adresses

#define NOP_REG 0x00 //
#define	SWRESET_REG 0x01 //Software Reset
#define	RDDID_REG 0x04 //Read Display ID
#define RDDST_REG 0x09 //Read Display Status
#define	RDDPM_REG 0x0A //Read Display powermode
#define	RDDMADCTL_REG 0x0B //Read Display MADCTL
#define RDDCOLMOD_REG 0x0C //Read Display Pixel Format
#define RDDIM_REG 0x0D // Read Display Image Mode
#define RDDSM_REG 0x0E //Read Display Signal Mode
#define RDDSDR_REG 0x0F //Read Display Self-Diagnostic Result
#define SLPIN_REG 0x10 //Sleep in
#define SLPOUT_REG 0x11 //Sleep Out
#define PTLON_REG 0x12 //Partial Display Mode On
#define NORON_REG 0x13 //Normal Display Mode On
#define INVOFF_REG 0x20 //Display Inversion Off
#define INVON_REG 0x21 //Display Inversion On
#define GAMSET_REG 0x26 //Gamma Set
#define DISPOFF_REG 0x28 //Display Off
#define DISPON_REG 0x29//Display On
#define CASET_REG 0x2A // Column Address Set
#define RASET_REG 0x2B //Row Address Set
#define RAMWR_REG 0x2C //Memory Write
#define RAMRD_REG 0x2E // Memory Read
#define PTLAR_REG 0x30 // Partial Area
#define VSCRDEF_REG 0x33 //Vertical Scrolling Definition
#define TEOFF_REG 0x34 // Tearing Effect Line OFF
#define TEON_REG 0x35 // Tearing Effect Line On
#define MADCTL_REG 0x36 // Memory Data Access Control
#define VSCSAD_REG 0x37 // Vertical Scroll Start Address of RAM
#define IDMOFF_REG 0x38 // Idle Mode Off
#define IDMON_REG 0x39 // Idle mode on
#define COLMOD_REG 0x3A // Interface Pixel Format
#define WRMEMC_REG 0x3C //  Write Memory Continue
#define RDMEMC_REG 0x3E //  Read Memory Continue
#define STE_REG 0x44 // Set Tear Scanline
#define GSCAN_REG 0x45 //Get Scanline
#define WRDISBV_REG 0x51 //Write Display Brightness
#define RDDISBV_REG 0x52 //Read Display Brightness Value
#define WRCTRLD_REG 0x53 // Write CTRL Display
#define RDCTRLD_REG 0x54 // Read CTRL Value Display
#define WRCACE_REG 0x55 // Write Content Adaptive Brightness Control and Color Enhancement
#define RDCABC_REG 0x56 // Read Content Adaptive Brightness Control
#define WRCABCMB_REG 0x5E // Write CABC Minimum Brightness
#define RDCABCMB_REG 0x5F //Read CABC Minimum Brightness
#define RDABCSDR_REG 0x68 // Read Automatic Brightness Control Self-Diagnostic Result
#define RDID1_REG 0xDA //Read ID1
#define RDID2_REG 0xDB //Read ID2
#define RDID3_REG 0xDC //Read ID3
#define RAMCTRL_REG 0xB0 //RAM Control
#define RGBCTRL_REG 0xB1 //RGB Interface Control
#define PORCTRL_REG 0xB2 //Porch Setting
#define FRCTRL1_REG 0xB3 // Frame Rate Control 1 (In partial mode/ idle colors)
#define PARCTRL_REG 0xB5 //Partial mode Control
#define GCTRL_REG 0xB7 //Gate Control
#define GTADJ_REG 0xB8 //Gate On Timing Adjustment
#define DGMEN_REG 0xBA //Digital Gamma Enable
#define VCOMS_REG 0xBB //VCOMS Setting
#define LCMCTRL_REG 0xC0 //LCM Control
#define IDSET_REG 0xC1 // ID Code Setting
#define VDVVRHEN_REG 0xC2 //VDV and VRH Command Enable
#define VRHS_REG 0xC3 // VRH Set
#define VDVS_REG 0xC4 //VDV Set
#define VCMOFSET_REG 0xC5 //VCOMS Offset Set
#define FRCTRL2_REG 0xC6 // Frame Rate Control in Normal Mode
#define CABCCTRL_REG 0xC7 //CABC Control
#define REGSEL1_REG 0xC8 //Register Value Selection 1
#define REGSEL2_REG 0xCA // Register Value Selection 2
#define PWMFRSEL_REG 0xCC //PWM Frequency Selection
#define PWCTRL1_REG 0xD0 // Power Control 1
#define VAPVANEN_REG 0xD2 //Enable VAP/VAN signal output
#define CMD2EN_REG 0xDF // Command 2 Enable
#define PVGAMCTRL_REG 0xE0 // Positive Voltage Gamma Control
#define NVGAMCTRL_REG 0xE1 //Negative Voltage Gamma Control
#define DGMLUTR_REG 0xE2 //Digital Gamma Look-up Table for Red
#define DGMLUTB_REG 0xE3 //Digital Gamma Look-up Table for Blue
#define GATECTRL_REG 0xE4 // Gate Control
#define SPI2EN_REG 0xE7 //SPI2 Enable
#define PWCTRL2_REG 0xE8 //Power Control 2
#define EQCTRL_REG 0xE9 //Equalize time control
#define PROMCTRL_REG 0xEC // Program Mode Control
#define PROMEN_REG 0xFA //Program Mode Enable
#define NVMSET_REG 0xFC //NVM Setting
#define PROMACT_REG 0xFE //Program action


#endif /* __ST7789V_H */
