#include <stdio.h>

int arr[2][100001];
int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int T, n;
	int i,t;
	int dp[2][3];

	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&n);
		
		for(i=1;i<=n;i++) scanf("%d",&arr[0][i]);
		for(i=1;i<=n;i++) scanf("%d",&arr[1][i]);

		dp[0][0] = arr[0][1];
		dp[1][0] = arr[1][1];
		dp[0][1] = arr[1][1]+ arr[0][2];
		dp[1][1] = arr[0][1]+ arr[1][2];
		if(n==1||n==2) { printf("%d\n", max(dp[0][n],dp[1][n])); continue;}
		for(i=3;i<=n;i++)
		{
			dp[0][2] = max(dp[1][1]+arr[0][i],dp[1][0] + arr[0][i]);
			dp[1][2] = max(dp[0][1]+arr[1][i],dp[0][0] + arr[1][i]);

			dp[0][0] = dp[0][1];
			dp[1][0] = dp[1][1];
			dp[0][1] = dp[0][2];
			dp[1][1] = dp[1][2];
		}
		printf("%d\n",max(dp[0][2],dp[1][2]));
	}


	return 0;
}