#ifndef _FORWARDPASS_H_
#define _FORWARDPASS_H_
#include "NeuralNetwork.h"
#include "W25Q64Drv.h"
#include "SDDrv.h"
#include "DataConversion.h"

#define MAX_DATA_VECTOR_SIZE 1024

typedef struct _ForwardPass{
	NET * NeuralNetwork;
	NET_INFO * net_data;
	MEMORY * w28q64;
	double DATABUF[MAX_DATA_VECTOR_SIZE];
	double WEIGHTBUFF[MAX_DATA_VECTOR_SIZE];
	double LAYEROUTBUF[MAX_DATA_VECTOR_SIZE];
	double BIAS[MAX_DATA_VECTOR_SIZE];


}ForwardPass;


void Init_ForwardPass(ForwardPass * this,NET * net,NET_INFO * ndata,MEMORY * mem);
void FP_Load_Input(ForwardPass * this,uint8_t * buff);
void FP_Load_W1_wector(ForwardPass * this,uint32_t vector_number);
void FP_Load_B1(ForwardPass * this);
void FP_Forward_PassFirstLayer(ForwardPass * this);
void FP_Load_W2_wector(ForwardPass * this,uint32_t vector_number);
void FP_Load_B2(ForwardPass * this);
void FP_Forward_PassSecondLayer(ForwardPass * this);
void FP_Load_W3_wector(ForwardPass * this,uint32_t vector_number);
void FP_Load_B3(ForwardPass * this);
void FP_Forward_PassThirdLayer(ForwardPass * this);
uint8_t FP_Retrun_Result(ForwardPass * this);

#endif



