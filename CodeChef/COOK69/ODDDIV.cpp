#include <bits/stdc++.h>

using namespace std;

const int max_N = 1e5 + 5;
long long int A[max_N];

void precomp();
long long int odddiv(int);

int main()
{
	precomp();	

	int t;
	cin>>t;

	while(t--)
	{
		int l,r;
		cin>>l>>r;
		cout<<(A[r]-A[l-1])<<endl;
	}
}

void precomp()
{
	long long int sum = 0; 
	for(int i=0;i<max_N;i++)
	{
		A[i] = odddiv(i);
	}

	for(int i=1;i<max_N;i++)
		A[i] += A[i-1];
}

long long int odddiv(int n)
{
	long long int sum = 0;
	int i;
	for(i=1;i*i<n;i++)
	{
		if(n%i == 0)
		{
			if(i%2)
				sum += i;
			if((n/i)%2)
				sum += n/i;			
		}
	}

	if(i*i == n && i%2)
		sum += i;

	return sum;
}