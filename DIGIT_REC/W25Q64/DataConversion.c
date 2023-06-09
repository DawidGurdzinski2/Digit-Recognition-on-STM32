#include "DataConversion.h"


union DataConv data;

/*
  * @brief zamieniamy wartosc double na 8 bajtowa tablice uint8_t
  * @param  vlad - wartosc która rozbijamy na tablice
  * @param  valbuff - wskaznik na tablcie do której bedziemy wpisywac wartosci z rozbitego doubla
  * @retval None
*/
void SplitDouble(double vald,uint8_t* valbuff){
	uint8_t * pvald=(uint8_t*)&vald;
	for(uint8_t i=0;i<8;i++){
		valbuff[i]=pvald[i];
	}
}
/*
  * @brief zamieniamy wartosc 8 bajtowej tablicy zwracaja odtworzonego doubla
  * @param  valbuff - wskaznik na tablcie z której bedziemy pobierac wartosci do sklejenia doubla
  * @retval vlad - wartosc która zostałą odtworzona  z tablicy
*/
double  ReconstructDouble(uint8_t *valbuff){
	double vald;
	uint8_t * pvald=(uint8_t*)&vald;
	for(uint8_t i=0;i<8;i++){
		pvald[i]=valbuff[i];
	}
	return vald;
}

/*
  * @brief zamieniamy wartosc double na 8 bajtowa tablice uint8_t z zastosowaniem unni
  * @param  vlad - wartosc która rozbijamy na tablice
  * @param  valbuff - wskaznik na tablcie do której bedziemy wpisywac wartosci z rozbitego doubla
  * @retval None
*/
void SplitDoubleUnion(double vald,uint8_t* valbuff){
	data.d=vald;
	for(uint8_t i=0;i<8;i++){
		valbuff[i]=data.u[i];
	}
}
/*
  * @brief zamieniamy wartosc 8 bajtowej tablicy zwracaja odtworzonego doubla z uzyciem unni
  * @param  valbuff - wskaznik na tablcie z której bedziemy pobierac wartosci do sklejenia doubla
  * @retval vlad - wartosc która zostałą odtworzona  z tablicy
*/
double  ReconstructDoubleUnion(uint8_t *valbuff){
	for(uint8_t i=0;i<8;i++){
		data.u[i]=valbuff[i];
	}
	return data.d;
}
/*
  * @brief zamieniamy dwia znak ichar na jedna wartosc hex exmp:  ch1='F' ch2='1'  ->  hex_value=0xF1
  * @param  ch1- pierwsza wartosc char na wartosci hex
  * @param  ch2- druga wartosc char na wartosci hex
  * @retval hex_value - wartosc hexa któ©a zostałą utworzona z dówch charów
*/
uint8_t Hex_Chars_To_Hex(char ch1,char ch0){
	char hex_string[] = {ch1,ch0,0};
	int hex_value;
	sscanf(hex_string, "%2x", &hex_value);
	return (uint8_t)hex_value;
}
/*
  * @brief odwaraca tablice (pierwsza wartosc ostatnia a ostatnia pierwsza)
  * @param  buff - wskaznik na tablice ktora chcemy odwrocic
  * @param  bufflen - rozmiar tablicy
  * @retval None
*/

void Invert_Array(uint8_t *buff,uint16_t bufflen){
	uint16_t start=0;
	uint16_t end=bufflen-1;
	uint16_t i=30000;//zabezbieczenie max iter
	while(start<end &&  i>0){
		uint8_t temp = buff[start];
		buff[start] = buff[end];
		buff[end] = temp;
		start++;
		end--;
		i--;
	}
}







