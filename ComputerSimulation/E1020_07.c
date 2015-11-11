#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20.0

int kaijo(int n){
	if(n==0)
		return 1;
	return n*kaijo(n-1);
}

void linear(){
	double f0 = log2(N);
	double f1 = log2(N+0.1);

	double result = f0 + (f1-f0)/0.1 * (0.05);
	double ans    = log2(N+0.05);

	printf("(a)線形補間\n近似値は%f. 真値との誤差は%fです.\n", result, result-ans);
}

void newton2(){
	int i;
	double f[3],df[2],d2f[1], y1, r, result=0;

	for(i=0;i<3;i++)
		f[i] = log2(N+0.1*i);
	for(i=0;i<2;i++)
		df[i] = f[i+1]-f[i];
	for(i=0;i<1;i++)
		d2f[i] = df[i+1]-df[i];

	y1 = log2(N);
	r = 0.05 / 0.1;

	result += y1;
	result += r*df[0];
	result += r*(r-1)/2*d2f[0];

	double ans = log2(N+0.05);
	printf("(b)ニュートンの2次前進差分補間\n近似値は%f, 誤差は%fです.\n",result,result-ans);
}

void newton3(){
	int i;
	double f[4],df[3], d2f[2],d3f[1],y1, r, result=0;

	for(i=0;i<4;i++)
		f[i] = log2(N+0.1*i);
	for(i=0;i<3;i++)
		df[i] = f[i+1]-f[i];
	for(i=0;i<2;i++)
		d2f[i] = df[i+1]-df[i];
	for(i=0;i<1;i++)
		d3f[i] = d2f[i+1]-d2f[i];

	y1 = log2(N);
	r = 0.05 / 0.1;

	result += y1;
	result += r*df[0];
	result += r*(r-1)/2*d2f[0];
	result += r*(r-1)*(r-2)/(3*2) * d3f[0];

	double ans = log2(N+0.05);
	printf("(c)ニュートンの3次前進差分補間\n近似値は%f, 誤差は%fです.\n",result,result-ans);
}

void lagrange(){
	int i,j;
	double n, d, f=0;

	for(i=0;i<4;i++){
		n = 1; d = 1;

		for(j=0;j<4;j++){
			if(i!=j){
				n *= ( 0.05 - 0.1*j );
				d *= ( 0.1*i - 0.1*j );
			}
		}

		f += n/d * log2(N+0.1*i);
	}

	double ans    = log2(N+0.05);
	printf("(d)ラグランジュ補間\n近似値は%f, 誤差は%fです.\n",f,f-ans);
}



int main(void){
	linear();
	newton2();
	newton3();
	lagrange();
	return 0;
}
