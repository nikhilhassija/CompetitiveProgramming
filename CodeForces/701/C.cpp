#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;

	string S;
	cin>>S;

	int A[256];
	memset(A,0,sizeof(A));
	for(int i=0;i<n;i++)
		A[S[i]] = 1;

	int c = 0;
	for(int i=0;i<256;i++)
		c += A[i];

	int B[256];
	memset(B,0,sizeof(B));
	int l = 0;
	int ans = n;
	B[S[0]] = 1;
	c--;

	for(int i=1;i<n;i++)
	{
		if(B[S[i]] == 0)
			c--;


		B[S[i]]++;

		if(S[i] == S[l])
		{
			while(B[S[l]]>1)
			{
				B[S[l]]--;
				l++;
			}
		}		

		if(c == 0)
			ans = min(ans,i-l+1);
	}
	printf("%d\n",ans);
}