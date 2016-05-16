#include <bits/stdc++.h>

using namespace std;

vector <int> A;
vector <int> T;

void build(int, int, int);
int query(int, int, int, int, int);

int main()
{
	int n,q;
	cin>>n>>q;

	A.resize(n);
	T.resize(4*n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	build(1,0,n-1);

	int ans = 0;

	while(q--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;

		int l,r;
		l = (a*max(ans,0) + b)%n+1;
		r = (c*max(ans,0) + d)%n+1;

		if(l>r)
			swap(l,r);
		
		if(k == 1)
		{
			ans = query(1,0,n-1,l-1,r-1);
			cout<<ans<<endl;
		}
		else
		{
			set <int> S;

			for(int i=l-1;i<r;i++)
			{
				S.insert(A[i]);
			}
			
			if(S.size() < k)
				ans = -1;	
			else
			{
				k--;
				auto it = S.begin();
				while(k--)
					it++;
				ans = *it;
			}		

			cout<<ans<<endl;
		}
	}
}

void build(int node, int l, int r)
{
	if(l == r)
		T[node] = A[l];
	else
	{
		int mid = (l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);

		T[node] = min(T[2*node],T[2*node+1]);
	}
}

int query(int node, int tl, int tr, int l, int r)
{
	if(r < tl || l > tr)
		return INT_MAX;
	else if(l <= tl && tr <= r)
		return T[node];
	else
	{
		int mid = (tl+tr)/2;

		return min(query(2*node,tl,mid,l,r),query(2*node+1,mid+1,tr,l,r)); 
	}
}