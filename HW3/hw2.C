double f(double x, double y) 
{
        return 2*x*y;
}




void hw2()
{
        double y2,x;
	double y1=1;
	double a=0.25, b=0.75, alp=2./3.,bet=2./3.;  // Heun Method
	double h = 0.2;
	double N = 1 / h; // number of iterations
	double fn;


        for (double n = 0 ; n <= N ; n++ )
        {
                x = n*h;
		printf("%f\n",x);
                fn = f(x,y1);
                y2 = y1 + h*(a*fn+b*f(x+alp*h,y1+bet*h*fn));
                y1 = y2 ;

        }
        printf("heun method =  %f\n",y2);



}

