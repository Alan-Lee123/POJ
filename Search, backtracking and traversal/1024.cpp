#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

int W, H;

bool Walls[101][101][2];

int used[101][101];

struct point
{
	int x, y;
	int step;
	point() {}
	point(int xx, int yy, int s) : x(xx), y(yy), step(s) {}
};

bool my_check(string path, int&endx, int&endy)
{
	endx = 0, endy = 0;
	int n = path.size();
	for (int i = 0; i < n; ++i)
	{
		if (path[i] == 'U')
		{
			if (Walls[endx][endy][1])
				return false;
			endy += 1;
		}

		else if (path[i] == 'D')
		{
			if (Walls[endx][endy - 1][1])
				return false;
			endy -= 1;
		}

		else if (path[i] == 'R')
		{
			if (Walls[endx][endy][0])
				return false;
			endx += 1;
		}

		else
		{
			if (Walls[endx - 1][endy][0])
				return false;
			endx -= 1;
		}
	}
	return true;
}

inline bool check_point(int x, int y, int target)
{
	return x >= 0 && x < W && y >= 0 && y < H && used[x][y] == target;
}

bool back_check(int endx, int endy, int len)
{
	used[0][0] = 0;
	int x = endx, y = endy, cur = len - 1;
	int nx = 0, ny = 0;
	while ((x != 0 || y != 0) && cur)
	{
		int cnt = 0;
		if (check_point(x - 1, y, cur) && !Walls[x - 1][y][0])
		{
			cnt += 1;
			nx = x - 1, ny = y;
		}
		if (check_point(x + 1, y, cur) && !Walls[x][y][0])
		{
			cnt += 1;
			nx = x + 1, ny = y;
		}
		if (check_point(x, y - 1, cur) && !Walls[x][y - 1][1])
		{
			cnt += 1;
			nx = x, ny = y - 1;
		}
		if (check_point(x, y + 1, cur) && !Walls[x][y][1])
		{
			cnt += 1;
			nx = x, ny = y + 1;
		}
		if (cnt != 1)
			return false;
		x = nx, y = ny;
		--cur;
	}
	return true;
}

bool bfs(int endx, int endy, int len)
{
	point start(0, 0, 0);
	queue<point> q;
	q.push(start);
	point p;
	int ans = 10001;
	memset(used, 0, sizeof(used));
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		point t = point(p.x + 1, p.y, p.step + 1);
		if (t.x < W && (!used[t.x][t.y]))
		{
			if (!Walls[p.x][p.y][0])
			{
				used[t.x][t.y] = t.step;
				q.push(t);
				if (t.x == endx && t.y == endy) { ans = t.step; break; }
			}
		}
		t = point(p.x - 1, p.y, p.step + 1);
		if (t.x >= 0 && (!used[t.x][t.y]))
		{
			if (!Walls[t.x][t.y][0])
			{
				used[t.x][t.y] = t.step;
				q.push(t);
				if (t.x == endx && t.y == endy) { ans = t.step; break; }
			}
		}
		t = point(p.x, p.y + 1, p.step + 1);
		if (t.y < H && (!used[t.x][t.y]))
		{
			if (!Walls[p.x][p.y][1])
			{
				used[t.x][t.y] = t.step;
				q.push(t);
				if (t.x == endx && t.y == endy) { ans = t.step; break; }
			}
		}
		t = point(p.x, p.y - 1, p.step + 1);
		if (t.y >= 0 && (!used[t.x][t.y]))
		{
			if (!Walls[t.x][t.y][1])
			{
				used[t.x][t.y] = t.step;
				q.push(t);
				if (t.x == endx && t.y == endy) { ans = t.step; break; }
			}
		}
	}
	if (ans != len)
		return false;
	return back_check(endx, endy, ans);
}



int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &W, &H);
		char buff[10010];
		scanf("%s", buff);
		string path = buff;
		int wn;
		scanf("%d", &wn);
		int x1, y1, x2, y2;
		memset(Walls, 0, sizeof(Walls));
		for (int i = 0; i < wn; ++i)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x2 + y2 > x1 + y1)
			{
				if (x2 > x1)
					Walls[x1][y1][0] = true;
				else
					Walls[x1][y1][1] = true;
			}
			else
			{
				if (x1 > x2)
					Walls[x2][y2][0] = true;
				else
					Walls[x2][y2][1] = true;
			}
		}
		int endx, endy;
		bool ret = my_check(path, endx, endy);
		ret = bfs(endx, endy, path.size());
		for (int i = 0; i < W && ret; ++i)
		{
			for (int j = 0; j < H && ret; ++j)
			{
				for (int k = 0; k < 2; ++k)
				{
					if (Walls[i][j][k])
					{
						Walls[i][j][k] = false;
						bool t = bfs(endx, endy, path.size());
						if (t)
						{
							ret = false;
							break;
						}
						Walls[i][j][k] = true;
					}
				}
			}
		}
		if (ret)
			printf("CORRECT\n");
		else
			printf("INCORRECT\n");
	}
	return 0;
}