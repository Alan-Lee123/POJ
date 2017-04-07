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

#define INF 0x7FFFFFFF
#define ESP 1e-9

struct vectree
{
	int nums[120];
	vectree()
	{
		memset(nums, 0, sizeof(nums));
	}
	int lastBit(int x)
	{
		return x & (-x);
	}
	int sum(int t)
	{
		int r = 0;
		for (int i = t; i > 0; i -= lastBit(i))
			r += nums[i];
		return r;
	}
	void add(int x, int v)
	{
		for (int i = x; i < 120; i += lastBit(i))
			nums[i] += v;
	}
};

struct point
{
	int id, v, x;
};

point ps[250100];

struct line
{
	int p, id1, id2;
	double t, px;
	line() {}
	line(int x)
	{
		p = x;
		id1 = ps[x].id;
		id2 = ps[x + 1].id;
		if (ps[x].v <= ps[x + 1].v)
		{
			t = INF;
			px = INF;
		}
		else
		{
			t = (ps[x + 1].x - ps[x].x) * 1.0 / (ps[x].v - ps[x + 1].v);
			px = ps[x].x + ps[x].v * t;
		}
	}
	bool operator <(const line& l) const
	{
		if (abs(t - l.t) > ESP * (t + l.t))
			return t > l.t;
		else
			return px > l.px;
	}
};

int N;
line ls[250100];
priority_queue<line> pq;

int main()
{
	scanf("%d", &N);
	vectree vt;
	int inv = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", &ps[i].x, &ps[i].v);
		ps[i].id = i + 1;
		ps[i].v += 1;
		vt.add(ps[i].v, 1);
		inv = (inv + i + 1 - vt.sum(ps[i].v)) % 1000000;
	}
	printf("%d\n", inv);
	for (int i = 0; i < N - 1; ++i)
	{
		ls[i] = line(i);
		pq.push(ls[i]);
	}
	for (int i = 0; i < 10000 && !pq.empty(); ++i)
	{
		line l = pq.top();
		pq.pop();
		if (ps[l.p].id != l.id1 || ps[l.p + 1].id != l.id2)
		{
			i--;
			continue;
		}
		if (l.t == INF)
			break;
		printf("%d %d\n", l.id1, l.id2);
		swap(ps[l.p], ps[l.p + 1]);
		if (l.p + 1 < N - 1)
			pq.push(line(l.p + 1));
		if (l.p != 0)
			pq.push(line(l.p - 1));
	}
	return 0;
}