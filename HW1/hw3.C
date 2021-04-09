double f1(double x) // definition of given function
{
	if (x==0)
	{
		return 0.;
	}
	else
	{
	        double f = - sin(x) / x;
		return f;
	}
}
double f2(double x) // definition of given function
{
	if (x==0)
        {
                return 0.;
        }
	else
	{
	        double f = (x*cos(x) - sin(x))/(x*x*x);
		return f;
	}
}


void hw3()
{
	double N = 2*3.141592;
	int len = 100;
	double h = N / len;
	double x[len], j1[len], j2[len]; // for plotting
	int i=0;


	for (double n=0;n<=N;n+=h)
	{
		if (n!=0)
		{
			x[i] = n;
			j1[i] = (f1(n+h)-f1(n))/h;
			j2[i] = n*(f2(n+h)-f2(n))/h;
			//printf("%f\t%f\t%f\n",x[i],j1[i],j2[i]);
			printf("%f\t%f\t%f\n",x[i],j1[i],j2[i]);
		}
		else
		{
			x[i]=0;
			j1[i]=0;
			j2[i]=0;
			printf("x=0\n");
		}
		i++;
	}

        TGraph *Dsol1 = new TGraph(len,x,j1); Dsol1 ->Draw("APC");
        TGraph *Dsol2 = new TGraph(len,x,j2); Dsol2 ->Draw("PC same");


        Dsol1 ->SetLineColor(1);
        Dsol2 ->SetLineColor(2);

        TLegend *l = new TLegend(0.359,0.921,0.359,0.921);
        l->AddEntry(Dsol1,"j1(x)","l");
        l->AddEntry(Dsol2,"j2(x)","l");
        l->Draw();

        //TGraphErrors *Dsol2 = new TGraphErrors(100,x,sol,0,rms); Dsol2 ->Draw("ALP");
        //Dsol2 ->SetLineColor(2);




}
