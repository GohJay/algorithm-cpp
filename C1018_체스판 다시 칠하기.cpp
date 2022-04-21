#include <stdio.h>

int main()
{
	char board[50][50];
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", &board[i]);
	int min = 32;
	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			int cntBlack = 0;
			int cntWhite = 0;
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if ((k + l) % 2 == 0)
					{
						if (board[k][l] == 'B')
							cntWhite++;
						else
							cntBlack++;
					}
					else
					{
						if (board[k][l] == 'B')
							cntBlack++;
						else
							cntWhite++;
					}
				}
			}
			min = min > cntBlack ? cntBlack : min;
			min = min > cntWhite ? cntWhite : min;
		}
	}
	printf("%d\n", min);
}