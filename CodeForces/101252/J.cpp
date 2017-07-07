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

void subset(int, int);

int d = 0;
int K;

int main()
{
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, k;
	cin >> n >> k; 

	K = k;

	cout << "+" << n;
	int i = n;
	d++;

	for(; i>=k; i--)
	{
		subset(i-1, k-1);
		
		if(i == k)
		{
			cout << "-" << i << endl;
			return 0;
		}

		cout << "--" << i;
	}

	// if
	cout << "-" << i << endl;

	return (0-0);	
}

void subset(int n, int k)
{
	if(not k)
	{
		assert(d == K);
		return ;
	}

	cout << "+" << n;
	d++;

	assert(d <= K);

	subset(n-1, k-1);
	assert(d <= K);
	
	cout << "-" << n;
	d--;
	assert(d);

	if(n == k)
	{
		return ;
	}

	subset(n-1, k);
}