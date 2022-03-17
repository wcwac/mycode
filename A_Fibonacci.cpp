#include <iostream>
using namespace std;

struct node
{
    int a, b, c;
};
node mul(const node &a, const node &b)
{
    node ans;
    ans.a = (a.a * b.a + a.b * b.b) % 10000;
    ans.b = (a.b * b.a + a.c * b.b) % 10000;
    ans.c = (a.b * b.b + a.c * b.c) % 10000;
    return ans;
}

int f(int n)
{
    if (n <= 0)
        return 0;
    --n;
    node a = {1, 1, 0}, b = {1, 0, 1};
    while (n)
    {
        if (n & 1)
            b = mul(b, a);
        a = mul(a, a);
        n >>= 1;
    }
    return b.a;
}

int main()
{
    int n;
    cin >> n;
    while (n != -1)
    {
        cout << f(n) << endl;
        cin >> n;
    }
}