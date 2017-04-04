#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

long long nums[1501];
priority_queue<long long> pq;
set<long long> used;

int main()
{
	pq.push(-1);
	used.insert(-1);
	long long x3[3];
	for (int i = 1; i < 1501; ++i)
	{
		long long t = pq.top();
		pq.pop();
		nums[i] = -t;
		x3[0] = t * 2;
		x3[1] = t * 3;
		x3[2] = t * 5;
		for (int j = 0; j < 3; ++j)
		{
			if (!used.count(x3[j]))
			{
				used.insert(x3[j]);
				pq.push(x3[j]);
			}
		}
	}
	int x;
	while (true)
	{
		scanf("%d", &x);
		if (x == 0)
			break;
		printf("%d\n", nums[x]);
	}
	return 0;
}