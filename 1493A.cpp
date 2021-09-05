#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> ans;
        for (int i = k + 1; i <= n; ++i)
            ans.push_back(i);
        for (int i = k/2; i <k; ++i)
        {
            if (i+i+1!=k)
            ans.push_back(i);
        }
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}