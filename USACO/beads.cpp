/*
ID: nikhil14
PROG: beads
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	int n,i,j;
	string S;
	cin>>n;
	cin>>S;
	for(i=0;i<n;i++)
		if(S[i] == 'r')
			break;
	if(i==n)
	{
		cout<<n<<endl;
		return 0;
	}
	for(i=0;i<n;i++)
		if(S[i] == 'b')
			break;
	if(i==n)
	{
		cout<<n<<endl;
		return 0;
	}
	int m = 0;
	int s = 0;
	for(i=0;i<n;i++)
	{
		s = 0;
		if(S[i] == 'w')
		{
			int x_r = 0;
			int x_b = 0;
			for(j=i;;j++)
			{
				if(j>=n)
					j -= n;
				if(S[j] == 'r' || S[j] == 'w')
					x_r++;
				else
					break;
			}
			for(j=i;;j++)
			{
				if(j>=n)
					j -= n;
				if(S[j] == 'b' || S[j] == 'w')
					x_b++;
				else
					break;
			}
			s += max(x_r,x_b);
		}
		else
		{
			for(j=i;;j++)
			{
				if(j>=n)
					j -= n;
				if(S[j] == S[i] || S[j] == 'w')
					s++;
				else
					break;
			}
		}
		if(S[i-1] == 'w')
		{
			int x_r = 0;
			int x_b = 0;
			for(j=i-1;;j--)
			{
				if(j<0)
					j += n;
				if(S[j] == 'r' || S[j] == 'w')
					x_r++;
				else
					break;
			}
			for(j=i-1;;j--)
			{
				if(j<0)
					j += n;
				if(S[j] == 'b' || S[j] == 'w')
					x_b++;
				else
					break;
			}
			s += max(x_r,x_b);
		}
		else
		{
			for(j=i-1;;j--)
			{
				if(j<0)
					j += n;
				if(S[j] == S[i-1] || S[j] == 'w')
					s++;
				else
					break;
			}
		}
		m = max(s,m);
	}
	cout<<m<<endl;
}