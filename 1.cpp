#include <bits/stdc++.h>
using namespace std;
const int N = 10;
struct cmp
{
    bool operator()(const bitset<N> &a, const bitset<N> &b) const
    {
        return a.to_ulong() < b.to_ulong();
    }
};
map<bitset<N>, int, cmp> q;
int main()
{
    for (int i = 1; i <= 100; ++i)
    {
        bitset<N> a = i;
        cout << i << "   :" << a << endl;
        q[a] = i;
    }
    for (auto i : q)
    {
        cout << i.second << "   :" << i.first << endl;
    }
    return 0;
}