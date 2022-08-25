#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	vector<long long> solution;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		solution.push_back(temp);
	}
	std::sort(solution.begin(), solution.end());

	int result[3];
	long long min = LLONG_MAX;
	for (int i = 0; i < N - 2; i++)
	{
		int target = solution[i];
		int begin = i + 1;
		int end = N - 1;

		while (begin < end)
		{
			long long val = target + solution[begin] + solution[end];
			if (abs(min) > abs(val))
			{
				min = val;
				result[0] = target;
				result[1] = solution[begin];
				result[2] = solution[end];
			}

			if (val < 0)
				begin++;
			else if (val > 0)
				end--;
			else
				break;
		}

		if (min == 0)
			break;
	}
	printf("%d %d %d\n", result[0], result[1], result[2]);
	return 0;
}
