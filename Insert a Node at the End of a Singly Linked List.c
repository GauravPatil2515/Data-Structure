#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) { // Check for memory allocation failure
        printf("Memory allocation failed!\n");
        return head;
    }
    newNode->data = data;  // Assign data to the new node
    newNode->next = NULL;  // Set the next of new node to NULL (since it will be the last node)

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Traverse the list to find the last node
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;  // Link the last node to the new node
    }

    return head;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;  // Initialize the head of the list
    
    // Insert nodes at the end
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    // Print the updated list
    printList(head);  // Output: 10 -> 20 -> 30 -> NULL
    
    return 0;
}

