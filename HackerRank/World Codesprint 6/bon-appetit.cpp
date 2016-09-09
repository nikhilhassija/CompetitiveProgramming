#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	int sum = 0;
	for(int i=0;i<n;i++)
		sum += A[i];

	sum -= A[k];

	int x;
	cin>>x;

	if(2*x == sum)
		printf("Bon Appetit\n");
	else
		printf("%d\n",x-(sum/2));
}