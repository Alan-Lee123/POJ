#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> vline;
vector<int> sline;
vector<int> rs, hs;
int N, M;

void my_search(int level, int s, int v, int& ret)
{
	if (s + sline[level] >= ret)
		return;
	if (level == M)
	{
		if (v == N && s < ret)
			ret = s;
		return;
	}
	int tv, ts;
	for (int r = sqrt((N - v - vline[level + 1]) / (M - level) * 1.0); r >= M - level; --r)
	{
		if (level != 0 && r > rs[level - 1] - 1)
			r = rs[level - 1] - 1;
		if (r <= 2 * (N - v) / (ret - s))
			break;
		int h = (N - v - vline[level + 1]) / (r * r);
		if (level != 0 && h > hs[level - 1] - 1)
			h = hs[level - 1] - 1;
		for (; h >= M - level; --h)
		{
			
			rs[level] = r;
			hs[level] = h;
			tv = v + r * r * h;
			ts = s + 2 * r * h;
			if (level == 0)
				ts += r * r;
			my_search(level + 1, ts, tv, ret);
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	hs = rs = vector<int>(M, 0);
	vline = sline = vector<int>(M + 1, 0);
	vline[M] = 0;
	for (int i = 1; i <= M; ++i)
		vline[M - i] = vline[M - i + 1] + i * i * i;
	sline[M] = 0;
	for (int i = 1; i <= M; ++i)
		sline[M - i] = sline[M - i + 1] + 2 * i * i;
	sline[0] += M * M;
	int BIG = (1 << 31) - 1;
	int ans = BIG;
	if (M == 0 || N < vline[0])
	{
		printf("0\n");
	}
	else
	{
		my_search(0, 0, 0, ans);
		if (ans == BIG)
			ans = 0;
		printf("%d\n", ans);
	}
	return 0;
}