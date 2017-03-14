#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	char s[200];
	char t[200];
	scanf("%s%s", s, t);
	if (strlen(s) != strlen(t))
	{
		printf("NO\n");
		return 0;
	}
	vector<int> mp1(26, 0);
	vector<int> mp2(26, 0);
	for (int i = 0; s[i]; ++i)
	{
		mp1[s[i] - 'A']++;
		mp2[t[i] - 'A']++;
	}
	sort(mp1.begin(), mp1.end());
	sort(mp2.begin(), mp2.end());
	for (int i = 0; i < 26; ++i)
		if (mp1[i] != mp2[i])
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}