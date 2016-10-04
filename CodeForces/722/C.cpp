#include <bits/stdc++.h>

#define lli long long int

using namespace std;

const lli inf = 1e17;
const lli N = 1e5 + 5;

lli A[N];
lli P[N];
lli Q[N];
lli C[N];

lli D[N];
lli S[N];

void make_set(int);
int find(int);
void merge(int, int);

int main()
{
	int n;
	cin >> n;

	for(int i=1;i<=n;i++)
		cin >> A[i];

	for(int i=0;i<n;i++)
		cin >> P[i];

	for(int i=0;i<n+2;i++)
		C[i] = -inf;

	Q[n-1] = 0;
	lli sum = 0;

	make_set(n+2);

	for(int i=n-1;i>0;i--)
	{
		int x = P[i];
		C[x] = A[x];

		if(C[x-1] != -inf)
			merge(x-1,x);
	
		if(C[x+1] != -inf)
			merge(x+1,x);


		sum = max(sum, S[find(x)]);
		Q[i-1] = sum;
	}

	for(int i=0;i<n;i++)
		cout << Q[i] << ' ';
	cout << endl;
}

void make_set(int n)
{
	for(int i=0;i<n;i++)
	{
		D[i] = i;
		S[i] = A[i];
	}
}

int find(int x)
{
	if(x == D[x])
		return x;

	return D[x] = find(D[x]);
}

void merge(int a, int b)
{
	int A = find(a);
	int B = find(b);

	if(a != b)
	{
		D[B] = A;
		S[A] += S[B];
	}
}