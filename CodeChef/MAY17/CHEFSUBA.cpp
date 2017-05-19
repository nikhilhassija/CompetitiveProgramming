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

struct frame 
{
	int cnt;
	int last;
};

int main()
{
	int n, k, p;
	cin >> n >> k >> p;

	k = min(k, n);

	int A[n];
	for(int i=0; i<n; i++)
		cin >> A[i];

	string S;
	cin >> S;

	multiset <int> M;

	int cnt = 0;
	for(int i=0; i<k-1; i++)
		cnt += A[i];

	deque <frame> Q;

	for(int i=k-1; i<n; i++)
	{
		cnt += A[i];
		Q.push_back({cnt, A[i]});
		M.insert(cnt);

		cnt -= A[i-k+1];
	}

	int shift = 0;

	for(int i=0; i<S.size(); i++)
	{
		if(S[i] == '!')
		{
			shift++;
			shift %= n;

			auto ff = Q.front();
			auto fe = Q.back();
			Q.pop_back();

			auto itr = M.find(fe.cnt);

			if(itr != M.end())
				M.erase(itr);

			frame nf = {ff.cnt + fe.last - ff.last, 
					A[(n + (k - 1 - shift)) % n]};

			M.insert(nf.cnt);
			Q.push_front(nf);
		}
		else
		{
			cout << *(prev(M.end())) << endl;
		}
	}

	return (0-0);	
}