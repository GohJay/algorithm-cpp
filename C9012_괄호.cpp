#include <stdio.h>

int main()
{
	int N;
	char str[50];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		int cnt = 0;
		for (int j = 0; ; j++)
		{
			if (str[j] == '\0')
				break;
			else if (str[j] == '(')
				cnt++;
			else if (str[j] == ')')
				cnt--;
		}
		printf("%s\n", cnt == 0 ? "YES" : "NO");
	}
	return 0;
}
