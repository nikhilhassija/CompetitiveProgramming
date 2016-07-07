#include <bits/stdc++.h>

using namespace std;

int mod(int);
void decide(int);

string A,B;

int diff;

int main()
{
	int t;
	cin>>t;

	for(int c=1;c<=t;c++)
	{
		cin>>A>>B;

		A.insert(0,"0");
		A.push_back('0');

		B.insert(0,"0");
		B.push_back('0');

		diff = 0;
		for(int i=1;i<A.size()-1;i++)
			decide(i);

		printf("Case #%d: ",c);
		for(int i=1;i<A.size()-1;i++)
			cout<<A[i];
		printf(" ");
		for(int i=1;i<B.size()-1;i++)
			cout<<B[i];
		printf("\n");
	}
}

int mod(int x)
{
	if(x<0)
		x = -x;
	return x;
}

void decide(int x)
{
	if(A[x] != '?' && B[x] != '?')
	{
		if(!diff)
		{
			if(A[x] > B[x])
				diff = 1;
			if(A[x] < B[x])
				diff = -1;
		}
	}
	else
	{
		if(!diff)
		{
			if(A[x+1] == B[x+1])
			{
				if(A[x] == '?' && B[x] == '?')
				{
					A[x] = '0';
					B[x] = '0';
				}
				else
				{
					A[x] = min(A[x],B[x]);
					B[x] = min(A[x],B[x]);
				}
			}
			else
			{
				if(mod(A[x+1] - B[x+1]) > 5)
				{
					if(A[x+1] < B[x+1])
					{
						if(A[x] == '?' && B[x] == '?')
						{
							A[x] = '1';
							B[x] = '0';
						}
						else
						{
							if(A[x] == '?')
							{
								if(B[x] != '9')
									A[x] = B[x] + 1;
								else
									A[x] = B[x];
							}
							else
							{
								if(A[x] != '0')
									B[x] = A[x] - 1;
								else
									B[x] = A[x];
							}
						}	
					}
					else
					{
						if(A[x] == '?' && B[x] == '?')
						{
							A[x] = '0';
							B[x] = '1';
						}
						else
						{
							if(A[x] == '?')
							{
								if(B[x] != '0')
									A[x] = B[x] - 1;
								else
									A[x] = B[x];
							}
							else
							{
								if(A[x] != '9')
									B[x] = A[x] + 1;
								else
									B[x] = A[x];
							}
						}
					}
				}
				else
				{
					if(A[x] == '?' && B[x] == '?')
					{
						A[x] = '0';
						B[x] = '0';
					}
					else
					{
						A[x] = min(A[x],B[x]);
						B[x] = min(A[x],B[x]);
					}
				}
			}

			if(A[x] > B[x])
				diff = 1;
			if(A[x] < B[x])
				diff = -1;
		}
		else
		{
			if(diff == -1)
			{
				if(A[x] == '?')
					A[x] = '9';
				if(B[x] == '?')
					B[x] = '0';
			}
			else
			{
				if(A[x] == '?')
					A[x] = '0';
				if(B[x] == '?')
					B[x] = '9';	
			}
		}
	}
}