#include <stdio.h>
#include <string.h>

int main()
{
	char str[6];
	for (;;)
	{
		scanf("%s", &str);
		if (strcmp(str, "0") == 0) break;
		int find = 1;
		for (int i = 0; i < strlen(str) / 2; i++)
		{
			if (str[i] != str[strlen(str) -1 - i])
			{
				find = 0;
				printf("%s\n", "no");
				break;
			}
		}
		if (find) printf("%s\n", "yes");
	}
}
