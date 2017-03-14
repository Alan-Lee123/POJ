#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

void printAns(int kase, double h, double perc)
{
	printf("Region %d\n", kase);
	printf("Water level is %.2f meters.\n", h);
	printf("%.2f percent of the region is under water.\n", perc);
	printf("\n");
}

int main()
{
	for (int kase = 1;; ++kase)
	{
		int m, n, w;
		scanf("%d%d", &m, &n);
		if (m == 0 && n == 0)
			break;
		int N = m * n;
		vector<int> hs = vector<int>(N, 0);
		for (int i = 0; i < N; ++i)
			scanf("%d", &hs[i]);
		scanf("%d", &w);
		sort(hs.begin(), hs.end());
		double wh = hs[0];
		if (w == 0)
		{
			printAns(kase, 0, 0);
			continue;
		}
		int i, cnt = 0;
		for (i = 1; i < N; ++i)
		{
			if (hs[i] == hs[i - 1])
				continue;
			else
			{
				int h = hs[i] - hs[i - 1];
				if (w < i * h * 100)
				{
					wh += w / (i * 100.);
					break;
				}
				else
				{
					w -= i * h * 100;
					wh += h;
				}
			}
		}
		if (i == N)
		{
			wh += w / (i * 100.);
		}
		printAns(kase, wh, i * 100.0 / N);
	}
    
	return 0;
}