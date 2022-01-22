#include <bits/stdc++.h>
using namespace std;
long long ans = 1;
map<int, int> v;
int a[] = {2, 3, 5, 7, 11, 13, 17, 19};
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (n == 1)
            break;
        while (n != 1 && n % i == 0)
        {
            ++v[i];
            n /= i;
        }
    }
    int now=1;
    for (auto i:v){
        if (i.second){

        }
    }
    return 0;
}