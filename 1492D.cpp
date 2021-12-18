#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    if (k == 0)
    {
        puts("Yes");
        for (int i = 1; i <= b; ++i)
            putchar('1');
        for (int i = 1; i <= a; ++i)
            putchar('0');
        puts("");
        for (int i = 1; i <= b; ++i)
            putchar('1');
        for (int i = 1; i <= a; ++i)
            putchar('0');
        return 0;
    }
    if (b == 1 || a == 0)
    {
        puts("No");
        return 0;
    }
    if (k > a + b - 2)
    {
        puts("No");
        return 0;
    }
    string sa, sb;

    --b;
    sa += '1';
    sb += '1';

    while (a + b - 1 > k)
    {
        if (b > 1)
        {
            --b;
            sa += '1';
            sb += '1';
        }
        else
        {
            --a;
            sa += '0';
            sb += '0';
        }
    }

    sa += '1';
    sb += '0';
    --b;
    --a;
    while (a)
    {
        --a;
        sa += '0';
        sb += '0';
    }
    while (b)
    {
        --b;
        sa += '1';
        sb += '1';
    }
    sa += '0';
    sb += '1';

    cout << "Yes\n"
         << sa << "\n"
         << sb;
    return 0;
}