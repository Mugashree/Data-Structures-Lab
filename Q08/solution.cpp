// Program to implement list ADT using doubly linked list

#include <cstdio>
#include <cstdlib>

class List
{

struct node
{
int data;
struct node *next;
struct node *prev;
};

struct node *head;
struct node *tail;

public:

List()
{
head = NULL;
tail = NULL;
}

void InsertBeg(int);
void InsertEnd(int);
void InsertPos(int,int);
void DelBeg();
void DelPos(int);
void DelEnd();
int Search(int);
void Display();

};

int main(){

List obj;

while(1){


printf("\n\n\nMENU:\n");
printf("1. Insert Beginning\n2. Insert End\n3. Insert Position\n");
printf("4. Delete Beginning\n5. Delete End\n6. Delete Postion\n");
printf("7. Search\n8. Display\n9. Exit\n ");

int choice;
int num;
int pos;
printf("\nEnter you choice: \n");
scanf("%d", &choice);


switch(choice){

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
printf("Enter the positon that then number should be inserted: \n");
scanf("%d", &pos);
obj.InsertPos(num,pos);
break;

case 4:

obj.DelBeg();
break;

case 5:

obj.DelEnd();
break;

case 6:

printf("Enter the position to be deleted:\n");
scanf("%d", &pos);
obj.DelPos(pos);
break;
case 7:

printf("Enter the number to be searched in the list:\n");
scanf("%d", &num);
if(obj.Search(num) == 1){
printf("The number %d is found in the list.\n", num);
}

else{
printf("The number %d is not found in the list.", num);
}
break;

case 8:
obj.Display();
break;

case 9:

printf("Exiting the program.....\n");
return 0;
break;

default:

printf("Invalid Input\n");
break;
}
}


return 0;

}

// Function to insert in the beginning

void List :: InsertBeg(int num){

struct node *newnode = (struct node*)malloc(sizeof(struct node));
newnode -> data = num;
newnode -> prev = NULL;

if(head == NULL){
newnode ->next = NULL;
head = newnode;
tail = newnode;
}

else{
newnode -> prev = NULL;
newnode -> data = num;
newnode -> next = head;
head -> prev = newnode;
head = newnode;

}
}

// Function to insert at end

void List :: InsertEnd(int num){

struct node *newnode = (struct node*)malloc(sizeof(struct node));

if(head == NULL){
InsertBeg(num);
return;
}

else{
newnode -> data = num;
newnode -> next = NULL;
newnode -> prev = tail;
tail -> next = newnode;
tail = newnode;
}


}

// Function to insert at position

void List :: InsertPos(int num, int pos){

struct node *newnode = (struct node*)malloc(sizeof(struct node));
newnode-> data = num;

if(pos<= 0){
printf("Invalid position.");
return;
}

else if(pos == 1){
InsertBeg(num);
return;
}

else{
struct node *cur = head;
for(int i = 1; cur != NULL && i < pos -1; i++){
cur = cur -> next;
}

if(cur == NULL){
printf("Invalid position.");
}

newnode -> prev = cur;
newnode ->next = cur -> next;
cur -> next -> prev = newnode;
cur -> next = newnode;
return;
}

}

// Function to delete at beginning

void List :: DelBeg(){

if(head == NULL){
printf("The list is empty.");
return;
}

else{
int temp = head -> data;
head = head->next;
head -> prev = NULL;
printf("The deleted number is %d", temp);
}

}

// Function to delete in the end

void List :: DelEnd(){

if(head == NULL){
printf("The list is empty.");
return;
}

struct node *temp = tail;
int data = temp -> data;
tail = tail -> prev;
if (tail != NULL) {
        tail->next = NULL; 
    } else {
        head = NULL; 
    }
printf("The deleted number is %d", data);

}

// Function to delete at position

void List :: DelPos(int pos){
if(head == NULL){
printf("The list is empty.");
return;
}


if(pos == 1){
DelBeg();
return;
}

else{

struct node *cur = head;

for(int i = 1; cur != NULL && i < pos - 1; i++){

cur = cur -> next;
}

if( cur == NULL || cur -> next == NULL){
printf("Invalid Position.");

}

struct node* to_free = cur -> next;
int temp = to_free -> data;
cur -> next = to_free -> next;

if (to_free->next != NULL) {
       to_free->next->prev = cur;
} else {
    tail = cur;
}
free(to_free);

printf("The deleted number at position %d is %d", pos, temp);
return;

}
}

// Function to search for an element

int List :: Search (int num){

if(head == NULL){
printf("The list is empty.");
}

struct node *temp = head;

while(temp != NULL){

if(temp -> data == num){
return 1;
}
temp = temp -> next;
}

return 0;


}

// Display function

void List :: Display(){

if(head == NULL){
printf("The list is empty.");
}

else{
struct node *temp = head;

while(temp != NULL){
printf("%d -> ", temp->data);
temp = temp->next;
}

printf("NULL");
}

printf("\n");

struct node *temp = tail;

while(temp != NULL){
printf("%d -> ", temp->data);
temp = temp->prev;
}

printf("NULL");
}

