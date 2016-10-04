#include <bits/stdc++.h>

using namespace std;

struct node
{
	node *A[26];
	int count = 0;
};

void trie_insert(node *, string);
int trie_find(node *, string);

int main()
{
	node root;
	root.count = 0;
	for(int i=0;i<26;i++)
		root.A[i] = NULL;

	int n;
	cin >> n;

	while(n--)
	{
		string Q,S;
		cin >> Q >> S;

		if(Q == "add")
			trie_insert(&root, S);
		else
			printf("%d\n", trie_find(&root, S));
	}
}

void trie_insert(node * root, string S)
{
	root->count++;

	for(int i=0;i<S.size();i++)
	{
		if(root->A[S[i] - 'a'] == NULL)
			root->A[S[i] - 'a'] = new node;

		root = root->A[S[i] - 'a'];

		root->count++;
	}
}

int trie_find(node * root, string S)
{
	for(int i=0;i<S.size();i++)
	{
		if(root->A[S[i] - 'a'] == NULL)
			return 0;
		else
			root = root->A[S[i] - 'a'];
	}

	return root->count;
}