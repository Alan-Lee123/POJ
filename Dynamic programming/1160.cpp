#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int dist[310][310];
int dp[2][310];
int village[310];


int main()
{
	int N, P;
	scanf("%d%d", &N, &P);
	for (int i = 0; i < N; ++i)
		scanf("%d", &village[i]);
	for (int i = 0; i < N; ++i)
	{
		dist[i][i] = 0;
		dist[i][i + 1] = village[i + 1] - village[i];
	}
	for (int k = 2; k < N; ++k)
	{
		for (int i = 0; i + k < N; ++i)
			dist[i][i + k] = village[i + k] - village[i] + dist[i + 1][i + k - 1];
	}

	for (int i = 0; i < N; ++i)
		dp[0][i] = dist[0][i];
	int pre = 0, cur = 1;
	for (int k = 2; k <= P; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			if (i < k)
				dp[cur][i] = 0;
			else
			{
				dp[cur][i] = dp[pre][i];
				for (int j = i - 1; j > k - 1; --j)
					dp[cur][i] = min(dp[cur][i], dp[pre][j] + dist[j + 1][i]);
			}
		}
		swap(cur, pre);
	}
	printf("%d\n", dp[pre][N - 1]);
	return 0;
}