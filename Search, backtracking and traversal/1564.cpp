#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

set<string> mp;
vector<int> nums;
vector<string> strs;
int t, n;

string my_to_string(int x)
{
	char buff[10] = { 0 };
	sprintf(buff, "%d", x);
	return buff;
}

void my_search(int cur, int tot, string ns)
{
	for (int i = cur; i < n; ++i)
	{
		if (tot + nums[i] <= t)
		{
			string temp = ns;
			if (ns == "")
				temp = strs[i];
			else
				temp += "+" + strs[i];
			if (tot + nums[i] == t)
			{
				if (!mp.count(temp))
					mp.insert(temp);
			}
			else
				my_search(i + 1, tot + nums[i], temp);
		}
	}
}


int main()
{
	
	while (true)
	{
		scanf("%d%d", &t, &n);
		if (n == 0)
			break;
		mp.clear();
		nums = vector<int>(n, 0);
		strs = vector<string>(n, "");
		for (int i = 0; i < n; ++i)
			scanf("%d", &nums[i]);
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n / 2; ++i)
			swap(nums[i], nums[n - 1 - i]);
		for (int i = 0; i < n; ++i)
			strs[i] = my_to_string(nums[i]);
		my_search(0, 0, "");
		if (mp.empty())
		{
			printf("Sums of %d:\nNONE\n", t);
			continue;
		}
		set<string>::iterator iter = mp.end();
		--iter;
		printf("Sums of %d:\n", t);
		while (true)
		{
			printf("%s\n", (*iter).c_str());
			if (iter == mp.begin()) break;
			--iter;
		} 
	}
	return 0;
}