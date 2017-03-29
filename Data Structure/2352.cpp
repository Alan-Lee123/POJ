#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

struct treeVec
{
	int vals[33000];
	treeVec()
	{
		memset(vals, 0, sizeof(vals));
	}
	int low_bit(int x)
	{
		return x & -x;
	}
	int sum(int x)
	{
		int tot = 0;
		for (int i = x; i > 0; i -= low_bit(i))
			tot += vals[i];
		return tot;
	}
	void add(int x, int v)
	{
		for (int i = x; i <= 33000; i += low_bit(i))
			vals[i] += v;
	}
};

int nums[16000];
treeVec tv;



int main()
{
	int N;
	scanf("%d", &N);
	memset(tv.vals, 0, sizeof(tv.vals));
	int x, y;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", &x, &y);
		nums[tv.sum(x + 1)] += 1;
		tv.add(x + 1, 1);
	}
	for (int i = 0; i < N; ++i)
		printf("%d\n", nums[i]);
	return 0;
}