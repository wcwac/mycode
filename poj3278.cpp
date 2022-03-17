//poj3278
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
int f[100010];
int main()
{
    cin >> n >> m;
    f[n] = 1;
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x - 1 >= 0 && f[x - 1] == 0)
        {
            f[x - 1] = f[x] + 1;
            q.push(x - 1);
        }
        if (x + 1 < 100010 && f[x + 1] == 0)
        {
            f[x + 1] = f[x] + 1;
            q.push(x + 1);
        }
        if (x < m && x * 2 < 100010 && f[x * 2] == 0)
        {
            f[x * 2] = f[x] + 1;
            q.push(x * 2);
        }
        if (f[m] != 0)
            break;
    }
    cout << f[m] - 1 << endl;
}