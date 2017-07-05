#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

struct point
{
	int x, y;
	point() {}
	bool operator <(const point& p) const
	{
		if (y == p.y)
			return x < p.x;
		return y < p.y;
	}
};

struct BIT
{
	int nums[110];
	static const int n = 110;
	BIT()
	{
		memset(nums, 0, sizeof(nums));
	}

	int last_bit(int x)
	{
		return x & (-x);
	}

	void add(int p, int v)
	{
		for (int k = p + 1; k > 0; k -= last_bit(k))
			nums[k] += v;
	}

	int at(int p)
	{
		int r = 0;
		for (int k = p + 1; k < n; k += last_bit(k))
			r += nums[k];
		return r;
	}
};

bool icmp(const point& p1, const point& p2)
{
	if (p1.x == p2.x)
		return p1.y < p2.y;
	return p1.x < p2.x;
}

BIT b;
priority_queue<point> pq;
point ps[110];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(b.nums, 0, sizeof(b.nums));
		pq = priority_queue<point>();
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%*d%d%*d", &ps[i].x, &ps[i].y);
			if (ps[i].x > ps[i].y)
				swap(ps[i].x, ps[i].y);
		}
			

		sort(ps, ps + n, icmp);
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			pq.push(ps[i]);
			b.add(ps[i].y, 1);
			while (b.at(ps[i].x) > k)
			{
				cnt += 1;
				point p = pq.top();
				b.add(p.y, -1);
				pq.pop();
			}
		}
		printf("%d\n", cnt);
	}
}