#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
using namespace std;


vector<int> ps1;
vector<int> ps2;


int my_search(int v)
{
	int n = ps1.size();
	int cnt = 0;
	for (int i = 0, j = n - 1; i < n && j >= 0;)
	{
		int t = ps1[i] + ps2[j];
		if (t < v)
			++i;
		else if (t > v)
			--j;
		else
		{
			int a = 1, b = 1;
			for (; i < n - a && ps1[i] == ps1[i + a]; ++a);
			for (; j < n - b && ps2[j] == ps2[j - b]; ++b);
			cnt += a * b;
			i += a;
			j -= b;
		}
	}
	return cnt;
}

inline int pow3(int x)
{
	return x * x * x;
}

int main()
{
	int a1, a2, a3, a4, a5;
	scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
	int L = 100;
	ps1 = vector<int>(L * L, 0);
	ps2 = vector<int>(L * L, 0);
	vector<int> x3(L, 0);
	for (int i = 0; i < 50; ++i)
		x3[i] = pow3(i - 50);
	for (int i = 0; i < 50; ++i)
		x3[i + 50] = pow3(i + 1);
	for (int i = 0; i < L; ++i)
	{
		for (int j = 0; j < L; ++j)
		{
			int t = i * L + j;
			ps1[t] = a1 * x3[i] + a2 * x3[j];
			ps2[t] = a3 * x3[i] + a4 * x3[j];
		}
	}
	sort(ps1.begin(), ps1.end());
	sort(ps2.begin(), ps2.end());
	int cnt = 0;
	for (int i = 0; i < L; ++i)
		cnt += my_search(-a5 * x3[i]);
	printf("%d\n", cnt);
	return 0;
}