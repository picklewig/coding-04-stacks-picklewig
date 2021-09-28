/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

// each cpp includes ONLY it's header directly!
#include "stack.h"


Stack::Stack(){
    top = -1;
}

// function to insert data into stack
bool Stack::push(int x, const string* info){
    if(top < STACK_SIZE-1)
    {
        stack[++top]->id = x;
        stack[++top]->information = info;
    }
    return top < STACK_SIZE-1;
}

// function to remove data from the top of the stack
int Stack::pop(){
    if(isEmpty()){
        throw 0;
    }
    return stack[top--];
}

int Stack::peek(){
    if(isEmpty()){
        throw 0;
    }
    return stack[top];
}

// function to check if stack is empty
bool Stack::isEmpty(){
    return top < 0;
}