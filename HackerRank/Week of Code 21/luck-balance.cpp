#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	vector <int> A;
	int l=0;

	while(n--)
	{
		int x,y;
		cin>>x>>y;

		if(y)
			A.push_back(x);
		else
			l += x;
	}	

	sort(A.rbegin(),A.rend());

	k = min(k,(int)A.size());

	for(int i=0;i<k;i++)
		l += A[i];

	for(int i=k;i<A.size();i++)
		l -= A[i];

	printf("%d\n",l);
}