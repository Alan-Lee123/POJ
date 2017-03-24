#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct person
{
	int age, p, d;
	string name;
	bool operator < (const person& p) const
	{
		if (age != p.age)
			return age > p.age;
		else
			return name < p.name;
	}
};

person ps[110];


int get_parent(int x)
{
	int d = 0;
	while (ps[x].p != 0)
	{
		d += ps[x].d;
		x = ps[x].p;
	}
	return d;
}


int main()
{
	int T;
	scanf("%d", &T);
	char name1[100], name2[100];
	srand(time(NULL));
	for (int kase = 1; kase <= T; ++kase)
	{
		int n;
		scanf("%d", &n);
		map<string, int> mp;
		mp["Ted"] = 1;
		int cnt = 2;
		memset(ps, 0, sizeof(ps));
		for (int i = 0; i < n; ++i)
		{
			int d;
			scanf("%s%s%d", name1, name2, &d);
			if (!mp.count(name1))
				mp[name1] = cnt++;
			if (!mp.count(name2))
				mp[name2] = cnt++;
			ps[mp[name2]].p = mp[name1];
			ps[mp[name2]].d = d;
		}
		for (map<string, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
		{
			ps[iter->second].name = iter->first;
			int d = get_parent(iter->second);
			ps[iter->second].age = 100 - d;
		}

		sort(ps + 1, ps + cnt);

		printf("DATASET %d\n", kase);
		for (int i = 2; i < cnt; ++i)
		{
			printf("%s %d\n", ps[i].name.c_str(), ps[i].age);
		}
	}
	return 0;
}