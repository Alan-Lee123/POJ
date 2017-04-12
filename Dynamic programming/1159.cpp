#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int dp[3][5010];
char str[5010];

int main()
{
	int N;
	scanf("%d", &N);
	scanf("%s", str);
	for (int i = 0; i < N; ++i)
	{
		dp[0][i] = 0;
		dp[1][i] = 1;
	}
	int p1 = 0, p2 = 1, cur = 2;
	for (int k = 1; k < N; ++k)
	{
		for (int i = 0; i + k < N; ++i)
		{
			int t = 2 * (k + 1);
			if (str[i] == str[i + k])
				t = dp[p1][i + 1] + 2;
			t = min(t, dp[p2][i] + 2);
			t = min(t, dp[p2][i + 1] + 2);
			dp[cur][i] = t;
		}
		p1 = (p1 + 1) % 3;
		p2 = (p2 + 1) % 3;
		cur = (cur + 1) % 3;
	}
	printf("%d\n", dp[p2][0] - N);
	return 0;
}