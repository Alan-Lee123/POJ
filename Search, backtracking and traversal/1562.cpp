#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

char board[110][110];
int m, n;

void dye(int x, int y)
{
	board[x][y] = '*';
	for (int i = -1; i < 2; ++i)
	{
		for (int j = -1; j < 2; ++j)
		{
			if (x + i >= 0 && x + i < m && y + j >= 0 && y + j < n && (i != 0 || j != 0))
			{
				if (board[x + i][y + j] == '@')
					dye(x + i, y + j);
			}
		}
	}
}


int main()
{
	while (true)
	{
		scanf("%d%d", &m, &n);
		if (m == 0)
			break;
		for (int i = 0; i < m; ++i)
			scanf("%s", board[i]);
		int cnt = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == '@')
				{
					++cnt;
					dye(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}