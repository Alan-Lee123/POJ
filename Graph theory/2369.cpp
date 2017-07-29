#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <stack>

using namespace std;

int N;
int nums[1100];
int mp[1100];
int loops[1100];

int lcm(int x, int y)
{
	if (x == 0)
		return y;
	else
		return lcm(y % x, x);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &nums[i]);
	for (int i = 1; i <= N; ++i)
		mp[i] = nums[i];
	for (int i = 1; i <= N; ++i)
	{
		if (nums[i] == i)
		{
			loops[i] = 1;
			continue;
		}
		int t = i;
		for (int j = 1; ; ++j)
		{
			if (nums[t] == i)
			{
				loops[i] = j;
				break;
			}
			t = nums[t];
		}
	}

	int cnt = 1;
	for (int i = 1; i <= N; ++i)
	{
		cnt = (long long)cnt * loops[i] / lcm(loops[i], cnt);
	}
	printf("%d\n", cnt);
	
	return 0;
}