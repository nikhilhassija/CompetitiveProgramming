#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long int x,n,sum=0;
	cin>>n;
	x = n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)*(n-6);
	sum += x/5040;
	x /= n-6;
	sum += x/720;
	x /= n-5;
	sum += x/120;
	// cout<<x<<endl;
	cout<<sum<<endl;
}