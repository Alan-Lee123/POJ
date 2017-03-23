#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node
{
	int d;
	int p;
};

node ns[50100];

int iparent(int x, int& d)
{
	d = 0;
	while (ns[x].p != 0)
	{
		d += ns[x].d;
		x = ns[x].p;
	}
	return x;
}

bool imerge(int x, int y, int d)
{
	int dx, dy;
	x = iparent(x, dx);
	y = iparent(y, dy);
	if (x == y)
	{
		return (dx - dy - d) % 3 == 0;
	}
	if (rand() % 2)
	{
		ns[x].p = y;
		ns[x].d = dy - dx + d;
	}
	else
	{
		ns[y].p = x;
		ns[y].d = dx - dy - d;
	}
	return true;
}

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	memset(ns, 0, sizeof(ns));
	srand(time(NULL));
	int cnt = 0;
	int D, x, y;
	for (int i = 0; i < K; ++i)
	{
		scanf("%d%d%d", &D, &x, &y);
		if (x > N || y > N)
			++cnt;
		else if (x == y && D == 2)
			++cnt;
		else
		{
			cnt += !imerge(x, y, D - 1);
		}
	}
	printf("%d\n", cnt);
	return 0;
}