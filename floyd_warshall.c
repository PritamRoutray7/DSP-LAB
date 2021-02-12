#include <stdio.h>

// declaring cost matrix 'a' , final distance matrix 'd' and 'n' is the no of vertices of the graph

int a[10][10], d[10][10], n; 

// function declaration to find the minimum among two variables

int min(int a, int b)
{
    if(a<b)
    	return a;
    else
    	return b;
}

// function declaration to find the distance matrix 'd'

void path()
{
    int i,j,k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

void main()
{
    int i,j;
    printf("\n Enter the no of vertices:");  // user inputs for no of vertices
    scanf("%d",&n);
    printf("\n Enter the cost matrix:\n");  // user inputs the cost matrix
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            d[i][j]=a[i][j];                // copying the cost matrix to the final distance matrix
        }
	}
    path();                                // function call 
    printf("\n The final distance matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%4d",d[i][j]);         // print the final distance matrix

        }
        printf("\n");
	}
}    
