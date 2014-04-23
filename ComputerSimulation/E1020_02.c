#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// プロトタイプ宣言
void func1(void);
double func2(double);
float func3_1(void);
double func3_2(void);
float func3_3(void);

int main(void){

	func1();
	//double ans2_1 = func2(M_PI/6);
	//double ans2_2 = ((double)(int)(ans2_1*1000+0.5))/1000;
	double ans2 = ((double)(int)(func2(M_PI/6)*1000+0.5))/1000;

	printf("2. 誤差は%f\n\n",ans2-(sqrt(3)/2));

	printf("3. (1) %f\n"  ,func3_1());
	printf("3. (2) %f\n"  ,func3_2());
	printf("3. (3) %f\n\n",func3_3());

	return 0;
}


float func3_1(){
	float x=1234567, y=0.01;
	float s = sqrtf(x+y);
	return s-sqrtf(x);
}

double func3_2(){
	double x=1234567, y=0.01;
	double s = sqrt(x+y);
	return s-sqrt(x);
}

float func3_3(){
	float ans, x=1234567, y=0.01;
	float s = sqrtf(x+y);
	float s1 = s+sqrtf(x);
	ans = y/s1;
	return ans;
}

double func2(double x){
	double ans;
	ans = 1 - (x*x)/2;
	return ans;
}

void func1(){

	double xb, xa;

	printf("1. 初期値を入力して下さい。\n>>> ");
	scanf("%lf",&xa);

	do{
		xb = xa;
		xa = 1 + (1/xb);
		printf("%f\n",xa);
	}while(fabs(xa-xb) >= 0.0001);
	printf("この2次方程式の解は%fです。\n\n",xa);

	/* 1 2つめ */
	printf("1-2. 初期値を入力して下さい。\n>>> ");
	scanf("%lf",&xa);
	do{
		xb = xa;
		xa = (xb*xb+1)/(2*xb-1);
		printf("%f\n",xa);
	}while(fabs(xa-xb) >= 0.0001);

	printf("この2次方程式の解は%fです。\n\n",xa);
}
