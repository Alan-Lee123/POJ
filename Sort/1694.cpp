#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<vector<int> >& tree, int cur)
{
	int n = tree[cur].size();
	if (n == 0)
		return 1;
	vector<int> rs = vector<int>(n, 0);
	for (int i = 0; i < n; ++i)
		rs[i] = search(tree, tree[cur][i]);
	sort(rs.begin(), rs.end());
	int mx = -1;
	for (int i = 0; i < n; ++i)
	{
		if (rs[i] + n - 1 - i > mx)
			mx = rs[i] + n - 1 - i;
	}
	return mx;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (; N > 0; --N)
	{
		int n;
		scanf("%d", &n);
		vector<vector<int> > tree = vector<vector<int> >(n + 1, vector<int>());
		int x, m;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &x, &m);
			if (m != 0)
			{
				tree[x] = vector<int>(m, 0);
				for (int j = 0; j < m; ++j)
					scanf("%d", &tree[x][j]);
			}
		}
		int ret = search(tree, 1);
		printf("%d\n", ret);
	}
}