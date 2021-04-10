double f(double x)
{
	double fx = sqrt((1 + x*x) / (x));
	return fx;
}

void hw5()
{
	// parameters initialization
	double a = 0.;
	double b = 1.;
	double an = 2.17886;
	double n = 0.01;

	// simpson search
	for (double h=0.1;h>=0.0001;h*=0.1)
	{
		double N = (b-a) / h;
		double sim = 0;
		for (int i=1;i<(N/2+1);i++)
		{
                        sim = sim +  h*(((2. / 3.) * f(a+(2*i*h))) + (4. / 3.) *f((a+((2*i-1)*h))));
		}
                printf("h = %f,\t an = %f,\t sim = %f,\t difference = %f\n",h,an,sim,an-sim);

	}
}


