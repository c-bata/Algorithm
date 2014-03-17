/* E1020 芝田 将 */
#include <stdio.h>
#include <stdlib.h>

#define N 1000000
int seed;
int A[N];

// 配列を初期化
void init(int A[]){
	int i;
	srand((unsigned int)seed);
	for(i=0;i<N;i++){
		A[i]=rand();
	}
}

void subsort(int s, int t){
	int i=s, j=t, temp;
	int x = A[s];	// ピボットは何でもいいので一番最初の要素を使う.
	do{
		// x(ピボット)を基準にして2つのクラスに分ける.
		while(A[i] < x){
			i=i+1;
		}
		while(x < A[j]){
			j=j-1;
		}
		if(i<=j){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i=i+1;
			j=j-1;
		}
	}while(i<j);

	if(s<j){
		subsort(s,j);	// x以下のクラスを再帰的にソート.
	}
	if(i<t){
		subsort(i,t);	// x以上のクラスを再帰的にソート.
	}
}

void quicksort(){
	subsort(0,N);
}

int main(void){
	printf("seed >> ");
	scanf("%d", &seed);
	init(A);
	quicksort();
	printf("%d\n",A[499998]);
	printf("%d\n",A[499999]);
	printf("%d\n",A[500000]);
	return 0;
}
