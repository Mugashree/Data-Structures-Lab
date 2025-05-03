#include <cstdio>
#include <cstdlib>
#include "header.h"

listadt::listadt() 
{
    head = NULL;
}

struct listadt::node* listadt::gethead()
{
    return head;
}

int main() 
{
    int chc;
    listadt obj, obj1, obj2;
    do {
        printf("Enter: \n\t1. For Inserting into List 1\n\t2. For Inserting into List 2\n\t3. For Merging\n\t4. For Display\n\t5. For Exit\n");
        printf("Enter the choice:\n");
        scanf("%d", &chc);

        switch (chc) 
        {
            case 1: 
            {
                int num;
                printf("Enter the number to be inserted into List 1:\n");
                scanf("%d", &num);
                if (obj1.insert_list1(num)) 
                {
                    printf("Insertion was successful.\n");
                } 
                else 
                {
                    printf("Insertion was unsuccessful.\n");
                }
                break;
            }
            case 2: 
            {
                int num;
                printf("Enter the number to be inserted into List 2:\n");
                scanf("%d", &num);
                if (obj2.insert_list2(num)) 
                {
                    printf("Insertion was successful.\n");
                } 
                else 
                {
                    printf("Insertion was unsuccessful.\n");
                }
                break;
            }
            case 3:
                obj.merge_2(obj1, obj2);
                printf("Lists merged successfully.\n");
                break;
            case 4:
                obj.display();
                return 0;
            case 5:
                return 0;
            default:
                printf("Invalid input.\n");
                break;
        }
    } while (chc < 5);
}

int listadt::insert_list1(int num)
{
    return insert(num);
}

int listadt::insert_list2(int num)
{
    return insert(num);
}

void listadt::merge_2(listadt& obj1, listadt& obj2)
{
    return merge(obj1, obj2);
}
