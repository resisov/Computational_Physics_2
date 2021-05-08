double f(double x)
{
        double fx = x*x*x*x-6*x*x*x+7*x*x-6*x-8;
        return fx;
}



void hw1_1()
{
	double precision = 1e-12;
	double a = -2.;
	double b = 6.;
	double c;
	double scanstep = 0.1;
	int count;

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
                                printf("%f\t%f\t%f\t%f\t%f\t%f\t%d\n",point1,point2,c,f(point1),f(point2),f(c),count);

				if (abs(point2 - point1) < precision)
				{
					break;
				}
			
			}
		}
	}
}


