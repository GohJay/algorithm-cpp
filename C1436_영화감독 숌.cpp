#include <stdio.h>
#include <string>

int main()
{
	int N;
	int cnt = 0;
	int result = 665;
	std::string str;
	scanf("%d", &N);
	for (;;)
	{
		str = std::to_string(result);
		if (str.find("666") != std::string::npos) cnt++;
		if (cnt == N) break;
		result++;
	}
	printf("%d\n", result);
	return 0;
}
