#include <stdio.h>
#include <math.h>

#define DIVIDE_NUM 20

double fx(double x){
	return 1/(double)x;
}

void sectional_measurement_a(double a, double b, double truevalue){
	int i;
	double h = (b-a)/(double)DIVIDE_NUM;
	double sum = 0;

	for(i=0;i<DIVIDE_NUM;i++){
		sum += h * fx(a + i*h);
	}

	printf("(a)計算値 : %f , 真値との差 : %f\n",sum,sum-truevalue);
}

void sectional_measurement_b(double a, double b, double truevalue){
	int i;
	double h = (b-a)/(double)DIVIDE_NUM;
	double sum = 0;

	for(i=0;i<DIVIDE_NUM;i++){
		sum += h * fx(a + (i+1)*h);
	}

	printf("(b)計算値 : %f , 真値との差 : %f\n",sum,sum-truevalue);
}

void sectional_measurement_c(double a, double b, double truevalue){
	int i;
	double h = (b-a)/(double)DIVIDE_NUM;
	double sum = 0;

	for(i=0;i<DIVIDE_NUM;i++){
		sum += h * fx(a + i*h + h/2);
	}

	printf("(c)計算値 : %f , 真値との差 : %f\n",sum,sum-truevalue);
}

void sectional_measurement_d(double a, double b, double truevalue){
	int i;
	double h = (b-a)/(double)DIVIDE_NUM;
	double sum = 0;

	for(i=0;i<DIVIDE_NUM;i++){
		sum += h * (fx(a+i*h) + fx(a+(i+1)*h));
	}
	sum /= 2;

	printf("(d)計算値 : %f , 真値との差 : %f\n",sum,sum-truevalue);
}

void simpson(double a, double b, double truevalue){
	int i;
	double h = (b-a)/(double)DIVIDE_NUM;
	double t1, t2 = 0, t3 = 0;

	t1 = fx(a) + fx(b);

	for(i=1;i<DIVIDE_NUM;i++){
		if(i%2 == 1)
			t2 += fx(a+i*h);
		else
			t3 += fx(a+i*h);
	}

	double ans = h*(t1 + 4*t2 + 2*t3)/3;

	printf("(d)計算値 : %f , 真値との差 : %f\n",ans ,ans-truevalue);

}

int main(void){
	double truevalue = log(3);
	sectional_measurement_a(1, 3, truevalue);
	sectional_measurement_b(1, 3, truevalue);
	sectional_measurement_c(1, 3, truevalue);
	sectional_measurement_d(1, 3, truevalue);
	simpson(1, 3, truevalue);
	return 0;
}
