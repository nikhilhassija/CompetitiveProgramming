#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n,z=0;
	string S;
	cin>>n;
	cin>>S;
	for(int i=0;i<n;i++)
		if(S[i]=='0')
			z++;
	n -= 2*min(n-z,z);
	cout<<n<<endl;
	return 0;
}