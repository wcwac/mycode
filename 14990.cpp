#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, k1, k2, a, b;
		cin >> n >> k1 >> k2 >> a >> b;
		int aa = (k1 / 2) + (k2 / 2) + ((k1 % 2 == 1) && (k2 % 2 == 1));
		k1 = n - k1;
		k2 = n - k2;
		int bb = (k1 / 2) + (k2 / 2) + ((k1 % 2 == 1) && (k2 % 2 == 1));
		if (aa >= a && bb >= b)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}