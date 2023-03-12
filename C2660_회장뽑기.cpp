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

int graph[51][51];
int node;
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
    cin >> node;
    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            if (i != j)
                graph[i][j] = INF;
        }
    }

    for (;;)
    {
        cin >> from >> to;
        if (from == -1 && to == -1)
            break;

        graph[from][to] = 1;
        graph[to][from] = 1;
    }

    FloydWashall();

    int result = INF;
    vector<int> vect;
    vect.reserve(node);

    for (int i = 1; i <= node; i++)
    {
        int temp = 0;
        for (int j = 1; j <= node; j++)
            temp = max(temp, graph[i][j]);

        if (temp < result)
        {
            result = temp;
            vect.clear();
            vect.emplace_back(i);
        }
        else if (temp == result)
            vect.emplace_back(i);
    }

    cout << result << " " << vect.size() << '\n';
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";

    return 0;
}
