#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int board[110][110];
int dp[110][110];
int step[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

int isearch(int x, int y)
{
	if (dp[x][y] >= 0)
		return dp[x][y];
	if (board[x][y] == -1)
		return dp[x][y] = 0;
	dp[x][y] = 1;
	for (int i = 0; i < 4; ++i)
	{
		int a = x + step[i][0], b = y + step[i][1];
		if (board[a][b] < board[x][y])
		{
			dp[x][y] = max(dp[x][y], isearch(a, b) + 1);
		}
	}
	return dp[x][y];
}

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	memset(dp, -1, sizeof(dp));
	memset(board, -1, sizeof(board));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			scanf("%d", &board[i + 1][j + 1]);
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (isearch(i, j) > ans)
				ans = dp[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}