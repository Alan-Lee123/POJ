#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

bool used[16000000];

int main()
{
	int a, c, m, R0;
	scanf("%d%d%d%d", &a, &c, &m, &R0);
	long long r = R0;
	while (!used[r])
	{
		used[r] = true;
		r = (r * a + c) % m;
	}
	int cur = -1;
	int ans = 0;
	for (int i = 0; i < 16000000; ++i)
	{
		if (used[i])
		{
			if (i - cur > ans && cur != -1)
				ans = i - cur;
			cur = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}