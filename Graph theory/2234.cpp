#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) > 0)
	{
		int w = 0, x;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			w ^= x;
		}
		if (w == 0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}