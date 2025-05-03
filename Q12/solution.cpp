// Program to implement stack ADT using singly linked list

#include <cstdio>
#include <cstdlib>

class Stack
{

struct node
{
char data;
struct node *next;
};

struct node *head;

public:

Stack()
{
head = NULL;
}

void Push(char val);
void Pop();
void Peek();
void Display();


};

int main() {
    Stack obj;

    while (1) {
        printf("\n\n\nMENU:\n");
        printf("1. Push\n2. Pop\n3. Peek\n");
        printf("4. Display\n5. Exit\n");

        int choice;
        char val;

        printf("\nEnter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the character to be pushed into the stack: \n");
                scanf(" %c", &val);
                obj.Push(val);
                break;

            case 2:
                obj.Pop();
                break;

            case 3:
                obj.Peek();
                break;

            case 4:
                obj.Display();
                break;

            case 5:
                printf("Exiting the program.....\n");
                return 0;

            default:
                printf("Invalid Input\n");
                break;
        }
    }
}

void Stack::Push(char val) {
    struct node* cur = head;
    int i = 0;

    while (cur != NULL) {
        cur = cur->next;
        i++;
    }

    if (i > 4) {
        printf("Stack Overflow");
        return;
    } else {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = head;
        head = newnode;
        printf("%c is pushed into the stack\n", val);
        return;
    }
}

void Stack::Pop() {
    if (head == NULL) {
        printf("The stack is empty.");
        return
