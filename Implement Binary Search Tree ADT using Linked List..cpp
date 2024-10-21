#include<stdio.h>
#include<stdlib.h>

struct bstree {
    int data;
    struct bstree *left, *right;
};

struct bstree* insert(struct bstree* root, int d) {
    if (root == NULL) {
        struct bstree* p = (struct bstree*)malloc(sizeof(struct bstree));
        p->data = d;
        p->left = p->right = NULL;
        return p;
    }
    if (d < root->data)
        root->left = insert(root->left, d);
    else
        root->right = insert(root->right, d);
    return root;
}

void inorder(struct bstree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct bstree* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct bstree* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct bstree* search(struct bstree* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int ch, d;
    struct bstree* root = NULL;
    while (1) {
        printf("\nMENU\n1. Insert\n2. In-order\n3. Pre-order\n4. Post-order\n5. Search\n6. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &d);
                root = insert(root, d);
                break;
            case 2:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter key to search: ");
                scanf("%d", &d);
                struct bstree* result = search(root, d);
                if (result == NULL)
                    printf("Key not found.\n");
                else
                    printf("Key found: %d\n", result->data);
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}

