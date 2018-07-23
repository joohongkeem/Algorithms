#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int N, K;
char board[101][101];
char move[10001];
char headx=1, heady=1, tailx=1, taily=1;
int TIME;
char head_dir;
char tail_dir;
int Len=1;


int main()
{
	int i,j,C;

	scanf("%d",&N);
	scanf("%d",&K);

	while(K--)
	{
		int tx, ty;
		scanf("%d %d",&ty, &tx);
		board[ty][tx] = -1;
	}


	scanf("%d" ,&C);

	while(C--)
	{
		int t;
		char tc;
		scanf("%d %c",&t, &tc);
		move[t] = tc;
	}

	board[1][1] = 1;
	headx = 1;
	heady = 1;
	tailx = 1;
	taily = 1;


	while(1)
	{
		TIME++;

		// head의 방향을 지정해준다.
		// 0(오른쪽), 1(아래쪽), 2(왼쪽), 3(위쪽)
		if(move[TIME-1] == 'L')
		{
			head_dir = (head_dir+4-1)%4;
		}
		else if(move[TIME-1] == 'D')
		{
			head_dir = (head_dir+4+1)%4;
		}

		// tail의 방향을 지정해준다.
		// 0(오른쪽), 1(아래쪽), 2(왼쪽), 3(위쪽)
		// 
		// [핵심★]
		// Len이 늘어나면 체크한 move를 다시 체크하여 방향이 꼬일 수 있으므로,
		// move배열을 통해 꼬리의 방향을 바꿨다면, 0으로 세팅하여 꼬임을 방지한다.
		// (이것 때문에 계속 틀렸습니다!!)
		if(move[TIME-Len] == 'L')
		{
			tail_dir = (tail_dir+4-1)%4;
			move[TIME-Len] = 0;				
		}
		else if(move[TIME-Len] == 'D')
		{
			tail_dir = (tail_dir+4+1)%4;
			move[TIME-Len] = 0;
		}

		if(head_dir == 0)	// 오른쪽 진행
		{
			if(headx + 1 > N ) break;					// 보드 밖으로 나가면 종료
			if(board[heady][headx+1] == 1) break;		// 뱀의 머리가 뱀을 만나면 종료
			if(board[heady][headx+1] == -1)				// 뱀의 머리가 사과라면?
			{
				Len++;
			}
			else										// 뱀의 머리가 빈땅이라면?
			{
				board[taily][tailx] = 0;				// 기존의 꼬리를 없애고
														// 꼬리의 방향에 따라서 새로운 꼬리 설정
				if(tail_dir == 0) tailx = tailx+1;
				else if(tail_dir == 1) taily = taily+1;
				else if(tail_dir == 2) tailx = tailx-1;
				else if(tail_dir == 3) taily = taily-1;
			}


			board[heady][headx+1] = 1;					// 머리가 이동한 곳을 1로 바꾸고 새로운 머리 지정
			headx = headx+1;

		}
		else if(head_dir == 1)	// 아래쪽 진행
		{
			if(heady + 1 > N) break;
			if(board[heady+1][headx] == 1 ) break;
			if(board[heady+1][headx] == -1)
			{
				Len++;
			}
			else
			{
				
				board[taily][tailx] = 0;
				if(tail_dir == 0) tailx = tailx+1;
				else if(tail_dir == 1) taily = taily+1;
				else if(tail_dir == 2) tailx = tailx-1;
				else if(tail_dir == 3) taily = taily-1;

			}
			
				board[heady+1][headx] = 1;
				heady=heady+1;
			
		}
		else if(head_dir == 2)	// 왼쪽 진행
		{
			if(headx - 1 < 1) break;
			if(board[heady][headx-1] == 1) break;
			if(board[heady][headx-1] == -1)
			{
				
				Len++;
			}
			else
			{
				board[taily][tailx] = 0;
				if(tail_dir == 0) tailx = tailx+1;
				else if(tail_dir == 1) taily = taily+1;
				else if(tail_dir == 2) tailx = tailx-1;
				else if(tail_dir == 3) taily = taily-1;
			}
			
				board[heady][headx-1] = 1;
				headx= headx -1;
			
		}
		else if(head_dir == 3)	// 위쪽 진행
		{
			if(heady - 1 < 1) break;
			if(board[heady-1][headx] == 1 ) break;
			if(board[heady-1][headx] == -1)
			{
				Len++;
			}
			else
			{
				board[taily][tailx] = 0;
				if(tail_dir == 0) tailx = tailx+1;
				else if(tail_dir == 1) taily = taily+1;
				else if(tail_dir == 2) tailx = tailx-1;
				else if(tail_dir == 3) taily = taily-1;
			}
			
				board[heady-1][headx] = 1;
				heady=heady-1;
			
		}

	}
	
	printf("%d\n",TIME);

	return 0;
}