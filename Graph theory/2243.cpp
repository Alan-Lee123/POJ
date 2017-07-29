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

int dist[64][64];

int main()
{
	for (int i = 0; i < 64; ++i)
		for (int j = 0; j < 64; ++j)
			dist[i][j] = 64;
	for (int i = 0; i < 64; ++i)
		dist[i][i] = 0;
	for (int i = 0; i < 64; ++i)
	{
		int x = i / 8, y = i % 8;
		for (int k = -2; k < 3; ++k)
		{
			if (k == 0)
				continue;
			int t = 3 - abs(k);
			if (x + k >= 0 && x + k < 8 && y + t >= 0 && y + t < 8)
				dist[i][(x + k) * 8 + y + t] = 1;
			t = -t;
			if (x + k >= 0 && x + k < 8 && y + t >= 0 && y + t < 8)
				dist[i][(x + k) * 8 + y + t] = 1;
		}
	}
	for (int k = 0; k < 64; ++k)
	{
		for (int i = 0; i < 64; ++i)
		{
			for (int j = 0; j < 64; ++j)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	char s1[10], s2[10];
	while (scanf("%s%s", s1, s2) > 0)
	{
		int p1 = (s1[0] - 'a') * 8 + s1[1] - '1';
		int p2 = (s2[0] - 'a') * 8 + s2[1] - '1';
		printf("To get from %s to %s takes %d knight moves.\n", s1, s2, dist[p1][p2]);
	}
	return 0;
}