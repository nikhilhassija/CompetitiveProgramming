#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string A;
	cin>>A;
	int x = 0;
	for(int i=0;i<A.size();i++)
		if(A[i]-'0')
			x++;
	cout<<min(x,(int)(A.size())-x);
	return 0;
}