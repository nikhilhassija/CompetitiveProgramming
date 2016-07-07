#include <bits/stdc++.h>
#include <message.h>
#include <winning_move.h>

using namespace std;

int main()
{
	int me = MyNodeId();

	if(me == 0)
	{
		int n = GetNumPlayers();
		vector <long long int> A(n+3);

		A[0] = 0;
		for(long long int i=1;i<=n;i++)
			A[i] = GetSubmission(i-1);
		A[n+1] = 0;
		A[n+2] = 1;

		sort(A.begin()+1,A.begin()+n);

		for(int i=1;i<=n+1;i++)
		{
			if(A[i] != A[i-1] && A[i] != A[i+1])
			{
				printf("%lld\n",A[i]);
				return 0;
			}
		}
	}
}