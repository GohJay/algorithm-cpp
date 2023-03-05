#include <algorithm>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <string.h>
#include <unordered_map>

#define INF 2100000000

using namespace std;

int n;
int k;
int visited[100001];
int answer1;
int answer2;

void BFS()
{
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));

	answer1 = INF;
	answer2 = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int sec = q.front().second;
		q.pop();

		if (answer1 < sec)
			break;

		if (x == k)		
		{
			answer1 = sec;
			answer2++;
			continue;
		}

		visited[x] = 1;
		if (x - 1 >= 0 && !visited[x - 1])
			q.push(make_pair(x - 1, sec + 1));
		if (x + 1 <= 100000 && !visited[x + 1])
			q.push(make_pair(x + 1, sec + 1));
		if (x * 2 <= 100000 && !visited[x * 2])
			q.push(make_pair(x * 2, sec + 1));
	}
}

int main()
{
	cin >> n >> k;

	BFS();

	cout << answer1;
	cout << "\n";
	cout << answer2;
	return 0;
}
