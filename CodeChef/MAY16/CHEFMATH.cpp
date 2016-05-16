#include <bits/stdc++.h>

using namespace std;

vector <int> C(44);

const long long int mod = 1e9 + 7;

long long int query(int, int, int);

int main()
{
	C[0] = 1;
	C[1] = 2;

	for(int i=2;i<44;i++)
		C[i] = C[i-1] + C[i-2];

	reverse(C.begin(),C.end());

	int q;
	cin>>q;

	while(q--)
	{
		int x,k;
		cin>>x>>k;

		int index = 0;
		while(C[index]>x)
			index++;

		cout<<query(x,k,index)<<endl;
	}
}

long long int query(int x, int k, int index)
{
	if(x < 0)
		return 0;

	if(k<0)
		return 0;

	if(k == 0)
	{
		if(x == 0)
			return 1;
		else
			return 0;
	}

	long long int ans = 0;
	for(int i=index;i<44;i++)
	{
		int d = x/C[i];
		if(d && d<=k)
		{
			while(d)
			{
				ans += query(x-d*C[i],k-d,i+1);
				ans %= mod;
				d--;
			}
		}
	}

	return ans;
}