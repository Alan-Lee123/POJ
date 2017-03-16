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
	int x, y;
	int step;
	point(){}
	point(int xx, int yy, int s) :x(xx), y(yy), step(s){}
	bool operator == (const point& p)
	{
		return x == p.x && y == p.y;
	}
};

int main()
{
	char s1[10], s2[10];
	while (scanf("%s%s", s1, s2) != -1)
	{
		point start(s1[0] - 'a', s1[1] - '1', 0);
		point target(s2[0] - 'a', s2[1] - '1', 0);
		bool used[8][8] = { false };
		int N = 8;
		queue<point> q;
		q.push(start);
		point p = start;
		while (!q.empty())
		{
			p = q.front();
			q.pop();
			if (p == target)
				break;
			for (int i = -1; i < 2; i += 2)
			{
				for (int j = -2; j < 3; j += 4)
				{
					point t(p.x + i, p.y + j, p.step + 1);
					if (t.x >= 0 && t.x < N && t.y >= 0 && t.y < N && !used[t.x][t.y])
					{
						q.push(t);
						used[t.x][t.y] = true;
					}
				}
			}
			for (int i = -2; i < 3; i += 4)
			{
				for (int j = -1; j < 2; j += 2)
				{
					point t(p.x + i, p.y + j, p.step + 1);
					if (t.x >= 0 && t.x < N && t.y >= 0 && t.y < N && !used[t.x][t.y])
					{
						q.push(t);
						used[t.x][t.y] = true;
					}
				}
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n", s1, s2, p.step);
	}
	return 0;
}