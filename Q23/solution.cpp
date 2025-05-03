// Program to implement Tree ADT using Binary Search Tree


#include <stdio.h>
#include <stdlib.h>


class BinarySearchTree {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };


    Node* root;


    BinarySearchTree() {
        root = NULL;
    }


    void insert(int data) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            printf("Memory error\n");
            return;
        }
        newNode->data = data;
        newNode->left = newNode->right = NULL;


        if (root == NULL) {
            root = newNode;
            return;
        }


        Node* current = root;
        Node* parent = NULL;


        while (current != NULL) {
            parent = current;
            if (data < current->data) {
                current = current->left;
            } else if (data > current->data) {
                current = current->right;
            } else {
                printf("Duplicate value not allowed.\n");
                free(newNode);
                return;
            }
        }


        if (data < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }


    void preorder(Node* rootNode) {
        if (rootNode != NULL) {
            printf("%d ", rootNode->data);
            preorder(rootNode->left);
            preorder(rootNode->right);
        }
    }


    void inorder(Node* rootNode) {
        if (rootNode != NULL) {
            inorder(rootNode->left);
            printf("%d ", rootNode->data);
            inorder(rootNode->right);
        }
    }


    void postorder(Node* rootNode) {
        if (rootNode != NULL) {
            postorder(rootNode->left);
            postorder(rootNode->right);
            printf("%d ", rootNode->data);
        }
    }


    Node* search(int data) {
        Node* current = root;
        while (current != NULL) {
            if (data == current->data) {
                return current;
            } else if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return NULL;
    }


    Node* getRoot() {
        return root;
    }
};


void displayMenu() {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Search\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}


int main() {
    BinarySearchTree bst;
    int choice, data;


    do {
        displayMenu();
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                bst.insert(data);
                break;
            case 2:
                printf("Preorder traversal: ");
                bst.preorder(bst.getRoot());
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal: ");
                bst.inorder(bst.getRoot());
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                bst.postorder(bst.getRoot());
                printf("\n");
                break;
            case 5:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                if (bst.search(data) != NULL) {
                    printf("%d found in the tree.\n", data);
                } else {
                    printf("%d not found in the tree.\n", data);
                }
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);


    return 0;
}


