#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <string>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int ps[10010];

int main()
{
	int N, M;
	while (true)
	{
		scanf("%d%d", &N, &M);
		if (N == 0 && M == 0)
			break;
		memset(ps, 0, sizeof(ps));
		int p;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				scanf("%d", &p);
				++ps[p];
			}
		}
		int mx = 0, sec = 0;
		for (int i = 0; i < 10010; ++i)
		{
			if (ps[i] > mx)
			{
				sec = mx;
				mx = ps[i];
			}
			else if (ps[i] > sec)
			{
				sec = ps[i];
			}
		}
		for (int i = 0; i < 10010; ++i)
		{
			if (ps[i] == sec)
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}