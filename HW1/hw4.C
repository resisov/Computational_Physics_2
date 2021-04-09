double f(double x)
{
	double fx = 1. / x;
	return fx;
}

void hw4()
{
	// parameters initialization
	double precision = 1e-04;
	double a = 1.;
	double b = 2.;
	double an = log(b) - log(a);
	double N = 1.;

	// midpoint search
	while (1)
	{
		double mid = 0.;
		for (int i=0;i<N;i++)
		{
			double h = (b - a) / N;
			mid = mid + f(a+(i*h))*h;
		}
		if (precision > abs(an-mid))
		{
			printf("Mid-point = %d\n", int (N));
			break;
		}
                N++;

	}

	// N initialize
	N = 1.;

	// trapezoidal search
	while (1)
        {
		double h;
                double tra = 0;
                for (int i=0;i<=N;i++)
                {
                        h = (b - a) / N;
                        tra = tra + (h*f(a+(i*h)));
                }
		tra = tra - (0.5*h*(f(a)+f(b)));
                if (precision > abs(an-tra))
                {
                        printf("Trapezoidal = %d\n",int (N));
                        break;
                }
                N++;
        }

	// N initialize
        N = 1.;

	// simpson search
	while (1)
	{
		double sim = 0;
		for (int i=1;i<(N/2+1);i++)
		{
			double h = (b- a) / N;
			sim = sim +  h*(((2. / 3.) * f(a+(2*i*h))) + (4. / 3.) *f((a+((2*i-1)*h))));
		}
                if (precision > abs(an-sim))
                {
                        printf("Simpson = %d\n",int (N));
                        break;
                }
                N++;
        }

}


