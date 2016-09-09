#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	lli t;
	cin>>t;

	lli n = log2((t+2)/3);
	lli base = 3*(pow(2,n) - 1);
	lli counter = 3*pow(2,n);

	assert(base<t);

	while(base<t)
	{
		base++;
		counter--;
	}

	cout<<counter+1<<endl;
}