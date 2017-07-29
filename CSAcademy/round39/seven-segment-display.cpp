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

struct num
{
	int A[10];
};

const int MAX_K = 1e5 + 5;

num DP[MAX_K];

num add(num, int);
int valid(num);
num best(num, num);
string printnum(num);

int S[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; 

int main()
{
	int k;
	cin >> k;

	for(int i = 0; i < MAX_K; i++)
	{
		mset(DP[i].A);
		DP[i].A[0] = -1;
	}

	mset(DP[0].A);

	for(int i = 1; i <= k; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(i - S[j] >= 0)
			{
				num n = add(DP[i - S[j]], j);
			
				if(valid(n))
				{
					DP[i] = best(DP[i], n);
				}
			}
		}
	}

	cout << printnum(DP[k]) << endl;;
	
	return (0-0);	
}

num add(num a, int x)
{
	if(not valid(a))
		return a;

	num b(a);
	b.A[x]++;

	return b;
}

int valid(num a)
{
	if(a.A[0] < 0)
		return 0;

	int s = 0;
	for(int i = 0; i < 10; i++)
		s += a.A[i];

	if(s == a.A[0] and s > 1)
		return 0;

	return 1;
}

num best(num a, num b)
{
	if(not valid(a))
		return b;

	if(not valid(b))
		return a;

	int as = 0;
	for(int i = 0; i < 10; i++)
		as += a.A[i];

	if(as == 0)
		return b;

	int bs = 0;
	for(int i = 0; i < 10; i++)
		bs += b.A[i];

	if(bs == 0)
		return a;

	if(as < bs)
		return a;

	if(bs < as)
		return b;

	if(as == 1 and a.A[0])
		return a;

	if(bs == 1 and b.A[0])
		return b;

	int fa = 0;
	int fb = 0;

	for(int i = 1; i < 10; i++)
		if(a.A[i])
		{
			fa = i;
			break;
		}

	for(int i = 1; i < 10; i++)
		if(b.A[i])
		{
			fb = i;
			break;
		}

	if(fa < fb)
		return a;

	if(fb < fa)
		return b;

	for(int i = 0; i < 10; i++)
		if(a.A[i] > b.A[i])
			return a;

	return b;
}

string printnum(num a)
{
	if(not valid(a))
	{
		return "-1";
	}

	int s = 0;
	for(int i = 0; i < 10; i++)
		s += a.A[i];

	if(s == 1 and a.A[0])
	{
		return "0";
	}

	int f = 0;
	for(int i = 1; i < 10; i++)
	{
		if(a.A[i])
		{
			f = i;
			a.A[i]--;
			break;
		}
	}

	string S = "";

	S.pb(f + '0');
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < a.A[i]; j++)
			S.pb(i + '0');

	return S;
}