#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>

using namespace std;

struct point
{
	int v, step;
	point() {}
	point(int val, int st) : v(val), step(st) {}
};

int N, K, M;

queue<point> q;
int pre[1010];
int record[1010];

inline int ivalue(int x)
{
	return (x % K + K) % K;
}

string get_path(point p)
{
	char s[1010];
	int len = 0;
	for (int i = 0, cur = p.v; cur != -1; ++i, cur = pre[cur])
	{
		s[i] = record[cur];
		++len;
	}
	--len;
	for (int i = 0; i < len / 2; ++i)
		swap(s[i], s[len - 1 - i]);
	s[len] = '\0';
	return s;
}

point solution(int target)
{
	q = queue<point>();
	point start(ivalue(N), 0);
	q.push(start);
	memset(pre, 0, sizeof(pre));
	memset(record, 0, sizeof(record));
	pre[start.v] = -1;
	record[start.v] = '?';
	point p;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (!record[ivalue(p.v + M)])
		{
			point t(ivalue(p.v + M), p.step + 1);
			record[t.v] = '+';
			pre[t.v] = p.v;
			if (t.v == target) {p = t; break; }
			q.push(t);
			
		}
		if (!record[ivalue(p.v - M)])
		{
			point t(ivalue(p.v - M), p.step + 1);
			record[t.v] = '-';
			pre[t.v] = p.v;
			if (t.v == target) {p = t; break; }
			q.push(t);
		}
		if (!record[ivalue(p.v * M)])
		{
			point t(ivalue(p.v * M), p.step + 1);
			record[t.v] = '*';
			pre[t.v] = p.v;
			if (t.v == target) { p = t; break; }
			q.push(t);
		}
		if (p.step < 2)
		{
			int v = 0;
			if (p.step == 0)
				v = ivalue((N % M + M) % M);
			else
				v = 0;
			if ((p.step == 0 || record[p.v] == '*') && !record[v])
			{
				point t(v, p.step + 1);
				record[t.v] = '%';
				pre[t.v] = p.v;
				if (t.v == target) { p = t; break; }
				q.push(t);
			}
		}
	}
	return p;
}


int main()
{
	while (true)
	{
		scanf("%d%d%d", &N, &K, &M);
		if (N == 0 && K == 0 && M == 0)
			break;
		int target = ivalue(N + 1);
		string s;
		point ans = solution(target);
		if (ans.v == target)
			s = get_path(ans);
		if (ans.v == target)
			printf("%d\n%s\n", ans.step, s.c_str());
		else
			printf("0\n");
	}
	return 0;
}