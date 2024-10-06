#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to delete the head node
struct Node* deleteFromBeginning(struct Node* head) {
    // If the list is empty, return the same
    if (head == NULL) {
        printf("List is already empty.\n");
        return head;
    }

    // Store the current head node in a temporary pointer
    struct Node* temp = head;

    // Move the head pointer to the next node
    head = head->next;

    // Free the memory of the old head node
    free(temp);

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

// Helper function to insert a node at the end (for testing purposes)
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    
    return head;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the end for testing
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Original List: ");
    printList(head);  // Output: 10 -> 20 -> 30 -> NULL

    // Delete the head node
    head = deleteFromBeginning(head);

    printf("After Deleting Head: ");
    printList(head);  // Output: 20 -> 30 -> NULL

    return 0;
}
