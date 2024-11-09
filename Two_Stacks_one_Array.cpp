#include <iostream>
// ek array chahiye
// do top pop and push
// ek top=-1 and dusra top = size
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
        
    }

    void push1(int data)
    {
        if(top2-top1==1){
            // Space not available
            cout<<"Overflow";
        }
        else{
        top1++;
        arr[top1]= data;
        }
    }


    void push2(int data)
    {
        if(top2-top1==1){
            // Space not available
            cout<<"Overflow";
        }
        else{
        top2--;
        arr[top2]= data;
        }
    }

    void pop1(){
        if(top1==-1){
            cout<<"Underflow";
        }
        else{
            top1--;

        }
    }

    void pop2(){
        if(top1==size){
            cout<<"Underflow";
        }
        else{
            top2++;
        }
    }
};
int main(){
    return 0;
}