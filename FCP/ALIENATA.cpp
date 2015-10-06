#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t,n,i;
	int max_n = 1e8 +5;
	int mod = 1e9 + 7;
	vector <int> A(max_n);
	A[0] = 0;
	A[1] = 2;
	A[2] = 7;
	for(i=3;i<max_n;i++)
		A[i] = (A[i-1] + (A[i-2]*2))%mod;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<A[n]<<endl;
	}
	return 0;
}