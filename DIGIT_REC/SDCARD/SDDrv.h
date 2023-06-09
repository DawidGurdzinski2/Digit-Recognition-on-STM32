#ifndef _SDDRV_H_
#define _SDDRV_H_

#include "fatfs.h"

//#define BUF4KB
//#define BUF8KB
//#define BUF12KB
#define BUF16KB

#define F4KB 4096
#define DATASIZE 4080
typedef  struct  _SD_Iterface{
	FATFS fs;
	FIL fil;
	UINT bw,br;
	uint8_t fresult;
	uint8_t buffer[513];
	uint8_t convertet[256];




}SD_Iterface;



typedef struct _NET_INFO{
	//pierwsza warstwa
	uint32_t page_addres_W1_start; //strona od której zaczynaja sie wagi  w pamieci
	uint32_t page_addres_W1_vector_size; // ilosc stron potrzebnych na zapis jednego wektora
	uint32_t W1_size; //ile takich wektorów wag
	uint32_t W1_pages_size; //ile stron na wszystkie wagi
	uint32_t page_addres_B1_start;//strona od kóßrej zaczynaja sie biasy w pamieci
	uint32_t B1_pages_size; //ile stron na wszsystki biasy
	//druga warstwa
	uint32_t page_addres_W2_start; //strona od której zaczynaja sie wagi  w pamieci
	uint32_t page_addres_W2_vector_size; // ilosc stron potrzebnych na zapis jednego wektora
	uint32_t W2_size; //ile takich wektorów wag
	uint32_t W2_pages_size; //ile stron na wszystkie wagi
	uint32_t page_addres_B2_start;//strona od kóßrej zaczynaja sie biasy w pamieci
	uint32_t B2_pages_size; //ile stron na wszsystki biasy

	//trzecia  warstwa
	uint32_t page_addres_W3_start; //strona od której zaczynaja sie wagi  w pamieci
	uint32_t page_addres_W3_vector_size; // ilosc stron potrzebnych na zapis jednego wektora
	uint32_t W3_size; //ile takich wektorów wag
	uint32_t W3_pages_size; //ile stron na wszystkie wagi
	uint32_t page_addres_B3_start;//strona od kóßrej zaczynaja sie biasy w pamieci
	uint32_t B3_pages_size; //ile stron na wszsystki biasy




}NET_INFO;

void INIT_NETINFO(NET_INFO* this);
void readDataPacked(SD_Iterface * this,const TCHAR* path);
void mountSDcard(SD_Iterface * this);
void openFile(SD_Iterface * this,const TCHAR* path,BYTE mode);
void closeFile(SD_Iterface * this);
void writeDataPacked(SD_Iterface * this,const TCHAR* path);






#endif
