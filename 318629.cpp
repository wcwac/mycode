#include <bits/stdc++.h>
using namespace std;
struct NODE
{
    long double score;
    double S, A, B, C, id;
    void cal()
    {
        double K = 3000000.0l / S;

        S *= K;
        A = A * K;
        B = B * K;
        C = C * K;
        for (double l = 0; l <= S; ++l)
        {
            double r = min(l + B, S);
            if (A >= l)
            {
                double len = (r - l);
                score += (len + min(C, l)) * min(A, l);
                score += len * len / 2 + min(C, l) * len;
            }
        }
        swap(B, C); //ACB
        for (double l = 0; l <= S; ++l)
        {
            double r = min(l + B, S);
            if (A >= l)
            {
                double len = (r - l);
                score += (len + min(C, l)) * min(A, l);
                score += len * len / 2 + min(C, l) * len;
            }
        }
        swap(A, C); //BCA
        for (double l = 0; l <= S; ++l)
        {
            double r = min(l + B, S);
            if (A >= l)
            {
                double len = (r - l);
                score += (len + min(C, l)) * min(A, l);
                score += len * len / 2 + min(C, l) * len;
            }
        }
        swap(B, C); //BAC
        for (double l = 0; l <= S; ++l)
        {
            double r = min(l + B, S);
            if (A >= l)
            {
                double len = (r - l);
                score += (len + min(C, l)) * min(A, l);
                score += len * len / 2 + min(C, l) * len;
            }
        }
        swap(A, C); //CAB
        for (double l = 0; l <= S; ++l)
        {
            double r = min(l + B, S);
            if (A >= l)
            {
                double len = (r - l);
                score += (len + min(C, l)) * min(A, l);
                score += len * len / 2 + min(C, l) * len;
            }
        }
        swap(B, C); //CBA
        for (double l = 0; l <= S; ++l)
        {
            double r = min(l + B, S);
            if (A >= l)
            {
                double len = (r - l);
                score += (len + min(C, l)) * min(A, l);
                score += len * len / 2 + min(C, l) * len;
            }
        }
    }
} s[20];

bool cmp(const NODE &a, const NODE &b)
{
    return a.score < b.score;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i].S >> s[i].A >> s[i].B >> s[i].C;
        s[i].id = i + 1;
        s[i].cal();
    }
    stable_sort(s, s + n, cmp);
    for (int i = 0; i < n; ++i)
    {
        cout << s[i].id << " ";
    }
    return 0;
}