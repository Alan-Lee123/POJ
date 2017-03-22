#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int nums[20];
int M;
int ans;


void dfs(int cur, int x, int y, int z)
{
	if (cur == M)
	{
		int area = x * y * 2 + x * z * 2 + y * z * 2;
		if (area < ans)
			ans = area;
		return;
	}
	dfs(cur + 1, x * nums[cur], y, z);
	if (cur == 0)
		return;
	dfs(cur + 1, x, y * nums[cur], z);
	if (cur == 1)
		return;
	dfs(cur + 1, x, y, z * nums[cur]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		memset(nums, 0, sizeof(nums));
		M = 0;
		for (int i = 2; i < 1000;)
		{
			if (n % i == 0)
			{
				nums[M++] = i;
				n /= i;
			}
			else
				++i;
		}
		ans = 0x7FFFFFFF;
		dfs(0, 1, 1, 1);
		printf("%d\n", ans);
	}
	return 0;
}