#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int isalpha(char a)
{
	if((a>=65 && a<=90)||(a>=97 && a<=122)) return 1;
	else return 0;
}


int main()
{
	char arr[1000002]={0};
	int COUNT=0,i=0;
	scanf("%[^\n]s",arr);
	while(arr[i] != 0)
	{
		if(isalpha(arr[i]) == 1)
		{
			COUNT ++;
			i++;
			while(isalpha(arr[i]) != 0) i++;
		}
		else i++;
	}
	printf("%d\n",COUNT);
	return 0;

}