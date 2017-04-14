#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int nums[10000];
int dp[10000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N * (N + 1) / 2; ++i)
		scanf("%d", &nums[i]);
	for (int i = N * (N - 1) / 2 + 1; i <= N * (N + 1) / 2; ++i)
		dp[i] = nums[i];
	for (int i = N - 1; i > 0; --i)
	{
		for (int j = i * (i + 1) / 2; j > i * (i - 1) / 2; --j)
		{
			int l = j + i, r = j + i + 1;
			dp[j] = nums[j] + max(dp[l], dp[r]);
		}
	}
	printf("%d\n", dp[1]);
	return 0;
}