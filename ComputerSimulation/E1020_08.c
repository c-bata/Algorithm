#include <stdio.h>
#include <math.h>

#define N 6

int main(void){
	int i;
	double a0, a1, sumx=0, sumy=0, sumxx=0, sumxy=0, e=0;
	double x[N]={0.0,1.0,2.0,3.0,4.0,5.0}, y[N]={10.2,12.0,15.7,17.0,20.5,22.4};

	for(i=0; i<N; i++){
		sumx += x[i];
		sumy += y[i];
		sumxx += x[i]*x[i];
		sumxy += x[i]*y[i];
	}

	a0 = (sumy*sumxx - sumx*sumxy)/(N*sumxx - sumx*sumx);
	a1 = (N*sumxy - sumx*sumy)/(N*sumxx - sumx*sumx);

	for(i=0;i<N;i++){
		e += pow(y[i]-a0-a1*x[i],2);
	}

	printf("a0=%f, a1=%f, 残像平方和=%f\n", a0, a1, e);

}
