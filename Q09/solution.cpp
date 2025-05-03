//Program to implement list ADT using circular linked list

#include<cstdio>
#include<stdlib.h>

class cir_link{
    struct node{
    int data;
    struct node*next;
    };
    struct node*head;
    
public:
    cir_link(){
        head=NULL;
    };
    
    void insert_at_beg(int);
    void insert_at_end(int);
    void insert_at_pos(int,int);
    void delete_at_beg();
    void delete_at_end();
    void delete_at_pos(int);
    void search(int);
    void display();
};
int main(){
    cir_link obj;
    int choice;
    int num,pos;
    do{
        printf("\nMENU\n");
        printf("1.Insert Beginning\n2.Insert End\n3.Insert Position\n4.Delete Beginning\n5.Delete End\n6.Delete Position\n");
        printf("7.Search\n8.Display\n");
        printf("9.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the number to be inserted at the beginning:\n");
                scanf("%d",&num);
                obj. insert_at_beg(num);
                break;
                
            case 2:
                printf("Enter the number to be inserted at end:\n");
                scanf("%d",&num);
                obj.insert_at_end(num);
                break;
                
            case 3:
                printf("Enter the position:\n");
                scanf("%d",&pos);
                printf("Enter the number:\n");
                scanf("%d",&num);
                obj.insert_at_pos(num,pos);
                break;
                
            case 4:
                obj.delete_at_beg();
                break;
                
            case 5:
                obj.delete_at_end();
                break;
                
            case 6:
                printf("Enter the position to delete:\n");
                scanf("%d",&pos);
                obj.delete_at_pos(pos);
                break;
                
            case 7:
                printf("Enter the number to search:\n");
                scanf("%d",&num);
                obj.search(num);
                break;
            case 8:
                obj.display();
                break;
            case 9:
                printf("Exiting the program.....\n");
                return 0;
            default:
                 printf("Invalid input\n");
}
}while(choice!=9);
}

//Function to Insert number at the beginning
void cir_link::insert_at_beg(int num){
    struct node*newnode=(struct node*)malloc(sizeof(node));
    newnode->data=num;
    
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        struct node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
        head=newnode;
    }
}

//Function to Insert number at end
void cir_link::insert_at_end(int num) {
    struct node * newnode=(struct node*)malloc(sizeof(node));
    newnode->data=num;
    
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        struct node*temp=head;
        while(temp->next !=head){
            temp=temp->next;
     }
     temp->next=newnode;
     newnode->next=head;
}
}

//Function to Insert at position
void cir_link::insert_at_pos(int num, int pos) {
    if (pos < 1) {
        printf("Position is out of range\n");
        return;
    }
    struct node* newnode = (struct node*)malloc(sizeof(node));
    newnode->data = num;

    if (head == NULL) {  
        if (pos == 1) {
            head = newnode;
            newnode->next = head;  
        } else {
            printf("Position out of range\n");
            free(newnode);
        }
        return;
    }

    if (pos == 1) {  
        struct node* temp = head;
        while (temp->next != head) { 
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
        return;
    }

    struct node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head) { 
        temp = temp->next;
        count++;
    }

    if (count == pos - 1) { 
        newnode->next = temp->next;
        temp->next = newnode;
    } else {
        printf("Position out of range!\n");
        free(newnode);
    }
}

//Function to Delete at beginning
void cir_link::delete_at_beg(){
    if(head==NULL){
        printf("The list is empty\n");
    }
    struct node*temp=head;

    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    else{
        struct node*last=head;
        while(last->next!=head){
            last=last->next;
        }
        head=head->next;
        last->next=head;
        free(temp);
    }
}
//Function to delete at end
void cir_link::delete_at_end(){
    if(head==NULL){
        printf("The list is empty\n");
    }
    struct node*temp=head,*prev=NULL;

    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    else{
        while(temp->next!=head){
            prev=temp;
            temp=temp->next;
        }
        prev->next=head;
        free(temp);
    }
    printf("Node deleted\n");
}

//Function to delete at position
void cir_link::delete_at_pos(int pos) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct node *temp = head, *prev = NULL;
    int count = 1;
    if (pos == 1) {
        if (head->next == head) {  
            free(head);
            head = NULL;
            return;
        }
        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        head = head->next;  
        last->next = head;  
        free(temp);  
        return;
    }
    struct node* current = head;
    do {
        prev = current;
        current = current->next;
        count++;
    } while (count < pos && current != head);

    if (count == pos) {
        prev->next = current->next;
        free(current);
        printf("Node deleted successfully\n");
    } else {
        printf("Position out of range\n");
    }
}

//Function to implement search function
void cir_link::search(int num) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct node* temp = head;

    while (temp->next != head) {  
        if (temp->data == num) {
            printf("The number %d is found\n", num);
            return;
        }
        temp = temp->next;
    }
    if (temp->data == num) {
        printf("The number %d is found\n", num);
        return;
    }
    printf("The number %d is not found\n", num);
}

//Function to display
void cir_link::display() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct node* temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  
    printf("(head)\n");  
}

