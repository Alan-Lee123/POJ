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

int nums[6000];
priority_queue<long long> pq;
set<long long> st;

int main()
{
	pq.push(-1);
	for (int i = 0; i < 5842;)
	{
		long long t = pq.top();
		pq.pop();
		if (st.count(t))
			continue;
		else
			st.insert(t);
		nums[++i] = -t;
		pq.push(t * 2);
		pq.push(t * 3);
		pq.push(t * 5);
		pq.push(t * 7);
	}
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		if (n % 10 == 1 && n % 100 != 11)
			printf("The %dst humble number is %d.\n", n, nums[n]);
		else if (n % 10 == 2 && n % 100 != 12)
			printf("The %dnd humble number is %d.\n", n, nums[n]);
		else if (n % 10 == 3 && n % 100 != 13)
			printf("The %drd humble number is %d.\n", n, nums[n]);
		else
			printf("The %dth humble number is %d.\n", n, nums[n]);
	}
	return 0;
}