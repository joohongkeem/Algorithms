#include <stdio.h>
#include <string.h>

char arr[6];

int main()
{
	int i;
	int max,len,check;
	while(1)
    {
        for(i=0;i<=5;i++) arr[i]=-1;
		check = 0;
        scanf("%s",arr);
        if(arr[0] == '0') break;
        
        len = strlen(arr);
	    max = (len)/2-1;

		for(i=0;i<=max;i++) if(arr[0+i]!=arr[len-1-i]) {puts("no"); check = 1;break;}
		
	if(check==0) puts("yes");
    }
	
	return 0;
}