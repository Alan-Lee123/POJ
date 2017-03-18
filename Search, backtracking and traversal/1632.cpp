#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

vector<int> lines[40];
int used[40];
bool flag;

bool vec_cmp(vector<int>& v1, vector<int> v2)
{
	return v1.size() > v2.size();
}

void try_find(int cur, int cnt, int target)
{
	if (cnt == target)
		flag = true;
	if (flag)
		return;
	if (lines[cur].size() < target)
		return;
	int c = 0;
	for (int i = 0, len = lines[cur].size(); i < len; ++i)
	{
		if (used[lines[cur][i]] == cnt)
			++c;
	}
	if (c >= target)
	{
		for (int i = 0, len = lines[cur].size(); i < len; ++i)
			used[lines[cur][i]] += 1;
		try_find(cur + 1, cnt + 1, target);
		for (int i = 0, len = lines[cur].size(); i < len; ++i)
			used[lines[cur][i]] -= 1;
	}
	try_find(cur + 1, cnt, target);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < 40; ++i)
			lines[i].clear();
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			lines[x].push_back(y);
		}
		sort(lines, lines + 40, vec_cmp);
		int ans = 0;
		flag = true;
		while (flag)
		{
			flag = false;
			memset(used, 0, sizeof(used));
			ans += 1;
			try_find(0, 0, ans + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}