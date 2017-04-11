#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int dist[110][110];

int main()
{
	int N;
	while (true)
	{
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
				dist[i][j] = (N + 1) * 11;
		}
		for (int i = 1; i <= N; ++i)
		{
			int m, to, cost;
			scanf("%d", &m);
			dist[i][i] = 0;
			for (int j = 0; j < m; ++j)
			{

				scanf("%d", &to);
				scanf("%d", &cost);
				dist[i][to] = cost;
			}
		}
		for (int k = 1; k <= N; ++k)
		{
			for (int i = 1; i <= N; ++i)
			{
				for (int j = 1; j <= N; ++j)
				{
					if (dist[i][j] > dist[i][k] + dist[k][j])
						dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
		int idx = 0, mx = (N + 1) * 11;
		for (int i = 1; i <= N; ++i)
		{
			int t = 0;
			for (int j = 1; j <= N; ++j)
			{
				if (dist[i][j] > t)
					t = dist[i][j];
			}
			if (mx > t)
			{
				idx = i, mx = t;
			}
		}
		printf("%d %d\n", idx, mx);
	}
	return 0;
}