#include <stdio.h>
#include <string.h>

char arr[103];

int main()
{
	int i,n,N;
	int max,len,check;
	scanf("%d",&N);
    getchar();
	while(N--)
	{
		gets(arr);
		len = strlen(arr);
		check = 0;
		for(i=0;i<=len;i++) 
		{
			if(arr[i]>=65 && arr[i]<=90) arr[i] = arr[i] + 32;
		}
		
		max = (len)/2-1;
		for(i=0;i<=max;i++) if(arr[0+i]!=arr[len-1-i]) {puts("No"); check = 1; break;}
		if(check == 0) puts("Yes");
		for(i=0;i<=len;i++) arr[i] = 0;
	}
	
	

	
	return 0;
}