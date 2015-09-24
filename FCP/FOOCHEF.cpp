#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,l,b,h,a;
	cin>>t;
	while(t--)
	{
		cin>>l>>b>>h>>a;
		cout<<(l/a)*(b/a)*(h/a)<<endl;
	}
}