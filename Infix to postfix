#include <stdio.h> 

#include <stdlib.h> 

#define MAX 5  // Define the maximum size of the stack 

 

// Define the stack structure 

struct stack { 

    int data[MAX]; 

    int top; 

}; 

 

// Function to initialize the stack 

void initialize(struct stack *s) { 

    s->top = -1; 

} 

 

// Function to check if the stack is empty 

int isEmpty(struct stack *s) { 

    return s->top == -1; 

} 

 

// Function to check if the stack is full 

int isFull(struct stack *s) { 

    return s->top == MAX - 1; 

} 

 

// Function to push an element onto the stack 

int push(struct stack *s, int d) { 

    if (isFull(s)) { 

        return 0;  // Stack is full 

    } else { 

        s->top++; 

        s->data[s->top] = d; 

        return 1;  // Push operation successful 

    } 

} 

 

// Function to pop an element from the stack 

void pop(struct stack *s) { 

    if (isEmpty(s)) { 

        printf("\n\tStack Underflows->"); 

    } else { 

        int d = s->data[s->top]; 

        s->top--; 

        printf("\nPopped Data is %d", d); 

    } 

} 

 

// Function to peek at the top element of the stack 

void peek(struct stack *s) { 

    if (isEmpty(s)) { 

        printf("\n\tStack Underflows->"); 

    } else { 

        int d = s->data[s->top]; 

        printf("\nData at peek is %d", d); 

    } 

} 

 

// Function to display the contents of the stack 

void display(struct stack *s) { 

    if (isEmpty(s)) { 

        printf("\n\tStack is Empty->"); 

    } else { 

        printf("\nStack Contents ->->\n"); 

        for (int i = s->top; i >= 0; i--) { 

            printf("%d\n", s->data[i]); 

        } 

    } 

} 

 

// Main function to test the stack operations 

int main() { 

    int ch, d; 

    struct stack s; 

    initialize(&s); 

    while (1) { 

        printf("\n\t\t\tMENU\n1. Push.\n2. Pop.\n3. Peek."); 

        printf("\n4. Display.\n5. Exit."); 

        printf("\n\tEnter your choice :: "); 

        scanf("%d", &ch); 

        switch (ch) { 

            case 1: 

                printf("\nEnter Data to be Pushed : "); 

                scanf("%d", &d); 

                if (push(&s, d)) 

                    printf("\nPushed successfully"); 

                else 

                    printf("\nCannot Push.. Stack is full."); 

                break; 

            case 2: 

                pop(&s); 

                break; 

            case 3: 

                peek(&s); 

                break; 

            case 4: 

                display(&s); 

                break; 

            case 5: 

                exit(0); 

            default: 

                printf("\n\tPlease enter correct choice->->->->"); 

        } 

    } 

    return 0; 

} 
