#include <stdio.h>


int main()
{
	int n,i;
	int dp[3];
	dp[0]=1;
	dp[1]=1;
	
	scanf("%d",&n);
	if(n==1) {printf("%d",dp[1]); return 0;}
	for(i=2;i<=n;i++)
	{
		dp[2] = (dp[1] + 2*dp[0])%10007;
		dp[0] = dp[1];
		dp[1] = dp[2];
	}
	printf("%d",dp[2]);

	return 0;
}