#include <stdio.h>


int main()
{
	char arr[14];
	int i,count = 0;
	int N;
	int a,b,c,d,e,f;
	while(1)
	{
		scanf("%d",&N);
		if(N==0) break;
		for(i=1;i<=N;i++)
		scanf("%d",&arr[i]);

		for(a=1;a<=N-5;a++)
			for(b=a+1;b<=N-4;b++)
				for(c=b+1;c<=N-3;c++)
					for(d=c+1;d<=N-2;d++)
						for(e=d+1;e<=N-1;e++)
							for(f=e+1;f<=N;f++)
								printf("%d %d %d %d %d %d\n",arr[a],arr[b],arr[c],arr[d],arr[e],arr[f]);
		puts("");
	}


	return 0;
}