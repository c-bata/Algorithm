#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define E 0.000001



// 以下，行列処理に関する関数の中身
// 理想的には，A,Bについてもポインタで渡すほうがメモリ効率が良い
// 行列のサイズは3×3専用であることに注意
void M_copy(double A[N][N], double C[N][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			C[i][j] = A[i][j];
		}
	}
}

void M_multiply(double A[N][N], double B[N][N]){
	int i,j,k;
	double C[N][N];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			C[i][j] = 0;
			for(k=0;k<3;k++){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	M_copy(C,A);
}


void v_multiply(double A[3][3], double x[3], double *y){
	int i,j;
	for(i=0;i<3;i++){
		*(y+i) = 0;
		for(j=0;j<3;j++){
			*(y+i) += A[i][j]*x[j];
		}
	}
}


void vv_multiply(double x[3], double y[3], double *C){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			*(C+3*i+j) = x[i]*y[j];
		}
	}
}

void M_transpose(double A[3][3], double C[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			C[i][j] = A[j][i];
		}
	}
}

void Set_Identity(double *C){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i==j) *(C+3*i+j) = 1;
			else    *(C+3*i+j) = 0;
		}
	}
}

void Set_fund_vec(int i, double *y){
	int j;
	for(j=0;j<3;j++){
		if(i==j) *(y+j) = 1;
		else    *(y+j) = 0;
	}
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

double euclid(double x[3]){
	int i;
	double sum=0;
	for(i=0;i<3;i++){
		sum += x[i]*x[i];
	}
	return sqrt(sum);
}


void yakobi(){

	double a[N][N] = {{20,-1,0}, {-1,2,-1}, {0,-1,2}}, m[N][N]={}, temp[N][N]={}, mi[N][N];
	double theta;
	int i,j,p=0,q=1;

	Set_Identity(mi);

	while(1){
		// 非対角要素のなかで最大の要素を選ぶ
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if( i!=j && (fabs(a[i][j]) > fabs(a[p][q]))){
					p=i;
					q=j;
				}
			}
		}

		if(fabs(a[p][q])<E) break;

		if(a[p][p]==a[q][q]){
			theta = M_PI/4;
		}else{
			theta = atan(2*a[p][q]/(a[q][q]-a[p][p]))/2;
		}

		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(i==j && (i==p || i==q) ){
					m[i][j] = cos(theta);
				}else if(i==j && i!=p && i!=q){
					m[i][j] = 1;
				}else if(i==p && j==q){
					m[i][j] = sin(theta);
				}else if(j==p && i==q){
					m[i][j] = -sin(theta);
				}else{
					m[i][j] = 0;
				}
			}
		}


		// 固有ベクトルの計算
		M_multiply(mi,m);

		// Ai+1の計算.
		M_transpose(m,temp);	//転置
		M_multiply(temp, a);
		M_multiply(temp, m);
		M_copy(temp, a);
	}

	printf("固有値\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j)	printf("%f\t",a[i][j]);
		}
	}
	printf("\n");

	printf("固有ベクトル\n");
	for(i=0;i<N;i++){
		printf("%dつ目	\t",i+1);
		for(j=0;j<N;j++){
			printf("%f\t",mi[j][i]);
		}
		printf("\n");
	}

}

void ruijo(){
	double a[N][N] = {{20,-1,0}, {-1,2,-1}, {0,-1,2}}, m[N][N]={}, temp[N][N]={}, mi[N][N];
	double norm, v0[N]={}, v1[N]={10, 9, 8}, avi[N];
	int i,j,p=0,q=1;

	do{
		M_copy(v1, v0);
		v_multiply(a, v0, avi);
		norm = euclid(avi);

		for(i=0;i<N;i++){
			v1[i] = avi[i]/norm;
		}
		printf("%f\n",norm);
	}while(length(v1, v0) > E);

	printf("最大固有値 : %f\n",norm);

	printf("固有ベクトル\n");
	for(i=0;i<N;i++){
		printf("%f\t",v1[i]);
	}
	printf("\n");
}


int main(void){
	printf("(a) ヤコビ法\n\n");
	yakobi();
	printf("\n(b) 累乗法\n\n");
	ruijo();
	printf("\nコメント\n表示されている桁までは全く同じ値になった。\n");
	return 0;
}
