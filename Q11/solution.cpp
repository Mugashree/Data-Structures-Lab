// Program to implement stack using array

#include <cstdio>
#include <cstdlib>

class Stack{

char arr[5];
int top;

public:

Stack(){
top = -1;
}

void Push(char val);
void Pop();
void Peek();
void Display();
};


int main(){

Stack obj;

while(1){


printf("\n\n\nMENU:\n");
printf("1. Push\n2. Pop\n3. Peek\n");
printf("4. Display\n5. Exit\n");

int choice;
char val;
printf("\nEnter you choice: \n");
scanf("%d", &choice);


switch(choice){

case 1:
printf("Enter the character to be pushed into the stack: \n");
scanf(" %c", &val);
obj.Push(val);
break;

case 2:
obj.Pop();
break;
case 3:
obj.Peek();
break;

case 4:
obj.Display();
break;

case 5:
printf("Exiting the program.....\n");
return 0;
break;

default:

printf("Invalid Input\n");
break;
}

}

}


void Stack :: Push(char val){

if(top == 4){
printf("Stack Overflow\n");
return;
}
else{
top++;
arr[top] = val;
printf("%c is pushed into the stack\n", val);
return;
}

}

void Stack :: Pop(){

if(top == -1){
printf("The stack is empty\n");
return;
}

char pop = arr[top];
top --;
printf("The popped character is: %c", pop);
return;
}

void Stack :: Peek(){

if(top == -1){
printf("The stack is empty\n");
return;
}

printf("The top element is %c", arr[top]);
return;
}

void Stack :: Display(){

if(top == -1){
printf("The stack is empty\n");
return;
}

printf("Stack elements are: \n");
for(int i = 0; i<= top; i++){
printf("%c ", arr[i]);
}
}
