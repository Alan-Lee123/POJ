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

#define MAX_NUM 0x7FFFFFFF

struct line
{
	int x, y, h;
	bool operator <(const line& l) const
	{
		return h > l.h;
	}
};

struct cost
{
	int xt, yt;
	cost() {}
	cost(int x, int y) : xt(x), yt(y) {}
};

struct segment
{
	int x, y, h, t;
	bool used;
	segment* left, *right;
};

segment segs[6100];
line ls[1100];
int M, N, MAX, num;
map<int, int> mp;
int nums[2100];

void build_tree(segment* root, int x, int y)
{
	root->x = x;
	root->y = y;
	root->h = MAX_NUM;
	root->used = false;
	if (y == x)
	{
		root->left = NULL;
		root->right = NULL;
		return;
	}
	int mid = (x + y) / 2;
	root->left = &segs[M++];
	root->right = &segs[M++];
	build_tree(root->left, x, mid);
	build_tree(root->right, mid + 1, y);
}

void update(segment* root, int x, int h, int t)
{
	root->h = h;
	if (x == root->x && x == root->y)
	{
		root->used = true;
		root->t = t;
	}
	else
	{
		int mid = (root->x + root->y) / 2;
		if (x <= mid)
			update(root->left, x, h, t);
		else
			update(root->right, x, h, t);
	}
}

void idelete(segment* root, int x, int y)
{
	if (root->h == MAX_NUM)
		return;
	if (root->x == root->y)
	{
		root->used = false;
		root->h = MAX_NUM;
	}
	else
	{
		int mid = (root->x + root->y) / 2;
		if (x > mid)
			idelete(root->right, x, y);
		else if (y <= mid)
			idelete(root->left, x, y);
		else
		{
			idelete(root->left, x, mid);
			idelete(root->right, mid + 1, y);
		}
		root->h = min(root->left->h, root->right->h);
	}
}

cost query(segment* root, int x, int y, int h)
{
	if (root->h - h > MAX)
		return cost(MAX_NUM, MAX_NUM);
	if (root->x == root->y)
	{
		if (root->used)
			return cost(root->t, root->t);
		else
			return cost(MAX_NUM, MAX_NUM);
	}
	else
	{
		int mid = (root->x + root->y) / 2;
		if (x > mid)
			return query(root->right, x, y, h);
		else if (y <= mid)
			return query(root->left, x, y, h);
		else
		{
			cost cl = query(root->left, x, mid, h);
			cost cr = query(root->right, mid + 1, y, h);
			if (cl.yt != MAX_NUM)
				cl.yt += nums[y] - nums[mid];
			if (cr.xt != MAX_NUM)
				cr.xt += nums[mid + 1] - nums[x];
			return cost(min(cl.xt, cr.xt), min(cl.yt, cr.yt));
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int x, y;
		scanf("%d%d%d%d", &N, &x, &y, &MAX);
		M = 1;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d%d%d", &ls[i].x, &ls[i].y, &ls[i].h);
			nums[2 * i] = ls[i].x;
			nums[2 * i + 1] = ls[i].y;
		}
		nums[2 * N] = x;
		sort(nums, nums + 2 * N + 1);
		num = 1;
		for (int i = 1; i < 2 * N + 1; ++i)
		{
			if (nums[i] != nums[i - 1])
				nums[num++] = nums[i];
		}
		mp = map<int, int>();
		for (int i = 0; i < num; ++i)
		{
			mp[nums[i]] = i;
		}
		for (int i = 0; i < N; ++i)
		{
			ls[i].x = mp[ls[i].x];
			ls[i].y = mp[ls[i].y];
		}
		x = mp[x];
		sort(ls, ls + N);
		segment* root = &segs[0];
		build_tree(root, 0, num);
		update(root, x, y, 0);
		for (int i = 0; i < N; ++i)
		{
			cost c = query(root, ls[i].x, ls[i].y, ls[i].h);
			idelete(root, ls[i].x, ls[i].y);
			if (c.xt != MAX_NUM)
				update(root, ls[i].x, ls[i].h, c.xt);
			if (c.yt != MAX_NUM)
				update(root, ls[i].y, ls[i].h, c.yt);
		}
		int ans = MAX_NUM;
		for (int i = 0; i < num; ++i)
		{
			cost c = query(root, i, i, 0);
			ans = min(ans, c.xt);
		}
		ans += y;
		printf("%d\n", ans);
	}
	return 0;
}