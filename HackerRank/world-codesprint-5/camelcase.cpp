#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;

	int c = 0;
	for(char s:S)
		if(isupper(s))
			c++;

	printf("%d\n",c+1);
}