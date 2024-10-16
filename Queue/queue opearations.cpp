#include <stdio.h>
#define MAX 5

struct queue {
    int data[MAX];
    int front;
    int rear;
};

void initialize(struct queue *s) {
    s->front = 0;
    s->rear = -1;
}

int isEmpty(struct queue *s) {
    return s->front > s->rear;
}

int isFull(struct queue *s) {
    return s->rear == MAX - 1;
}

int enqueue(struct queue *s, int d) {
    if (isFull(s)) {
        return 0;
    } else {
        s->rear++;
        s->data[s->rear] = d;
        return 1;
    }
}

void dequeue(struct queue *s) {
    if (isEmpty(s)) {
        printf("\n\tQueue Underflow");
    } else {
        int d = s->data[s->front];
        s->front++;
        printf("\nDequeued data: %d", d);
    }
}

void display(struct queue *s) {
    if (isEmpty(s)) {
        printf("\nQueue is empty");
    } else {
        printf("\nQueue content:\n");
        for (int i = s->front; i <= s->rear; i++) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch, d;
    struct queue s;
    initialize(&s);
    
    while (1) {
        printf("\nMenu\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("\nEnter data to be queued: ");
                scanf("%d", &d);
                if (enqueue(&s, d)) {
                    printf("\nQueued successfully");
                } else {
                    printf("\nCannot enqueue, queue is full.");
                }
                break;
            case 2:
                dequeue(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                return 0;  // Exit the program
            default:
                printf("\nPlease enter the correct choice -> -> -> ->");
        }
    }
}

