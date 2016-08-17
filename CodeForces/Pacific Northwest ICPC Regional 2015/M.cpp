#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A[101];
	for(int i=0;i<=100;i++)
		A[i] = i;

	int n;
	cin>>n;

	int C[101];
	memset(C,0,sizeof(C));

	while(n--)
	{
		string S;
		int x;

		cin>>S>>x;

		if(S == "ADD")
			for(int i=0;i<=100;i++)
				if(C[i] == 0)
					A[i] += x;

		if(S == "MULTIPLY")
			for(int i=0;i<=100;i++)
				if(C[i] == 0)
					A[i] *= x;

		if(S == "SUBTRACT")
			for(int i=0;i<=100;i++)
				if(C[i] == 0)
				{
					A[i] -= x;
					if(A[i]<0)
						C[i] = 1;
				}

		if(S == "DIVIDE")
			for(int i=0;i<=100;i++)
				if(C[i] == 0)
				{
					A[i] = (A[i]%x)?-1:A[i]/x;
					if(A[i]<0)
						C[i] = 1;
				}
	}

	int ans = 0;
	for(int i=1;i<=100;i++)
		ans += C[i];

	cout<<ans<<endl;
}