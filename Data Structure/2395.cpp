#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

struct line
{
	int x, y, len;
	bool operator <(const line& l) const
	{
		return len < l.len;
	}
};

line ls[10100];
int ps[10100];

int iparent(int x)
{
	return ps[x] == 0 ? x : (ps[x] = iparent(ps[x]));
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i)
		scanf("%d%d%d", &ls[i].x, &ls[i].y, &ls[i].len);
	sort(ls, ls + M);
	int ans = 0;
	for (int i = 0, j = 0; j < N - 1; ++i)
	{
		int x = iparent(ls[i].x), y = iparent(ls[i].y);
		if (x != y)
		{
			ans = ls[i].len;
			j += 1;
			ps[x] = y;
		}
	}
	printf("%d\n", ans);
	return 0;
}