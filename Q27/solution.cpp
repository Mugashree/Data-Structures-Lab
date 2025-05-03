//Implementing priority queue using max tree


#include <cstdio>
#include <cstdlib>


class TreeADT {
    int cur;
    int tree[50];
public:
    TreeADT() {
        cur = -1;
        for (int i = 0; i < 50; i++) {
            tree[i] = 0;
        }
    }


    void insert(int);
    bool search(int, int);
    int deletion();
    void heapify_down();
    void heapify_up();
    void display();
    int* heap_sort(int &size);
    bool isempty();
};


int main() {
    int chc;
    TreeADT obj;
    do {
        printf("\nEnter:\n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Search\n\t5. Sort (Heap Sort)\n\t6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &chc);


        switch (chc) {
            case 1: {
                int val;
                printf("Enter the integer to be inserted: ");
                scanf("%d", &val);
                obj.insert(val);
                break;
            }
            case 2: {
                int ret = obj.deletion();
                if (ret != -9999) {
                    printf("Deletion successful. Deleted element: %d\n", ret);
                }
                break;
            }
            case 3: {
                obj.display();
                break;
            }
            case 4: {
                int key;
                printf("Enter the element to be searched: ");
                scanf("%d", &key);
                bool ret = obj.search(1, key);
                if (ret == false) {
                    printf("The element was not found.\n");
                } else {
                    printf("The element was found.\n");
                }
                break;
            }
            case 5: {
                int size;
                int* arr = obj.heap_sort(size);
                if (arr == NULL) {
                    break;
                }
                printf("Sorted elements (descending): ");
                for (int i = 1; i <= size; i++) {
                    printf("%d  ", arr[i]);
                }
                printf("\n");
                delete[] arr;
                break;
            }
            case 6: {
                exit(0);
            }
            default: {
                printf("Invalid input. Please try again.\n");
            }
        }
    } while (1);


    return 0;
}


bool TreeADT::isempty() {
    return cur == -1;
}


void TreeADT::insert(int data) {
    if (cur == -1) {
        tree[1] = data;
        cur = 1;
    } else {
        cur++;
        tree[cur] = data;
        heapify_up();
    }
}


void TreeADT::heapify_up() {
    int i = cur;
    while (i > 1 && tree[i / 2] < tree[i]) {
        int temp = tree[i / 2];
        tree[i / 2] = tree[i];
        tree[i] = temp;
        i = i / 2;
    }
}


int TreeADT::deletion() {
    if (cur == -1) {
        printf("Queue is empty.\n");
        return -9999;
    } else {
        int data = tree[1];
        tree[1] = tree[cur];
        cur--;
        heapify_down();
        return data;
    }
}


void TreeADT::heapify_down() {
    int i = 1;
    while (2 * i <= cur) {
        int lar = i;
        int left = 2 * i;
        int right = 2 * i + 1;


        if (left <= cur && tree[left] > tree[lar]) {
            lar = left;
        }
        if (right <= cur && tree[right] > tree[lar]) {
            lar = right;
        }


        if (lar != i) {
            int temp = tree[i];
            tree[i] = tree[lar];
            tree[lar] = temp;
            i = lar;
        } else {
            break;
        }
    }
}


void TreeADT::display() {
    if (cur == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Priority Queue: ");
    for (int i = 1; i <= cur; i++) {
        printf("%d  ", tree[i]);
    }
    printf("\n");
}


bool TreeADT::search(int i, int key) {
    if (i > cur) {
        return false;
    }
    if (tree[i] < key) {
        return false;
    }
    if (tree[i] == key) {
        return true;
    }
    int left = 2 * i;
    int right = 2 * i + 1;


    return search(left, key) || search(right, key);
}


int* TreeADT::heap_sort(int &size) {
    if (cur == -1) {
        printf("Queue is empty.\n");
        return NULL;
    }
    size = cur;
    int i = cur;
    int* arr = new int[cur + 1];  // +1 for 1-based index


    while (!isempty()) {
        arr[i] = deletion();
        i--;
    }
    return arr;
}
