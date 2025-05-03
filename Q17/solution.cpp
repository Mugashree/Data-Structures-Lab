//Program to implement queue using linked list

#include <cstdio>
#include <cstdlib>

class Queue {
private:
    struct Node {
        char data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void Enqueue(char val);
    void Dequeue();
    void Peek();
    void Display();
    bool isEmpty();
};

int main() {
    Queue obj;

    while (1) {
        printf("\n\nMENU:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n");
        printf("4. Display\n5. Exit\n");

        int choice;
        char val;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the character to be added: ");
                scanf(" %c", &val);
                obj.Enqueue(val);
                break;

            case 2:
                obj.Dequeue();
                break;

            case 3:
                obj.Peek();
                break;

            case 4:
                obj.Display();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

bool Queue::isEmpty() {
    return front == nullptr;
}

void Queue::Enqueue(char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = val;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("'%c' enqueued successfully\n", val);
}

void Queue::Dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    Node* temp = front;
    char deleted = temp->data;

    front = front->next;
    free(temp);

    if (front == nullptr) {
        rear = nullptr;
    }

    printf("Dequeued element: '%c'\n", deleted);
}

void Queue::Peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Front element: '%c'\n", front->data);
}

void Queue::Display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    Node* current = front;
    while (current != nullptr) {
        printf("'%c' ", current->data);
        current = current->next;
    }
    printf("\n");
}

