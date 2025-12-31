#include <stdio.h>
#include <limits.h>

#define V 4

int parent[V], rank[V];

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


void krushkal(int wg[V][V])
{
	int edge_count=0, min_cost=0;
	while(edge_count < V-1)
	{
		int min = INT_MAX, u=-1, v=-1;
		for(int i=0; i<V; i++)
		{
			for(int j=0;j<V;j++)
			{
				if(find_set(i) != find_set(j) && wg[i][j] < min)
				{
					min=wg[i][j];
					u=i;
					v=j;
				}
			}
		}
		union_set(u,v);
		printf("%d. (%d, %d) - %d\n", ++edge_count, u, v, min); 

		min_cost=min_cost+min;
	}
	printf("Minimum Cost is : %d\n", min_cost);
}



int main()
{
	// Adjacency matrix with weights(2D Array)
	int wg[V][V] = {
		{INT_MAX, 10,4,3},
		{10, INT_MAX, INT_MAX,5},
		{4, INT_MAX, INT_MAX,12},
		{3,5,12, INT_MAX}
	};
	
	// step 1 : Make set operation
	for(int i=0;i<V; i++)
	{
		make_set(i);
	}
	
	//MST Creation
	krushkal(wg);
	
	return (0);
}


