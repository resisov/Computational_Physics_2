double f(double m)
{
	// define constants
	double d = 1.293; // air density (kg/m^3)
	double k = 0.25; // drag coefficient
	double g = 9.81; // gravitational acc (m/sec^2)
	double a = 0.7; // area (m^2)

	// given condition
	double t = 4;
	double v = 36;
	double vinf = sqrt((2*m*g)/(d*a*k));

	// calculate and return
	double vm = vinf*tanh(g*t/vinf) - v;
	return vm;
}

void hw4()
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
	printf("mass = %f [kg]\n",x1);

}
