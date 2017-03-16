#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

struct point
{
	int x, y, z;
	int step;
	point(){}
	point(int xx, int yy, int zz, int s) :x(xx), y(yy), z(zz), step(s){}
	bool operator == (const point& p)
	{
		return x == p.x && y == p.y && z == p.z;
	}
};

int main()
{
	char board[12][12][12];
	int N;
	while (scanf("%*s%d", &N) != -1)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
				scanf("%s", board[i][j]);
		}
		point start, target;
		scanf("%d%d%d", &start.z, &start.y, &start.x);
		scanf("%d%d%d", &target.z, &target.y, &target.x);
		start.step = 0;
		scanf("%*s");
		int step = 0;
		queue<point> q;
		point p = start;
		board[start.x][start.y][start.z] = '*';
		q.push(start);
		while (!q.empty())
		{
			p = q.front();
			q.pop();
			if (p == target)
				break;
			for (int i = -1; i < 2; i += 2)
			{
				int xx = p.x + i, yy = p.y + i, zz = p.z + i;
				point ps[3];
				ps[0] = point(xx, p.y, p.z, p.step + 1);
				ps[1] = point(p.x, yy, p.z, p.step + 1);
				ps[2] = point(p.x, p.y, zz, p.step + 1);
				for (int j = 0; j < 3; ++j)
				{
					if (ps[j].x >= 0 && ps[j].x < N && ps[j].y >= 0 && ps[j].y < N && ps[j].z >= 0 && ps[j].z < N)
					{
						if (board[ps[j].x][ps[j].y][ps[j].z] == 'O')
						{
							board[ps[j].x][ps[j].y][ps[j].z] = '*';
							q.push(ps[j]);
						}
							
					}
				}
			}
		}
		if (p == target)
		{
			printf("%d %d\n", N, p.step);
		}
		else
		{
			printf("NO ROUTE\n");
		}
	}
	return 0;
}