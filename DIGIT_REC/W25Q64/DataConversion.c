#include "DataConversion.h"


union DataConv data;
union DataConvF dataf;

void SplitDouble(double vald,uint8_t* valbuff){

//	data.d=vald;
//	for(uint8_t i=0;i<8;i++){
//		valbuff[i]=data.u[i];
//
//	}



	uint8_t * pvald=(char*)&vald;
	for(uint8_t i=0;i<8;i++){
		valbuff[i]=pvald[i];
	}
}

double ReconstructDouble(uint8_t *valbuff){

//	for(uint8_t i=0;i<8;i++){
//		data.u[i]=valbuff[i];
//
//	}
//	return data.d;

//		double vald;
//	uint8_t * pvald=(uint8_t*)&vald;
//	for(uint8_t i=0;i<8;i++){
//		pvald[i]=valbuff[i];
//	}
//	return vald;
//
	double vald;
	uint8_t * pvald=(uint8_t*)&vald;
	for(uint8_t i=0;i<8;i++){
		pvald[i]=valbuff[i];
	}
	return vald;


}




void Splitfloat(float valf , uint8_t *valbuff){
	float a=valf;
	dataf.f=valf;
	for(uint8_t i=0;i<4;i++){
		valbuff[i]=dataf.u[i];

	}


}


float ReconstructFloat(uint8_t* valbuff){

	for(uint8_t i=0;i<4;i++){
			dataf.u[i]=valbuff[i];

		}
		return dataf.f;



}




void SplitfloatRETARDED(float valf , uint8_t *valbuff){
	dataf.f=valf;
	for(uint8_t i=0;i<4;i++){
		valbuff[i]=dataf.u[i];

	}


}


float ReconstructFloatRETARDED(uint8_t* valbuff){

	for(uint8_t i=0;i<4;i++){
			dataf.u[i]=valbuff[i];

		}
		return dataf.f;



}



