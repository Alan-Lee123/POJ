#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int primes[20000];
int N;

void get_primes()
{
	primes[0] = 2, primes[1] = 3;
	int cur = 5, cnt = 2;
	for (int i = 5, j = 0; i < 100100; i += 2)
	{
		int st = (int)(sqrt(i * 1.0) + 1e-6);
		for (j = 0; primes[j] <= st; ++j)
		{
			if (i % primes[j] == 0)
				break;
		}
		if (primes[j] > st)
		{
			primes[cnt++] = i;
		}
	}
	N = cnt;
}

int isearch(int x, int y, int v)
{
	if (x == y - 1)
		return x;
	int mid = (x + y) / 2;
	if (primes[mid] == v)
		return mid;
	else if (primes[mid] < v)
		return isearch(mid, y, v);
	else
		return isearch(x, mid, v);
}

int main()
{
	int m, a, b;
	get_primes();
	while (true)
	{
		scanf("%d%d%d", &m, &a, &b);
		if (m == 0)
			break;
		int rv = (int)(sqrt(1. * b / a * m) + 1e-6);
		rv = min(rv, m / 2);
		int r = isearch(0, N, rv);
		int lv = primes[r] * a / b;
		int l = isearch(0, N, lv);
		while (primes[l] * b < primes[r] * a)
		{
			if (primes[l + 1] * primes[r] <= m)
				++l;
			else
				--r;
		}
		int ansv = primes[l] * primes[r], ansl = l, ansr = r;
		while (l <= r)
		{
			if (primes[l] * primes[r] > ansv)
			{
				ansv = primes[l] * primes[r];
				ansl = l, ansr = r;
			}
			++l;
			while (primes[l] * primes[r] > m)
				--r;
		}
		printf("%d %d\n", primes[ansl], primes[ansr]);
	}

	return 0;
}