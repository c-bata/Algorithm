/* E1020 芝田 将 */
#include <stdio.h>

int fibonacci(int n){
	int a=1,b=0,i;
	for(i=0;i<n;i++){
		b+=a;
		a=b-a;
	}
	return b;
}

int main(void){
	printf("自然数を入力して下さい。\n");
	int n;
	do{
		printf("\n>>>");
		scanf("%d", &n);
	}while(n<0);
	printf("%d番目のフィボナッチ数は%dです。\n",n,fibonacci(n));
}
