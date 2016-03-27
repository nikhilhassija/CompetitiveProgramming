#include <stdio.h>
#include <stdlib.h>

struct node
{
	int x,y;
	struct node * next;
};

void insert(struct node **, int, int);

void mergesort(struct node **);

struct node * middle(struct node *);

struct node * merge(struct node *, struct node *);

int lessthan(struct node *, struct node *);

void delete_duplicates(struct node *);

void print(struct node *);

int equal(struct node *, struct node *);

int main()
{
	struct node * A = NULL;
	struct node * B = NULL;

	int x,y;

	while(1)
	{
		scanf("%d",&x);
		if(x)
		{
			scanf("%d %d",&x,&y);
			insert(&A,x,y);
		}
		else
			break;
	}
	while(1)
	{
		scanf("%d",&x);
		if(x)
		{
			scanf("%d %d",&x,&y);
			insert(&B,x,y);
		}
		else
			break;
	}

	mergesort(&A);
	mergesort(&B);

	struct node * C;
	C = merge(A,B);
	delete_duplicates(C);

	print(C);
}

void insert(struct node ** head, int a, int b)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->x = a;
	temp->y = b;
	temp->next = NULL;

	struct node * cur = *head;

	if(cur == NULL)
		*head = temp;
	else
	{
		while(cur->next != NULL)
			cur = cur->next;

		cur->next = temp;
	}
}

void mergesort(struct node ** head)
{
	if( (*head) == NULL || (*head)->next == NULL )
		return ;
	else
	{
		struct node * temp;
		temp = middle(*head);
		struct node * mid = temp->next;
		temp->next = NULL;

		mergesort(head);
		mergesort(&mid);

		*head = merge(*head,mid);
	}
}

struct node * middle(struct node * head)
{
	if( head == NULL || head->next == NULL)
		return NULL;
	struct node * slow = head;
	struct node * fast = head;
	while(fast->next != NULL && (fast->next)->next != NULL)
	{
		slow = slow->next;
		fast = (fast->next)->next;
	}
	return slow;
}

struct node * merge(struct node * a, struct node * b)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	struct node * cur = temp;
	while(a != NULL &&  b != NULL)
	{
		if(lessthan(a,b))
		{
			cur->next = a;
			a = a->next;
		}
		else
		{
			cur->next = b;
			b = b->next;
		}
		cur = cur->next;
	}
	if(a == NULL)
		cur->next = b;
	else
		cur->next = a;
	return temp->next;
}

int lessthan(struct node * a, struct node * b)
{
	return (a->x < b->x) || (a->x == b->x && a->y < b->y);
}

void delete_duplicates(struct node * head)
{
	while(head->next != NULL)
	{
		if(equal(head,head->next))
			head->next = (head->next)->next;
		else
			head = head->next;
	}
}

int equal(struct node * a, struct node * b)
{
	return (a->x == b->x) && (a->y == b->y);
}

void print(struct node * head)
{
	while(head != NULL)
	{
		printf("%d %d\n",head->x,head->y);
		head = head->next;
	}
}