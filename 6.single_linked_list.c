#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *header = NULL;


/*
void createNode(int item)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->link = NULL;
}
*/

void traverseList()
{
	struct node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}


void insertAtFront(int item)
{
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->link = NULL;

	if(header==NULL)
	{
		header=newnode;
	}
	else
	{
		newnode->link=header;
		header=newnode;
	}
}

void insertAtLast(int item)
{
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = item;
        newnode->link = NULL;

        if(header==NULL)
        {
                header=newnode;
        }
	else
	{
		struct node *ptr;
        	ptr=header;
        	while(ptr->link !=NULL)
        	{
                	ptr=ptr->link;
        	}
		ptr->link=newnode;
	}
}


void insertAtAny(int key, int item)
{
	struct node *ptr, *prev, *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->link = NULL;

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

        prev = NULL;
        ptr = header;

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
        struct node *ptr1 = header;
	
	while (ptr->link != NULL) 
	{
        	ptr1 = ptr;
        	ptr = ptr->link;
        }

    	printf("Node with value %d deleted from the end.\n", ptr->data);
    	ptr1->link = NULL;
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
        	ptr = ptr->link;
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
    		printf("1. Insert at Front\n");
    		printf("2. Insert at Last\n");
    		printf("3. Insert Before a Node\n");
    		printf("4. Display List\n");
    		printf("5. Delete at Front\n");
    		printf("6. Delete at Last\n");
    		printf("7. Delete at Any\n");
    		printf("8. Search for an Element\n"); // Added Search option
    		printf("9. Exit\n");
    	
    		printf("Enter your choice: ");
    		scanf("%d", &choice);
    		switch(choice)
    		{
        		case 1:
        			printf("Enter element to insert at front: ");
            			scanf("%d", &item);
            			insertAtFront(item);
            			break;

        		case 2:
            			printf("Enter element to insert at last: ");
            			scanf("%d", &item);
            			insertAtLast(item);
            			break;

			case 3:
            			printf("Enter the key before which to insert: ");
            			scanf("%d", &key);
            			printf("Enter element to insert: ");
            			scanf("%d", &item);
            			insertAtAny(key, item);
            			break;
	        	
	        	case 4:
        			printf("Current List: ");
            			traverseList();
            			break;
	        	
	        	case 5:
            			deleteAtFront();
            			break;

	        	case 6:
            			deleteAtEnd();
            			break;
	        	
	        	case 7:
            			printf("Enter the key of the node to delete: ");
            			scanf("%d", &key);
            			deleteAtAny(key);
            			break;
	        	
	        	case 8:
            			Search();
            			break;
	        	
	        	case 9:
            			printf("Exiting...\n");
	            		exit(0);
	        	default:
        			printf("Invalid choice! Please try again.\n");
    		}
    	}
	return (0);
}
