/* Ants (POJ No.1852) */
/* 探索の問題と思わせながら、実はアイデアっていう問題
 * 全探索すると間に合わないから、ヒネる必要がある
 * 詳しくはプロコンチャレンジブック2 P.23 */

#include <stdio.h>
#include <stdlib.h>

int max(int, int);	//max関数のプロトタイプ宣言.
int min(int, int);

int main(){
	int a, l, n, x;
	int *mi, *ma;	// Answer min & max

	scanf("%d",&a);	// 1行目は問題の数. Sampleだと2問

	// 動的に配列を確保
	mi = malloc(sizeof(int)*a);
	ma = malloc(sizeof(int)*a);
	if( mi==NULL || ma==NULL){
		printf("error - malloc\n");
		exit(1);
	}

	for(int i=0;i<a;i++){
		scanf("%d %d",&l, &n);	// ポールの長さ, 蟻の数
		for(int j=0;j<n;j++){	// 蟻の数だけループ
			scanf("%d",&x);	// 左端からの蟻の位置
			// ここからが本番
			mi[i] = max(mi[i], min(x, l-x));
			ma[i] = max(ma[i], max(x, l-x));
		}
	}

	for(int i=0;i<a;i++){
		printf("%d %d\n",mi[i] ,ma[i]);
	}

	free(mi);free(ma);
	return 0;
}


int max(int a, int b){
	if(a > b){
		return a;
	}else{
		return b;
	}
}

int min(int a, int b){
	if(a > b){
		return b;
	}else{
		return a;
	}
}
