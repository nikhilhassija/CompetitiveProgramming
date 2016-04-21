#include <bits/stdc++.h>

using namespace std;

struct node 
{
	int data;
	struct node * d[10];
	node()
	{
		data = 0;
		for(int i=0;i<10;i++)
			d[i] = NULL;
	}
};

void insert(struct node * t, int x)
{
	struct node * cur = t;
	while(x)
	{
		if(cur->d[x%10] == NULL)
			cur->d[x%10] = (struct node *)malloc(sizeof(struct node));
		cur = cur->d[x%10];
		x /= 10;
	}
	cur->data = 1;
}

int find(struct node * t, int x)
{
	struct node * cur = t;
	while(x)
	{
		if(cur->d[x%10] == NULL)
			return 0;
		cur = cur->d[x%10];
		x /= 10;
	}
	return cur->data;
}

int main()
{
	int q;
	scanf("%d",&q);

	struct node * t = (struct node *)malloc(sizeof(struct node));

	while(q--)
	{
		int c,n;
		scanf("%d %d",&c,&n);

		if(c == 1)
			insert(t,n);
		else
			if(find(t,n))
				printf("yes\n");
			else
				printf("no\n");
	}
}