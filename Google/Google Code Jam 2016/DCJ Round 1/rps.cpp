#include <bits/stdc++.h>
#include <message.h>
#include <rps.h>

using namespace std;

int main()
{
	int nodes = NumberOfNodes();
	int master = nodes - 1;
	int me = MyNodeId();
	int n = GetN();
	int mn;
	if(nodes == 10)
	{
		nodes = 9;
		mn = n - 3;
	}
	if(nodes == 100)
	{
		nodes = 65;
		mn = n - 6;
	}

	if(mn<0)
		mn = 0;
	n = (1<<mn);

	if(me && me<nodes)
	{
		long long int l = (me-1)*n;
		long long int r = (me)*n;

		if(l>=(1<<GetN()))
			return 0;

		// printf("%d == %lld-%lld %lld-%lld\n",me,l,r,n,(long long int)(r-l-1LL));

		vector < pair<long long int,char> > A(n);
		for(long long int i=l;i<r;i++)
		{
			A[i-l].first = i;
			A[i-l].second = GetFavoriteMove(i);
		}

		n = r-l-1;
		while(n)
		{
			for(long long int i=0;i<n;i+=2)
			{
				char a = A[i].second;
				char b = A[i+1].second;
				if(a == b)
				{
					A[i/2] = A[i];
				}
				else
				{
					long long int x;
					switch(a)
					{
						case 'R': (b=='S')?(x=i):(x=i+1);break;
						case 'P': (b=='R')?(x=i):(x=i+1);break;
						case 'S': (b=='P')?(x=i):(x=i+1);break;
					}
					A[i/2] = A[x];
				}
			}
			n = n/2;
		}

		PutLL(master,A[0].first);
		Send(master);
	}

	if(me == master)
	{
		// printf("%lld\n",GetN());
		nodes--;
		int x = 0;
		vector < pair<long long int,char> > A(nodes);
		for(int i=0;i<nodes && (i*n)<(1<<GetN());i++)
		{
			Receive(i+1);
			A[i].first = GetLL(i+1);
			A[i].second = GetFavoriteMove(A[i].first);
			x++;
		}

		n = x;
		while(n)
		{
			for(long long int i=0;i<n;i+=2)
			{
				char a = A[i].second;
				char b = A[i+1].second;
				if(a == b)
				{
					A[i/2] = A[i];
				}
				else
				{
					long long int x;
					switch(a)
					{
						case 'R': (b=='S')?(x=i):(x=i+1);break;
						case 'P': (b=='R')?(x=i):(x=i+1);break;
						case 'S': (b=='P')?(x=i):(x=i+1);break;
					}
					A[i/2] = A[x];
				}
			}
			n = n/2;
		}
		printf("%lld\n",A[0].first);
	}
}