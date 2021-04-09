void hw8()
{
	// monte carlo integration
	long seed;
        double x,y,z;
	double xx[7],err[7];
        TRandom3 *rd = new TRandom3(long(&seed));
	int cnt = 0;
        for (int interval=100;interval<=100000000L;interval*=10)
        {
		double in_function = 0;
		double out_function = 0;
                for (int i=0;i<interval;i++)
                {
                        x = rd->Uniform(-1,1);
                        y = rd->Uniform(-1,1);
			z = rd->Uniform(-1,1);
                        if (sqrt(x*x+y*y+z*z) <= 1)
                        {
                                in_function++;
                        }
			else
			{
				out_function++;
			}
                }
		printf("%d\t%f\t%f\n",interval,in_function/interval*6, TMath::Pi()-in_function/interval*6);
		xx[cnt] = interval;
		err[cnt] = abs(TMath::Pi()-in_function/interval*6);
		cnt++;
	}


        TGraph *Dsol1 = new TGraph(cnt,xx,err); Dsol1 ->Draw("APC");
        Dsol1 ->SetLineColor(1);

	

}


