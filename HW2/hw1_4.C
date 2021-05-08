double f(double x)
{
        double fx = x*x*x*x-6*x*x*x+7*x*x-6*x-8;
        return fx;
}

void hw1_4()
{

	double step = 0.1;
	double precision = 1e-12;
	double x0 = -2., x1 = 6.;
	int cnt=0, sol=1;

	for (double x=-2.;x<=6.;x+=2*step)
	{
		if (f(x-step)*f(x+step)<0.)
		{
			printf("solution %d\n",sol);
			x0 = x-step;
			x1 = x+step;
			double x2 = 0;
			cnt = 0;
			while (1)
			{
				x2 = (x1*f(x0) - x0*f(x1)) / (f(x0) - f(x1));
                                printf("%+lf\t%+lf\t%+lf\t%+lf\t%d\n",x0,x1,f(x0),f(x1),cnt);

				if (abs(x1-x0)<precision)
				{
					break;
				}
				x0=x1;
				x1=x2;
				cnt++;
			}
		        printf("====================================================================\n");
                        printf("%+lf\t%+lf\t%+lf\t%+lf\t%d\n\n",x0,x1,f(x0),f(x1),cnt);
			sol++;

		}
	}
}


