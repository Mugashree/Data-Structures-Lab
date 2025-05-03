//Program to implement charcter binary tree

#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

class treeadt
{
    struct node
    {
        char data;
        struct node* left;
        struct node* right;
    }*head;

public:
    treeadt()
    {
        head = NULL;
    }
    struct node* gethead()
    {
        return head;
    }
    void preorder(struct node*);
    void inorder(struct node*);
    void postorder(struct node*);
    void insert(char);
    int search(struct node*, char, int);
};

int main()
{
    int chc;
    treeadt obj;
    do 
    {
        printf("Enter: \n\t 1. For Inserting\n\t 2. Inorder Traversal\n\t 3. Preorder Traversal\n\t 4. Postorder Traversal\n\t 5. Search\n\t 6. Exit\n");
        printf("Enter Your Choice: \n");
        scanf("%d", &chc);
        switch(chc)
        {
            case 1:
            {
                char val;
                printf("Enter the Character to be Inserted: \n");
                scanf(" %c", &val);
                obj.insert(val);
                break;
            }
            case 2:
            {
                printf("Inorder Traversal: ");
                obj.inorder(obj.gethead());
                printf("\n");
                break;
            }
            case 3:
            {
                printf("Preorder Traversal: ");
                obj.preorder(obj.gethead());
                printf("\n");
                break;
            }
            case 4:
            {
                printf("Postorder Traversal: ");
                obj.postorder(obj.gethead());
                printf("\n");
                break;
            }
            case 5:
            {
                char key;
                printf("Enter the Character to be Searched: \n");
                scanf(" %c", &key);
                int ret = obj.search(obj.gethead(), key, 0);
                printf(ret ? "The Character Was Found.\n" : "The Character Was Not Found.\n");
                break;
            }
            case 6:
            {
                exit(0);
            }
        }
    } while(1);
}

void treeadt::insert(char data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->right = NULL;
    newnode->left = NULL;
    newnode->data = data;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        queue<struct node*> que;
        que.push(head);
        while(!que.empty())
        {
            struct node* Node = que.front();
            que.pop();

            if(Node->left != nullptr)
            {
                que.push(Node->left);
            }
            else
            {
                Node->left = newnode;
                return;
            }

            if(Node->right != nullptr)
            {
                que.push(Node->right);
            }
            else
            {
                Node->right = newnode;
                return;
            }
        }
    }
}

void treeadt::inorder(struct node* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%c  ", root->data);
        inorder(root->right);
    }
}

void treeadt::preorder(struct node* root)
{
    if(root)
    {
        printf("%c  ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void treeadt::postorder(struct node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c  ", root->data);
    }
}

int treeadt::search(struct node* root, char key, int flag)
{
    if(root)
    {
        flag = search(root->left, key, flag);
        if(root->data == key)
        {
            flag++;
        }
        flag = search(root->right, key, flag);
    }
    return flag;
}

