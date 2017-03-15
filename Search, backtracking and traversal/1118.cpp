#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int gcd(int x, int y)
{
	if (x == 0)
		return y;
	else
		return gcd(y % x, x);
}

struct fraction
{
	int x, y;
	fraction(){}
	fraction(int xx, int yy)
	{
		int g = gcd(xx, yy);
		x = xx / g;
		y = yy / g;
	}
	bool operator <(const fraction& f) const
	{
		return x * f.y < y * f.x;
	}
	bool operator !=(const fraction& f) const
	{
		return x * f.y != y * f.x;
	}
};

struct line
{
	fraction k, b;
	bool operator <(const line& l) const
	{
		if (k != l.k)
			return k < l.k;
		else
			return b < l.b;
	}
	bool operator !=(const line& l) const
	{
		return k != l.k || b != l.b;
	}
};

int main()
{
	int n;
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		vector<int> x(n, 0), y(n, 0);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &x[i], &y[i]);
		if (n == 1)
		{
			printf("1\n");
			continue;
		}
		vector<line> ls(n * (n - 1) / 2, line());
		int cur = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				ls[cur].k = fraction(y[i] - y[j], x[i] - x[j]);
				ls[cur].b = fraction(y[i] * ls[cur].k.y - x[i] * ls[cur].k.x, ls[cur].k.y);
				++cur;
			}
		}
		sort(ls.begin(), ls.end());
		int mx = 1, cnt = 1;
		for (int i = 1; i < cur + 1; ++i)
		{
			if (i == cur || ls[i] != ls[i - 1])
			{
				if (cnt > mx)
					mx = cnt;
				cnt = 1;
			}
			else
				++cnt;
		}
		int ret = (int)(1 + sqrt(1.0 + 8 * mx)) / 2;
		printf("%d\n", ret);

	}
	return 0;
}
