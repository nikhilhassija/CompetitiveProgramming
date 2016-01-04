/*
ID: nikhil14
PROG: ride
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

bool oj = true;

int main()
{
	if(oj)
	{
		freopen("ride.in","r",stdin);
		freopen("ride.out","w",stdout);
	}
	string A,B;
	cin>>A>>B;
	int a=1,b=1;
	for(auto i:A)
	{
		a *= i-'A'+1;
		a %= 47;
	}
	for(auto i:B)
	{
		b *= i-'A'+1;
		b %= 47;
	}
	if(a==b)
		cout<<"GO"<<endl;
	else
		cout<<"STAY"<<endl;
}