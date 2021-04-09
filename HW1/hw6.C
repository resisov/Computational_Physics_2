double f(double x)
{
	double mu = 4*3.141592*1e-07;
	double l = 10;
	double meter = 100.;
	double fx = mu / (2 * 3.141592) * l * (1/x) * meter;
	return fx;
}

void hw6()
{
	// parameters initialization
	double a = 1;
	double b = 10;
	double an = 4*3.141592*1e-07*10/(2*3.141592)*log(b/a) * 100;
	double h = 0.01;


	// simpson search
	double N = (b-a) / h;
	double sim = 0.;
	for (int i=1;i<(N/2+1);i++)
	{
        	sim = sim +  h*(((2. / 3.) * f(a+(2*i*h))) + (4. / 3.) *f((a+((2*i-1)*h))));
	}
        printf("an = %f (H),\t sim = %f (H),\t difference = %f (H)\n",an,sim,an-sim);


}


