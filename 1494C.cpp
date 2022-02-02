#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int N = 2e5 + 10;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		vector<int> la, ra, lb, rb;
		map<int, int> lq, rq;
		int lcnt = 0, rcnt = 0;
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			int x;
			cin >> x;
			if (x > 0)
				ra.push_back(x), rq[x] = 1;
			else
				la.push_back(-x), lq[-x] = 1;
		}
		for (int i = 1; i <= m; ++i)
		{
			int x;
			cin >> x;
			if (x > 0)
			{
				rcnt += rq[x];
				rq[x] = 0;
				rb.push_back(x);
			}
			else
			{
				lcnt += lq[-x];
				lq[-x] = 0;
				lb.push_back(-x);
			}
		}
		sort(la.begin(), la.end());
		sort(ra.begin(), ra.end());
		sort(lb.begin(), lb.end());
		sort(rb.begin(), rb.end());
		int l = 0, r = -1, now = 0, lmax = lcnt, nowcnt = lcnt;
		for (l = 0; l < lb.size(); ++l)
		{
			while (now < la.size() && la[now] <= lb[l] + now)
			{
				if (!lq[la[now]])
					--nowcnt;
				++now;
			}
			while (r + 1 < lb.size() && lb[r + 1] < lb[l] + now)
			{
				++r;
				++nowcnt;
			}
			//cout << "l:" << la[l] << "r:" << lb[r] << endl;
			lmax = max(lmax, nowcnt);
			--nowcnt;
		}
		int rmax = rcnt;
		l = 0, r = -1, now = 0, nowcnt = rcnt;
		for (l = 0; l < rb.size(); ++l)
		{
			while (now < ra.size() && ra[now] <= rb[l] + now)
			{
				if (!rq[ra[now]])
					--nowcnt;
				++now;
			}
			while (r + 1 < rb.size() && rb[r + 1] < rb[l] + now)
			{
				++r;
				++nowcnt;
			}
			//cout << "l:" << la[l] << "r:" << lb[r] << endl;
			rmax = max(rmax, nowcnt);
			--nowcnt;
		}
		cout << lmax + rmax << endl;
	}

	return 0;
}