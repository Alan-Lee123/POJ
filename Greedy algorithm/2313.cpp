#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

using namespace std;

int as[110];
int bs[110];

int imid(int x, int y, int z)
{
	if ((x - y) * (x - z) <= 0)
		return x;
	if ((y - x) * (y - z) <= 0)
		return y;
	return z;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &as[i]);
	bs[0] = as[0], bs[n - 1] = as[n - 1];
	for (int i = 1; i < n - 1; ++i)
		bs[i] = imid(bs[i - 1], as[i], as[i + 1]);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans += abs(as[i] - bs[i]);
	for (int i = 0; i < n - 1; ++i)
		ans += abs(bs[i + 1] - bs[i]);
	printf("%d\n", ans);
	return 0;
}