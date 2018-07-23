#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main()
{
	int T, x1, x2, y1, y2, r1, r2;
	long long int dis;
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		if(x1 == x2 && y1 == y2)
		{
			if(r1 == r2) puts("-1");
			else puts("0");

			continue;
		}
		
		dis = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);

		if(dis > (r1+r2)*(r1+r2) || dis < (r1-r2)*(r1-r2)) puts("0");
		else if(dis == (r1+r2)*(r1+r2)  || dis == (r1-r2)*(r1-r2)) puts("1");
		else if(dis < (r1+r2)*(r1+r2) || dis > (r1-r2)*(r1-r2)) puts("2");
	}


	return 0;
}