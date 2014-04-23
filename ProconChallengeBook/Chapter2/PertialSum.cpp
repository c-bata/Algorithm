/* P.34 部分和問題 
 * 木構造、再帰による深さ優先検索(DFS)を使う
 * */
#include<cstdio>

//int n=4, a[]={1,2,4,7}, k=13;	//Input1
int n=4, a[]={1,2,4,7}, k=15;	//Input2

bool dfs(int i, int sum){
	if(i==n) return sum==k;
	if(dfs(i+1, sum)) return true;		//a[i]を使わない場合
	if(dfs(i+1, sum+a[i])) return true;		//a[i]を使う
	return false;
}

int main(void){
	if(dfs(0,0)){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}
