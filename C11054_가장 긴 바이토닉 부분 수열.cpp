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

int N;
int num[1000];
int dp_left[1000];
int dp_right[1000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		dp_left[i] = 1;
		dp_right[i] = 1;
	}	

	for (int i = 0; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if ((num[j] < num[i]) && (dp_left[i] < dp_left[j] + 1))
				dp_left[i] = dp_left[j] + 1;
		}
	}

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < N; j++)
		{
			if ((num[j] < num[i]) && (dp_right[i] < dp_right[j] + 1))
				dp_right[i] = dp_right[j] + 1;
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++)
		result = max(result, (dp_left[i] + dp_right[i]));

	cout << result - 1;
}
