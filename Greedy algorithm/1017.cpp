#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>
#include <stack>

using namespace std;

int main()
{
	int nums[7];
	while (true)
	{
		int n = 0;
		for (int i = 1; i <= 6; ++i)
		{
			scanf("%d", &nums[i]);
			n += nums[i];
		}
		if (n == 0)
			break;

		int ans = 0;
		ans += nums[6];
		ans += nums[5];
		nums[1] -= 11 * nums[5];
		ans += nums[4];
		if (nums[2] >= 5 * nums[4])
			nums[2] -= 5 * nums[4];
		else
		{
			nums[1] -= (5 * nums[4] - nums[2]) * 4;
			nums[2] = 0;
		}
		ans += nums[3] / 4;
		nums[3] = nums[3] % 4;
		if (nums[3] != 0)
		{
			ans += 1;
			int empty = 9 * (4 - nums[3]);
			empty -= min(nums[2], 2 * (4 - nums[3]) - 1) * 4;
			nums[2] -= min(nums[2], 2 * (4 - nums[3]) - 1);
			nums[1] -= empty;
		}
		ans += nums[2] / 9;
		nums[2] = nums[2] % 9;
		if (nums[2] != 0)
		{
			nums[1] -= (9 - nums[2]) * 4;
			ans += 1;
		}
		nums[1] = max(0, nums[1]);
		if (nums[1] > 0)
			ans += nums[1] / 36;
		if (nums[1] % 36 != 0)
			ans += 1;
		printf("%d\n", ans);
	}
	return 0;
}