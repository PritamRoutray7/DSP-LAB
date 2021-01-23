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

// INSERT AT THE BEGINNING 

struct Node *insertatbeginning(struct Node *first,int data)
{
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->next=first;
	ptr->data=data;
	return ptr;
}

// INSERT AT ANY INDEX

struct Node *insertatindex(struct Node *first,int data,int index)
{
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	struct Node *p=first;
	int i=0;
	while(i!=index-1)
	{
		p=p->next;
		i++;
	}
	ptr->data=data;
	ptr->next=p->next;
	p->next=ptr;
	return first;
}

// INSERT AT THE END

struct Node *insertatend(struct Node *first,int data)
{
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=data;
	struct Node *p=first;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=ptr;
	ptr->next=NULL;
	return first;
}

// INSERT AFTER A NODE

struct Node *insertafternode(struct Node *first,struct Node *previousnode,int data)
{
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=data;
	ptr->next=previousnode->next;
	previousnode->next=ptr;
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
	
	printf("Linked list before insertion\n");
	LLtraversal(first);
	
	first=insertatbeginning(first,109);
	printf("\nLinked list after insertion at the beginning\n");
	LLtraversal(first);
	
	first=insertatindex(first,10,2);
	printf("\nLinked list after insertion at the index\n");
	LLtraversal(first);
		
	first=insertatend(first,20);
	printf("\nLinked list after insertion at the end\n");
	LLtraversal(first);
	
	first=insertafternode(first,second,30);
	printf("\nLinked list after insertion after a node\n");
	LLtraversal(first);
	
	return 0;
}

