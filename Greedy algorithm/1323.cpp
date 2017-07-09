#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int m, n;
	for (int T = 1;;++T)
	{
		scanf("%d%d", &m, &n);
		if (m == 0 && n == 0)
			break;
		vector<int> nums(n, 0);
		for (int i = 0; i < n; ++i)
			scanf("%d", &nums[i]);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n / 2; ++i)
			swap(nums[i], nums[n - i - 1]);
		set<int> used;
		for (int i = 0; i < n; ++i)
			used.insert(nums[i]);
		int cur = m * n;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			while (used.count(cur)) --cur;
			if (cur > nums[i])
				--cur;
			else
				++cnt;
		}
		printf("Case %d: %d\n", T, cnt);
	}
	return 0;
}