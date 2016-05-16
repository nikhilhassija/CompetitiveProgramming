#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m,p;
	cin>>n>>m>>p;

	string S;
	cin>>S;
	S.insert(0,"(");
	S.push_back(')');

	int L[n+1];
	int R[n+2];
	int P[n+2];
	int D[n+2];

	stack <int> X;

	for(int i=0;i<n+2;i++)
	{
		L[i] = i-1;
		R[i] = i+1;
		D[i] = 0;

		if(S[i] == '(')
			X.push(i);
		else
		{
			int x = X.top();
			X.pop();
			P[x] = i;
			P[i] = x;
		}
	}

	string Q;
	cin>>Q;

	for(int i=0;i<Q.size();i++)
	{	
		if(Q[i] == 'R')
			p = R[p];
		else if(Q[i] == 'L')
			p = L[p];
		else
		{
			D[p] = 1;
			D[P[p]] = 1;

			if(p > P[p])
				p = P[p];
			
			if(p != 0)
			{
				R[L[p]] = R[P[p]];
			}
			if(p != n-1)
			{
				L[R[P[p]]] = L[p];
			}

			if(p > P[p])
				p = R[p];
			else
				p = R[P[p]];
		}
	}

	int i=1;
	while(i<=n+1)
	{
		if(D[i])
		{
			i = R[P[i]];
		}
		else
			break;
	}

	while(i<=n)
	{
		cout<<S[i];
		i = R[i];
	}
	cout<<endl;
}