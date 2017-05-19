#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, -1, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

const int MAX_N = 2e5 + 5;

struct node
{
	int has[MAX_N][2];

	node * child [2];
};

unordered_map <int, int> M;
int id = 0;

void init(node *);
void trie_insert(node *, int, int, int);
int  trie_max(node *, int, int);
int  trie_min(node *, int, int);

void binary(int *, int);

int main()
{
	node root;
	init(&root);

	int N, Q;
	cin >> N >> Q;

	int R, K;
	cin >> R >> K;

	M[R] = id++;

	trie_insert(&root, M[R], M[R], K);	

	for(int i=0; i<N-1; i++)
	{
		int v, u, k;
		cin >> u >> v >> k;

		M[u] = id++;

		trie_insert(&root, M[u], M[v], k);
	}

	int l = 0;

	while(Q--)
	{
		int t;
		cin >> t;

		t ^= l;

		if(not t)
		{
			int v, u, k;
			cin >> v >> u >> k;

			v ^= l;
			u ^= l;
			k ^= l;			

			M[u] = id++;

			printf("yo\n");

			trie_insert(&root, M[u], M[v], k);
		}
		else
		{
			int v, k;
			cin >> v >> k;

			v ^= l;
			k ^= l;

			int min_a = trie_min(&root, M[v], k);
			int max_a = trie_max(&root, M[v], k);

			l = min_a ^ max_a;

			cout << min_a << " " << max_a << endl;
		}
	}

	return (0-0);	
}

void init(node * root)
{
	mset(root->has);

	root->child[0] = NULL;
	root->child[1] = NULL;
}

void trie_insert(node * root, int id, int par, int key)
{
	int A[32];

	binary(A, key);

	node * cur = root;

	for(int i=0; i<32; i++)
	{
		if(cur->child[A[i]] == NULL)
		{
			cur->child[A[i]] = (node *) malloc(sizeof(node));

			init(cur->child[A[i]]);
		}


		cur->has[id][0] = cur->has[par][0];
		cur->has[id][1] = cur->has[par][1];
		
		cur->has[id][A[i]] = id;

		if(id == 2)
		{
			cout << cur->has[id][0] << " ";
			cout << cur->has[id][1] << endl;
		}

		cur = cur->child[A[i]];
	}
}

void binary(int * A, int k)
{
	for(int i=31; i>=0; i--)
	{
		A[i] = k%2;
		k /= 2;
	}
}

int trie_max(node * root, int id, int key)
{
	int A[32];
	binary(A, key);

	node * cur = root;

	int val = 0;

	for(int i=0; i<32; i++)
	{
		if(cur->child[A[i] ^ 1] and (cur->has[id][A[i] ^ 1] != -1))
		{
			val = (val << 1) + (A[i] ^ 1);
			cur = cur->child[A[i] ^ 1];

			id = cur->has[id][A[i] ^ 1];
		}
		else
		{
			val = (val << 1) + (A[i]);
			cur = cur->child[A[i]];

			id = cur->has[id][A[i]];			
		}
	}

	return (val ^ key);
}

int trie_min(node * root, int id, int key)
{
	int A[32];
	binary(A, key);

	node * cur = root;

	int val = 0;

	for(int i=0; i<32; i++)
	{
		cout << i <<  " ";
		cout << A[i] << " ";
		cout << cur->has[id][A[i]] << " ";
		cout << cur->has[id][A[i] ^ 1] << endl;

		if(cur->child[A[i]] and (cur->has[id][A[i]] != -1))
		{
			cout << "took" << endl;

			val = (val << 1) + (A[i]);
			cur = cur->child[A[i]];

			id = cur->has[id][A[i]];
		}
		else
		{
			val = (val << 1) + (A[i] ^ 1);
			cur = cur->child[A[i] ^ 1];

			id = cur->has[id][A[i] ^ 1];
		}
	}

	cout << val << endl;
	return (val ^ key);
}