#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int main()
{
    int _;
    scanf("%d", &_);
    while (_--)
    {
        long long n;
        scanf("%lld", &n);
        if (n <= 1)
            printf("0\n");
        else
        {
            n = (n - 1) % P;
            printf("%d\n", n * n % P * (n + 1) % P * (n + 1) % P * 2 % P);
        }
    }

    return 0;
}