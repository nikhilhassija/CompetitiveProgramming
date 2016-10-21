#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n, m;
		cin >> n >> m;

		int flag = 0;

		if(n%6 == 0 || m%6 == 0)
			flag = 1;

		if(n%2 == 0 && m%3 == 0)
			flag = 1;

		if(m%2 == 0 && n%3 == 0)
			flag = 1;

		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
}