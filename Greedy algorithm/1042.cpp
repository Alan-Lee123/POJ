#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int fs[30], ds[30], ts[30];
int fishs[30][200];
int getfish[30][200];

int main()
{
	int N, H;
	for(int kase = 0; ; ++kase)
	{
		scanf("%d", &N);
		if (N == 0)
			break;
		scanf("%d", &H);
		for (int i = 0; i < N; ++i)
			scanf("%d", &fs[i]);
		for (int i = 0; i < N; ++i)
			scanf("%d", &ds[i]);
		for (int i = 0; i < N - 1; ++i)
			scanf("%d", &ts[i]);
		int tot = H * 12;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j <= tot; ++j)
			{
				if (ds[i] > 0 && j > fs[i] / ds[i] + 1)
					getfish[i][j] = getfish[i][j - 1];
				else
					getfish[i][j] = j * fs[i] - (j - 1) * j / 2 * ds[i];
			}
		}
		
		for (int i = 0; i <= tot; ++i)
		{
			fishs[0][i] = getfish[0][i];
		}
		for (int i = 1; i < N; ++i)
		{
			tot -= ts[i - 1];
			for (int j = 0; j <= tot; ++j)
			{
				int mx = fishs[i - 1][j];
				for (int t = 1; t <= j; ++t)
				{
					mx = max(mx, getfish[i][t] + fishs[i - 1][j - t]);
				}
				fishs[i][j] = mx;
			}
		}
		tot = H * 12;
		int mxfishs = 0, farpool = 0;
		for (int i = 0; i < N && tot >= 0; ++i)
		{
			if (fishs[i][tot] > mxfishs)
			{
				mxfishs = fishs[i][tot];
				farpool = i;
			}
			tot -= ts[i];
		}

		int ms[30];
		for (int i = farpool + 1; i < N; ++i)
			ms[i] = 0;
		tot = H * 12;
		for (int i = 0; i < farpool; ++i)
			tot -= ts[i];
		for (int i = farpool, j = 0; i >= 0; --i)
		{
			if (i == 0)
				ms[i] = tot * 5;
			else
			{
				for (j = 0; j < tot; ++j)
				{
					if (getfish[i][j] + fishs[i - 1][tot - j] == fishs[i][tot])
						break;
				}
				ms[i] = j * 5;
				tot -= j;
			}
		}
		if (kase > 0)
			printf("\n");
		printf("%d", ms[0]);
		for (int i = 1; i < N; ++i)
		{
			printf(", %d", ms[i]);
		}
		printf("\nNumber of fish expected: %d\n", mxfishs);
	}
	return 0;
}