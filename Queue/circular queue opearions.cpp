#include<stdio.h>
#include<unistd.h>

#define MAX 5

struct queue
{
	int data[MAX];
	int front;
	int rear;
};

void initialize(struct queue*q)
{
	q->front=0;
	q->rear=-1;
}

int isEmpty(struct queue*q)
{
	if (q->front ==-1)
	return 1;
	else
	return 0;
	
}

int isFull(struct queue*q)
{
	if(q->rear ==MAX-1 && q->front==0)
	return 1;
	else
	return 0;
	
}

int enqueue(struct queue*q, int d)
{
	if(isFull(q))
	return 0;
	else if (q->front ==-1 && q->rear == -1)
	{
		q->front = 0;
		q->rear =0;
	}
	else if(q->rear ==MAX -1 && q->front !=0)
	{
		q->rear = 0;
	}
	else
	{
		q->rear++;
	}
	q->data[q->rear]=d;
	return 1;
}

int  dequeue(struct queue*q ,int d)
{
	d=q->data[q->front];
	if(q->front == q->rear)
	 {
	 	q->front=q->rear = -1;
	 }
	else if (q->front == MAX -1)
	{
		q->front =0;
	}
	else 
	{
		q->front++;
		
	}
	printf("\n deleted data is %d",d);
}

void display(struct queue*q)
{
	int i;
	if (q->rear ==-1)
	printf("\n\t Queue is Empty");
	else 
	{
        printf("\n Queue Contents \n");
        for (i = q->rear; i > 0; i--) 
		{
            printf("%d\n", q->data[i]);
        }

    }
} 

int main() {
    int ch, d;
    struct queue q;
    initialize(&q);  // Initialize the queue

    while (1) {
        // Display the menu options
        printf("\n\t\t\tMENU\n1. Insert.\n2. Delete.\n3. Display.\n4. Exit.");
        printf("\n\tEnter your choice :: ");
        scanf("%d", &ch);  // Read the user’s choice

        switch (ch) {
            case 1:
                printf("\nEnter Data to be Inserted: ");
                scanf("%d", &d);  // Read the data to insert
                if (enqueue(&q, d))
                    printf("\n Inserted successfully");
                else
                    printf("\nCannot Insert..");
                break;
            case 2:
                if (isEmpty(&q))
                    printf("\n Queue Underflow");
                else
                    dequeue(&q, d);  // Dequeue data
                break;
            case 3:
                display(&q);  // Display the queue contents
                break;
            case 4:
                exit(0);  // Exit the program
            default:
                printf("\n\tPlease enter correct choice......");
        }
    }
}



