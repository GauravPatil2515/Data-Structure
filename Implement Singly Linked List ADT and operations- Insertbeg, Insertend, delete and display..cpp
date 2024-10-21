#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct SLL
{
	int data;
	struct SLL*next;
};


struct SLL *insertAtEnd(struct SLL *h, int d) {
    struct SLL *p, *tmp;
    p = (struct SLL *)malloc(sizeof(struct SLL)); // create a new node
    if (p == NULL) {
        printf("\nNot enough memory to allocate.");
        return h;
    }
    p->data = d;   // assign data
    p->next = NULL; // set next as NULL, since it will be the last node
    if (h == NULL) // if the list is empty
        h = p;
    else {
        tmp = h;
        while (tmp->next != NULL) // traverse to the last node
            tmp = tmp->next;
        tmp->next = p; // link the new node at the end
    }
    return h;
}




struct SLL *insertAtStart(struct SLL *h, int d) {
    struct SLL *p;
    p = (struct SLL *)malloc(sizeof(struct SLL)); // create a new node
    p->data = d;    // assign data
    p->next = h;    // link the new node to the current head
    h = p;          // update the head to the new node
    return h;
}



struct SLL *insertAfter(struct SLL *h, int key, int d) {
    struct SLL *p, *tmp;
    p = (struct SLL *)malloc(sizeof(struct SLL)); // create a new node
    p->data = d;    // assign data
    p->next = NULL; // set next to NULL
    if (h == NULL) {
        h = p;      // if list is empty, new node becomes head
    } else {
        tmp = h;
        while (tmp != NULL && tmp->data != key) // traverse to find the key node
            tmp = tmp->next;
        if (tmp != NULL) {
            p->next = tmp->next;  // link new node to the next node
            tmp->next = p;        // link key node to the new node
        } else {
            printf("\n\tGiven Node %d does not exist in the Linked List.", key);
            free(p);  // if key is not found, free the allocated node
        }
    }
    return h;
}


struct SLL *removelast(struct SLL *h) {
    struct SLL *tmp, *prev;
    tmp = h;
    if (h != NULL) {
        if (h->next != NULL) { // more than one node
            while (tmp->next != NULL) {
                prev = tmp;
                tmp = tmp->next;
            }
            prev->next = NULL; // remove the last node
        } else
            h = NULL; // single node case, set head to NULL
        free(tmp);
    } else
        printf("\nLL is empty.");
    return h;
}


struct SLL *removefirst(struct SLL *h) {
    struct SLL *tmp;
    tmp = h;
    if (h != NULL) {
        h = h->next; // move head to the next node
        free(tmp);   // delete the old head
    } else
        printf("\nLL is empty.");
    return h;
}



struct SLL *removeAfter(struct SLL *h, int key) {
    struct SLL *tmp, *p;
    tmp = h;
    if (h != NULL) {
        while (tmp != NULL && tmp->data != key)
            tmp = tmp->next;
        if (tmp != NULL) {
            if (tmp->next != NULL) {
                p = tmp->next;
                tmp->next = p->next; // bypass the node to be removed
                p->next = NULL;
                free(p);
            } else
                printf("\nGiven Node is the last Node.");
        } else
            printf("\nGiven key does not exist.");
    } else
        printf("\nLL is empty.");
    return h;
}



void display(struct SLL *h) {
    struct SLL *tmp;
    tmp = h;
    if (h != NULL) {
        printf("\n\n\t\tLinked List Contents..\n");
        while (tmp != NULL) {
            printf("\t%d\n", tmp->data); // print each node's data
            tmp = tmp->next; // move to the next node
        }
    } else {
        printf("\nLL is empty.");
    }
}




int main() {
    struct SLL *head;
    int ch, d, k;
    head = NULL;
    while (1) {
        printf("\n\n\n\t\t\tMENU");
        printf("\n1. Insert at End.\n2. Insert at Start.\n3. Insert After.\n4. Remove First.\n5. Remove Last.\n6. Remove After.\n7. Display.\n8. Exit.");
        printf("\n\tEnter Your Choice :: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("\n\tEnter Data : ");
            scanf("%d", &d);
            head = insertAtEnd(head, d);
            break;
        case 2:
            printf("\n\tEnter Data : ");
            scanf("%d", &d);
            head = insertAtStart(head, d);
            break;
        case 3:
            printf("\n\tEnter Data : ");
            scanf("%d", &d);
            printf("\n\tEnter Key Data : ");
            scanf("%d", &k);
            head = insertAfter(head, k, d);
            break;
        case 4:
            head = removefirst(head);
            break;
        case 5:
            head = removelast(head);
            break;
        case 6:
            printf("\n\tEnter Key : ");
            scanf("%d", &d);
            head = removeAfter(head, d);
            break;
        case 7:
            display(head);
            break;
        case 8:
            return 0;
        default:
            printf("\n\t\tPlease enter a correct choice....");
        }
    }
    return 0;
}

