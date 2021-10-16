#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    if (n >= 17 && m >= 30)
        return printf("11"), 0;
    if (n >= 15 && m >= 27)
        return printf("10"), 0;
    if (n >= 11 && m >= 30)
        return printf("9"), 0;
    if (n >= 13 && m >= 24)
        return printf("9"), 0;
    if (n >= 8 && m >= 30)
        return printf("8"), 0;
    if (n >= 9 && m >= 26)
        return printf("8"), 0;
    if (n >= 11 && m >= 21)
        return printf("8"), 0;
    if (n >= 15 && m >= 15)
        return printf("8"), 0;
    if (n >= 7 && m >= 22)
        return printf("7"), 0;
    if (n >= 9 && m >= 18)
        return printf("7"), 0;
    if (n >= 11 && m >= 13)
        return printf("7"), 0;
    if (n >= 6 && m >= 18)
        return printf("6"), 0;
    if (n >= 7 && m >= 15)
        return printf("6"), 0;
    if (n >= 9 && m >= 11)
        return printf("6"), 0;
    if (n >= 5 && m >= 12)
        return printf("5"), 0;
    if (n >= 7 && m >= 9)
        return printf("5"), 0;
    if (n >= 4 && m >= 9)
        return printf("4"), 0;
    if (n >= 5 && m >= 7)
        return printf("4"), 0;
    if (n >= 3 && m >= 5)
        return printf("3"), 0;
    if (n >= 2 && m >= 3)
        return printf("2"), 0;
    if (n >= 1 && m >= 1)
        return printf("1"), 0;
    printf("0");

    return 0;
}