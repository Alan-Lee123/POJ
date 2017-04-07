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

struct point
{
	int h, s, id, cnt, boss;
	point() {}
	point(int id, int h, int s) : id(id), h(h), s(s), cnt(1) {}
	bool operator < (const point& p) const
	{
		return s < p.s;
	}
};

point ps[31000];
point idx[1000000];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int m, q;
		scanf("%d%d", &m, &q);
		for (int i = 0; i < m; ++i)
		{
			int h, s, id;
			scanf("%d%d%d", &id, &s, &h);
			ps[i] = point(id, h, s);
		}
		ps[m] = point(0, 3000000, 20000000);
		++m;
		sort(ps, ps + m);
		stack<point> st;
		for (int i = 0; i < m; ++i)
		{
			while (!st.empty() && st.top().h <= ps[i].h)
			{
				ps[i].cnt += st.top().cnt;
				idx[st.top().id].boss = ps[i].id;
				st.pop();
			}
			idx[ps[i].id] = ps[i];
			st.push(ps[i]);
		}
		for (int i = 0; i < q; ++i)
		{
			int id;
			scanf("%d", &id);
			point t = idx[id];
			printf("%d %d\n", t.boss, t.cnt - 1);
		}
	}
	return 0;
}