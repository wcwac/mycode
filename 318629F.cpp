#include <bits/stdc++.h>
using namespace std;

int isflag(string str)
{
    if (str == "+")
        return 1;
    if (str == "-")
        return 1;
    if (str == "*")
        return 1;
    if (str == "/")
        return 1;
    if (str == "%")
        return 1;
    return 0;
}

int check1(string str)
{
    int flag = 1;
    stack<string> stk;
    for (int i = 0; i < str.size(); ++i)

    {
        char now = str[i];
        if (now == ' ')
            continue;
        if (now == '(')
        {
            stk.push(now + "");
        }
        else if (now == ')')
        {
            int cnt = 0;
            string r;
            while (!stk.empty() && stk.top() != "(")
            {
                if ((cnt & 1) != isflag(stk.top()))
                    return 0;
                r = stk.top() + r;
                ++cnt;
                stk.pop();
            }
            if ((cnt & 1) == 0)
                return 0;
            if (cnt != 3)
                flag = 0;
            if (stk.empty())
                return 0;
            stk.pop();
            r = "(" + r + ")";
            stk.push(r);
        }
        else if (now >= 'a' && now <= 'z')
        {
            stk.push(now + "");
        }
        else if (now == '+' || now == '-' || now == '*' || now == '/' || now == '%')
        {
            if (stk.size() < 1)
                return 0;
        }
        else
        {
            return 0;
        }
    }
    if (!stk.empty())
        return 0;
    return flag + 1;
}

int main()
{
    int flag = 0;
    string str;
    getline(cin, str);
    int ans = check1("(" + str + ")");
    if (ans == 1)
    {
        puts("improper");
    }
    else if (ans == 2)
    {
        puts("proper");
    }
    else
    {
        puts("error");
    }
    return 0;
}