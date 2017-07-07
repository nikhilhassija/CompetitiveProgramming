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

struct node 
{
	int count;
	int suffix;
	int end;

	node * child[26];	
};

void init(node *);

void f_insert(node *, string, int *);
void b_insert(node *, string);

int exist(node *, string);

int f_query(node *, string);
int b_query(node *, string);

void f_remove(node *, string, int *);
void b_remove(node *, string); 

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int q;
		cin >> q;

		node T, RT;

		init(&T);
		init(&RT);

		while(q--)
		{
			int q;
			string s;

			cin >> q >> s;

			int n = s.size();

			if(q == 1)
			{
				int z[s.size() + 1];
				mset(z);

				int L = 0, R = 0;
				for (int i = 1; i < n; i++) 
				{
					if (i > R) 
					{
						L = R = i;
						while (R < n && s[R-L] == s[R]) 
							R++;
						z[i] = R-L; R--;
					} 
					else 
					{
						int k = i-L;
						if (z[k] < R-i+1) 
							z[i] = z[k];
						else 
						{
							L = i;
							while (R < n && s[R-L] == s[R]) 
								R++;
							z[i] = R-L; R--;
						}
					}
				}

				int S[s.size() + 1];
				mset(S);
				for(int i=0; i<=s.size()/2; i++)
				{
					int j = n - 1 - i;

					S[i] = (z[j] + j == n);
				}
				S[0] = (s[0] == s[n-1]);

				f_insert(&T, s, S);
				b_insert(&RT, s);
			}
			else if(q == 2)
			{
				if(exist(&T, s) > 0)
				{
					int z[s.size() + 1];
					mset(z);

					int L = 0, R = 0;
					for (int i = 1; i < n; i++) 
					{
						if (i > R) 
						{
							L = R = i;
							while (R < n && s[R-L] == s[R]) 
								R++;
							z[i] = R-L; R--;
						} 
						else 
						{
							int k = i-L;
							if (z[k] < R-i+1) 
								z[i] = z[k];
							else 
							{
								L = i;
								while (R < n && s[R-L] == s[R]) 
									R++;
								z[i] = R-L; R--;
							}
						}
					}

					int S[s.size() + 1];
					mset(S);
					for(int i=0; i<n/2; i++)
					{
						int j = n - 1 - i;

						S[i] = (z[j] + j == n);
					}
					S[0] = (s[0] == s[n-1]);

					f_remove(&T, s, S);
					b_remove(&RT, s);
				}
			}
			else
			{
				int f = f_query(&T, s);
				int b = b_query(&RT, s);

				// cout << f << " ";
				// cout << b << " ";

				cout << (f + b) << endl;
			}
		}
	}
	
	return (0-0);  
}

void init(node * root)
{
	root -> end = 0;
	root -> count = 0;
	root -> suffix = 0;

	for(int i=0; i<26; i++)
		root -> child[i] = 0;
}

void f_insert(node * root, string S, int * Z)
{
	node * cur = root;
	int n = S.size();

	for(int i=0; i<n; i++)
	{
		int c = S[i] - 'a';
		if(cur -> child[c] == NULL)
		{
			cur -> child[c] = (node *) malloc(sizeof(node));
			init(cur -> child[c]);
		}

		(cur -> count)++;
		cur = (cur -> child[c]);

		if(i <= n/2 and Z[i])
			(cur -> suffix) ++;
		// (cur -> suffix) += (i < (n/2)) * (Z[i]);
	}

	(cur -> count)++;
	(cur -> end)++;
}

void b_insert(node * root, string S)
{
	node * cur = root;
	int n = S.size();

	for(int i=0; i<n; i++)
	{
		int c = S[n - 1 - i] - 'a';
		if(cur -> child[c] == NULL)
		{
			cur -> child[c] = (node *) malloc(sizeof(node));
			init(cur -> child[c]);
		}

		(cur -> count)++;

		cur = (cur -> child[c]);
	}

	(cur -> count)++;
}

int exist(node * root, string S)
{
	node * cur = root;
	int n = S.size();

	for(int i=0; i<n; i++)
	{
		int c = S[i] - 'a';

		if(cur -> child[c] == NULL or (cur -> count == 0))
			return 0;

		cur = cur -> child[c];
	}

	return (cur -> count) and (cur -> end);
}


void f_remove(node * root, string S, int * Z)
{
	node * cur = root;
	int n = S.size();

	for(int i=0; i<n; i++)
	{
		int c = S[i] - 'a';

		(cur -> count) = max(0, cur -> count - 1);
		cur = (cur -> child[c]);

		if(i <= n/2 and Z[i])
		{
			(cur -> suffix) = max(0, cur -> suffix - 1);
		}
	}

	(cur -> count) = max(0, cur -> count - 1);
	(cur -> end) = max(0, cur -> end - 1);
}


void b_remove(node * root, string S)
{
	node * cur = root;
	int n = S.size();

	for(int i=0; i<n; i++)
	{
		int c = S[n - 1 - i] - 'a';

		(cur -> count)--;
		cur = (cur -> child[c]);
	}

	max(0, (cur -> count)--);
}

int f_query(node * root, string S)
{
	int n = S.size();

	node * cur = root;

	for(int i=0; i<n; i++)
	{
		int c = S[i] - 'a';
		if(cur -> child[c] == NULL)
			return 0;

		cur = cur -> child[c];
	}

	// printf("in query %d %d\n", cur -> count, cur -> suffix);

	return (cur -> count) - (cur -> suffix) - (cur -> end);
}

int b_query(node * root, string S)
{
	int n = S.size();

	node * cur = root;

	for(int i=0; i<n; i++)
	{
		int c = S[n - 1 - i] - 'a';

		if(cur -> child[c] == NULL)
			return 0;

		cur = cur -> child[c];
	}

	return cur -> count;
}