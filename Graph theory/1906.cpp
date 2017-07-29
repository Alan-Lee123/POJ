#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <stack>
#include <queue>

using namespace std;

const int maxn = 200;
struct bign {
	int len, s[maxn];

	bign() {
		memset(s, 0, sizeof(s));
		len = 1;
	}

	bign(int num) {
		*this = num;
	}

	bign(const char* num) {
		*this = num;
	}

	bign operator =(int num) { //直接以整数赋值
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}

	bign operator =(const char* num) { //以字符串赋值
		len = strlen(num);
		for (int i = 0; i < len; i++)
			s[i] = num[len - i - 1] - '0';
		return *this;
	}

	string str() const { //将bign转化成字符串
		string res = "";
		for (int i = 0; i < len; i++)
			res = (char)(s[i] + '0') + res;
		if (res == "")
			res = "0";
		return res;
	}

	bign operator +(const bign& b) const { //重载+号运算
		bign c;
		c.len = 0;
		for (int i = 0, g = 0; g || i < max(len, b.len); i++) {
			int x = g;
			if (i < len) x += s[i];
			if (i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;
	}

	void clean() { //去掉前到0
		while (len > 1 && !s[len - 1])
			len--;
	}

	bign operator *(const bign& b) { //重载*号运算
		bign c;
		c.len = len + b.len;
		for (int i = 0; i < len; i++)
			for (int j = 0; j < b.len; j++)
				c.s[i + j] += s[i] * b.s[j];
		for (int i = 0; i < c.len - 1; i++) {
			c.s[i + 1] += c.s[i] / 10;
			c.s[i] %= 10;
		}
		c.clean();
		return c;
	}

	bign operator -(const bign& b) { //重载-号运算
		bign c;
		c.len = 0;
		for (int i = 0, g = 0; i < len; i++) {
			int x = s[i] - g;
			if (i < b.len)
				x -= b.s[i];
			if (x >= 0)
				g = 0;
			else {
				g = 1;
				x += 10;
			}
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}

	bool operator <(const bign& b) const { //重载<号运算
		if (len != b.len)
			return len < b.len;
		for (int i = len - 1; i >= 0; i--)
			if (s[i] != b.s[i])
				return s[i] < b.s[i];
		return false;
	}

	bool operator >(const bign& b) const { //重载>号运算
		return b < *this;
	}

	bool operator <=(const bign& b) { //重载<=号运算
		return !(b > *this);
	}

	bool operator ==(const bign& b) { //重载>=号运算
		return !(b < *this) && !(*this < b);
	}

	bign operator +=(const bign& b) { //重载+=号运算
		*this = *this + b;
		return *this;
	}
};

bign ps[70];

int main()
{
	ps[0] = 1;
	for (int i = 1; i < 70; ++i)
		ps[i] = ps[i - 1] * 3;

	unsigned long long n;
	while (true)
	{
		scanf("%llu", &n);
		if (n == 0)
			break;
		n -= 1;
		vector<int> nums;
		int cnt = 0;
		while (n != 0)
		{
			if (n % 2 == 0)
			{
				n /= 2;
				++cnt;
			}
			else
			{
				n -= 1;
				nums.push_back(cnt);
			}
		}
		if (nums.size() == 0)
			printf("{ }\n");
		else
		{
			printf("{ %s", ps[nums[0]].str().c_str());
			for (int i = 1; i < nums.size(); ++i)
				printf(", %s", ps[nums[i]].str().c_str());
			printf(" }\n");
		}
	}
	return 0;
}