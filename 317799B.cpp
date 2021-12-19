#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> ans;
    for (int i = 1; i <= n; ++i)
    {
        int flag = 1;
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[j] - a[j - 1] != a[j - i] - a[j - i - 1])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    return 0;
}