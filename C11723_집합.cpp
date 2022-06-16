#include <stdio.h>
#include <string.h>

int main()
{
	int arr[21] = { 0, };
	int M;
	int x;
	char str[7];
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%s", str);
		if (strcmp(str, "all") == 0)
		{
			for (int j = 1; j <= 20; j++)
			{
				arr[j] = 1;
			}
			continue;
		}
		else if (strcmp(str, "empty") == 0)
		{
			memset(arr, 0, sizeof(arr));
			continue;
		}

		scanf("%d", &x);
		if (strcmp(str, "add") == 0)
		{
			arr[x] = 1;
		}
		else if (strcmp(str, "remove") == 0)
		{
			arr[x] = 0;
		}
		else if (strcmp(str, "check") == 0)
		{
			if (arr[x] == 1)
				printf("%d\n", 1);
			else
				printf("%d\n", 0);
		}
		else if (strcmp(str, "toggle") == 0)
		{
			arr[x] = !arr[x];
		}
	}	
	return 0;
}
