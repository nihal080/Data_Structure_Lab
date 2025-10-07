



#include<stdio.h>
#define MAX_SIZE 10

int Q[MAX_SIZE], FRONT = -1, REAR = -1;



void enque(int value){

	if (REAR >= MAX_SIZE - 1){
		printf("Queue is Full\n");
	} else {
		if ( FRONT == -1 && REAR == -1){
			FRONT = 0;
		}
		REAR += 1;
		
		Q[REAR] = value;
	}
}

void deque(){
	if (FRONT < 0){
		printf("Queue is Empty\n");
	}else{
		printf("Deleted Element is: %d\n", Q[FRONT]);
		if(FRONT == REAR){
			FRONT = -1;
			REAR = -1;
		}else{
			FRONT = FRONT + 1;
		}
	}
}

void display(){
	if (REAR >= 0){
		printf("Stack Elements are:\n");
		for (int i = REAR; i >= FRONT; i--){
			printf("%d\n", Q[i]);
		}
	} else {
		printf("QUEUE is empty\n");
	}
}


int main(){
	int count = 0, var, value;


	while (count != 1) {
	
		printf(" 1.Enque\n 2.Deque\n 3.Display\n 4.Exit\n Enter Your Choice: ");
		scanf("%d", &var);
		
		switch(var){
			case 1: printf("Enter a value: ");
					scanf("%d",&value);
					enque(value);
					break;
					
			case 2: deque();
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
