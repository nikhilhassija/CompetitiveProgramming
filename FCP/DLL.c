#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node * prev;
	struct node * next;
};

void insertbeg(struct node **, int);
void insertend(struct node **, int);
void deletenext(struct node *, int, int);
void print(struct node *);
void sort(struct node **, int, int, int);
void ascmergesort(struct node **);
void dscmergesort(struct node **);
struct node * ascmerge(struct node *, struct node *);
struct node * dscmerge(struct node *, struct node *);
struct node * middle(struct node *);
int lessthan(struct node *, struct node *);

int main()
{
	int q;
	scanf("%d",&q);

	struct node * head = NULL;

	while(q--)
	{
		char A[20];
		scanf("%s",A);

		if(strcmp(A,"INSERTBEG") == 0)
		{
			int x;
			scanf("%d",&x);

			insertbeg(&head,x);
		}
		if(strcmp(A,"INSERTEND") == 0)
		{
			int x;
			scanf("%d",&x);

			insertend(&head,x);
		}
		if(strcmp(A,"DELETENEXT") == 0)
		{
			int i,m;
			scanf("%d %d",&i,&m);

			deletenext(head,i,m);
		}
		if(strcmp(A,"PRINT") == 0)
		{
			print(head);
		}
		if(strcmp(A,"SORT") == 0)
		{
			int o,l,u;
			scanf("%d %d %d",&o,&l,&u);

			sort(&head,o,l,u);
		}
	}
}

void insertbeg(struct node ** head, int x)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;

	temp->next = *head;
	if((*head) != NULL)
		(*head)->prev = temp;
	*head = temp;
}

void insertend(struct node ** head, int x)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->prev = NULL;
	temp->next = NULL;

	if(*head == NULL)
	{
		*head = temp;
	}
	else
	{
		struct node * cur = *head;

		while(cur->next != NULL)
			cur = cur->next;

		cur->next = temp;
		temp->prev = cur;
	}
}

void deletenext(struct node * head, int l, int r)
{
	struct node * cur = head;

	l--;
	while(l-- && cur != NULL)
		cur = cur->next;

	if(cur == NULL)
		return ;
	else
	{
		struct node * find = cur->next;

		while(r-- && find!= NULL)
			find = find->next;

		cur->next = find;
		if(find != NULL)
			find->prev = cur;
	}
}

void print(struct node * head)
{
	if(head == NULL)
		return;
	else
	{
		while(head != NULL)
		{
			printf("%d ",head->data);
			head = head->next;
		}
		printf("\n");
	}
}

void sort(struct node ** head, int o, int l, int u)
{
	struct node * front = *head;

	l--;
	while(l-- && front!=NULL)
		front = front->next;

	if(front == NULL)
		return;

	struct node * a = front->prev;

	struct node * last = *head;

	u--;
	while(u-- && last!=NULL)
		last = last->next;

	struct node * end = NULL; 
	if(last != NULL)	
	{
		end = last->next;
		last->next = NULL;
	}

	if(o == 1)
		ascmergesort(&front);
	else
		dscmergesort(&front);

	// print(front);
	if(a != NULL)
		a->next = front;
	else
		*head = front;
	// printf("Works\n");
	front->prev = a;

	while(front->next!=NULL)
		front = front->next;

	front->next = end;
	if(end != NULL)
		end->prev = front;
}

void ascmergesort(struct node ** head)
{
	if( (*head) == NULL || (*head)->next == NULL )
		return ;
	else
	{
		struct node * temp;
		temp = middle(*head);
		struct node * mid = temp->next;
		temp->next = NULL;

		ascmergesort(head);
		ascmergesort(&mid);

		*head = ascmerge(*head,mid);
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

struct node * ascmerge(struct node * a, struct node * b)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	struct node * cur = temp;
	while(a != NULL &&  b != NULL)
	{
		if(lessthan(a,b))
		{
			cur->next = a;
			a->prev = cur;
			a = a->next;
		}
		else
		{
			cur->next = b;
			a->prev = cur;
			b->prev = cur;
			b = b->next;
		}
		cur = cur->next;
	}
	if(a == NULL)
	{
		cur->next = b;
		b->prev = cur;
	}
	else
	{
		cur->next = a;
		a->prev = cur;
	}
	return temp->next;
}

void dscmergesort(struct node ** head)
{
	if( (*head) == NULL || (*head)->next == NULL )
		return ;
	else
	{
		struct node * temp;
		temp = middle(*head);
		struct node * mid = temp->next;
		temp->next = NULL;

		dscmergesort(head);
		dscmergesort(&mid);

		*head = dscmerge(*head,mid);
	}
}

struct node * dscmerge(struct node * a, struct node * b)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	struct node * cur = temp;
	while(a != NULL &&  b != NULL)
	{
		if(!lessthan(a,b))
		{
			cur->next = a;
			a->prev = cur;
			a = a->next;
		}
		else
		{
			cur->next = b;
			b->prev = cur;
			b = b->next;
		}
		cur = cur->next;
	}
	if(a == NULL)
	{
		b->prev = cur;
		cur->next = b;
	}
	else
	{	
		a->prev = cur;
		cur->next = a;
	}
	return temp->next;
}

int lessthan(struct node * a, struct node * b)
{
	return (a->data < b->data);
}