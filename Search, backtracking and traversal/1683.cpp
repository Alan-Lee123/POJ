#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <string>

using namespace std;

struct point
{
	int x, y;
	point(){}
	point(int xx, int yy) :x(xx), y(yy){}
};

bool excluded[128][128];
vector<int> group[128];
int N, M;
char board[10][10];
point pos[128];
bool used[10][10];
int ans[10][10];

bool try_fill(int guest, int item, int p)
{
	if (used[item][p])
		return false;
	char c = board[item][p];
	for (int i = 0; i < N; ++i)
	{
		if (excluded[c][ans[guest][i]])
			return false;
	}
	bool flag = true;
	used[item][p] = true;
	ans[guest][item] = c;
	for (int i = 0, len = group[c].size(); i < len && flag; ++i)
	{
		char t = group[c][i];
		if (ans[guest][pos[t].x])
		{
			if (ans[guest][pos[t].x] != t)
				flag = false;
		}
		else
			flag &= try_fill(guest, pos[t].x, pos[t].y);
	}
	if (!flag)
	{
		used[item][p] = false;
		ans[guest][item] = 0;
	}
	return flag;
}

void ierase(int guest, int item, int p)
{
	used[item][p] = false;
	ans[guest][item] = 0;
	char c = board[item][p];
	for (int i = 0, len = group[c].size(); i < len; ++i)
	{
		char t = group[c][i];
		if (ans[guest][pos[t].x])
			ierase(guest, pos[t].x, pos[t].y);
	}
}

bool dfs(int guest, int item)
{
	if (guest == M)
		return true;
	if (item == N)
		return dfs(guest + 1, 0);
	if (ans[guest][item])
		return dfs(guest, item + 1);
	if (item == 0)
	{
		if (try_fill(guest, item, guest))
		{
			return dfs(guest, item + 1);
		}
		return false;
	}
	for (int i = 0; i < M; ++i)
	{
		if (!used[item][i])
		{
			if (try_fill(guest, item, i))
			{
				bool ret = dfs(guest, item + 1);
				if (ret) return true;
				else
					ierase(guest, item, i);
			}
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 0; kase < T; ++kase)
	{
		if (kase != 0)
			printf("\n");
		memset(used, 0, sizeof(used));
		memset(excluded, 0, sizeof(excluded));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < 128; ++i)
			group[i].clear();
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++i)
			scanf("%s", board[i]);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
				pos[board[i][j]] = point(i, j);
		}
		int x1, y1, x2, y2;
		char c;
		while (true)
		{
			scanf("%d%d %c%d%d", &x1, &y1, &c, &x2, &y2);
			if (x1 == 0)
				break;
			char a = board[x1 - 1][y1 - 1], b = board[x2 - 1][y2 - 1];
			if (c == 'R')
			{
				group[a].push_back(b);
				group[b].push_back(a);
			}
			else
			{
				excluded[a][b] = excluded[b][a] = true;
			}
		}
		dfs(0, 0);
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				printf("%c", ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}