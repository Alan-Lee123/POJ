#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <stack>
#include <queue>

using namespace std;

long long nums[12][27];

int main()
{
	char s[20];
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 1; i < n; ++i)
		if (s[i] <= s[i - 1])
		{
			printf("0\n");
			return 0;
		}
	for (int i = 1; i <= 26; ++i)
		nums[1][i] = i;
	for (int k = 2; k <= n; ++k)
	{
		for (int i = k; i <= 26; ++i)
		{
			for (int j = i - 1; j >= k - 1; --j)
				nums[k][i] += nums[k - 1][j];
		}
	}
	long long ans = 0;
	for (int k = 1; k <= n - 1; ++k)
	{
		ans += nums[k][26];
	}
	for (int i = 0; i < n; ++i)
	{
		int j = i == 0 ? 0 : s[i - 1] - 'a' + 1;
		for (; j + 'a' < s[i]; ++j)
		{
			ans += nums[n - i - 1][25 - j];
		}
	}
	if (n >= 2)
		ans += s[n - 1] - s[n - 2];
	else
		ans += s[n - 1] - 'a' + 1;
	printf("%lld\n", ans);
	return 0;
}