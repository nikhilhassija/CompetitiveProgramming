#include <bits/stdc++.h>

using namespace std;

int check(int64_t,int64_t,int64_t,int64_t,int64_t,int64_t);

int main()
{
	ios_base::sync_with_stdio(false);
	int t,n,i,cur,g;
	vector <int> X,Y,R,M;
	cin>>t;
	while(t--)
	{
		cin>>n;
		X.resize(n);
		Y.resize(n);
		R.resize(n);
		M.resize(n);
		for(i=0;i<n;i++)
			cin>>X[i]>>Y[i]>>R[i];
		for(i=0;i<n;i++)
			M[i] = 0;
		stack <int> S;
		M[0] = 1; //clockwise
		S.push(0);
		while(!S.empty())
		{
			// cur = S.pop(); 
			cur = S.top();
			S.pop();
			for(i=0;i<n;i++)
			{
				if(!M[i] && check(X[i],Y[i],R[i],X[cur],Y[cur],R[cur]))
				{
					M[i] = -M[cur];
					S.push(i);
				}
			}
		}
		for(int i=0; i<n; i++)
        {
        	if (M[i]==0)
        	    cout << "not moving" << endl;
        	else
        	{
        	    g = __gcd(R[0],R[i]);
        	    cout << R[0]/g;
        	    if (R[i]-g)
        	        cout << "/" << R[i]/g;
        	    if(M[i]+1)
        	    	cout<<" clockwise"<<endl;
        	    else
        	  		cout<<" counterclockwise"<<endl;
        	}
        }
	}
	return 0;
}

int check(int64_t x1,int64_t y1,int64_t r1,int64_t x2,int64_t y2,int64_t r2)
{
	int64_t d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	int64_t r = (r1+r2)*(r1+r2);
	if(d==r)
		return 1;
	return 0;
}