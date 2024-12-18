#include <iostream>

using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size =size;
        arr = new int[size];
        front = 0;
        rear =0;
    }

    void push(int data){
        if(rear==size){
            cout<<"Queue is full";
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    void pop(){
        if(front ==rear){
            cout<<"queue is empty";
        }
        else{
            arr[front] =-1;
            front++;
            if(front == rear){
                front =0;
                rear = 0;

            }
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
    Queue q(10);
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);
    return 0;
}