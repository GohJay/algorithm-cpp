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

int dp[100001][3];
int max[2][3];
int min[2][3];

void Solution(int n)
{
	max[0][0] = min[0][0] = dp[1][0];
	max[0][1] = min[0][1] = dp[1][1];
	max[0][2] = min[0][2] = dp[1][2];

	for (int i = 1; i < n; i++)
	{
		max[1][0] = std::max(max[0][0], max[0][1]) + dp[i + 1][0];
		max[1][1] = std::max(std::max(max[0][0], max[0][1]), max[0][2]) + dp[i + 1][1];
		max[1][2] = std::max(max[0][1], max[0][2]) + dp[i + 1][2];
		max[0][0] = max[1][0];
		max[0][1] = max[1][1];
		max[0][2] = max[1][2];

		min[1][0] = std::min(min[0][0], min[0][1]) + dp[i + 1][0];
		min[1][1] = std::min(std::min(min[0][0], min[0][1]), min[0][2]) + dp[i + 1][1];
		min[1][2] = std::min(min[0][1], min[0][2]) + dp[i + 1][2];
		min[0][0] = min[1][0];
		min[0][1] = min[1][1];
		min[0][2] = min[1][2];
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);

	Solution(N);

	int iMax = std::max(std::max(max[0][0], max[0][1]), max[0][2]);
	int iMin = std::min(std::min(min[0][0], min[0][1]), min[0][2]);
	printf("%d %d\n", iMax, iMin);

	return 0;
}
