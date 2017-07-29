#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <string>

using namespace std;

char buff[10000];

int main()
{
	int n = 0;
	while (fgets(buff, 10000, stdin) != NULL)
	{
		for (int i = 0; buff[i]; ++i)
		{
			if (buff[i] != '"')
				putchar(buff[i]);
			else
			{
				n ^= 1;
				if (n != 0)
				{
					printf("``");
				}
				else
					printf("\'\'");
			}
		}
	}
	return 0;
}