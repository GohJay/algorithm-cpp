#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <functional>

using namespace std;

vector<pair<int, int>> graph[1001];
vector<vector<int>> path[1001];
int dist[1001];

void dijkstra(int start, int end, int n, vector<int> &answer)
{
	vector<int> route(n + 1, 0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (pq.size() > 0)
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost > dist[cur])
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int ncost = graph[cur][i].second;
			int ncur = graph[cur][i].first;
			
			if (dist[ncur] > cost + ncost)
			{
				dist[ncur] = ncost + cost;
				route[ncur] = cur;
				pq.push(make_pair(dist[ncur], ncur));
			}
		}
	}

	int temp = end;
	while (temp != 0)
	{
		answer.push_back(temp);
		temp = route[temp];
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INT_MAX;
	}
	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back(make_pair(end, cost));
	}
	int start, end;
	cin >> start >> end;
	vector<int> answer;
	dijkstra(start, end, n, answer);
	cout << dist[end] << endl;
	cout << answer.size() << endl;
	for (int i = answer.size() - 1; i >= 0; i--)
	{
		cout << answer[i] << " ";
	}
	return 0;
}
