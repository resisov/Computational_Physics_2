double f(double x) // definition of given function
{
	double fx = exp(x);
	return fx;
}

void hw2()
{
	double N = 100.;
	double h = 1 / N;
	double x[100], an[100], sol[100], rms[100]; // for plotting
	
	for (int n=0;n<N;n++)
	{
		double xn = (n+1) / N;
		x[n] = xn;
		an[n] = f(xn);
		sol[n] = (f(xn+h)-2*f(xn)+f(xn-h))/(h*h);
		double rootmeansq = rootmeansq + sqrt(pow(an[n]-sol[n],2)/N);
		rms[n] = rootmeansq;
		printf("%f\t%f\t%e\t%f\n",x[n],an[n],sol[n],rms[n]);
	}
        TGraphErrors *Dsol2 = new TGraphErrors(100,x,sol,0,rms); Dsol2 ->Draw("ALP");
        Dsol2 ->SetLineColor(2);




}
