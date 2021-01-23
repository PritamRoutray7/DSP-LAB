#include<stdio.h>
#include<math.h>

int len(int a)
{
	int l=0;
	while(a>0)
	{
		l++;
		a/=10;
	}
	return l;
}
int prime(int n)
{
	int c=1;
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			c=0;
			break;
		}
	}
	return c;
}
int main()
{
	int N;
	int i;
	printf("Enter a number:\n");
	scanf("%d",&N);
	if(N<=0)
	{
		printf("-1");
		return 0;
	}
	int r=len(N);
	int p=0;
	for(i=2;i<=r;i++)
	{
		int num=N;
		int j;
		int le=len(N);
		for(j=0;j<i;j++)
		{
			int rem=num%10; 
			num=(num/10)+(rem*pow(10,le-1));
		}
		int result=prime(num);
		if(result==1)
		p++;
	}
	if(p==r)
	printf("1");
	else
	printf("0");
	return r;
	return 0;
}

