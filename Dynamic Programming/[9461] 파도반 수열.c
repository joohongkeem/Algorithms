#include <stdio.h>


int main()
{
	int N,T;
	int i,t;
	long long int arr[101]={0,1,1,1,2};
	
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&N);
		
		for(i=5;i<=N;i++)
		{
			arr[i] = arr[i-1]+arr[i-5];
		}
		printf("%lld\n",arr[N]);
	}

}