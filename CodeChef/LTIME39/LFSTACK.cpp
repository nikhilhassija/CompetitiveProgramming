#include <bits/stdc++.h>

using namespace std;

int n;

vector <vector <int>> A;
vector <int> L,R;
vector <int> S;

int solve(int);

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		cin>>n;

		A.resize(n);
		L.resize(n);
		R.resize(n);

		int s_sz = 0;
		for(int i=0;i<n;i++)
		{
			L[i] = 0;
			cin>>R[i];
			s_sz += R[i];

			A[i].resize(R[i]);
			for(int j=0;j<R[i];j++)
				cin>>A[i][j];
		}

		S.resize(s_sz);
		for(int i=1;i<=s_sz;i++)
			cin>>S[s_sz-i];

		if(n == 1)
		{
			int f = 1;
			for(int i=0;i<R[0] && f;i++)
				if(A[0][i] != S[i])
					f = 0;

			if(f)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
		{
			if(solve(0))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}	
}

int solve(int sptr)
{
	if(sptr == S.size())
		return 1;

	int f = 0;

	for(int i=0;i<n;i++)
	{
		if(L[i] == R[i])
			continue;

		if(A[i][L[i]] == S[sptr])
		{
			L[i]++;
			f = f || solve(sptr+1);
			L[i]--;
		}
	}

	return f;
}