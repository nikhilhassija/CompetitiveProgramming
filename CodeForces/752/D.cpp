#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fast() ios_base::sync_with_stdio(0);

using namespace std;

struct node 
{
	priority_queue <int> A,B;
};

struct pnode
{
	priority_queue <int> A;
};

int isPal(string);

int main()
{
	int n, k;
	cin >> n >> k;

	node PP[n];
	map <string, int> M;
	int g = 0;

	pnode P[n];
	map <string, int> PM;
	int pg = 0;

	while(n--)
	{
		string S;
		int w;

		cin >> S >> w;

		if(isPal(S))
		{

			if(PM.find(S) != PM.end())
			{
				int x = PM[S];

				P[x].A.push(w);
			}
			else
			{
				PM[S] = pg;
				P[pg].A.push(w);

				pg++;
			}
		}
		else
		{
			string R = S;
			reverse(R.begin(), R.end());

			if(M.find(S) != M.end())
			{
				int x = M[S];

				PP[x].A.push(w);
			}
			else if(M.find(R) != M.end())
			{
				int x = M[R];

				PP[x].B.push(w);
			}
			else
			{
				M[S] = g;
				PP[g].A.push(w);

				g++;
			}
		}
	}

	lli ans = 0;

	for(int i=0; i<g; i++)
	{
		while(!PP[i].A.empty() && !PP[i].B.empty())
		{
			int a = PP[i].A.top();
			PP[i].A.pop();

			int b = PP[i].B.top();
			PP[i].B.pop();

			if(a + b > 0)
				ans += a + b;
			else
				break;
		}
	}

	lli sum = 0;
	vector <int> C;
	vector <int> D;
	for(int i=0; i<pg; i++)
	{
		while(P[i].A.size() > 1)
		{
			int a = P[i].A.top();
			P[i].A.pop();

			int b = P[i].A.top();
			P[i].A.pop();


			if(a + b > 0)
			{
				sum += a + b;

				if(min(a,b) < 0)
					C.pb(min(a,b));
			}
			else
			{
				D.pb(a);
				break;
			}
		}

		if(P[i].A.size() && P[i].A.top() > 0)
		{
			D.pb(P[i].A.top());
		}
	}

	lli best_sum = max(0ll, sum);

	for(int i=0; i<C.size(); i++)
		best_sum = max(best_sum, sum - C[i]);

	for(int i=0; i<D.size(); i++)
		best_sum = max(best_sum, sum + D[i]);

	ans += max(0ll, best_sum);

	cout << ans << endl;
}

int isPal(string S)
{
	int l = 0;
	int r = S.size() - 1;

	while(l < r)
	{
		if(S[l] != S[r])
			return 0;

		l++;
		r--;
	}

	return 1;
}