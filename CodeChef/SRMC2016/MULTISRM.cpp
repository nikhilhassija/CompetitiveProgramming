#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int a,b;

	cin>>a>>b;

	vector <int> A;
	vector <int> B;
	vector <int> C;

	while(a)
	{
		A.push_back(a%10);
		a = a/10;
	}
	// reverse(A.begin(),A.end());

	while(b)
	{
		B.push_back(b%10);
		b = b/10;
	}
	// reverse(B.begin(),B.end());

	for(int i=0;i<31;i++)
		C.push_back(0);

	for(int i=0;i<B.size();i++)
		for(int j=0;j<A.size();j++)
			C[i+j] += B[i]*A[j];

	for(int i=0;i<30;i++)
	{
		C[i+1] += C[i]/10;
		C[i] = C[i]%10;
	}
	reverse(C.begin(),C.end());

	int f = 0;
	for(int i=0;i<31;i++)
	{
		if(C[i])
			f = 1;
		if(f)
			cout<<C[i];
	}
	cout<<endl;
}