#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

struct my_point
{
	int x, y;
	int no;
	my_point(){};
	my_point(int xx, int yy, int n) :x(xx), y(yy), no(n) {}
	bool operator <(const my_point& p) const
	{
		if (x != p.x)
			return x < p.x;
		else
			return y < p.y;
	}
};

vector<my_point> points;

bool my_search(int &l, int &b, int &e, int &di)
{
	sort(points.begin(), points.end());
	int n = points.size();
	bool ret = false;
	for (int i = 0; i < n - 1; ++i)
	{
		if (points[i].x == points[i + 1].x)
		{
			int y1 = points[i].y, y2 = points[i + 1].y, no1 = points[i].no, no2 = points[i + 1].no;
			if ((abs(no2 - no1) > 1) && ((y2 - y1 < l) || (y2 - y1 == l && min(no2, no1) < b) ||
				(y2 - y1 == l && min(no2, no1) == b && max(no2, no1) > e)))
			{
				l = y2 - y1;
				if (no2 > no1)
				{
					b = no1;
					e = no2;
					di = 0;
				}
				else
				{
					b = no2;
					e = no1;
					di = 1;
				}
				ret = true;
			}
		}
	}
	return ret;
}


int main()
{
	int n;
	scanf("%d", &n);
	points = vector<my_point>(n + 1, my_point());
	char* input = (char *)malloc(sizeof(char) * (n + 1));
	scanf("%s", input);
	int x = 0, y = 0;
	points[0] = my_point(0, 0, 0);
	for (int i = 0; i < n; ++i)
	{
		if (input[i] == 'N')
			x -= 1;
		else if (input[i] == 'S')
			x += 1;
		else if (input[i] == 'W')
			y -= 1;
		else if (input[i] == 'E')
			y += 1;
		points[i + 1] = my_point(x, y, i + 1);
	}

	int b, e, di, l = n + 1;
	char d;
	my_search(l, b, e, di);
	if (di == 0)
		d = 'E';
	else
		d = 'W';
	for (int i = 0; i < n + 1; ++i)
		swap(points[i].x, points[i].y);
	bool ret = my_search(l, b, e, di);
	if (ret)
	{
		if (di == 0)
			d = 'S';
		else
			d = 'N';
	}
	printf("%d %d %d %c\n", l, b, e, d);
	return 0;
}