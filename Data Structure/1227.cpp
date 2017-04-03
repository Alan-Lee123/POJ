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

int N, K;

int lines[110][110];
int footprint[110][110];
bool used[110][110];

void travel(int p, int step)
{
	if (step >= N)
		return;
	if (used[step][p])
		return;
	used[step][p] = true;
	footprint[step][p] += 1;
	for (int i = 0; lines[p][i] != 0; ++i)
		travel(lines[p][i], step + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &K);
		memset(lines, 0, sizeof(lines));
		memset(footprint, 0, sizeof(footprint));
		map<int, int> mp;
		int cnt = 1;
		for (int i = 0; i < N; ++i)
		{
			int x, m, y;
			scanf("%d%d", &x, &m);
			if (!mp.count(x))
				mp[x] = cnt++;
			x = mp[x];
				
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &y);
				if (!mp.count(y))
					mp[y] = cnt++;
				y = mp[y];
				lines[x][j] = y;
			}
		}
		int init;
		for (int i = 0; i < K; ++i)
		{
			scanf("%d", &init);
			init = mp[init];
			memset(used, 0, sizeof(used));
			travel(init, 0);
		}
		bool ans = false;
		for (int i = 0; i < N && !ans; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (footprint[i][j] == K)
					ans = true;
			}
		}
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}