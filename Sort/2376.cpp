#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
using namespace std;

struct line
{
	int x, y;
	bool operator <(const line& l) const
	{
		return x < l.x;
	}
};

vector<line> ls;

int main()
{
	int N, T;
	scanf("%d%d", &N, &T);
	ls = vector<line>(N, line());
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", &ls[i].x, &ls[i].y);
	}

	sort(ls.begin(), ls.end());
	int cur = 1, cnt = 0;
	for (int i = 0, j = 0; i < N; i = j)
	{
		int temp = cur - 1;
		
		for (j = i; j < N; ++j)
		{
			if (ls[j].x > cur)
				break;
			if (ls[j].y > temp)
				temp = ls[j].y;
		}
		if (temp < cur)
			break;
		cnt += 1;
		cur = temp + 1;
		if (cur > T)
			break;
	}
	if (cur <= T)
		printf("-1\n");
	else
		printf("%d\n", cnt);
	return 0;
}