#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	long long int sum = 0;
	for(int i=0;i<n;i++)
		sum += A[i];

	int t = n;
	sum -= 2*n;
	
	if(sum>0)
		t += sum/2 + sum%2;

	cout<<t<<endl;
}