#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node* left;
    struct Node* right;
    int data;
};

struct Node* newNode(int data)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->left=NULL;
	node->right=NULL;
    node->data=data;
    return node;
}

int getHeight(struct Node* root)
{
	int height =0;
    if (root) 
	{
        if (root->left || root->right) 
		{
            int leftheight = 0, rightheight = 0;
            if (root->left) 
			{
                leftheight = getHeight(root->left);
        	}
            if (root->right) 
			{
                rightheight = getHeight(root->right);
            }
            if (leftheight > rightheight) 
			{
                height = leftheight + 1;
            } 
            else 
			{
                height = rightheight + 1;
            }
        }
        else
		{ 
			height = height + 1;
        }
    }
    return height;
}

struct Node* insert(struct Node* root,int data)
{
    if(root==NULL)
        return newNode(data);
    else
	{
        struct Node* cur;
        if(data<=root->data)
		{
            cur=insert(root->left,data);
            root->left=cur;                
        }
        else
		{
            cur=insert(root->right,data);
            root->right=cur;
        }
    }
    return root;
}

int main()
{
    struct Node* root=NULL;
    int T,data;
    printf("no of nodes: ");
    scanf("%d",&T);
    while(T-->0)
	{
        scanf("%d",&data);
        root=insert(root,data);
    }
    int height=getHeight(root);
    printf("%d",height);
    return 0;
}
