#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <set>

using namespace std;

double vs[10100];
int ts[10100];

int main()
{
	int N;
	const int L = 4500;
	while (true)
	{
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 0; i < N; ++i)
		{
			int v;
			scanf("%d%d", &v, &ts[i]);
			vs[i] = v * 1000. / 3600;
		}
		double t = 1e10;
		for (int i = 0; i < N; ++i)
		{
			if (ts[i] < 0)
				continue;
			double x = ts[i] + L / vs[i];
			if (x < t)
				t = x;
		}
		printf("%d\n", (int)ceil(t));
	}
	return 0;
}