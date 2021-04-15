void bisect_01()
{
	double precision = 0.000001;
	double a = -1.;
	double b = 0.5;
	double an = 0.;
	double c[30];
	double fx[30];
	int i=0;
	double cnt[30];

	while (1)
	{
		if (sin(a)*sin(b)>0)
		{
			printf("sol not found\n");
			break;
		}
		c[i] = (a + b) / 2.;
		fx[i] = sin(c[i]);
		cnt[i] = i;
		printf("%f\t%f\t%f\n",sin(a),sin(b),sin(c[i]));

		if ( sin(a) * sin(c[i]) <= 0.)
		{
			b = c[i];
		}
		else
		{
			a = c[i];
		}
		printf("%f\n",sin(c[i]));
		i++;
		if (abs(b-a) < precision)
		{
			break;
		}
	}

        TGraph *Dsol1 = new TGraph(i,cnt,fx); Dsol1 ->Draw("APC");


        Dsol1 ->SetMarkerStyle(20); Dsol1 ->SetMarkerColor(1);


}

