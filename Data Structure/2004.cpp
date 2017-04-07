#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

struct point
{
	int ws[26];
	bool operator <(const point& p) const
	{
		for (int i = 0; i < 26; ++i)
		{
			if (ws[i] != p.ws[i])
				return ws[i] < p.ws[i];
		}
		return false;
	}
};

point ps[10000];
string ss[10000];
map<point, int> mp;
int depths[10000];

int idepth(int x)
{
	if (depths[x])
		return depths[x];
	int d = 0;
	point p = ps[x];
	for (int i = 0; i < 26; ++i)
	{
		p.ws[i] += 1;
		if (mp.count(p))
		{
			int t = idepth(mp[p]);
			if (t > d)
				d = t;
		}
		p.ws[i] -= 1;
	}
	depths[x] = d + 1;
	return d + 1;
}

void iprint(int x, int d)
{
	printf("%s\n", ss[x].c_str());
	if (d == 1)
		return;
	point p = ps[x];
	for (int i = 0; i < 26; ++i)
	{
		p.ws[i] += 1;
		if (mp.count(p))
		{
			int t = depths[mp[p]];
			if (t == d - 1)
			{
				iprint(mp[p], d - 1);
				break;
			}
		}
		p.ws[i] -= 1;
	}
	return;
}

int main()
{
	char s[30];
	int n = 0;
	memset(ps, 0, sizeof(ps));
	while (scanf("%s", s) != -1)
	{
		for (int i = 0; s[i]; ++i)
			ps[n].ws[s[i] - 'a'] += 1;
		mp[ps[n]] = n;
		ss[n] = s;
		++n;
	}
	int d = 0, p;
	for (int i = 0; i < n; ++i)
	{
		int t = idepth(i);
		if (t > d)
		{
			d = t;
			p = i;
		}
	}
	iprint(p, d);
	return 0;
}

