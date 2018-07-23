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

		// head�� ������ �������ش�.
		// 0(������), 1(�Ʒ���), 2(����), 3(����)
		if(move[TIME-1] == 'L')
		{
			head_dir = (head_dir+4-1)%4;
		}
		else if(move[TIME-1] == 'D')
		{
			head_dir = (head_dir+4+1)%4;
		}

		// tail�� ������ �������ش�.
		// 0(������), 1(�Ʒ���), 2(����), 3(����)
		// 
		// [�ٽɡ�]
		// Len�� �þ�� üũ�� move�� �ٽ� üũ�Ͽ� ������ ���� �� �����Ƿ�,
		// move�迭�� ���� ������ ������ �ٲ�ٸ�, 0���� �����Ͽ� ������ �����Ѵ�.
		// (�̰� ������ ��� Ʋ�Ƚ��ϴ�!!)
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

		if(head_dir == 0)	// ������ ����
		{
			if(headx + 1 > N ) break;					// ���� ������ ������ ����
			if(board[heady][headx+1] == 1) break;		// ���� �Ӹ��� ���� ������ ����
			if(board[heady][headx+1] == -1)				// ���� �Ӹ��� ������?
			{
				Len++;
			}
			else										// ���� �Ӹ��� ���̶��?
			{
				board[taily][tailx] = 0;				// ������ ������ ���ְ�
														// ������ ���⿡ ���� ���ο� ���� ����
				if(tail_dir == 0) tailx = tailx+1;
				else if(tail_dir == 1) taily = taily+1;
				else if(tail_dir == 2) tailx = tailx-1;
				else if(tail_dir == 3) taily = taily-1;
			}


			board[heady][headx+1] = 1;					// �Ӹ��� �̵��� ���� 1�� �ٲٰ� ���ο� �Ӹ� ����
			headx = headx+1;

		}
		else if(head_dir == 1)	// �Ʒ��� ����
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
		else if(head_dir == 2)	// ���� ����
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
		else if(head_dir == 3)	// ���� ����
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