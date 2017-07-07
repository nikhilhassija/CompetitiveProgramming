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
	node * child[2];
	int    has[2];
};

void init	(node *);
void bin	(int *, int);
void insert	(node *, int);
void remove	(node *, int); 
int  search	(node *, int);

int main()
{
	node root;
	init(&root);

	int n;
	cin >> n;

	insert(&root, 0);

	while(n--)
	{
		char x;
		int y;
		cin >> x >> y;

		switch(x)
		{
			case '+': insert(&root, y); break;
			case '-': remove(&root, y); break;
			case '?': cout << search(&root, y) << endl;
		}
	}

	return (0-0);	
}

void init(node * root)
{
	root->child[0] = root->child[1] = NULL;
	root->has[0] = root->has[1] = 0;
}

void bin(int * A, int x)
{
	for(int i=31; i>=0; i--)
	{
		A[i] = x % 2;
		x /= 2;
	}
}

void insert(node * root, int x)
{
	int A[32];
	bin(A, x);

	node * cur = root;

	for(int i=0; i<32; i++)
	{
		if(cur->child[A[i]] == NULL)
		{
			cur->child[A[i]] = (node *)malloc(sizeof(node));
			init(cur->child[A[i]]);
		}

		cur->has[A[i]]++;
		cur = cur->child[A[i]];
	}
}

void remove(node * root, int x)
{
	int A[32];
	bin(A, x);

	node * cur = root;

	for(int i=0; i<32; i++)
	{
		cur->has[A[i]]--;
		cur = cur->child[A[i]];
	}
}

int search(node * root, int x)
{
	int A[32];
	bin(A, x);

	node * cur = root;

	int ans = 0;
	for(int i=0; i<32; i++)
	{
		ans *= 2;
		if(cur->has[1 ^ A[i]])
		{
			ans++;
			cur = cur->child[1 ^ A[i]];
		}
		else
			cur = cur->child[A[i]];
	}

	return ans;
}