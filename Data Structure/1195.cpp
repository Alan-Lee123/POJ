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

struct treeVec2
{
	int board[1100][1100];
	treeVec2()
	{
		memset(board, 0, sizeof(board));
	}
	int low_bit(int x)
	{
		return x & (-x);
	}
	int sum(int x, int y)
	{
		int r = 0;
		for (int i = x; i > 0; i -= low_bit(i))
		{
			for (int j = y; j > 0; j -= low_bit(j))
			{
				r += board[i][j];
			}
		}
		return r;
	}
	void add(int x, int y, int v)
	{
		for (int i = x; i < 1100; i += low_bit(i))
		{
			for (int j = y; j < 1100; j += low_bit(j))
			{
				board[i][j] += v;
			}
		}
	}
};

treeVec2 tv;

int main()
{
	int d, N;
	scanf("%d%d", &d, &N);
	while (true)
	{
		scanf("%d", &d);
		if (d == 3)
			break;
		if (d == 1)
		{
			int x, y, a;
			scanf("%d%d%d", &x, &y, &a);
			tv.add(x + 1, y + 1, a);

		}
		else
		{
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			int r = tv.sum(x2 + 1, y2 + 1);
			r -= tv.sum(x1, y2 + 1);
			r -= tv.sum(x2 + 1, y1);
			r += tv.sum(x1, y1);
			printf("%d\n", r);
		}
	}
	return 0;
}