#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

struct BIT
{
	int nums[10010];
	static const int n = 10010;
	int last_bit(int x)
	{
		return x & (-x);
	}

	void add(int p, int v)
	{
		for (int i = p + 1; i < n; i += last_bit(i))
			nums[i] += v;
	}

	int at(int p)
	{
		int sum = 0;
		for (int i = p + 1; i > 0; i -= last_bit(i))
			sum += nums[i];
		return sum;
	}
};

struct line
{
	int x, y;
	bool operator <(const line& l) const
	{
		if (y == l.y)
			return x < l.x;
		return y < l.y;
	}
};

BIT bt;
line ls[10010];


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &ls[i].x, &ls[i].y);
	sort(ls, ls + n);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int t = bt.at(ls[i].y) - bt.at(ls[i].x - 1);
		if (t == 0)
		{
			cnt += 2;
			bt.add(ls[i].y, 1);
			bt.add(ls[i].y - 1, 1);
		}
		else if (t == 1)
		{
			cnt += 1;
			bt.add(ls[i].y, 1);
		}
	}
	printf("%d\n", cnt);
	return 0;
}