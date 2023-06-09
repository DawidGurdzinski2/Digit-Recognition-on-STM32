#include "ForwardPass.h"

/*
  * @brief Inicjalizuje strukture Linear czyli strukture zawierajacą informacje o parametrach
  * warstwy sieci neuronowej
  * @param  this - wskaznik na strukture Linear
  * @param Net_size - ilosc neuronóœ w warstwie
  * @retval None
*/

void Init_ForwardPass(ForwardPass * this,NET * net,NET_INFO * ndata,MEMORY * mem){
	this->w28q64=mem;
	this->NeuralNetwork=net;
	this->net_data=ndata;
}

/*
  * @brief WPISUJEMY do tablicy na wejsciu warstwy dane wartosci z tablicy buff
  * @param  this - wskaznik na strukture ForwardPass
  * @param buff - wskaznik na tablice kóra wpisujemy do tablicy DATABUF
  * @retval None
*/
void FP_Load_Input(ForwardPass * this,uint8_t * buff){
	for(uint16_t i=0;i<INPUT_SIZE;i++){
		this->DATABUF[i]=((double)(buff[i]))/255;
	}
}

/*
  * @brief Odczytujemy z pamieci wektor wag pierwszej warstwy i wpisujemy go do tablicy wag WEIGHTBUFF
  * @param  this - wskaznik na strukture ForwardPass
  * @param 	vector number - numer wektora do zczytania z pamieci
  * @retval None
*/
void FP_Load_W1_wector(ForwardPass * this,uint32_t vector_number){
	//1023 max index wektora
	for(uint32_t i=0;i<this->net_data->page_addres_W1_vector_size;i++){
		uint8_t read_buffer[W25Q64_PAGE_SIZE];
		uint8_t convert_buff[8];
		W25Q64_ReadDataBytes(this->w28q64,W25Q64_PAGE_SIZE*(this->net_data->page_addres_W1_start +i+this->net_data->page_addres_W1_vector_size*vector_number), read_buffer, W25Q64_PAGE_SIZE);
		for(uint32_t j=0;j<32;j++){
			convert_buff[0]=read_buffer[i*8];
			convert_buff[1]=read_buffer[i*8+1];
			convert_buff[2]=read_buffer[i*8+2];
			convert_buff[3]=read_buffer[i*8+3];
			convert_buff[4]=read_buffer[i*8+4];
			convert_buff[5]=read_buffer[i*8+5];
			convert_buff[6]=read_buffer[i*8+6];
			convert_buff[7]=read_buffer[i*8+7];
			this->WEIGHTBUFF[i*32+j]=ReconstructDouble(convert_buff);
		}
	}
}

