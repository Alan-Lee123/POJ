#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <string>

using namespace std;

int N, M;
int C;
bool flag;
int pid;

void dfs(int i, int id)
{
	if (flag || i >= N)
		return;

	while (i < N && !flag)
	{
		if (C + 1 == M)
		{
			printf("Loop %d: Process ID=%d\n", i, id);
			flag = true;
			return;
		}
		pid += 1;
		if (C + 2 == M)
		{
			printf("Process ID=%d, A=%d\n", pid, (i + 1) * 7);
			flag = true;
			return;
		}
		C += 2;
		dfs(i + 1, pid);
		i += 1;
	}


}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &M);
		flag = false;
		C = 0;
		pid = 1000;
		dfs(0, 1000);
	}
	return 0;
}