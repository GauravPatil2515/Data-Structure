#include <stdio.h>
#include <stdlib.h>

struct SLL {
    int data;
    struct SLL *next;
};

struct SLL* insertAtEnd(struct SLL* h, int d) {
    struct SLL* p = (struct SLL*)malloc(sizeof(struct SLL));
    if (p == NULL) {
        printf("\nNot enough memory to allocate.");
        return h;
    }
    p->data = d;
    if (h == NULL) {
        p->next = p;
        h = p;
    } else {
        struct SLL* tmp = h;
        while (tmp->next != h)
            tmp = tmp->next;
        tmp->next = p;
        p->next = h;
    }
    return h;
}

struct SLL* insertAtStart(struct SLL* h, int d) {
    struct SLL* p = (struct SLL*)malloc(sizeof(struct SLL));
    if (p == NULL) {
        printf("\nNot enough memory to allocate.");
        return h;
    }
    p->data = d;
    if (h == NULL) {
        p->next = p;
        h = p;
    } else {
        struct SLL* tmp = h;
        while (tmp->next != h)
            tmp = tmp->next;
        p->next = h;
        tmp->next = p;
        h = p;
    }
    return h;
}

struct SLL* insertAfter(struct SLL* h, int key, int d) {
    struct SLL* p = (struct SLL*)malloc(sizeof(struct SLL));
    p->data = d;
    if (h == NULL) {
        p->next = p;
        h = p;
    } else {
        struct SLL* tmp = h;
        do {
            if (tmp->data == key) {
                p->next = tmp->next;
                tmp->next = p;
                return h;
            }
            tmp = tmp->next;
        } while (tmp != h);
        printf("\n\tGiven Node %d does not exist in the Circular Linked List.", key);
        free(p);
    }
    return h;
}

struct SLL* removeLast(struct SLL* h) {
    if (h != NULL) {
        if (h->next == h) {
            free(h);
            return NULL;
        } else {
            struct SLL* tmp = h;
            while (tmp->next->next != h)
                tmp = tmp->next;
            struct SLL* prev = tmp->next;
            tmp->next = h;
            free(prev);
        }
    } else {
    }
    return h;
}

struct SLL* removeFirst(struct SLL* h) {
    if (h != NULL) {
        if (h->next == h) {
            free(h);
            return NULL;
        } else {
            struct SLL* last = h;
            while (last->next != h)
                last = last->next;
            struct SLL* tmp = h;
            h = h->next;
            last->next = h;
            free(tmp);
        }
    } else {
        printf("\nLL is empty.");
    }
    return h;
}

struct SLL* removeAfter(struct SLL* h, int key) {
    if (h != NULL) {
        struct SLL* tmp = h;
        do {
            if (tmp->data == key) {
                struct SLL* p = tmp->next;
                if (p == h) {
                    return removeFirst(h);
                }
                tmp->next = p->next;
                free(p);
                return h;
            }
            tmp = tmp->next;
        } while (tmp != h);
        printf("\nGiven key does not exist.");
    } else {
        printf("\nLL is empty.");
    }
    return h;
}

void display(struct SLL* h) {
    if (h != NULL) {
        printf("\n\n\t\tCircular Linked List Contents..\n");
        struct SLL* tmp = h;
        do {
            printf("\t%d\n", tmp->data);
            tmp = tmp->next;
        } while (tmp != h);
    } else {
        printf("\nLL is empty.");
    }
}

int main() {
    struct SLL* head = NULL;
    int ch, d, k;
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
            head = removeFirst(head);
            break;
        case 5:
            head = removeLast(head);
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

