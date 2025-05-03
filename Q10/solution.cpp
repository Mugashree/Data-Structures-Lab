//Implementing round robin scheduling 

#include "circular_header.h"

void insert(int, listadt&);
void execute(int, listadt&);

listadt::listadt()
{
    head=NULL;
}

int main()
{
    int chc;
    listadt obj;
    int slt=0;
    printf("Enter the time slot to be alloted:\n");
    scanf("%d", &slt);
    do {
        printf("MENU: \n\t 1. Insert\n\t 2. Execute \n\t 3. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &chc);

        switch (chc) 
        {
            case 1: 
            {
                int num;
                printf("Enter the number to be inserted\n");
                scanf("%d", &num);
                insert(num, obj);
                break;
            }
            case 2: 
            {
                execute(slt, obj);
                break;
            }
            case 3:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (chc !=5);
}
void insert(int num, listadt& obj)
{
    obj.listadt::insert_end(num);
    obj.listadt::display();
}
void execute(int slt, listadt& obj)
{
    int x=obj.listadt::gethead();
    if (x!=0)
    {
        int ret = obj.listadt::delete_beginning();
        ret=ret-slt;
        if (ret<=0)
        {
            printf("Operation was successful\n");
        }
        else
        {
            obj.listadt::insert_end(ret);
            printf("Operation was successful\n");
        }
    }
    else
    {
        printf("The queue is empty.\n");
        return;
    }    

    obj.listadt::display();
}
