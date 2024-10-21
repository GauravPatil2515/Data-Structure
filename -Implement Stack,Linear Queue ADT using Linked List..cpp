#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Stack operations using Linked List
struct Node* push(struct Node* top, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = top;
    top = temp;
    return top;
}

struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        struct Node* temp = top;
        printf("Popped: %d\n", top->data);
        top = top->next;
        free(temp);
    }
    return top;
}

void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("\nStack is empty\n");
    } else {
        printf("Stack: ");
        struct Node* temp = top;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Queue operations using Linked List
struct Node* enqueue(struct Node* rear, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if (rear != NULL) {
        rear->next = temp;
    }
    return temp;
}

struct Node* dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("\nQueue Underflow\n");
    } else {
        struct Node* temp = *front;
        printf("Dequeued: %d\n", temp->data);
        *front = (*front)->next;
        free(temp);
    }
    return *front;
}

void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("\nQueue is empty\n");
    } else {
        printf("Queue: ");
        struct Node* temp = front;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    struct Node* top = NULL;  // Stack top pointer
    struct Node* front = NULL;  // Queue front pointer
    struct Node* rear = NULL;  // Queue rear pointer
    int choice, value;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue to Queue\n");
        printf("5. Dequeue from Queue\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                displayStack(top);
                break;

            case 4:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                if (front == NULL) { // Queue is empty
                    front = rear = enqueue(rear, value);
                } else {
                    rear = enqueue(rear, value);
                }
                break;

            case 5:
                front = dequeue(&front);
                if (front == NULL) {
                    rear = NULL; // Queue is empty
                }
                break;

            case 6:
                displayQueue(front);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

