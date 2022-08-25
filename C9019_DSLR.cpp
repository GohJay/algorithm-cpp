#include <stdio.h>
#include <queue>
#include <string>

using namespace std;

string BFS(int start, int end)
{
	int visited[10000] = { 0, };
	queue<pair<int, string>> container;
	container.push(pair<int, string>(start, ""));
	while (container.size() > 0)
	{
		pair<int, string> temp = container.front();
		container.pop();
		int var = temp.first;
		string str = temp.second;

		if (var == end)
			return str;

		int D = (var << 1) % 10000;
		if (!visited[D])
		{
			container.push(pair<int, string>(D, str + "D"));
			visited[D] = 1;
		}

		int S = (var > 0) ? var - 1 : 9999;
		if (!visited[S])
		{
			container.push(pair<int, string>(S, str + "S"));
			visited[S] = 1;
		}

		int L = (var % 1000) * 10 + (var / 1000);
		if (!visited[L])
		{
			container.push(pair<int, string>(L, str + "L"));
			visited[L] = 1;
		}

		int R = (var % 10) * 1000 + (var / 10);
		if (!visited[R])
		{
			container.push(pair<int, string>(R, str + "R"));
			visited[R] = 1;
		}
	}
	return "";
}
int main()
{
	int T;
	int A, B;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &A, &B);
		printf("%s\n", BFS(A, B).c_str());
	}
	return 0;
}
