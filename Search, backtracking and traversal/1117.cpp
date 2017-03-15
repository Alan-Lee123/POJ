#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

struct point
{
	int x, y;
	point() {}
	point(int xx, int yy) : x(xx), y(yy) {}
	bool operator < (const point& p) const
	{
		return x < p.x;
	}
};

int get_bit(int x)
{
	int cnt = 1;
	x /= 10;
	while (x > 0)
	{
		++cnt;
		x /= 10;
	}
	return cnt;
}

int my_pow(int x, int y)
{
	int t = 1;
	while (y > 0)
	{
		t *= x;
		--y;
	}
	return t;
}

vector<point> solution(int cur)
{
	long long a = my_pow(10, cur);
	int b = 2;
	long long c = 11 * a;
	int b_end = a - 1;
	int c_end = N / c;
	vector<point> ans;
	if (c_end == 0)
	{
		if (N % 2 == 0)
		{
			ans.push_back(point(N % a / 2 + N / a * a, N % a / 2));
			if (N >= 2 * a && a >= 10)
				ans.push_back(point(ans[0].x - a + a / 2, ans[0].y + a / 2));
		}
			
		return ans;
	}
	for (int ta = 0; ta < 10; ++ta)
	{	
		int tb = 0, tc = c_end;
		while (tb <= b_end && tc > 0)
		{
			long long t = ta * a + tb * b + tc * c;
			if (t == N)
			{
				ans.push_back(point(ta * a + tb + tc * a * 10, tb + tc * a));
				tb += 1;
				tc -= 1;
			}
			else if (t < N)
			{
				tb += (N - t - 1) / b + 1;
			}
			else
			{
				tc -= (t - N - 1) / c + 1;
			}
		}
	}
	return ans;
}

void add_0_print(int x, int k)
{
	int b = get_bit(x);
	for (; b < k; ++b)
		printf("0");
	printf("%d", x);
}

int main()
{
	scanf("%d", &N);
	int B = get_bit(N);
	vector<point> ans;
	for (int i = 0; i < B; ++i)
	{
		vector<point> ret = solution(i);
		ans.insert(ans.begin(), ret.begin(), ret.end());
	}
	sort(ans.begin(), ans.end());
	int m = ans.size(), t = 1;
	for (int i = 1; i < m; ++i)
	{
		if (ans[i].x != ans[i - 1].x)
		{
			ans[t] = ans[i];
			++t;
		}
	}
	if (m != 0)
		m = t;
	ans = vector<point>(ans.begin(), ans.begin() + m);
	printf("%d\n", m);
	for (int i = 0; i < m; ++i)
	{
		printf("%d + ", ans[i].x);
		add_0_print(ans[i].y, get_bit(ans[i].x) - 1);
		printf(" = %d\n", N);
	}
	return 0;
}