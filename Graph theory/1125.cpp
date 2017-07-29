#include <iostream>
#include <string>
#include <cstring>

using namespace std;

unsigned int board[101][101];

int main()
{
	while (true)
	{
		int N;
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
				board[i][j] = -1;
			board[i][i] = 0;
		}
		for (int i = 1; i <= N; ++i)
		{
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; ++j)
			{
				int d, t;
				scanf("%d%d", &d, &t);
				board[i][d] = t;
			}
		}
		for (int k = 1; k <= N; ++k)
			for (int i = 1; i <= N; ++i)
				for (int j = 1; j <= N; ++j)
					if (board[i][k] != -1 && board[k][j] != -1 && board[i][j] > board[i][k] + board[k][j])
						board[i][j] = board[i][k] + board[k][j];
		unsigned int ans = -1;
		int p = 0;
		for (int i = 1; i <= N; ++i)
		{
			unsigned int t = 0;
			for (int j = 1; j <= N; ++j)
				if (t < board[i][j])
					t = board[i][j];
			if (t < ans)
			{
				ans = t;
				p = i;
			}
				
		}
		if (ans == -1)
			printf("disjoint\n");
		else
			printf("%d %u\n", p, ans);
	}
	return 0;
}