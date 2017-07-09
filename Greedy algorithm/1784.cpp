#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

int dp[210][210];
int sums[210][210];

int main()
{
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		vector<int> nodes(n, 0);
		vector<int> fnodes(n + 1, 0);
		for (int i = 0; i < n; ++i)
			scanf("%d", &nodes[i]);
		for (int i = 0; i < n + 1; ++i)
			scanf("%d", &fnodes[i]);
		for (int i = 0; i < n; ++i)
			sums[i][i] = nodes[i] + fnodes[i] + fnodes[i + 1];
		for (int k = 1; k < n; ++k)
		{
			for (int i = 0; i < n; ++i)
				sums[i][i + k] = sums[i][i] - fnodes[i + 1] + sums[i + 1][i + k];
		}
		for (int i = 0; i < n; ++i)
			dp[i][i] = sums[i][i];
		int pre = 0, cur = 1;
		for (int k = 1; k < n; ++k)
		{
			for (int i = 0; i < n - k; ++i)
			{
				dp[i][i + k] = fnodes[i] + nodes[i] + dp[i + 1][i + k] + sums[i + 1][i + k];
				for (int j = 1; j < k; ++j)
				{
					int t = nodes[i + j] + dp[i][i + j - 1] + dp[i + j + 1][i + k] + sums[i][i + j - 1] + sums[i + j + 1][i + k];
					dp[i][i + k] = min(t, dp[i][i + k]);
				}
				int t = nodes[i + k] + fnodes[i + k + 1] + dp[i][i + k - 1] + sums[i][i + k - 1];
				dp[i][i + k] = min(t, dp[i][i + k]);
			}
		}
		printf("%d\n", dp[0][n - 1]);
	}

	return 0;
}