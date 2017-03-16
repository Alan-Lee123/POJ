#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

struct point
{
	int x, y;
	point(){}
	point(int xx, int yy) :x(xx), y(yy){}
	bool operator <(const point& p) const
	{
		return x + y > p.x + p.y;
	}
};

vector<point> ps;
vector<int> accum;

void solution(int cur, int cx, int cy, int& ret)
{
	if (cx + cy + accum[cur] <= ret)
		return;
	if (cx >= 0 && cy >= 0 && cx + cy > ret)
		ret = cx + cy;
	if (cur == ps.size())
		return;
	solution(cur + 1, cx + ps[cur].x, cy + ps[cur].y, ret);
	solution(cur + 1, cx, cy, ret);
}

int main()
{
	int n;
	scanf("%d", &n);
	ps = vector<point>();
	int x, y;
	int sx = 0, sy = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &x, &y);
		if (x >= 0 && y >= 0)
		{
			sx += x;
			sy += y;
		}
		else if (x > 0 || y > 0)
			ps.push_back(point(x, y));
	}
	n = ps.size();
	sort(ps.begin(), ps.end());
	accum = vector<int>(n + 1, 0);
	for (int i = n - 1; i >= 0; --i)
	{
		int t = ps[i].x + ps[i].y;
		if (t < 0)
			accum[i] = accum[i + 1];
		else
			accum[i] = accum[i + 1] + t;
	}
	int ans = sx + sy;
	solution(0, sx, sy, ans);
	printf("%d\n", ans);
	return 0;
}