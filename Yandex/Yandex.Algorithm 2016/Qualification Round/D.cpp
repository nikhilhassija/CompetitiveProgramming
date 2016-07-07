#include <bits/stdc++.h>

using namespace std;

long long int f(long long int x)
{
	printf("%lld --> ",x);
	vector <int> A;
	while(x)
	{
		A.push_back(x%2);
		x /= 2;
	}

	if(A.size() == 0)
		A.push_back(0);

	reverse(A.begin(),A.end());

	for(int i=0;i<A.size();i++)
		cout<<A[i];
	printf(" | ");

	vector <int> X;
	X.push_back(A[0]);
	for(int i=1;i<A.size();i++)
		if(A[i] != A[i-1])
			X.push_back(A[i]);

	for(int i=0;i<X.size();i++)
		cout<<X[i];
	printf(" | ");

	x = 0;
	for(int i=0;i<X.size();i++)
		x = x*2 + X[i];

	return x;
}

int main()
{
	int A[101];
	for(int i=0;i<101;i++)
	{
		A[i] = f(i);
		cout<<A[i]<<endl;
	}

	printf("\n");
	for(int i=1;i<101;i++)
	{
		A[i] += A[i-1];
		cout<<A[i]<<endl;
	}
}