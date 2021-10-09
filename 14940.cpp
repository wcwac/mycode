#include <iostream>
using namespace std;

int checkk(string str)
{
	int now = 0;
	for (auto i : str)
	{
		if (i == '(')
			++now;
		if (i == ')')
			--now;
		if (now < 0)
			return 0;
	}
	return now == 0;
}

int check(string str)
{
	for (int i = 1; i <= 2; ++i)
	{
		for (int j = 1; j <= 2; ++j)
		{
			for (int k = 1; k <= 2; ++k)
			{
				string tmp;
				for (auto t : str)
				{
					if (t == 'A')
						tmp += (i == 1) ? '(' : ')';
					if (t == 'B')
						tmp += (j == 1) ? '(' : ')';
					if (t == 'C')
						tmp += (k == 1) ? '(' : ')';
				}
				if (checkk(tmp))
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		puts(check(str) ? "YES" : "NO");
	}

	return 0;
}