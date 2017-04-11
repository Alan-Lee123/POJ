#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

struct point
{
	int x, p;
};

struct edge
{
	int from, to, cost;
	bool operator <(const edge& e) const
	{
		return cost < e.cost;
	}
};

point ps[110];
edge es[10100];

int iparent(int x)
{
	return ps[x].p == 0 ? x : (ps[x].p = iparent(ps[x].p));
}

int main()
{
	int N;
	scanf("%d", &N);
	int num = 0;
	for (int i = 0; i < N; ++i)
	{
		ps[i + 1].x = i + 1;
		ps[i + 1].p = 0;
		for (int j = 0; j < N; ++j)
		{
			int len;
			scanf("%d", &len);
			if (i < j)
			{
				es[num].from = i + 1;
				es[num].to = j + 1;
				es[num].cost = len;
				++num;
			}
		}
	}
	int Q;
	scanf("%d", &Q);
	int cnt = 0;
	for (int i = 0; i < Q; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x = iparent(x);
		y = iparent(y);
		if (x != y)
		{
			ps[x].p = y;
			++cnt;
		}
			
	}
	sort(es, es + num);
	int tot = 0;
	for (int i = 0; i < num && cnt < N - 1; ++i)
	{
		int x = iparent(es[i].from), y = iparent(es[i].to);
		if (x != y)
		{
			tot += es[i].cost;
			ps[x].p = y;
			++cnt;
		}
	}
	printf("%d\n", tot);
	return 0;
}