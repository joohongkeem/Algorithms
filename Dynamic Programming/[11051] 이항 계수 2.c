#include <stdio.h>


int dp[2][1001];
int main()
{
	int N,K;
	int i,j;
	scanf("%d %d",&N,&K);

	dp[0][0] = 1;
	dp[0][1] = 1;
	if(N==1) {printf("1\n"); return 0;}
	for(i=2;i<=N;i++)
	{
		for(j=0;j<=i;j++)
		{
			dp[1][j] = dp[0][j-1] + dp[0][j];
			dp[1][j] %= 10007;

		}
		for(j=0;j<=i;j++)
		{
			
			dp[0][j] = dp[1][j];
		}
	}
	printf("%d\n",dp[1][K]);
	return 0;
}