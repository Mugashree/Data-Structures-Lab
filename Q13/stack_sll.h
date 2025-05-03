#ifndef STACK_SLL_H
#define STACK_SLL_H
#include<cstdio>
#include<cstdlib>
class stack_sll{
    struct node{
        int data;
        struct node*next;
    };node*top;
public:
    stack_sll(){
        top=NULL;
    }
    void push(int);
    char pop();
    char peek();
    bool isEmpty();
};
void stack_sll::push(int num){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        return;
    }
    newnode->data=num;
    newnode->next=top;
    top=newnode;
}
char stack_sll::pop(){
    if(top==NULL){
        return '\0';
    }
    char value=top->data;
    struct node*temp=top;
    top=top->next;
    free(temp);
    return value;
}
char stack_sll::peek() {
    if (top == NULL) {
        return '\0'; 
    }
    return top->data;
}
bool stack_sll:: isEmpty() {
    return top == nullptr;
}


#endif
