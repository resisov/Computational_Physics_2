double F(double x, double y) {
        return y+x ;
}
double an(double x) {
	return 2*exp(x)-x-1;
}

void Euler_Method_2()
{
        double y2,x;
	double y1=1;
	//double x_arr[10], y2_arr[10];
	for (int i =0 ; i <=9 ; i++)
	{
		double point = (i+1);
		double h = 1. / 1000.;
		double N = point / h;
                for (double n = 0 ; n <= N ; n++ ) {

                        x = 0+n*h ;
                        y2 = y1 + h*F(x,y1);

                        //printf("%f\t%f\t%f\n",y2,x,n) ;

                        y1 = y2 ;
                }
		printf("%f\t%f\t%f\n",x,y2,an(point));
		y1=1;
	}
	/*
		x_arr[i]= point;
		y2_arr[i] = y2;
		y1=1;
	}
        TGraph *Dsol1 = new TGraph(10,x_arr,y2_arr); Dsol1 ->Draw("APC");
	TF1 *an = new TF1("fa1","2*exp(x)-x-1",0,1);
	an->Draw("same");
        Dsol1 ->SetMarkerStyle(20); Dsol1 ->SetMarkerColor(1); Dsol1 ->SetLineColor(1);
	*/


}

