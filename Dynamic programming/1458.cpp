#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

char s1[10000], s2[10000];
int dp[2][10100];

int main()
{
	while (scanf("%s%s", s1, s2) != -1)
	{
		int n1 = strlen(s1), n2 = strlen(s2);
		for (int i = 0; i <= n1; ++i)
			dp[0][i] = 0;
		int pre = 0, cur = 1;
		for (int k = 0; k < n2; ++k)
		{
			dp[cur][0] = 0;
			for (int i = 0; i < n1; ++i)
			{
				if (s2[k] != s1[i])
					dp[cur][i + 1] = max(dp[cur][i], dp[pre][i + 1]);
				else
					dp[cur][i + 1] = 1 + dp[pre][i];
			}
			swap(cur, pre);
		}
		printf("%d\n", dp[pre][n1]);
	}
	return 0;
}