#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

struct cube
{
	int x[4];
	bool init;
	cube() : init(false)
	{
		memset(x, 0, sizeof(x));
	}
	cube(int *xx) : init(false)
	{
		for (int i = 0; i < 4; ++i)
			x[i] = xx[i];
	}

	bool operator !=(const cube& c) const
	{
		for (int i = 0; i < 4; ++i)
		{
			if (x[i] != c.x[i])
				return true;
		}
		return false;
	}
};

vector<cube> cs;

bool my_init(int idx, const vector<vector<int> >& inputs, vector<bool>& used)
{
	used[idx] = true;
	for (int i = 0; i < 8; ++i)
	{
		int cur = inputs[idx][i];
		if (cur == 0)
			continue;
		cs[idx].x[i / 2] += i % 2 * 2 - 1;
		cube c(cs[idx].x);
		cs[idx].x[i / 2] -= i % 2 * 2 - 1;
		if (cs[cur].init)
		{
			if (cs[cur] != c)
				return false;
		}
		else
		{
			cs[cur].init = true;
			for (int i = 0; i < 4; ++i)
				cs[cur].x[i] = c.x[i];
		}
	}
	bool ret = true;
	for (int i = 0; i < 8; ++i)
	{
		if (inputs[idx][i] != 0 && used[inputs[idx][i]] == false)
			ret = ret && my_init(inputs[idx][i], inputs, used);
	}
	return ret;
}

int main()
{
	int kase;
	scanf("%d", &kase);
	while (kase-- > 0)
	{
		int n;
		scanf("%d", &n);
		vector<vector<int> >inputs(110, vector<int>(8, 0));
		map<int, int> mp;
		cs = vector<cube>(110, cube());
		int cnt = 1;
		mp[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			int cur;
			scanf("%d", &cur);
			if (!mp.count(cur))
				mp[cur] = cnt++;
			cur = mp[cur];
			for (int j = 0; j < 8; ++j)
			{
				int t;
				scanf("%d", &t);
				if (!mp.count(t))
					mp[t] = cnt++;
				inputs[cur][j] = mp[t];
			}
				
		}
		n = mp.size();
		cs[1].init = true;
		vector<bool> used(n, false);
		bool consistent = my_init(1, inputs, used);
		for (int i = 1; i < n; ++i)
			consistent = consistent && used[i];
		if (consistent == false)
			printf("Inconsistent\n");
		else
		{
			int x[4] = { 0 }, y[4] = { 0 };
			for (int i = 1; i < n; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					x[j] = x[j] < cs[i].x[j] ? x[j] : cs[i].x[j];
					y[j] = y[j] > cs[i].x[j] ? y[j] : cs[i].x[j];
				}
			}
			long long ans = 1;
			for (int i = 0; i < 4; ++i)
				ans *= y[i] - x[i] + 1;
			printf("%lld\n", ans);
		}
	}
	return 0;
}