/* POJ No.2386 Lake Counting */
#include<cstdio>

#define MAX_N 100
#define MAX_M 100

char a[MAX_N][MAX_M+1];	// $0が入るから一つ多く作らないとダメ
int n, m;

void dfs(int x, int y){
	a[x][y] = '.';

	for(int i=x-1;i<=x+1;i++){
		for(int j=y-1;j<=y+1;j++){
			if(0<=i && i<=n && 0<=j && j<=m && a[i][j] == 'W') dfs(i,j);
		}
	}
}

int main(void){

	int ans = 0;
	//入力
	scanf("%d %d",&n ,&m);
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='W'){
				dfs(i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
