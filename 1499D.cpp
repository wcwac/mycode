#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e7 + 10;
#define int long long

signed _[N], tot, p[N];
bool v[N];

void pre()
{
	_[1] = 0;
	for (int i = 2; i < N; ++i)
	{
		if (!v[i])
			v[i] = 1, p[++tot] = i, _[i] = 1;
		for (int j = 1; j <= tot && i < N / p[j]; ++j)
		{
			v[p[j] * i] = 1;
			_[i * p[j]] = _[i];
			if (i % p[j] == 0)
				break;
			++_[i * p[j]];
		}
	}
}

int cal(int c, int t)
{
	if (t % c)
		return 0;
	int x = t / c;
	return static_cast<long long>(1) << _[x];
}

signed main()
{
	pre();
	int T;
	cin >> T;
	while (T--)
	{
		int c, d, x;
		cin >> c >> d >> x;
		int ans = 0;
		for (int i = 1; i * i <= x; ++i)
		{
			if (x % i)
				continue;
			ans += cal(c, i + d);
			if (i * i == x)
				continue;
			ans += cal(c, x / i + d);
		}
		cout << ans << endl;
	}

	return 0;
}