#include <stdio.h>
int parent[50], rank[50];

void make_set(int x)
{
	parent[x]=x;
	rank[x]=0;
}

int find_set(int x)
{
	if (x!=parent[x])
	{
		parent[x]=find_set(parent[x]);
	}
	return parent[x];
}

void link(int x,int y)
{
	if(x!=y)
	{
		if (rank[x]>rank[y])
		{
			parent[y]=x;
		}
		else
		{
			parent[x]=y;
			if (rank[x]==rank[y])
			{
				rank[y]=rank[y]+1;
			}
		}
	}
	else
	{
		printf("Both are same ");
	}
}

void union_set(int x, int y)
{
	link(find_set(x), find_set(y));
}



int main()
{
	make_set(0);
	make_set(1);
	make_set(2);
	make_set(3);	
	make_set(4);
	make_set(5);
	make_set(6);
	
	find_set(1);
	
	union_set(0,1);
	union_set(1,2);
	union_set(3,4);
	union_set(5,6);
	union_set(4,5);
	union_set(2,6);
	
	for(int i=0;i<7;i++)
	{
		printf("%d ",i);
	}
	
	printf("\n");
	
	for(int i=0;i<7;i++)
	{
		printf("%d ",parent[i]);
	}
	
	printf("\n");
	
	for(int i=0;i<7;i++)
	{
		printf("%d ",rank[i]);
	}
	
	printf("\n");
	
	return 0;
}


