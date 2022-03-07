#include <iostream>
#include <string>
int main()
{
	std::string a, b;	
	std::cin >> a;
	std::cin >> b;
	int alen = a.length();
	int blen = b.length();
	int result = alen;
	for (int i = 0; i <= (blen - alen); i++)
	{
		int cnt = 0;
		std::string str = b.substr(i, alen);
		for (int j = 0; j < alen; j++)
		{			
			if (str[j] != a[j]) cnt++;
		}
		if (result > cnt) result = cnt;
	}
	std::cout << result << std::endl;
    return 0;
}