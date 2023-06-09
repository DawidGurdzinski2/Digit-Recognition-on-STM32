#include "NeuralNetwork.h"

/*
  * @brief Inicjalizuje strukture Linear czyli strukture zawierajacą informacje o parametrach
  * warstwy sieci neuronowej
  * @param  this - wskaznik na strukture Linear
  * @param input_size - ilosc wejsc w warstwie
  * @param Net_size - ilosc neuronóœ w warstwie
  * @retval None
*/
void Init_Layer(Linear * this,uint16_t input_size,uint16_t Net_size){
	this->input_num=input_size;
	this->nueron_num=Net_size;
}
/*
  * @brief przypisuje do struktury NET warstwy sieci neuronowej tworzac tym strukture całej sieci
  * @param  this - wskaznik na strukture NET
  * @param lin1 - wskaznik na strukture Linear
  * @param lin2 - wskaznik na strukture Linear
  * @param lin3 - wskaznik na strukture Linear
  * @retval None
*/
void Init_Net(NET * this,Linear * lin1,Linear* lin2,Linear * lin3){
	this->first_Layer=lin1;
	this->second_Layer=lin2;
	this->third_Layer=lin3;
	Init_Layer(lin1,784, 1024);
	Init_Layer(lin2,1024, 512);
	Init_Layer(lin3, 512,10);
}

