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

struct node
{
	int x;
	node* p;
};

node nodes[10010];
bool used[10010];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i <= N; ++i)
		{
			nodes[i].x = i;
			nodes[i].p = NULL;
			used[i] = 0;
		}
		int x, y;
		for (int i = 0; i < N - 1; ++i)
		{
			scanf("%d%d", &x, &y);
			nodes[y].p = &nodes[x];
		}
		scanf("%d%d", &x, &y);
		while (nodes[x].p != NULL)
		{
			used[x] = true;
			x = nodes[x].p->x;
		}
		used[x] = true;
		while (!used[y])
		{
			y = nodes[y].p->x;
		}
		printf("%d\n", y);
	}
	return 0;
}