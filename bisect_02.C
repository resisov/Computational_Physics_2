double f(double x)
{
        double fx = x*x*x*x+2*x*x*x-13*x*x-14*x+24;
        return fx;
}


void bisect_02()
{
	double precision = 0.00000001;
	double a = -5.;
	double b = 5.;
	double c;
	double scanstep = 0.1;
	double count;

	for (double i=a;i<b;i+=scanstep)
	{
		count = 0;
		if (f(i)*f(i+scanstep)<0)
		{
			double point1 = i;
			double point2 = i+scanstep;
			while (1)
			{
				c = (point1 +  point2) / 2.;
				if (f(point1) * f(c) <= 0.)
				{
					point2 = c;
				}
				else
				{
					point1 = c;
				}
				count++;

				if (abs(point2 - point1) < precision)
				{
					break;
				}
			}
			printf("%f\t%f\t%f\n",c,f(c),count);
		}
	}
}


