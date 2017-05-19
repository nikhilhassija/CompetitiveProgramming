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

struct trie_node
{
	int has_pos;
	int has_neg;
	int end_pos;
	int end_neg;

	trie_node * child[26];
};

void node_init(trie_node *);
void trie_insert(trie_node *, string, int, int);
string getprefix(trie_node *, string);

int main()
{
	trie_node root;
	node_init(&root);

	int n;
	cin >> n;

	vector <string> B;

	int f = 0;

	while(n--)
	{
		char C;
		string S;

		cin >> C >> S;

		trie_insert(&root, S, C == '+', C == '-');

		if(C == '-')
		{
			f = 1;
			B.pb(S);
		}
	}

	if(not f)
	{
		cout << 0 << endl;
		return 0;
	}

	set <string> S;

	for(int i=0; i<B.size(); i++)
	{
		string X = getprefix(&root, B[i]);

		if(X == "")
		{
			cout << -1 << endl;
			return 0;
		}

		S.insert(X);
	}

	cout << S.size() << endl;

	for(auto it=S.begin(); it!=S.end(); it=next(it))
		cout << *it << endl;

	return (0-0);
}

void node_init(trie_node * node)
{
	node->has_pos = 0;
	node->has_neg = 0;
	node->end_pos = 0;
	node->end_neg = 0;

	for(int i=0; i<26; i++)
		node->child[i] = NULL;
}

void trie_insert(trie_node * root, string S, int is_pos, int is_neg)
{
	trie_node * cur = root;

	for(int i=0; i<S.size(); i++)
	{
		if(cur->child[S[i]-'a'] == NULL)
		{	
			cur->child[S[i]-'a'] = (trie_node *) malloc(sizeof(trie_node));
			node_init(cur->child[S[i]-'a']);
		}

		cur->has_neg += is_neg;
		cur->has_pos += is_pos;

		cur = cur->child[S[i]-'a'];
	}

	cur->has_pos += is_pos;
	cur->has_neg += is_neg;
}

string getprefix(trie_node * root, string S)
{
	trie_node * cur = root;

	for(int i=0; i<S.size(); i++)
	{
		if(cur->has_neg and not cur->has_pos)
			return S.substr(0, i);

		if(cur->child[S[i] - 'a'] == NULL)
			return "";

		cur = cur->child[S[i]-'a'];
	}

	if(cur->has_neg and not cur->has_pos)
		return S;

	return "";
}