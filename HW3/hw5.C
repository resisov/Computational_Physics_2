#define la 0.693 / 5013. // day
#define lb 0.693 / 138376. // day
#define h 100. // day
#define N 50000 // number of iterations

void hw5()
{
	double Na = 100000, Nb = 0, Nc = 0 ;
	double Na_arr[N],Nb_arr[N],Nc_arr[N], T_arr[N] ;
	int t;

	// Euler method loop
	for (int n=0;n<(5*10e+5/100);n++)
	{
		t = n*h ;
                Na_arr[n] = abs(Na);
                Nb_arr[n] = abs(Nb);
                Nc_arr[n] = abs(Nc);
                T_arr[n] = t;
		Na = Na -h*la*Na;
		Nb = Nb -h*(la*Na + lb*Nb);
		Nc = Nc -h*(lb*Nb);
	}
	
	// visualization
	TGraph *Dsol1 = new TGraph(5000,T_arr,Na_arr) ;
	Dsol1->Draw("AP");
        Dsol1->GetXaxis()->SetTitle("Time [days]");
        Dsol1->GetXaxis()->SetLimits(0.0,500000.0);
        Dsol1->GetYaxis()->SetLimits(0.0,100000.0);
        Dsol1->GetYaxis()->SetTitle("Number of Atoms");
	//gPad->SetLogx();
	//gPad->SetLogy();
	TGraph *Dsol2 = new TGraph(5000,T_arr,Nb_arr) ;
	Dsol2->Draw("same") ;
        Dsol2->SetLineColor(2);

	TGraph *Dsol3 = new TGraph(5000,T_arr,Nc_arr) ;
	Dsol3->Draw("same") ;
        Dsol3->SetLineColor(3);
        TLegend *Lgd = new TLegend(0.70,0.80,1.00,1.00);
        Lgd->AddEntry(Dsol1,"Atom A","l");
        Lgd->AddEntry(Dsol2,"Atom B","l");
        Lgd->AddEntry(Dsol3,"Atom C","l");
        Lgd->Draw();



}
