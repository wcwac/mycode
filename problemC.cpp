#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> q;
void dfs(string s, int flag)
{
    for (int i = 0, now = 1; i < s.length(); ++i)
    {
        if (s[i] == ')')
            continue;
        if (s[i] == '(')
        {
            string tmp;
            int deep = 1;
            ++i;
            while (deep - (s[i] == ')'))
            {
                if (s[i] == '(')
                    ++deep;
                if (s[i] == ')')
                    --deep;
                tmp += s[i];
                ++i;
            }
            if (now == -1)
                dfs(tmp, -flag), now = 1;
            else
                dfs(tmp, flag);
            continue;
        }
        if (s[i] == '*' || s[i] == '/')
        {
            if (s[i] == '/')
                now = -1;
        }
        else
        {
            string tmp;
            tmp += s[i];
            while (i + 1 < s.length() && ((s[i + 1] >= 'a' && s[i + 1] <= 'z') || (s[i + 1] >= 'A' && s[i + 1] <= 'Z')))
            {
                ++i;
                tmp += s[i];
            }
            if (now == -1)
            {
                q[tmp] -= flag;
                now = 1;
            }
            else
                q[tmp] += flag;
        }
    }
}

int tt[200];
char ch[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
bool cmp(string a, string b)
{
    for (int i = 0; i < a.length(); ++i)
        a[i] = tt[a[i]];
    for (int i = 0; i < b.length(); ++i)
        b[i] = tt[b[i]];
    return a < b;
}
vector<string> a, b;

int main()
{
    for (int i = 0; i < 52; ++i)
    {
        tt[ch[i]] = i;
    }
    string s;
    cin >> s;
    dfs(s, 1);
    for (auto i : q)
    {
        if (i.second > 0)
            for (int j = 1; j <= i.second; ++j)
                a.push_back(i.first);
        // cout << i.first << "*";
    }
    // puts("");
    for (auto i : q)
    {
        if (i.second < 0)
            for (int j = 1; j <= abs(i.second); ++j)
                b.push_back(i.first);
        // cout << i.first << "*";
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    if (a.empty())
    {
        cout << "1\n";
    }
    else
    {
        for (int i = 0; i < a.size(); ++i)
        {
            cout << a[i] << ((i == a.size() - 1) ? "\n" : "*");
        }
    }
    if (b.empty())
    {
        cout << "1\n";
    }
    else
    {

        for (int i = 0; i < b.size(); ++i)
        {
            cout << b[i] << ((i == b.size() - 1) ? "\n" : "*");
        }
    }
}