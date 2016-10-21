#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	vector <lli> A;

	lli p = 1;
	for(int i=0;i<10;i++)
	{
		p *= 9;
		A.push_back(p);

		p *= 2;
		A.push_back(p);
	}

	lli n;

	while(cin >> n)
	{
		n--;

		int x = 0;
		for(int i=0;i<A.size()-1;i++)
		{
			if(n/A[i] && !(n/A[i+1]))
				break;
			x ^= 1;
		}

		if(x)
			printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");
	}
}