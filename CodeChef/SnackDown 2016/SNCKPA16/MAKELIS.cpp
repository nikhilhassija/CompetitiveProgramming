#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > P;
vector < vector <int> > D;
vector < vector <int> > M;
vector <int> A;

void init();

int main()
{
	init();

	int t;
	cin>>t;
	// t = 100000;

	while(t--)
	{
		int k;
		// k = t+1;
		cin>>k;
		int tk = k;

		if(k == 100000)
		{
			printf("50\n");
			for(int i=1;i<=5;i++)
			{
				for(int j=0;j<10;j++)
					printf("%d ",(i*10)-j);
			}
			printf("\n");
		}
		else
		{
			vector <int> X(5);

			for(int i=0;i<5;i++)
			{
				X[i] = k%10;
				k /= 10;
			}

			A.clear();

			for(int i=0;i<5;i++)
			{
				for(int x=0;x<P[i].size();x++)
						A.push_back(P[i][x]);

				for(int x=0;x<X[i];x++)
						A.push_back(D[i][x]);
			}

			for(int i=4;i>0;i--)
			{
				for(int x=0;x<M[i].size();x++)
					A.push_back(M[i][x]);
			} 

			int C[101];
			memset(C,0,sizeof(C));

			for(int i=0;i<A.size();i++)
				C[A[i]]=1;

			int n = 0;
			for(int i=0;i<101;i++)
			{
				// assert(C[i] <= 1);
				if(C[i])
				{
					C[i] = n+1;
					n++;
				}
			}

			for(int i=0;i<A.size();i++)
				A[i] = C[A[i]];

			printf("%d\n",n);
			for(int i=0;i<n;i++)
				printf("%d ",A[i]);
			printf("\n");
		}
	}
}

void init()
{
	P.resize(5);

	P[0].push_back(88);
	P[0].push_back(89);
	P[0].push_back(90);
	P[0].push_back(91);

	P[1].push_back(66);
	P[1].push_back(67);
	P[1].push_back(68);

	P[2].push_back(45);
	P[2].push_back(46);

	P[3].push_back(25);


	D.resize(5);

	for(int i=0;i<9;i++)
	{
		D[0].push_back(100-i);
		D[1].push_back(77-i);
		D[2].push_back(55-i);
		D[3].push_back(34-i);
		D[4].push_back(14-i);
	}


	M.resize(5);

	for(int i=0;i<10;i++)
	{
		M[1].push_back(87-i);
		M[2].push_back(65-i);
		M[3].push_back(44-i);
		M[4].push_back(24-i);
	}
}