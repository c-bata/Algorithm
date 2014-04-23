/* P21. 三角形 C言語で書いてみた */
#include <stdio.h>

int max(int, int);	//max関数のプロトタイプ宣言.

int solve(int n, int a[]){
	int ans = 0; // 答え
	int i, j, k; // カウンタ変数 C++じゃないので必要

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				int len  = a[i]+a[j]+a[k];	//周長
				int ma   = max(a[i], max(a[j], a[k]));

				/* はじめて解いた時↓の方法でやったけど、答えの方が綺麗だった。
				 * if((len-ma)>ma && len>ans)		ans = len; */

				if((len-ma) > ma) ans = max(ans, len);

			}
		}
	}
	return ans;
}

int main(void){
	int n=5, a[]={2,3,4,5,10};
	printf("%d\n",solve(n,a));
	return 0;
}

int max(int a, int b){
	/* C++じゃないので作成 */
	if(a > b){
		return a;
	}else{
		return b;
	}
}
