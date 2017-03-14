#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>

using namespace std;

struct cow
{
	int x, v;
	bool operator <(const cow& c) const
	{
		return v < c.v;
	}
};

const int n = 20010;

struct BIT
{
	int bs[20011];
	BIT()
	{
		memset(bs, 0, sizeof(bs));
	}

	inline int lowbit(int x)
	{
		return x&(-x);
	}

	void edit(int k, int v)
	{
		for (int i = k; i <= n; i += lowbit(i))
			bs[i] += v;
	}
	
	long long asum(int x)
	{
		long long ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += bs[i];
		return ret;
	}
};

int main()
{
	int N;
	scanf("%d", &N);
	vector<cow> cows = vector<cow>(N, cow());
	for (int i = 0; i < N; ++i)
		scanf("%d%d", &cows[i].v, &cows[i].x);
	sort(cows.begin(), cows.end());
	long long tot = 0;
	long long cnt = 0;
	if (N <= 1)
	{
		printf("0\n");
		return 0;
	}
	BIT Bs = BIT();
	BIT Ps = BIT();
	Bs.edit(cows[0].x, cows[0].x);
	Ps.edit(cows[0].x, 1);
	tot += cows[0].x;
	for (int i = 1; i < N; ++i)
	{
		long long l = Bs.asum(cows[i].x);
		int pl = Ps.asum(cows[i].x);
		cnt += cows[i].v * (pl * cows[i].x - l + tot - l - (i - pl) * cows[i].x);
		Bs.edit(cows[i].x, cows[i].x);
		Ps.edit(cows[i].x, 1);
		tot += cows[i].x;
	}

	printf("%lld\n", cnt);
	return 0;
}