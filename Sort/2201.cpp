#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
using namespace std;

struct point
{
	int x, y, no;
	point* left, *right, *parent;
};
struct record
{
	int no, l, r, p;
	bool operator< (const record& r) const
	{
		return no < r.no;
	}
};

vector<point> ps;

bool cmp1(const point& p1, const point& p2)
{
	return p1.x < p2.x;
}



void build_tree()
{
	sort(ps.begin(), ps.end(), cmp1);
	int n = ps.size();
	for (int i = 0; i < n - 1; ++i)
	{
		if (ps[i].y > ps[i + 1].y)
		{
			if (ps[i].parent == NULL)
			{
				ps[i].parent = &ps[i + 1];
				ps[i + 1].left = &ps[i];
			}
			else
			{
				point* cur = ps[i].parent;
				while (cur != NULL && cur->y > ps[i + 1].y)
					cur = cur->parent;
				if (cur != NULL)
				{
					point *temp = cur->right;
					temp->parent = &ps[i + 1];
					ps[i + 1].left = temp;
					ps[i + 1].parent = cur;
					cur->right = &ps[i + 1];
				}
				else
				{
					cur = &ps[i];
					while (cur->parent != NULL)
						cur = cur->parent;
					cur->parent = &ps[i + 1];
					ps[i + 1].left = cur;
				}
			}
		}
		else
		{
			ps[i].right = &ps[i + 1];
			ps[i + 1].parent = &ps[i];
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	ps = vector<point>(N, point());
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d", &ps[i].x, &ps[i].y);
		ps[i].no = i + 1;
	}
	
	build_tree();
	vector<record> rs = vector<record>(N, record());
	for (int i = 0; i < N; ++i)
	{
		if (ps[i].parent != NULL)
			rs[i].p = ps[i].parent->no;
		if (ps[i].left != NULL)
			rs[i].l = ps[i].left->no;
		if (ps[i].right != NULL)
			rs[i].r = ps[i].right->no;
		rs[i].no = ps[i].no;
	}
	sort(rs.begin(), rs.end());
	printf("YES\n");
	for (int i = 0; i < N; ++i)
	{
		printf("%d %d %d\n", rs[i].p, rs[i].l, rs[i].r);
	}
	return 0;
}