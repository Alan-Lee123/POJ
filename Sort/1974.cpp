#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct point
{
	int x, y;
	bool operator <(const point& p) const
	{
		if (x != p.x)
			return x < p.x;
		else
			return y < p.y;
	}
};

vector<point> ps;

int solution(int m, int n)
{
	int k = ps.size();
	int cnt = 0;
	if (n < 2)
		return 0;
	if (k == 0)
		return m;
	cnt += ps[0].x - 1;
	if (ps[0].y - 1 >= 2)
		++cnt;
	for (int i = 1; i < k; ++i)
	{
		if (ps[i].x != ps[i - 1].x)
		{
			cnt += ps[i].x - ps[i - 1].x - 1;
			if (n - ps[i - 1].y >= 2)
				++cnt;
			if (ps[i].y - 1 >= 2)
				++cnt;
		}
		else
		{
			if (ps[i].y - ps[i - 1].y - 1 >= 2)
				++cnt;
		}
	}
	cnt += m - ps[k - 1].x;
	if (n - ps[k - 1].y >= 2)
		++cnt;
	return cnt;
}

int main()
{
	int kase;
	scanf("%d", &kase);
	while (kase-- > 0)
	{
		int m, n, k;
		scanf("%d%d%d", &m, &n, &k);
		ps = vector<point>(k, point());
		for (int i = 0; i < k; ++i)
			scanf("%d%d", &ps[i].x, &ps[i].y);
		sort(ps.begin(), ps.end());
		int row = solution(m, n);
		for (int i = 0; i < k; ++i)
			swap(ps[i].x, ps[i].y);
		sort(ps.begin(), ps.end());
		int col = solution(n, m);
		int cnt = row + col;
		printf("%d\n", cnt);
	}
	return 0;
}