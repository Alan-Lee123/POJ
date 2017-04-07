#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

#define P 10000019

char str[100100];
int nums[26];
int K;
int used[P];

inline int ichar(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	else if (c >= 'A' && c <= 'Z')
		return c - 'A';
	else
		return -1;
}

string get_str(int x)
{
	int i = 0, cur = x;
	char s[100];
	while (i < K)
	{
		if (ichar(str[cur]) >= 0)
			s[i++] = 'a' + ichar(str[cur]);
		--cur;
	}
	s[i] = '\0';
	sort(s, s + i);
	return s;
}

int main()
{
	while (true)
	{
		scanf("%d%*c", &K);
		if (K == 0)
			break;
		gets(str);
		nums[0] = 1;
		for (int i = 1; i < 26; ++i)
			nums[i] = nums[i - 1] * (K + 1) % P;
		int idx = 0;
		int cur = 0;
		queue<int> q;
		for (int i = 0; i < K && str[idx]; ++idx)
		{
			int c = ichar(str[idx]);
			if (c >= 0)
			{
				cur = (cur + nums[c]) % P;
				q.push(c);
				++i;
			}
		}
		memset(used, -1, sizeof(used));
		used[cur] = idx - 1;
		set<string> hits;
		while (str[idx])
		{
			int c = ichar(str[idx]);
			if (c >= 0)
			{
				cur = (cur + nums[c] - nums[q.front()] + P) % P;
				if (used[cur] != -1)
				{
					hits.insert(get_str(used[cur]));
					if (hits.count(get_str(idx)))
						break;
				}
				used[cur] = idx;
				q.pop();
				q.push(c);
			}
			++idx;
		}
		printf("%d\n", idx);
	}
	return 0;
}