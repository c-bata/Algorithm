#include <stdio.h>
#include <math.h>	/* コンパイル時は -lm を付けないとコンパイルできない */
#include <assert.h> /* 後で消す */

/*
 * 1.
 * そのまま計算: O(n^2)
 * ホーナーの方法: O(n)
 *
 * 2.
 * O(n^3)
 * */

double func_a(double x, int n){
	/*
	 * x^nを求める
	 * */
	int i;
	for(i=n;i>1;i/=2){
		x *= x;
	}
	return x;
}

double func_b(double x){
	/*
	 * x^4 + 2x^3 - x^2 + 3x -1を求める
	 * */
	int i;
	double b[] = {1, 2, -1, 3, -1};
	for(i=0;i<4;i++){
		b[i+1] = b[i]*x+b[i+1];
	}
	return b[4];
}

void func_c(){
	int i, alpha=3;
	int c[] = {22, 21, 20, 19, 18};
	int ansc[5];
	ansc[0] = c[0];
	for(i=0;i<4;i++){
		ansc[i+1] = ansc[i]*alpha+c[i+1];
	}

	printf("商は%dx^3+%dx^2+%dx+%d\n", ansc[0], ansc[1], ansc[2], ansc[3]);
	printf("余りは%d\n",ansc[4]);
}

int main(void){
	/* 入力 */
	int n;
	double x;
	printf("xとnの順で入力して下さい.\n>> ");
	scanf("%lf %d",&x ,&n);

	/* (a) */
	printf("x^nは%fです.\n",func_a(x, n));
	/* test a */
	assert((int)func_a(2,  2) ==     4);
	assert((int)func_a(2,  4) ==    16);
	assert((int)func_a(2,  8) ==   256);
	assert((int)func_a(2, 16) == 65536);

	/* (b) */
	printf("xを入力して下さい.\n>> ");
	scanf("%lf",&x);
	printf("%f\n",func_b(x));
	/* test b */
	assert((int)func_b(1) == 4);

	/* (c) */
	func_c();
}
