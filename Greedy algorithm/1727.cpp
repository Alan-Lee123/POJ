#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
	int x, y;
};

struct edge
{
	int l, r;
	bool operator <(const edge& e) const
	{
		return r < e.r;
	}
};

vector<edge> project(const vector<point>& points, int y)
{
	int n = points.size();
	vector<edge>edges = vector<edge>(n, edge());
	for (int i = 0; i < n; ++i)
	{
		edges[i].r = points[i].x + points[i].y - y;
		edges[i].l = points[i].x - points[i].y + y;
	}
	return edges;
}

int greedy(const vector<point>& points, int y)
{
	vector<edge> edges = project(points, y);
	sort(edges.begin(), edges.end());
	int cur = edges[0].r;
	int cnt = 1;
	int n = edges.size();
	for (int i = 1; i < n; ++i)
	{
		if (edges[i].l > cur)
		{
			cnt += 1;
			cur = edges[i].r;
		}
	}
	return cnt;
}

int my_search(int start, int end, const vector<point>&points, const int n)
{
	if (start >= end - 1)
		return start;
	int mid = (start + end) / 2;
	int r = greedy(points, mid);
	if (r <= n)
		return my_search(mid, end, points, n);
	else
		return my_search(start, mid, points, n);
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int kase = 1; kase < N + 1; ++kase)
	{
		int m, n;
		scanf("%d%d", &m, &n);
		vector<point> points(m, point());
		for (int i = 0; i < m; ++i)
			scanf("%d%d", &points[i].y, &points[i].x);
		int high = points[0].y;
		point l = points[0], r = points[0];
		for (int i = 0; i < m; ++i)
		{
			if (high > points[i].y)
				high = points[i].y;
			if (l.x + l.y > points[i].x + points[i].y)
				l = points[i];
			if (r.y - r.x > points[i].y - points[i].x)
				r = points[i];
		}
		int low = (l.y + r.y + l.x - r.x) / 2 - 1;
		int result = my_search(low, high + 1, points, n);
		printf("Case %d: %d\n", kase, result);
	}
	return 0;
}