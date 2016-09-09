#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	string S;
	cin>>S;

	int C[n];
	memset(C,0,sizeof(C));

	int l = 0;
	int r = n-1;
	int s = 0;

	while(l<r)
	{
		if(S[l] != S[r])
		{
			if(S[l]>S[r])
			{
				S[r] = S[l];
				C[r] = 1;
			}
			else
			{
				S[l] = S[r];
				C[l] = 1;
			}
			s++;
		}
		l++;
		r--;
	}


	if(s > k)
		printf("-1\n");
	else if(s == k)
		cout<<S<<endl;
	else
	{
		int l = 0;
		int r = n - 1;
		int x = k - s;

		while(l<r && x)
		{
			if(C[l]==0 && C[r]==0 && x>1 && S[l] != '9')
			{
				S[l] = '9';
				S[r] = '9';
				x -= 2;
			}
			else if(C[l] || C[r])
			{
				S[l] = '9';
				S[r] = '9';
				x = x - 2 + C[l] + C[r];
			}
			l++;
			r--;
		}

		if(n%2 && x)
			S[n/2] = '9';
		
		cout<<S<<endl;
	}
}