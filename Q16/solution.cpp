//Program  to implement circular queue

#include <cstdio>
#include <cstdlib>

class CircularQueue {
    char arr[5];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void Enqueue(char val);
    void Dequeue();
    void Peek();
    void Display();
    
private:
    bool isFull() {
        return (rear + 1) % 5 == front;
    }
};

int main() {
    CircularQueue obj;

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

void CircularQueue::Enqueue(char val) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }

    if (rear == -1) {
        front = 0;
    }
    
    rear = (rear + 1) % 5; 
    arr[rear] = val;
    
    printf("%c is added to the queue\n", val);
}

void CircularQueue::Dequeue() {
    if (rear == -1 || front > rear) {
        printf("The queue is empty\n");
        return;
    }

    char pop = arr[front];
    front = (front + 1) % 5; 

   if (front > rear) { 
       front = rear = -1; 
   }
   
   printf("The dequeued character is: %c\n", pop);
}

void CircularQueue::Peek() {
   if (rear == -1 || front > rear) {
       printf("The queue is empty\n");
       return;
   }

   printf("The front element is %c\n", arr[front]);
}

void CircularQueue::Display() {
   if (front == -1 || front > rear) {
       printf("The queue is empty\n");
       return;
   }

   printf("Queue elements are: \n");
   for (int i = front; i <= rear; i++) {
       printf("%c ", arr[i]);
   }
}
