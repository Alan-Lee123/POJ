#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long h2n[100];
long long h2tn[100];

string getTree(int n, int h)
{
	if (h == 1)
		return "X";
	char ans[100];
	if (n <= h2n[h - 1])
	{
		string r = getTree(n, h - 1);
		sprintf(ans, "X(%s)", r.c_str());
	}
	else
	{
		int m = n - h2n[h - 1];
		int k;
		for (k = 1; k < h - 1; ++k)
		{
			if (m > h2n[k] * h2n[h - 1 - k])
				m -= h2n[k] * h2n[h - 1 - k];
			else
				break;
		}
		if (k < h - 1)
		{
			string l = getTree((m - 1) / h2n[h - 1 - k] + 1, k);
			string r = getTree((m - 1) % h2n[h - 1 - k] + 1, h - 1 - k);
			sprintf(ans, "(%s)X(%s)", l.c_str(), r.c_str());
		}
		else
		{
			string l = getTree(m, k);
			sprintf(ans, "(%s)X", l.c_str());
		}
	}
	return ans;
}

int main()
{
	h2n[0] = h2n[1] = 1;
	h2tn[0] = 0, h2tn[1] = 1;
	for (int k = 2; ; ++k)
	{
		h2n[k] = 0;
		for (int i = 0; i <= k - 1; ++ i)
			h2n[k] += h2n[i] * h2n[k - 1 - i];
		h2tn[k] = h2n[k] + h2tn[k - 1];
		if (h2tn[k] > 500000000)
			break;
	}
	int n;
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		int h = 0;
		for (; h2tn[h] < n; ++h);
		string ans = getTree(n - h2tn[h - 1], h);
		printf("%s\n", ans.c_str());
	}
	return 0;
}