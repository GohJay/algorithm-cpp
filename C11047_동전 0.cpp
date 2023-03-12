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

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> vect;
    vect.reserve(N + 1);

    int coin;
    for (int i = 1; i <= N; i++)
    {
        cin >> coin;
        vect[i] = coin;
    }

    int result = 0;
    while (K)
    {
        while (K - vect[N] >= 0)
        {
            K -= vect[N];
            result++;
        }
        N--;
    }

    cout << result;
    return 0;
}
