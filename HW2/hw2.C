#include "rtflsp.c"

float f(float x)
{
        float fx = x*x*x*x-6*x*x*x+7*x*x-6*x-8;
        return fx;
}



void hw2()
{
	float precision = 1e-12;
	float a = -2.;
	float b = 1.;

	rtflsp(f,a,b,precision);
	printf("====================================================================================\n");
	a = 1.;
	b = 6.;
        rtflsp(f,a,b,precision);
	

}


