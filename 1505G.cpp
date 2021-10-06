#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e;
char cal()
{
    if (a == 1 && b == 0 && c == 0 && d == 1 && e == 0)
        return 'a';
    if (a == 1 && b == 1 && c == 0 && d == 2 && e == 0)
        return 'b';
    if (a == 2 && b == 0 && c == 0 && d == 1 && e == 1)
        return 'c';
    if (a == 2 && b == 1 && c == 0 && d == 1 && e == 2)
        return 'd';
    if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1)
        return 'e';
    if (a == 2 && b == 1 && c == 0 && d == 2 && e == 1)
        return 'f';
    if (a == 2 && b == 2 && c == 0 && d == 2 && e == 2)
        return 'g';
    if (a == 1 && b == 2 && c == 0 && d == 2 && e == 1)
        return 'h';
    if (a == 1 && b == 1 && c == 0 && d == 1 && e == 1)
        return 'i';
    if (a == 1 && b == 2 && c == 0 && d == 1 && e == 2)
        return 'j';
    if (a == 1 && b == 0 && c == 1 && d == 2 && e == 0)
        return 'k';
    if (a == 1 && b == 1 && c == 1 && d == 3 && e == 0)
        return 'l';
    if (a == 2 && b == 0 && c == 1 && d == 2 && e == 1)
        return 'm';
    if (a == 2 && b == 1 && c == 1 && d == 2 && e == 2)
        return 'n';
    if (a == 1 && b == 1 && c == 1 && d == 2 && e == 1)
        return 'o';
    if (a == 2 && b == 1 && c == 1 && d == 3 && e == 1)
        return 'p';
    if (a == 2 && b == 2 && c == 1 && d == 3 && e == 2)
        return 'q';
    if (a == 1 && b == 2 && c == 1 && d == 3 && e == 1)
        return 'r';
    if (a == 1 && b == 1 && c == 1 && d == 2 && e == 1)
        return 's';
    if (a == 1 && b == 2 && c == 1 && d == 2 && e == 2)
        return 't';
    if (a == 1 && b == 0 && c == 2 && d == 2 && e == 1)
        return 'u';
    if (a == 1 && b == 1 && c == 2 && d == 3 && e == 1)
        return 'v';
    if (a == 2 && b == 0 && c == 2 && d == 2 && e == 2)
        return 'x';
    if (a == 2 && b == 1 && c == 2 && d == 2 && e == 3)
        return 'y';
    if (a == 1 && b == 1 && c == 2 && d == 2 && e == 2)
        return 'z';
    if (a == 1 && b == 2 && c == 1 && d == 1 && e == 3)
        return 'w';
    return '0';
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c >> d >> e;
        cout << cal();
    }
}