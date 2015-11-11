#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// プロトタイプ宣言
double newton(double, double);
double kassen(double, double, double);
void nibun(double, double, double);
void ougon(double, double, double);
void kyogeki(double, double, double);
double func(double, double);
double funcd(double);

int main(void){
	double n = 20, x1 = 10, x2 = 20;
	printf("ニュートン法によって計算した方程式の解は%fです.\n", newton(x1, n));
	printf("割線法によって計算した方程式の解は%fです.\n", kassen(x1, x2, n));

	// init a and b
	x1 = 3; x2 = 10;
	nibun(x1, x2, n);
	ougon(x1, x2, n);
	kyogeki(x1, x2, n);

	return 0;
}

double newton(double xa, double n){
	double xb;
	do{
		xb = xa;
		xa = xb - func(xb,n)/funcd(xb);
		printf("%f\n",xa);
	}while(fabs(xa-xb) >= 0.0001);
	return xa;
}

double kassen(double x1,double x2, double n){
	// init
	double xa = x2;
	x2 = x1;
	// loop
	do{
		x1 = x2;
		x2 = xa;
		xa = x2 - func(x2, n)*(x2-x1)/(func(x2, n)-func(x1, n));
		printf("%f\n",xa);
	}while(fabs(xa-x2) >= 0.0001);
	return xa;
}

void nibun(double a, double b, double n){
	double c;
	if(func(a, n)*func(b, n) > 0){
		printf("aとbがおかしいです.\n");
		return ;
	}

	while(fabs(a-b) >= 0.0001){
		c = (a+b)/2;
		if(func(c, n)*func(a, n) > 0){
			a = c;
		}else{
			b = c;
		}
		printf("%f\n", c);
	}

	printf("二分法によって計算した方程式の解は%fです\n.", a);
}

void ougon(double a, double b, double n){
	double c;
	if(func(a, n)*func(b, n) > 0){
		printf("aとbがおかしいです.\n");
		return ;
	}

	while(fabs(a-b) >= 0.0001){
		c = ((1+sqrt(5))*a+2*b) / (3+sqrt(5));
		if(func(c, n)*func(a, n) > 0){
			a = c;
		}else{
			b = c;
		}
		printf("%f\n", c);
	}

	printf("黄金分割法によって計算した方程式の解は%fです\n.", a);
}


void kyogeki(double a, double b, double n){
	double c;
	if(func(a, n)*func(b, n) > 0){
		printf("aとbがおかしいです.\n");
		return ;
	}

	while(fabs(a-b) >= 0.0001){
		c = ((a*func(b, n)) - (b*func(a,n))) / (func(b, n) - func(a, n));

		if(fabs(func(c,n)) < 0.0001){
			a = c;
			break;
		}

		if(func(c, n)*func(a, n) > 0){
			a = c;
		}else{
			b = c;
		}
		printf("%f\n",c);
	}

	printf("挟撃法によって計算した方程式の解は%fです\n.", a);
}

double func(double x, double n){
	//return f(x)
	return exp(x)-15*x*x+n;
}

double funcd(double x){
	//return f'(x)
	return exp(x)-30*x;
}
