#include <bits/stdc++.h>

using namespace std;

int s(int n)
{
	int ans = 0;
	while(n)
	{
		ans += n%10;
		n /= 10;
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;

	int ans = 0;
	for(int i=n;i>n-2000;i--)
	{
		if((i + s(i) + s(s(i))) == n)
		{
			ans++;
		}
	}

	printf("%d\n",ans);
}