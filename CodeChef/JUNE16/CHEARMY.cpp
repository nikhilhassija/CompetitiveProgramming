#include <bits/stdc++.h>

using namespace std;

string base5(long long int x);

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		long long int k;
		cin>>k;

		k--;
		string S = base5(k);

		for(int i=0;i<S.size();i++)
			printf("%d",int(S[i])*2);
		printf("\n");
	}
}

string base5(long long int x)
{
	string S;
	if(x==0)
		S.push_back(0);
	
	while(x)
	{
		S.push_back(x%5);
		x /= 5;
	}

	reverse(S.begin(),S.end());
	return S;
}