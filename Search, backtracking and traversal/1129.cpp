#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

vector<vector<int> > lines;
vector<int> colors;

bool dye(int cur, int c, int m)
{
	colors[cur] = c;
	for (int i = 0, len = lines[cur].size(); i < len; ++i)
	{
		if (colors[lines[cur][i]] == c)
			return false;
	}
	for (int i = 0, j = 0, len = lines[cur].size(); i < len; ++i)
	{
		if (colors[lines[cur][i]] == 0)
		{
			for (j = 1; j < m + 1; ++j)
			{
				if (j == c)
					continue;
				bool ret = dye(lines[cur][i], j, m);
				if (ret)
					break;
			}
			if (j == m + 1)
				return false;
		}
	}
	return true;
}

bool try_dye(int m)
{
	int n = colors.size();
	bool succ = true;
	for (int i = 0; i < n; ++i)
	{
		if (colors[i] == 0)
		{
			succ = dye(i, 1, m);
			if (!succ)
				break;
		}
	}
	colors = vector<int>(n, 0);
	return succ;
}

int main()
{
	char buff[100];
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		lines = vector<vector<int> >(n, vector<int>());
		colors = vector<int>(n, 0);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", buff);
			string s = buff;
			for (int j = 2, len = s.size(); j < len; ++j)
			{
				lines[i].push_back(s[j] - 'A');
			}
		}
		int mx = 0;
		for (int i = 0; i < n; ++i)
			mx = mx > lines[i].size() ? mx : lines[i].size();
		if (mx == 0)
		{
			printf("1 channel needed.\n");
		}
		else
		{
			for (int i = 2; i < mx + 2; ++i)
			{
				bool ret = try_dye(i);
				if (ret)
				{
					printf("%d channels needed.\n", i);
					break;
				}
			}
		}
	}
	return 0;
}