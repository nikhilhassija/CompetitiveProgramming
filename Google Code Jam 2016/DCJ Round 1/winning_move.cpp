#include <bits/stdc++.h>
#include <message.h>
#include <winning_move.h>

using namespace std;

int main()
{
	int nodes = NumberOfNodes();
	int me = MyNodeId();
	int n = GetNumPlayers();

	int sz = n/nodes;

	if(me <= (n%nodes))
		sz++;


	vector <long long int> A(sz+3);

	A[0] = 0;
	for(long long int i=me;i<n;i+=nodes)
		A[(i/nodes)+1] = GetSubmission(i);
	A[sz-2] = 0;
	A[sz-1] = 1;

	vector <long long int> P;

	sort(A.begin()+1,A.end()-2);

	for(long long int i=1;i<=n+1;i++)
	{
		if(A[i] != A[i-1] && A[i] != A[i+1])
		{
			P.push_back(A[i]);
		}
	}

	int m = 1000/nodes;
	m -= 1;
	for(int i=0;i<P.size() && i<m;i++)
		PutLL(0,P[i]);
	PutLL(0,0);
	Send(0);

	printf("%d\n", me);
	if(me == 0)
	{
		int f = 1;
		A.clear();
		A.push_back(0);

		for(int i=0;i<nodes;i++)
		{
			Receive(i);
			while(true)
			{
				long long int x = GetLL(i);
				if(x)
					A.push_back(x);
				else
					break;
			}
		}
		int n = A.size();
		sort(A.begin()+1,A.end());
		A.push_back(0);
		A.push_back(1);
		A.push_back(1);
		A.push_back(0);
		A.push_back(1);

		for(int i=1;i<n+4;i++)
		{
			if(A[i] != A[i-1] && A[i] != A[i+1])
			{
				printf("%lld\n",A[i]);
				return 0;
			}
		}
	}
}