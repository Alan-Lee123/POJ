#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int n;
	scanf("%d" , &n);
	vector<int> nums = vector<int>(n, 0);
	for (int i = 0; i < n; ++i)
		scanf("%d", &nums[i]);
	sort(nums.begin(), nums.end());
	char s[10];
	scanf("%s", s);
	int k ,x;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &x);
		printf("%d\n", nums[x - 1]);
	}
	return 0;

}