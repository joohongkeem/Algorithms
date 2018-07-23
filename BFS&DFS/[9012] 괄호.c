#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
	int N;
	char ctemp[51]={0};
	int len;
	int i;
	scanf("%d",&N);

	while(N--)
	{
		int TOP = 0;
		int BOTTOM = 0;
		int flag = 0;

		scanf("%s",ctemp);
		len = strlen(ctemp);
		
		for(i=0;i<len;i++)
		{
			if(ctemp[i]=='(') ++TOP;
			else if(ctemp[i]==')')--TOP;


			if(i!=len-1 && TOP<BOTTOM){ puts("NO"); flag = 1; break;}
			
		}
		if(flag==1) continue;
		
			if(TOP==BOTTOM ) puts("YES");
			else puts("NO");
	}


	return 0;
}