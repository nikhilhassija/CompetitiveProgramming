#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t,n;
	double s;
	vector <int> A;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s = 0.0;
		A.clear();
		A.resize(n);
		for(int i=0;i<n;i++)
			cin>>A[i];
		for(int i=0;i<n;i++)
			s += A[i];
		s = s/2;
		cout.precision(2);
		cout<<fixed<<s<<endl;
	}
	return 0;
}