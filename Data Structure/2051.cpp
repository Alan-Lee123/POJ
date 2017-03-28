#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

struct query
{
	int num;
	int t;
	int inc;
	bool operator <(const query& q) const
	{
		if(t != q.t)
			return t > q.t;
		else
			return num > q.num;
	}
};

int main()
{
	char buff[10];
	priority_queue<query> pq;
	query q;
	while(true)
	{
		scanf("%s", buff);
		if(buff[0] == '#')
			break;
		scanf("%d%d", &q.num, &q.inc);
		q.t = qs.inc;
		pq.push(q);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		q = pq.front();
		pq.pop();
		printf("%d\n", q.num);
		q.t += q.inc;
		pq.push(q);
	}
	return 0;
}