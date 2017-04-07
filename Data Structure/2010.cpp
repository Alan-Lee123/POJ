#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

struct cow
{
	int score, cost;
	bool operator <(const cow& c) const
	{
		return cost < c.cost;
	}
};

int N, C, F;
cow cows[100000];
int scores[100000];

bool icheck(int s)
{
	int l = 0, r = 0, half = N / 2;
	int tot = 0;
	vector<int> es;
	for (int i = 0; i < C && tot <= F; ++i)
	{
		if (cows[i].score < s && l < half)
		{
			l += 1;
			tot += cows[i].cost;
		}
		else if (cows[i].score >= s)
		{
			r += 1;
			tot += cows[i].cost;
		}
		if (l + r == N)
			break;
	}
	return tot <= F && (l + r == N);
}

int bisearch(int x, int y)
{
	if (x == y - 1)
		return x;
	int mid = (x + y) / 2;
	if (icheck(scores[mid]))
		return bisearch(mid, y);
	else
		return bisearch(x, mid);
}

int main()
{
	scanf("%d%d%d", &N, &C, &F);
	for (int i = 0; i < C; ++i)
	{
		scanf("%d%d", &cows[i].score, &cows[i].cost);
		scores[i] = cows[i].score;
	}
	sort(cows, cows + C);
	sort(scores, scores + C);
	int r = bisearch(0, C);
	if (r == 0 && !icheck(r))
		printf("%d\n", -1);
	else
		printf("%d\n", scores[r]);
	return 0;
}
