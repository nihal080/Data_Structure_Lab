#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *header = NULL;

struct node* createNode(int item)
{
		struct node *newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data = item;
    	newnode->link = NULL;
    	return newnode;
}

void traverseList()
{
    	if (header == NULL)
    	{
        	printf("The list is empty.\n");
        	return;
    	}
    	struct node *ptr = header;
    	while(ptr != NULL)
    	{
        	printf("%d ", ptr->data);
        	ptr = ptr->link;
    	}
    	printf("\n");
}

void insertAtFront(int item)
{
    	struct node *newnode = createNode(item);
    	if(header == NULL)
    	{
     		header = newnode;
    	}
    	else
    	{
        	newnode->link = header;
        	header = newnode;
    	}
}

void insertAtAny(int key, int item)
{
    	struct node *newnode = createNode(item);
    	if(header == NULL)
    	{
        	printf("List is empty. Cannot insert before key %d.\n", key);
        	free(newnode);
        	return;
    	}
    	if(header->data == key)
    	{
        	newnode->link = header;
        	header = newnode;
        	return;
    	}
    	struct node *prev = NULL;
    	struct node *ptr = header;
    	while(ptr != NULL && ptr->data != key)
    	{
        	prev = ptr;
        	ptr = ptr->link;
    	}
    	if(ptr == NULL)
    	{
        	printf("Key %d not found, insertion not possible.\n", key);
        	free(newnode);
    	}
    	else
    	{
        	prev->link = newnode;
        	newnode->link = ptr;
    	}
}

void insertAtLast(int item)
{
    	struct node *newnode = createNode(item);
    	if(header == NULL)
    	{
        	header = newnode;
    	}
    	else
    	{
        	struct node *ptr = header;
        	while(ptr->link != NULL)
        	{
           		ptr = ptr->link;
        	}
        	ptr->link = newnode;
    	}
}

void deleteAtFront() 
{
    	if (header == NULL) 
    	{
        	printf("List is empty, nothing to delete.\n");
        	return;
    	}
    	struct node *temp = header;
    	printf("Node with value %d deleted from the front.\n", temp->data);
    	header = header->link;
    	free(temp);
	}

void deleteAtEnd() 
{
    	if (header == NULL) 
    	{
        	printf("List is empty, nothing to delete.\n");
        	return;
    	}
    	if (header->link == NULL) 
    	{
        	printf("Node with value %d deleted from the end.\n", header->data);
        	free(header);
        	header = NULL;
        	return;
    	}
    	struct node *ptr = header;
    	struct node *prev = NULL;
    	while (ptr->link != NULL) 
    	{
        	prev = ptr;
        	ptr = ptr->link;
    	}
    	printf("Node with value %d deleted from the end.\n", ptr->data);
    	prev->link = NULL;
    	free(ptr);
}

void deleteAtAny(int key) 
{
    	if (header == NULL) 
    	{
        	printf("List is empty. Cannot delete key %d.\n", key);
        	return;
    	}
    	struct node *ptr = header;
    	struct node *prev = NULL;
    	while (ptr != NULL && ptr->data != key) 
    	{
        	prev = ptr;
        	ptr=ptr->link;
    	}
    	if (ptr == NULL) 
    	{
        	printf("Key %d not found, deletion not possible.\n", key);
        	return;
    	}
    	if (prev == NULL) 
    	{
        	header = ptr->link;
    	}	
    	else 
    	{
       		prev->link = ptr->link;
    	}
    	printf("Node with value %d deleted.\n", ptr->data);
    	free(ptr);
}

void Search()
{
    	int key, position = 1;
    	struct node *ptr = header;
    	if (header == NULL)
    	{
        	printf("The list is empty.\n");
        	return;
    	}
    	printf("Enter the element to search: ");
    	scanf("%d", &key);
    	while (ptr != NULL)
    	{
        	if (ptr->data == key)
        	{
        		printf("Element %d found at position %d in the list.\n", key, position);
            		return;
        	}	
        	ptr = ptr->link;
        	position++;
    	}
    	printf("Element %d not found in the list.\n", key);
}

int main()
{
    	int choice, item, key;
    	while(1)
    	{
        	printf("\n--- Linked List Operations ---\n");
        	printf("1. Display\n");
        	printf("2. Search\n");
        	printf("3. Insert at Front\n");
        	printf("4. Insert at Any\n");
       		printf("5. Insert at Last\n");
        	printf("6. Delete at Front\n");
        	printf("7. Delete at Any\n");
        	printf("8. Delete at Last\n");
       		printf("9. Exit\n");
        	printf("Enter your choice: ");
        	scanf("%d", &choice);
        	switch(choice)
        	{
            		case 1:
                	traverseList();
                	break;
            	
            		case 2:
                	Search();
                	break;
            	
            		case 3:
                	printf("Enter element to insert at front: ");
                	scanf("%d", &item);
                	insertAtFront(item);
                	break;
            
            		case 4:
                	printf("Enter the key before which to insert: ");
                	scanf("%d", &key);
                	printf("Enter element to insert: ");
                	scanf("%d", &item);
                	insertAtAny(key, item);
                	break;
            
            		case 5:
                	printf("Enter element to insert at last: ");
                	scanf("%d", &item);
                	insertAtLast(item);
                	break;
            	
            		case 6:
                	deleteAtFront();
                	break;
            	
            		case 7:
                	printf("Enter the key of the node to delete: ");
                	scanf("%d", &key);
                	deleteAtAny(key);
                	break;
            
            		case 8:
                	deleteAtEnd();
                	break;
            	
            		case 9:
                	printf("Exiting...\n");
                	exit(0);
            
            		default:
                	printf("Invalid choice! Please try again.\n");
                }
	}
	return 0;
}
