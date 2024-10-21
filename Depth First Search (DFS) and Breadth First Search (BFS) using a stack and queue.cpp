#include <stdio.h>
#include <stdlib.h>  // Include for exit function
#define MAX 20

// Stack structure for DFS
struct stack {
    int data[MAX];
    int top;
};

// Queue structure for BFS
struct Queue {
    int data[MAX];
    int front, rear;
};

// Stack functions
void push(struct stack *s, int d) {
    if (s->top == MAX - 1) {
        printf("\n\tStack Overflows->");
    } else {
        s->data[++s->top] = d;    
    }
}

int pop(struct stack *s) {
    if (s->top == -1) {
        printf("\n\tStack Underflows->");
        return -1; // Return -1 to indicate error
    } else {
        return s->data[s->top--];
    }
}

void initialize(struct stack *s) {
    s->top = -1;
}

// Queue functions
void insert(struct Queue *q, int d) {
    if (q->rear == MAX - 1) {
        printf("\n\tQueue is Full->");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->data[++q->rear] = d;
    }
}

void initializeQ(struct Queue *q) {
    q->front = q->rear = -1;
}

int queue_delete(struct Queue *q) {  // Renamed from delete to queue_delete
    if (q->front == -1) {
        printf("\nQueue is empty..");
        return -1; // Return -1 to indicate error
    } else {
        int d = q->data[q->front++];
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return d;
    }
}

// DFS algorithm using stack
void dfs(int a[][10], int n) {
    struct stack s;
    int visited[10] = {0};  // Initialize visited array to track visited nodes
    int i, j, v;
    initialize(&s);
    visited[0] = 1;  // Start from the first vertex (0)
    printf("\n\t\tDFS Traversal :\n0\t");
    push(&s, 0);
    
    while (s.top != -1) {  // Until stack is not empty
        v = -1;
        // Get an unvisited vertex adjacent to the stack's top element
        for (j = 0; j < n; j++) {
            if (a[s.data[s.top]][j] == 1 && visited[j] == 0) {
                v = j;
                break;
            }
        }
        if (v == -1) {  // No adjacent unvisited vertex found, pop from the stack
            pop(&s);
        } else {  // Adjacent unvisited vertex found
            visited[v] = 1;  // Mark vertex as visited
            printf("%d\t", v);  // Print the visited vertex
            push(&s, v);  // Push the vertex onto the stack
        }
    }
}

// BFS algorithm using queue
void bfs(int a[][10], int n) {
    struct Queue q;
    int visited[10] = {0};  // Initialize visited array to track visited nodes
    int i, j, v;
    initializeQ(&q);
    visited[0] = 1;  // Start from the first vertex (0)
    printf("\n\t\tBFS Traversal :\n0\t");
    insert(&q, 0);
    
    while (q.front != -1) {  // Until queue is not empty
        v = queue_delete(&q);  // Dequeue the vertex
        if (v != -1) {
            // Get an unvisited vertex adjacent to the dequeued vertex
            for (j = 0; j < n; j++) {
                if (a[v][j] == 1 && visited[j] == 0) {
                    visited[j] = 1;  // Mark vertex as visited
                    printf("%d\t", j);  // Print the visited vertex
                    insert(&q, j);  // Enqueue the vertex
                }
            }
        }
    }
}

// Main function with menu
int main() {
    int n, i, j, ch;
    int a[10][10];  // Adjacency matrix

    while (1) {    
        printf("\n\n\t\tMENU\n1. Make Graph.\n2. DFS.\n3. BFS.\n4. Exit.");
        printf("\n\tEnter Your Choice :: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:  // Create a graph (adjacency matrix)
                printf("\nENTER THE NUMBER OF VERTICES :: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("\nEnter 1 if %d has an Edge with %d else 0: ", i + 1, j + 1);
                        scanf("%d", &a[i][j]);
                    }
                }
                printf("\n\nTHE ADJACENCY MATRIX IS\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("\t%d", a[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:  // DFS traversal
                dfs(a, n);
                break;

            case 3:  // BFS traversal
                bfs(a, n);
                break;

            case 4:  // Exit
                exit(0);

            default:  // Invalid input
                printf("\nInvalid choice. Please try again.");
        }
    }
    return 0;
}

