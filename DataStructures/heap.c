/* E1020 芝田 将 */
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 11

int heap[HEAP_SIZE];
int heaptail;

/*配列h[1..r]を対象として,h[k]だけがその子との間で部分順序付き木の条件を満たしていない時に,
  h[k]の値を正しい位置にふるい落とす。*/
void downheap(int k, int r)
{
	int i,v;

	i = 2*k;
	v = heap[k];

	while(i <= r){
		if(i<r && heap[i] < heap[i+1]){
			i = i+1;
		}
		if(heap[i] <= v){
			return;
		}

		heap[k] = heap[i];
		heap[i]=v;
		k = i;
		i = 2*k;
	}
}
/*
void downheap(int k,int r){
	int i,v;
	i = 2*k;
	v = heap[k];
	while(i<=r){
		// i<=rが真ということはindex kの左の子がいる
		if(i<r && heap[i]<heap[i+1]){
			// i<r つまりi<=r+1が真ということは右の子もいる。
			// 左の子よりも右の子のほうが大きかったら実行。 
			i++;
		}
		if(h[i]<=v){
			break;
		}else{
			// もし親よりも左の子が大きかったら入れ替える
			h[k]=h[i];
			k=i;
			i=2*k;
		}
	}
	heap[k]=v;
}
*/

void upheap(int k){
	int i,v;
	v = heap[k];
	i = k/2;
	while(i>=1){
		if(heap[i]>=v){
			break;
		}else{
			heap[k]=heap[i];
			k=i;
			i=k/2;
		}
	}
	heap[k]=v;
}



/*最大値を取り出してxに代入する。h[1]にh[n]のデータを入れ,h[1]のデータを適切にふるい落とす。*/
void getheap(){
	if(heaptail<1){
		printf("ヒープは空です.");
	}else{
		//x=heap[1];
		printf("最大値%dを取り出しました\n",heap[1]);
		heap[1]=heap[heaptail];
		heaptail--;
		//upheap(heaptail);
		downheap(1,heaptail);
	}
}

void printheap(){
	int i;
	for(i=1;i<=heaptail;i++){
		printf("heap[%d]=%d\n",i,heap[i]);
	}
}

/*ヒープh[1..n]にデータxを挿入する。*/
void putheap(int x){
	if(heaptail>=10){
		printf("ヒープは満杯です.");
		return;
	}else{
		heaptail++;
		heap[heaptail]=x;
		upheap(heaptail);
	}
}

/* キューの初期化 */
void init_heap() {
	int i;
	heaptail=7;
	for(i=1;i<=heaptail;i++){
		heap[i] = i;
	}
}

void mkheap(int index){
	int i;
	for(i=2;i<=index;i++){
		upheap(i);
	}
}

int main(void){

	printf("i： 後に続いて入力されたデータをヒープに挿入する．\n");
	printf("ヒープが満杯の場合はその旨をディスプレイに出力する．\n");
	printf("d： ヒープが保持する最大値のデータを削除する．\n");
	printf("ヒープが空の場合はその旨をディスプレイに出力する．\n");
	printf("p： ヒープのデータを配列のインデクス 1 から順番にディスプレイに出力する．\n");
	printf("q： 実行を終了する．\n");
	printf("上記以外： i，d，p，または q を入力する旨のメッセージをディスプレイに出力する．\n");

	int n;
	char c;
	init_heap();
	mkheap(heaptail);

	while(1){
		printf("\n>>>");
		scanf("%1s", &c);
		switch (c) {
			case 'i':
				scanf("%d", &n);
				putheap(n);
				break;
			case 'd':
				getheap();
				break;
			case 'p':
				printheap();
				break;
			case 'q':
				exit(0);
				break;
			default:
				printf("i,d,p,またはqを入力して下さい。\n");
		}
	}
}
