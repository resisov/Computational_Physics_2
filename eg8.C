{
	double h = 0.1;
	double x[11], an[11], tra[11], rms[11];
	double N = 10.;

	for (int i=1;i<11;i++)
	{
        	x[i] = i;
		double xn = i / N;
		double step = xn / h;
		an[i] = exp(xn) - exp(0);
		for (int j=0;j<step;j++)
		{
			tra[i] = tra[i] + h*((0.5*exp(j*h)) + (0.5*exp((j+1)*h)));
		}
		rms[i] = sqrt((an[i]-tra[i])*(an[i]-tra[i]));
		printf("%d\t%f\t%f\t%f\n",i,an[i],tra[i],rms[i]);
	}

	TGraph *Dsol1 = new TGraph(11,x,an); Dsol1 ->Draw("APC");
        TGraphErrors *Dsol2 = new TGraphErrors(11,x,tra,0,rms); Dsol2 ->Draw("ALP");

	Dsol1 ->SetMarkerStyle(20); Dsol1 ->SetMarkerColor(1); Dsol1 ->SetLineColor(1);
        Dsol2 ->SetMarkerStyle(20); Dsol2 ->SetMarkerColor(2); Dsol2 ->SetLineColor(2);


	TLegend *l = new TLegend(0.9,0.5,0.9,0.5);
	l->AddEntry(Dsol1,"Analytic Sol","l");
        l->AddEntry(Dsol2,"Trapezoidal Sol","l");
	l->Draw();

}

