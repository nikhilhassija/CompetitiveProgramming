#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string S;
		cin>>S;

		int n = S.size();
		if(n == 2 && S[0] == S[1])
				cout<<S[0]<<endl;
		else if(n == 3)
		{
			int x = 0;
			for(int i=0;i<n;i++)
				if(S[i] == 'A')
					x++;
			if(x == 1)
				printf("B\n");
			else if(x == 2)
				printf("A\n");
			else
				printf("-1\n");
		}
		else if(n == 4)
		{
			int x = 0;
			for(int i=0;i<n;i++)
				if(S[i] == 'A')
					x++;
			// printf("%d\n",x);
			if(x == 1 && S[1] == 'A')
				printf("BAB\n");
			else if(x == 2 && S[1] == S[2])
				printf("%c%c%c\n",S[0],S[1],S[3]);
			else if(x == 3 && S[1] == 'B')
				printf("ABA\n");
			else
				printf("-1\n");
		}
		else
		{
			int x = 1;
			vector < pair<char,int> > A;
			for(int i=1;i<n;i++)
			{
				if(S[i] == S[i-1])
					x++;
				else
				{
					A.push_back(make_pair(S[i-1],x));
					x = 1;
				}
			}
			A.push_back(make_pair(S[n-1],x));

			int l = A.size();

			int f = -1;
			for(int i=0;i<l;i++)
				if(A[i].second == 2)
					f = i;

			if(f == -1)
			{
				int oa = 0;
				int ob = 0;
				int ac = 0;
				int bc = 0;
				for(int i=0;i<l;i++)
				{
					if(A[i].first == 'A')
					{
						if(A[i].second == 1)
							oa++;
						ac++;
					} 
					if(A[i].first == 'B')
					{
						if(A[i].second == 1)
							ob++;
						bc++;
					} 
				}
				if(oa>1 && ac>2)
				{
					if(ob)
					{
						int flag = 0;
						for(int i=0;i<l;i++)
						{
							if(A[i].first == 'B' && flag == 0)
							{
								flag = 1;
							}
							else
							{
								for(int j=0;j<A[i].second;j++)
									cout<<A[i].first;	
							}
						}
						cout<<endl;
					}
					else
					{
						int m;
						if(A[1].first == 'B')
							m = 1;
						else
							m = 2;
						for(int i=1;i<l-1;i++)
							if(A[i].first == 'B' && A[i].second < A[m].second)
								m = i;

						for(int i=0;i<l;i++)
							if(i != m)
								for(int j=0;j<A[i].second;j++)
									cout<<A[i].first;
						cout<<endl;
					}
				}
				else if(ob>1 && bc>2)
				{
					if(oa)
					{
						int flag = 0;
						for(int i=0;i<l;i++)
						{
							if(A[i].first == 'A' && flag == 0)
							{
								flag = 1;
							}
							else
							{
								for(int j=0;j<A[i].second;j++)
									cout<<A[i].first;	
							}
						}
						cout<<endl;
					}
					else
					{
						int m;
						if(A[1].first == 'A')
							m = 1;
						else
							m = 2;
						for(int i=1;i<l-1;i++)
							if(A[i].first == 'A' && A[i].second < A[m].second)
								m = i;

						for(int i=0;i<l;i++)
							if(i != m)
								for(int j=0;j<A[i].second;j++)
									cout<<A[i].first;
						cout<<endl;
					}
				}
				else
					printf("-1\n");
			}
			else
			{
				for(int i=0;i<l;i++)
				{
					if(i == f)
						cout<<A[i].first;
					else
					{
						for(int j=0;j<A[i].second;j++)
							cout<<A[i].first;
					}
				}
				cout<<endl;
			}
		}
	}
}