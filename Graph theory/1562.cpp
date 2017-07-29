#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <stack>
#include <queue>

using namespace std;

char board[110][110];

int m, n;

void travel(int x, int y)
{
	if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '*')
		return;
	board[x][y] = '*';
	for (int i = -1; i < 2; ++i)
	{
		for (int j = -1; j < 2; ++j)
			if (i == 0 && j == 0)
				continue;
			else
				travel(x + i, y + j);
	}
}

int main()
{
	while (true)
	{
		scanf("%d%d", &m, &n);
		if (m == 0 && n == 0)
			break;
		fgets(board[0], 110, stdin);
		for (int i = 0; i < m; ++i)
			fgets(board[i], 110, stdin);
		int cnt = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == '@')
				{
					++cnt;
					travel(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}