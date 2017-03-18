#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

int record[21][21][21];
bool used[21][21][21];

int ifun(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return ifun(20, 20, 20);
	if (used[a][b][c])
		return record[a][b][c];
	if (a < b && b < c)
		record[a][b][c] = ifun(a, b, c - 1) + ifun(a, b - 1, c - 1) - ifun(a, b - 1, c);
	else
		record[a][b][c] = ifun(a - 1, b, c) + ifun(a - 1, b - 1, c) + ifun(a - 1, b, c - 1) - ifun(a - 1, b - 1, c - 1);
	used[a][b][c] = true;
	return record[a][b][c];
}

int main()
{
	memset(used, 0, sizeof(used));
	while (true)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1)
			break;
		int ans = ifun(a, b, c);
		printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
	}
	return 0;
}