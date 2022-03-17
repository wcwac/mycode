#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    m-=2;
    puts(((n >> m) & 1) ? "NO" : "YES");
}