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

char s[10000];
int N;
int target;

bool dfs(int& cur, int t)
{
	cur += 1;
	if (s[cur] == ')')
	{
		if (cur + 2 < N && s[cur + 2] == ')')
			return t == target;
		return  false;
	}
	int v;
	sscanf(s + cur, "%d", &v);
	while (s[cur] != '(')
		++cur;
	bool r = dfs(cur, t + v);
	if (r)
		return true;
	while (s[cur] != '(')
		++cur;
	return dfs(cur, t + v);
}

int main()
{
	while (scanf("%d", &target) != -1)
	{
		int len = 0, l = 0, r = 0;
		while (true)
		{
			scanf("%s", s + len);
			int t = strlen(s + len);
			for (int i = 0; i < t; ++i)
			{
				if (s[len + i] == '(')
					l += 1;
				else if (s[len + i] == ')')
					r += 1;
			}
			len += t;
			if (l == r)
			{
				s[len] = '\0';
				N = len;
				break;
			}
		}
		int cur = 0;
		if (N > 2 && dfs(cur, 0))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}