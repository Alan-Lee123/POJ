#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <string>

using namespace std;

#define X2(x) ((x) * (x))

vector<int> bases[16];

int get_color(vector<int> c)
{
	int m = 0x7FFFFFFF;
	int idx = 0;
	for (int i = 0; i < 16; ++i)
	{
		int d = X2(bases[i][0] - c[0]) + X2(bases[i][1] - c[1]) + X2(bases[i][2] - c[2]);
		if (d < m)
		{
			m = d;
			idx = i;
		}
	}
	return idx;
}

int main()
{
	vector<int> v(3, 0);
	int cnt = 0;
	while (true)
	{
		scanf("%d%d%d", &v[0], &v[1], &v[2]);
		if (v[0] == -1 && v[1] == -1 && v[2] == -1)
			break;
		if (cnt < 16)
		{
			bases[cnt] = v;
			++cnt;
		}
		else
		{
			int r = get_color(v);
			printf("(%d,%d,%d) maps to (%d,%d,%d)\n", v[0], v[1], v[2], bases[r][0], bases[r][1], bases[r][2]);
		}
	}
	return 0;
}