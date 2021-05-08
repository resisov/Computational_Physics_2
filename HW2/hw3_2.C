double f(double x)
{
        double fx = x*x*x*x*x*x*x*x*x*x-1;
        return fx;
}

double df(double x)
{
	double fx = 9*x*x*x*x*x*x*x*x*x;
	return fx;
}

void hw3_2()
{

	double step = 0.01;
	double precision = 1e-12;
	double x0 = 0.5, x1 = 1.3;
	int cnt=0, sol=1;

	for (double x=0.5;x<=1.3;x+=2*step)
	{
		if (f(x-step)*f(x+step)<0.)
		{
			printf("solution %d\n",sol);
			x0 = x-step;
			cnt = 0;
			while (1)
			{
				if (df(x0) != 0)
				{
					x1 = x0 - f(x0)/df(x0);
				}
				if (abs(x1-x0)<precision)
				{
					break;
				}
				printf("%+lf\t%+lf\t%+lf\t%+lf\t%d\n",x0,x1,f(x0),f(x1),cnt);
				x0=x1;
				cnt++;
			}
		        printf("====================================================================\n");
                        printf("%+lf\t%+lf\t%+lf\t%+lf\t%d\n\n",x0,x1,f(x0),f(x1),cnt);
			sol++;

		}
	}
}


