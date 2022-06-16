#include <stdio.h>
#include <queue>

int main()
{
	std::priority_queue<int> queue;
	int N, x;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		if (x == 0)
		{
			int top = 0;
			if (!queue.empty())
			{
				top = queue.top();
				queue.pop();
			}
			printf("%d\n", top);
		}
		else
		{
			queue.push(x);
		}
	}
	return 0;
}
