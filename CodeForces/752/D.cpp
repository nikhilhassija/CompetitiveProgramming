#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))

using namespace std;

struct node
{
	node * C[26];
	int best;
};

int isPal(string);
int findbest(node *, string);
void insert(node *, string, int);

vector < pair<string, int> > A;
vector <int> B;

int main()
{
	int n,k;
	cin >> n >> k;

	A.resize(n);
	for(int i=0;i<n;i++)
		cin >> A[i]._F >> A[i]._S;

	B.resize(n);
	for(int i=0;i<n;i++)
		B[i] = A[i].second;

	priority_queue < pii > P;
	priority_queue < pair <int, pii> > PP;

	for(int i=0;i<n;i++)
		if(isPal(A[i]._F))
		{
			pair <int, int> p = {A[i]._S, i};
			P.push(p);
		}

	node root;
	for(int i=0;i<26;i++)
		root.C[i] = NULL;
	root.best = -1;

	for(int i=0;i<n;i++)
	{
		int b = findbest(&root, A[i].first);

		if(b != -1)
		{
			// pair <int, pii> = make_pair(A[])
			PP.push({B[i] + B[b] ,{i, b}});
		}

		string S = A[i].first;
		reverse(S.begin(), S.end());
		insert(&root, S, i);
	}

	int U[n];
	mset(U);

	int ans = 0;

	priority_queue < pii > Q(P);
	priority_queue < pair <int, pii> > QQ(PP);


	while(!PP.empty() && PP.top().first > 0)
	{
		pair <int, pii> p = PP.top();
		PP.pop();

		int u = p.second.first;
		int v = p.second.second;

		if(!U[u] && !U[v])
		{
			ans += p.first;
			U[u] = 1;
			U[v] = 1;
		}
	}

	while(!P.empty() && P.top().first > 0)
	{
		pii p = P.top();
		P.pop();

		if(!U[p.second])
		{
			ans += p.first;
			break;
		}
	}

	int sum = 0;

	int V[n];
	mset(V);

	if(!Q.empty() && Q.top().first > 0)
	{
		sum += Q.top().first;
		V[Q.top().second] = 1;
	}

	while(!QQ.empty() && QQ.top().first > 0)
	{
		pair <int, pii> p = QQ.top();
		QQ.pop();

		int u = p.second.first;
		int v = p.second.second;

		if(!V[u] && !V[v])
		{
			sum += p.first;
			V[u] = 1;
			V[v] = 1;
		}
	}

	cout << max(sum, ans) << endl;
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

int findbest(node * root, string S)
{
	for(int i=0;i<S.size();i++)
	{
		if(root->C[S[i]-'a'] != NULL)
		{
			root = root->C[S[i] - 'a'];
		}
		else
			return -1;
	}

	return root->best;
}

void insert(node * root, string S, int ind)
{
	for(int i=0;i<S.size();i++)
	{
		int c = S[i] - 'a';

		if(root->C[c] == NULL)
		{
			root->C[c] = (node *)malloc(sizeof(node));
			for(int j=0;j<26;j++)
				root->C[c]->C[j] = NULL;
			root->C[c]->best = -1;
		}

		root = root -> C[c];
	}

	if(root->best == -1)
		root->best = ind;
	else
	{
		int b = root->best;

		if(B[ind] > B[b])
			root->best = ind;
	}
}