#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int nums[50][2];

int main()
{
	nums[1][0] = 1;
	nums[1][1] = 1;
	for (int k = 2; k < 45; ++k)
	{
		nums[k][0] = nums[k - 1][0] + nums[k - 1][1];
		nums[k][1] = nums[k - 1][0];
	}
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		int x;
		scanf("%d", &x);
		printf("Scenario #%d:\n", i);
		printf("%d\n\n", nums[x][0] + nums[x][1]);
	}
	return 0;
}