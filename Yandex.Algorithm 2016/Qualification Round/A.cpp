#include <bits/stdc++.h>

using namespace std;

int hdist(string, string);

int main()
{
	int n;
	cin>>n;

	string S[n];

	for(int i=0;i<n;i++)
		cin>>S[i];

	int D[n][n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			D[i][j] = hdist(S[i],S[j]);

	for(int i=0;i<n;i++)
	{
		int d = 0;
		for(int j=0;j<n;j++)
			d = max(d,D[i][j]);
		if(d == 1)
		{
			cout<<S[i]<<endl;
			return 0;
		}
	}	
}

int hdist(string A, string B)
{
	int d = 0;
	int n = A.size();
	for(int i=0;i<n;i++)
		if(A[i]-B[i])
			d++;
	
	return d;
}