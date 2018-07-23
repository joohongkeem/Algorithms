#include <stdio.h>

int dp[501][501]={0};
int ans[501][501]={0};
int N;
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}

void dfs(int (*ans)[501],int i, int j)
{
	if(dp[i][j] == 0) {ans[i][j] = max(ans[i][j],1); return;}


	if(((dp[i][j] & 1) == 1) && i-1>=1) { dfs(ans,i-1,j); dp[i][j]-=1; ans[i][j] = max(ans[i][j], ans[i-1][j]+1); }
	if(((dp[i][j] & 2) == 2) && j+1<=N) { dfs(ans,i,j+1); dp[i][j]-=2; ans[i][j] = max(ans[i][j], ans[i][j+1]+1); }
	if(((dp[i][j] & 4) == 4) && i+1<=N) { dfs(ans,i+1,j); dp[i][j]-=4; ans[i][j] = max(ans[i][j], ans[i+1][j]+1); }
	if(((dp[i][j] & 8) == 8) && j-1>=1) { dfs(ans,i,j-1); dp[i][j]-=8; ans[i][j] = max(ans[i][j], ans[i][j-1]+1); }

	return ;
}

int main()
{
	int i,j,tmp;

	scanf("%d",&N);
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) scanf("%d",&ans[i][j]);
	
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++) 
		{
			if(ans[i][j] < ans[i-1][j] && i-1 >= 1) dp[i][j] += 1;
			if(ans[i][j] < ans[i][j+1] && j+1 <= N) dp[i][j] += 2;
			if(ans[i][j] < ans[i+1][j] && i+1 <= N) dp[i][j] += 4;
			if(ans[i][j] < ans[i][j-1] && j-1 >= 1) dp[i][j] += 8;
		}
	}

    for(i=1;i<=N;i++) for(j=1;j<=N;j++) ans[i][j] = 0;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++) 
		{
			dfs(ans,i,j);
		}
	}

	tmp = 0;
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++) 
		{
			tmp = max(tmp,ans[i][j]);
		}
	}
    printf("%d\n",tmp);
	
	return 0;
}