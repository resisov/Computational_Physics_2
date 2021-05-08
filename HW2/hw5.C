double f(double v)
{
	// define constants
	double R = 0.08314;
	double a = 1.463;
	double b = 0.0394;
	double T = 215;
	double P = 70;

	// calculate and return
	double fv = (P + a/(v*v))*(v-b) - R*T;
	return fv;
}

double ideal_gas(double P, double R, double T)
{
	double sol = R*T/P;
	return sol;
}

void hw5()
{
	double precision = 1e-12;
	int count = 0;
	double x1 = 40.;
	double x2 = 45.;
	double x3;
	while (abs(x2-x1) > precision)
	{
		x3 = (x2*f(x1) - x1*f(x2)) / (f(x1) - f(x2));
		count++;
		printf("x1 = %f\t x2 = %f\t x3 = %f\t, count = %d\n",x1,x2,x3,count);
		x1 = x2;
		x2 = x3;
	}
	printf("==================================================\n");
	printf("non ideal V = %f [m^3/kg-mole]\t ideal V = %f [m^3/kg-mole]\n",x3,ideal_gas(70,0.08314,215));

}
