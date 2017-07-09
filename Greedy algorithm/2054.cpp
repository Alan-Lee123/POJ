#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>
#include <stack>

using namespace std;

struct node
{
	int c, p, t;
	double avg;
};

node ns[1010];

int main()
{
	while (true)
	{
		int N, R;
		scanf("%d%d", &N, &R);
		if (N == 0 && R == 0)
			break;
		long long ans = 0;
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", &ns[i].c);
			ns[i].t = 1;
			ns[i].avg = ns[i].c;
			ans += ns[i].c;
		}
		for (int i = 0; i < N - 1; ++i)
		{
			int f, s;
			scanf("%d%d", &f, &s);
			ns[s].p = f;
		}
		for (int i = 0; i < N - 1; ++i)
		{
			int pos = 0;
			double w = 0;
			for (int j = 1; j <= N; ++j)
			{
				if (ns[j].avg > w && j != R)
				{
					w = ns[j].avg;
					pos = j;
				}
			}
			int p = ns[pos].p;
			ans += ns[pos].c * ns[p].t;
			ns[p].c += ns[pos].c;
			ns[p].t += ns[pos].t;
			ns[p].avg = ns[p].c * 1.0 / ns[p].t;
			for (int j = 1; j <= N; ++j)
			{
				if (ns[j].p == pos)
					ns[j].p = p;
			}
			ns[pos].avg = 0;
		}
		printf("%lld\n", ans);
	}
	return 0;
}