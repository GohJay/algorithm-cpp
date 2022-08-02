#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int T, N, M;
int A[1000];
int B[1000];
long long result;

void GetSumOfSubarr(int arr[], int size, vector<int> &out)
{
	for (int i = 0; i < size; i++)
	{
		int sum = arr[i];
		out.push_back(sum);
		for (int j = i + 1; j < size; j++)
		{
			sum += arr[j];
			out.push_back(sum);
		}
	}
}
void Solution()
{
	vector<int> vectA;
	vector<int> vectB;
	GetSumOfSubarr(A, N, vectA);
	GetSumOfSubarr(B, M, vectB);
	sort(vectA.begin(), vectA.end());
	sort(vectB.begin(), vectB.end());

	unordered_map<int, int> map;
	for (int i = 0; i < vectA.size(); i++)
	{
		auto iter = map.find(vectA[i]);
		if (iter != map.end())
		{
			result += iter->second;
			continue;
		}
		auto low = lower_bound(vectB.begin(), vectB.end(), T - vectA[i]);
		auto high = upper_bound(vectB.begin(), vectB.end(), T - vectA[i]);
		int cnt = high - low;
		map.insert(pair<int, int>(vectA[i], cnt));
		result += cnt;
	}
}
int main()
{
	scanf("%d", &T);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &B[i]);
	}
	Solution();
	printf("%lld", result);
	return 0;
}
