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

struct point
{
	int x, y, id, p;
};

point ps[1100];
int N, D;

int iparent(int id)
{
	int t = id;
	while (ps[t].p != -1)
		t = ps[t].p;
	if (t != id)
		ps[id].p = t;
	return t;
}

void imerge(int a, int b)
{
	a = iparent(a);
	b = iparent(b);
	if (a == b)
		return;
	if (rand() % 2)
		ps[a].p = b;
	else
		ps[b].p = a;
}

inline int idist(int a, int b)
{
	int x = ps[a].x - ps[b].x, y = ps[a].y - ps[b].y;
	return x * x + y * y;
}

int main()
{
	scanf("%d%d", &N, &D);
	D *= D;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d%d", &ps[i].x, &ps[i].y);
		ps[i].id = i;
		ps[i].p = -1;
	}
	char buff[10];
	int a, b;
	int rps[1100];
	int rpn = 0;
	srand(time(NULL));
	while (scanf("%s", buff) != -1)
	{
		if (buff[0] == 'O')
		{
			scanf("%d", &a);
			for (int i = 0; i < rpn; ++i)
			{
				if (idist(rps[i], a) <= D)
				{
					imerge(rps[i], a);
				}
			}
			rps[rpn] = a;
			rpn += 1;
		}
		else
		{
			scanf("%d%d", &a, &b);
			if (iparent(a) == iparent(b))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	return 0;
}