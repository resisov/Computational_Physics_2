#define la = 0.693 / 5013. // day
#define lb = 0.693 / 138376. // day
#define h = 100. // day

double fa(double na, double dt) 
{
        return -la*na*dt;
}
double fb(double na, double nb, double dt)
{
        return -la*na*dt -lb*nb*dt;
}
double fc(double nb double dt)
{
        return -lb*nb*dt;
}




void hw5()
{
        double na = 100000.;
	double fin = 5*10*10*10*10*10;
	double nb = 0.;
	double nc = 0.;
	double a=0., b=1., alp=1./2.,bet=1./2.;  // Heun Method
	double dt = h;
	double N = fin / h;
	double t_[N], num_a[N], num_b[N], num_c[N];
	double na2,nb2,nc;

        for (double n = 0 ; n <= fin ; n+dt )
        {
                t_[N] = n*dt;
		num_a[N] = na;
		num_b[N] = nb;
		num_c[N] = nb;
             	
                na2 = na + h*(a*fa(na,n*dt)+b*fa(x+alp*dt,y1+bet*dt*fn));
                y1 = y2 ;

        }
        printf("heun method =  %f\n",y2);



}

