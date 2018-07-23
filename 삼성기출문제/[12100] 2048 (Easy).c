#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int N;
int board[22][22];
int MAX = 0;

int max(int a, int b)
{
	if(a>b) return a;
	else return b;
}

void moveup(int idx, int (*p)[22]);
void moveright(int idx, int (*p)[22]);
void movedown(int idx, int (*p)[22]);
void moveleft(int idx, int (*p)[22]);

void makingANS(int (*arr)[22],int idx)
{
	int i,j;
	int temp[22][22];
	if(idx ==5)
	{
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				MAX=max(MAX,arr[i][j]);
		return;
	}
	
	//puts("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) temp[i][j] = arr[i][j];
	moveup(idx+1,temp);
	
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) temp[i][j] = arr[i][j];
	movedown(idx+1,temp);

	
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) temp[i][j] = arr[i][j];
	moveleft(idx+1,temp);
	
	for(i=1;i<=N;i++) for(j=1;j<=N;j++) temp[i][j] = arr[i][j];
	moveright(idx+1,temp);
}

void moveup(int idx, int (*p)[22])
{
	int i,j;
	int temp[22][22] = {0};
	int NEXT[22][22] = {0};
	
	for(j=1;j<=N;j++)
	{
		int K= 1;
		for(i=1;i<=N;i++)
		{
			if(p[i][j] == 0) continue;
			else
			{
				temp[K][j] = p[i][j];
				K++;
			}	
		}
	}

	for(j=1; j<=N; j++)
	{
		for(i=1; i<=N; i++)
		{
			if(temp[i][j] == temp[i+1][j])
			{
				temp[i][j] += temp[i+1][j];
				temp[i+1][j] = 0;
			}
		}
	}

	for(j=1;j<=N;j++)
	{
		int K= 1;
		for(i=1;i<=N;i++)
		{
			if(temp[i][j] == 0) continue;
			else
			{
				NEXT[K][j] = temp[i][j];
				K++;
			}	
		}
	}

	//puts("---------UP---------");
	//for(i=1;i<=N;i++)
	//{
	//	for(j=1;j<=N;j++) printf("%d ", NEXT[i][j]);
	//	puts("");
	//}

	makingANS(NEXT,idx);
}

void movedown(int idx, int (*p)[22])
{
	int i,j;
	int temp[22][22] = {0};
	int NEXT[22][22] = {0};

	
	for(j=1;j<=N;j++)
	{
		int K= N;
		for(i=N;i>=1;i--)
		{
			if(p[i][j] == 0) continue;
			else
			{
				temp[K][j] = p[i][j];
				K--;
			}	
		}
	}

	for(j=1; j<=N; j++)
	{
		for(i=N; i>=1; i--)
		{
			if(temp[i][j] == temp[i-1][j])
			{
				temp[i][j] += temp[i-1][j];
				temp[i-1][j] = 0;
			}
		}
	}
	for(j=1;j<=N;j++)
	{
		int K= N;
		for(i=N;i>=1;i--)
		{
			if(temp[i][j] == 0) continue;
			else
			{
				NEXT[K][j] = temp[i][j];
				K--;
			}	
		}
	}
	//puts("---------DOWN---------");
	//for(i=1;i<=N;i++)
	//{
	//	for(j=1;j<=N;j++) printf("%d ", NEXT[i][j]);
	//	puts("");
	//}

	makingANS(NEXT,idx);
}
void moveleft(int idx, int (*p)[22])
{
	int i,j;
	int temp[22][22] = {0};
	int NEXT[22][22] = {0};

	for(i=1;i<=N;i++)
	{
		int K = 1;
		for(j=1;j<=N;j++)
		{
			if(p[i][j] == 0) continue;
			else
			{
				temp[i][K] = p[i][j];
				K++;
			}
		}
	}

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(temp[i][j] == temp[i][j+1])
			{
				temp[i][j] += temp[i][j+1];
				temp[i][j+1] = 0;
			}
		}
	}


	for(i=1;i<=N;i++)
	{
		int K = 1;
		for(j=1;j<=N;j++)
		{
			if(temp[i][j] == 0) continue;
			else
			{
				NEXT[i][K] = temp[i][j];
				K++;
			}
		}
	}
	//puts("---------LEFT---------");
	//for(i=1;i<=N;i++)
	//{
	//	for(j=1;j<=N;j++) printf("%d ", NEXT[i][j]);
	//	puts("");
	//}

	makingANS(NEXT,idx);
}
void moveright(int idx, int (*p)[22])
{
	int i,j;
	int temp[22][22] = {0};
	int NEXT[22][22] = {0};

	for(i=1;i<=N;i++)
	{
		int K = N;
		for(j=N;j>=1;j--)
		{
			if(p[i][j] == 0) continue;
			else
			{
				temp[i][K] = p[i][j];
				K--;
			}
		}
	}

	for(i=1;i<=N;i++)
	{
		for(j=N;j>=1;j--)
		{
			if(temp[i][j] == temp[i][j-1])
			{
				temp[i][j] += temp[i][j-1];
				temp[i][j-1] = 0;
			}
		}
	}


	for(i=1;i<=N;i++)
	{
		int K = N;
		for(j=N;j>=1;j--)
		{
			if(temp[i][j] == 0) continue;
			else
			{
				NEXT[i][K] = temp[i][j];
				K--;
			}
		}
	}

	//puts("---------RIGHT---------");
	//for(i=1;i<=N;i++)
	//{
	//	for(j=1;j<=N;j++) printf("%d ", NEXT[i][j]);
	//	puts("");
	//}

	makingANS(NEXT,idx);
}

int main()
{
	int i,j;
	scanf("%d", &N);
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++) scanf("%d",&board[i][j]);


	makingANS(board,0);


	printf("%d\n", MAX);

}