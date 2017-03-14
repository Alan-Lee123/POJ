#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <queue>
using namespace std;

struct record
{
	int item, salepoint, num;
	bool operator <(const record& p) const
	{
		if (salepoint != p.salepoint)
			return salepoint < p.salepoint;
		else
			return item < p.item;
	}
};

vector<record> rs;

int main()
{
	int N;
	scanf("%d", &N);
	rs = vector<record>(N, record());
	for (int i = 0; i < N; ++i)
		scanf("%d%d%d", &rs[i].item, &rs[i].salepoint, &rs[i].num);
	sort(rs.begin(), rs.end());
	set<int> its;
	for (int i = 0; i < N; ++i)
	{
		if (!its.count(rs[i].item))
			its.insert(rs[i].item);
	}
	vector<int> items = vector<int>(its.begin(), its.end());
	sort(items.begin(), items.end());
	int itemnum = items.size();
	printf("-1");
	for (int i = 0; i < itemnum; ++i)
		printf(" %d", items[i]);
	printf("\n");
	printf("%d", rs[0].salepoint);
	int cnt = rs[0].num;
	int cur = 0;
	for (int i = 1; i < N; ++i)
	{
		if (rs[i].salepoint == rs[i - 1].salepoint)
		{
			if (rs[i].item == rs[i - 1].item)
				cnt += rs[i].num;
			else
			{
				while (items[cur] != rs[i - 1].item)
				{
					printf(" 0");
					++cur;
				}
				printf(" %d", cnt);
				cnt = rs[i].num;
				++cur;
			}
		}
		else
		{
			if (cnt != 0)
			{
				while (items[cur] != rs[i - 1].item)
				{
					printf(" 0");
					++cur;
				}
				printf(" %d", cnt);
				++cur;
			}
			while (cur != itemnum)
			{
				printf(" 0");
				++cur;
			}
			printf("\n%d", rs[i].salepoint);
			cnt = rs[i].num;
			cur = 0;
		}
	}
	if (cnt != 0)
	{
		while (items[cur] != rs[N - 1].item)
		{
			printf(" 0");
			++cur;
		}
		printf(" %d", cnt);
		++cur;
	}
	while (cur != itemnum)
	{
		printf(" 0");
		++cur;
	}
	printf("\n");
	return 0;
}