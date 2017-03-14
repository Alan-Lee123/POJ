#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

vector<string> readstrs()
{
	vector<string> ds;
	char temp[20];
	while (true)
	{
		scanf("%s", temp);
		if (string(temp) == "XXXXXX")
			break;
		ds.push_back(temp);
	}
	return ds;
}

string sortstr(string s)
{
	string cp = s;
	sort(cp.begin(), cp.begin() + cp.size());
	return cp;
}

int main()
{
	vector<string> ds = readstrs();
	vector<string> strs = readstrs();
	sort(ds.begin(), ds.end());
	map<string, vector<string> >mp;
	for (int i = 0; i < ds.size(); ++i)
		mp[sortstr(ds[i])].push_back(ds[i]);
	for (int i = 0; i < strs.size(); ++i)
	{
		string cur = sortstr(strs[i]);
		if (mp.count(cur))
		{
			vector<string>& ss = mp[cur];
			for (int j = 0; j < ss.size(); ++j)
				printf("%s\n", ss[j].c_str());
		}
		else
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
	return 0;


}