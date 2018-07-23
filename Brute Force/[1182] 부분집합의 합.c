#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pow(int x,int y)
{
	if (y == 0) return 1;
	if (y == 1) return x;
	return x*pow(x, y - 1);
}

int main(void)
{
	int N, S;
	int arr[21] = { 0 };
	int i, j, count = 0,sum,tmp;

	scanf("%d %d", &N, &S);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 1; i <= pow(2, N) - 1; i++)
	{
		sum = 0;
		for (j = N - 1; j >= 0; j--)
		{
			//tmp = 0; // 주석처리 가능할듯
			tmp = (i / pow(2, j))%2;
			sum += tmp * arr[N-j];
		}

		if (S == sum) count++;
	}
	printf("%d", count);

	return 0;
}