/*
  * @brief Odczytujemy z pamieci biasy dla pierwszej  warstwy i wpisujemy go do tablicy biasów BIAS
  * @param  this - wskaznik na strukture ForwardPass
  * @retval None
*/
void FP_Load_B1(ForwardPass * this){
	//1023 max index wektora
	for(uint32_t i=0;i<this->net_data->B1_pages_size;i++){
		uint8_t read_buffer[W25Q64_PAGE_SIZE];
		uint8_t convert_buff[8];
		W25Q64_ReadDataBytes(this->w28q64,W25Q64_PAGE_SIZE*(this->net_data->page_addres_B1_start +i), read_buffer, W25Q64_PAGE_SIZE);
		for(uint32_t j=0;j<32;j++){
			convert_buff[0]=read_buffer[i*8];
			convert_buff[1]=read_buffer[i*8+1];
			convert_buff[2]=read_buffer[i*8+2];
			convert_buff[3]=read_buffer[i*8+3];
			convert_buff[4]=read_buffer[i*8+4];
			convert_buff[5]=read_buffer[i*8+5];
			convert_buff[6]=read_buffer[i*8+6];
			convert_buff[7]=read_buffer[i*8+7];
			this->BIAS[i*32+j]=ReconstructDouble(convert_buff);
		}
	}
}
/*
  * @brief wykonujemy operacje propagacji przez pierwsza warstwe odczytujac co chwile nowe wartosci wektoróœ wag
  * i wpisujac wuniki do tablicy LAYEROUTBUF gdzie następnie po przejsciu przez całą warstwe dane z  LAYEROUTBUF
  * sa wpisywane na DATABUF czyli nasza tablcie wejsciowa co umozliwy dalsza propagacje
  * @param  this - wskaznik na strukture ForwardPass
  * @retval None
*/
void FP_Forward_PassFirstLayer(ForwardPass * this){
	double val;
	FP_Load_B1(this);
	for(uint32_t i=0;i<this->net_data->W1_size;i++){
		val=0;
		FP_Load_W1_wector(this, i);
		for(uint32_t j=0;j<INPUT_SIZE;j++){
			val+=this->DATABUF[j]*this->WEIGHTBUFF[j];
		}
		val+=this->BIAS[i];
		//RELU
		if(val<0){
			val=0;
		}
		this->LAYEROUTBUF[i]=val;
	}
	for(uint32_t i=0;i<this->net_data->W1_size;i++){
		this->DATABUF[i]=this->LAYEROUTBUF[i];
	}
}
/*
  * @brief Odczytujemy z pamieci wektor wag drugiej warstwy i wpisujemy go do tablicy wag WEIGHTBUFF
  * @param  this - wskaznik na strukture ForwardPass
  * @param 	vector number - numer wektora do zczytania z pamieci
  * @retval None
*/
void FP_Load_W2_wector(ForwardPass * this,uint32_t vector_number){
	//511 max index wektora
	for(uint32_t i=0;i<this->net_data->page_addres_W2_vector_size;i++){
		uint8_t read_buffer[W25Q64_PAGE_SIZE];
		uint8_t convert_buff[8];
		W25Q64_ReadDataBytes(this->w28q64,W25Q64_PAGE_SIZE*(this->net_data->page_addres_W2_start +i+this->net_data->page_addres_W2_vector_size*vector_number), read_buffer, W25Q64_PAGE_SIZE);
		for(uint32_t j=0;j<32;j++){
			convert_buff[0]=read_buffer[i*8];
			convert_buff[1]=read_buffer[i*8+1];
			convert_buff[2]=read_buffer[i*8+2];
			convert_buff[3]=read_buffer[i*8+3];
			convert_buff[4]=read_buffer[i*8+4];
			convert_buff[5]=read_buffer[i*8+5];
			convert_buff[6]=read_buffer[i*8+6];
			convert_buff[7]=read_buffer[i*8+7];
			this->WEIGHTBUFF[i*32+j]=ReconstructDouble(convert_buff);
		}
	}
}
/*
  * @brief Odczytujemy z pamieci biasy dla drugiej warstwy i wpisujemy go do tablicy biasów BIAS
  * @param  this - wskaznik na strukture ForwardPass
  * @retval None
*/
void FP_Load_B2(ForwardPass * this){
	//511 max index wektora
	for(uint32_t i=0;i<this->net_data->B2_pages_size;i++){
		uint8_t read_buffer[W25Q64_PAGE_SIZE];
		uint8_t convert_buff[8];
		W25Q64_ReadDataBytes(this->w28q64,W25Q64_PAGE_SIZE*(this->net_data->page_addres_B2_start +i), read_buffer, W25Q64_PAGE_SIZE);
		for(uint32_t j=0;j<32;j++){
			convert_buff[0]=read_buffer[i*8];
			convert_buff[1]=read_buffer[i*8+1];
			convert_buff[2]=read_buffer[i*8+2];
			convert_buff[3]=read_buffer[i*8+3];
			convert_buff[4]=read_buffer[i*8+4];
			convert_buff[5]=read_buffer[i*8+5];
			convert_buff[6]=read_buffer[i*8+6];
			convert_buff[7]=read_buffer[i*8+7];
			this->BIAS[i*32+j]=ReconstructDouble(convert_buff);
		}
	}
}

