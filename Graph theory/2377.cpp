#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstdlib>
#include <queue>
using namespace std;

struct line
{
	int e, cost;
	line(){}
	line(int ee, int c): e(ee), cost(c){}
	bool operator <(const line& l) const
	{
		return cost < l.cost;
	}
};

vector<vector<line> >ls;

int max_tree(int N)
{
	set<int> used;
	priority_queue<line> pq;
	used.insert(0);
	int cost = 0;
	for (int i = 0; i < ls[0].size(); ++i)
		pq.push(ls[0][i]);
	while (used.size() < N && pq.size() > 0)
	{
		line l = pq.top();
		pq.pop();
		if (used.count(l.e))
			continue;
		used.insert(l.e);
		cost += l.cost;
		for (int i = 0; i < ls[l.e].size(); ++i)
		{
			if (!used.count(ls[l.e][i].e))
				pq.push(ls[l.e][i]);
		}
	}
	if (used.size() < N)
		return -1;
	else
		return cost;
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	ls = vector<vector<line> >(N, vector<line>());
	for (int i = 0; i < M; ++i)
	{
		int s, e, c;
		scanf("%d%d%d", &s, &e, &c);
		ls[s - 1].push_back(line(e - 1, c));
		ls[e - 1].push_back(line(s - 1, c));
	}
	int cost = max_tree(N);
	printf("%d\n", cost);
	return 0;
}