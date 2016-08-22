#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	int n;
	cin>>n;

	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	sort(A,A+n);

	if(n%2)
		cout<<A[n/2];
	else
	{
		int pa = A[n/2 - 1];
		int pb = A[n/2];

		lli suma = 0;
		lli sumb = 0;
		for(int i=0;i<n;i++)
		{
			suma += abs(A[i]-pa);
			sumb += abs(A[i]-pb);
		}

		if(suma == min(suma,sumb))
			cout<<pa;
		else
			cout<<pb;
	}

	cout<<endl;
}