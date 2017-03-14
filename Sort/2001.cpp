#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <string>

using namespace std;

int my_cmp(string s1, string s2)
{
	int len = s1.size();
	int k = 0;
	while (k < len && s1[k] == s2[k])
		++k;
	return k;
}

int main()
{
	char buff[30];
	vector<string> ss;
	while (scanf("%s", buff) != -1)
		ss.push_back(buff);
	vector<string> cp = ss;
	map<string, string> mp;
	sort(ss.begin(), ss.end());
	int n = ss.size();
	int pre = 1;
	for (int i = 0; i < n - 1; ++i)
	{
		int t = my_cmp(ss[i], ss[i + 1]);
		if (t == ss[i].size())
		{
			mp[ss[i]] = ss[i];
		}
		else
		{
			mp[ss[i]] = string(ss[i].begin(), ss[i].begin() + max(t + 1, pre));
		}
		pre = t + 1;
	}
	mp[ss[n - 1]] = string(ss[n - 1].begin(), ss[n - 1].begin() + pre);
	for (int i = 0; i < n; ++i)
	{
		printf("%s %s\n", cp[i].c_str(), mp[cp[i]].c_str());
	}
	return 0;
}