// Program to implement binary expression tree


#include "bst_header.h"


treeadt::treeadt()
{
    head = NULL;
}


string postfix();
void consttree(string, treeadt&);


int main()
{
    string post;
    int chc;
    treeadt obj;
    
    do 
    {
        printf("Please choose an option:\n");
        printf("\t1. Enter a postfix expression\n");
        printf("\t2. Construct the expression tree\n");
        printf("\t3. Display inorder traversal\n");
        printf("\t4. Display preorder traversal\n");
        printf("\t5. Display postorder traversal\n");
        printf("\t6. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &chc);
        
        switch(chc)
        {
            case 1:
            {
                post = postfix();
                break;
            }
            case 2:
            {
                consttree(post, obj);
                break;
            }
            case 3:
            {
                obj.inorder(obj.gethead());
                printf("\n");
                break;
            }
            case 4:
            {
                obj.preorder(obj.gethead());
                printf("\n");
                break;
            }
            case 5:
            {
                obj.postorder(obj.gethead());
                printf("\n");
                break;
            }
            case 6:
            {
                printf("Exiting the program...\n");
                exit(0);
                break;
            }
            default:
            {
                printf("Invalid input, please try again.\n");
            }
        }
    } while (1);
}


string postfix()
{
    string post;
    printf("Please enter a valid postfix expression: ");
    cin >> post;
    return post;
}


void consttree(string post, treeadt& obj)
{
    obj.sethead(obj.exptree(post, NULL, '\0'));
}
