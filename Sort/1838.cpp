#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
using namespace std;

struct point
{
	int x, y;
	bool used;
	point():x(0), y(0), used(false){}
};

vector<point> ps;
map<int, point*> mp;
const int M = 10010;

void dye(point* p, int& cnt)
{
	if (p->used)
		return;
	cnt += 1;
	p->used = true;
	if (mp.count((p->x - 1) * M + p->y))
		dye(mp[(p->x - 1) * M + p->y], cnt);
	if (mp.count((p->x + 1) * M + p->y))
		dye(mp[(p->x + 1) * M + p->y], cnt);
	if (mp.count(p->x * M + p->y - 1))
		dye(mp[p->x * M + p->y - 1], cnt);
	if (mp.count(p->x * M + p->y + 1))
		dye(mp[p->x * M + p->y + 1], cnt);
}

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	ps = vector<point>(N, point());
	for (int i = 0; i < N; ++i)
		scanf("%d%d", &ps[i].x, &ps[i].y);
	for (int i = 0; i < N; ++i)
		mp[ps[i].x * M + ps[i].y] = &ps[i];
	int cnt = 0;
	vector<int> regions;
	for (int i = 0; i < N; ++i)
	{
		if (ps[i].used == false)
		{
			cnt = 0;
			dye(&ps[i], cnt);
			regions.push_back(cnt);
		}
	}
	sort(regions.begin(), regions.end());
	int ret = 0, r = regions.size();
	for (int i = 0; i < K && i < r; ++i)
		ret += regions[r - i - 1];
	printf("%d\n", ret);
	return 0;
}