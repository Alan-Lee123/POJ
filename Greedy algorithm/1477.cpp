#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int n;
	for (int T = 1;; ++T)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		vector<int> hs(n, 0);
		for (int i = 0; i < n; ++i)
			scanf("%d", &hs[i]);
		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += hs[i];
		int avg = sum / n;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			if (hs[i] > avg)
				cnt += hs[i] - avg;
		}
		printf("Set #%d\n", T);
		printf("The minimum number of moves is %d.\n\n", cnt);
	}
	return 0;
}