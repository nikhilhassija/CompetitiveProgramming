#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector <int> A(4);
	for(int i=0;i<4;i++)
		cin>>A[i];

	sort(A.begin(),A.end());

	int f = 0;

	do
	{
		int x = __gcd(A[0],A[1]);
		int y = __gcd(A[2],A[3]);

		if(A[0]/x == A[2]/y && A[1]/x == A[3]/y)
		{
			f = 1;
			break;
		}
	}while(next_permutation(A.begin(),A.end()));

	if(f)
		printf("Possible\n");
	else
		printf("Impossible\n");

}