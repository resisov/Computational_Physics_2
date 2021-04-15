double f(double x)
{
        double fx = x*x*x*x+2*x*x*x-13*x*x-14*x+24;
        return fx;
}


void falsi()
{
	double precision = 0.00000001;
	double a = -5.;
	double b = 5.;
	double c1, c2;
	double scanstep = 0.01;
	double count1, count2;

	for (double i=a;i<b;i+=scanstep)
	{
		count1 = 0;
		count2 = 0;
		if (f(i)*f(i+scanstep)<0)
		{
			double point11 = i;
			double point12 = i+scanstep;
			while (1)
			{
				c1 = (point11 +  point12) / 2.; // bisection
				if (f(point11) * f(c1) <= 0.)
				{
					point12 = c1;
				}
				else
				{
					point11 = c1;
				}
				count1++;

				if (abs(point12 - point11) < precision)
				{
					break;
				}
			}

                        double point21 = i;
                        double point22 = i+scanstep;
                        while (1)
                        {
                                c2 = (point21*f(point22)-point22*f(point21)) / (f(point22)-f(point21)); // farsi
                                if (f(point21) * f(c2) <= 0.)
                                {
                                        point22 = c2;
                                }
                                if (f(c2) * f(point22))
                                {
                                        point21 = c2;
                                }
                                count2++;
				printf("%f\n",c2);
                                if (abs(point22 - point21) < precision)
                                {
                                        break;
                                }
                        }


			printf("%f\t%f\t%f\t%f\t%f\t%f\n",c1,f(c1),count1,c2,f(c2),count2);
		}
	}
}


