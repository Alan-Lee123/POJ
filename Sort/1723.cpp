#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> xs = vector<int>(N, 0);
	vector<int> ys = vector<int>(N, 0);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", &xs[i], &ys[i]);
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	for (int i = 0; i < N; ++i)
		xs[i] -= i;
	sort(xs.begin(), xs.end());
	int cnt = 0;
	for (int i = 0; i < N / 2; ++i)
	{
		cnt += xs[N - i - 1] - xs[i];
		cnt += ys[N - i - 1] - ys[i];
	}
	printf("%d\n", cnt);
	return 0;
}