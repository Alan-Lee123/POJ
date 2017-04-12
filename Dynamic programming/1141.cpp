#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int dp[110][110];
char str[110];
int N;

string dfs(int x, int y)
{
	if (dp[x][y] == y - x)
		return string(str + x, str + y);
	if (x + 1 == y)
	{
		if (str[x] == '(' || str[x] == ')')
			return "()";
		else
			return "[]";
	}
	if ((str[x] == '(' && str[y - 1] == ')') || (str[x] == '[' && str[y - 1] == ']'))
	{
		if (dp[x][y] == dp[x + 1][y - 1] + 2)
			return str[x] + dfs(x + 1, y - 1) + str[y - 1];
	}
	for (int k = x + 1; k < y; ++k)
	{
		if (dp[x][k] + dp[k][y] == dp[x][y])
			return dfs(x, k) + dfs(k, y);
	}
	return "";
}

int main()
{
	scanf("%s", str);
	N = strlen(str);
	for (int i = 0; i < N; ++i)
	{
		dp[i][i] = 0;
		dp[i][i + 1] = 2;
	}
		
	for (int k = 2; k <= N; ++k)
	{
		for (int i = 0; i + k <= N; ++i)
		{
			int t = 2 * k;
			if ((str[i] == '(' && str[i + k - 1] == ')') || (str[i] == '[' && str[i + k - 1] == ']'))
				t = dp[i + 1][i + k - 1] + 2;
			for (int j = i + 1; j < i + k; ++j)
				t = min(t, dp[i][j] + dp[j][i + k]);
			dp[i][i + k] = t;
		}
	}
	string ans = dfs(0, N);
	printf("%s\n", ans.c_str());
	return 0;
}