#ifndef _DATACONVERSION_H_
#define _DATACONVERSION_H_
#include "stdint.h"


union DataConv{
	double d;
	char u[8];

};

union DataConvF{
	float f;
	char u[4];
};
void SplitDouble(double vald,uint8_t *valbuff);


double ReconstructDouble(uint8_t* valbuff);

void Splitfloat(float valf , uint8_t *valbuff);


float ReconstructFloat(uint8_t* valbuff);
void SplitfloatRETARDED(float valf , uint8_t *valbuff);


float ReconstructFloatRETARDED(uint8_t* valbuff);
#endif
