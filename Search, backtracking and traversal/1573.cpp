#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

char board[12][12];
int trace[12][12];

int main()
{
	int start;
	while (true)
	{
		int m, n;
		scanf("%d%d%d", &m, &n, &start);
		if (m == 0)
			break;
		for (int i = 0; i < m; ++i)
			scanf("%s", board[i]);
		memset(trace, 0, sizeof(trace));
		int x = 0, y = start - 1;
		bool out = false;
		int cnt = 0;
		int lp = 0;
		while (true)
		{
			if (x < 0 || x >= m || y < 0 || y >= n)
			{
				out = true;
				break;
			}
			++cnt;
			if (trace[x][y] != 0)
			{
				out = false;
				lp = cnt - trace[x][y];
				cnt = trace[x][y] - 1;
				break;
			}
			else
				trace[x][y] = cnt;
			if (board[x][y] == 'W')
				--y;
			else if (board[x][y] == 'E')
				++y;
			else if (board[x][y] == 'N')
				--x;
			else
				++x;
		}
		if (out)
			printf("%d step(s) to exit\n", cnt);
		else
			printf("%d step(s) before a loop of %d step(s)\n", cnt, lp);
	}
	return 0;
}