#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->data[++(s->top)] = value;
    } else {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

int evaluatePostfix(char *exp) {
    Stack s;
    initStack(&s);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (exp[i]) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
                default:
                    printf("Invalid operator encountered: %c\n", exp[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }
    return pop(&s);
}

int main() {
    char exp[MAX_STACK_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    int result = evaluatePostfix(exp);
    printf("The result is: %d\n", result);
    return 0;
}

