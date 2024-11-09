#include<iostream>
using namespace std;

class CQueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    CQueue(int size){
        this->size =size;
        arr = new int[size];
        front = 0;
        rear =0;
    }

    void push(int data){
        // Queue Full
        // Single Elemet Case
        // Circluar Nature 
        // Normal Flow

        if(front ==0 && rear == size-1){
            cout<<"Q is full"<<endl;
        }
        else if(front-rear==1){
            cout<<"Q is full"<<endl;
        }
        else if(front==-1){
            front=rear=0;
            arr[rear] =data;
        }
        else if(rear == size-1 && front!=0){
            rear =0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pop(){
        // Empty check]

        // ?Single element 

        // circular nature

        // general flow
        if(front ==-1){
            cout<<"Queu is empty"<<endl;
        }
        else if(front==rear){
            arr[front] =1;
            front =rear =-1;
        }
        else if(front == size-1){
            front =0;
        }
        else{
            front++;
        }
    }
    int getFront(){
        if(front==rear){
            cout<<"Q isd empty";
            return -1;
        }
        else{
            return arr[front];
        }
    }  

    bool isempty(){
        if(front == rear){
            return true;
        }

        else{
            return false;
        } 
    }

    int getSize(){
        return rear-front;
    }
};
int main(){
    CQueue q(4);
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);
    q.pop();
    return 0;
}