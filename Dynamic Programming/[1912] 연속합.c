#include <stdio.h>


int main()
{
	int N,i,value,max=-1001;
	int dp[2]={0};

	scanf("%d",&N);

	for(i=1;i<=N;i++) 
	{
		scanf("%d",&value);
		if(dp[0] < 0) dp[1] = value;
		else dp[1] = dp[0] + value;
		if(max<dp[1]) max = dp[1];
		dp[0] = dp[1];
	}
	
	

	printf("%ud\n",max);
	return 0;
}