#include <bits/stdc++.h>

using namespace std;

vector < string > S(2); 

int check(int x,int n)
{
	bool flag = true;
	flag = flag && (S[0][x] == '.' && S[1][x] == '.');
	if(x>0)
		flag = flag && (S[0][x-1] == 'X' && S[1][x-1] == 'X');
	if(x<n-1)
		flag = flag && (S[0][x+1] == 'X' && S[1][x+1] == 'X');
	return flag;
}

int main()
{
	int t;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		int n;
		cin>>n;
		cin>>S[0];
		cin>>S[1];
		vector < pair<int,int> > A,B;
		int count = 0;
		int g = 0;
		for(int i=0;i<n;i++)
		{
			if(check(i,n))
			{
				S[0][i] = 'X';
				S[1][i] = 'X';
				g++;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(S[0][i] == '.')
				count++;
			else if(count)
			{
				A.push_back(make_pair(i-count,count));
				count = 0;
			}
		}	
		if(count)
			A.push_back(make_pair(n-count,count));
		count = 0;
		for(int i=0;i<n;i++)
		{
			if(S[1][i] == '.')
				count++;
			else if(count)
			{
				B.push_back(make_pair(i-count,count));
				count = 0;
			}
		}		
		if(count)
			B.push_back(make_pair(n-count,count));
		// for(int i=0;i<A.size();i++)
			// cout<<A[i].first<<" "<<A[i].second<<endl;
		// cout<<endl;
		// for(int i=0;i<B.size();i++)
			// cout<<B[i].first<<" "<<B[i].second<<endl;
		for(int i=0;i<A.size();i++)
		{
			if(A[i].second > 1)
			{
				g++;
				for(int j=0;j<B.size();j++)
				{
					if(B[j].second == 1 && A[i].first<=B[j].first && B[j].first<(A[i].first+A[i].second))
					{
						B[j].second = 0;
						// cout<<"Overlap "<<A[i].first<<" "<<B[j].first<<endl;
						break;
					}
				}
				A[i].second = 0;
			}
		}	
		for(int i=0;i<B.size();i++)
		{
			if(B[i].second > 1)
			{
				g++;
				for(int j=0;j<A.size();j++)
				{
					if(A[j].second == 1 && B[i].first<=A[j].first && A[j].first<(B[i].first+B[i].second))
					{
						A[j].second = 0;
						// cout<<"Overlap "<<B[i].first<<" "<<A[j].first<<endl;
						break;
					}
				}
				B[i].second = 0;
			}
		}
		for(int i=0;i<A.size();i++)
			if(A[i].second)
				g++;
		for(int i=0;i<B.size();i++)
			if(B[i].second)
				g++;
		printf("Case #%d: %d\n",c,g);
	}
}