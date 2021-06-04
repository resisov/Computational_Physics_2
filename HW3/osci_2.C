#define k 0.5
#define m 1.0
#define alp 0.5
#define bet 0.5
#define a 1.0
#define b 1.0
#define h 3.141592/5.

double fx(double vn, double t) 
{
        return vn;
}

double fv(double xn, double t)
{
        return -k/m*xn;
}

void osci_2()
{
	int N = 50;
        double t_arr[N], v_arr[N], x_arr[N];
	double fx1,fx2,fx3,fx4,fv1,fv2,fv3,fv4;
	double x0 = 1.;
	double v0 = 0.;
	double t0 = 0.;
	double v1, x1;

        for (int n =0 ; n <N ; n++)
        {
                t_arr[n] = t0;
		fx1 = fx(v0,t0);
                fv1 = fv(x0,t0);

		fx2 = fx(v0+(1./2.*h*fv1),t0+0.5*h);
                fv2 = fv(x0+(1./2.*h*fx1),t0+0.5*h);

		fx3 = fx(v0+(1./2.*h*fv2),t0+0.5*h);
                fv3 = fv(x0+(1./2.*h*fx2),t0+0.5*h);

		fx4 = fx(v0+h*fv3,t0+h);
                fv4 = fv(x0+h*fx3,t0+h);

		x1 = x0 + (1. / 6.)*h*(fx1+2*fx2+2*fx3+fx4);
		v1 = v0 + (1. / 6.)*h*(fv1+2*fv2+2*fv3+fv4);
		x_arr[n] = x0;
		v_arr[n] = v0;
		x0 = x1;
		v0 = v1;
		t0 += h;
		printf("%f\t%f\t%f\n",x0,v0,0+n*h);
	}

        TGraph *Dsol1 = new TGraph(N,t_arr,v_arr); Dsol1 ->Draw("APC");
	Dsol1 ->SetMinimum(-1.5);
	Dsol1 ->SetMaximum(1.5);
	TGraph *Dsol2 = new TGraph(N,t_arr,x_arr);
        Dsol2->Draw("PCsame");
        Dsol1 ->SetMarkerStyle(20); Dsol1 ->SetMarkerColor(1); Dsol1 ->SetLineColor(1);
        Dsol2 ->SetMarkerStyle(20); Dsol2 ->SetMarkerColor(2); Dsol1 ->SetLineColor(2);

}




