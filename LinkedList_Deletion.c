#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

void LLtraversal(struct Node *ptr)
{
	while(ptr!=NULL)
	{
		printf("DATA : %d\n",ptr->data);
		ptr=ptr->next;
	}
}

// DELETE THE FIRST NODE

struct Node *deletefirst(struct Node *first)
{
	struct Node *ptr=first;
	first=first->next;
	free(ptr);
	return first; 
}

// DELETE NODE AT AN INDEX

struct Node *deleteatindex(struct Node *first,int index)
{
	struct Node *p=first;
	struct Node *q=first->next;
	int i;
	for( i=0;i<index-1;i++)
	{
		p=p->next;
		q=q->next;
 	}
	p->next=q->next;
	free(q);
	return first;
}

// DELETE THE LAST NODE

struct Node *deletelast(struct Node *first)
{
	struct Node *p=first;
	struct Node *q=first->next;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next;
 	}
	p->next=NULL;
	free(q);
	return first;
}

// DELETE NODE WITH A GIVEN VALUE

struct Node *deletenodewithvalue(struct Node *first,int value)
{
	struct Node *p=first;
	struct Node *q=first->next;
	while(q->data!=value && q->data!=NULL)
	{
		p=p->next;
		q=q->next;
 	}
	if(q->data==value)
	{
		p->next=q->next;
		free(q);
	}
	return first;
}


int main()
{
	struct Node *first;
	struct Node *second;
	struct Node *third;
	struct Node *fourth;
	
	first=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	fourth=(struct Node*)malloc(sizeof(struct Node));
	
	first->data=7;
	first->next=second;
	second->data=11;
	second->next=third;
	third->data=45;
	third->next=fourth;
	fourth->data=67;
	fourth->next=NULL;
	
	printf("Linked list before deleting first node\n");
	LLtraversal(first);
	
//	first=deletefirst(first);
//	printf("Linked list after deleting first node\n");
//	LLtraversal(first);
	
//	first=deleteatindex(first,2);
//	printf("Linked list after deleting at a node\n");
//	LLtraversal(first);
	
//	first=deletelast(first);
//	printf("Linked list after deleting last node\n");
//	LLtraversal(first);

	first=deletenodewithvalue(first,11);
	printf("Linked list after deleting node with a value\n");
	LLtraversal(first);
	return 0;
}

