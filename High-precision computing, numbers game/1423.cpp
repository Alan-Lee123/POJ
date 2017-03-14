#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int m;
		scanf("%d", &m);
		double r = log10(sqrt(2 * acos(-1.0) * m)) + m * log10(m / exp(1.0)) + 1 / (12.0 * n) * log10(exp(1.0));
		printf("%d\n", (int)r + 1);
	}
	return 0;
}