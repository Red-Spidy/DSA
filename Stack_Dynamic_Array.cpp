#include <iostream>
#include <cstdlib>
using namespace std;
class Stack{
    public:
    int top;
    int *arr;
    int size;
    Stack(int size){
        arr = new int[size];
        this->size  = size;
        top = -1;
    }
    void push(int data){
        if(size-top>1){
            // Space available
            ++top;
            arr[top] = data;

        }
        else{
            cout<<"Stack Overflow"<<endl;
        }

    }

    void pop(){
        // Stack is Not empty
        if(top==-1){
            cout<<"Stack Empty / Underflow";
        }
        else{ 
            top--;
        }

    }

    int getTop(){
        if(top ==-1){
            cout<<"there Is bo element";
        }
        else{
            return arr[top];
        }

    }

    int getSize(){
        // No. of Valid elements present in the stack
        return top+1;
        
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    //s.push(60);
    while(!s.isempty()){
        cout<<s.getTop()<<endl;
        s.pop();
    }
    s.pop();
    return 0;
}