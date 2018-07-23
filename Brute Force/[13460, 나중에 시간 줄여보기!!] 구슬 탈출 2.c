#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


char board[12][12];
int N,M;
int MIN = 100;

int min(int a, int b)
{
	if(a>b) return b;
	else return a;
}

void makingboard(char (*temp_board)[12], int idx);



// 위쪽으로 굴릴때
void swapup(char (*temp_board)[12],int idx)
{
	char temp;
	int i,j;
	if(idx>=MIN-1) return;
	idx++;

	for(j=1; j<=M;j++)
	{
		for(i=1; i<=N;i++)
		{
			if(temp_board[i][j] == '#' || temp_board[i][j] == '.') continue;
			else if(temp_board[i][j] == 'O')
			{
				int k = 1,check = 0;
				while(i+k<=N)
				{
					if(temp_board[i+k][j] == '#') break;
					else if(temp_board[i+k][j] == 'R') {check = 1; k++;}
					else if(temp_board[i+k][j] == 'B') return;
					else k++;
				}
				if(check) {MIN = min(MIN,idx); return;}
			}
			else
			{	
				int k = 1;

				while(i-k>=1)
				{
					
					if(temp_board[i-k][j] == '.') k++;
					else {k--; break;}
				}
				temp = temp_board[i][j];
				temp_board[i][j] = temp_board[i-k][j];
				temp_board[i-k][j] = temp;
			}
		}
	}

	makingboard(temp_board, idx);
}
void swapdown(char (*temp_board)[12],int idx)
{
	char temp;
	int i,j;
	if(idx>=MIN-1) return;
	idx++;

	for(j=1; j<=M;j++)
	{
		for(i=N; i>=1;i--)
		{
			if(temp_board[i][j] == '#' || temp_board[i][j] == '.') continue;
			else if(temp_board[i][j] == 'O')
			{
				int k = 1,check = 0;
				while(i-k>=1)
				{
					if(temp_board[i-k][j] == '#') break;
					else if(temp_board[i-k][j] == 'R') {check = 1; k++;}
					else if(temp_board[i-k][j] == 'B') return;
					else k++;
				}
				if(check) {MIN = min(MIN,idx); return;}
			}
			else
			{	
				int k = 1;

				while(i+k<=N)
				{
					if(temp_board[i+k][j] == '.') k++;
					else {k--; break;}
				}
				temp = temp_board[i][j];
				temp_board[i][j] = temp_board[i+k][j];
				temp_board[i+k][j] = temp;
			}
		}
	}

	makingboard(temp_board, idx);
}

void swapleft(char (*temp_board)[12],int idx)
{
	char temp;
	int i,j;


	if(idx>=MIN-1) return;
	idx++;

	for(i=1; i<=N;i++)
	{
		for(j=1; j<=M;j++)
		{
			if(temp_board[i][j] == '#' || temp_board[i][j] == '.') continue;
			else if(temp_board[i][j] == 'O')
			{
				int k = 1,check = 0;
				while(j+k<=M)
				{
					if(temp_board[i][j+k] == '#') break;
					else if(temp_board[i][j+k] == 'R') {check = 1; k++;}
					else if(temp_board[i][j+k] == 'B') return;
					else k++;
				}
				if(check) {MIN = min(MIN,idx); return;}
			}
			else
			{	
				int k = 1;
				while(j-k>=1)
				{
					if(temp_board[i][j-k] == '.') k++;
					else {k --; break;}
				}
				temp = temp_board[i][j];
				temp_board[i][j] = temp_board[i][j-k];
				temp_board[i][j-k] = temp;
			}
		}
	}
	

	makingboard(temp_board, idx);
}
void swapright(char (*temp_board)[12],int idx)
{
	char temp;
	int i,j;

	if(idx>=MIN-1) return;
	idx++;



	for(i=1; i<=N;i++)
	{
		for(j=M; j>=1;j--)
		{
			if(temp_board[i][j] == '#' && temp_board[i][j] != '.') continue;
			else if(temp_board[i][j] == 'O')
			{
				int k = 1,check = 0;
				while(j-k>=1)
				{
					if(temp_board[i][j-k] == '#') break;
					else if(temp_board[i][j-k] == 'R') {check = 1; k++;}
					else if(temp_board[i][j-k] == 'B') return;
					else k++;
				}
				if(check) {MIN = min(MIN,idx); return;}

			}
			else
			{	
				int k = 1;

				while(j+k<=M)
				{
					if(temp_board[i][j+k] == '.') k++;
					else {k --; break;}
				}
				temp = temp_board[i][j];
				temp_board[i][j] = temp_board[i][j+k];
				temp_board[i][j+k] = temp;
			}
		}
	}

	makingboard(temp_board, idx);
}

void makingboard(char (*p)[12], int idx)
{
	char temp_board[12][12] = {0};
	int i,j;
	
	if(idx >= 10 || idx>=MIN) return;

	for(i=1;i<=N;i++) for(j=1;j<=M; j++) temp_board[i][j] = p[i][j]; 
	swapup(temp_board,idx);
	for(i=1;i<=N;i++) for(j=1;j<=M; j++) temp_board[i][j] = p[i][j]; 
	swapdown(temp_board,idx);
	for(i=1;i<=N;i++) for(j=1;j<=M; j++) temp_board[i][j] = p[i][j]; 
	swapleft(temp_board,idx);
	for(i=1;i<=N;i++) for(j=1;j<=M; j++) temp_board[i][j] = p[i][j]; 
	swapright(temp_board,idx);
}


int main()
{

	int i;

	scanf("%d %d", &N, &M);
	for(i=1;i<=N;i++)
		 scanf("%s",&board[i][1]);


	makingboard(board,0);

	if(MIN == 100) printf("-1\n");
	else printf("%d",MIN);
	return 0;
}