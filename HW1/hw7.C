double f(double x)
{
	double fx = 4 / (1+(x*x));
	return fx;
}

void hw7()
{
	// parameters initialization
        double a = 0;
        double b = 1;
        double an = 4*atan(b)-4*atan(a);
	printf("%f\n",an);
        double h = 0.01;

	// simpson integration
        double N = (b-a) / h;
        double sim = 0.;
        for (int i=1;i<(N/2+1);i++)
        {
                sim = sim +  h*(((2. / 3.) * f(a+(2*i*h))) + (4. / 3.) *f((a+((2*i-1)*h))));
        }
        sim = sim + h *(1./3.)*(f(a)-f(b));
        printf("an = %f,\t sim = %f,\t difference = %f\n",an,sim,an-sim);

	// monte carlo integration
	long seed;
        double x,y;
        TRandom3 *rd = new TRandom3(long(&seed));
        for (int interval=100;interval<=100000000L;interval*=10)
        {
		double in_function = 0;
		double out_function = 0;
                for (int i=0;i<interval;i++)
                {
                        x = rd->Uniform(0,1);
                        y = rd->Uniform(0,4);
                        if (y<=f(x))
                        {
                                in_function++;
                        }
			else
			{
				out_function++;
			}
                }
		printf("%d\t%f\t%f\t%f\n",interval,an,in_function/interval*4,TMath::Pi()-in_function/interval*4);
	}
	

	TF1 *fx1 = new TF1("fx1","4 / (1+(x*x))",0,1);
	fx1->Draw();
}


