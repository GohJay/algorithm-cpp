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

int router[10000001];
long long low;
long long high;
long long mid;

int main()
{
	int N;
	int C;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
		cin >> router[i];

	sort(router, router + N);
	high = router[N - 1];

	int result = 0;
	while (low <= high)
	{
		int dist = 1;
		int start = router[0];
		mid = (low + high) / 2;

		for (int i = 1; i < N; i++)
		{
			int end = router[i];
			if (end - start >= mid)
			{
				dist++;
				start = end;
			}
		}

		if (dist >= C)
		{
			low = mid + 1;
			if (result < mid)
				result = mid;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << result;
}
