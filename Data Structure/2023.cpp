#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

struct line
{
	char type;
	string s;
	int choices[2];
	bool happy;
};

line ls[110];
int N;
vector<int> ans;
bool used[110];

bool dfs(int cur)
{
	if (ls[cur].type == 'E')
	{
		if (ls[cur].happy)
			ans.push_back(cur);
		return ls[cur].happy;
	}
	if (used[cur])
		return false;
	used[cur] = true;
	ans.push_back(cur);
	bool r = dfs(ls[cur].choices[0]);
	if (r) return true;
	r = dfs(ls[cur].choices[1]);
	if (r) return true;
	ans.pop_back();
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	char buff[300];
	const string happy = "HAPPY";
	const string grisly = "GRISLY";
	for (int kase = 1; kase <= T; ++kase)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%s", buff);
			ls[i].type = buff[0];
			while (getchar() != '"');
			for (int k = 0;; ++k)
			{
				buff[k] = getchar();
				if (buff[k] == '"')
				{
					buff[k] = '\0';
					ls[i].s = buff;
					break;
				}
			}
			if (ls[i].type == 'C')
			{
				scanf("%d%d", &ls[i].choices[0], &ls[i].choices[1]);
			}
			else
			{
				scanf("%s", buff);
				if (happy == buff)
					ls[i].happy = true;
				else
					ls[i].happy = false;
			}
		}
		ans = vector<int>();
		memset(used, 0, sizeof(used));
		dfs(1);
		printf("STORY %d\n", kase);
		for (int i = 0, l = ans.size(); i < l; ++i)
			printf("%s\n", ls[ans[i]].s.c_str());
	}
	return 0;
}