#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	set <int> S;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;

		S.insert(x);
	}

	switch(S.size())
	{
		case 1: 
		case 2: printf("YES\n"); break;
		case 3: 
		{
			vector <int> A(S.begin(),S.end());
			if(A[0] + A[2] == 2*A[1])
				printf("YES\n");
			else
				printf("NO\n");
		}
		break;
		default: printf("NO\n");
	}
}