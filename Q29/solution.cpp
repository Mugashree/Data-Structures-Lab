//Program to implement hash ADT using quadratic probing


#include <cstdio>


#define size 11


class HashTable {
private:
    int table[size];
    int empty = -1;
    int del = -2;
    int count = 0;


public:
    int hash(int key);
    void Insert(int key);
    void Delete(int key);
    void Search(int key);
    void Display();
    void Initialize();
};


int main() {
    HashTable hashTable;
    hashTable.Initialize();


    int chc, key;


    while (1) {
        printf("\n\n MENU: \n");
        printf(" 1. Insert \n 2. Delete \n 3. Search \n 4. Display \n 5. Exit \n");
        printf("Enter your choice: \n");
        scanf("%d", &chc);


        switch (chc) {
            case 1:
                printf("Enter the key to be inserted: \n");
                scanf("%d", &key);
                hashTable.Insert(key);
                break;


            case 2:
                printf("Enter the key to be deleted: \n");
                scanf("%d", &key);
                hashTable.Delete(key);
                break;


            case 3:
                printf("Enter the key to be searched: \n");
                scanf("%d", &key);
                hashTable.Search(key);
                break;


            case 4:
                hashTable.Display();
                break;


            case 5:
                printf("Exiting the program...\n");
                return 0;
                break;


            default:
                printf("Invalid choice. \n");
        }
    }


    return 0;
}


int HashTable::hash(int key) {
    return key % size;
}


void HashTable::Insert(int key) {
    if (count == size) {
        printf("The table is full.\n");
        return;
    }


    int index = hash(key);
    for (int i = 0; i < size; i++) {
        int pos = (index + i * i) % size;
        if (table[pos] == empty || table[pos] == del) {
            table[pos] = key;
            count++;
            printf("%d is inserted at index %d\n", key, pos);
            return;
        }
    }


    printf("Insertion failed.\n");
}


void HashTable::Delete(int key) {
    int index = hash(key);


    for (int i = 0; i < size; i++) {
        int pos = (index + i * i) % size;
        if (table[pos] == empty) {
            break;
        }
        if (table[pos] == key) {
            table[pos] = del;
            count--;
            printf("%d deleted at %d position\n", key, pos);
            return;
        }
    }
    printf("%d is not found in the table.\n", key);
}


void HashTable::Search(int key) {
    int index = hash(key);
    for (int i = 0; i < size; i++) {
        int pos = (index + i * i) % size;
        if (table[pos] == key) {
            printf("%d is found at %d position\n", key, pos);
            return;
        }
    }
    printf("%d is not found in the table\n", key);
}


void HashTable::Display() {
    printf("HASH TABLE: \n");
    for (int i = 0; i < size; i++) {
        if (table[i] == empty) {
            printf("[%d] : EMPTY\n", i);
        }
        else if (table[i] == del) {
            printf("[%d] : DELETED\n", i);
        }
        else {
            printf("[%d] : %d\n", i, table[i]);
        }
    }
}


void HashTable::Initialize() {
    for (int i = 0; i < size; i++) {
        table[i] = empty;
    }
}
