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

#define INF		2100000000

using namespace std;

vector<pair<int, int>> graph[101];		// 그래프
vector<int> dist[101];					// 모든 노드 까지의 최단거리 배열
int node;

void dijkstra(int start)
{
	dist[start][start] = 0;		// 자기 자신의 거리는 0

	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int now = pq.top().first;			// 경유하는 노드
		int nowDist = -pq.top().second;		// 경유하는 노드 까지의 비용
		pq.pop();

		// 최단 거리가 아닌 경우 스킵
		if (dist[start][now] < nowDist)
			continue;

		// 간선이 있는 노드만 조사
		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;					// 경유 노드에서 갈 수 있는 인접 노드
			int nextDist = nowDist + graph[now][i].second;	// here 을 경유 했을때 start -> next 까지의 비용

			// 기존의 최소 비용보다 더 저렴하다면 교체
			if (nextDist < dist[start][next])
			{
				dist[start][next] = nextDist;
				pq.push({ next, -nextDist });
			}
		}
	}
}

int main()
{
	vector<int> item(101);

	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);

	for (int i = 1; i <= n; i++)
	{
		int cnt;
		scanf("%d ", &cnt);
		item[i] = cnt;

		graph[i].reserve(n + 1);
		dist[i].assign(n + 1, INF);
	}

	for (int i = 0; i < r; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		graph[from].emplace_back(pair<int, int>(to, cost));
		graph[to].emplace_back(pair<int, int>(from, cost));
	}

	for (int i = 1; i <= n; i++)
		dijkstra(i);

	int itemCount = 0;
	for (int i = 1; i <= n; i++)
	{
		int tempCount = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] <= m)
				tempCount += item[j];
		}
		itemCount = max(itemCount, tempCount);
	}

	printf("%d", itemCount);
	return 0;
}
