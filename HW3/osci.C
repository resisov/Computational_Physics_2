#define k 0.5
#define m 1.0
#define alp 0.5
#define bet 0.5
#define a 1.0
#define b 1.0
#define h 3.141592/50.

double fx_n(double vn) 
{
        return vn;
}
double fx_al(double vn,double xn)
{
        return vn+bet*h*(-k/m*xn);
}

double fv_n(double xn)
{
        return -k/m*xn;
}
double fv_al(double xn,double vn)
{
        return -k/m*(xn+bet*h*vn);
}

void osci()
{
	int N = 200;
        double t_arr[N], v_arr[N], x_arr[N];
	double x0 = 1.;
	double v0 = 0.;
	double v1, x1;

        for (int n =0 ; n <N ; n++)
        {
                t_arr[n] = 0+n*h;
                x1 = x0 + h * (a * fx_n(v0) + b * fx_al(v0,x0));
		v1 = v0 + h * (a * fv_n(x0) + b * fv_al(x0,v0));
		x_arr[n] = x0;
		v_arr[n] = v0;
		x0 = x1;
		v0 = v1;
		printf("%f\t%f\t%f\n",x0,v0,0+n*h);
	}

        TGraph *Dsol1 = new TGraph(N,t_arr,v_arr); Dsol1 ->Draw("APC");
	TGraph *Dsol2 = new TGraph(N,t_arr,x_arr);
        Dsol2->Draw("PCsame");
        Dsol1 ->SetMarkerStyle(20); Dsol1 ->SetMarkerColor(1); Dsol1 ->SetLineColor(1);
        Dsol2 ->SetMarkerStyle(20); Dsol2 ->SetMarkerColor(2); Dsol1 ->SetLineColor(2);

}




