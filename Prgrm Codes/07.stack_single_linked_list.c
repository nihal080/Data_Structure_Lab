#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *header = NULL;
int size = 0;
const int MAX_SIZE = 5;

void push(int item)
{
	if (size == MAX_SIZE)
	{
		printf("Stack is full. Cannot push %d.\n", item);
		return;
	}
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->link = NULL;
	if (header == NULL)
	{
		header = newnode;
	}
	else
	{
		newnode->link = header;
		header = newnode;
	}
	size++;
	printf("%d pushed onto the stack.\n", item);
}

void pop()
{
	if (header == NULL)
	{
		printf("Stack is empty. Nothing to pop.\n");
		return;
	}
	struct node *temp = header;
	printf("Popped element: %d\n", temp->data);
	header = header->link;
	free(temp);
	size--;
}


void display()
{
	if (header == NULL)
	{
		printf("Stack is empty.\n");
		return;
	}
	struct node *ptr = header;
	printf("Stack elements: ");
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

int main()
{
	int choice, item;
	while (1)
	{
	        printf("\n--- Stack Menu ---\n");
	        printf("1. Push\n");
	        printf("2. Pop\n");
	        printf("3. Display\n");
	        printf("4. Exit\n");
	        printf("Enter your choice: ");
	        scanf("%d", &choice);
	        switch (choice)
		{
		        case 1:
                	printf("Enter element to push: ");
                	scanf("%d", &item);
                	push(item);
                	break;
            		case 2:
                	pop();
                	break;
		        case 3:
                	display();
               		break;
            		case 4:
			printf("Exiting....");
                	return 0;
            		default:
                	printf("Invalid choice. Please try again.\n");
        	}
	}
}
