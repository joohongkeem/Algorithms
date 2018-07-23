#include <stdio.h>

int arr[2001];
int dp[2001][2001];
int main()
{
	int N,M,i,k;
	int S,E;
	scanf("%d",&N);
	for(i=1; i<=N; i++){scanf("%d",&arr[i]); dp[i][i] = 1;}

	for(i=1;i<=N-1;i++) if(arr[i]==arr[i+1]) dp[i][i+1] = 1;
	for(k=2;k<=N-1;k++) 
		for(i=1;i+k<=N;i++)
			if(arr[i]==arr[i+k]&&dp[i+1][i+k-1] == 1) dp[i][i+k] = 1;

	scanf("%d",&M);
	while(M--)
	{
		scanf("%d %d", &S,&E);
		printf("%d\n",dp[S][E]);
	}

	return 0;
}