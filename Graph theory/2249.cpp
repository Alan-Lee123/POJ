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

int main()
{
	int n, k;
	while (true)
	{
		scanf("%d%d", &n, &k);
		if (n == 0 && k == 0)
			break;
		if (k > n - k)
			k = n - k;
		long long t = 1;
		int cnt = 2;
		for (int i = k; i > 0; --i)
		{
			t *= n--;
			while (cnt <= k && t % cnt == 0)
				t /= cnt++;
		}
		printf("%lld\n", t);
	}
	return 0;
}