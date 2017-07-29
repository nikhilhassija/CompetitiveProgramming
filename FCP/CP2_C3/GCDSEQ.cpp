#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0); cin.tie(NULL)

using namespace std;

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int MAX_N = 1e5 + 5;

vector <int> F[MAX_N];

void init();

int main()
{
	init();

	int n;
	cin >> n;

	int A[n];
	for (int &i: A)
		cin >> i;

	int DP[MAX_N];
	mset(DP);

	for (int x: A)
	{
		int len = 1;

		for (int f: F[x])
			len = max(len, DP[f] + 1);

		DP[x] = len;

		for (int f: F[x])
			DP[f] = max(DP[f], len);
	}

	int ans = 1;
 
	for (int x: DP)
		ans = max(ans, x);

	cout << ans << endl;

	return (0-0);	
}

void init()
{
	vector < int > P(MAX_N, 1);

	for (int i = 2; i < MAX_N; i++)
	{
		if (P[i])
		{
			for (int j = 2 * i; j < MAX_N; j += i)
			{
				P[j] = 0;

				F[j].pb(i);
			}
		}
	}
}