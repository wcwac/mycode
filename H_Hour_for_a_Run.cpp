#include <bits/stdc++.h>
using namespace std;
int count(unsigned long long t)
{
    int cnt = 0;
    while (t)
    {
        t -= -t & t;
        ++cnt;
    }
    return cnt;
}
int main()
{
    unsigned long long n;
    cin >> n;
    printf("%.0f\n", pow(2.0, count(n)));
}