/*
ID: nikhil14
PROG: friday
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

bool oj = true;

int dayofweek(int y, int m, int d)
{
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

int main()
{
	if(oj)
	{
		freopen("friday.in","r",stdin);
		freopen("friday.out","w",stdout);
	}
	int n;
	cin>>n;
	int A[7];
	memset(A,0,sizeof(A));
	for(int i=0;i<n;i++)
		for(int j=1;j<=12;j++)
			A[dayofweek(1900+i,j,13)]++;
	for(int i=6;i<12;i++)
		cout<<A[i%7]<<" ";
	cout<<A[5]<<endl;
}