// Menu Driven Program to implement List ADT in array

#include <cstdio>

class List {
    int cur;
    int arr[5];

public:
    List() { cur = -1; }

    void InsertBeg(int);
    void InsertEnd(int);
    void InsertPos(int, int);
    void DelBeg();
    void DelEnd();
    void DelPos(int);
    void Search(int);
    void Rotate(int);
    void Display();
};

int main() {
    List obj;

    while (1) {
        printf("\n\nMENU:\n");
        printf("1.Insert Beginning\n2.Insert End\n3. Insert Position\n");
        printf("4. Delete Beginning\n5. Delete End\n6. Delete Position\n");
        printf("7. Search\n8. Display\n9. Rotate\n10. Exit\n ");

        int choice;
        int num;
        int pos;
        printf("\nEnter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to be inserted at the beginning: \n");
                scanf("%d", &num);
                obj.InsertBeg(num);
                break;
            case 2:
                printf("Enter the number to be inserted at the end: \n");
                scanf("%d", &num);
                obj.InsertEnd(num);
                break;
            case 3:
                printf("Enter the number to be inserted at the position: \n");
                scanf("%d", &num);
                printf("Enter the position where the number should be inserted: \n");
                scanf("%d", &pos);
                obj.InsertPos(num, pos);
                break;
            case 4:
                obj.DelBeg();
                break;
            case 5:
                obj.DelEnd();
                break;
            case 6:
                printf("Enter the position where the number should be deleted: \n");
                scanf("%d", &pos);
                obj.DelPos(pos);
                break;
            case 7:
                printf("Enter the number to be searched in the array: \n");
                scanf("%d", &num);
                obj.Search(num);
                break;
            case 8:
                printf("The array is: ");
                obj.Display();
                break;
            case 9:
                printf("Enter the number of rotations to be implemented: \n");
                scanf("%d", &num);
                obj.Rotate(num);
                break;
            case 10:
                printf("Exiting the program.... \n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}

void List::InsertBeg(int num) {
    if (cur == 4) {
        printf("The list is full\n");
        return;
    }
    for (int i = cur; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = num;
    cur++;
}

void List::InsertEnd(int num) {
    if (cur == 4) {
        printf("The list is full\n");
        return;
    }
    arr[++cur] = num;
}

void List::InsertPos(int num, int pos) {
    if (cur == 4 || pos < 0 || pos > cur) {
        printf("Invalid position or list is full.\n");
        return;
    }
    if (pos == cur) {
        InsertEnd(num);
        return;
    }
    for (int i = cur; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    cur++;
}

void List::DelBeg() {
    if (cur == -1) {
        printf("The list is empty.\n");
        return;
    }
    for (int i = 0; i < cur; i++) {
        arr[i] = arr[i + 1];
    }
    cur--;
}

void List::DelEnd() {
    if (cur == -1) {
        printf("The list is empty.\n");
        return;
    }
    cur--;
}

void List::DelPos(int pos) {
    if (cur == -1) {
        printf("The list is empty.\n");
        return;
    }
    if (pos < 0 || pos >= cur) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos; i < cur - 1; i++) {
        arr[i] = arr[i + 1];
    }
    cur--;
}

void List::Search(int num) {
    if (cur == -1) {
        printf("The list is empty.\n");
        return;
    }
    for (int i = 0; i <= cur; i++) {
        if (arr[i] == num) {
            printf("The number %d has been found at position %d\n", num, i);
            return;
        }
    }
    printf("The number %d is not present in the list.\n", num);
}

void List::Rotate(int num) {
    if (cur == -1) {
        printf("The list is empty\n");
        return;
    }
    num = num % (cur + 1);
    if (num == 0) return;
    for (int i = 0; i < num; i++) {
        int temp = arr[cur];
        for (int j = cur; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

void List::Display() {
    if (cur == -1) {
        printf("The list is empty.\n");
        return;
    }
    for (int i = 0; i <= cur; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
