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

using namespace std;

int dp[501][501];

int Solution(int n)
{
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
				dp[i][j] = dp[i - 1][j] + dp[i][j];
			else if (i == j)
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];

			ret = max(ret, dp[i][j]);
		}
	}
	return ret;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
			scanf("%d", &dp[i][j]);
	}

	int answer = Solution(N);
	printf("%d\n", answer);

	return 0;
}
