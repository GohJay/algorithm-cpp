#include <stdio.h>

int factorial(int n)
{
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
int binomial(int n, int k)
{
    return factorial(n) / (factorial(n - k) * factorial(k));
}
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    printf("%d\n", binomial(N, K));
    return 0;
}
