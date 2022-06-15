#include <iostream>

int dp[10];
int DP(int n)
{
	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}
int main()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	int T, N;
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		std::cin >> N;
		if (N <= 3)
			std::cout << dp[N] << std::endl;
		else
			std::cout << DP(N) << std::endl;
	}	
	return 0;
}
