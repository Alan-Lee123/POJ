#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <string>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

vector<string> ss;

int my_trans[26] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8 };

string clear_trans(string s)
{
	char t[100];
	int n = s.size();
	int cur = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] != '-')
		{
			if (s[i] >= '0' && s[i] <= '9')
				t[cur++] = s[i];
			else
				t[cur++] = my_trans[s[i] - 'A'] + '1';
		}
			
		if (cur == 3)
			t[cur++] = '-';
	}
	t[cur] = '\0';
	return t;
}

int main()
{
	int n;
	scanf("%d", &n);
	char s[100];
	ss = vector<string>(n, string());
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", &s);
		ss[i] = clear_trans(s);
	}
	sort(ss.begin(), ss.end());
	int cnt = 1;
	bool no_duplicate = true;
	for (int i = 1; i < n + 1; ++i)
	{
		if (i == n || ss[i] != ss[i - 1])
		{
			if (cnt > 1)
			{
				printf("%s %d\n", ss[i - 1].c_str(), cnt);
				cnt = 1;
				no_duplicate = false;
			}
		}
		else
		{
			++cnt;
		}
	}
	if (no_duplicate)
		printf("No duplicates.\n");
	return 0;
}