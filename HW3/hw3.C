#define k 0.5
#define m 1.0
#define alp 0.5
#define bet 0.5
#define a 1.0
#define b 1.0
#define h 3.141592/10.


double fx(double vn, double t)
{
        return vn;
}

double fv(double xn, double vn, double c)
{
        return -(k/m*xn+c/m*vn);
}


void hw3()
{
	int N = 50;
        double t_arr[N], v_over_arr[N], x_over_arr[N];
	double v_crit_arr[N], x_crit_arr[N];
	double v_undr_arr[N], x_undr_arr[N];
	double v_no_arr[N], x_no_arr[N];
	double x0 = 1.;
	double v0 = 0.;
	double t0 = 0.;
	double c0 = 2*sqrt(k/m); //crit
	double c1 = 2*sqrt(k/m)/5; //under
	double c2 = 2*sqrt(k/m)*5; //over
	double c3 = 0.; //no
	double v1,x1;
	double fx1,fv1,fx2,fv2,fx3,fv3,fx4,fv4;
	int n;

        for (n =0 ; n <N ; n++)
        {
                t_arr[n] = t0;


                fx1 = fx(v0,t0);
                fv1 = fv(x0,v0,c0);

                fx2 = fx(v0+(1./2.*h*fv1),t0+0.5*h);
                fv2 = fv(x0+(1./2.*h*fx1),v0+(1./2.*h*fv1),c0);

                fx3 = fx(v0+(1./2.*h*fv2),t0+0.5*h);
                fv3 = fv(x0+(1./2.*h*fx2),v0+(1./2.*h*fv2),c0);

                fx4 = fx(v0+h*fv3,t0+h);
                fv4 = fv(x0+h*fx3,v0+h*fv3,c0);

                x1 = x0 + (1. / 6.)*h*(fx1+2*fx2+2*fx3+fx4);
                v1 = v0 + (1. / 6.)*h*(fv1+2*fv2+2*fv3+fv4);


		x_crit_arr[n] = x0;
		v_crit_arr[n] = v0;
                x0 = x1;
                v0 = v1;
                t0 += h;

	}
	x0 =1.;
	v0 =0.;
	t0=0.;

        for (n =0 ; n <N ; n++)
        {

                fx1 = fx(v0,t0);
                fv1 = fv(x0,v0,c1);

                fx2 = fx(v0+(1./2.*h*fv1),t0+0.5*h);
                fv2 = fv(x0+(1./2.*h*fx1),v0+(1./2.*h*fv1),c1);

                fx3 = fx(v0+(1./2.*h*fv2),t0+0.5*h);
                fv3 = fv(x0+(1./2.*h*fx2),v0+(1./2.*h*fv2),c1);

                fx4 = fx(v0+h*fv3,t0+h);
                fv4 = fv(x0+h*fx3,v0+h*fv3,c1);

                x1 = x0 + (1. / 6.)*h*(fx1+2*fx2+2*fx3+fx4);
                v1 = v0 + (1. / 6.)*h*(fv1+2*fv2+2*fv3+fv4);


		x_undr_arr[n] = x0;
		v_undr_arr[n] = v0;
		x0 = x1;
		v0 = v1;
		t0 += h;

	}
	x0 =1.;
        v0 =0.;
        t0=0.;


        for (n =0 ; n <N ; n++)
        {

                fx1 = fx(v0,t0);
                fv1 = fv(x0,v0,c2);

                fx2 = fx(v0+(1./2.*h*fv1),t0+0.5*h);
                fv2 = fv(x0+(1./2.*h*fx1),v0+(1./2.*h*fv1),c2);

                fx3 = fx(v0+(1./2.*h*fv2),t0+0.5*h);
                fv3 = fv(x0+(1./2.*h*fx2),v0+(1./2.*h*fv2),c2);

                fx4 = fx(v0+h*fv3,t0+h);
                fv4 = fv(x0+h*fx3,v0+h*fv3,c2);


                x1 = x0 + (1. / 6.)*h*(fx1+2*fx2+2*fx3+fx4);
                v1 = v0 + (1. / 6.)*h*(fv1+2*fv2+2*fv3+fv4);


                x_over_arr[n] = x0;
                v_over_arr[n] = v0;
                x0 = x1;
                v0 = v1;
                t0 += h;

        }
        x0 =1.;
        v0 =0.;
        t0=0.;


        for (n =0 ; n <N ; n++)
        {

                fx1 = fx(v0,t0);
                fv1 = fv(x0,v0,c3);

                fx2 = fx(v0+(1./2.*h*fv1),t0+0.5*h);
                fv2 = fv(x0+(1./2.*h*fx1),v0+(1./2.*h*fv1),c3);

                fx3 = fx(v0+(1./2.*h*fv2),t0+0.5*h);
                fv3 = fv(x0+(1./2.*h*fx2),v0+(1./2.*h*fv2),c3);

                fx4 = fx(v0+h*fv3,t0+h);
                fv4 = fv(x0+h*fx3,v0+h*fv3,c3);

                x1 = x0 + (1. / 6.)*h*(fx1+2*fx2+2*fx3+fx4);
                v1 = v0 + (1. / 6.)*h*(fv1+2*fv2+2*fv3+fv4);


                x_no_arr[n] = x0;
                v_no_arr[n] = v0;
                x0 = x1;
                v0 = v1;
                t0 += h;

        }
        x0 =1.;
        v0 =0.;
        t0=0.;



        TGraph *Dsol1 = new TGraph(N,t_arr,x_crit_arr); Dsol1 ->Draw("APC");
	Dsol1 ->SetMinimum(-2.0);
	Dsol1 ->SetMaximum(2.0);
	TGraph *Dsol2 = new TGraph(N,t_arr,x_undr_arr);
        TGraph *Dsol3 = new TGraph(N,t_arr,x_over_arr);
        TGraph *Dsol4 = new TGraph(N,t_arr,x_no_arr);

        Dsol2->Draw("PCsame");
        Dsol3->Draw("PCsame");
        Dsol4->Draw("PCsame");

        Dsol1 ->SetMarkerStyle(20); Dsol1 ->SetMarkerColor(1); Dsol1 ->SetLineColor(1);
        Dsol2 ->SetMarkerStyle(20); Dsol2 ->SetMarkerColor(2); Dsol2 ->SetLineColor(2);
        Dsol3 ->SetMarkerStyle(20); Dsol3 ->SetMarkerColor(3); Dsol3 ->SetLineColor(3);
        Dsol4 ->SetMarkerStyle(20); Dsol4 ->SetMarkerColor(4); Dsol4 ->SetLineColor(4);

	TLegend *Lgd = new TLegend(0.15,0.73,0.36,0.90);
	Lgd ->AddEntry(Dsol1,"Critical","p");
        Lgd ->AddEntry(Dsol2,"Under","p");
        Lgd ->AddEntry(Dsol3,"Over","p");
        Lgd ->AddEntry(Dsol4,"No","p");
	Lgd ->Draw();

}




