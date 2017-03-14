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
#include <cstdlib>
#include <ctime>

using namespace std;
vector<int> cows;

int find_pos(vector<int>& arr, int start, int end, int target)
{
	int i, j;
	if (start == end - 1)
		return arr[start];
	for (i = start + 1, j = end - 1; i <= j;)
	{
		if (arr[i] > arr[start])
		{
			swap(arr[i], arr[j]);
			--j;
		}
		else
			++i;
	}
	swap(arr[start], arr[j]);
	if (j == target)
		return arr[j];
	else if (j > target)
		return find_pos(arr, start, j, target);
	else
		return find_pos(arr, j + 1, end, target);
}

int main()
{
	int n;
	scanf("%d", &n);
	cows = vector<int>(n, 0);
	for (int i = 0; i < n; ++i)
		scanf("%d", &cows[i]);
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
		swap(cows[i], cows[rand() % n]);
	int ans = find_pos(cows, 0, n, n / 2);
	printf("%d\n", ans);
	return 0;
}