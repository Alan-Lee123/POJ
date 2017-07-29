#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

vector<vector<int> > lines;
int cs[26];
int N, M;

bool dfs(int cur)
{
	if (cur == N)
		return true;
	int len = lines[cur].size();
	for (int i = 0, j = 0; i < M; ++i)
	{
		for (j = 0; j < len; ++j)
		{
			if (cs[lines[cur][j]] == i)
				break;
		}
		if (j != len) continue;
		cs[cur] = i;
		bool ret = dfs(cur + 1);
		if (ret) return true;
	}
	return false;
}

int main()
{
	while (true)
	{
		scanf("%d", &N);
		if (N == 0)
			break;
		lines = vector<vector<int> >(N, vector<int>());
		char buff[50];
		int p = 0;
		for (int i = 0; i < N; ++i)
		{
			scanf("%s", buff);
			for (int j = 2; buff[j]; ++j)
			{
				lines[i].push_back(buff[j] - 'A');
			}
		}
		memset(cs, 0, sizeof(cs));
		if (N == 1)
		{
			printf("1 channel needed.\n");
			continue;
		}
		cs[0] = 0;
		for (M = 1; M < N; ++M)
		{
			if (dfs(1))
				break;
		}
		if(M == 1)
			printf("1 channel needed.\n");
		else
			printf("%d channels needed.\n", M);
	}
	return 0;
}