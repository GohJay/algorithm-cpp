#include <iostream>
#include <set>

int main()
{
	std::multiset<int> multiset;
	std::multiset<int>::iterator iter;
	int T, k;
	int n;
	char c;
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		multiset.clear();
		std::cin >> k;
		for (int j = 0; j < k; j++)
		{
			std::cin >> c >> n;
			switch (c)
			{
			case 'I':
				multiset.insert(n);
				break;
			case 'D':
				if (!multiset.empty())
				{
					iter = (n == 1) ? --multiset.end() : multiset.begin();
					multiset.erase(iter);
				}
				break;
			default:
				break;
			}
		}
		if (multiset.empty())
			std::cout << "EMPTY" << std::endl;
		else
			std::cout << *--multiset.end() << " " << *multiset.begin() << std::endl;
	}
	return 0;
}
