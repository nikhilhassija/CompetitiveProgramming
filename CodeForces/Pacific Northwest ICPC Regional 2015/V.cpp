#include <bits/stdc++.h>

#define lli long long int

using namespace std;

lli check(lli,lli,lli,lli,lli,lli);

int main()
{
	ios_base::sync_with_stdio(false);
	lli t,n,i,cur,g;
	vector <lli> X,Y,R,M,V;
	t = 1;	
	while(t--)
	{
		cin>>n;
		
		X.resize(n);
		Y.resize(n);
		R.resize(n);
		M.resize(n);
		V.resize(n);
		
		for(i=0;i<n;i++)
			cin>>X[i]>>Y[i]>>R[i];
		
		for(i=0;i<n;i++)
		{
			M[i] = 0;
			V[i] = 0;
		}

		stack <lli> S;
		
		M[0] = 1; //clockwise
		
		S.push(0);
		
		while(!S.empty())
		{
			cur = S.top();
			S.pop();

			V[cur] = 1;

			for(i=0;i<n;i++)
			{
				if(!V[i] && check(X[i],Y[i],R[i],X[cur],Y[cur],R[cur]))
				{
					if(!M[i])
					{
						M[i] = -M[cur];
					}
					else if(M[i]*M[cur] > 0)
					{
						M[i] = 0;
						M[cur] = 0;
					}
					S.push(i);
				}
			}
		}
		

		if(V[n-1])
		{
			if(M[n-1])
			{
				lli g = __gcd(R[0],R[n-1]);

				if(M[n-1]-1)
					printf("-");

				printf("%lld:%lld\n",R[n-1]/g,R[0]/g);
			}
			else
				printf("The input gear cannot move.\n");
		}
		else
			printf("The input gear is not connected to the output gear.”\n");
	}
	return 0;
}

lli check(lli x1,lli y1,lli r1,lli x2,lli y2,lli r2)
{
	lli d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	lli r = (r1+r2)*(r1+r2);
	if(d==r)
		return 1;
	return 0;
}