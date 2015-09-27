#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int t,i,j;
	vector <int> X,Y;
	string A,B;
	cin>>t;
	while(t--)
	{
		cin>>A>>B;
		X.clear();
		Y.clear();
		X.resize(10,0);
		Y.resize(10,0);
		for(i=0;i<A.size();i++)
			X[A[i]-'0']++;
		for(i=0;i<B.size();i++)
			Y[B[i]-'0']++;
		for(i=0;i<10;i++)
			X[i] = min(X[i],Y[i]);
		for(i=9;i>=0;i--)
			for(j=0;j<X[i];j++)
				cout<<(char)(i+'0');
		cout<<endl;
	}
	return 0;
}