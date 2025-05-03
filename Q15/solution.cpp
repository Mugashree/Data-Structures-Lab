//Program to implement queue

#include <cstdio>
#include <cstdlib>

class Queue {
    char arr[5];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void Enqueue(char val);
    void Dequeue();
    void Peek();
    void Display();
};

int main() {
    Queue obj;

    while (1) {
        printf("\n\nMENU:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");

        int choice;
        char val;
        printf("\nEnter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the character to be added into the queue: \n");
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
                printf("Exiting the program.....\n");
                return 0;

            default:
                printf("Invalid Input\n");
                break;
        }
    }
}

void Queue::Enqueue(char val) {
    if (rear == 4) {
        printf("Queue is full\n");
        return;
    }

    if (rear == -1) {
        front = 0;
    }
    
    rear++;
    arr[rear] = val;
    printf("%c is added to the queue\n", val);
}

void Queue::Dequeue() {
    if (rear == -1 || front > rear) {
        printf("The queue is empty\n");
        return;
    }

    char pop = arr[front];
    front++;
    printf("The dequeued character is: %c\n", pop);
}

void Queue::Peek() {
    if (rear == -1 || front > rear) {
        printf("The queue is empty\n");
        return;
    }

    printf("The front element is %c\n", arr[front]);
}

void Queue::Display() {
    if (front == -1 || front > rear) {
        printf("The queue is empty\n");
        return;
    }

    printf("Queue elements are: \n");
    for (int i = front; i <= rear; i++) {
        printf("%c ", arr[i]);
    }
}
