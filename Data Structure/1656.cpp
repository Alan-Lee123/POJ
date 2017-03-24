#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
bool board[100][100];

int main()
{
	int n;
	scanf("%d", &n);
	int x, y, l;
	char buff[10];
	string s;
	for (int kase = 0; kase < n; ++kase)
	{
		scanf("%s", buff);
		s = buff;
		scanf("%d%d%d", &x, &y, &l);
		--x, --y;
		if (s == "TEST")
		{
			int cnt = 0;
			for (int i = 0; i < l; ++i)
			{
				for (int j = 0; j < l; ++j)
				{
					cnt += board[x + i][y + j];
				}
			}
			printf("%d\n", cnt);
		}
		else if (s == "BLACK")
		{
			for (int i = 0; i < l; ++i)
			{
				for (int j = 0; j < l; ++j)
				{
					board[x + i][y + j] = true;
				}
			}
		}
		else if (s == "WHITE")
		{
			for (int i = 0; i < l; ++i)
			{
				for (int j = 0; j < l; ++j)
				{
					board[x + i][y + j] = false;
				}
			}
		}
		
	}
	return 0;

}