#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>>S;

	long long int c = 0;
	long long int l = S.size();
	for(int i=0;i<l;i++)
		if(S[i] == 'a')
			c++;

	long long int n;
	cin>>n;

	long long int ans = (n/l)*c;
	for(int i=0;i<n%l;i++)
		if(S[i] == 'a')
			ans++;

	printf("%lld\n",ans);
}