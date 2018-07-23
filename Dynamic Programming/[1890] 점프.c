#include <stdio.h>

int main()
{
	int N;
	int arr[101][101];
	long long int dp[101][101]={0};
	int i,j;
	scanf("%d",&N);

	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++) scanf("%d",&arr[i][j]);
	
	dp[1][1]=1;

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(i==N&&j==N) break;
			if(dp[i][j]>0){
				if(i+arr[i][j]<=N) {dp[i+arr[i][j]][j]+=dp[i][j];}
				if(j+arr[i][j]<=N) {dp[i][j+arr[i][j]]+=dp[i][j];}
			}
		}
	}


	printf("%lld",dp[N][N]);
	return 0;
}