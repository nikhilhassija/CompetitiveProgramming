#include <bits/stdc++.h>

using namespace std;

long long int ncr(int n, int r)
{
	long long int res = 1;
	for(int i=0;i<r;i++)
		res *= (n-i);
	for(int i=0;i<r;i++)
		res /= i+1;
	return res;
}

int main()
{
	int n;
	cin>>n;
	cout<<ncr(n+4,5)*ncr(n+2,3)<<endl;
}