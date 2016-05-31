#include <bits/stdc++.h>
#include <message.h>
#include <oops.h>

using namespace std;

int main()
{
	int nodes = NumberOfNodes();
	int me = MyNodeId();
	int n = GetN();
	int l = (n/nodes)*me;
	int r = (n/nodes)*(me+1);
	if(me == nodes - 1)
		r = n;

	long long int mn = GetNumber(l);
	long long int mx = GetNumber(l);

	for(int i=l;i<r;i++)
	{
		long long int x = GetNumber(i);
		mn = min(mn,x);
		mx = max(mx,x);
	}

	PutLL(0,mn);
	PutLL(0,mx);
	Send(0);

	if(me == 0)
	{
		for(int i=0;i<nodes;i++)
		{
			Receive(i);
			mn = min(mn,GetLL(i));
			mx = max(mx,GetLL(i));
		}
		printf("%lld\n",mx-mn);
	}
}