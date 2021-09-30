/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
    
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */
    if(stack.isEmpty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "stack is not empty" << endl;
    }
    try{
        cout << stack.peek().id << " was peeked in stack" << endl;
        cout << stack.peek().information << " was peeked in stack" << endl;
    }
    catch(int errorNum){
        cout << "can not peek empty stack" << endl;
    }
    try{
        stack.pop();
        cout << "removing number from stack" << endl;
    }
    catch(int errorNum){
        cout << "stack underflow, cannot pop from an empty stack" << endl;
    }
    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack. Also show what happens
     * when you try and push negative ids and/or empty strings, which your
     * stack should not accept.
     */
    std::string x(data[number_test_cases]);
    for(int index{0}; index < number_test_cases; index++){
        std::string x(data[index]);
        int operationNum = (rand() % 3);
        switch(operationNum){
            case 0:
                if(stack.push(ids[index], &x)){ //string input problems with push
                    cout << "adding number to stack" << endl;
                }
                else{
                    cout << "cannot push, stack is full or data is invalid" << endl;
                }
                break;
            case 1:
                try{
                    stack.pop();
                    cout << "removing number from stack" << endl;
                }
                catch(int errorNum){
                    cout << "stack underflow, cannot pop from an empty stack" << endl;
                }
                break;
            case 2:
                try{
                    cout << stack.peek().id << " was peeked in stack" << endl;
                    cout << stack.peek().information << " was peeked in stack" << endl;
                }
                catch(int errorNum){
                    cout << "can not peek empty stack" << endl;
                }
                break;
        }
    }

    return 0;
}
