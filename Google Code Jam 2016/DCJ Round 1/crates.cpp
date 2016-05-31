#include <bits/stdc++.h>
#include <message.h>
#include <crates.h>

using namespace std;

long long int mod = 1e9 + 7;

int main()
{
	int me = MyNodeId();

	if(me == 0)
	{
		long long int n = GetNumStacks();
		
		long long int A[n];
		long long int B[n];
		long long int sum = 0;

		for(long long int i=0;i<n;i++)
		{
			A[i] = GetStackHeight(i+1);
			sum += A[i];
		}	

		for(int i=0;i<n;i++)
		{
			B[i] = sum/n;
			if(i < sum%n)
				B[i]++;
		}

		long long int D[n];

		for(int i=0;i<n;i++)
			D[i] = B[i]-A[i];

		long long int m = 0; 
		for(int i=0;i<n-1;i++)
		{
			if(D[i]>0)
			{
				m += D[i];
				m %= mod;
				D[i+1] += D[i];
				D[i] = 0;
			}
		} 

		for(int i=n-1;i>0;i--)
		{
			if(D[i]>0)
			{
				m += D[i];
				m %= mod;
				D[i-1] += D[i];
				D[i] = 0;
			}
		}

		printf("%lld\n",m);
	}
}