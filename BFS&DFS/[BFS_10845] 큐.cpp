#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[10001];
int FRONT=0;
int REAR=0;


int main()
{
	int N;
	char op[10];
	scanf("%d",&N);
	getchar();
	while(N--)
	{
	
		scanf("%[^\n]s",op);
		getchar();

		if(strncmp(op,"push",4)==0)
		{
			int input = atoi(&op[5]);
			arr[REAR++] = input;
		}

		if(strncmp(op,"pop",3)==0)
		{
			if(FRONT>=REAR) puts("-1");
			else printf("%d\n",arr[FRONT++]);
		}

		if(strncmp(op,"size",4)==0)
		{
			if(FRONT>=REAR) puts("0");
			else printf("%d\n",REAR-FRONT);
		}

		if(strncmp(op,"empty",5)==0)
		{
			if(FRONT>=REAR) puts("1");
			else puts("0");
		}

		if(strncmp(op,"front",5)==0)
		{
			if(FRONT>=REAR) puts("-1");
			else printf("%d\n",arr[FRONT]);
		}
		if(strncmp(op,"back",4)==0)
		{
			if(FRONT>=REAR) puts("-1");
			else printf("%d\n",arr[REAR-1]);
		}


	}


}