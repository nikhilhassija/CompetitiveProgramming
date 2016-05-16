#include <bits/stdc++.h>

using namespace std;

vector <int> A;
vector <int> S;
vector <int> P;
int n;

void tree(int, int, int);

int main()
{
	cin>>n;

	A.resize(n);
	S.resize(n);
	P.resize(n,0);

	for(int i=0;i<n;i++)
		cin>>A[i];

	for(int i=0;i<n;i++)
		S[i] = A[i];

	sort(S.begin(),S.end());

	tree(0,0,n);

	for(int i=1;i<n;i++)
		printf("%d ",A[P[i]]);

	printf("\n");
}

void tree(int root, int tl, int tr)
{
	int index = upper_bound(S.begin()+tl,S.begin()+tr,A[root]) - S.begin() - 1;
	// printf("r-%d A[r]-%d s=%d tl-%d tr-%d\n",root,A[root],index,tl,tr);

	int ll,lr,rl,rr;

	ll = tl;
	lr = index;
	rl = index + 1;
	rr = tr;

	if(ll != lr)
	{
		for(int i=root+1;i<n;i++)
			if(A[i]<=A[root])
			{
				int x = lower_bound(S.begin(),S.end(),A[i]) - S.begin() - 1;
				if(x<=ll && x<lr)
				{
					// printf("%d->%d\n",A[root],A[i]);
					P[i] = root;
					tree(i,ll,lr);
					break;
				}
			}
	}	

	if(rl != rr)
	{
		for(int i=root+1;i<n;i++)
			if(A[i]>A[root])
			{
				int x = lower_bound(S.begin(),S.end(),A[i]) - S.begin() - 1;
				if(x<=rl && x<rr)
				{
					// printf("%d->%d\n",A[root],A[i]);
					P[i] = root;
					tree(i,rl,rr);
					break;
				}
			}
	}
}