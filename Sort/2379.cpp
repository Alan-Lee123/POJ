#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <string>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct record
{
	int c, p, t, r;
	bool operator <(const record& rd) const
	{
		if (c != rd.c)
			return c < rd.c;
		else if (p != rd.p)
			return p < rd.p;
		else if (t != rd.t)
			return t < rd.t;
		else
			return r > rd.r;
	}
};

struct result
{
	int c, v;
	long long t;
	bool operator <(const result& r) const
	{
		if (v != r.v)
			return v > r.v;
		else if (t != r.t)
			return t < r.t;
		else
			return c < r.c;
	}
};

int main()
{
	int C, N;
	scanf("%d%d", &C, &N);
	vector<result> results = vector<result>(C, result());
	vector<record> rs = vector<record>(N, record());
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d%d%d", &rs[i].c, &rs[i].p, &rs[i].t, &rs[i].r);
	}
	for (int i = 0; i < C; ++i)
		results[i].c = i + 1;
	sort(rs.begin(), rs.end());
	long long tot = 0;
	bool solved[1012] = { false };
	int cnt = 0;
	if (rs[0].r == 1)
	{
		solved[rs[0].p] = true;
		cnt += 1;
		tot += rs[0].t;
	}
		
	for (int i = 1; i < N + 1; ++i)
	{
		if (i == N || rs[i].c != rs[i - 1].c)
		{
			result& rt = results[rs[i - 1].c - 1];
			rt.t = tot;
			rt.v = cnt;
			tot = 0;
			cnt = 0;
			memset(solved, 0, sizeof(solved));
		}
		if (i == N)
			break;
		if (rs[i].r == 1 && solved[rs[i].p] == false)
		{
			solved[rs[i].p] = true;
			cnt += 1;
			int j;
			for (j = i - 1; j >= 0 && rs[j].p == rs[i].p && rs[j].c == rs[i].c; --j)
				tot += 20 * 60;
			tot += rs[i].t;
		}

	}
	sort(results.begin(), results.end());
	for (int i = 0; i < C - 1; ++i)
		printf("%d ", results[i].c);
	printf("%d\n", results[C - 1].c);
	return 0;
}