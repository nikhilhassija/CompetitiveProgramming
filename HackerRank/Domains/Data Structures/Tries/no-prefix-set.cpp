
#define pis pair <int, string> 

using namespace std;

struct node
{
	int ends_here = 0;
	node * A[26];
};

node root;

pis trie_insert(node *, string);

int main()
{
	root.ends_here = 0;
	for(int i=0;i<26;i++)
		root.A[i] = NULL;

	int n;
	cin >> n;

	while(n--)
	{
		string S;
		cin >> S;

		auto p = trie_insert(&root, S);

		if(p.first)
		{
			cout << "BAD SET\n" << p.second << '\n';
			return 0;
		}
	}

	printf("GOOD SET\n");
}

pis trie_insert(node * root, string S)
{
	for(int i=0;i<S.size();i++)
	{
		if(root->ends_here)
			return {1,S};

		if(root->A[S[i]-'a'] == NULL)
		{
			root->A[S[i]-'a'] = new node;
			root = root->A[S[i]-'a'];
			
			for(int i=0;i<26;i++)
				root->A[i] = NULL;
		}
		else
		{

			root = root->A[S[i]-'a'];
		}
	}

	if(root->ends_here)
		return {1,S};

	root->ends_here = 1;

	for(int i=0;i<10;i++)
	{
		if(root->A[i] != NULL)
		{
			// S.push_back(i+'a');

			// root = root->A[i];

			// if(root -> ends_here)
				return {1,S};
		}
	}

	return {0,""};
}