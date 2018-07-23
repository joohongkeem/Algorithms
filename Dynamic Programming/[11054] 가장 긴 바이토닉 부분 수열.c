#include <stdio.h>

int findmax(int a, int b)
{
	if(a>b) return a;
	else return b;
}

int main()
{
	int arr[1001];
	int LIS[1001];
	int LDS[1001];
	int i,j,max,N;

	scanf("%d",&N);
	for(i=1;i<=N;i++) scanf("%d",&arr[i]);

	LIS[1] = 1;
	for(i=2;i<=N;i++)
	{
		LIS[i] = 1;
		for(j=1;j<=i-1;j++) if(arr[i]>arr[j]) LIS[i] = findmax(LIS[i],LIS[j]+1);
	}

	LDS[N] = 1;
	for(i=N-1;i>=1;i--)
	{
		LDS[i] = 1;
		for(j=N;j>=i+1;j--) if(arr[i]>arr[j]) LDS[i] = findmax(LDS[i],LDS[j]+1);
	}

	max = 1;
	for(i=1;i<=N;i++) max = findmax(max, LIS[i]+LDS[i]);

	printf("%d\n",max-1);


	return 0;
}