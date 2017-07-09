#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

static inline bool fequal(double x, double y)
{
	if (abs(x - y) / (abs(x) + abs(y)) < 1e-6)
		return true;
	else
		return false;
}

struct line
{
	double x, y;
	bool operator <(const line& l) const
	{
		if (fequal(y, l.y))
			return x < l.x;
		return y < l.y;
	}
};

line ls[1010];

int main()
{
	for(int T = 1; ; ++T)
	{
		int n, d;
		scanf("%d%d", &n, &d);
		if (n == 0 && d == 0)
			break;
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (!flag)
				continue;
			if (y > d)
			{
				flag = false;
				continue;
			}
			ls[i].x = x - sqrt(1. * d * d - y * y);
			ls[i].y = x + sqrt(1. * d * d - y * y);
		}
		if (!flag)
		{
			printf("Case %d: %d\n", T, -1);
			continue;
		}

		sort(ls, ls + n);
		double cur = ls[0].x - 1 - abs(ls[0].x);
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			if (cur > ls[i].x || fequal(cur, ls[i].x))
				continue;
			cnt += 1;
			cur = ls[i].y;
		}
		printf("Case %d: %d\n", T, cnt);
	}
	return 0;
}