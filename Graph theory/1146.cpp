#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	char buff[100];
	while (true)
	{
		scanf("%s", buff);
		if (buff[0] == '#')
			break;
		string s = buff;
		bool r = next_permutation(s.begin(), s.end());
		if (r)
			printf("%s\n", s.c_str());
		else
			printf("No Successor\n");
	}
	return 0;
}