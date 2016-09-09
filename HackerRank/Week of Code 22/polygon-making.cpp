#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	vector <int> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];

	int sum = 0;
	for(int i=0;i<n;i++)
		sum += A[i];

	sort(A.begin(),A.end());

	int c = 0;
	while(A[n-1] >= (sum - A[n-1]))
	{
		c++;
		int x = A[n-1]/2;
		A[n-1] -= x;
		A.push_back(x);
		sort(A.begin(),A.end());
		n++;
	}

	printf("%d\n",c);
}