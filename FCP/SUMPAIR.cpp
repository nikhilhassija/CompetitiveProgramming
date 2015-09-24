#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n,a,l,r;
	vector <int> A;
	cin>>n>>a;
	l = 0;
	r = n-1;
	A.resize(n);
	while(n--)
		cin>>A[r-n];
	while(l<r)
	{
		if(A[l]+A[r]==a)
		{
			cout<<l<<' '<<r<<' '<<A[l]<<' '<<A[r];
			return 0;
		}
		else if(A[l]+A[r]>a)
			r--;
		else
			l++;
	}
	cout<<"NO";
	return 0;
}