#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a, b;
        double sum = 0;
        for (int i = 1; i <= n + n; ++i)
        {
            int x, y;
            cin >> x >> y;
            if (!x)
                b.push_back(abs(y));
            else
                a.push_back(abs(x));
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < a.size() && i < b.size(); ++i)
        {
            sum += sqrt(1.0l * a[i] * a[i] + 1.0l * b[i] * b[i]);
        }
        printf("%.15f\n", sum);
    }

    return 0;
}