#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int N;
int ans, ans_node;
const int BIG = 20100;

vector<vector<int> > tree;

int dfs(int cur, int pre)
{
	int n = tree[cur].size();
	int r = 1;
	int b = 0;
	for (int i = 0; i < n; ++i)
	{
		if (tree[cur][i] != pre)
		{
			int x = dfs(tree[cur][i], cur);
			r += x;
			b = max(b, x);
		}
	}
	b = max(b, N - r);
	if (b < ans)
	{
		ans = b;
		ans_node = cur;
	}
	else if (b == ans && cur < ans_node)
		ans_node = cur;
	return r;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		tree = vector<vector<int> >(BIG, vector<int>());
		int st = 1;
		for (int i = 0; i < N - 1; ++i)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			tree[x].push_back(y);
			tree[y].push_back(x);
			st = x;
		}
		ans = BIG, ans_node = BIG;
		dfs(st, -1);
		printf("%d %d\n", ans_node, ans);
	}
	return 0;
}