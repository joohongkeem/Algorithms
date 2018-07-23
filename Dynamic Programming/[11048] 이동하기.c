#include <stdio.h>

int max (int a, int b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	int N,M,i,j,v;
	int dp[2][1001]={0};
	scanf("%d %d",&N,&M);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++) {
			scanf("%d",&v);
			dp[1][j] = max(dp[0][j], dp[1][j-1]) + v  ;
			dp[0][j] = dp[1][j];
		}
		
	}


	printf("%d\n",dp[1][M]);
	return 0;
}