#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

struct line
{
	int s, d, l, cost;
	line() {}
	line(int s, int d, int l, int c) : s(s), d(d), l(l), cost(c) {}
};

struct point
{
	int len, cost, p;
	point() {}
	point(int l, int c, int p) : len(l), cost(c), p(p) {}
	bool operator <(const point& y) const
	{
		return len > y.len;
	}
};

int K, N, R;
vector<line> ls[101];
priority_queue<point> pq;

int main()
{
	scanf("%d%d%d", &K, &N, &R);
	for (int i = 0; i < R; ++i)
	{
		int s, d, l, r;
		scanf("%d%d%d%d", &s, &d, &l, &r);
		ls[s].push_back(line(s, d, l, r));
	}
	pq.push(point(0, 0, 1));
	int ans = 0x7FFFFFFF;
	while (!pq.empty())
	{
		point p = pq.top();
		pq.pop();
		if (p.cost > K)
			continue;
		if (p.p == N)
		{
			if (p.len < ans)
			{
				ans = p.len;
				break;
			}
			continue;
		}
		for (int i = 0, l = ls[p.p].size(); i < l; ++i)
		{
			pq.push(point(p.len + ls[p.p][i].l, p.cost + ls[p.p][i].cost, ls[p.p][i].d));
		}
	}
	if(ans == 0x7FFFFFFF)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}