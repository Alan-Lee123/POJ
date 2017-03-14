#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

class point
{
public:
	int x, y;
	point() :x(0), y(0) {}
	point(int xx, int yy) :x(xx), y(yy) {};
	bool operator <(const point& p) const
	{
		return (x * 1000 + y) < (p.x * 1000 + p.y);
	}
};

int main()
{
	int n, i, j;
	while (scanf("%d", &n) && n)
	{
		vector<point> p(n, point());
		map<point, int> mp;
		int cnt = 0;
		for (i = 0; i < n; ++i)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			mp[p[i]] = i;
		}
		for (i = 0; i < n; ++i)
		{
			for (j = i + 1; j < n; ++j)
			{
				point t1(p[i].x + p[j].x + p[j].y - p[i].y, p[i].y + p[j].y - p[j].x + p[i].x);
				point t2(p[i].x + p[j].x  + p[i].y - p[j].y, p[i].y + p[j].y - p[i].x + p[j].x);
				if (t1.x % 2 || t1.y % 2 || t2.x % 2 || t2.y % 2)
					continue;
				else
				{
					t1.x /= 2, t2.x /= 2, t1.y /= 2, t2.y /= 2;
				}
				if (mp.count(t1) && mp.count(t2))
				{
					++cnt;
				}
			}
		}
		printf("%d\n", cnt/2);
	}
	return 0;
}