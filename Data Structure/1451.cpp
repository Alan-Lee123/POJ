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

struct node
{
	int v;
	char c;
	int d;
	node *nexts[26];
	node *p;
	bool operator <(const node& y) const
	{
		return v < y.v;
	}
};

node nodes[2000];
int M;
priority_queue<node> candis;

char table[10][5] = {
	"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void insert(node* root, int v, char* s, int p)
{
	if (!s[p])
		return;
	root->v += v;
	if (root->nexts[s[p] - 'a'] == NULL)
	{
		root->nexts[s[p] - 'a'] = &nodes[M++];
		nodes[M - 1].p = root;
		nodes[M - 1].c = s[p];
		nodes[M - 1].d = root->d + 1;
	}
	insert(root->nexts[s[p] - 'a'], v, s, p + 1);
}

string istr(node* p)
{
	char s[200];
	int t = 0;
	while (p->p != NULL)
	{
		s[t++] = p->c;
		p = p->p;
	}
	s[t] = '\0';
	for (int i = 0; i < t / 2; ++i)
		swap(s[i], s[t - i - 1]);
	return s;
}

void solution(char* nums)
{
	candis = priority_queue<node>();
	candis.push(nodes[0]);
	int mx;
	vector<node*> rs;
	for (int i = 0; nums[i] != '1'; ++i)
	{
		mx = -1;
		rs.clear();
		while (!candis.empty())
		{
			node t = candis.top();
			if (t.d > i)
				break;
			candis.pop();
			int x = nums[t.d] - '0';
			for (int j = 0; table[x][j]; ++j)
			{
				node * o = t.nexts[table[x][j] - 'a'];
				if (o == NULL)
					continue;
				candis.push(*o);
				if (o->v < mx)
					continue;
				if (o->v > mx && t.d == i)
				{
					mx = o->v;
					rs.clear();
					rs.push_back(o);
				}
				else if (o->v == mx && t.d == i)
				{
					rs.push_back(o);
				}
			}
		}
		if (rs.empty())
		{
			printf("MANUALLY\n");
		}
		else
		{
			vector<string> ss(rs.size(), "");
			for (int j = 0, l = rs.size(); j < l; ++j)
				ss[j] = istr(rs[j]);
			string s = ss[0];
			for (int j = 1, l = ss.size(); j < l; ++j)
			{
				if (ss[j] < s)
					s = ss[j];
			}
			printf("%s\n", s.c_str());
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	char word[200];
	for (int kase = 1; kase <= T; ++kase)
	{
		memset(nodes, 0, sizeof(nodes));
		M = 1;
		node* root = &nodes[0];
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			int v;
			scanf("%s%d", word, &v);
			insert(root, v, word, 0);
		}
		printf("Scenario #%d:\n", kase);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", word);
			solution(word);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}