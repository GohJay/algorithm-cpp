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

using namespace std;

int n;
int k;
int visited[100001];
int answer;

void BFS()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, n));

	while (!q.empty())
	{
		int sec = q.top().first;
		int x = q.top().second;
		q.pop();

		if (x == k)
		{
			answer = sec;
			break;
		}

		visited[x] = 1;
		if (x - 1 >= 0 && !visited[x - 1])
			q.push(make_pair(sec + 1, x - 1));
		if (x + 1 <= 100000 && !visited[x + 1])
			q.push(make_pair(sec + 1, x + 1));
		if (x * 2 <= 100000 && !visited[x * 2])
			q.push(make_pair(sec, x * 2));
	}
}

int main()
{
	cin >> n >> k;

	BFS();

	cout << answer;
	return 0;
}
{\rtf1}