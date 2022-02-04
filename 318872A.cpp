#include <iostream>
using namespace std;
const int N = 110;
int f[1050][N][N];
char vis[N][N][N];
int n, m, E[N], D[N], S[N];

int dfs(int i, int j, int k, int now)
{
	if (j > m)
		return now;
	if (vis[i][j][k])
		return f[i][j][k];
	vis[i][j][k] = 1;
	if (D[j] <= k)//做当前题目
		f[i][j][k] = max(f[i][j][k], dfs(i, j + 1, k - D[j], now + S[j]));
	f[i][j][k] = max(f[i][j][k], dfs(i, j + 1, k, now));
	for (int tmp = 0; tmp < n; ++i) {
		if (((1 << tmp) & i) == 0) {
			f[i][j][k] = max(f[i][j][k], dfs(i | (1 << tmp), j, E[tmp], now));
		}
	}
	return f[i][j][k];
	/*
	for (int tmp = j; tmp <= m; ++tmp)
	{
		if (D[tmp] <= k)
			f[i][j][k] = max(f[i][j][k], dfs(i, tmp + 1, k - D[tmp], now + S[tmp]));
	}
	return f[i][j][k] = max(f[i][j][k], dfs(i + 1, j, E[i + 1], now));*/
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> E[i];
	for (int i = 1; i <= m; ++i)
		cin >> D[i];
	for (int i = 1; i <= m; ++i)
		cin >> S[i];
	cout << dfs(1, 1, E[1], 0) << endl;
}