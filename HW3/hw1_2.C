#define h 1 // step size
#define c 0.25
#define a 0.7
#define d 1.293
#define g 9.81
#define m 65.0
double fv(double v)
{
	return g - 0.5*((c*a*d*v*v)/m);
}

void hw1_2()
{
	double v, t, x,n ;
	int N = 1./h; // number of iterations
	double v1_arr[11], v2_arr[11], t_arr[11];
	v1_arr[0] = 0.0;
	v2_arr[0] = 0.0;
	t_arr[0] = 0.0;
	double A=0.25,B=0.75,Al=2./3.,Be=2./3.;
	double F1,F2,F3,F4;
	for (int i=1 ;i<=10;i++ )
	{
		//parameter initialization
		x = 0.0;
		v = 0.0;
		for (n=0;n<N*10*i; n++ )
		{
			F1 = fv(v);
			F2 = fv(v+0.5*F1);
			F3 = fv(v+0.5*F2);
			F4 = fv(v+F3);
			v += h/6.*(F1+F2*2+F3*2+F4);

		}
		t_arr[i] = i*10;
		v1_arr[i] = v;
		printf("%f\n",v);
	}

	double vinf = sqrt((2*m*g)/(d*a*c));
	printf("%f\n",vinf);
        TGraph *Dsol1 = new TGraph(11,t_arr,v1_arr);
        Dsol1->Draw("ACP");
        Dsol1->GetXaxis()->SetLimits(0.0,100.0);
        Dsol1->GetXaxis()->SetTitle("Time [s]");
        Dsol1->GetYaxis()->SetLimits(0.0,80.0);
        Dsol1->GetYaxis()->SetTitle("Velocity [m/s]");
        TF1 *An = new TF1("k","75.073713*tanh(9.81*x/75.073713)",0,100);
	An->Draw("same");
        TLegend *Lgd = new TLegend(0.70,0.20,1.00,0.40);
        Lgd->AddEntry(Dsol1,"4th Runge-Kutta","l");
        Lgd->AddEntry(An,"Analytic Solution","l");
        Lgd->Draw();

}
