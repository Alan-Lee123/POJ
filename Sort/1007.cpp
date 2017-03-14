#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct dna
{
	int id;
	int order;
	dna():id(0), order(0){}
	dna(int i, int o):id(i), order(o){}
	bool operator<(const dna& d) const
	{
		return order == d.order ? id < d.id : order < d.order;
	}
};


int iorder(char *s)
{
	int letters[3] = {};
	int i, ans = 0;
	for(i = 0; s[i]; ++i)
	{
		if(s[i] == 'A')
			ans += letters[0] + letters[1] + letters[2];
		else if(s[i] == 'C')
		{
			letters[0]++;
			ans += letters[1] + letters[2];
		}
		else if(s[i] == 'G')
		{
			letters[1]++;
			ans += letters[2];
		}
		else
			letters[2]++;
	}
	return ans;
}

int main()
{
	int m, n, i;
	char strs[100][51];
	dna ds[100];
	scanf("%d%d",&n, &m);
    for(i = 0; i < m; ++i)
	{
		scanf("%s",strs[i]);
		ds[i].id = i;
		ds[i].order = iorder(strs[i]);
	}
	sort(ds, ds + m);
	for(i = 0; i < m; ++i)
	{
		printf("%s\n",strs[ds[i].id]);
	}
	return 0;
}