/*
  * @brief wykonujemy operacje propagacji przez druga warstwe odczytujac co chwile nowe wartosci wektoróœ wag
  * i wpisujac wuniki do tablicy LAYEROUTBUF gdzie następnie po przejsciu przez całą warstwe dane z  LAYEROUTBUF
  * sa wpisywane na DATABUF czyli nasza tablcie wejsciowa co umozliwy dalsza propagacje
  * @param  this - wskaznik na strukture ForwardPass
  * @retval None
*/
void FP_Forward_PassSecondLayer(ForwardPass * this){
	double val;
	FP_Load_B2(this);
	for(uint32_t i=0;i<this->net_data->W2_size;i++){
		val=0;
		FP_Load_W2_wector(this, i);
		for(uint32_t j=0;j<this->net_data->W1_size;j++){
			val+=this->DATABUF[j]*this->WEIGHTBUFF[j];
		}
		val+=this->BIAS[i];
		//RELU
		if(val<0){
			val=0;
		}
		this->LAYEROUTBUF[i]=val;
	}
	for(uint32_t i=0;i<this->net_data->W2_size;i++){
		this->DATABUF[i]=this->LAYEROUTBUF[i];
	}
}
/*
  * @brief Odczytujemy z pamieci wektor wag trzeciej warstwy i wpisujemy go do tablicy wag WEIGHTBUFF
  * @param  this - wskaznik na strukture ForwardPass
  * @param 	vector number - numer wektora do zczytania z pamieci
  * @retval None
*/
void FP_Load_W3_wector(ForwardPass * this,uint32_t vector_number){
	//9 max index wektora
	for(uint32_t i=0;i<this->net_data->page_addres_W3_vector_size;i++){
		uint8_t read_buffer[W25Q64_PAGE_SIZE];
		uint8_t convert_buff[8];
		W25Q64_ReadDataBytes(this->w28q64,W25Q64_PAGE_SIZE*(this->net_data->page_addres_W3_start  +i+this->net_data->page_addres_W2_vector_size*vector_number), read_buffer, W25Q64_PAGE_SIZE);
		for(uint32_t j=0;j<32;j++){
			convert_buff[0]=read_buffer[i*8];
			convert_buff[1]=read_buffer[i*8+1];
			convert_buff[2]=read_buffer[i*8+2];
			convert_buff[3]=read_buffer[i*8+3];
			convert_buff[4]=read_buffer[i*8+4];
			convert_buff[5]=read_buffer[i*8+5];
			convert_buff[6]=read_buffer[i*8+6];
			convert_buff[7]=read_buffer[i*8+7];
			this->WEIGHTBUFF[i*32+j]=ReconstructDouble(convert_buff);
		}
	}
}
/*
  * @brief Odczytujemy z pamieci biasy dla trzeciej  warstwy i wpisujemy go do tablicy biasów BIAS
  * @param  this - wskaznik na strukture ForwardPass
  * @retval None
*/
void FP_Load_B3(ForwardPass * this){
	//511 max index wektora
	for(uint32_t i=0;i<this->net_data->B3_pages_size;i++){
		uint8_t read_buffer[W25Q64_PAGE_SIZE];
		uint8_t convert_buff[8];
		W25Q64_ReadDataBytes(this->w28q64,W25Q64_PAGE_SIZE*(this->net_data->page_addres_B3_start +i), read_buffer, W25Q64_PAGE_SIZE);
		for(uint32_t j=0;j<32;j++){
			convert_buff[0]=read_buffer[i*8];
			convert_buff[1]=read_buffer[i*8+1];
			convert_buff[2]=read_buffer[i*8+2];
			convert_buff[3]=read_buffer[i*8+3];
			convert_buff[4]=read_buffer[i*8+4];
			convert_buff[5]=read_buffer[i*8+5];
			convert_buff[6]=read_buffer[i*8+6];
			convert_buff[7]=read_buffer[i*8+7];
			this->BIAS[i*32+j]=ReconstructDouble(convert_buff);
		}
	}
}
/*
  * @brief wykonujemy operacje propagacji przez trzecia warstwe odczytujac co chwile nowe wartosci wektoróœ wag
  * i wpisujac wuniki do tablicy LAYEROUTBUF
  * @param  this - wskaznik na strukture ForwardPass
  * @retval None
*/

void FP_Forward_PassThirdLayer(ForwardPass * this){
	double val;
	FP_Load_B3(this);
	for(uint32_t i=0;i<this->net_data->W3_size;i++){
		val=0;
		FP_Load_W3_wector(this, i);
		for(uint32_t j=0;j<this->net_data->W2_size;j++){
			val+=this->DATABUF[j]*this->WEIGHTBUFF[j];
		}
		val+=this->BIAS[i];
		//RELU
		if(val<0){
			val=0;
		}
		this->LAYEROUTBUF[i]=val;
	}
}
/*
  * @brief zwracamy index najwiekszej wartosci w tablicy
  * @param  this - wskaznik na strukture ForwardPass
  * @retval result - index najwiekszej wartosci
*/
uint8_t FP_Retrun_Result(ForwardPass * this){
	uint8_t result=0;
	for(uint8_t i=0;i<this->net_data->W3_size;i++){
		if(this->LAYEROUTBUF[i] > this->LAYEROUTBUF[result]){
			result=i;
		}
	}
	return result;
}

