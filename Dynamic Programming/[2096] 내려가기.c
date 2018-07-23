#include <stdio.h>

int findmax(int a, int b)
{
	if(a>b) return a;
	else return b;
}
int findmax3(int a, int b, int c)
{
	return findmax(findmax(a,b),c);
}

int findmin(int a, int b)
{
	if(a>b) return b;
	else return a;
}
int findmin3(int a, int b, int c)
{
	return findmin(findmin(a,b),c);
}

int mindp[2][4];
int maxdp[2][4];

int main()
{
	int N;
	int i;
	int min=0,max=0;
	int arr[4];

	scanf("%d",&N);

	for(i=1;i<=N;i++)
	{
		scanf("%d %d %d", &arr[1],&arr[2],&arr[3]);
		mindp[1][1] = findmin(mindp[0][1]+arr[1],mindp[0][2]+arr[1]);
		mindp[1][2] = findmin3(mindp[0][1]+arr[2],mindp[0][2]+arr[2],mindp[0][3]+arr[2]);
		mindp[1][3] = findmin(mindp[0][2]+arr[3],mindp[0][3]+arr[3]);

		mindp[0][1]=mindp[1][1];
		mindp[0][2]=mindp[1][2];
		mindp[0][3]=mindp[1][3];

		maxdp[1][1] = findmax(maxdp[0][1]+arr[1],maxdp[0][2]+arr[1]);
		maxdp[1][2] = findmax3(maxdp[0][1]+arr[2],maxdp[0][2]+arr[2],maxdp[0][3]+arr[2]);
		maxdp[1][3] = findmax(maxdp[0][2]+arr[3],maxdp[0][3]+arr[3]);

		maxdp[0][1]=maxdp[1][1];
		maxdp[0][2]=maxdp[1][2];
		maxdp[0][3]=maxdp[1][3];
	}

	printf("%d ", findmax3(maxdp[1][1],maxdp[1][2],maxdp[1][3]));
	printf("%d", findmin3(mindp[1][1],mindp[1][2],mindp[1][3]));
	return 0;
}