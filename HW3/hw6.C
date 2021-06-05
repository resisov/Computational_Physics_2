#define hbar 1 // particle physics unit
#define m 0.5 // mass of electron [MeV]
#define h 0.1 // step size
#define N 10 // number of iterations

double fx(double x, double psi, double D_psi) {
	return D_psi;
}

double dfx(double x, double psi, double D_psi) {
	double E;
	E = 3.141592*3.141592/4.;
	return ((2.*m*E)/(hbar*hbar))*psi;
}


void hw6()
{
	double psi, x, D_psi, E;
	double fx1, fx2, fx3, fx4, dfx1, dfx2, dfx3, dfx4;
	double psi_arr[N+1], x_arr[N+1], mx_arr[N+1];
	psi = 1;
	D_psi = 0;
	x = 0;

	// 4th Runge Kutta
	for (int n=0;n<=N;n++) 
	{

		x = n*h;
		x_arr[n] = x;
		mx_arr[n] = -x;
		psi_arr[n] = psi;
                printf("%f\t%f\t%f\t%d\n",x,-x,psi,n);
	
		fx1 = fx(x,psi,D_psi);
		dfx1 = dfx(x,psi,D_psi);

		fx2 = fx(x+0.5*h,psi+0.5*h*fx1,D_psi+0.5*h*dfx1);
		dfx2 = dfx(x+0.5*h,psi+0.5*h*fx1,D_psi+0.5*h*dfx1);

		fx3 = fx(x+0.5*h,psi+0.5*h*fx2,D_psi+0.5*h*dfx2);
		dfx3 = dfx(x+0.5*h,psi+0.5*h*fx2,D_psi+0.5*h*dfx2);

		fx4 = fx(x+h,psi+h*fx3,D_psi+h*dfx3);
		dfx4 = dfx(x+h,psi+h*fx3,D_psi+h*dfx3);
		
		psi = psi + (h/6.)*(fx1+2*fx2+2*fx3+fx4);
		D_psi = D_psi -(h/6.)*(dfx1+2*dfx2+2*dfx3+dfx4);
		
	}

	// visualization
	TGraph *Dsol1 = new TGraph(N+1,x_arr,psi_arr);
	Dsol1->Draw("ACP");	
	Dsol1->GetXaxis()->SetLimits(-1.0,1.0);
	Dsol1->GetXaxis()->SetTitle("Position");
        Dsol1->GetYaxis()->SetLimits(0.0,2.0);
	Dsol1->GetYaxis()->SetTitle("Energy [MeV]");
	TGraph *Dsol2 = new TGraph(N+1,mx_arr,psi_arr);
	Dsol2 -> Draw("PCsame");

	// analytic solution
	TF1 *An = new TF1("k","cos(3.141592/2*x)",-1,1);
	An->Draw("PCsame");

        TLegend *Lgd = new TLegend(0.70,0.80,1.00,1.00);
        Lgd->AddEntry(Dsol1,"4th Runge-Kutta Solution","l");
        Lgd->AddEntry(An,"Analytic Solution","l");
        Lgd->Draw();

}

