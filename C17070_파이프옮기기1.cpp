#include <stdio.h>

int N;
int graph[17][17];
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };
int result = 0;

bool check(int r, int c)
{
	if (r < 1 || r > N || c < 1 || c > N)
		return false;

	return true;
}
void DFS(int x, int y, int pipe)
{
	if (x == N && y == N)
	{
		result++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if ((i == 0 && pipe == 1) || (i == 1 && pipe == 0))
			continue;

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (graph[nx][ny] || !check(nx, ny))
			continue;

		if (i == 2 && (graph[x + 1][y] || graph[x][y + 1]))
			continue;

		DFS(nx, ny, i);
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	DFS(1, 2, 0);
	printf("%d", result);
	return 0;
}
