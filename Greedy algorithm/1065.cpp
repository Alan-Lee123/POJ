#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct line
{
	int x, y;
	bool operator < (const line& l) const
	{
		if (y == l.y)
			return x > l.x;
		else
			return y > l.y;
	}
};

bool icmp(line& l1, line& l2)
{
	if (l1.x == l2.x)
		return l1.y < l2.y;
	else
		return l1.x < l2.x;
}

line ls[5100];
set<line> st;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d%d", &ls[i].x, &ls[i].y);
		sort(ls, ls + N, icmp);
		st.clear();
		st.insert(ls[0]);
		for (int i = 1; i < N; ++i)
		{
			set<line>::iterator iter = st.lower_bound(ls[i]);
			if (iter != st.end())
				st.erase(*iter);
			st.insert(ls[i]);
		}
		printf("%d\n", (int)st.size());
	}
	return 0;
}