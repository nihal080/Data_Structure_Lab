#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *header = NULL;

void createnode()
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = 10;
	newnode->link = NULL;
	header=newnode;
}

int main()
{
	createnode();
	printf("Data: %d\n",header->data);
	return (0);
}
