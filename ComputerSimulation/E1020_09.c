#include <stdio.h>
#include <math.h>

#define N 6

void funca(double fx[]){
	printf("(a)前進差分近似\n");
	printf("1階の微分係数 : %f , 真値との差: %f\n",fx[3]-fx[2],fx[3]-fx[2]-exp(2));
	printf("2階の微分係数 : %f , 真値との差: %f\n",fx[4]-2*fx[3]+fx[2],fx[4]-2*fx[3]+fx[2]-exp(2));
}

void funcb(double fx[]){
	printf("(b)後退差分近似\n");
	printf("1階の微分係数 : %f , 真値との差: %f\n",fx[2]-fx[1], fx[2]-fx[1]-exp(2));
	printf("2階の微分係数 : %f , 真値との差: %f\n",fx[2]-2*fx[1]+fx[0],fx[2]-2*fx[1]+fx[0]-exp(2));
}

void funcc(double fx[]){
	printf("(c)中間差分近似\n");
	printf("1階の微分係数 : %f , 真値との差: %f\n",(fx[3]-fx[1])/2,(fx[3]-fx[1])/2-exp(2));
	printf("2階の微分係数 : %f , 真値との差: %f\n",fx[3]-2*fx[2]+fx[1],fx[3]-2*fx[2]+fx[1]-exp(2));
}

void funcd(double fx[]){
	int i, j, k, l, n=4;
	double num, d, L=0;

	for(i=0;i<=n;i++){
		num=0; d=1;
		for(j=0;j<=n;j++){

			if(i!=j){
				d *= (i-j);
				l=1;

				for(k=0;k<=n;k++){
					if(k!=i && k!=j){
						//l *= 2-k+1;
						l *= 2-k;
					}
				}

				num += l;
			}
		}
		L += (num/d * fx[i]);
	}
	printf("(d)ラグランジュ補完\n");
	printf("1階の微分係数 : %f , 真値との差: %f\n\n",L ,L-exp(2));
}

int main(void){
	int i;
	double fx[5];
	for(i=0;i<=4;i++){
		fx[i] = exp(i);
	}
	funca(fx);
	funcb(fx);
	funcc(fx);
	funcd(fx);
}
