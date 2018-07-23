#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int STACK[10001];
int TOP = 0;
int BOTTOM = 0;

int main()
{
	int N;
	char ctemp[10]={0};
	int ntemp;

	scanf("%d",&N);
	getchar();
	while(N--)
	{
		scanf("%[^\n]",ctemp);
		getchar();

		if(strncmp(ctemp,"push",4)==0)
		{
			ntemp = atoi(&ctemp[5]);			
			STACK[++TOP] = ntemp;
		}
		else if(strncmp(ctemp,"top",3)==0)
		{
			if(TOP<=BOTTOM) puts("-1");
			else printf("%d\n",STACK[TOP]);
		}
		else if(strncmp(ctemp,"pop",3)==0)
		{
			if(TOP<=BOTTOM) puts("-1");
			else printf("%d\n",STACK[TOP--]);
		}
		else if(strncmp(ctemp,"size",4)==0)
		{
			printf("%d\n",TOP-BOTTOM);
		}
		else if(strncmp(ctemp,"empty",5)==0)
		{
			if(TOP<=BOTTOM) puts("1");
			else puts("0");
		}

	}


	return 0;
}