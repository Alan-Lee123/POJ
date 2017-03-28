#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

struct point
{
	int x, y, h;
	point() {}
	point(int x, int y, int h) :x(x), y(y), h(h){}
	bool operator< (const point& p) const
	{
		return h > p.h;
	}
};

int board[310][310];
bool used[310][310];
int W, H;
priority_queue<point> pq;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

long long solution()
{
	for (int i = 0; i <= H + 1; ++i)
		used[i][0] = used[i][W + 1] = true;
	for (int i = 0; i <= W + 1; ++i)
		used[0][i] = used[H + 1][i] = true;
	for (int i = 1; i <= H; ++i)
	{
		pq.push(point(i, 1, board[i][1]));
		pq.push(point(i, W, board[i][W]));
		used[i][1] = used[i][W] = true;
	}
	for (int i = 2; i <= W - 1; ++i)
	{
		pq.push(point(1, i, board[1][i]));
		pq.push(point(H, i, board[H][i]));
		used[1][i] = used[H][i] = true;
	}
	point p;
	long long cnt = 0;
	while (!pq.empty())
	{
		p = pq.top();
		pq.pop();
		point t;
		for (int i = 0; i < 4; ++i)
		{
			t.x = p.x + dx[i];
			t.y = p.y + dy[i];
			t.h = board[t.x][t.y];
			if (used[t.x][t.y])
				continue;
			if (t.h < p.h)
			{
				cnt += p.h - t.h;
				t.h = p.h;
			}
			pq.push(t);
			used[t.x][t.y] = true;
		}
	}
	return cnt;
}

int main()
{
	scanf("%d%d", &W, &H);
	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			scanf("%d", &board[i][j]);
		}
	}
	memset(used, 0, sizeof(used));
	long long ans = solution();
	printf("%lld\n", ans);
	return 0;
}