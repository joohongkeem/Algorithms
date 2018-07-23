#include <stdio.h>
#include <string.h>

unsigned long long int koong[68];

int main()
{
	int T,N,i;

	koong[0] = 1;
	koong[1] = 1;
	koong[2] = 2;
	koong[3] = 4;

	for(i=4; i<=67; i++)
		koong[i] = koong[i-1]+koong[i-2]+koong[i-3]+koong[i-4];

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		printf("%lld\n",koong[N]);
	}

	
	return 0;
}