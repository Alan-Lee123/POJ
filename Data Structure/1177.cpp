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

struct line
{
	int a, b, h;
	bool up;
	line() {}
	line(int a, int b, int h, bool u) : a(a), b(b), h(h), up(u) {}
	bool operator <(const line& l) const
	{
		if (h != l.h)
			return h < l.h;
		else
			return up > l.up;
	}
};

struct segment
{
	int x, y, cnt, cover;
	segment* left, *right;
};

segment segs[60100];
int M;


void build_tree(segment* root, int l, int r)
{
	root->x = l;
	root->y = r;
	root->cnt = 0;
	root->cover = 0;
	if (r - l == 1)
	{
		root->left = root->right = NULL;
	}
	else
	{
		int mid = (l + r) / 2;
		root->left = &segs[M++];
		root->right = &segs[M++];
		build_tree(root->left, l, mid);
		build_tree(root->right, mid, r);
	}
}

void insert(segment* root, int l, int r, int v)
{
	if (l == root->x && r == root->y)
	{
		root->cnt += v;
		if (root->cnt == 0)
		{
			if (root->left != NULL)
				root->cover = root->left->cover + root->right->cover;
			else
				root->cover = 0;
		}
			
		else
			root->cover = root->y - root->x;
	}
	else
	{
		int mid = (root->x + root->y) / 2;
		if (r <= mid)
			insert(root->left, l, r, v);
		else if (l >= mid)
			insert(root->right, l, r, v);
		else
		{
			insert(root->left, l, mid, v);
			insert(root->right, mid, r, v);
		}
		if (!root->cnt)
			root->cover = root->left->cover + root->right->cover;
	}
}

int ifind(segment* root, int l, int r)
{
	if (root->cnt)
		return r - l;
	if (l == root->x && r == root->y)
	{
		return root->cover;
	}
	else
	{
		int mid = (root->x + root->y) / 2;
		if (r <= mid)
			return ifind(root->left, l, r);
		else if (l >= mid)
			return ifind(root->right, l, r);
		else
		{
			int t = ifind(root->left, l, mid);
			t += ifind(root->right, mid, r);
			return t;
		}
	}
}


line rows[10000], cols[10000];
int N;

int solution(line* ls, int n)
{
	int r = 0;
	for (int i = 0; i < n; ++i)
	{
		if (ls[i].up)
		{
			r += ls[i].b - ls[i].a - ifind(&segs[0], ls[i].a, ls[i].b);
			insert(&segs[0], ls[i].a, ls[i].b, 1);
		}
		else
		{
			insert(&segs[0], ls[i].a, ls[i].b, -1);
			r += ls[i].b - ls[i].a - ifind(&segs[0], ls[i].a, ls[i].b);
		}
	}
	return r;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		rows[2 * i] = line(y1, y2, x1, true);
		rows[2 * i + 1] = line(y1, y2, x2, false);
		cols[2 * i] = line(x1, x2, y1, true);
		cols[2 * i + 1] = line(x1, x2, y2, false);
	}
	sort(rows, rows + 2 * N);
	sort(cols, cols + 2 * N);
	M = 1;
	build_tree(&segs[0], -10000, 10000);
	int ans = solution(rows, 2 * N);
	ans += solution(cols, 2 * N);
	printf("%d\n", ans);
	return 0;
}