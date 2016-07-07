#include <bits/stdc++.h>

using namespace std;

int main()
{
	double v,t;
	cin>>v>>t;

	int n;
	cin>>n;

	double X[n],T[n];
	for(int i=0;i<n;i++)
		cin>>X[i]>>T[i];

	double d = X[0] + v*(t+T[0]);
	int index = 0;

	for(int i=n-1;i>0;i--)
	{
		if((X[i] + v*(t+T[i])) <= d)
		{
			d = X[i] + v*(t+T[i]);
			index = i;
		}
	}

	printf("%f %d\n",d,index+1);	
}