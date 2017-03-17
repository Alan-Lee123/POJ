#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

struct line
{
	int to;
	int color;
	line(int t, int c) : to(t), color(c) {}
};

struct point
{
	int x, y;
	int step;
	point() {}
	point(int xx, int yy, int s) : x(xx), y(yy), step(s) {}
};

int N, L, K, Q;
int colors[110];
vector<line> ls[110];
bool used[101][101];

void iuse(int x, int y)
{
	used[x][y] = true;
	used[y][x] = true;
}

bool iget(int x, int y)
{
	return used[x][y] || used[y][x];
}

int bfs()
{
	memset(used, 0, sizeof(used));
	queue<point> q;
	q.push(point(L, K, 0));
	if (L == Q || K == Q)
		return 0;
	iuse(L, K);
	point p;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		for (int i = 0, len = ls[p.x].size(); i < len; ++i)
		{
			if (ls[p.x][i].color == colors[p.y] && !iget(ls[p.x][i].to, p.y))
			{
				point t(ls[p.x][i].to, p.y, p.step + 1);
				if (t.x == t.y) continue;
				if (t.x == Q || t.y == Q) return t.step;
				q.push(t);
				iuse(t.x, t.y);
			}
		}
		for (int i = 0, len = ls[p.y].size(); i < len; ++i)
		{
			if (ls[p.y][i].color == colors[p.x] && !iget(ls[p.y][i].to, p.x))
			{
				point t(ls[p.y][i].to, p.x, p.step + 1);
				if (t.x == t.y) continue;
				if (t.x == Q || t.y == Q) return t.step;
				q.push(t);
				iuse(t.x, t.y);
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d%d%d%d", &N, &L, &K, &Q);
	for (int i = 0; i < N; ++i)
		scanf("%d", &colors[i + 1]);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		ls[x].push_back(line(y, c));
	}
	int ans = bfs();
	if (ans == -1)
		printf("NO\n");
	else
		printf("YES\n%d\n", ans);
	return 0;
}