#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int ts[60];
int ans, remain;

struct path
{
	int x, y, len;
	path(){}
	path(int xx, int yy, int l) :x(xx), y(yy), len(l) {}
	bool operator <(const path& p) const
	{
		if (len != p.len)
			return len > p.len;
		else
			return x < p.x;
	}
};

path ps[1000];
int N;

bool icheck(int x, int y)
{
	for (int i = x; i < 60; i += y)
	{
		if (!ts[i])
			return false;
	}
	return true;
}

void dfs(int cur, int cnt)
{
	if (remain == 0)
	{
		if (cnt < ans)
			ans = cnt;
	}
	while (cur < N && ps[cur].len > remain)
		++cur;
	for (int i = cur; i < N; ++i)
	{
		if (icheck(ps[i].x, ps[i].y))
		{
			if (cnt + remain / ps[i].len >= ans)
				return;
			for (int j = ps[i].x; j < 60; j += ps[i].y)
				ts[j]--;
			remain -= ps[i].len;
			dfs(i, cnt + 1);
			remain += ps[i].len;
			for (int j = ps[i].x; j < 60; j += ps[i].y)
				ts[j]++;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	memset(ts, 0, sizeof(ts));
	int x;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		ts[x] += 1;
	}
	N = 0;
	for (int i = 0; i < 30; ++i)
	{
		for (int j = i + 1; i + j < 60; ++j)
		{
			if (icheck(i, j))
				ps[N++] = path(i, j, 1 + (59 - i) / j);
		}
	}
	ans = n;
	remain = n;
	sort(ps, ps + N);
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}