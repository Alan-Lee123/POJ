#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

int nums[20];
int sums[20];
int N;

bool isearch(int target, int cur)
{
	if (target == 0)
		return true;
	if (cur < 0)
		return false;
	bool r = false;
	if (target > sums[cur])
		return false;
	if (target >= nums[cur])
		r = isearch(target - nums[cur], cur - 1);
	if (r)
		return true;
	else
		return isearch(target, cur - 1);
}

int main()
{
	nums[0] = 1;
	sums[0] = 1;
	N = 1;
	while (nums[N - 1] * N <= 1000000)
	{
		nums[N] = nums[N - 1] * N;
		sums[N] = sums[N - 1] + nums[N];
		++N;
	}
	int n;
	while (true)
	{
		scanf("%d", &n);
		if (n < 0)
			break;
		if (n != 0 && isearch(n, N - 1))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}