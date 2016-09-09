#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n;
	cin>>n;

	while(n--)
	{
		string S;
		cin>>S;

		int A[300];
		memset(A,0,sizeof(A));

		int p = 0;
		for(char s:S)
		{
			if(A[s] == 0)
			{
				A[s] = 1;
				p++;
			}
		}

		printf("%d\n",p);	
	}
}