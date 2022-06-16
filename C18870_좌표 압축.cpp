#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> org;
	std::vector<int> tmp;
	std::vector<int>::iterator iter;
	int N;
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		std::cin >> x;
		org.push_back(x);
		tmp.push_back(x);
	}
	std::sort(tmp.begin(), tmp.end());
	iter = std::unique(tmp.begin(), tmp.end());
	for (int i = 0; i < N; i++)
	{
		std::cout << std::lower_bound(tmp.begin(), iter, org[i]) - tmp.begin() << " ";
	}
	return 0;
}
