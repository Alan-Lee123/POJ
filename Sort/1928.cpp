#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

struct point
{
	int x, y, v;
	point(){}
	point(int xx, int yy, int vv) :x(xx), y(yy), v(vv){}
	bool operator <(const point& p) const
	{
		return v > p.v;
	}
};

vector<point> ps;

int main()
{
	int T;
	scanf("%d", &T);
	for (; T > 0; --T)
	{
		int M, N, K;
		scanf("%d%d%d", &M, &N, &K);
		ps = vector<point>();
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int v;
				scanf("%d", &v);
				if (v != 0)
					ps.push_back(point(i + 1, j, v));
			}
		}
		sort(ps.begin(), ps.end());
		if (ps.size() == 0)
		{
			printf("0\n");
			continue;
		}
		int x = 0, y = ps[0].y;
		int cnt = 0, step = 0;
		for (int i = 0; i < ps.size(); ++i)
		{
			step += abs(ps[i].x - x) + abs(ps[i].y - y) + 1;
			if (step + ps[i].x > K)
				break;
			cnt += ps[i].v;
			x = ps[i].x, y = ps[i].y;
		}
		printf("%d\n", cnt);
	}
	return 0;
}