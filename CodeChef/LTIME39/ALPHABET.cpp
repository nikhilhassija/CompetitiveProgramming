#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;

	int A[26];
	memset(A,0,sizeof(A));
	for(int i=0;i<S.size();i++)
		A[S[i]-'a']++;

	int t;
	cin>>t;

	while(t--)
	{
		cin>>S;

		int f = 1;

		for(int i=0;i<S.size() && f;i++)
		{
			if(A[S[i]-'a'] == 0)
			{
				printf("No\n");
				f = 0;
			}
		}

		if(f)
			printf("Yes\n");
	}
}