#include <stdio.h>
#define MAX_SIZE 10

int S[MAX_SIZE], TOP = -1;

void push(int item)
{
	if (TOP >= MAX_SIZE-1)
	{
        	printf("The Stack is Full\n");
	}
	else
        {
        	TOP = TOP + 1;
        	S[TOP] = item;
        	printf("%d pushed into the stack.\n", item);
    	}
}

void pop()
{
	if (TOP < 0)
        {
        	printf("The Stack is Empty\n");
    	}
   	else
    	{
        	printf("The popped Element is %d\n", S[TOP]);
       		TOP = TOP - 1;
        }
}

void display()
{
	printf("STACK elements: ");
	for (int i = TOP; i >= 0; i--)
	{
		printf("%d ", S[i]);
	}
	printf("\n");
}

int main()
{
	int choice, element;
    	while (1)
    	{
        	printf("\nSTACK OPERATIONS\n");
        	printf("1. PUSH\n");
        	printf("2. POP\n");
        	printf("3. DISPLAY\n");
        	printf("4. EXIT\n");
        	printf("ENTER THE OPTION (1-4): ");
        	scanf("%d", &choice);

        	switch (choice)
        	{
        		case 1:
                	printf("Enter the element to be inserted: ");
                	scanf("%d", &element);
                	push(element);
                	break;

		        case 2:
                	pop();
                	break;

                        case 3:
                	display();
                	break;

		        case 4:
                	printf("EXITING....\n");
			return 0;

	                default:
                        printf("Invalid choice! Please select between 1-4.\n");
        	}
	}
    	return 0;
}
