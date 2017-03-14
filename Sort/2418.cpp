#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <string>

using namespace std;
map<string, int> mp;

int main()
{
	int tot = 0;
	char buff[100];
	while (true)
	{
		gets(buff);
		if (feof(stdin))
			break;
		if (buff == "")
			continue;
		if (mp.count(buff))
			mp[buff] += 1;
		else
			mp[buff] = 1;
		++tot;
	}
	for (map<string, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
	{
		printf("%s %.4lf\n", iter->first.c_str(), iter->second * 100.0 / tot);
	}
	return 0;
}