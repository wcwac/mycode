#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
long long f[N];
vector<int> primes;
bool flag[N];
void init()
{
    flag[1] = 1;
    f[1] = -4;
    for (int i = 2; i < N; ++i)
    {
        if (flag[i])
            f[i] = f[i - 1] + i;
        else
        {
            f[i] = f[i - 1] + i * 2;
            primes.push_back(i);
        }
        for (auto j : primes)
        {
            long long t = j * i;
            if (t >= N)
                break;
            flag[t] = 1;
            if (j % i == 0)
                break;
        }
    }
}

int main()
{
    init();
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        cout << f[m] << endl;
    }
}