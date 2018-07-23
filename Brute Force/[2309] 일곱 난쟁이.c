#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int key[9] = { 0 };
	int i, j, sum = 0,end=0,tmp;

	for (i = 0; i < 9; i++)
	{
		scanf("%d", &key[i]);
		sum += key[i];
	}

	for (i = 0; i <= 7; i++)
	{
		for (j = i + 1; j <= 8; j++)
		{
			if ((sum - key[i] - key[j]) == 100)
			{
				key[i] = 101;
				key[j] = 101;
				end = 1;
				break; 
			}
		}
		if (end == 1) break;
	}

	for (i = 0; i <8; i++)
	{
		for (j = 0; j<8-i; j++)
		{
			if (key[j] >= key[j+1])
			{
				tmp = key[j];
				key[j]= key[j+1];
				key[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < 7; i++)
	{
		printf("%d\n", key[i]);
	}


	return 0;
}