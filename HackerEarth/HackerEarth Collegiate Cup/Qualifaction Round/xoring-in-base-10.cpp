#include <bits/stdc++.h>

#define lli long long int

using namespace std;

struct num
{
	int D[10];

	void assign(int x)
	{
		for(int i=9;i>=0;i--)
		{
			D[i] = x%10;
			x  /= 10;
		}
	}

	void assign(num a)
	{
		for(int i=0;i<10;i++)
			D[i] = a.D[i];
	}

	void print()
	{
		for(int i=0;i<10;i++)
			printf("%d",D[i]);
		printf("\n");
	}

	void add(num a)
	{
		for(int i=0;i<10;i++)
			D[i] = (D[i] + a.D[i])%10;
	}

	void add(int x)
	{
		for(int i=9;i>=0;i--)
		{
			D[i] = (D[i]+x)%10;
			x  /= 10;
		}
	}

	int greater(num a)
	{
		for(int i=0;i<10;i++)
		{
			if(D[i] > a.D[i])
				return 0;
			if(D[i] < a.D[i])
				return 1;
		}

		return 0;
	}

	int greater(lli a)
	{
		lli n = 0;
		for(int i=0;i<10;i++)
			n = n*10 + D[i];

		return (a > n);
	}

	lli makenum()
	{
		lli n = 0;
		for(int i=0;i<10;i++)
			n = n*10 + D[i];

		return n;
	}
};

struct node
{
	node * A[10];
	int end;
};

int n,k,l,r;
int A[50];
num L[30];
num R[30];
num ans;
node * T[41];

void trie_init();
void trie_insert(node *, num);
void trie_max(node *, num);
void sum_left(int, int, num, int);
void sum_right(int, int, num, int);

int main()
{
	cin>>n>>k;

	for(int i=0;i<n;i++)
		cin>>A[i];

	// l = min(n,20);
	// r = max(0,n-l);

	l = n/2;
	r = n/2 + n%2;

	for(int i=0;i<l;i++)
		L[i].assign(A[i]);

	for(int i=0;i<r;i++)
		R[i].assign(A[l+i]);

	trie_init();

	num x;
	x.assign(0);

	sum_left(0,0,x,l);

	num y;
	y.assign(0);
	sum_right(0,0,y,r);

	printf("%lld\n",ans.makenum());
}

void trie_init()
{
	ans.assign(0);

	for(int i=0;i<=k;i++)
	{
		T[i] = (node *)malloc(sizeof(node));
		T[i]->end = 0;
		for(int j=0;j<10;j++)
			T[i]->A[j] = NULL;
	}
}

void trie_insert(node * root, num x)
{
	for(int i=0;i<10;i++)
	{
		int d = x.D[i];
		
		if(root->A[d] == NULL)
		{
			root->A[d] = (node *)malloc(sizeof(node));
			(root->A[d])->end = 0;
			for(int j=0;j<10;j++)
				(root->A[d])->A[j] = NULL;
		}

		root = root->A[d];
	}

	root->end = 1;
}

void sum_left(int i, int s, num x, int n)
{
	if(i == n && s <= k)
	{
		trie_insert(T[s],x);
		return ;
	}

	if(s == k)
	{
		trie_insert(T[k],x);
		return;
	}

	sum_left(i+1,s,x,n);
	x.add(L[i]);
	sum_left(i+1,s+1,x,n);
}

void sum_right(int i, int s, num x, int n)
{
	if(i == n && s <= k)
	{
		trie_max(T[k-s],x);
		return ;
	}

	if(s == k)
	{
		trie_max(T[0],x);
		return ;
	}

	sum_right(i+1,s,x,n);
	x.add(R[i]);
	sum_right(i+1,s+1,x,n);
}

void trie_max(node * root, num x)
{
	lli num = 0;

	for(int i=0;i<10;i++)
	{
		int d = x.D[i];
		d = 9 - d;

		do
		{
			if(d < 0)
				d += 10;

			if(root->A[d] != NULL)
			{
				num = num*10 + d;
				root = root->A[d];
				break;
			}
			d--;
		}
		while((d+10)%10 != (9 - x.D[i]));
	}

	x.add(num);

	if(root->end)
		if(ans.greater(x))
			ans.assign(x);
}