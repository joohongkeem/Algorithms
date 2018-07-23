#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int N;
	int i, j;
	int count = 0;
	char num[3] = { 0 };
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		if (i <= 99)count++;
		else
		{
			if (i == 1000) break;
			num[0] = i % 10;
			num[1] = (i / 10) % 10;
			num[2] = (i / 100) % 10;

			if (num[2] - num[1] == num[1] - num[0]) count++;

		}

	}

	printf("%d", count);
	return 0;
}