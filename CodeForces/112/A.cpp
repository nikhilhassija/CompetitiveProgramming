#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string A,B;
	cin>>A>>B;
	transform(A.begin(),A.end(),A.begin(),::tolower);
	transform(B.begin(),B.end(),B.begin(),::tolower);
	// cout<<A<<endl<<B<<endl;
	if(A==B)
		cout<<"0"<<endl;
	else if(A>B)
		cout<<"1"<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}