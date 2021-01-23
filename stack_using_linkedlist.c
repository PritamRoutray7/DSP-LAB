#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* top = NULL;

int isEmpty(struct Node* top)
{
	if(top == NULL)
	{
		return 1;	
	}
	else
	{
		return 0;
	}

}

int isFull(struct Node* top)
{
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));
	if(p == NULL)
	{
		return 1;	
	}
	else
	{
		return 0;
	}

}

struct Node* push(struct Node* top,int x)
{
	if(isFull(top))
	{
		printf("stack overflow\n");
	}
	else
	{
		struct Node* n = (struct Node*)malloc(sizeof(struct Node));
		n->data = x;
		n->next = top;
		top = n;
		return top;
	}
}

int pop(struct Node* tp)
{
	if(isEmpty(tp))
	{
		printf("stack underflow\n");	
	}
	else
	{
		struct Node* n = tp;
		top = (tp)->next;
		int x = n->data;
		free(n);
		return x;	
	}	
}
int main()
{
	top=push(top,10);
	top=push(top,20);
	top=push(top,30);
	top=push(top,40);
	int element = pop(top);
	printf("popped element is %d", element);
	return 0;
}
