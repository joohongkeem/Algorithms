#include <stdio.h>

int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int N;
	int p[1001];
	int i,j;
	int dp[1001];

	scanf("%d",&N);

	for(i=1;i<=N;i++) scanf("%d",&p[i]);

	for(i=1;i<=N;i++)
	{
		dp[i] = p[i];
		for(j=1;j<=i-1;j++)
		{
			dp[i] = max(dp[i],dp[i-j]+p[j]);
		}
	}
	printf("%d\n",dp[N]);

	return 0;
}