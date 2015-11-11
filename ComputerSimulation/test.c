#include<stdio.h>
#include<math.h>

void forward();
void back();
void middle();
void lagrange();
double f(double);


const double x[5]={0,1,2,3,4}; //math.hのexpを使うためxはdouble
const int p=2;
double df,ddf,h,t;

int main(){
	t = exp(2);
	printf("f(x)=e^x の値を区分[0,4]で1刻みで与えたデータから,\nx=2における1階の微分係数, 2階の微分係数を求める.\n");
	printf("\n(a) 前進差分近似\n");
	forward();
	printf("\n(b) 後退差分近似\n");
	back();
	printf("\n(c) 中間差分近似\n");
	middle();
	printf("\n(d) ラグランジュ補間を利用した計算\n");
	lagrange();
}


void forward(){
	h= x[p+1] - x[p];
	df = (f(x[p+1])-f(x[p])) / h;
	ddf = (f(x[p+2])-2*f(x[p+1])+f(x[p])) / pow(h,2);
	printf("f'(%d) = %f\t誤差 = %f\n",p,df,df-t);
	printf("f\"(%d) = %f\t誤差 = %f\n",p,ddf,ddf-t);
}


void back(){
	h= x[p] - x[p-1];
	df = (f(x[p])-f(x[p-1])) / h;
	ddf = (f(x[p])-2*f(x[p-1])+f(x[p-2])) / pow(h,2);
	printf("f'(%d) = %f\t誤差 = %f\n",p,df,df-t);
	printf("f\"(%d) = %f\t誤差 = %f\n",p,ddf,ddf-t);
}

void middle(){
	h= x[p+1] - x[p-1];  //2h → h
	df = (f(x[p+1])-f(x[p-1])) / h;
	ddf = (f(x[p+1])-2*f(x[p])+f(x[p-1])) / pow(h/2,2);
	printf("f'(%d) = %f\t誤差 = %f\n",p,df,df-t);
	printf("f\"(%d) = %f\t誤差 = %f\n",p,ddf,ddf-t);
}

void lagrange(){
	int i,j,k,l,n;
	double L,N,D;
	L=0; n=4;

	for(i=0;i<n+1;i++){  //手順2 (7から戻ってくる)
		N=0;D=1;

		for(j=0;j<n+1;j++){    //手順6のループ

			if(i!=j){  //手順3
				D *= (x[i]-x[j]);
				l=1;

				for(k=0;k<n+1;k++){  //手順4
					if(k!=i && k!=j){
						l*=(x[p]-x[k]);
					}
				}

				N += l;  //手順5
			}

		};	

		//手順7
		L += (N/D * f(x[i]));
	}
	printf("f'(%d) = %f\t誤差 = %f\n",p,L,L-t);
}

//f(xi)の計算
double f(double x){
	double fx;
	fx = exp(x);
	return fx;
}

