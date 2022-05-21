#include <stdio.h>
#include <queue>

int main()
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            if (!queue.empty())
            {
                int top = queue.top();
                queue.pop();
                printf("%d\n", top);
            }
            else
            {
                printf("%d\n", 0);
            }
        }
        else
        {
            queue.push(x);
        }
    }
    return 0;
}