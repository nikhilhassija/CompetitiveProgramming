#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,q;
	cin>>n>>q;

	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];

	while(q--)
	{
		int d;
		cin>>d;
		pair <int,int> ans = make_pair(-1,-1);
		map <int,int> M;
		M.clear();
		for(int i=0;i<n;i++)
		{
			if(M.find(A[i]-d) != M.end())
			{
				if(ans.first == -1 || ((i-M[A[i]-d]) < (ans.second - ans.first)))
				{
					ans.first = M[A[i]-d];
					ans.second = i;
				}
			}
			M[A[i]] = i;
		}

		if(ans.first == -1)
			printf("-1\n");
		else
			printf("%d %d\n",ans.first+1,ans.second+1);
	}

}