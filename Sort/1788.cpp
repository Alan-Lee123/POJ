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
	int cnt = 0;
	bool cool = false;
	for (int i = 0; i < n - 1; ++i)
	{
		if (ps[i].x == ps[i + 1].x)
		{
			if (cool)
				cool = false;
			else
			{
				cnt += ps[i + 1].y - ps[i].y;
				cool = true;
			}
		}
		else
			cool = false;
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
		for (int i = 0; i < n; ++i)
			swap(ps[i].x, ps[i].y);
		cnt += solution();
		printf("The length of the fence will be %d units.\n", cnt);
	}
	return 0;
}