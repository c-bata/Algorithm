#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3

void sweep_out(double a[N][N], double b[N]){
	// 掃き出し法
	int i, k, l, m;

	for(i=0; i<N; i++){
		b[i] /= a[i][i];
		for(k=N-1; k>=i; k--){
			a[i][k] /= a[i][i];
		}
		for(l=0; l<N; l++){
			if(l!=i){
				b[l] -= a[l][i]*b[i];
				for(m=N-1; m>=i; m--){
					a[l][m] -= a[l][i]*a[i][m];
				}
			}
		}
		/*
		for(int x=0; x<N; x++){
			printf("%f %f %f %f\n",a[x][0] ,a[x][1],a[x][2], b[x]);
		}
		*/
	}

	// 表示
	printf("掃き出し法による結果は\n");
	for(i=0; i<N; i++){
		printf("b%d = %f\n",i ,b[i]);
	}

}

void gauss(double a[N][N], double b[N]){
	// ガウスの消去法

	int i, k, j, max;
	double temp, akk, aik;
	double x[N];

	// ピボット選択
	for(k=0; k<=N-2; k++){
		max = k;
		for(i=k+1; i<=N-1; i++){
			if(fabs(a[i][k]) > fabs(a[max][k])) max = i;
		}

		if(fabs(a[max][k]) < 0.0001) exit(0);

		// 行の入れ替え
		if(max != k){
			for(j=0; j<N; j++){
				temp = a[k][j];
				a[k][j] = a[max][j];
				a[max][j] = temp;
			}
			temp = b[k];
			b[k] = b[max];
			b[max] = temp;
		}

		// 前進消去
		akk = a[k][k];
		for(j=k; j<N; j++){
			a[k][j] /= akk;
		}
		b[k] /= akk;

		for(i=k+1; i<N; i++){
			aik = a[i][k];

			for(j=k; j<=N-1; j++){
				a[i][j] -= aik * a[k][j];
			}
			b[i] -= aik*b[k];
		}
	}

	// 後退代入
	x[k] = b[k] / a[k][k];
	for(k=N-2; k>=0; k--){
		for(j=0; j<=N-1; j++){
			x[k] -= a[k][j]*x[j];
		}
		x[k] += b[k];
	}

	// 表示
	printf("ガウスの消去法による結果は\n");
	for(i=0; i<N; i++){
		printf("b%d = %f\n",i ,x[i]);
	}
}

int main(void){

	double a1[N][N] = {{6,5,4}, {12,13,10}, {18,21,17}};
	double b1[N] = {8,16,20};

	sweep_out(a1, b1);

	double a2[N][N] = {{6,5,4}, {12,13,10}, {18,21,17}};
	double b2[N] = {8,16,20};
	gauss(a2, b2);

	return 0;
}
