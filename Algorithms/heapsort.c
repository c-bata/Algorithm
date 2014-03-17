/* E1020 芝田 将 */
#include <stdio.h>
#include <stdlib.h>

#define N 1000000
int seed;

// 配列を初期化
void init(int A[]){
	int i;
	srand((unsigned int)seed);
	for(i=1;i<=N;i++){
		A[i]=rand();
	}
}

// A[1..n]のA[i]を下方にふるい落とす
void shift(int A[], int n, int i){
	int j, temp;
	int k = i;
	do{
		j = k;
		if(2*j <= n && A[2*j] > A[k]){	//kの左の子が存在して，kより大きい
			k = 2*j;
		}
		if(2*j+1 <= n && A[2*j+1] > A[k]){	//kの右の子が存在して，kより大きい
			k = 2*j + 1;
		}

		temp = A[j];
		A[j] = A[k];
		A[k] = temp;

	}while(j!=k);
}

void makeheap(int A[]){
	int i;
	for(i=N/2;i>0;i--){
		shift(A, N, i);
	}
}

void heap_sort(int A[]){
	int i, temp;
	makeheap(A);
	for(i=N;i>=2;i--){
		// ヒープの最初の要素とheap[i]を交換.
		temp = A[i];
		A[i] = A[1];
		A[1] = temp;
		shift(A, i-1, 1); // 配列の先頭アドレスとiを渡す.
	}
}

int main(void){
	int heap[N+1];
	printf("seed >> ");
	scanf("%d", &seed);
	init(heap);
	heap_sort(heap);
	printf("%d\n",heap[500000]);
	return 0;
}
