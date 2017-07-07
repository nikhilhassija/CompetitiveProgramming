#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

vector <lli> A;
vector <lli> C;

lli check(lli k);

int main()
{
	lli n, S;
	cin >> n >> S;

	A.resize(n);
	C.resize(n);
	for(int i=0; i<n; i++)
		cin >> A[i];

	lli l = 0;
	lli h = n;

	lli a = 0;
	lli c = 0;

	while(l <= h)
	{
		lli m = (l + h) / 2;

		lli x = check(m);

		if(x <= S)
		{
			if(a < m)
			{
				a = m;
				c = x;
			}

			if(a == m)
				c = min(c, x);

			l = m + 1;
		}
		else
			h = m - 1;
	}


	cout << a << " " << c << endl;

	return (0-0);	
}

lli check(lli k)
{
	for(lli i=0; i<A.size(); i++)
		C[i] = A[i] + (i+1)*k;

	sort(C.begin(), C.end());

	lli s = 0;

	for(int i=0; i<k; i++)
		s += C[i];

	return s;
}