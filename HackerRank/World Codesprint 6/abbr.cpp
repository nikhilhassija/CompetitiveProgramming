#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string A,B;
		cin>>A;
		cin>>B;

		int i = 0;
		int j = 0;

		while(i < A.size() && j < B.size())
		{
			if(toupper(A[i]) == B[j])
				j++;
			else if(A[i] == toupper(A[i]))
				j = B.size() + 2;

			i++;	
		}

		if(i != A.size() && j == B.size())
			for(;i<A.size();i++)
				if(A[i] == toupper(A[i]))
					j = j + 2;

		if(j == B.size())
			printf("YES\n");
		else
			printf("NO\n");
	}
}