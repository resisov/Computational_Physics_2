double f(double x, double y) 
{
        return x+y;
}




void Runge_2()
{
        double y2,x;
	double x0;
	double y1;
        double h;
        int N; // number of iterations
	double x_arr[11], y_arr[11], an_arr[11];
	double f1,f2,f3,f4;
	double fn;
	int cnt=0;

	for (double i=0;i<=1;i+=0.1)
	{
		y2 = 0;
		x0 = 0;
		y1 = 1;
		N = 2;
		h = i / N;
	        for (int n = 0 ; n < N ; n++ )
		{
			x = x0+n*h;
			f1 = f(x,y1);
			f2 = f(x+0.5*h,y1+0.5*h*f1);
			f3 = f(x+0.5*h,y1+0.5*h*f2);
			f4 = f(x+h,y1+h*f3);
			y2 = y1 + (1./6.)*h*(f1+2*f2+2*f3+f4);
			y1 = y2 ;
			
		}
                x_arr[cnt] = i;
                y_arr[cnt] = y1;
                printf("%f\t%f\t%d\n",x_arr[cnt],y_arr[cnt],cnt);

		cnt++;
	}


        TGraph *Dsol1 = new TGraph(11,x_arr,y_arr); Dsol1 ->Draw("APC");
        TF1 *an = new TF1("fa1","2*exp(x)-x-1",0,1);
        an->Draw("same");
        Dsol1 ->SetMarkerStyle(20); Dsol1 ->SetMarkerColor(1); Dsol1 ->SetLineColor(1);




}

