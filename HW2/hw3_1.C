double f(double x)
{
        double fx = x*x*x*x*x*x*x*x*x*x-1;
        return fx;
}



void hw3_1()
{
	double precision = 1e-12;
	double a = 0.;
	double b = 1.3;
	double c;
	double scanstep = 0.01;
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
	printf("===========================================================================\n");

	for (double i=a;i<b;i+=scanstep)
	{
		count = 0;
		if (f(i)*f(i+scanstep)<0)
		{
			double point1 = i;
			double point2 = i+scanstep;
			while (1)
			{
				//c = (point1 +  point2) / 2.; biseciton
				c = (point1*f(point2)-point2*f(point1)) / (f(point2)-f(point1)); // farsi
				//printf("%f\n",c);
				if (f(point1) * f(c) <= 0.)
				{
					if (f(c) * f(point2) <= 0.)
					{
						if (count % 2 == 0)
						{
							point2 = c;
						}
						else
						{
							point1 = c;
						}
					}
					else
					{
						point2 = c;
					}
				}
				else
				{
					if (f(point1) * f(c) <=0.)
					{
						if (count % 2 == 0)
						{
							point1 = c;
						}
						else
						{
							point2 = c;
						}
					}
					else
					{
						point1 = c;
					}
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


