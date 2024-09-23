
#include<stdio.h> 

#include<unistd.h> 

#define MAX 5 

 

struct queue 

{ 

int data[MAX]; 

int front; 

int rear; 

}; 

 

void initialize(struct queue *s) 

{ 

s->front=0; 

s->rear=-1; 

} 

 

int isEmpty(struct queue *s) 

{ 

if(s->front==-1)			 

return 1; 

else 

return 0; 

} 

 

int isFull(struct queue *s) 

{ 

if(s->rear==MAX-1) 

return 1; 

else 

return 0; 

} 

 

int enqueue(struct queue *s,int d) 

{ 

if(isFull(s)) 

return 0; 

else 

{ 

s->rear++; 

s->data[s->rear]=d; 

return 1;	 

} 

} 

 

 

void dequeue(struct queue *s) 

{ 

if( isEmpty(s)) 

printf("\n\tStack Underflows->"); 

else 

{ 

int d; 

d=s->data[s->front]; 

s->front++;		 

printf("\nDequeue Data is %d",d); 

} 

} 

 

 

 

void display(struct queue *s) 

{ 

int i; 

if(isEmpty(s)) 

printf("\n\tStack is Empty->"); 

else 

{ 

printf("\nStack Contents ->->\n"); 

for(i=s->front;i<= s->rear;i++) 

{ 

printf("%d\n",s->data[i]); 

} 

} 

} 

 

int main() 

{ 

int ch,d; 

struct queue s; 

initialize(&s); 

while(1) 

{ 

printf("\n\t\t\tMENU\n1. enqueue.\n2. dequeue"); 

printf("\n3. Display.\n4. Exit."); 

printf("\n\tEnter your choice :: "); 

scanf("%d",&ch); 

switch(ch) 

{ 

case 1: 

printf("\nEnter Data to be queued : "); 

scanf("%d",&d); 

if(enqueue(&s,d)) 

printf("\nQueued successfully"); 

else 

printf("\nCannot dequeued.."); 

break; 

case 2: 

dequeue(&s); 

break; 

case 3: 

display(&s); 

break; 

case 4: 

exit(0); 

default: 

printf("\n\tPlease enter correct choice->->->->"); 

} 

} 

}   
