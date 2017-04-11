#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

long long dp[101][101][2];

int main()
{
	memset(dp, 0, sizeof(dp));
	dp[1][1][0] = 1;
	dp[1][1][1] = 1;
	for (int i = 2; i <= 100; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			for (int k = 1; k < j; ++k)
			{
				dp[i][j][0] += dp[i - 1][k][1];
			}
			for (int k = j + 1; k <= i; ++k)
			{
				dp[i][j][1] += dp[i - 1][k - 1][0];
			}
		}
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		long long c;
		scanf("%d%lld", &n, &c);
		vector<int> ans;
		int used[101] = { 0 };
		int pre = 2;
		for (int i = 0; i < n; ++i)
		{
			int cnt = 0;
			for (int j = 1; j <= n; ++j)
			{
				if (used[j])
				{
					++cnt;
					continue;
				}
				if (pre != 0 && (ans.size() == 0 || j > ans.back()))
				{
					if (c > dp[n - i][j - cnt][0])
						c -= dp[n - i][j - cnt][0];
					else
					{
						ans.push_back(j);
						used[j] = true;
						pre = 0;
						break;
					}
				}
				if (pre != 1 && (ans.size() == 0 || j < ans.back()))
				{
					if (c > dp[n - i][j - cnt][1])
						c -= dp[n - i][j - cnt][1];
					else
					{
						ans.push_back(j);
						used[j] = true;
						pre = 1;
						break;
					}
				}
			}
		}
		printf("%d", ans[0]);
		for (int i = 1; i < n; ++i)
			printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}