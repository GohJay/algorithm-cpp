#include <stdio.h>
#include <math.h>

int square[128][128];
int cnt_W = 0;
int cnt_b = 0;
void solve(int y, int x, int size)
{
	int check = square[y][x];
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (check == 0 && square[i][j] == 1)
			{
				check = 2;
			}
			else if (check == 1 && square[i][j] == 0)
			{
				check = 2;
			}
			if (check == 2)
			{
				// 왼쪽 위 사분면 탐색
				solve(y, x, size / 2);
				// 오른쪽 위 사분면 탐색
				solve(y, x + size / 2, size / 2);
				// 왼쪽 아래 사분면 탐색
				solve(y + size / 2, x, size / 2);
				// 오른쪽 아래 사분면 탐색
				solve(y + size / 2, x + size / 2, size / 2);
				return;
			}
		}
	}
	if (check == 0)
		cnt_W++;
	else
		cnt_b++;
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%d", &square[i][j]);
	}
	solve(0, 0, N);
	printf("%d\n", cnt_W);
	printf("%d\n", cnt_b);
	return 0;
}
