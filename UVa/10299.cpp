#include <bits/stdc++.h>

using namespace std;

int main()
{
	int64_t n,result;
	cin>>n;
	while(n)
	{
		if(n==1)
		{
			n = 0;
		}
		result = n;
		for(int64_t i=2; i*i<=n; i++)
		{
			if (n%i == 0)
			{
				while(n%i == 0)
					n /=i;
				result -= result/i;
			}
		}
		if(n>1)
			result -= result/n; //If n is prime
		cout<<result<<endl;
		cin>>n;
	}
}