#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

struct point
{
	int x, y;
	point(){}
	point(int xx, int yy) :x(xx), y(yy){}
	bool operator <(const point& p) const
	{
		if (x != p.x)
			return x < p.x;
		else
			return y < p.y;
	}
};

vector<point> ps;

int solution()
{
	sort(ps.begin(), ps.end());
	int n = ps.size();
	int cnt = 1;
	int y = ps[n - 1].y;
	for (int i = n - 2; i >= 0; --i)
	{
		if (ps[i].y > y)
		{
			cnt += 1;
			y = ps[i].y;
		}
	}
	return cnt;
}

int main()
{
	int n;
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		ps = vector<point>(n, point());
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &ps[i].x, &ps[i].y);
		int cnt = solution();
		printf("%d\n", cnt);
	}
	return 0;
}