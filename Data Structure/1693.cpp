#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

struct segment
{
	int x, y;
	vector<int> hs;
	segment *l, *r;
};

struct line
{
	int x, y, h;
	line() {}
	line(int x, int y, int h) : x(x), y(y), h(h) {}
	bool operator <(const line& l) const
	{
		return h < l.h;
	}
};

segment segs[10000];
line ls[200];
map<int, vector<int> > mp;
int M;

void build_tree(segment* root, int x, int y)
{
	root->x = x, root->y = y;
	root->hs.clear();
	if (x == y - 1)
		return;
	root->l = &segs[++M];
	root->r = &segs[++M];
	build_tree(root->l, x, (x + y) / 2);
	build_tree(root->r, (x + y) / 2, y);
}

void insert(segment* root, int x, int y, int h)
{
	if (root->x == x && root->y == y)
	{
		root->hs.push_back(h);
		return;
	}
	else
	{
		int mid = (root->x + root->y) / 2;
		if (y <= mid)
			insert(root->l, x, y, h);
		else if (x >= mid)
			insert(root->r, x, y, h);
		else
		{
			insert(root->l, x, mid, h);
			insert(root->r, mid, y, h);
		}
	}
}

vector<int> iseek(segment* root, int x, int y)
{
	vector<int> ret;
	if (root->hs.size())
		ret = root->hs;
	if (x == root->x && y == root->y)
		return ret;
	int mid = (root->x + root->y) / 2;
	if (y <= mid)
	{
		vector<int> r = iseek(root->l, x, y);
		ret.insert(ret.begin(), r.begin(), r.end());
	}
	else if (x >= mid)
	{
		vector<int> r = iseek(root->r, x, y);
		ret.insert(ret.begin(), r.begin(), r.end());
	}
	else
	{
		vector<int> l = iseek(root->l, x, mid);
		vector<int> r = iseek(root->r, mid, y);
		sort(l.begin(), l.end());
		sort(r.begin(), r.end());
		for (int i = 0, j = 0; i < l.size() && j < r.size();)
		{
			if (l[i] < r[j])
				++i;
			else if (l[i] > r[j])
				++j;
			else
			{
				ret.push_back(l[i]);
				++i, ++j;
			}
		}
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		M = 0;
		segment* root = &segs[0];
		build_tree(root, -100, 1100);
		int n, x1, y1, x2, y2, nrow = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x1 == x2)
				insert(root, min(y1, y2), max(y1, y2), x1);
			else
				ls[nrow++] = line(min(x1, x2), max(x1, x2), y1);
		}
		sort(ls, ls + nrow);
		mp.clear();
		int mx = 2000;
		int ans = 0;
		for (int i = 0; i < nrow; ++i)
		{
			for (int j = i + 1; j < nrow; ++j)
			{
				if (ls[i].y <= ls[j].x || ls[i].x >= ls[j].y || ls[i].h == ls[j].h)
					continue;
				int x = max(ls[i].x, ls[j].x);
				int y = min(ls[i].y, ls[j].y);
				int idx = ls[i].h * mx + ls[j].h;
				if (!mp.count(idx))
				{
					mp[idx] = iseek(root, ls[i].h, ls[j].h);
				}
					
				vector<int> &vec = mp[idx];
				int cnt = 0;
				for (int k = 0, len = vec.size(); k < len; ++k)
				{
					if (vec[k] >= x && vec[k] <= y)
						++cnt;
				}
				ans += cnt * (cnt - 1) / 2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}