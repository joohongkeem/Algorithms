#include <stdio.h>
#include <string.h>
int main()
{
	int N,i,j;
	int arr[1001];
	int dp[1001]={0};
	int max=0;

	scanf("%d",&N);
	for(i=1;i<=N;i++) scanf("%d",&arr[i]);
	
	dp[1] = 1;
	
	
	for(i=2;i<=N;i++)
	{
		for(j=1;j<i;j++)
		{
			if(arr[j]>=arr[i]) continue;
			else if(dp[i]<dp[j]+1) dp[i] = dp[j]+1;
		}
		if(dp[i]==0) dp[i]++;
	}

	
	for(i=1;i<=N;i++)
	{
		if(max<dp[i]) max=dp[i];	
	}
	printf("%d ",max);

	return 0;
}