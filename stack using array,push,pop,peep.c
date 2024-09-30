#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

// Corrected function to insert at the beginning of the list
struct node* insertAtbeginning(struct node* head, int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("Memory allocation failed!\n");
		return head;
	}
	newnode->data = data;
	newnode->next = head;   // Link the new node with the current head
	head = newnode;         // Update the head to the new node
	return head;
}

// Function to print the list
void printList(struct node* head) 
{
	struct node* temp = head;
	while (temp != NULL) 
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main() 
{
	struct node* head = NULL;  // Initialize the head of the list
    
	// Insert nodes at the beginning
	head = insertAtbeginning(head, 10);
	head = insertAtbeginning(head, 20);
	head = insertAtbeginning(head, 30);

	// Print the updated list
	printList(head);  // Output: 30 -> 20 -> 10 -> NULL
    
	return 0;
}

