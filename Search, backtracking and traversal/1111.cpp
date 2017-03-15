#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

char board[30][30];
bool used[30][30];

void dye(int x, int y, int m, int n, int &cnt)
{
	used[x][y] = true;
	for (int i = -1; i < 2; ++i)
	{
		for (int j = -1; j < 2; ++j)
		{
			int cx = x + i, cy = y + j;
			if (cx >= 0 && cx < m && cy >= 0 && cy < n)
			{
				if (i * j == 0 && board[cx][cy] == '.')
					++cnt;
				if (board[cx][cy] == 'X' && !used[cx][cy])
					dye(cx, cy, m, n, cnt);
			}
			else if (i * j == 0)
				++cnt;
		}
	}
}

int main()
{
	int m, n, x, y;
	while (true)
	{
		scanf("%d%d%d%d", &m, &n, &x, &y);
		if (m == 0)
			break;
		for (int i = 0; i < m; ++i)
			scanf("%s", board[i]);
		memset(used, 0, sizeof(used));
		int cnt = 0;
		dye(x - 1, y - 1, m, n, cnt);
		printf("%d\n", cnt);
	}
	return 0;
}