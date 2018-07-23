#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int N;
char garomap[52][52];
char seromap[52][52];

int maxoftwo(int a, int b)
{
	if(a>b) return a;
	else return b;
}

void init_map()
{
	int i, j;
	for(i=1; i<=N; i++)
	{
		for(j=1;j<=N;j++)
		{
			garomap[i][j] = 1;
			seromap[i][j] = 1;
		}
	}
}
void mapmaking(char (*p)[52])
{
	int i,j;

	for(i=1; i<=N; i++)
	{
		for(j=2;j<=N;j++)
			if(p[i][j] == p[i][j-1]) garomap[i][j] = garomap[i][j-1]+1;
	}	

	for(i=2; i<=N; i++)
	{
		for(j=1;j<=N;j++)
			if(p[i][j] == p[i-1][j]) seromap[i][j] = seromap[i-1][j] +1;
	}	

}
int changeup(char (*arr)[52],int x, int y)
{
	char temp;
	int i, j;
	int max = 0;
	char tmpmap[52][52];

	if(x==1) return 0;
	
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) tmpmap[i][j] = arr[i][j];

	temp = tmpmap[x][y];
	tmpmap[x][y] = tmpmap[x-1][y];
	tmpmap[x-1][y] = temp;

	init_map();
	mapmaking(tmpmap);
	
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) if(garomap[i][j] > max) max = garomap[i][j];
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) if(seromap[i][j] > max) max = seromap[i][j];
	


	return max;
}

int changeleft(char (*arr)[52],int x, int y)
{
	char temp;
	int i, j;
	int max = 0;
	char tmpmap[52][52];

	if(y==1) return 0;

	for(i=1;i<=N;i++) for(j=1;j<=N;j++) tmpmap[i][j] = arr[i][j];

	temp = tmpmap[x][y];
	tmpmap[x][y] = tmpmap[x][y-1];
	tmpmap[x][y-1] = temp;

	init_map();
	mapmaking(tmpmap);
	
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) if(garomap[i][j] > max) max = garomap[i][j];
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) if(seromap[i][j] > max) max = seromap[i][j];

	return max;
}
int main()
{
	int i,j;
	int ans = 0;
	char arr[52][52];
	int temp;
	
	scanf("%d",&N);

	for(i=1;i<=N;i++)
	{
		scanf("%s",&arr[i][1]);
	}

	
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			temp = maxoftwo(changeup(arr,i,j),changeleft(arr,i,j));
			if(ans < temp) ans = temp;
		}
	}

	printf("%d", ans);

	return 0;
}