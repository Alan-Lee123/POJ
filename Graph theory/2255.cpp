#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void travel(char* pre, char* order, int n)
{
	if (n == 0)
	{
		return;
	}
	else if (pre[0] == order[0])
	{
		travel(pre + 1, order + 1, n - 1);
		putchar(pre[0]);
	}
	else
	{
		int t = 1;
		while (order[t] != pre[0]) ++t;
		travel(pre + 1, order, t);
		travel(pre + 1 + t, order + t + 1, n - 1 - t);
		putchar(order[t]);
	}
}

int main()
{
	char pre[30], order[30];
	while (scanf("%s%s", pre, order) > 0)
	{
		travel(pre, order, strlen(pre));
		printf("\n");
	}
	return 0;
}