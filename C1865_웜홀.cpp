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

#define INF 2100000000

using namespace std;

struct EDGE
{
	EDGE(int a, int b, int c) : s(a), e(b), t(c)
	{
	}

	int s;
	int e;
	int t;
};

bool BellmanFord(const vector<EDGE>& edges, int n)
{
	vector<int> dist(n + 1, INF);
	dist[1] = 0;
	int s, e, t;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;

			if (dist[e] > dist[s] + t)
				dist[e] = dist[s] + t;
		}
	}

	for (int j = 0; j < edges.size(); j++)
	{
		s = edges[j].s;
		e = edges[j].e;
		t = edges[j].t;

		if (dist[e] > dist[s] + t)
			return true;
	}

	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	int n, m, w;
	int s, e, t;
	vector<EDGE> edges;
	edges.reserve(501);

	while (TC > 0)
	{
		cin >> n >> m >> w;

		edges.clear();
		for (int i = 0; i < m; i++)
		{
			cin >> s >> e >> t;
			edges.emplace_back(s, e, t);
			edges.emplace_back(e, s, t);
		}

		for (int i = 0; i < w; i++)
		{
			cin >> s >> e >> t;
			edges.emplace_back(s, e, -t);
		}

		if (BellmanFord(edges, n))
			cout << "YES\n";
		else
			cout << "NO\n";

		TC--;
	}

	return 0;
}
