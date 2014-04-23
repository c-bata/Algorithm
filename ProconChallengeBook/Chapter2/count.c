#include<stdio.h>
/* i++と++iのお話 */

// 結果どっちも一緒だった...
// for文では関係ないみたい

int main(void){
	// 後置:先に処理してから加算
	for(int i=0;i<3;i++)	printf("%d ",i);
	printf("\n");
	// 前置:先に加算してから処理
	for(int i=0;i<3;++i)	printf("%d ",i);
	printf("\n");
	return 0;
}
