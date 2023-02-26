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

#define INF     2100000000

using namespace std;

int N, M;
int result;
int graph[50][50];
vector<pair<int, int>> house, chicken;
bool reserved[13];

int distance(const pair<int, int>& a, const pair<int, int>& b)
{
    // 맨해튼 거리
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void DFS(int idx, int selected)
{
    // 조건 만족
    if (selected == M)
    {
        int tempResult = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int dist = INF;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (reserved[j])
                    dist = min(dist, distance(house[i], chicken[j]));
            }
            tempResult += dist;
        }
        result = min(result, tempResult);
        return;
    }
    
    // 기저 사례
    if (idx == chicken.size())
        return;

    // 프랜차이즈 선정
    reserved[idx] = true;
    DFS(idx + 1, selected + 1);

    // 프랜차이즈 선정 X
    reserved[idx] = false;
    DFS(idx + 1, selected);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
                house.emplace_back(make_pair(i, j));
            else if (graph[i][j] == 2)
                chicken.emplace_back(make_pair(i, j));
        }
    }

    result = INF;
    DFS(0, 0);


    cout << result << endl;
    return 0;
}
