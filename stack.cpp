/*****************
 * author: Isaac Shepherd
 * file: stack.cpp
 * defines methods for class Stack, incorporates use of the user defined data struct "Data"
 * includes stack.h
 ******************/

// each cpp includes ONLY it's header directly!
#include "stack.h"

Stack::Stack(){
    top = -1;
}

// function to insert data into stack
bool Stack::push(int x, const string* info){
    bool pushed = false;
    if(top < STACK_SIZE-1 and x >= 0 and *info != "")
    {
        stack[++top] = new Data;
        stack[top]->id = x;
        stack[top]->information = *info;
        pushed = true;
    }
    return pushed;
}

// function to remove data from the top of the stack
bool Stack::pop(Data &myData){
    bool popped = true;
    if(isEmpty()){
        popped = false;
        myData.id = -1;
        myData.information = "";
    }
    else{
        myData.id = stack[top]->id;
        myData.information = stack[top]->information;
        delete stack[top--];
    }
    return popped;
}

bool Stack::peek(Data &myData){
    bool peeked = true;
    if(isEmpty()){
        peeked = false;
        myData.id = -1;
        myData.information = "";
    }
    else{
        myData.id = stack[top]->id;
        myData.information = stack[top]->information;
    }
    return peeked;
}

// function to check if stack is empty
bool Stack::isEmpty(){
    return top < 0;
}