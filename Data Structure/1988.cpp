#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

struct point
{
	int x, len;
	point* pre;
};

point ps[300100];
int tails[300100];

int get_head(int x)
{
	if (ps[x].pre == NULL)
	{
		ps[x].len = 0;
		return x;
	}
	int r = get_head(ps[x].pre->x);
	ps[x].len = ps[x].len + ps[x].pre->len;
	ps[x].pre = &ps[r];
	return r;
}

int main()
{
	memset(ps, 0, sizeof(ps));
	for (int i = 1; i <= 300000; ++i)
		tails[i] = ps[i].x = i;
	int P;
	scanf("%d", &P);
	char c[10];
	int x, y;
	for (int k = 0; k < P; ++k)
	{
		scanf("%s", c);
		if (c[0] == 'M')
		{
			scanf("%d%d", &x, &y);
			int h1 = get_head(x);
			int h2 = get_head(y);
			int t1 = tails[h1];
			int t2 = tails[h2];
			ps[h1].pre = &ps[t2];
			ps[h1].len = 1;
			tails[h2] = t1;
		}
		else
		{
			scanf("%d", &x);
			get_head(x);
			printf("%d\n", ps[x].len);
		}
	}
	return 0;
}