#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3
#define M 400
#define E 0.000001

double length(double l1[3], double l2[3]);
// 2つのベクトルの距離の差を計算する関数．

void Jacobi(){
	double a[N][N] = {{15,5,4}, {12,13,10}, {1,2,17}};
	double b[N] = {8,16,20};
	double x0[N] = {}, x1[N] = {};
	int i, j, k=1;
	double sum=0;

	do{
		for(i=0;i<N;i++){
			x0[i] = x1[i];
		}

		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(i==j) j++;
				sum += a[i][j]*x0[j];
			}
			x1[i] = (b[i]-sum)/a[i][i];
			sum = 0;
		}

		printf("%d\tx1 = %f\tx2 = %f\tx3 = %f\n",k,x0[0],x0[1],x0[2]);
		k++;
	}while(fabs(length(x1,x0)) > E);

	printf("ヤコビ法\t: x1 = %f\tx2 = %f\tx3 = %f\n\n",x1[0],x1[1],x1[2]);
}

void Seidel(){

	double a[N][N] = {{15,5,4}, {12,13,10}, {1,2,17}};
	double b[N] = {8,16,20};
	double x0[N] = {},x1[N] = {};
	int i, j, k=1;
	double sum=0;

	do{
		for(i=0;i<N;i++){
			x0[i] = x1[i];
		}

		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(j < i){
					sum += a[i][j]*x1[j];
				}
				if(j > i){
					sum += a[i][j]*x0[j];
				}
			}
			x1[i] = (b[i]-sum)/a[i][i];
			sum = 0;
		}

		printf("%d\tx1 = %f\tx2 = %f\tx3 = %f\n",k,x0[0],x0[1],x0[2]);
		k++;
	}while(fabs(length(x1,x0)) > E);

	printf("ガウス・ザイデル法\t: x1 = %f\tx2 = %f\tx3 = %f\n\n",x1[0],x1[1],x1[2]);
}

void Sor(){

	double a[N][N] = {{15,5,4}, {12,13,10}, {1,2,17}};
	double b[N] = {8,16,20};
	double x0[N] = {},x1[N] = {};
	int i, j, k=1;
	double sum=0, omega = 1.1;

	do{
		for(i=0;i<N;i++){
			x0[i] = x1[i];
		}

		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(j < i){
					sum += a[i][j]*x1[j];
				}
				if(j > i){
					sum += a[i][j]*x0[j];
				}
			}
			x1[i] = (b[i]-sum)/a[i][i];
			x1[i] = x0[i] + omega*(x1[i] - x0[i]);
			sum = 0;
		}

		printf("%d\tx1 = %f\tx2 = %f\tx3 = %f\n",k,x0[0],x0[1],x0[2]);
		k++;
	}while(fabs(length(x1,x0)) > E);

	printf("SOR法\t: x1 = %f\tx2 = %f\tx3 = %f\n\n",x1[0],x1[1],x1[2]);

}


int main(void){

	Jacobi();
	Seidel();
	Sor();
	return 0;
}


double length(double x[3], double y[3]){
	int i;
	double z[3];
	double sum=0;

	for(i=0;i<3;i++){
		z[i] = x[i]-y[i];
		sum += z[i]*z[i];
	}
	return sqrt(sum);
}
