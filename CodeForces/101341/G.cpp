#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0); cin.tie(NULL)

using namespace std;
const int N = 200005;
string f[N];
int cnt[N], fin[N];
int main()
{
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)	{
		cin>>f[i];
		cnt[i] = 0;
		fin[i] = i;
	}
	int m;
	cin>>m;
	while(m--)	{
		int a, b;
		cin>>a>>b;
		a--, b--;
		cnt[a] = cnt[b] + 1;
		fin[a] = fin[b];
	}
	for(int i = 0; i < cnt[0]; i++)
		cout<<"I_love_";
	cout<<f[fin[0]]<<'\n';
	return (0-0);	
}