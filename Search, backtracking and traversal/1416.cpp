#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

int target;
int nums[10];
int ans[10];
int N, ans_tot;
int ans_nb;
int record[10];
int remains[10];

void dfs(int cur, int pos, int pre, int tot)
{
	if (cur == N)
	{
		if (tot <= target && tot > ans_tot)
		{
			ans_nb = 1;
			ans_tot = tot;
			memcpy(ans, record, pos * sizeof(int));
			ans[pos] = -1;
		}
		else if (tot == ans_tot)
		{
			ans_nb += 1;
		}
		return;
	}

	if (tot + remains[cur] > target)
		return;

	record[pos] = nums[cur];
	dfs(cur + 1, pos + 1, record[pos], tot + nums[cur]);
	if (cur == 0)
		return;
	record[pos - 1] = pre * 10 + nums[cur];
	dfs(cur + 1, pos, record[pos - 1], tot + record[pos - 1] - pre);

}

int main()
{
	while (true)
	{
		int num;
		scanf("%d%d", &target, &num);
		if (target == 0 && num == 0)
			break;
		N = 0;
		while (num > 0)
		{
			nums[N++] = num % 10;
			num /= 10;
		}
		for (int i = 0; i < N / 2; ++i)
			swap(nums[i], nums[N - 1 - i]);
		remains[N] = 0;
		for (int i = N - 1; i >= 0; --i)
			remains[i] = remains[i + 1] + nums[i];
		ans_nb = 0;
		ans_tot = 0;
		dfs(0, 0, 0, 0);
		if (ans_nb == 0)
			printf("error\n");
		else if (ans_nb > 1)
			printf("rejected\n");
		else
		{
			printf("%d", ans_tot);
			for (int i = 0; ans[i] != -1; ++i)
				printf(" %d", ans[i]);
			printf("\n");
		}
	}
	return 0;
}