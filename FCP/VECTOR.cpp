#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n);

int main()
{
	ios_base::sync_with_stdio(false);
	int t,n,x,y,z,i;
	cin>>t;
	while(t--)
	{
		x = 0;
		y = 0;
		z = 0;
		cin>>n;
		while(n--)
		{
			cin>>i;
			x += i;
			cin>>i;
			y += i;
			cin>>i;
			z += i;
		}
		if(is_prime(x) && is_prime(y) && is_prime(z))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

bool is_prime(int n)
{
	if( n == 2 || n == 3 ) 
		return true;
	if( n < 2 || n%2 == 0 ) 
		return false;
	if(n < 9) 
		return true;
	if(n%3 == 0) 
		return false;
	int r = sqrt(n);
	int f = 5;
	while(f <= r)
	{
		if(n%f == 0) 
			return false;
		if(n%(f+2) == 0) 
			return false;
		f +=6;
	}
	return true;
}