#include <bits/stdc++.h>

using namespace std;

int main()
{
	stack <int> S;

	int n;
	cin>>n;

	while(n--)
	{
		int x;
		cin>>x;
		S.push(x);
	}

	while(!S.empty())
	{
		printf("%d ",S.top());
		S.pop();
	}

	printf("\n");
}