#include <iostream>
#include <map>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        if (n & 1)
        {
            printf("%d %d %d\n", 1, n / 2, n / 2);
        }
        else if ((n / 2) & 1)
        {
            printf("%d %d %d\n", 2, n / 2 - 1, n / 2 - 1);
        }
        else
        {
            printf("%d %d %d\n", n / 4, n / 4, n / 2);
        }
    }
    return 0;
}