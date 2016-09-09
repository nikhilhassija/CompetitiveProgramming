#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

int main()
{
	vector <lli> A = {1ll,2ll,6ll,30ll,210ll,2310ll,30030ll,510510ll,9699690ll,223092870ll,6469693230ll,200560490130ll,7420738134810ll,304250263527210ll,13082761331670030ll,614889782588491410ll};

	int q;
	cin>>q;

	while(q--)
	{
		lli n;
		cin>>n;

		int i=0;
		for(;i<A.size();i++)
			if(A[i] > n)
				break;

		if(i != A.size())
			i--;

		printf("%d\n",i);
	}
}