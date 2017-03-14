#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <string>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
vector<int> cows;

int main()
{
	int n;
	scanf("%d", &n);
	cows = vector<int>(n, 0);
	for (int i = 0; i < n; ++i)
		scanf("%d", &cows[i]);
	sort(cows.begin(), cows.end());
	long long cnt = 0;
	long long pre = cows[0];
	for (int i = 1; i < n; ++i)
	{
		cnt += (i * (long long)cows[i] - pre);
		pre += cows[i];
	}
	printf("%lld\n", cnt * 2);
	return 0;
}