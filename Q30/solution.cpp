//Program to implement hash ADT using separate chaining


#include <stdio.h>
#include <list>


class HashADT {
private:
    int Size;
    std::list<int>* Hash;


public:
    HashADT(int Siz) {
        Size = Siz;
        Hash = new std::list<int>[Siz];
    }


    int Insert(int Value);
    int Deletion(int Value);
    int Search(int Value);
    void Display();
};


int main() {
    int Choice;
    int TableSize;


    printf("Enter the size of the hash table: ");
    scanf("%d", &TableSize);


    HashADT Object(TableSize);


    while (1) {
        printf("Enter your choice:\n");
        printf("\t1. To insert a value\n");
        printf("\t2. To delete a value\n");
        printf("\t3. To search for a value\n");
        printf("\t4. To display the hash table\n");
        printf("\t5. To exit\n");
        scanf("%d", &Choice);


        switch (Choice) {
            case 1: {
                int Value;
                printf("Enter the value to be inserted: ");
                scanf("%d", &Value);
                int Result = Object.Insert(Value);
                if (Result == 0) {
                    printf("Insertion was unsuccessful.\n");
                } else {
                    printf("Insertion was successful.\n");
                }
                break;
            }
            case 2: {
                int Value;
                printf("Enter the value to be deleted: ");
                scanf("%d", &Value);
                int Result = Object.Deletion(Value);
                if (Result == 0) {
                    printf("Deletion was unsuccessful.\n");
                } else if (Result == -1) {
                    printf("Deletion was unsuccessful. Element to be deleted was not found.\n");
                } else {
                    printf("Deletion was successful.\n");
                }
                break;
            }
            case 3: {
                int Value;
                printf("Enter the value to be searched: ");
                scanf("%d", &Value);
                int Result = Object.Search(Value);
                if (Result == -1) {
                    printf("Element was not found.\n");
                } else {
                    printf("Element was found at position: %d\n", Result);
                }
                break;
            }
            case 4:
                Object.Display();
                break;
            case 5:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }


    return 0;
}


int HashADT::Insert(int Value) {
    if (Size == 0) {
        printf("Hash table has no size.\n");
        return 0;
    }
    int Position = Value % Size;
    Hash[Position].push_back(Value);
    return 1;
}


int HashADT::Deletion(int Value) {
    if (Size == 0) {
        printf("Hash table has no size.\n");
        return 0;
    }
    int Position = Value % Size;
    for (auto it = Hash[Position].begin(); it != Hash[Position].end(); ++it) {
        if (*it == Value) {
            Hash[Position].erase(it);
            return 1;
        }
    }
    return -1;
}


int HashADT::Search(int Value) {
    if (Size == 0) {
        printf("Hash table has no size.\n");
        return -1;
    }
    int Position = Value % Size;
    for (auto it = Hash[Position].begin(); it != Hash[Position].end(); ++it) {
        if (*it == Value) {
            return Position;
        }
    }
    return -1;
}


void HashADT::Display() {
    for (int i = 0; i < Size; i++) {
        if (Hash[i].empty()) {
            printf("%d: [EMPTY]\n", i);
        } else {
            printf("%d: ", i);
            for (auto it = Hash[i].begin(); it != Hash[i].end(); ++it) {
                printf("%d -> ", *it);
            }
            printf("NULL\n");
        }
    }
}
