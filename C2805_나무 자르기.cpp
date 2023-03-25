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

long long tree[10000001];
long long low;
long long high;
long long mid;

int main()
{
	int K;
	int N;
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> tree[i];
		if (high < tree[i])
			high = tree[i];
	}

	long long result = 0;
	while (low <= high)
	{
		long long wood = 0;
		mid = (low + high) / 2;

		for (int i = 0; i < K; i++)
		{
			long long temp = tree[i] - mid;
			if (temp > 0)
				wood += temp;
		}

		if (wood >= N)
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
