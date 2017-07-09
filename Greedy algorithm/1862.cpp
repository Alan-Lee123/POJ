#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>
#include <stack>

using namespace std;

int main()
{
	int n;
	priority_queue<double> st;
	scanf("%d", &n);
	int v;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v);
		st.push(v);
	}
	double cost = 0;
	while (st.size() > 1)
	{
		double x = st.top();
		st.pop();
		double y = st.top();
		st.pop();
		double z = 2 * sqrt(x * y);
		st.push(z);
	}
	printf("%.3f\n", st.top());
	return 0;
}