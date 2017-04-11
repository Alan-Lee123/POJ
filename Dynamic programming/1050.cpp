#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int board[101][101];
int ls[101][101];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			scanf("%d", &board[i][j]);
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
			ls[i][j] = ls[i - 1][j] + board[i][j];
	}
	int ans = board[1][1];
	for (int r1 = 0; r1 < N; ++r1)
	{
		for (int r2 = r1 + 1; r2 <= N; ++r2)
		{
			int cur = 0;
			for (int i = 1; i <= N; ++i)
			{
				cur += ls[r2][i] - ls[r1][i];
				if (cur > ans)
					ans = cur;
				if (cur < 0)
					cur = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}