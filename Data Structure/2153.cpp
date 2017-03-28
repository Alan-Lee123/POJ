#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

map<string, int> mp;

int main()
{
	int n;
	scanf("%d%*c", &n);
	char name[100];
	char lim[] = "Li Ming";
	for (int i = 0; i < n; ++i)
	{
		gets(name);
		mp[name] = 0;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int x;
			scanf("%d%*c", &x);
			gets(name);
			mp[name] += x;
		}
		int cnt = 0, v = mp[lim];
		for (map<string, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
		{
			if (iter->second > v)
				cnt++;
		}
		printf("%d\n", cnt + 1);
	}
	return 0;
}