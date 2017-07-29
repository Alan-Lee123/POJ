#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

priority_queue<long long> q;
vector<long long> nums;
set<long long> st;
int ps[4] = { 2, 3, 5, 7 };

int main()
{
	q.push(-1);
	while (nums.size() < 5842)
	{
		long long t = q.top();
		q.pop();
		nums.push_back(-t);
		for (int i = 0; i < 4; ++i)
		{
			long long x = t * ps[i];
			if (st.count(x))
				continue;
			q.push(x);
			st.insert(x);
		}
	}
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		int v = nums[n - 1];
		char *post[] = {
			"st",
			"nd",
			"rd"
		};
		if (n % 10 < 4 && n % 10 >= 1 && (n % 100 < 10 || n % 100 > 20))
		{
			printf("The %d%s humble number is %d.\n", n, post[n % 10 - 1], v);
		}
		else
		{
			printf("The %dth humble number is %d.\n", n, v);
		}
	}
	return 0;
}