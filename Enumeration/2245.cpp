#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int n;
int nums[20];
bool used[20];
int record[20];

void dfs(int cur, int s)
{
	if (cur == 6)
	{
		printf("%d", record[0]);
		for (int i = 1; i < 6; ++i)
			printf(" %d", record[i]);
		printf("\n");
		return;
	}
	for (int i = s; i <= n - 6 + cur; ++i)
	{
		if (!used[i])
		{
			used[i] = true;
			record[cur] = nums[i];
			dfs(cur + 1, i + 1);
			used[i] = false;
		}
	}
}

int main()
{
	bool start = true;
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < n; ++i)
			scanf("%d", &nums[i]);
		memset(used, 0, sizeof(used));
		if (start)
			start = false;
		else
			printf("\n");
		dfs(0, 0);
	}
	return 0;
}