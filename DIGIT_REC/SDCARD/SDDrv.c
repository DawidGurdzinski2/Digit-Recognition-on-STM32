


#include <stdio.h>
#include <string.h>
#include "SDDrv.h"
#include "fatfs.h"


/*
  * @brief 	Inicjalizuje parametry i dane potrzebne do sieci neuronowej
  * @param  this - wskaznik na strukture NET_INFO
  * @retval None
*/

void INIT_NETINFO(NET_INFO* this){

	//TU BEDZIE SIE ZCZYTYWAC DANE Z 1 STRONY KARY SD
	//WARTOSCI PONIZEJ SA TESTOWE
	this->page_addres_W1_start=1;
	this->page_addres_W1_vector_size=25;
	this->W1_size=1024;
	this->W1_pages_size=25*1024;
	this->page_addres_B1_start=25*1024+1;
	this->B1_pages_size=32;

	this->page_addres_W2_start=(1024*25)+(1+32);
	this->page_addres_W2_vector_size=32;
	this->W2_size=512;
	this->W2_pages_size=32*512;
	this->page_addres_B2_start=(1024*25)+(1+32)+32*512;
	this->B2_pages_size=16;

	this->page_addres_W3_start=(1024*25)+(1+32)+32*512 +16;
	this->page_addres_W3_vector_size=16;
	this->W3_size=10;
	this->W3_pages_size=16*10;
	this->page_addres_B3_start=(1024*25)+(1+32)+32*512+16*10;
	this->B3_pages_size=1;
}


/*
  * @brief 	Montuje karte SD (czynnosc któ©a nalezy wykonac aby korzystac z karty sd)
  * @param  this - wskaznik na strukture SD_Interface
  * @retval None
*/
void mountSDcard(SD_Iterface * this){

	this->fresult=f_mount(&(this->fs), SDPath, 0);
	HAL_Delay(100);

}

/*
  * @brief 	otwiera plik na karcie sd
  * @param  this - wskaznik na strukture SD_Interface
  * @param  path - nazwa pliku ktory chemy otworzyc
  * @param  mode - tryb w jakim checmy plik otworzyc (write read etc)
  * @retval None
*/
void openFile(SD_Iterface * this,const TCHAR* path,BYTE mode){

	this->fresult=f_open(&(this->fil), path,mode);
}

/*
  * @brief 	zamyka plik
  * @param  this - wskaznik na strukture SD_Interface
  * @retval None
*/
void closeFile(SD_Iterface * this){

	this->fresult=f_close(&(this->fil));
}


/*
  * @brief 	wpisuje dane zawarte w struktuże SD_interface do karty sd
  * @param  this - wskaznik na strukture SD_Interface
  * @param  path - nazwa pliku do którego chcemy zapisac dane
  * @retval None
*/
void writeDataPacked(SD_Iterface * this,const TCHAR* path){
	this->fresult=f_write(&(this->fil), this->buffer,  512, &(this->bw));
}
/*
  * @brief odczytuje  dane zawarte w  kartcie sd do tablicy w strukturze SD_Iterface  (tak wiem interface n zgubiłem XD)
  * @param  this - wskaznik na strukture SD_Interface
  * @param  path - nazwa pliku z którego chcemy odczytac dane
  * @retval None
*/

void readDataPacked(SD_Iterface * this,const TCHAR* path){
	this->fresult=f_read(&(this->fil), this->buffer,  512, &(this->br));

}





