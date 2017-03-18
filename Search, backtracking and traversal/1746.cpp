#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

int Q, P;
int K;
vector<long long> ans;

long long inline irise(long long x)
{		
	return x + (long long)(x / 100. * P + 0.5);
}

bool try_pay(long long q, long long x, int k)
{
	int cnt = 0;
	if (irise(q) - q >= x)
		return false;
	while (q > 0 && cnt < k)
	{
		q = irise(q) - x;
		++cnt;
	}
	if (q <= 0)
		return true;
	return false;
}

long long isearch(long long x, long long y)
{
	if (x == y - 1)
		return y;
	long long mid = (x + y) / 2;
	if (try_pay(Q, mid, K))
		return isearch(x, mid);
	else
		return isearch(mid, y);
}

bool dfs(long long x, int cnt, long long remain)
{
	if (cnt == 1)
	{
		if (x == irise(remain))
		{
			ans.push_back(x);
			return true;
		}
		return false;
	}
	if (!try_pay(remain, x, cnt) || try_pay(remain, x - cnt + 1, cnt))
		return false;

	remain = irise(remain);
	if (remain < x)
		return false;

	if (dfs(x - 1, cnt - 1, remain - x) || dfs(x, cnt - 1, remain - x))
	{
		ans.push_back(x);
		return true;
	}
	return false;
}

int main()
{
	double q;
	scanf("%lf%d%d", &q, &P, &K);
	Q = (int)(q * 100 + 1e-6);
	long long p1 = isearch(0, 3 * (long long)Q);
	ans = vector<long long>();
	bool ret = dfs(p1, K, Q);
	while (!ret)
	{
		++p1;
		if (try_pay(Q, p1 - K + 1, K))
			break;
		ret = dfs(p1, K, Q);
	}
	if (!ret)
		printf("Impossible\n");
	else
	{
		int len = ans.size();
		for (int i = 0; i < len / 2; ++i)
			swap(ans[i], ans[len - 1 - i]);
		vector<int> nums(1, 1);
		for (int i = 1; i < len; ++i)
		{
			if (ans[i] == ans[i - 1])
			{
				++nums.back();
			}
			else
			{
				ans[nums.size()] = ans[i];
				nums.push_back(1);
			}
		}
		for (int i = 0, m = nums.size(); i < m; ++i)
		{
			printf("$%.2lf for %d year(s)\n", ans[i] * 0.01, nums[i]);
		}
	}
	return 0;
}