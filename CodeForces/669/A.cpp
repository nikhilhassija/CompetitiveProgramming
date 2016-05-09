#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int ans = 2*(n/3) + (n%3>0);
	cout<<ans<<endl;
}