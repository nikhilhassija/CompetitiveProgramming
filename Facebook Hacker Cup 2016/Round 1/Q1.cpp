#include <bits/stdc++.h>

using namespace std;

#define ff(A) A.first.first
#define fs(A) A.first.second
#define sc(A) A.second

int main()
{
	int t,i;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		int n;
		cin>>n;
		vector <int> A(n);
		vector < pair< pair <int,int>, int> > P; 
		for(i=0;i<n;i++)
			cin>>A[i];
		int count = 1;
		for(i=1;i<n;i++)
		{
			if(A[i]>A[i-1] && (A[i]-A[i-1])<=10)
				count++;
			else
			{
				P.push_back(make_pair(make_pair(A[i-count],A[i-1]),count%4));
				count = 1;
			}
		}
		P.push_back(make_pair(make_pair(A[i-count],A[i-1]),count%4));
		count = 0;
		// for(i=0;i<P.size();i++)
			// printf("%d %d %d\n",ff-(P[i]),fs(P[i]),sc(P[i]));
		for(i=0;i<P.size()-1;i++)
		{
			int x = count;
			if(sc(P[i]))
			{
				if(sc(P[i+1]))
				{
					int d = ff(P[i+1]) - fs(P[i]) ;
					// d = d / (4 - (sc(P[i])+sc(P[i+1])));
					if((sc(P[i])+sc(P[i+1]) < 4) &&  (d + (4-(sc(P[i])+sc(P[i+1]))) ) / (5 - (sc(P[i])+sc(P[i+1])))<= 10 && fs(P[i]) < ff(P[i+1]))
					{
						count += 4 - (sc(P[i])+sc(P[i+1]));
						sc(P[i+1]) = 0;
					} 
					else
						count += 4 - sc(P[i]);
				}
				else
				{
					count += 4 - sc(P[i]);
				}
			}
			// printf("%d %d %d | %d\n",ff(P[i]),fs(P[i]),sc(P[i]),count-x);
		}
		if(sc(P[i]))
			count += 4 - sc(P[i]);
		printf("Case #%d: %d\n",c,count);
	}
}