double f(double x, double y) 
{
        return 2*x*y;
}




void hw2()
{
        double y2,x;
	double y1=1;
	//double a=0.25, b=0.75, alp=2./3.,bet=2./3.;  // Heun Method
	double f1,f2,f3,f4;
	double h = 0.2;
	double N = 1 / h; // number of iterations
	double fn;


        for (double n = 0 ; n <= N ; n++ )
        {
                x = n*h;
		printf("%f\n",x);
                f1 = f(x,y1);
		f2 = f(x+0.5*h,y1+0.5*h*f1);
                f3 = f(x+0.5*h,y1+0.5*h*f2);
                f4 = f(x+h,y1+h*f3);

                y2 = y1 + 1./6.*h*(f1+2*f2+2*f3+f4);
                y1 = y2;

        }
        printf("4th method =  %f\n",y2);



}

