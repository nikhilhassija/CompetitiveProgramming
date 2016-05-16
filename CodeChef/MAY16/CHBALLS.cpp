#include <bits/stdc++.h>

using namespace std;

int main()
{
	cout<<"1\n3 1 1 2\n3 3 3 4\n";
	fflush(stdout);

	int x;
	cin>>x;

	cout<<2<<endl;
	switch(x)
	{
		case 2 : cout<<1<<endl; break;
		case 1 : cout<<2<<endl; break;
		case -2: cout<<3<<endl; break;
		case -1: cout<<4<<endl; break;
		case 0 : cout<<5<<endl; break;
	}	
}