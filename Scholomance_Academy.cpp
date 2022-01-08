#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    typedef pair<int, string> pis;
    vector<pis> v(n);
    int cnta = 0, cntb = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].second >> v[i].first;
        if (v[i].second[0] == '+')
            ++cnta;
        else
            ++cntb;
    }
    sort(v.begin(), v.end());
    double ans = 0;
    int fn = 0, tn = 0;
    double ltpr = 1, lfpr = 1;
    for (int i = 0; i < n; ++i)
    {
        if (v[i].second[0] == '+')
            ++fn;
        else
            ++tn;
        int tp = cnta - fn;
        int fp = cntb - tn;
        double tpr = 1.0l * tp / (tp + fn);
        double fpr = 1.0l * fp / (tn + fp);
        // cout << tpr << " " << fpr << endl;
        // a[i] = 1.0l * (i + 1 - cntb1) / (i + 1);
        // cout << i << "," << a[i] << endl;
        ans += ltpr * (lfpr - fpr);
        // cout << ltpr * (lfpr - fpr) << endl;
        ltpr = tpr;
        lfpr = fpr;
    }
    printf("%.15f\n", ans);
    return 0;
}