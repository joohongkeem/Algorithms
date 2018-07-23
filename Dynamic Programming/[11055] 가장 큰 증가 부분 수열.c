#include <stdio.h>


int findmax(int a, int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int N,i,j,max;
	int arr[1001]={0};
	int dp[1001]={0};

	scanf("%d",&N);

	for(i=1;i<=N;i++) scanf("%d",&arr[i]);

	dp[1]=arr[1];
	for(i=2;i<=N;i++)
	{
		for(j=1;j<i;j++)
		{	
			if(arr[j]>=arr[i]) continue;
			else dp[i] = findmax(dp[i],dp[j]+arr[i]); 				
		}
		dp[i] = findmax(dp[i],arr[i]);
	}
	

	max = 0;
	for(i=1;i<=N;i++)
	{
		max = findmax(max, dp[i]);
	}
	printf("%d\n",max);
	return 0;
}