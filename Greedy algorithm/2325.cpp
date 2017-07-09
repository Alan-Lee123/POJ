#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <string>

using namespace std;

string idiv(string s, int d, int& r)
{
	string ans = s;
	r = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		int x = r * 10 + s[i] - '0';
		ans[i] = x / d + '0';
		r = x % d;
	}
	if (ans[0] == '0' && ans.size() > 1)
		return ans.substr(1);
	return ans;
}

char str[1010];

int main()
{
	while (true)
	{
		scanf("%s", str);
		if (str[0] == '-')
			break;
		string s = str;
		if (s.size() == 1)
		{
			if (s == "0")
				printf("10\n");
			else
				printf("%s\n", ("1" + s).c_str());
			continue;
		}
		int r = 0;
		int nums[10] = {0};
		for (int i = 9; i > 1; --i)
		{
			int cnt = 0;
			while (s != "0")
			{
				string t = idiv(s, i, r);
				if (r != 0)
					break;
				else
				{
					s = t;
					cnt += 1;
				}
			}
			nums[i] = cnt;
		}
		if (s != "1")
		{
			printf("There is no such number.\n");
			continue;
		}
		string ans = "";
		for (int i = 2; i < 10; ++i)
			if(nums[i] > 0)
				ans += string(nums[i], i + '0');
		printf("%s\n", ans.c_str());
	}
	return 0;
}