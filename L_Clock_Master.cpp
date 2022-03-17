#include <bits/stdc++.h>
using namespace std;
long double a[50000], f[50000];
bool flag[50000];
vector<int> prime;

void pre()
{
    for (int i = 2; i <= 30000; ++i)
    {
        if (!flag[i])
            prime.push_back(i);
        for (auto j : prime)
        {
            int k = i * j;
            if (k > 30000)
                break;
            flag[k] = true;
            if (i % j == 0)
                break;
        }
    }
}

int main()
{
    pre();
    cin.tie(0)->sync_with_stdio(false);
    for (int i = 1; i <= 30000; ++i)
    {
        a[i] = log(1.0l * i);
    }
    for (auto i : prime)
    {
        for (int j = 30000; j >= 0; --j)
        {
            for (int k = i; k <= 30000; k *= i)
            {
                if (j - k >= 0)
                    f[j] = max(f[j], f[j - k] + a[k]);
            }
        }
    }
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << fixed << setprecision(9) << f[n] << endl;
    }

    return 0;
}