#include<stdio.h>
#include<stdlib.h>

#define max_nodes 5

int stack[max_nodes], visited[max_nodes], adjacency_matrix[max_nodes][max_nodes];
int top = -1;

void push(int node)
{
	if (top == max_nodes - 1)
	{
		printf("stack Overflow\n");
		exit(1);
	}
	top++;
	stack[top] = node;
}

int pop()
{
	if (top == -1)
	{
		printf("stack Underflow\n");
		exit(1);
	}
	int node = stack[top];
	top--;
	return node;		
}

void dfs(int start_node, int num_nodes)
{
	int i, current_node;
	push(start_node);
	visited[start_node] = 1;
	
	while(top != -1)
	{
		current_node = pop();
		printf("%d" , current_node);
		for(i = 0; i< num_nodes; i++)
		{
			if (adjacency_matrix[current_node][i] == 1 && !visited[i])
			{
				visited[i] = 1;
				push(i);
			}
		}

	}
}

int main()
{
	int i,j, num_nodes, start_node;
	printf("Enter the number of nodes: ");
	scanf("%d", &num_nodes);
	printf("Enter the adjacency matrix:\n");
	for (i = 0; i<num_nodes; i++)
	{
		for (j = 0; j < num_nodes; j++)
		{
			scanf("%d", &adjacency_matrix[i][j]);
		}
	}
	printf("Enter the start node: ");
	scanf("%d", &start_node);
	dfs(start_node, num_nodes);
	
	return 0;
}
				
		
