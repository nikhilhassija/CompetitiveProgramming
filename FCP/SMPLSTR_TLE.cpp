#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n,q,i,x,y,k;
	// string S;
	vector <int> A(26);
	// cin>>n>>q;
	scanf("%d %d",&n,&q);
	// cin>>S;
	char S[n+1];
	scanf("%s",S);
	while(q--)
	{
		for(i=0;i<26;i++)
			A[i] = 0;
		// cin>>x>>y>>k;
		scanf("%d %d %d",&x,&y,&k);
		x--;
		for(i=x;i<y;i++)
			A[S[i]-'a']++;
		if(k)
		{
			for(i=0;i<26;i++)
			{
				for(int j=0;j<A[i];j++)
					S[x++] = i+'a';
			}
		}
		else
		{
			for(i=25;i>=0;i--)
			{
				while(A[i]--)
					S[x++] = i+'a';
			}
		}
	}
	cout<<S<<endl;
	return 0;
}