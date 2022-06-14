#include <stdio.h>
#include <queue>
 
#define MAX_SIZE 1000

struct Tomato
{
	int y;
	int x;
};

std::queue<Tomato> queue;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };
int graph[MAX_SIZE][MAX_SIZE];
int M, N;

bool IsInside(int x, int y)
{
	return (0 <= x && 0 <= y && x < M && y < N);
}
void BFS()
{
	while (!queue.empty())
	{
		int x = queue.front().x;
		int y = queue.front().y;
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 그래프를 범위 안에 있으면서 익지않은 토마토일 경우
			if (IsInside(nx, ny) && graph[ny][nx] == 0)
			{
				graph[ny][nx] = graph[y][x] + 1;
				queue.push({ ny, nx });
			}
		}
	}
}
int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 1)
				queue.push({ i, j });
		}
	}

	BFS();

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 0)
			{
				printf("-1\n");
				return 0;
			}
			if (result < graph[i][j])
				result = graph[i][j];
		}
	}
	printf("%d\n", result - 1);
	return 0;
}
 