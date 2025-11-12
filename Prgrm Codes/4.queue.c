#include<stdio.h>
#define MAX_SIZE 10
int Q[MAX_SIZE], FRONT = -1, REAR = -1;

void enqueue(int value)
{
	if(REAR >= MAX_SIZE - 1)
	{
		printf("Queue is Full\n");
	}
	else
	{
	if( FRONT == -1 && REAR == -1)
	{
		FRONT = 0;
	}
	REAR += 1;
	Q[REAR] = value;
	}
}

void dequeue()
{
	if (FRONT < 0)
	{
		printf("Queue is Empty\n");
	}
	else
	{
		printf("Deleted Element is: %d\n", Q[FRONT]);
		if(FRONT == REAR)
		{
			FRONT = -1;
			REAR = -1;
		}
		else
		{
			FRONT = FRONT + 1;
		}
	}
}

void display()
{
	if (REAR >= 0)
	{
		printf("Stack Elements are : ");
		for (int i = REAR; i >= FRONT; i--)
		{
			printf("%d\t", Q[i]);
		}
		printf("\n");
	}
	else
	{
		printf("QUEUE is empty");
	}
}


int main()
{
	int count = 0, var, value;
	while (count != 1)
	{
		printf(" 1.Enqueue\t 2.Dequeue\t 3.Display\t 4.Exit\n ");
		printf(" Enter Your Choice: ");
		scanf("%d", &var);
		switch(var)
		{
			case 1: printf("Enter a value: ");
				scanf("%d",&value);
				enqueue(value);
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: count++;
				printf("Exited...\n");
				return(0);
				break;
			default: printf("invalid Number!!!\n");
		}
	}
	return(0);
}
