
double Om(double theta) 
{
        return -9.81/0.2*sin(theta);
}
double Th(double omega)
{
	return omega;
}



void hw4()
{
	double y1=1;
	double a=0.5, b=0.5, alp=1.0,bet=1.0;  // Modified Method
	double h = 0.001;
	int N = 2 / h; // number of iterations
	double th1 = 3.141592/5.;
	double o1 = 0.;
	double o2,th2,t;
	double t_arr[N], Om_arr[N], Th_arr[N];
	double Mom_arr[N], Mth_arr[N];
	double fn;
	int n;

        for (n = 0 ; n < N ; n++ )
        {
                t = n*h;
		t_arr[n] = t;
		Om_arr[n] = o1;
		Th_arr[n] = th1;
		o2 = o1 + h * (Om(th1));
		th2 = th1 + h * (Th(o1));
                o1 = o2;
		th1 = th2;
		
        }
	o1 = 0.;
	th1 = 3.141592/5.;
        for (n = 0 ; n < N ; n++ )
        {
                t = n*h;
                t_arr[n] = t;
                Mom_arr[n] = o1;
                Mth_arr[n] = th1;
                o2 = o1 + h * (a*Om(th1)+b*Om(th1+alp*h));
                th2 = th1 + h * (a*Th(o1)+b*Th(o1+alp*h));
                o1 = o2;
                th1 = th2;

        }

        TGraph *Dsol1 = new TGraph(N,t_arr,Om_arr); Dsol1 ->Draw("APC");
        Dsol1 ->SetMinimum(-5.0);
        Dsol1 ->SetMaximum(5.0);
        TGraph *Dsol2 = new TGraph(N,t_arr,Th_arr);
        TGraph *Dsol3 = new TGraph(N,t_arr,Mom_arr);
        TGraph *Dsol4 = new TGraph(N,t_arr,Mth_arr);

        Dsol2->Draw("PCsame");
        Dsol3->Draw("PCsame");
        Dsol4->Draw("PCsame");

        Dsol1 ->SetMarkerStyle(20); Dsol1 ->SetMarkerColor(1); Dsol1 ->SetLineColor(1);
        Dsol2 ->SetMarkerStyle(20); Dsol2 ->SetMarkerColor(2); Dsol2 ->SetLineColor(2);
        Dsol3 ->SetMarkerStyle(20); Dsol3 ->SetMarkerColor(3); Dsol3 ->SetLineColor(3);
        Dsol4 ->SetMarkerStyle(20); Dsol4 ->SetMarkerColor(4); Dsol4 ->SetLineColor(4);

        TLegend *Lgd = new TLegend(0.15,0.73,0.36,0.90);
        Lgd ->AddEntry(Dsol1,"Euler omega","p");
        Lgd ->AddEntry(Dsol2,"Euler theta","p");
        Lgd ->AddEntry(Dsol3,"Modified omega","p");
        Lgd ->AddEntry(Dsol4,"Modified thega","p");
        Lgd ->Draw();


}

