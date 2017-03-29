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

struct road
{
	int xs[4], ys[4];
	int n;
	road() : n(0) {}
};

int N, M;
int board[30][30];
road rs[30][30];
int pre[900];
bool used[900];
queue<int> q;

void build_road(int x1, int y1, int x2, int y2, int d)
{
	if (x1 != x2)
	{
		for (int i = x1; i != x2; i += d)
		{
			int n = rs[i][y1].n;
			rs[i][y1].xs[n] = d;
			rs[i][y1].ys[n] = 0;
			rs[i][y1].n += 1;
		}
	}
	else
	{
		for (int i = y1; i != y2; i += d)
		{
			int n = rs[x1][i].n;
			rs[x1][i].xs[n] = 0;
			rs[x1][i].ys[n] = d;
			rs[x1][i].n += 1;
		}
	}
}

bool bfs(int x1, int y1, int x2, int y2)
{
	q = queue<int>();
	memset(pre, 0, sizeof(pre));
	memset(used, 0, sizeof(used));
	q.push(x1 * M + y1);
	used[x1 * M + y1] = true;
	int target = x2 * M + y2;
	while (!q.empty() && !used[target])
	{
		int cur = q.front();
		q.pop();
		int x = cur / M, y = cur % M;
		for (int i = 0; i < rs[x][y].n; ++i)
		{
			int xt = x + rs[x][y].xs[i], yt = y + rs[x][y].ys[i];
			if (board[xt][yt] - board[x][y] > 10)
				continue;
			int next = xt * M + yt;
			if (!used[next])
			{
				pre[next] = cur;
				q.push(next);
				used[next] = true;
			}
		}
	}
	return used[target];
}

void print_route(int x, int y)
{
	int t = x * M + y;
	vector<int> ans;
	while (t != 0)
	{
		ans.push_back(t);
		t = pre[t];
	}
	for (int i = 0, l = ans.size(); i < l; ++i)
	{
		int x = ans[l - 1 - i] / M, y = ans[l - 1 - i] % M;
		if (i != 0)
			printf(" to ");
		printf("%d-%d", x, y);
	}
	printf("\n");
}

int main()
{
	bool flag = true;
	while (scanf("%d%d", &N, &M) != -1)
	{
		memset(rs, 0, sizeof(rs));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
				scanf("%d", &board[i + 1][j + 1]);
		}
		N += 1, M += 1;
		int x1, y1, x2, y2;
		while (true)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x1 == 0)
				break;
			if (x1 < x2 || y1 < y2)
				build_road(x1, y1, x2, y2, 1);
			else
				build_road(x1, y1, x2, y2, -1);
		}
		while (true)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x1 == 0)
				break;
			if (!flag)
				printf("\n");
			else
				flag = false;
			if (x1 == x2 && y1 == y2)
			{
				printf("To get from %d-%d to %d-%d, stay put!\n", x1, y1, x2, y2);
				continue;
			}
			bool r = bfs(x1, y1, x2, y2);
			if (r)
				print_route(x2, y2);
			else
				printf("There is no acceptable route from %d-%d to %d-%d.\n", x1, y1, x2, y2);
		}
	}
	return 0;
}