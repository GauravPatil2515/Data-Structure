#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50

// Define a stack structure for characters
struct stack {
    char data[MAX];
    int top;
};

// Check if the stack is empty
bool empty(struct stack *s) {
    return (s->top == -1);
}

// Push an element onto the stack
void push(struct stack *s, char ele) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = ele;
    } else {
        printf("\nStack Overflow.");
        exit(EXIT_FAILURE);
    }
}

// Pop an element from the stack
char pop(struct stack *s) {
    if (!empty(s)) {
        return s->data[s->top--];
    } else {
        return (char)-1;
    }
}

// Get the precedence of an operator
int precedence(char a) {
    switch (a) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
        case '$':
            return 3;
        default:
            return 0;
    }
}

// Convert infix expression to postfix expression
char *convert(const char *expr) {
    struct stack st;
    st.top = -1; // Initialize the stack
    int n = strlen(expr);
    char *pexpr = (char *)malloc(n + 1); // Allocate memory for postfix expression
    if (pexpr == NULL) {
        printf("\nMemory allocation failed.");
        exit(EXIT_FAILURE);
    }
    char c, sc = '\0';
    int i, j;

    for (i = 0, j = 0; expr[i] != '\0'; i++) {
        c = expr[i];
        switch (c) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '$':
                while (!empty(&st) && precedence(st.data[st.top]) >= precedence(c)) {
                    sc = pop(&st);
                    pexpr[j++] = sc;
                }
                push(&st, c);
                break;
            case '(':
                push(&st, c);
                break;
            case ')':
                while ((sc = pop(&st)) != '(') {
                    pexpr[j++] = sc;
                }
                break;
            default:
                pexpr[j++] = c;
                break;
        }
    }
    // Pop remaining elements from the stack
    while (!empty(&st)) {
        pexpr[j++] = pop(&st);
    }
    pexpr[j] = '\0'; // Null-terminate the postfix expression
    return pexpr;
}

int main() {
    char infix[MAX];
    char *postfix;

    printf("\nEnter Infix expression : ");
    scanf("%s", infix);

    postfix = convert(infix);
    printf("\nPostfix conversion is : %s\n", postfix);

    free(postfix); // Free the allocated memory
    return 0;
}
