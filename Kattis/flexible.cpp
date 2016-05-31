#include <bits/stdc++.h>

using namespace std;

int main()
{
	int w,p;
	cin>>w>>p;

	int W[w+1];
	int P[p+2];
	memset(W,0,sizeof(W));

	P[0] = 0;
	P[p+1] = w;
	for(int i=1;i<=p;i++)
		cin>>P[i];

	for(int i=0;i<p+2;i++)
		for(int j=i+1;j	<p+2;j++)
			W[P[j]-P[i]] = 1;

	for(int i=0;i<=w;i++)
		if(W[i])
			printf("%d ",i);
	printf("\n");
}