#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <string>

using namespace std;

bool icheck(int x, int k)
{
	int N = k * 2;
	int cur = (x - 1) % N, cnt = 0;
	while (cnt < k && cur >= k)
	{
		++cnt;
		cur = (cur + x % (N - cnt) - 1) % (N - cnt);
	}
	return cnt == k;
}

int ifind(int k)
{
	int N = k * 2;
	for (int i = k + 1;; ++i)
	{
		if ((i - 1) % N == 0)
			i += k;
		if (icheck(i, k))
		{
			return i;
		}
	}
}


int main()
{
	int ans[14];
	for (int i = 1; i < 14; ++i)
	{
		ans[i] = ifind(i);
	}
	while (true)
	{
		int k;
		scanf("%d", &k);
		if (k == 0)
			break;
		printf("%d\n", ans[k]);
	}
	return 0;
}