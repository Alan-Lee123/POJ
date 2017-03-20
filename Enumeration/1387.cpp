#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <string>

using namespace std;

int bitmap[220][220];
int M, N, R, C;

inline double iarea(int x1, int y1, int x2, int y2)
{
	return (bitmap[x2][y2] - bitmap[x1][y2] - bitmap[x2][y1] + bitmap[x1][y1]) * 1. / (x2 - x1) / (y2 - y1);
}


void solution(int* ret)
{
	int x1 = 0, y1 = 0, x2 = R, y2 = C;
	double v = iarea(0, 0, R, C) ;
	for (int i = 0; i <= M - R; ++i)
	{
		for (int j = 0; j <= N - C; ++j)
		{
			for (int k = i + R; k <= M; ++k)
			{
				for (int p = j + C; p <= N; ++p)
				{
					double a = iarea(i, j, k, p);
					if (a > v + 1e-6)
					{
						v = a;
						x1 = i, y1 = j, x2 = k, y2 = p;
					}
				}
			}
		}
	}
	ret[0] = x1 + 1, ret[1] = y1 + 1, ret[2] = x2, ret[3] = y2;
}

int main()
{
	while (true)
	{
		scanf("%d", &M);
		if (M == 0)
			break;
		scanf("%d%d%d", &N, &R, &C);
		memset(bitmap, 0, sizeof(bitmap));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int v;
				scanf("%d", &v);
				bitmap[i + 1][j + 1] = bitmap[i + 1][j] + bitmap[i][j + 1] - bitmap[i][j] + v;
			}
		}
		int ret[4];
		solution(ret);
		printf("%d %d %d %d\n", ret[0], ret[1], ret[2], ret[3]);
	}
	printf("*\n");
	return 0;
}