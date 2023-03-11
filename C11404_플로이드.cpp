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

int graph[101][101];
int node;
int edge;
int from;
int to;
int dist;

void FloydWashall()
{
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            for (int k = 1; k <= node; k++)
            {
                if (graph[j][i] != INF && graph[i][k] != INF)
                    graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }
}

int main()
{
    cin >> node >> edge;
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
            graph[i][j] = INF;
    }

    for (int i = 0; i < edge; i++)
    {
        cin >> from >> to >> dist;
        if (graph[from][to] > dist)
            graph[from][to] = dist;
    }

    FloydWashall();

    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            if (i == j || graph[i][j] == INF)
                cout << 0 << " ";
            else
                cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
