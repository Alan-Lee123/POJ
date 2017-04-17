#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

struct cow
{
	int x, y;
	bool operator < (const cow& c) const
	{
		return x < c.x;
	}
};

int pos[1100];
int flags[1100];
cow cows[1100];
int dp[3][1100][4];

int nums[50][2];

inline int min4(int* x)
{
	return min(x[0], min(x[1], min(x[2], x[3])));
}

int main()
{
	int N, K, B;
	scanf("%d%d%d", &N, &K, &B);
	for (int i = 0; i < N; ++i)
		scanf("%d%d", &cows[i].y, &cows[i].x);
	sort(cows, cows + N);
	int cnt = 1;
	pos[cnt] = cows[0].x;
	flags[cnt] = cows[0].y - 1;
	for (int i = 1; i < N; ++i)
	{
		if (cows[i].x == cows[i - 1].x)
			flags[cnt] = 2;
		else
		{
			cnt += 1;
			pos[cnt] = cows[i].x;
			flags[cnt] = cows[i].y - 1;
		}
	}
	N = cnt + 1;
	int INF = 2 * B + 1;
	int cur = 0, p1 = 2, p2 = 1;
	for (int k = 0; k < 3; ++k)
	{
		dp[k][0][0] = dp[k][0][1] = dp[k][0][2] = dp[k][0][3] = 0;
		for (int i = 1; i < N; ++i)
			dp[k][i][0] = dp[k][i][1] = dp[k][i][2] = dp[k][i][3] = INF;
	}
	
	for (int k = 1; k <= K; ++k)
	{
		cur = (cur + 1) % 3;
		p1 = (p1 + 1) % 3;
		p2 = (p2 + 1) % 3;
		dp[cur][0][0] = dp[cur][0][1] = dp[cur][0][2] = dp[cur][0][3] = INF;
		for (int i = 1; i < N; ++i)
		{
			int t1 = min4(dp[p1][i - 1]), t2 = min4(dp[p2][i - 1]);
			if (flags[i] != 2)
			{
				int a = dp[cur][i - 1][flags[i]] + pos[i] - pos[i - 1];
				int b = dp[cur][i - 1][3] + pos[i] - pos[i - 1];
				dp[cur][i][flags[i]] = min(a, min(b, t1 + 1));
				dp[cur][i][1 - flags[i]] = INF;
				dp[cur][i][2] = min(dp[cur][i - 1][2] + 2 * (pos[i] - pos[i - 1]), t1 + 2);
				a = dp[p1][i - 1][0] + pos[i] - pos[i - 1] + 1;
				b = dp[p1][i - 1][1] + pos[i] - pos[i - 1] + 1;
				int c = dp[cur][i - 1][3] + 2 * (pos[i] - pos[i - 1]);
				dp[cur][i][3] = min(min(a, min(b, c)), t2 + 2);
			}
			else
			{
				dp[cur][i][0] = dp[cur][i][1] = INF;
				dp[cur][i][2] = min(dp[cur][i - 1][2] + 2 * (pos[i] - pos[i - 1]), t1 + 2);
				int a = dp[p1][i - 1][0] + pos[i] - pos[i - 1] + 1;
				int b = dp[p1][i - 1][1] + pos[i] - pos[i - 1] + 1;
				int c = dp[cur][i - 1][3] + 2 * (pos[i] - pos[i - 1]);
				dp[cur][i][3] = min(min(a, min(b, c)), t2 + 2);
			}
			if (k == 1)
				dp[cur][i][3] = INF;
		}
		dp[cur][0][0] = dp[cur][0][1] = dp[cur][0][2] = dp[cur][0][3] = 0;
	}
	printf("%d\n", min4(dp[cur][N - 1]));
	return 0;
}