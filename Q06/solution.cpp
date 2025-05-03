// Program to implement List ADT using a singly linked list

#include <cstdio>
#include <cstdlib>

class listadt
{
    struct node
    {
        int data;
        struct node* next;
    }*head;
public:
    listadt()
    {
        head = NULL;
    }
    int insert_beginning(int);
    int insert_end(int);
    int insert_position(int, int);
    int delete_beginning();
    int delete_end();
    int delete_position(int);
    void display();
    void reverse_display();
    int reverse_link();
    int search(int);
};

int main()
{
    int chc;
    listadt obj;
    do 
    {
        printf("Enter: \n\t1. Inserting at the beginning\n\t2. Inserting at the end\n\t3. Inserting at a position\n\t4. Deleting at the beginning\n\t5. Deleting at the end\n\t6. Deleting at a position\n\t7. Searching\n\t8. Display\n\t9. Reverse display\n\t10. Reverse link\n\t11. Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &chc);
        switch(chc)
        {

            case 1:
            {
                int num;
                printf("Enter the number to be inserted\n");
                scanf("%d", &num);
                int ret = obj.insert_beginning(num);
                if (ret == 1)
                    printf("Insertion was successful\n");
                else 
                    printf("Insertion was unsuccessful\n");
                break;
            }

            case 2:
            {
                int num;
                printf("Enter the number to be inserted\n");
                scanf("%d", &num);
                int ret = obj.insert_end(num);
                if (ret == 1)
                    printf("Insertion was successful\n");
                else 
                    printf("Insertion was unsuccessful\n");
                break;
            }

            case 3:
            {
                int num;
                printf("Enter the number to be inserted\n");
                scanf("%d", &num);
                int pos;
                printf("Enter the position. 1 is the first position\n");
                scanf("%d", &pos);
                int ret = obj.insert_position(num, pos);
                if (ret == 1)
                    printf("Insertion was successful\n");
                else 
                    printf("Insertion was unsuccessful\n");
                break;
            }


            case 4:
            {
                int ret = obj.delete_beginning();
                if (ret == -9999)
                    printf("Deletion was unsuccessful\n");
                else
                    printf("Deletion was successful. Deleted value: %d\n", ret);
                break;
            }

            case 5:
            {
                int ret = obj.delete_end();
                if (ret == -9999)
                    printf("Deletion was unsuccessful\n");
                else
                    printf("Deletion was successful. Deleted value: %d\n", ret);
                break;
            }


            case 6:
            {
                int pos;
                printf("Enter the position. 1 is the first position\n");
                scanf("%d", &pos);
                int ret = obj.delete_position(pos);
                if (ret == -9999)
                    printf("Deletion was unsuccessful\n");
                else
                    printf("Deletion was successful. Deleted value: %d\n", ret);
                break;
            }


            case 7:
            {
                int key;
                printf("Enter the number to be searched\n");
                scanf("%d", &key);
                int ret = obj.search(key);
                if (ret > 0)
                    printf("The element was found at position %d\n", ret);
                else 
                    printf("The element was not found\n");
                break;
            }




            case 8:
                obj.display();
                break;

            case 9:
                obj.reverse_display();
                break;

            case 10:
            {
                int ret = obj.reverse_link();
                if (ret == 1)
                    printf("Reversal was successful\n");
                else
                    printf("Reversal was unsuccessful\n");
                break;
            }

            case 11:
                return 0;
            default:
                printf("Invalid input\n");
        }
    } while (chc < 11);
}


// Function to insert at the beginning

int listadt::insert_beginning(int num)
{
    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    newnode->data = num;
    newnode->next = head;
    head = newnode;
    return 1;
}

// Function to insert at the end

int listadt::insert_end(int num)
{
    if (head == NULL)
        return insert_beginning(num);

    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    newnode->data = num;
    newnode->next = NULL;
    temp->next = newnode;
    return 1;
}

// Function to insert at a position

int listadt::insert_position(int num, int pos)
{
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return 0;
    }

    if (pos == 1)
        return insert_beginning(num);

    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    newnode->data = num;
    struct node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return 0;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return 1;
}

// Function to delete at the beginning


int listadt::delete_beginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return -9999;
    }

    int data = head->data;
    head = head->next;
    return data;
}


// Function to delete at the end

int listadt::delete_end()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return -9999;
    }

    if (head->next == NULL)
        return delete_beginning();

    struct node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    int data = temp->next->data;
    temp->next = NULL;
    return data;
}


// Function to delete at a position

int listadt::delete_position(int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return -9999;
    }

    if (pos == 1)
        return delete_beginning();

    struct node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return -9999;
    }

    int data = temp->next->data;
    temp->next = temp->next->next;
    return data;
}

// Function to search for an element

int listadt::search(int key)
{
    if (head == NULL)
        return -1;

    struct node* temp = head;
    int pos = 0;

    while (temp != NULL)
    {
        pos++;
        if (temp->data == key)
            return pos;
        temp = temp->next;
    }
    return 0;
}

// Function to display

void listadt::display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the list

int listadt::reverse_link()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return 0;
    }

    struct node* prev = NULL;
    struct node* cur = head;
    struct node* next1 = NULL;

    while (cur != NULL)
    {
        next1 = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next1;
    }


    head = prev;
    return 1;
}


// Function to reverse display

void listadt::reverse_display()
{
    int ret = reverse_link();
    display();
    reverse_link(); 
}
