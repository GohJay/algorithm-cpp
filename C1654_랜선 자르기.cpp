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

int line[10001];
long long low = 1;
long long high = 0;
long long mid;

int main()
{
	int K;
	int N;
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> line[i];
		if (high < line[i])
			high = line[i];
	}

	int result = 0;
	while (low <= high)
	{
		int cnt = 0;
		mid = (low + high) / 2;

		for (int i = 0; i < K; i++)
			cnt += line[i] / mid;

		if (cnt >= N)
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
